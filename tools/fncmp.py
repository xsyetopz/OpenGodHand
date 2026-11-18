#!/usr/bin/env python3
"""Compile one source file and compare a function against the original bytes.

    python tools/fncmp.py src/foo.cpp 0x1FA010 [--flags "-O2 -G0"] [--sym NAME]

The target is the original executable (original/extracted/SLUS_215.03). Words
carrying a relocation in the compiled object are compared on their opcode
fields only, because their address fields are filled in at link time. Exit
status 0 means the function matches; otherwise a side-by-side listing marks
the differing instructions.
"""

from __future__ import annotations

import argparse
import shlex
import struct
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import configure  # noqa: E402

ORIG = ROOT / "original/extracted/SLUS_215.03"
TEXT_OFF = 0x1000 - 0x100000  # file offset = vram + TEXT_OFF
# Relocated words keep their opcode bits; the rest is the link-time field.
MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000}  # R_MIPS_26, HI16, LO16


def units() -> dict[int, tuple[int, str]]:
    return {v: (s, n) for v, s, n in configure.read_units()}


def compiled(obj: Path, sym: str) -> tuple[bytes, dict[int, int]]:
    with obj.open("rb") as f:
        elf = ELFFile(f)
        sec = elf.get_section_by_name(f".text.{sym}") or elf.get_section_by_name(".text")
        symtab = elf.get_section_by_name(".symtab")
        start = None
        for s in symtab.iter_symbols():
            if s.name == sym and s["st_shndx"] == elf.get_section_index(sec.name):
                start, size = s["st_value"], s["st_size"]
        if start is None:
            raise SystemExit(f"{obj}: no symbol {sym} in {sec.name}")
        data = sec.data()[start : start + size]
        relocs: dict[int, int] = {}
        for rs in elf.iter_sections():
            if isinstance(rs, RelocationSection) and elf.get_section(rs["sh_info"]).name == sec.name:
                for r in rs.iter_relocations():
                    off = r["r_offset"] - start
                    if 0 <= off < size:
                        relocs[off] = r["r_info_type"]
        return data, relocs


def disasm(word: int, vram: int) -> str:
    import rabbitizer

    return rabbitizer.Instruction(word, vram).disassemble()


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", type=Path)
    ap.add_argument("addr", type=lambda s: int(s, 0))
    ap.add_argument("--flags", default=configure.CXXFLAGS)
    ap.add_argument("--compiler", help="decomp.me compiler package (see tools/eecc.py)")
    ap.add_argument("--sym", help="symbol name in the object (default: original name)")
    ap.add_argument("-q", action="store_true", help="print only the verdict")
    args = ap.parse_args()

    size, name = units()[args.addr]
    sym = args.sym or name
    obj = ROOT / "build/fncmp" / args.src.resolve().relative_to(ROOT).with_suffix(".o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    pick = ["--compiler", args.compiler] if args.compiler else []
    cmd = [sys.executable, str(ROOT / "tools/eecc.py"), *pick, *shlex.split(args.flags), "-c", "-o", str(obj), str(args.src)]
    if subprocess.call(cmd, cwd=ROOT):
        return 2
    got, relocs = compiled(obj, sym)
    raw = ORIG.read_bytes()
    want = raw[args.addr + TEXT_OFF : args.addr + TEXT_OFF + size]
    # Units include trailing alignment nops that belong to no function body.
    while len(want) > len(got) and want[-4:] == bytes(4):
        want = want[:-4]

    bad = 0
    lines = []
    for off in range(0, max(len(got), len(want)), 4):
        g = struct.unpack_from("<I", got, off)[0] if off < len(got) else None
        w = struct.unpack_from("<I", want, off)[0] if off < len(want) else None
        mask = MASK.get(relocs.get(off), 0xFFFFFFFF)
        ok = g is not None and w is not None and (g & mask) == (w & mask)
        bad += not ok
        gs = disasm(g, args.addr + off) if g is not None else ""
        ws = disasm(w, args.addr + off) if w is not None else ""
        lines.append(f"{'  ' if ok else '! '}{args.addr + off:08X}  {ws:<40} {gs}")
    if bad and not args.q:
        print(f"           {'original':<40} compiled")
        print("\n".join(lines))
    verdict = "MATCH" if not bad else f"{bad} differing words"
    print(f"{name} @ 0x{args.addr:X}: {verdict} ({len(got)} vs {len(want)} bytes)")
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
