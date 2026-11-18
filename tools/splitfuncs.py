#!/usr/bin/env python3
"""Split one splat section disassembly into one file per symbol ("unit").

    splitfuncs.py SECTION_S OUTDIR END_VRAM

Each unit becomes `<OUTDIR>/<VRAM>.s` in its own `<section>.unit` section, so
the linker script can place it at its original address and compiled code can
replace it independently. `<OUTDIR>/units.tsv` lists `vram  size  name` in
address order; the size is splat's symbol size when given, else the span to
the next unit.

splat's `.align` directives are relative to the start of the section, which is
wrong once a unit starts off an aligned boundary, and gas would pad a plain
`.text` section to 16 bytes. Every `.align` is therefore rewritten as an
`.org` to the address of the next item, and each unit ends with an `.org` to
the next unit, which reproduces the original padding exactly.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

# `/* ROM VRAM [BYTES] */` on text/data lines, `/* VRAM */` on bss lines.
ADDR = re.compile(r"^\s+/\* (?:[0-9A-F]+ )?([0-9A-F]{8}) ")
MARK = re.compile(r"^nonmatching (\S+)(?:, 0x([0-9A-F]+))?$")
SECTION = re.compile(r"^\.section (\.\w+)(.*)$")
WIDE = re.compile(r"^\s+/\*[^*]*\*/ \.(?:word|half|short|float|double|dword)\b")
INSN = re.compile(r"^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/")
AUTO = re.compile(r"^func_[0-9A-F]{8}$")


def split_fragment(body: list[str]) -> list[list[str]]:
    """Split dead stack-pop pairs off the start of a function unit.

    The game's text holds unreferenced `addiu $sp,$sp,N; nop` pairs between
    functions (nothing branches or jumps to them). splat folds them into the
    following function, so its entry point would sit 8 bytes into the unit and
    no compiled function could replace it. The pairs become their own
    `frag_<vram>` unit and the function unit starts at its real entry; an
    automatic `func_<vram>` name follows the entry, other names are kept.
    """
    # Only the function's own instructions count; alignment nops follow endlabel.
    end = next((i for i, l in enumerate(body) if l.startswith("endlabel ")), len(body))
    insns = [(i, m) for i, l in enumerate(body[:end]) if (m := INSN.match(l))]
    words = [int.from_bytes(bytes.fromhex(m.group(2)), "little") for _i, m in insns]
    n = 0
    while (n + 2 < len(words) and words[n] >> 16 == 0x27BD and not words[n] & 0x8000
           and words[n + 1] == 0):
        n += 2
    if not n:
        return [body]
    cut = {i for i, _m in insns[:n]}
    vram, entry = int(insns[0][1].group(1), 16), int(insns[n][1].group(1), 16)
    rest, mark = [l for i, l in enumerate(body) if i not in cut], None
    for l in rest:
        if m := MARK.match(l.rstrip("\n")):
            mark = m
            break
    old = mark.group(1)
    new = f"func_{entry:08X}" if AUTO.match(old) else old
    frag = f"frag_{vram:08X}"
    head = [f"nonmatching {frag}, 0x{4 * n:X}\n", "\n", f"glabel {frag}\n"]
    # Code takes the entry's address as `%lo(func_<vram> + 8)`; the old name
    # stays defined at the fragment so those expressions keep their value.
    if new != old:
        head.append(f"  alabel {old}\n")
    pairs = head + [body[i] for i in sorted(cut)] + [f"endlabel {frag}\n", "\n"]
    size = f", 0x{int(mark.group(2), 16) - 4 * n:X}" if mark.group(2) else ""
    # splat may already mark the entry as an alternative entry of the unit.
    rest = [l for l in rest if l.split() != ["alabel", new]]
    rest = [f"nonmatching {new}{size}\n" if MARK.match(l.rstrip("\n"))
            else re.sub(rf"\b{re.escape(old)}\b", new, l) for l in rest]
    return [pairs, rest]


def unit_starts(lines: list[str]) -> list[int]:
    starts = []
    for i, line in enumerate(lines):
        if line.startswith("nonmatching "):
            s = i
            while s > 0 and lines[s - 1].startswith((".align", "/* Handwritten")):
                s -= 1
            starts.append(s)
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
    return merged


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("section_s", type=Path)
    ap.add_argument("out", type=Path)
    ap.add_argument("end", type=lambda s: int(s, 0), help="address one past the section's last byte")
    args = ap.parse_args()

    lines = args.section_s.read_text().splitlines(keepends=True)
    name, flags = next((m.group(1), m.group(2)) for l in lines if (m := SECTION.match(l)))
    header = f'.include "macro.inc"\n\n.set noat\n.set noreorder\n\n.section {name}.unit{flags}\n\n'
    starts = unit_starts(lines)
    if not starts:
        raise SystemExit(f"{args.section_s}: no units found")

    bodies = []
    for n, s in enumerate(starts):
        e = starts[n + 1] if n + 1 < len(starts) else len(lines)
        body = lines[s:e]
        if n == 0:
            # Lines before the first unit (leading padding) belong to it.
            body = [l for l in lines[:s] if ADDR.match(l)] + body
        start = next(int(m.group(1), 16) for l in body if (m := ADDR.match(l)))
        # gas aligns .word/.half to the unit's own start, so a unit that begins
        # off a word boundary and holds such data stays with the previous unit.
        if bodies and start % 4 and any(WIDE.match(l) for l in body):
            bodies[-1] += body
            continue
        bodies.extend(split_fragment(body))
    vrams = [next(int(m.group(1), 16) for l in b if (m := ADDR.match(l))) for b in bodies]

    args.out.mkdir(parents=True, exist_ok=True)
    for stale in args.out.glob("*.s"):
        stale.unlink()
    rows = []
    for n, body in enumerate(bodies):
        start = vrams[n]
        end = vrams[n + 1] if n + 1 < len(vrams) else args.end
        out = []
        for i, line in enumerate(body):
            if line.startswith(".align"):
                nxt = next((int(m.group(1), 16) for l in body[i + 1 :] if (m := ADDR.match(l))), end)
                out.append(f".org 0x{nxt - start:X}\n")
            else:
                out.append(line)
        out.append(f".org 0x{end - start:X}\n")
        mark = next(m for l in body if (m := MARK.match(l)))
        size = int(mark.group(2), 16) if mark.group(2) else end - start
        (args.out / f"{start:08X}.s").write_text(header + "".join(out))
        rows.append(f"{start:08X}\t{size:X}\t{mark.group(1)}\n")
    (args.out / "units.tsv").write_text("".join(rows))
    print(f"split {len(rows)} units into {args.out}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
