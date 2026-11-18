#!/usr/bin/env python3
"""Compile one source file and compare a function against the original bytes.

    python tools/fncmp.py src/foo.cpp 0x1FA010 [--flags "-O2 -G0"] [--sym NAME]

The target is the original executable (original/extracted/SLUS_215.03). Words
carrying a relocation in the compiled object are compared on their opcode
fields, and their address fields are checked against the relocation symbol's
address in the last full link (build/SLUS_215.03.elf), so a reference to the
wrong symbol does not pass as a match. Without a linked ELF, or for symbols it
does not define, only the opcode fields are compared. Exit
status 0 means the function matches; otherwise a side-by-side listing marks
the differing instructions.
"""

from __future__ import annotations

import argparse
import os
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


# Copy of the last link that passed the sha1 check; the link itself is
# rewritten (and briefly empty) during every build.
LINKED = ROOT / "build/SLUS_215.03.ok.elf"


def linked_symbols() -> dict[str, int]:
    if not LINKED.exists():
        return {}
    with LINKED.open("rb") as f:
        tab = ELFFile(f).get_section_by_name(".symtab")
        return {s.name: s["st_value"] for s in tab.iter_symbols() if s.name}


def target_ok(kind: int, g: int, w: int, vram: int, addr: int | None) -> bool:
    """Whether the original word `w` encodes the address the compiled word `g`
    refers to, `addr` being its relocation symbol's address (None: unknown).
    The objects use REL relocations, so the addend sits in the compiled field."""
    if addr is None:
        return True
    if kind == 4:  # R_MIPS_26
        return (w & 0x3FFFFFF) << 2 | (vram & 0xF0000000) == addr + ((g & 0x3FFFFFF) << 2)
    if kind == 6:  # R_MIPS_LO16
        lo = g & 0xFFFF
        return (addr + lo - ((lo & 0x8000) << 1)) & 0xFFFF == w & 0xFFFF
    if kind == 5:  # R_MIPS_HI16: the paired LO16 addend can carry one unit either way
        hi = ((addr + ((g & 0xFFFF) << 16) + 0x8000) >> 16) & 0xFFFF
        return ((w & 0xFFFF) - hi + 1) & 0xFFFF <= 2
    return True


def compiled(obj: Path, sym: str) -> tuple[bytes, dict[int, int], dict[int, str]]:
    with obj.open("rb") as f:
        elf = ELFFile(f)
        sec = elf.get_section_by_name(f".text.{sym}") or elf.get_section_by_name(".text")
        if sec is None:
            raise SystemExit(f"{obj}: no section for {sym}")
        symtab = elf.get_section_by_name(".symtab")
        start = None
        for s in symtab.iter_symbols():
            if s.name == sym and s["st_shndx"] == elf.get_section_index(sec.name):
                start, size = s["st_value"], s["st_size"]
        if start is None:
            raise SystemExit(f"{obj}: no symbol {sym} in {sec.name}")
        data = sec.data()[start : start + size]
        relocs: dict[int, int] = {}
        names: dict[int, str] = {}
        for rs in elf.iter_sections():
            if isinstance(rs, RelocationSection) and elf.get_section(rs["sh_info"]).name == sec.name:
                syms = elf.get_section(rs["sh_link"])
                for r in rs.iter_relocations():
                    off = r["r_offset"] - start
                    if 0 <= off < size:
                        relocs[off] = r["r_info_type"]
                        t = syms.get_symbol(r["r_info_sym"])
                        # Section symbols (local literals, own sections) have no linked address.
                        if t["st_info"]["type"] != "STT_SECTION" and t.name:
                            names[off] = t.name
        return data, relocs, names


def disasm(word: int, vram: int) -> str:
    import rabbitizer

    return rabbitizer.Instruction(word, vram).disassemble()


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", type=Path)
    ap.add_argument("addr", type=lambda s: int(s, 0))
    ap.add_argument("--flags", help="override flags (default: CXXFLAGS plus the source's // FLAGS:)")
    ap.add_argument("--compiler", help="decomp.me compiler package (see tools/eecc.py)")
    ap.add_argument("--sym", help="symbol name in the object (default: original name)")
    ap.add_argument("-q", action="store_true", help="print only the verdict")
    args = ap.parse_args()

    size, name = units()[args.addr]
    sym = args.sym or name
    # A per-process object lets several comparisons of one source run at once.
    obj = ROOT / "build/fncmp" / args.src.resolve().relative_to(ROOT).with_suffix(f".{os.getpid()}.o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    tag_compiler, tag_flags = configure.source_build(args.src)
    args.compiler = args.compiler or tag_compiler
    args.flags = args.flags or tag_flags
    pick = ["--compiler", args.compiler] if args.compiler else []
    cmd = [sys.executable, str(ROOT / "tools/eecc.py"), *pick, *shlex.split(args.flags), "-c", "-o", str(obj), str(args.src)]
    if subprocess.call(cmd, cwd=ROOT):
        return 2
    try:
        got, relocs, names = compiled(obj, sym)
    finally:
        obj.unlink(missing_ok=True)
    raw = ORIG.read_bytes()
    want = raw[args.addr + TEXT_OFF : args.addr + TEXT_OFF + size]
    # Units include trailing alignment nops that belong to no function body.
    while len(want) > len(got) and want[-4:] == bytes(4):
        want = want[:-4]

    linked = linked_symbols() if names else {}
    bad = 0
    lines = []
    wrong = []
    for off in range(0, max(len(got), len(want)), 4):
        g = struct.unpack_from("<I", got, off)[0] if off < len(got) else None
        w = struct.unpack_from("<I", want, off)[0] if off < len(want) else None
        mask = MASK.get(relocs.get(off), 0xFFFFFFFF)
        ok = g is not None and w is not None and (g & mask) == (w & mask)
        if ok and off in relocs and not target_ok(relocs[off], g, w, args.addr + off, linked.get(names.get(off))):
            ok = False
            wrong.append(f"  0x{args.addr + off:X}: {names[off]} (0x{linked[names[off]]:X}) is not the original target")
        bad += not ok
        gs = disasm(g, args.addr + off) if g is not None else ""
        ws = disasm(w, args.addr + off) if w is not None else ""
        lines.append(f"{'  ' if ok else '! '}{args.addr + off:08X}  {ws:<40} {gs}")
    if bad and not args.q:
        print(f"           {'original':<40} compiled")
        print("\n".join(lines))
        print("\n".join(wrong))
    verdict = "MATCH" if not bad else f"{bad} differing words"
    print(f"{name} @ 0x{args.addr:X}: {verdict} ({len(got)} vs {len(want)} bytes)")
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
