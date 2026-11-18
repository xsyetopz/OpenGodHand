#!/usr/bin/env python3
"""Compare a rebuilt file against the SHA-1 recorded in config/<name>.sha1.

On mismatch, print the first differing offsets against the user's original so
the failing section is obvious without a separate diff tool.
"""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main() -> int:
    built = Path(sys.argv[1])
    want = (ROOT / "config" / f"{built.name}.sha1").read_text().split()[0]
    data = built.read_bytes()
    got = hashlib.sha1(data).hexdigest()
    if got == want:
        print(f"{built}: OK")
        return 0
    print(f"{built}: FAILED (sha1 {got}, expected {want})", file=sys.stderr)
    orig = ROOT / "original/extracted" / built.name
    if orig.exists():
        ref = orig.read_bytes()
        diffs = [i for i in range(min(len(ref), len(data))) if ref[i] != data[i]]
        print(f"  size {len(data):#x} vs {len(ref):#x}; {len(diffs)} differing bytes", file=sys.stderr)
        for i in diffs[:8]:
            print(f"  {i:#08x}: {data[i]:02x} != {ref[i]:02x}", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
