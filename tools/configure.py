#!/usr/bin/env python3
"""Generate build.ninja for the SLUS_215.03 rebuild.

Every `.text` unit from `asm/text/units.tsv` is placed at its original address
by an explicit `. = ADDR;` in the generated linker script, so a unit whose
replacement compiles to the same bytes leaves the rest of the image untouched.
A decompiled function replaces its asm unit when a source file under `src/`
carries the annotation `// FUNCTION: GAME 0xADDR` above it.
"""

from __future__ import annotations

import argparse
import os
import re
import shlex
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import objdiff_config  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
TARGET = "SLUS_215.03"
TEXT_BASE = 0x100000

ASFLAGS = "-EL -march=r5900 -mabi=o64 -mno-pdr -G0 -Iinclude"
# SN Systems ProDG ee-gcc 2.95.3 (build 136), selected by tools/eecc.py.
CXXFLAGS = "-O2 -G0 -ffunction-sections -fno-common -Iinclude -Isrc"

# Sections outside .text keep a single unit each; order matches the original link.
DATA_UNITS = [
    (".data", 0x3BBF80, "asm/data/data.data.s", ".data"),
    (".sndata", 0x40A400, "asm/data/sndata.data.s", ".data"),
    (".rodata", 0x41B580, "asm/data/rodata.rodata.s", ".rodata"),
    (".gcc_except_table", 0x460C00, "asm/data/gcc_except_table.gcc_except_table.s", ".gcc_except_table"),
    (".sbss", 0x460D00, "asm/data/sbss.sbss.s", ".sbss"),
    (".bss", 0x460E00, "asm/data/bss.bss.s", ".bss"),
]
NOLOAD = {".sbss", ".bss"}
ANNOT = re.compile(r"^//\s*FUNCTION:\s*GAME\s+0x([0-9A-Fa-f]+)")
DEFN = re.compile(r"[\w:~<>]+\s*\(")


def tool(name: str) -> str:
    """Resolve a binutils program; `CROSS` overrides the prefix."""
    prefix = os.environ.get("CROSS", "mipsel-linux-gnu-")
    return prefix + name


def read_units() -> list[tuple[int, int, str]]:
    path = ROOT / "asm/text/units.tsv"
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
        addrs = [int(m.group(1), 16) for line in path.read_text().splitlines() if (m := ANNOT.match(line))]
        if addrs:
            found[path.relative_to(ROOT)] = addrs
    return found


def linker_script(units, replaced: dict[int, tuple[str, str]]) -> str:
    """`replaced` maps a unit address to (object path, input section) supplied by compiled code."""
    out = ["ENTRY(func_00100008)", "SECTIONS", "{", f"  .text 0x{TEXT_BASE:X} :", "  {"]
    # Inside an output section `.` is an offset from the section start.
    for vram, _size, _name in units:
        at = f"0x{vram - TEXT_BASE:X}"
        if vram in replaced:
            obj, sec = replaced[vram]
            out.append(f'    . = {at}; "{obj}"("{sec}")')
        else:
            out.append(f"    . = {at}; build/asm/text/{vram:08X}.o(.text.unit)")
    out.append("  }")
    for name, vram, src, sec in DATA_UNITS:
        noload = " (NOLOAD)" if name in NOLOAD else ""
        obj = "build/" + src[:-2] + ".o"
        out.append(f"  {name} 0x{vram:X}{noload} : {{ {obj}({sec}) }}")
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

    units = read_units()
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
    n.append(f"rule cc\n  command = {args.cc} $CXXFLAGS -c -o $out $in\n  description = CC $in")
    n.append(
        f"rule ld\n  command = {tool('ld')} -EL --no-warn-mismatch -Map $map -T $script "
        "-T build/undefined_funcs_auto.txt -T build/undefined_syms_auto.txt -o $out\n  description = LD $out"
    )
    n.append(f"rule pack\n  command = {py} tools/elfpack.py pack $in $out\n  description = PACK $out")
    n.append(f"rule check\n  command = {py} tools/check.py $in && touch $out\n  description = CHECK $in")
    n.append(f"as = {tool('as')}\nld = {tool('ld')}\npy = {py}")
    n.append(f"rule configure\n  command = {py} tools/configure.py\n  generator = 1\n  description = CONFIGURE")

    objs = []
    for vram, _size, _name in units:
        if vram in replaced:
            continue
        o = f"build/asm/text/{vram:08X}.o"
        n.append(f"build {o}: as asm/text/{vram:08X}.s")
        objs.append(o)
    for _name, _vram, src, _sec in DATA_UNITS:
        o = "build/" + src[:-2] + ".o"
        n.append(f"build {o}: as {src}")
        objs.append(o)
    for src in sources:
        o = "build/" + str(src.with_suffix(".o"))
        n.append(f"build {o}: cc {src}")
        objs.append(o)

    script = f"build/{TARGET}.link.ld"
    (ROOT / "build").mkdir(exist_ok=True)
    (ROOT / script).write_text(linker_script(units, replaced))

    n.append(f"build build/{TARGET}.elf: ld | {script} " + " ".join(objs))
    n.append(f"  script = {script}\n  map = build/{TARGET}.map")
    n.append(f"build build/{TARGET}: pack config/elf_layout.json build/{TARGET}.elf assets/elf | tools/elfpack.py")
    n.append(f"build build/{TARGET}.ok: check build/{TARGET} | tools/check.py config/{TARGET}.sha1")
    n.extend(objdiff_config.emit(units, sources))
    deps = " ".join(["tools/configure.py", "tools/objdiff_config.py", "asm/text/units.tsv", *map(str, sources)])
    n.append(f"build build.ninja: configure | {deps}")
    n.append(f"default build/{TARGET}.ok")
    (ROOT / "build.ninja").write_text("\n".join(n) + "\n")
    print(f"{len(units) - len(replaced)} asm units, {len(replaced)} compiled functions, {len(sources)} sources")
    return 0


if __name__ == "__main__":
    sys.exit(main())
