"""List free asm units: neither claimed by a FUNCTION tag nor held as a DRAFT.

Usage: census.py [--all] 0xLO 0xHI [MINSZ MAXSZ]

Prints one line per free unit in [LO, HI) whose size in bytes lies in
[MINSZ, MAXSZ] (default 40-240). Unit size is the distance to the next unit
in asm/text, so the last unit is never listed. Splitter fragments (units
with neither a `jr $ra` nor a stack-adjust prologue) are dropped and counted
on the last line unless --all is given. Run from the repository root.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import claimed  # noqa: E402


def is_real(addr):
    """Return True if the unit at addr has a `jr $ra` or an `addiu $sp, $sp, -N`."""
    text = Path(f"asm/text/{addr:08X}.s")
    if not text.exists():
        text = next(Path("asm/text").glob(f"{addr:08x}.s"), text)
    return bool(re.search(r"\bjr\s+\$ra\b|\baddiu\s+\$sp, \$sp, -", text.read_text()))


def main(argv):
    """Print free units in the requested address and size window."""
    show_all = "--all" in argv
    argv = [a for a in argv if a != "--all"]
    if len(argv) not in (3, 5):
        sys.exit(__doc__)
    lo, hi = (int(x, 16) for x in argv[1:3])
    mn, mx = (int(x) for x in argv[3:5]) if len(argv) == 5 else (40, 240)
    names = sorted(
        int(p.stem, 16)
        for p in Path("asm/text").glob("*.s")
        if len(p.stem) == 8 and all(c in "0123456789ABCDEFabcdef" for c in p.stem)
    )
    dropped = 0
    taken = set(claimed.claims()) | set(claimed.drafts())
    for a, b in zip(names, names[1:]):
        if lo <= a < hi and a not in taken and mn <= b - a <= mx:
            if show_all or is_real(a):
                print(f"0x{a:06X} {b - a}")
            else:
                dropped += 1
    if not show_all:
        print(f"# dropped {dropped} fragments")


if __name__ == "__main__":
    main(sys.argv)
