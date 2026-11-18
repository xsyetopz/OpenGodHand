#!/usr/bin/env python3
"""Prepare a decomp-permuter directory for one draft function.

    python tools/permute.py src/game/Fn145238.cpp 0x145238
    .venv/bin/python tools/ext/decomp-permuter/permuter.py -j4 build/permuter/00145238

Drafts that differ from the original only in register allocation or
scheduling are searched mechanically by decomp-permuter (clone it into
tools/ext/decomp-permuter; it needs the `toml` package from requirements.txt).
The permuter wants a directory with base.c, target.o, compile.sh and
settings.toml; this script derives all four from the repository:

  base.c       the draft function plus the declarations around it, as plain C:
               `extern "C"` and NONMATCHING guards are stripped, other function
               bodies and tag comments are dropped (pycparser parses C only,
               and base.c may hold one function).
  target.o     asm/text/<addr>.s assembled with the project's ASFLAGS, so the
               original carries the same symbolic relocations as a compiled
               candidate.
  compile.sh   rebuilds a .cpp from the candidate: the FUNCTION/DIVNOP tag
               lines (divnop padding needs them), the candidate wrapped in
               extern "C" (it was plain C), then tools/eecc.py with the game
               flags. Only drafts made of C-compatible code can be permuted;
               references, bool, classes and cvecop.h inline asm are out.
  settings.toml  function name and the mipsel objdump for the R5900.
"""

from __future__ import annotations

import argparse
import re
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import configure  # noqa: E402

OUT = ROOT / "build/permuter"


def top_level_chunks(text: str) -> list[str]:
    """Split source into top-level declarations, function bodies and preprocessor lines."""
    chunks: list[str] = []
    cur, depth = "", 0
    for line in text.splitlines(keepends=True):
        if depth == 0 and not cur.strip() and line.lstrip().startswith("#"):
            chunks.append(line)
            continue
        cur += line
        depth += line.count("{") - line.count("}")
        stripped = line.strip()
        if depth == 0 and (stripped.endswith(";") or stripped.endswith("}")):
            chunks.append(cur)
            cur = ""
    if cur.strip():
        chunks.append(cur)
    return chunks


def make_base(src: Path, name: str) -> str:
    """The target function and the declarations before it, as C."""
    text = re.sub(r"//[^\n]*", "", src.read_text())
    text = re.sub(r'extern\s+"C"\s*', "", text)
    keep = []
    for chunk in top_level_chunks(text):
        if re.match(r"\s*#\s*(ifdef\s+NONMATCHING|endif)\b", chunk):
            continue
        body = chunk.rstrip().endswith("}") and "{" in chunk and not chunk.lstrip().startswith(("struct", "union", "enum", "typedef"))
        if body and not re.search(rf"\b{re.escape(name)}\s*\(", chunk):
            continue  # another function's body
        keep.append(chunk)
        if body:
            break  # declarations after the function are not needed
    return "".join(keep)


def divnop_tag(addr: int) -> str:
    out = subprocess.run([sys.executable, str(ROOT / "tools/divnop.py"), hex(addr)], capture_output=True, text=True, cwd=ROOT)
    return out.stdout.strip() if out.returncode == 0 else ""


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", type=Path)
    ap.add_argument("addr", type=lambda s: int(s, 0))
    ap.add_argument("--out", type=Path, help=f"directory (default {OUT}/<addr>)")
    args = ap.parse_args()

    size, name = {v: (s, n) for v, s, n in configure.read_units()}[args.addr]
    out = args.out or OUT / f"{args.addr:08X}"
    out.mkdir(parents=True, exist_ok=True)
    compiler, flags = configure.source_build(args.src)
    pick = f"--compiler {compiler} " if compiler else ""

    (out / "base.c").write_text(make_base(args.src, name))

    asm = ROOT / f"asm/text/{args.addr:08X}.s"
    cmd = [configure.tool("as"), *shlex.split(configure.ASFLAGS), "-o", str(out / "target.o"), str(asm)]
    if subprocess.call(cmd, cwd=ROOT):
        return 1

    tags = f"// FUNCTION: GAME 0x{args.addr:X}\\n"
    if tag := divnop_tag(args.addr):
        tags += tag + "\\n"
    script = f"""#!/bin/bash
# usage: compile.sh candidate.c -o out.o
set -e
cd {ROOT}
work=$(mktemp -d build/permuter.XXXXXX)
trap 'rm -rf "$work"' EXIT
{{ printf '{tags}extern "C" {{\\n'; cat "$1"; printf '\\n}}\\n'; }} > "$work/f.cpp"
{shlex.quote(sys.executable)} tools/eecc.py {pick}{flags} -c -o "$work/f.o" "$work/f.cpp"
cp "$work/f.o" "$3"
"""
    (out / "compile.sh").write_text(script)
    (out / "settings.toml").write_text(
        f'func_name = "{name}"\ncompiler_type = "gcc"\nobjdump_command = "{configure.tool("objdump")} -drz -m mips:5900"\n'
    )
    print(f"wrote {out}\nrun: .venv/bin/python tools/ext/decomp-permuter/permuter.py -j4 {out.relative_to(ROOT) if out.is_relative_to(ROOT) else out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
