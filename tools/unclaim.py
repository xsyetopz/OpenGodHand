#!/usr/bin/env python3
"""Delete tagged function definitions from a source so their units revert to asm.

    python tools/unclaim.py src/game/Foo.cpp 0x30A2B0 [0x30A328 ...]

Library code (SDK, CRI, newlib) that was hand-decompiled leaves the source tree
this way: the original assembly builds the same bytes and the game-only
progress no longer depends on it. Each `// FUNCTION:` or `// DRAFT:` tag for a
listed address is removed together with the comment lines directly above it
and the definition below it, found by brace counting. An enclosing
`#ifdef NONMATCHING` ... `#endif` pair that ends up empty is removed too. A file
left with no tags is deleted.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

TAG = re.compile(r"^// (?:FUNCTION|DRAFT): GAME 0x([0-9A-Fa-f]+)")


def strip(lines: list[str], addr: int) -> list[str]:
    i = next((k for k, s in enumerate(lines) if (m := TAG.match(s)) and int(m.group(1), 16) == addr), None)
    if i is None:
        raise SystemExit(f"no tag for 0x{addr:X}")
    start = i
    while start > 0 and lines[start - 1].startswith("//") and not TAG.match(lines[start - 1]):
        start -= 1
    end, depth, opened = i + 1, 0, False
    while end < len(lines):
        s = lines[end]
        if s.startswith("#") and not opened:  # `#ifdef NONMATCHING` between tag and body
            end += 1
            continue
        depth += s.count("{") - s.count("}")
        opened = opened or "{" in s
        end += 1
        if opened and depth <= 0:
            break
    out = lines[:start] + lines[end:]
    # Drop an `#ifdef NONMATCHING` / `#endif` pair left with only blank lines.
    text = re.sub(r"#ifdef NONMATCHING\n(?:\s*\n)*#endif\n", "", "\n".join(out) + "\n")
    return re.sub(r"\n{3,}", "\n\n", text).rstrip("\n").split("\n")


def main() -> int:
    path, addrs = Path(sys.argv[1]), [int(a, 0) for a in sys.argv[2:]]
    lines = path.read_text().rstrip("\n").split("\n")
    for a in addrs:
        lines = strip(lines, a)
    if not any(TAG.match(s) for s in lines):
        path.unlink()
        print(f"{path}: removed (no tags left)")
    else:
        path.write_text("\n".join(lines) + "\n")
        print(f"{path}: removed {len(addrs)} definitions")
    return 0


if __name__ == "__main__":
    sys.exit(main())
