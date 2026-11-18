#!/usr/bin/env python3
"""Generate build.ninja for the SLUS_215.03 rebuild.

Every section is split into per-symbol units (`<unit dir>/units.tsv`), each
placed at its original address by an explicit `. = OFFSET;` in the generated
linker script, so a unit whose replacement compiles to the same bytes leaves
the rest of the image untouched.
A source file under `src/` claims a function with the annotation
`// FUNCTION: GAME 0xADDR` above it. tools/linkgen.py writes the linker script
at build time and links a claimed function only when its compiled bytes match
the original, so a work-in-progress annotation falls back to the asm unit.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import objdiff_config  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
TARGET = "SLUS_215.03"

ASFLAGS = "-EL -march=r5900 -mabi=o64 -mno-pdr -G0 -Iinclude"
# SN Systems ProDG ee-gcc 2.95.3 (build 136), selected by tools/eecc.py.
CXXFLAGS = "-O2 -G0 -ffunction-sections -fno-common -Iinclude -Isrc"

# Output sections in link order: (name, vram, end, splat output, unit dir).
# splat extends each section to the next one's start; elfpack trims to the original sizes.
# Every section is split into per-symbol units placed at their original offsets.
SECTIONS = [
    (".text", 0x100000, 0x3BBF20, "asm/text.s", "asm/text"),
    (".data", 0x3BBF80, 0x40A400, "asm/data/data.data.s", "asm/data/data"),
    (".sndata", 0x40A400, 0x41B580, "asm/data/sndata.data.s", "asm/data/sndata"),
    (".rodata", 0x41B580, 0x460C00, "asm/data/rodata.rodata.s", "asm/data/rodata"),
    (".gcc_except_table", 0x460C00, 0x460D00, "asm/data/gcc_except_table.gcc_except_table.s", "asm/data/gcc_except_table"),
    (".sbss", 0x460D00, 0x460E00, "asm/data/sbss.sbss.s", "asm/data/sbss"),
    (".bss", 0x460E00, 0x7867B4, "asm/data/bss.bss.s", "asm/data/bss"),
]
NOLOAD = {".sbss", ".bss"}
ANNOT = re.compile(r"^//\s*FUNCTION:\s*GAME\s+0x([0-9A-Fa-f]+)")
DEFN = re.compile(r"[\w:~<>]+\s*\(")


COMPILER_TAG = re.compile(r"^//\s*COMPILER:\s*(\S+)")
FLAGS_TAG = re.compile(r"^//\s*FLAGS:\s*(.*\S)")


def source_build(src: Path) -> tuple[str | None, str]:
    """Compiler package and flags for a source.

    Leading `// COMPILER: NAME` and `// FLAGS: ...` comment lines override the
    default package (tools/eecc.py DEFAULT) and append to CXXFLAGS.
    """
    compiler, flags = None, CXXFLAGS
    for line in Path(src).read_text(errors="replace").splitlines()[:4]:
        if m := COMPILER_TAG.match(line):
            compiler = m.group(1)
        elif m := FLAGS_TAG.match(line):
            flags += " " + m.group(1)
    return compiler, flags


def tool(name: str) -> str:
    """Resolve a binutils program; `CROSS` overrides the prefix."""
    prefix = os.environ.get("CROSS", "mipsel-linux-gnu-")
    return prefix + name


def read_units(unit_dir: str = "asm/text") -> list[tuple[int, int, str]]:
    path = ROOT / unit_dir / "units.tsv"
    if not path.exists():
        raise SystemExit(f"{path.relative_to(ROOT)} missing; run `just setup` first")
    units = []
    for line in path.read_text().splitlines():
        vram, size, name = line.split("\t")
        units.append((int(vram, 16), int(size, 16), name))
    return units


def read_sources() -> dict[Path, list[int]]:
    """Map each source file to the original addresses of the functions it defines, in file order."""
    found: dict[Path, list[int]] = {}
    for path in sorted((ROOT / "src").rglob("*.c*")) if (ROOT / "src").exists() else []:
        if path.suffix not in (".c", ".cpp", ".cc"):
            continue
        # src/scratch/ (gitignored) holds matching experiments that duplicate real sources.
        if path.relative_to(ROOT).parts[:2] == ("src", "scratch"):
            continue
        # `_name.cpp` files are local probes; they copy functions of real sources.
        if path.name.startswith("_"):
            continue
        addrs = [int(m.group(1), 16) for line in path.read_text().splitlines() if (m := ANNOT.match(line))]
        if addrs:
            found[path.relative_to(ROOT)] = addrs
    return found


def read_sources_all() -> list[Path]:
    """Every real source path (same exclusions as read_sources), annotated or not."""
    return [
        p.relative_to(ROOT)
        for p in sorted((ROOT / "src").rglob("*.c*"))
        if p.suffix in (".c", ".cpp", ".cc")
        and p.relative_to(ROOT).parts[:2] != ("src", "scratch")
        and not p.name.startswith("_")
    ]


INCLUDE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)


def headers(src: Path) -> list[str]:
    """Quoted includes reachable from `src`, searched like `-Iinclude -Isrc`.

    The EE compilers cannot write depfiles through the Wine wrapper, so
    configure scans includes itself; build.ninja depends on every source, so
    a new include re-runs configure."""
    seen: set[Path] = set()
    todo = [ROOT / src]
    while todo:
        text = todo.pop().read_text(errors="replace")
        for name in INCLUDE.findall(text):
            for base in (ROOT / "include", ROOT / "src"):
                h = base / name
                if h.exists() and h not in seen:
                    seen.add(h)
                    todo.append(h)
                    break
    return sorted(str(h.relative_to(ROOT)) for h in seen)


def unit_obj(unit_dir: str, vram: int) -> str:
    return f"build/{unit_dir}/{vram:08X}.o"


def linker_script(sections, replaced: dict[int, tuple[str, str]]) -> str:
    """`sections` pairs each SECTIONS row with its units; `replaced` maps a unit
    address to (object path, input section) supplied by compiled code."""
    out = ["ENTRY(func_00100008)", "SECTIONS", "{"]
    for (name, base, _end, _src, unit_dir), units in sections:
        noload = " (NOLOAD)" if name in NOLOAD else ""
        # splitfuncs names unit sections after splat's input section; .sndata's is .data.
        insec = (".data" if name == ".sndata" else name) + ".unit"
        out += [f"  {name} 0x{base:X}{noload} :", "  {"]
        # Inside an output section `.` is an offset from the section start.
        for vram, _size, _name in units:
            obj, sec = replaced.get(vram) or (unit_obj(unit_dir, vram), insec)
            out.append(f'    . = 0x{vram - base:X}; "{obj}"({sec})')
        out.append("  }")
    out += ["  /DISCARD/ : { *(*) }", "}", ""]
    return "\n".join(out)


def function_sections(obj_src: Path, addrs: list[int], units_by_addr) -> list[tuple[int, str]]:
    """Pair annotated addresses with mangled names from the original symbol table."""
    pairs = []
    for a in addrs:
        if a not in units_by_addr:
            raise SystemExit(f"{obj_src}: 0x{a:X} is not the start of a .text unit")
        pairs.append((a, ".text." + units_by_addr[a]))
    return pairs


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--cc", default=f"{shlex.quote(sys.executable)} tools/eecc.py", help="compiler driver command")
    args = ap.parse_args()

    sections = [(row, read_units(row[4])) for row in SECTIONS]
    units = sections[0][1]
    units_by_addr = {v: n for v, _s, n in units}
    sources = read_sources()
    replaced: dict[int, tuple[str, str]] = {}
    for src, addrs in sources.items():
        obj = "build/" + str(src.with_suffix(".o"))
        for vram, sec in function_sections(src, addrs, units_by_addr):
            if vram in replaced:
                raise SystemExit(f"{src}: 0x{vram:X} already provided by {replaced[vram][0]}")
            replaced[vram] = (obj, sec)

    py = shlex.quote(sys.executable)
    n = []
    n.append(f"ASFLAGS = {ASFLAGS}")
    n.append(f"CXXFLAGS = {CXXFLAGS}")
    n.append(f"rule as\n  command = {tool('as')} $ASFLAGS -o $out $in\n  description = AS $in")
    n.append(f"rule cc\n  command = {args.cc} $pick $CXXFLAGS $flags -c -o $out $in\n  description = CC $in")
    n.append(
        f"rule ld\n  command = {tool('ld')} -EL --no-warn-mismatch -Map $map -T $script "
        "-T config/aliases.ld -T build/undefined_funcs_auto.txt -T build/undefined_syms_auto.txt -o $out\n  description = LD $out"
    )
    n.append(f"rule pack\n  command = {py} tools/elfpack.py pack $in $out\n  description = PACK $out")
    n.append(f"rule check\n  command = {py} tools/check.py $in && cp $elf $elf_ok && touch $out\n  description = CHECK $in")
    n.append(f"as = {tool('as')}\nld = {tool('ld')}\npy = {py}")
    n.append(f"rule linkgen\n  command = {py} tools/linkgen.py $in $script\n  description = LINKGEN")
    n.append(f"rule configure\n  command = {py} tools/configure.py\n  generator = 1\n  description = CONFIGURE")

    objs = []
    for (_name, _base, _end, _src, unit_dir), sec_units in sections:
        for vram, _size, _name in sec_units:
            o = unit_obj(unit_dir, vram)
            n.append(f"build {o}: as {unit_dir}/{vram:08X}.s")
            objs.append(o)
    cobjs = []
    for src in sources:
        o = "build/" + str(src.with_suffix(".o"))
        hs = headers(src)
        n.append(f"build {o}: cc {src}" + (" | " + " ".join(hs) if hs else ""))
        compiler, flags = source_build(src)
        if compiler:
            n.append(f"  pick = --compiler {compiler}")
        if flags != CXXFLAGS:
            n.append(f"  flags = {flags[len(CXXFLAGS):].strip()}")
        cobjs.append(o)

    script = f"build/{TARGET}.link.ld"
    (ROOT / "build").mkdir(exist_ok=True)
    compiled = sorted([v, o, s[len(".text."):]] for v, (o, s) in replaced.items())
    link_json = {"sections": [list(row) for row in SECTIONS], "compiled": compiled}
    text = json.dumps(link_json, indent=1) + "\n"
    if not (ROOT / "build/link.json").exists() or (ROOT / "build/link.json").read_text() != text:
        (ROOT / "build/link.json").write_text(text)
    gated = [o[: -len(".o")] + ".gated.o" for o in cobjs]
    n.append(
        f"build {script} {' '.join(gated)} build/linkgen.tsv: linkgen build/link.json | "
        + " ".join(["tools/linkgen.py", "tools/fncmp.py", "original/extracted/SLUS_215.03", *cobjs])
    )
    n.append(f"  script = {script}")

    n.append(f"build build/{TARGET}.elf: ld | {script} config/aliases.ld " + " ".join(objs + gated))
    n.append(f"  script = {script}\n  map = build/{TARGET}.map")
    n.append(f"build build/{TARGET}: pack config/elf_layout.json build/{TARGET}.elf assets/elf | tools/elfpack.py")
    n.append(f"build build/{TARGET}.ok: check build/{TARGET} | tools/check.py config/{TARGET}.sha1 build/{TARGET}.elf")
    # fncmp reads symbol addresses from a copy of the last link that passed.
    n.append(f"  elf = build/{TARGET}.elf\n  elf_ok = build/{TARGET}.ok.elf")
    n.extend(objdiff_config.emit(units, sources))
    deps = " ".join(["tools/configure.py", "tools/objdiff_config.py", *(f"{row[4]}/units.tsv" for row in SECTIONS), *map(str, sources), *sorted({h for src in sources for h in headers(src)})])
    n.append(f"build build.ninja: configure | {deps}")
    n.append(f"default build/{TARGET}.ok")
    (ROOT / "build.ninja").write_text("\n".join(n) + "\n")
    print(f"{len(units)} asm units, {len(replaced)} annotated functions, {len(sources)} sources")
    return 0


if __name__ == "__main__":
    sys.exit(main())
