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
    """Split preprocessed source into top-level declarations and function bodies."""
    chunks: list[str] = []
    cur, depth = "", 0
    for line in text.splitlines(keepends=True):
        cur += line
        depth += line.count("{") - line.count("}")
        stripped = line.strip()
        if depth == 0 and (stripped.endswith(";") or stripped.endswith("}")):
            chunks.append(cur)
            cur = ""
    if cur.strip():
        chunks.append(cur)
    return chunks


def c_name(unit: str, text: str, addr: int) -> str:
    """Name the function carries in base.c: the unit name for extern "C" code, else func_<ADDR>.

    A C++ unit (`Turn_dest__FPCffT0f`) is defined in the source under its
    unmangled name; base.c gets a C name and target.o's symbol is renamed to it.
    """
    if re.search(rf"\b{re.escape(unit)}\s*\(", text) or "__" not in unit:
        return unit
    return f"func_{addr:08X}"


def make_base(src: Path, name: str, addr: int) -> tuple[str, str]:
    """The target function and the declarations before it as C, and its C name.

    The source goes through the compiler's preprocessor first (project includes,
    macros, NONMATCHING drafts), since the permuter preprocesses base.c without
    include paths.
    """
    cmd = ["cc", "-E", "-P", "-x", "c++", "-nostdinc", "-DNONMATCHING", f"-I{ROOT / 'src'}", f"-I{ROOT / 'include'}", str(src)]
    text = subprocess.run(cmd, capture_output=True, text=True, check=True).stdout
    text = re.sub(r'extern\s+"C"\s*', "", text)
    cname = c_name(name, text, addr)
    pattern = name if cname == name else name.split("__")[0]
    keep = []
    for chunk in top_level_chunks(text):
        body = chunk.rstrip().endswith("}") and "{" in chunk and not chunk.lstrip().startswith(("struct", "union", "enum", "typedef", "class", "static", "inline"))
        if body and not re.search(rf"\b{re.escape(pattern)}\s*\(", chunk):
            continue  # another function's body
        if body:
            keep.append(re.sub(rf"\b{re.escape(pattern)}\s*\(", cname + "(", chunk, count=1))
            break  # declarations after the function are not needed
        keep.append(chunk)
    return "".join(keep), cname


def divnop_tag(src: Path, addr: int) -> str:
    """The DIVNOP line for the function: the draft's own tag, else divnop.py's count.

    divnop.py counts every zero word before a div.s, including a nop the
    compiler emits itself, so the count written under the draft's tag (the
    nops to insert) wins when present.
    """
    mine = False
    for line in src.read_text().splitlines():
        if m := configure.ANNOT.match(line) or re.match(r"//\s*DRAFT:\s*GAME\s+0x([0-9A-Fa-f]+)", line):
            mine = int(m.group(1), 16) == addr
        if mine and (m := re.search(r"DIVNOP:\s*(\d+(?:\s+\d+)*)", line)):
            return f"// DIVNOP: {m.group(1)}"
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

    base, cname = make_base(args.src, name, args.addr)
    (out / "base.c").write_text(base)

    asm = ROOT / f"asm/text/{args.addr:08X}.s"
    cmd = [configure.tool("as"), *shlex.split(configure.ASFLAGS), "-o", str(out / "target.o"), str(asm)]
    if subprocess.call(cmd, cwd=ROOT):
        return 1
    if cname != name:  # C++ unit: the candidate is built under its C name
        subprocess.check_call([configure.tool("objcopy"), "--redefine-sym", f"{name}={cname}", str(out / "target.o")])

    tags = f"// FUNCTION: GAME 0x{args.addr:X}\\n"
    if tag := divnop_tag(args.src, args.addr):
        tags += tag + "\\n"
    rename = cname != name  # C++ unit: build under the unit name so divnop applies, then rename
    if rename:
        tags += f"#define {cname} {name}\\n"
    fix = f'{configure.tool("objcopy")} --redefine-sym {name}={cname} "$work/f.o"\n' if rename else ""
    script = f"""#!/bin/bash
# usage: compile.sh candidate.c -o out.o
set -e
cd {ROOT}
work=$(mktemp -d build/permuter.XXXXXX)
trap 'rm -rf "$work"' EXIT
{{ printf '{tags}extern "C" {{\\n'; cat "$1"; printf '\\n}}\\n'; }} > "$work/f.cpp"
{shlex.quote(sys.executable)} tools/eecc.py {pick}{flags} -c -o "$work/f.o" "$work/f.cpp"
{fix}cp "$work/f.o" "$3"
"""
    (out / "compile.sh").write_text(script)
    (out / "settings.toml").write_text(
        f'func_name = "{cname}"\ncompiler_type = "gcc"\nobjdump_command = "{configure.tool("objdump")} -drz -m mips:5900"\n'
    )
    print(f"wrote {out}\nrun: .venv/bin/python tools/ext/decomp-permuter/permuter.py -j4 {out.relative_to(ROOT) if out.is_relative_to(ROOT) else out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
