"""Pad `div.s` with the nops the game's assembler put before it.

Below 0x3229D0 the game has 911 `div.s`: 585 follow two nops, 261 none, 62
one and 3 three, and both forms occur inside one function. The padding is the
assembler's R5900 divide-hazard workaround; no packaged ps2eeas reproduces
it, and no rule over the surrounding instructions predicts it exactly (the
best, 87.6%, is in docs/decomp.md). The compiler's scheduling around the
divide is already right, so the counts are recorded per function in the
source and inserted into the compiler's assembly before it is assembled:

    // FUNCTION: GAME 0x2EA798
    // DIVNOP: 2

lists the nops before each `div.s` of that function, in emission order.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402

TAG = re.compile(r"^//\s*DIVNOP:\s*(.*?)\s*$")
ENT = re.compile(r"^\s*\.(ent|end)\s+(\S+)")
DIV = re.compile(r"^\s*div\.s\s")


def spec(src: Path) -> dict[str, list[int]]:
    """Nop counts per function symbol, from the DIVNOP tags of a source file."""
    names = {vram: name for vram, _, name in configure.read_units()}
    found: dict[str, list[int]] = {}
    addr = None
    for line in src.read_text().splitlines():
        if m := configure.ANNOT.match(line):
            addr = int(m.group(1), 16)
        elif (m := TAG.match(line)) and addr is not None:
            found[names[addr]] = [int(n) for n in m.group(1).split()]
    return found


def pad(asm: str, counts: dict[str, list[int]]) -> str:
    out, func, seen = [], None, {}
    for line in asm.splitlines(keepends=True):
        if m := ENT.match(line):
            func = m.group(2) if m.group(1) == "ent" and m.group(2) in counts else None
            if func:
                seen[func] = 0
        elif DIV.match(line) and func is not None:
            n = seen[func]
            seen[func] = n + 1
            if n < len(counts[func]):
                out.append("\tnop\n" * counts[func][n])
        out.append(line)
    for name, want in counts.items():
        if seen.get(name) != len(want):
            raise SystemExit(f"divnop: {name}: {seen.get(name)} div.s emitted, DIVNOP lists {len(want)}")
    return "".join(out)


def original(vram: int) -> list[int]:
    """Nops before each `div.s` of the original function at vram."""
    size = {v: s for v, s, _ in configure.read_units()}[vram]
    data = (configure.ROOT / "original/extracted/SLUS_215.03").read_bytes()
    off = vram + 0x1000 - 0x100000
    words = [int.from_bytes(data[off + i : off + i + 4], "little") for i in range(0, size, 4)]
    counts = []
    for i, w in enumerate(words):
        if w >> 26 == 0x11 and (w >> 21) & 0x1F == 0x10 and w & 0x3F == 3:
            n = 0
            while i - n - 1 >= 0 and words[i - n - 1] == 0:
                n += 1
            counts.append(n)
    return counts


if __name__ == "__main__":
    # Print the tag for each address given, e.g. `divnop.py 0x2EA798`.
    for arg in sys.argv[1:]:
        print(f"// DIVNOP: {' '.join(map(str, original(int(arg, 16))))}")
