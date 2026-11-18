#!/usr/bin/env python3
"""Write the linker script, linking only compiled functions that match.

    linkgen.py build/link.json build/SLUS_215.03.link.ld

`build/link.json` (written by configure.py) lists every section's unit
directory and every annotated function as `[vram, object, symbol]`. Each
annotated function is compared with the original bytes (relocated fields
masked, as in fncmp.py). A match is placed at its address in place of its asm
unit. A mismatch keeps the asm unit; its compiled symbol is weakened in a
`.gated.o` copy of the object so the asm definition wins and calls from the
same source file still resolve. Every compiled object is linked through its
`.gated.o` copy.

`build/linkgen.tsv` records `vram  status  symbol` for each annotated function
(status `match` or `differ`), so a work-in-progress annotation never breaks
the build and the progress tools can tell which functions are linked.
"""

from __future__ import annotations

import json
import os
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import configure  # noqa: E402
import fncmp  # noqa: E402

ROOT = configure.ROOT


def matches(obj: Path, vram: int, sym: str, span: int, raw: bytes) -> bool:
    try:
        got, relocs = fncmp.compiled(obj, sym)
    except SystemExit:
        return False
    off = vram + fncmp.TEXT_OFF
    want = raw[off : off + span]
    # The unit span includes alignment padding after the function body.
    if len(got) > len(want) or want[len(got) :].strip(b"\0"):
        return False
    for i in range(0, len(got), 4):
        mask = fncmp.MASK.get(relocs.get(i), 0xFFFFFFFF)
        g, w = struct.unpack_from("<I", got, i)[0], struct.unpack_from("<I", want, i)[0]
        if (g ^ w) & mask:
            return False
    return True


def gated(obj: str) -> str:
    return obj[: -len(".o")] + ".gated.o"


def main() -> int:
    link_json, script = Path(sys.argv[1]), Path(sys.argv[2])
    cfg = json.loads(link_json.read_text())
    raw = fncmp.ORIG.read_bytes()
    sections = [(row, configure.read_units(row[4])) for row in cfg["sections"]]
    spans = {}
    text_units = sections[0][1]
    for n, (vram, _size, _name) in enumerate(text_units):
        end = text_units[n + 1][0] if n + 1 < len(text_units) else sections[0][0][2]
        spans[vram] = end - vram

    placed: dict[int, tuple[str, str]] = {}
    weak: dict[str, list[str]] = {o: [] for _v, o, _s in cfg["compiled"]}
    rows = []
    for vram, obj, sym in cfg["compiled"]:
        ok = matches(ROOT / obj, vram, sym, spans[vram], raw)
        if ok:
            placed[vram] = (gated(obj), f".text.{sym}")
        else:
            weak[obj].append(sym)
        rows.append(f"{vram:08X}\t{'match' if ok else 'differ'}\t{sym}\n")

    objcopy = os.environ.get("CROSS", "mipsel-linux-gnu-") + "objcopy"
    for obj, syms in weak.items():
        subprocess.check_call([objcopy, *(f"--weaken-symbol={s}" for s in syms), obj, gated(obj)], cwd=ROOT)

    script.write_text(configure.linker_script(sections, placed))
    (ROOT / "build/linkgen.tsv").write_text("".join(rows))
    differ = [r.split("\t")[2].strip() for r in rows if "\tdiffer\t" in r]
    print(f"linkgen: {len(placed)} compiled functions linked, {len(differ)} kept in asm"
          + (f" ({', '.join(differ[:5])}{', ...' if len(differ) > 5 else ''})" if differ else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
