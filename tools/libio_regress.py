#!/usr/bin/env python3
"""Check every annotated function of the libio sources against the original bytes.

    python tools/libio_regress.py [DIR]       (default: src/sce/libio)

A header change such as a typedef touches many units at once. Each source in DIR
is compiled once, and each `// FUNCTION: GAME 0x...` in it is compared with the
original executable (relocated words on their opcode fields). The output lists
one line per unit: MATCH, "N diff" or "nosym" (the object has no section for the
unit's name). Run it before and after a shared-header edit and diff the output.
"""
import sys, re, subprocess, shlex
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import fncmp, configure
from concurrent.futures import ThreadPoolExecutor
ORIG = fncmp.ORIG.read_bytes()
U = fncmp.units()
def run(src):
    src = Path(src)
    addrs = [int(m, 16) for m in re.findall(r"^// FUNCTION: GAME 0x([0-9A-Fa-f]+)", src.read_text(), re.M)]
    obj = ROOT / "build/fncmp/libio_regress" / (src.name + ".o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    comp, flags = configure.source_build(src)
    pick = ["--compiler", comp] if comp else []
    if subprocess.call([sys.executable, str(ROOT/"tools/eecc.py"), *pick, *shlex.split(flags), "-c", "-o", str(obj), str(src)], cwd=ROOT, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
        return [(str(src), "COMPILE FAIL")]
    out = []
    for a in addrs:
        size, name = U[a]
        try:
            got, relocs, names = fncmp.compiled(obj, name)
        except SystemExit:
            out.append((f"{src.name} {a:X} {name}", "nosym")); continue
        want = ORIG[a + fncmp.TEXT_OFF: a + fncmp.TEXT_OFF + size]
        while len(want) > len(got) and want[-4:] == bytes(4): want = want[:-4]
        bad = 0
        for off in range(0, max(len(got), len(want)), 4):
            g = got[off:off+4]; w = want[off:off+4]
            if len(g) < 4 or len(w) < 4: bad += 1; continue
            gi = int.from_bytes(g, "little"); wi = int.from_bytes(w, "little")
            m = fncmp.MASK.get(relocs.get(off), 0xFFFFFFFF)
            bad += (gi & m) != (wi & m)
        out.append((f"{src.name} {a:X} {name}", "MATCH" if not bad else f"{bad} diff"))
    obj.unlink(missing_ok=True)
    return out
target = ROOT / (sys.argv[1] if len(sys.argv) > 1 else "src/sce/libio")
files = sorted(str(p) for p in target.glob("*.c*"))
with ThreadPoolExecutor(4) as ex:
    for res in ex.map(run, files):
        for k, v in res: print(k, v)
