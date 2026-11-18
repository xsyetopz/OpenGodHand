#!/usr/bin/env python3
"""List free units whose mnemonic skeleton equals that of a matched or claimed unit.

Units are grouped by the sequence of instruction mnemonics in asm/text/<ADDR>.s
(nops ignored). Each output row reads:

    <free count> <skeleton length> <anchor addr> <free addrs...>

Usage:
    tools/skel.py [-n ROWS] [--min-len N] [--max-addrs N]
                  [--linkgen build/linkgen.tsv] [--asm asm/text]

Run from the repository root. Anchors are `match` rows of linkgen.tsv plus
functions already claimed by a source file; frag_* and tiny units are skipped,
and units held as a DRAFT are not listed as free.
"""
import argparse
import collections
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import configure  # noqa: E402
import claimed as claimed_mod  # noqa: E402
import objdiff_config  # noqa: E402


def skeleton(path):
    out = []
    for line in open(path):
        if "/*" not in line:
            continue
        tok = line.split("*/")[-1].split()
        if tok and tok[0] != "nop":
            out.append(tok[0])
    return tuple(out)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("-n", "--rows", type=int, default=25, help="rows to print")
    ap.add_argument("--min-len", type=int, default=6, help="minimum skeleton length (exclusive)")
    ap.add_argument("--max-addrs", type=int, default=200, help="free addresses printed per row")
    ap.add_argument("--linkgen", default="build/linkgen.tsv")
    ap.add_argument("--asm", default="asm/text")
    a = ap.parse_args()

    matched = set()
    for line in open(a.linkgen):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 3 and p[1] == "match":
            matched.add(int(p[0], 16))
    claimed = {x for al in configure.read_sources().values() for x in al}
    # Drafted units belong to decomp-worker, so they are neither free nor anchors.
    drafted = set(claimed_mod.drafts())
    # SDK, CRI and libc units stay asm or come from upstream, so only Game units are free.
    listed = objdiff_config.game_units()
    groups = collections.defaultdict(list)
    for addr, size, name in configure.read_units():
        if name.startswith("frag_") or size < 0x20:
            continue
        try:
            groups[skeleton("%s/%08X.s" % (a.asm, addr))].append(addr)
        except OSError:
            pass
    rows = []
    for key, units in groups.items():
        anchors = [x for x in units if x in matched or x in claimed]
        free = [x for x in units if x not in matched and x not in claimed and x not in drafted
                and objdiff_config.region(x, listed) == "game"]
        if anchors and free and len(key) > a.min_len:
            rows.append((len(free), len(key), min(anchors), sorted(free)))
    rows.sort(reverse=True)
    for n, length, anchor, free in rows[: a.rows]:
        print(n, length, hex(anchor), " ".join(hex(x) for x in free[: a.max_addrs]))


if __name__ == "__main__":
    main()
