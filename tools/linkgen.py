#!/usr/bin/env python3
"""Write the linker script, linking only compiled functions that match.

    linkgen.py build/link.json build/SLUS_215.03.link.ld

`build/link.json` (written by configure.py) lists every section's unit
directory and every annotated function as `[vram, object, symbol]`. Each
annotated function is compared with the original bytes (relocated fields
masked, as in fncmp.py). A match is placed at its address in place of its asm
unit. A mismatch keeps the asm unit; every compiled function that is not
placed (mismatched or unannotated) is weakened in a `.gated.o` copy of the
object so the asm definition wins and calls from the same source file still
resolve. Every compiled object is linked through its
`.gated.o` copy.

`build/linkgen.tsv` records `vram  status  symbol` for each annotated function
(status `match`, `differ`, or `refs SECTIONS` for a match that relocates
against a non-function section of its object, which is not linked yet), so a work-in-progress annotation never breaks
the build and the progress tools can tell which functions are linked.

A switch function whose only data reference is its own `.rodata` jump table
(see `jump_table`) also places that section at the original `jtbl_` unit's
address, replacing `asm/data/rodata/<addr>.o`. A function whose only data
reference is a reloc-free `.rodata` section equal to a run of original rodata
units (see `rodata_span`) places that section over the run the same way.
"""

from __future__ import annotations

import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402
import fncmp  # noqa: E402
from linkdata import derived_addresses, find_symbol, jump_table, matches, positional_address, rodata_span  # noqa: E402

ROOT = configure.ROOT


def known_symbols(cfg) -> set[str]:
    """Every name the final link defines without compiled code."""
    names = {n for row in cfg["sections"] for _v, _s, n in configure.read_units(row[4])}
    for f in ("config/aliases.ld", "build/undefined_funcs_auto.txt", "build/undefined_syms_auto.txt"):
        names |= set(re.findall(r"^(\S+)\s*=", (ROOT / f).read_text(), re.M))
    return names


def local_refs(obj: Path, sym: str, known: set[str]) -> set[str]:
    """Sections of `obj` that `sym` relocates against through a section symbol
    or a symbol defined outside a function section. Only matching function
    sections are linked, so a reference to a compiled `.rodata` constant or
    file-static variable cannot resolve yet."""
    out = set()
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        for rs in elf.iter_sections():
            if not isinstance(rs, RelocationSection) or elf.get_section(rs["sh_info"]).name != f".text.{sym}":
                continue
            for r in rs.iter_relocations():
                target = symtab.get_symbol(r["r_info_sym"])
                shndx = target["st_shndx"]
                if shndx == "SHN_UNDEF":
                    if target.name not in known:
                        out.add(target.name)  # a name the original never defines
                    continue
                pinned = target.name in known and target["st_info"]["bind"] != "STB_LOCAL"
                if not isinstance(shndx, int) or pinned:
                    continue  # absolute, or a global the link script pins; locals stay in their section
                name = elf.get_section(shndx).name
                if target["st_info"]["type"] == "STT_SECTION" or not name.startswith(".text."):
                    out.add(name)
    return out


def text_symbols(obj: Path) -> set[str]:
    """Global symbols defined in the object's function sections."""
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        return {
            s.name for s in symtab.iter_symbols()
            if s["st_info"]["bind"] == "STB_GLOBAL" and isinstance(s["st_shndx"], int)
            and elf.get_section(s["st_shndx"]).name.startswith(".text.")
        }


def shrink_section(path: Path, name: str, size: int) -> None:
    """Cut section `name` of the ELF at `path` to `size` bytes by rewriting
    its header's sh_size in place. objcopy --update-section would drop the
    section's relocations; here `.rel<name>` stays intact and the dropped tail
    (zero, unrelocated) is never read by the linker."""
    with path.open("r+b") as f:
        elf = ELFFile(f)
        sec = elf.get_section_by_name(name)
        hdr = elf["e_shoff"] + elf.get_section_index(name) * elf["e_shentsize"]
        assert elf.little_endian and elf.elfclass == 32 and size <= sec["sh_size"]
        f.seek(hdr + 20)  # Elf32_Shdr.sh_size
        f.write(struct.pack("<I", size))


def gated(obj: str) -> str:
    return obj[: -len(".o")] + ".gated.o"


