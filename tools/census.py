"""List free asm units: neither claimed by a FUNCTION tag nor held as a DRAFT.

Usage: census.py 0xLO 0xHI [MINSZ MAXSZ]

Prints one line per free unit in [LO, HI) whose size in bytes lies in
[MINSZ, MAXSZ] (default 40-240). Unit size is the distance to the next unit
in asm/text, so the last unit is never listed. Run from the repository root.
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import claimed  # noqa: E402


def main(argv):
    """Print free units in the requested address and size window."""
    if len(argv) not in (3, 5):
        sys.exit(__doc__)
    lo, hi = (int(x, 16) for x in argv[1:3])
    mn, mx = (int(x) for x in argv[3:5]) if len(argv) == 5 else (40, 240)
    names = sorted(
        int(p.stem, 16)
        for p in Path("asm/text").glob("*.s")
        if len(p.stem) == 8 and all(c in "0123456789ABCDEFabcdef" for c in p.stem)
    )
    taken = set(claimed.claims()) | set(claimed.drafts())
    for a, b in zip(names, names[1:]):
        if lo <= a < hi and a not in taken and mn <= b - a <= mx:
            print(f"0x{a:06X} {b - a}")


if __name__ == "__main__":
    main(sys.argv)
