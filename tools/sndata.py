#!/usr/bin/env python3
"""Decode the SN Systems SNR2 symbol table stored in the `.sndata` section.

Layout (all little-endian u32, pointers are absolute EE addresses):

    +0x00  magic "SNR2"
    +0x04  ptr  -> table A (unnamed 12-byte records)
    +0x08  u32     table A record count
    +0x0C  ptr  -> table B (named 12-byte records)
    +0x10  u32     table B record count
    +0x20  ptr  -> end of tables
    +0x2C  u32     end offset relative to section start
    +0x3C  NUL-separated mangled name pool

Table B records are (name_ptr, address, info). Record 0 is a sentinel with an
empty name. The meaning of `info` is not yet known; it is preserved verbatim.
"""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile


def load(elf_path: Path):
    with elf_path.open("rb") as f:
        elf = ELFFile(f)
        sec = elf.get_section_by_name(".sndata")
        text = elf.get_section_by_name(".text")
        if sec is None:
            raise SystemExit(f"{elf_path}: no .sndata section")
        data = sec.data()
        base = sec["sh_addr"]
        text_range = (text["sh_addr"], text["sh_addr"] + text["sh_size"])

    if data[:4] != b"SNR2":
        raise SystemExit(f"{elf_path}: .sndata magic is {data[:4]!r}, expected SNR2")

    hdr = struct.unpack_from("<12I", data, 0)

    def cstr(ptr: int) -> str:
        off = ptr - base
        return data[off : data.index(b"\0", off)].decode("ascii")

    named = []
    off_b = hdr[3] - base
    for i in range(hdr[4]):
        name_ptr, addr, info = struct.unpack_from("<3I", data, off_b + i * 12)
        name = cstr(name_ptr)
        if name:
            named.append((addr, name, info))

    unnamed = []
    off_a = hdr[1] - base
    for i in range(hdr[2]):
        unnamed.append(struct.unpack_from("<3I", data, off_a + i * 12))

    return named, unnamed, text_range


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("elf", type=Path)
    ap.add_argument("--splat", type=Path, help="write splat symbol_addrs lines")
    ap.add_argument("--dump", action="store_true", help="print all decoded records")
    args = ap.parse_args()

    named, unnamed, (t0, t1) = load(args.elf)

    if args.dump:
        for addr, name, info in sorted(named):
            print(f"{addr:08X} {info:08X} {name}")
        for rec in unnamed:
            print("A " + " ".join(f"{w:08X}" for w in rec))

    if args.splat:
        lines = []
        seen: set[str] = set()
        for addr, name, _info in sorted(named):
            # Address 0 marks entries the SN linker left unresolved; they have no placement.
            if addr == 0 or name in seen:
                continue
            seen.add(name)
            tag = " // type:func" if t0 <= addr < t1 else ""
            lines.append(f"{name} = 0x{addr:08X};{tag}\n")
        args.splat.write_text("".join(lines))
        print(f"wrote {len(lines)} symbols to {args.splat}", file=sys.stderr)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
