#!/usr/bin/env python3
"""Report which sources claim function addresses, and duplicate claims.

    python tools/claimed.py [0xADDR ...]

With addresses, prints the source claiming each one, or `free`. Without, it
lists every address claimed twice. Addresses compare numerically, so
`0x1FA6F8` and `0x001FA6F8` are the same claim. `#ifdef NONMATCHING` drafts
carry no annotation and do not count.
"""

from __future__ import annotations

import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402


def claims() -> dict[int, list[str]]:
    """Every claimed address with the sources (and repeats) that claim it."""
    found: dict[int, list[str]] = defaultdict(list)
    for src, addrs in configure.read_sources().items():
        for a in addrs:
            found[a].append(str(src))
    return found


def main() -> int:
    found = claims()
    if len(sys.argv) > 1:
        for arg in sys.argv[1:]:
            a = int(arg, 16)
            print(f"0x{a:X}\t{', '.join(found[a]) if a in found else 'free'}")
        return 0
    dups = {a: s for a, s in found.items() if len(s) > 1}
    for a, s in sorted(dups.items()):
        print(f"0x{a:X}\t{', '.join(s)}")
    return 1 if dups else 0


if __name__ == "__main__":
    sys.exit(main())
