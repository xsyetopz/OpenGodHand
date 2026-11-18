#!/usr/bin/env python3
"""Minimal ISO9660 reader/patcher for the God Hand disc image.

Reads files from the user's ISO without host tools, and produces a rebuilt
disc by replacing a file's extent in a copy of the original image. Because the
rebuilt executable has the original size, a matching executable yields a
byte-identical ISO.
"""

from __future__ import annotations

import argparse
import hashlib
import shutil
import struct
import sys
from pathlib import Path

SECTOR = 2048


def _records(img, lba: int, size: int):
    img.seek(lba * SECTOR)
    data = img.read(size)
    pos = 0
    while pos < len(data):
        length = data[pos]
        if length == 0:
            # Records never straddle sectors; skip to the next sector.
            pos = (pos // SECTOR + 1) * SECTOR
            continue
        rec = data[pos : pos + length]
        ext_lba, ext_size = struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0]
        flags = rec[25]
        name_len = rec[32]
        name = rec[33 : 33 + name_len].decode("ascii", "replace")
        yield name, ext_lba, ext_size, bool(flags & 2)
        pos += length


def find(img, path: str):
    """Return (lba, size) of `path` (slash-separated, case-insensitive)."""
    img.seek(16 * SECTOR)
    pvd = img.read(SECTOR)
    if pvd[1:6] != b"CD001":
        raise SystemExit("not an ISO9660 image")
    root = pvd[156:190]
    lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    parts = [p for p in path.upper().split("/") if p]
    for i, part in enumerate(parts):
        for name, e_lba, e_size, is_dir in _records(img, lba, size):
            if name.split(";")[0] == part:
                lba, size = e_lba, e_size
                break
        else:
            raise SystemExit(f"{path}: not found in ISO")
    return lba, size


def cmd_extract(args) -> int:
    with open(args.iso, "rb") as img:
        lba, size = find(img, args.path)
        img.seek(lba * SECTOR)
        data = img.read(size)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_bytes(data)
    return 0


def cmd_patch(args) -> int:
    new = args.file.read_bytes()
    with open(args.iso, "rb") as img:
        lba, size = find(img, args.path)
    if len(new) != size:
        raise SystemExit(f"{args.file}: size {len(new):#x} differs from ISO extent {size:#x}")
    args.out.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(args.iso, args.out)
    with open(args.out, "r+b") as img:
        img.seek(lba * SECTOR)
        img.write(new)
    return 0


def cmd_sha1(args) -> int:
    h = hashlib.sha1()
    with open(args.file, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    print(h.hexdigest())
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    sub = ap.add_subparsers(required=True)
    p = sub.add_parser("extract", help="copy one file out of the ISO")
    p.add_argument("iso", type=Path)
    p.add_argument("path")
    p.add_argument("out", type=Path)
    p.set_defaults(fn=cmd_extract)
    p = sub.add_parser("patch", help="write a copy of the ISO with one file replaced in place")
    p.add_argument("iso", type=Path)
    p.add_argument("path")
    p.add_argument("file", type=Path)
    p.add_argument("out", type=Path)
    p.set_defaults(fn=cmd_patch)
    p = sub.add_parser("sha1", help="print a file's SHA-1")
    p.add_argument("file", type=Path)
    p.set_defaults(fn=cmd_sha1)
    args = ap.parse_args()
    return args.fn(args)


if __name__ == "__main__":
    sys.exit(main())
