"""Pad short loops the way the game's assembler did.

Every backward branch in the game code spans at least six instructions,
counting the branch target through the delay slot: the original executable has
434 loops of exactly six and none shorter (build/asprobe/loops.py scans it).
The shortest loops carry `nop`s right before the branch (`lw; nop; nop; nop;
bnel; lw` in cDamageUnit::AddDamageCollSphere, `jal; daddu; nop; nop; bnez`
in cMessage::deleteAll), which is the R5900 short-loop erratum workaround of
SN's assembler. The ps2eeas 1.8.19 used here has no such pass and the 1.9.x
builds pad to seven, so the compiler's assembly is padded here and assembled
again.

`find(obj)` lists, per `.text*` section, the index of each short loop's branch
among the section's branches and the nops it needs; `pad(asm, fixes, totals)` inserts
them before the matching branch line of the compiler output.
"""

from __future__ import annotations

import re
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile

MIN_LOOP = 6
# Conditional and unconditional branches, including the likely forms and the
# coprocessor tests; the linking forms (bal, bltzal, ...) are calls.
ASM_BRANCH = re.compile(
    r"^\s*(?:b|beqz?|bnez?|blez|bgtz|bltz|bgez|bgeu?|bgtu?|bleu?|bltu?|bc[0-3][ft])l?\s"
)
SECTION = re.compile(r"^\s*\.section\s+([^\s,]+)|^\s*\.(text)\b")


def is_branch(word: int) -> bool:
    op = word >> 26
    if op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17):
        return True
    if op == 1:  # REGIMM: bltz, bgez and their likely forms
        return (word >> 16) & 0x1F in (0, 1, 2, 3)
    if op in (0x10, 0x11, 0x12):  # COPz BC
        return (word >> 21) & 0x1F == 8
    return False


def find(obj: Path) -> tuple[dict[str, list[tuple[int, int]]], dict[str, int]]:
    """Short loops per section, and the branch count of every text section."""
    fixes: dict[str, list[tuple[int, int]]] = {}
    totals: dict[str, int] = {}
    with obj.open("rb") as f:
        for sec in ELFFile(f).iter_sections():
            if not sec.name.startswith(".text") or sec["sh_type"] != "SHT_PROGBITS":
                continue
            data = sec.data()
            n = 0
            for off in range(0, len(data) - 3, 4):
                word = struct.unpack_from("<I", data, off)[0]
                if not is_branch(word):
                    continue
                disp = (word & 0xFFFF) - ((word & 0x8000) << 1)
                span = 1 - disp  # target through delay slot, in instructions
                if disp <= 0 and span < MIN_LOOP:
                    fixes.setdefault(sec.name, []).append((n, MIN_LOOP - span))
                n += 1
            totals[sec.name] = n
    return fixes, totals


def pad(asm: str, fixes: dict[str, list[tuple[int, int]]], totals: dict[str, int]) -> str:
    out, section, counts = [], ".text", {}
    for line in asm.splitlines(keepends=True):
        if m := SECTION.match(line):
            section = m.group(1) or ".text"
        elif ASM_BRANCH.match(line):
            n = counts.get(section, 0)
            counts[section] = n + 1
            need = dict(fixes.get(section, ())).get(n, 0)
            out.append("\tnop\n" * need)
        out.append(line)
    # Branch lines and encoded branches pair up by position only when every
    # padded section has as many of one as of the other.
    for sec in fixes:
        if counts.get(sec, 0) != totals[sec]:
            raise SystemExit(f"shortloop: {sec}: {counts.get(sec, 0)} branch lines, {totals[sec]} branches encoded")
    return "".join(out)
