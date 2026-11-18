#!/usr/bin/env python3
"""Score every `// DRAFT: GAME` function with decomp-permuter's base score.

    EECC_CONTAINER=eecc-perm python tools/permute_triage.py [-j4] [--retry] [ADDR ...]

Each draft gets a permuter directory from tools/permute.py under
build/permuter-triage/ (separate from build/permuter/, whose directories may
belong to running searches), then `permuter.py --debug` compiles the base
candidate and prints its base score. Results append to build/permuter/scores.tsv
(addr, file, score, target bytes, status), so a rerun skips scored addresses;
--retry redoes the ones whose status is not ok. Low scores on same-size
drafts are the ones worth a long permuter run: about 10 points per differing
word, more when the instruction count differs.
"""

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import configure  # noqa: E402

DRAFT = re.compile(r"^//\s*DRAFT:\s*GAME\s+0x([0-9A-Fa-f]+)")
TSV = ROOT / "build/permuter/scores.tsv"
WORK = ROOT / "build/permuter-triage"
PERMUTER = ROOT / "tools/ext/decomp-permuter/permuter.py"


def drafts() -> dict[int, Path]:
    found: dict[int, Path] = {}
    for src in sorted((ROOT / "src").rglob("*.cpp")):
        for line in src.read_text(errors="replace").splitlines():
            if m := DRAFT.match(line):
                found[int(m.group(1), 16)] = src
    return found


def classify(text: str) -> str:
    """Failure class from the permuter's or permute.py's output."""
    for needle, label in (
        ("Syntax error", "pycparser syntax error"),
        ("Unable to compile", "compile error"),
        ("divnop:", "divnop error"),
        ("No such file", "missing file"),
    ):
        if needle in text:
            return label
    last = [ln for ln in text.strip().splitlines() if ln.strip()]
    return "other: " + (last[-1][:80] if last else "no output")


def score(addr: int, src: Path, env: dict[str, str]) -> tuple[str, str]:
    """(score, status) for one draft."""
    out = WORK / f"{addr:08X}"
    prep = subprocess.run([sys.executable, str(ROOT / "tools/permute.py"), str(src), hex(addr), "--out", str(out)], capture_output=True, text=True, cwd=ROOT, env=env)
    if prep.returncode:
        return "", "prepare: " + classify(prep.stderr).removeprefix("other: ")
    try:
        run = subprocess.run([sys.executable, str(PERMUTER), "--debug", str(out)], capture_output=True, text=True, cwd=ROOT, env=env, timeout=300)
    except subprocess.TimeoutExpired:
        return "", "timeout"
    text = run.stdout + run.stderr
    if m := re.search(r"base score = (\d+)", text):
        return m.group(1), "ok"
    return "", classify(text)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("addrs", nargs="*", type=lambda s: int(s, 0), help="only these addresses")
    ap.add_argument("-j", type=int, default=4)
    ap.add_argument("--retry", action="store_true", help="redo addresses whose status is not ok")
    args = ap.parse_args()

    sizes = {v: s for v, s, _ in configure.read_units()}
    todo = {a: f for a, f in drafts().items() if a in sizes and (not args.addrs or a in args.addrs)}
    done: dict[int, list[str]] = {}
    if TSV.exists():
        for line in TSV.read_text().splitlines()[1:]:
            row = line.split("\t")
            done[int(row[0], 16)] = row
    if args.retry:
        done = {a: r for a, r in done.items() if r[4] == "ok"}
    todo = {a: f for a, f in todo.items() if a not in done}
    TSV.parent.mkdir(parents=True, exist_ok=True)
    if not TSV.exists() or not TSV.read_text().strip():
        TSV.write_text("addr\tfile\tscore\tbytes\tstatus\n")
    elif args.retry:
        keep = [f"0x{a:X}\t" + "\t".join(r[1:]) for a, r in sorted(done.items())]
        TSV.write_text("addr\tfile\tscore\tbytes\tstatus\n" + "".join(k + "\n" for k in keep))
    env = {**os.environ, "EECC_CONTAINER": os.environ.get("EECC_CONTAINER", "eecc-perm")}
    print(f"{len(todo)} drafts to score ({len(done)} already in {TSV.relative_to(ROOT)})", file=sys.stderr)

    def one(item: tuple[int, Path]) -> None:
        addr, src = item
        sc, status = score(addr, src, env)
        with TSV.open("a") as f:
            f.write(f"0x{addr:X}\t{src.relative_to(ROOT)}\t{sc}\t{sizes[addr]}\t{status}\n")

    with ThreadPoolExecutor(args.j) as pool:
        list(pool.map(one, sorted(todo.items())))
    return 0


if __name__ == "__main__":
    sys.exit(main())
