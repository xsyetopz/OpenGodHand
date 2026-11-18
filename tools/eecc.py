#!/usr/bin/env python3
"""Run SCE ee-gcc 2.96 (2.96-ee-001003-1) on any host.

The executable's version string "GCC2096 SCE3020" identifies the compiler. The
only available build of it is a set of i386 Linux binaries, so on other hosts
the wrapper runs them in an `i386/debian` container (Docker or a compatible
CLI named by `EECC_DOCKER`). The toolchain is downloaded on first use into
tools/compilers/ and verified by SHA-256.

Usage: eecc.py [--compiler NAME] [ee-gcc options] -c -o OUT.o IN.cpp
NAME is a decomp.me compiler package (default ee-gcc2.96); packages listed in
PINNED are verified by SHA-256. Paths must be inside the repository, which is
mounted at the same location.
"""

from __future__ import annotations

import hashlib
import os
import platform
import shutil
import subprocess
import sys
import tarfile
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
URL = "https://github.com/decompme/compilers/releases/download/compilers/{}.tar.xz"
PINNED = {
    "ee-gcc2.96": "0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a",
}
DEFAULT = "ee-gcc2.96"
IMAGE = "i386/debian:bookworm-slim"


def ensure_toolchain(name: str) -> Path:
    home = ROOT / "tools/compilers" / name
    if home.exists():
        return home
    home.parent.mkdir(parents=True, exist_ok=True)
    archive = home.parent / f"{name}.tar.xz"
    if not archive.exists():
        print(f"eecc: downloading {URL.format(name)}", file=sys.stderr)
        urllib.request.urlretrieve(URL.format(name), archive)
    digest = hashlib.sha256(archive.read_bytes()).hexdigest()
    if name in PINNED and digest != PINNED[name]:
        archive.unlink()
        raise SystemExit(f"eecc: {archive.name} SHA-256 {digest}, expected {PINNED[name]}")
    home.mkdir()
    with tarfile.open(archive) as tar:
        tar.extractall(home, filter="tar")
    return home


def driver(home: Path) -> tuple[Path, list[str]]:
    """Locate the gcc driver and the -B paths for its cc1/cc1plus and assembler."""
    gcc = next(p for p in sorted((home / "bin").glob("*gcc")) if p.is_file())
    libs = sorted((home / "lib/gcc-lib").glob("*/*/")) + sorted((home / "lib/gcc").glob("*/*/"))
    bflags = []
    for d in libs[:1] + [p for p in (home / "ee/bin", home / "mips64r5900el-ps2-elf/bin") if p.exists()]:
        bflags += ["-B", f"{d}/"]
    return gcc, bflags


def main() -> int:
    argv = sys.argv[1:]
    name = os.environ.get("EECC_COMPILER", DEFAULT)
    if argv[:1] == ["--compiler"]:
        name, argv = argv[1], argv[2:]
    home = ensure_toolchain(name)
    gcc, bflags = driver(home)
    cwd = Path.cwd().resolve()
    gcc_args = [*bflags, *argv]
    native = sys.platform.startswith("linux") and platform.machine() in ("x86_64", "i386", "i686")
    if native:
        cmd = [str(gcc), *gcc_args]
    else:
        docker = os.environ.get("EECC_DOCKER") or shutil.which("docker") or shutil.which("podman")
        if not docker:
            raise SystemExit("eecc: ee-gcc 2.96 is i386 Linux only; install Docker or Podman")
        cmd = [
            docker, "run", "--rm", "--platform", "linux/386", "-v", f"{ROOT}:{ROOT}", "-w", str(cwd),
            IMAGE, str(gcc), *gcc_args,
        ]
    return subprocess.call(cmd)


if __name__ == "__main__":
    sys.exit(main())
