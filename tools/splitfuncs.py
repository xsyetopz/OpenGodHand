#!/usr/bin/env python3
"""Split splat's single `.text` disassembly into one file per function.

Each unit becomes `<out>/<VRAM>.s` so the linker script can place every
function at its original address and a decompiled function can replace its
unit independently. `<out>/units.tsv` lists `vram  size  name` in address order.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

# gas pads `.text` itself to 16 bytes on MIPS, which would shift the next unit;
# a named section keeps each unit at its exact size.
SECTION = ".text.unit"
HEADER = f'.include "macro.inc"\n\n.set noat\n.set noreorder\n\n.section {SECTION}, "ax"\n\n'
INSN = re.compile(r"^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) ")
# Data-in-text blocks carry no size; their span runs to the next unit.
MARK = re.compile(r"^nonmatching (\S+)(?:, 0x([0-9A-F]+))?$")
TEXT_END = 0x3BBF20


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("text_s", type=Path)
    ap.add_argument("out", type=Path)
    args = ap.parse_args()

    lines = args.text_s.read_text().splitlines(keepends=True)
    starts = []
    for i, line in enumerate(lines):
        if line.startswith("nonmatching "):
            s = i
            while s > 0 and (lines[s - 1].startswith(".align") or lines[s - 1].startswith("/* Handwritten")):
                s -= 1
            starts.append(s)
    if not starts:
        raise SystemExit(f"{args.text_s}: no functions found")
    # A function that runs past an embedded data block ends (endlabel) inside the
    # next block; keep such blocks together so `.size` stays a local expression.
    defined: set[str] = set()
    merged = []
    for n, s in enumerate(starts):
        e = starts[n + 1] if n + 1 < len(starts) else len(lines)
        ends = {l.split()[1] for l in lines[s:e] if l.startswith(("endlabel ", "enddlabel "))}
        own = {l.split()[1] for l in lines[s:e] if l.startswith(("glabel ", "dlabel "))}
        if merged and ends - own and (ends - own) <= defined:
            defined |= own
            continue
        defined = own
        merged.append(s)
    starts = merged

    args.out.mkdir(parents=True, exist_ok=True)
    units = []
    for n, s in enumerate(starts):
        e = starts[n + 1] if n + 1 < len(starts) else len(lines)
        body = lines[s:e]
        # Lines before the first unit (header, leading padding) belong to the first unit.
        if n == 0:
            body = [l for l in lines[:s] if INSN.match(l)] + body
        vram = next(int(m.group(1), 16) for l in body if (m := INSN.match(l)))
        m = next(m for l in body if (m := MARK.match(l)))
        # Every padding word is disassembled explicitly, so `.align` adds nothing and
        # would be wrong relative to a section that starts off an 8-byte boundary.
        body = [l for l in body if not l.startswith(".align")]
        (args.out / f"{vram:08X}.s").write_text(HEADER + "".join(body))
        units.append([vram, int(m.group(2), 16) if m.group(2) else None, m.group(1)])
    for n, u in enumerate(units):
        if u[1] is None:
            u[1] = (units[n + 1][0] if n + 1 < len(units) else TEXT_END) - u[0]
    index = units
    (args.out / "units.tsv").write_text("".join(f"{v:08X}\t{z:X}\t{name}\n" for v, z, name in units))
    print(f"split {len(index)} units into {args.out}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
