#!/usr/bin/env python3
"""Propose function names for CRI middleware units from embedded error strings.

CRI libraries embed their function names in strings such as
"E9040801:partition ID is range outside.(adxf_ChkPrmPt)". A unit that
addresses such a string through a %hi/%lo pair and names exactly one function
is proposed as that function. Version strings ("ADXT/PS2EE Ver.9.67 ...") give
each library an address span from the units that reference them.

    python tools/crinames.py [--text asm/text] [--rodata asm/data/rodata.rodata.s]
                             [--spans] [--range LO HI]

Output is TSV: vram, current name, proposed name, evidence string. With
--spans, a span table per library follows on stderr-free stdout lines
prefixed "#". Nothing under config/ is modified.
"""
import argparse
import bisect
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

STR = re.compile(r'/\*\s*\w+\s+([0-9A-F]{8})\s*\*/\s+\.asciz\s+"((?:[^"\\]|\\.)*)"')
PAREN = re.compile(r"\(([A-Za-z][A-Za-z0-9]*_[A-Za-z0-9_]+)\)$")
COLON = re.compile(r"^(?:E\d{8}:)?([A-Za-z][A-Za-z0-9]*_[A-Za-z0-9_]+):")
VER = re.compile(rb"\n((?:CRI )?[A-Z][A-Za-z0-9]*(?:/PS2EE)?) +Ver\.[0-9.]+ Build:")
BASE, TEXT_END = 0x100000, 0x41B580
HILO = re.compile(r"%hi\((D_[0-9A-F]{8})\)")
GLABEL = re.compile(r"^glabel (\S+)", re.M)


def load_strings(path):
    """Return sorted starts and a dict start -> (end, text) for every .asciz."""
    table = {}
    for m in STR.finditer(Path(path).read_text()):
        text = m.group(2)
        table[int(m.group(1), 16)] = (int(m.group(1), 16) + len(text) + 1, text)
    return sorted(table), table


def lookup(starts, table, addr):
    """Find the string covering addr, or None."""
    i = bisect.bisect_right(starts, addr) - 1
    if i >= 0 and addr < table[starts[i]][0]:
        return table[starts[i]][1]
    return None


def func_name(text):
    """Extract the function name an error string embeds, or None."""
    for rx in (PAREN, COLON):
        m = rx.search(text) if rx is PAREN else rx.match(text)
        if m and re.search(r"[a-z]", m.group(1)):
            return m.group(1)
    return None


def version_refs(binary, units):
    """Map library -> units whose code loads its version string.

    The version text is found in the executable image (some strings sit in
    alignment padding the asm dump omits). A reference is a lui/addiu pair on
    the string address, or on a data word that stores the string address.
    """
    img = Path(binary).read_bytes()
    words = struct.unpack("<%dI" % (len(img) // 4), img[: len(img) // 4 * 4])
    libs = {m.group(1).decode(): m.start() + BASE for m in VER.finditer(img)}
    out = defaultdict(set)
    for lib, addr in libs.items():
        ptrs = [addr] + [i * 4 + BASE for i, w in enumerate(words) if w == addr]
        for t in ptrs:
            hi, lo = (t + 0x8000) >> 16, t & 0xFFFF
            for i in range((TEXT_END - BASE) // 4):
                w = words[i]
                if w >> 16 & 0xFFE0 == 0x3C00 and w & 0xFFFF == hi:
                    reg = w >> 16 & 0x1F
                    for j in range(i + 1, min(i + 9, len(words))):
                        x = words[j]
                        if x >> 26 in (9, 13, 35, 55) and x >> 21 & 0x1F == reg and x & 0xFFFF == lo:
                            k = bisect.bisect_right(units, i * 4 + BASE) - 1
                            out[lib].add(units[k])
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--text", default="asm/text")
    ap.add_argument("--rodata", default="asm/data/rodata.rodata.s")
    ap.add_argument("--spans", action="store_true", help="print per-library version spans")
    ap.add_argument("--binary", default="build/SLUS_215.03.rom", help="executable image for version strings")
    ap.add_argument("--range", nargs=2, metavar=("LO", "HI"), default=["0x328098", "0x36F048"],
                    help="range counted in the summary line")
    a = ap.parse_args()
    lo, hi = (int(x, 16) for x in a.range)
    starts, table = load_strings(a.rodata)
    props, spans, inrange = [], defaultdict(list), 0
    for f in sorted(Path(a.text).glob("*.s")):
        src = f.read_text()
        vram = int(f.stem, 16)
        names = {}
        for sym in set(HILO.findall(src)):
            s = lookup(starts, table, int(sym[2:], 16))
            if s is None:
                continue
            n = func_name(s)
            if n:
                names.setdefault(n, s)
        cur = (GLABEL.search(src) or [None, "?"])[1]
        if len(names) == 1 and cur.startswith("func_"):
            n, ev = next(iter(names.items()))
            props.append((vram, cur, n, ev))
            spans[n.split("_")[0].upper() + " (names)"].append(vram)
            inrange += lo <= vram < hi
    for vram, cur, n, ev in props:
        print("0x%08X\t%s\t%s\t%s" % (vram, cur, n, ev.replace("\t", " ")))
    print("# proposals: %d, in 0x%X-0x%X: %d" % (len(props), lo, hi, inrange))
    if a.spans:
        units = sorted(int(f.stem, 16) for f in Path(a.text).glob("*.s"))
        for lib, v in version_refs(a.binary, units).items():
            spans[lib + " (ver)"] = sorted(v)
        for k in sorted(spans, key=lambda k: min(spans[k])):
            v = spans[k]
            print("# %-16s 0x%08X-0x%08X  %d unit(s)" % (k, min(v), max(v), len(v)))


if __name__ == "__main__":
    sys.exit(main())
