#!/usr/bin/env python3
"""Carry names from the 2006-06-20 preview build (SLPM_665.50) onto retail units.

    python tools/protomap.py [--min-votes N]

The preview disc's SNR2 table names 70 functions retail drops, and its debug
prints ("espModSys::getMotData() ID[%d] invalid") name functions retail never
names. Code moved and changed between builds, so matching works on opcode and
register fields only (immediates and jump targets masked):

- `SYM`: preview-only SNR2 names whose whole body occurs once in retail.
- `DBG`: debug-print names; the 80 instructions around the string reference
  vote for a retail offset through shared 6-instruction runs. Fewer than 20
  votes proved unreliable (KillEffect landed inside MtxMulScaleVec).

The preview ELF is read from original/SLUS-21503-prototype-2006-06-20/extracted/,
which, like every disc extract, stays out of git.
"""

from __future__ import annotations

import argparse
import bisect
import collections
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402
import sndata  # noqa: E402

PROTO = configure.ROOT / "original/SLUS-21503-prototype-2006-06-20/extracted/SLPM_665.50"
RETAIL = configure.ROOT / "original/extracted/SLUS_215.03"
K = 6


def mask(w: int) -> int:
    op = w >> 26
    if op in (2, 3):
        return w & 0xFC000000
    if op in (0, 0x1C):
        return w
    return w & 0xFFFF0000


def words(elf: ELFFile, name: str) -> tuple[int, tuple[int, ...]]:
    s = elf.get_section_by_name(name)
    d = s.data()
    return s["sh_addr"], struct.unpack(f"<{len(d) // 4}I", d)


def debug_strings(elf: ELFFile) -> dict[int, tuple[str, str]]:
    out = {}
    for sec in (".rodata", ".data"):
        s = elf.get_section_by_name(sec)
        base, d = s["sh_addr"], s.data()
        for m in re.finditer(rb"([A-Za-z_]\w{3,})\(\)", d):
            s0 = d.rfind(b"\0", 0, m.start()) + 1
            text = d[s0 : d.index(b"\0", m.start())].decode("latin1")
            out[base + s0] = (m.group(1).decode(), text[:60])
    return out


def string_refs(pw, strs) -> dict[int, list[int]]:
    """Word indices of `lui` whose paired `addiu` forms a debug-string address."""
    refs = collections.defaultdict(list)
    for i, w in enumerate(pw):
        if w >> 26 != 0xF:
            continue
        reg, hi = (w >> 16) & 31, w & 0xFFFF
        for x in pw[i + 1 : i + 10]:
            if x >> 26 == 9 and (x >> 21) & 31 == reg:
                lo = x & 0xFFFF
                a = ((hi << 16) + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
                if a in strs:
                    refs[a].append(i)
                break
    return refs


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--min-votes", type=int, default=20)
    args = ap.parse_args()
    if not PROTO.exists():
        raise SystemExit(f"{PROTO}: extract SLPM_665.50 from the preview disc first")

    pn, pu, pt = sndata.load(PROTO)
    rn, _, _ = sndata.load(RETAIL)
    pe, re_ = ELFFile(PROTO.open("rb")), ELFFile(RETAIL.open("rb"))
    pb, pw = words(pe, ".text")
    rb, rw = words(re_, ".text")
    pm, rm = [mask(w) for w in pw], [mask(w) for w in rw]
    idx: dict[tuple, list[int]] = {}
    for i in range(len(rm) - K):
        idx.setdefault(tuple(rm[i : i + K]), []).append(i)
    units = configure.read_units()
    ustart = [u[0] for u in units]

    def unit_at(addr: int) -> str:
        u = units[bisect.bisect_right(ustart, addr) - 1]
        return f"{u[2]} @0x{u[0]:X}"

    retail_names = {n for _, n, _ in rn}
    starts = sorted({a for a, _, _ in pn if pt[0] <= a < pt[1]} | {r[1] for r in pu if pt[0] <= r[1] < pt[1]})
    for a, n, _ in sorted(pn):
        if not pt[0] <= a < pt[1] or n in retail_names:
            continue
        length = (next((s for s in starts if s > a), pt[1]) - a) // 4
        seq = pm[(a - pb) // 4 : (a - pb) // 4 + length]
        hits = [h for h in idx.get(tuple(seq[:K]), []) if rm[h : h + length] == seq] if length >= K else []
        if len(hits) == 1:
            print(f"SYM\t{n}\t{unit_at(rb + hits[0] * 4)}")

    strs = debug_strings(pe)
    for a, refs in sorted(string_refs(pw, strs).items(), key=lambda kv: strs[kv[0]]):
        name, text = strs[a]
        for i in refs:
            votes = collections.Counter()
            for k in range(max(0, i - 40), min(len(pm) - K, i + 40)):
                for h in idx.get(tuple(pm[k : k + K]), [])[:50]:
                    votes[h - k] += 1
            if votes and (best := votes.most_common(1)[0])[1] >= args.min_votes:
                print(f"DBG\t{name}\t{unit_at(rb + (i + best[0]) * 4)}\tvotes {best[1]}\t{text}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