def main() -> int:
    link_json, script = Path(sys.argv[1]), Path(sys.argv[2])
    cfg = json.loads(link_json.read_text())
    raw = fncmp.ORIG.read_bytes()
    sections = [(row, configure.read_units(row[4])) for row in cfg["sections"]]
    spans = {}
    text_units = sections[0][1]
    for n, (vram, _size, _name) in enumerate(text_units):
        end = text_units[n + 1][0] if n + 1 < len(text_units) else sections[0][0][2]
        spans[vram] = end - vram

    known = known_symbols(cfg)
    status: dict[int, str] = {}
    refs: dict[int, set[str]] = {}
    jtbl: dict[int, tuple[int, str, bytes | None, list[int]]] = {}
    ro_span: dict[int, tuple[str, list[int]]] = {}
    ro_units = [(v, sz) for row, units in sections if row[0] == ".rodata" for v, sz, _n in units]
    ro_names = {v: n for row, units in sections if row[0] == ".rodata" for v, _sz, n in units}
    absolute: dict[str, int] = {}
    unit_at = {v: n for _row, units in sections for v, _sz, n in units}
    taken = {e[2] for e in cfg["compiled"]}
    for entry in cfg["compiled"]:
        found = find_symbol(ROOT / entry[1], entry[0], entry[2], spans[entry[0]], raw, taken)
        taken.add(found)
        if found != entry[2]:  # the compiler mangled a name the original lacks
            absolute[entry[2]] = entry[0]
            entry[2] = found
    compiled_defs: set[str] = set()
    for obj in {e[1] for e in cfg["compiled"] if (ROOT / e[1]).exists()}:
        compiled_defs |= text_symbols(ROOT / obj)
    for vram, obj, sym in cfg["compiled"]:
        status[vram] = "match" if matches(ROOT / obj, vram, sym, spans[vram], raw) else "differ"
        # Names defined by no compiled function take the address the original
        # instructions use, so asm data and code stay where they are.
        derived = derived_addresses(ROOT / obj, sym, vram, raw, known | compiled_defs)
        absolute.update(derived)
        refs[vram] = local_refs(ROOT / obj, sym, known | set(derived))
        # asm exception tables name `$LEH_<addr>` labels of this unit; each is its address.
        for label in re.findall(r"\$LEH_([0-9A-F]{8})", (ROOT / f"asm/text/{vram:08X}.s").read_text()):
            absolute[f"$LEH_{label}"] = int(label, 16)
        for name in sorted(refs[vram]):
            addr = positional_address(name, unit_at)
            if addr is not None:  # the original names this unit differently
                absolute[name] = addr
                refs[vram].discard(name)
        if status[vram] == "match" and refs[vram]:
            jt = jump_table(ROOT / obj, sym, vram, spans[vram], raw, ro_units)
            if jt:
                jtbl[vram] = jt
                refs[vram].discard(jt[1])
            elif len(refs[vram]) == 1 and next(iter(refs[vram])).startswith(".rodata"):
                name = next(iter(refs[vram]))
                span_units = rodata_span(ROOT / obj, name, raw, ro_units)
                if span_units:
                    ro_span[vram] = (name, span_units)
                    refs[vram].clear()
    # A reference to another function section resolves only if that function
    # is linked as well; drop unresolvable matches until none remain.
    while True:
        linked = {(o, f".text.{s}") for v, o, s in cfg["compiled"] if status[v] == "match"}
        bad = [
            v for v, o, _s in cfg["compiled"]
            if status[v] == "match" and any((o, r) not in linked for r in refs[v])
        ]
        if not bad:
            break
        for v in bad:
            status[v] = "refs " + ",".join(sorted(r for r in refs[v]))

    placed: dict[int, tuple[str, str]] = {}
    rows = []
    for vram, obj, sym in cfg["compiled"]:
        if status[vram] == "match":
            placed[vram] = (gated(obj), f".text.{sym}")
            if vram in jtbl:  # the jump tables replace their asm .rodata units
                first, name, _cut, covered = jtbl[vram]
                placed[first] = (gated(obj), name)
                placed.update({u: configure.DROP for u in covered[1:]})
                absolute.update({ro_names[u]: u for u in covered})
            if vram in ro_span:  # a constant section replaces its asm units
                first, *rest = ro_span[vram][1]
                placed[first] = (gated(obj), ro_span[vram][0])
                placed.update({u: configure.DROP for u in rest})
                # asm code still names the dropped units' labels: pin them.
                absolute.update({ro_names[u]: u for u in ro_span[vram][1]})
        rows.append(f"{vram:08X}\t{status[vram]}\t{sym}\n")
    # Every function not placed is weakened, annotated or not, so the asm
    # unit of the same name wins and work in progress cannot clash with it.
    linked_syms = {sec[len(".text."):] for _o, sec in placed.values() if sec.startswith(".text.")}
    weak = {o: sorted(text_symbols(ROOT / o) - linked_syms) for o in {o for _v, o, _s in cfg["compiled"]}}

    objcopy = os.environ.get("CROSS", "mipsel-linux-gnu-") + "objcopy"
    for obj, syms in weak.items():
        subprocess.check_call([objcopy, *(f"--weaken-symbol={s}" for s in syms), obj, gated(obj)], cwd=ROOT)
    # A table section padded past its unit is cut to the unit's size.
    for vram, (_uv, name, cut, _units) in jtbl.items():
        if cut is not None and status[vram] == "match":
            obj = next(o for v, o, _s in cfg["compiled"] if v == vram)
            shrink_section(ROOT / gated(obj), name, len(cut))

    script.write_text(configure.linker_script(sections, placed, absolute))
    (ROOT / "build/linkgen.tsv").write_text("".join(rows))
    differ = [r.split("\t")[2].strip() for r in rows if "\tmatch\t" not in r]
    print(f"linkgen: {len(placed)} compiled functions linked, {len(differ)} kept in asm"
          + (f" ({', '.join(differ[:5])}{', ...' if len(differ) > 5 else ''})" if differ else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
