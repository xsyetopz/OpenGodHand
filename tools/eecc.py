#!/usr/bin/env python3
"""Run a PS2 EE compiler package from decomp.me on any host.

The game code is built with SN Systems ProDG ee-gcc 2.95.3 (build 136): its
prologues save callee-saved registers with `sq`, which no SCE gcc emits. The
"GCC2096 SCE3020" string in the executable comes from the linked SCE libraries.
The objects were assembled by SN's ps2eeas 1.8.19.316 (shipped in the
ee-gcc2.95.2-273a package), not the packaged GNU as: it keeps a `nop` after
`mtc1` before the FPU reads the moved register, as the game does, while the
1.9.x builds also pad a load used across a branch, which the game does not.
For SN packages `-c` therefore runs as `-S` followed by that ps2eeas.
SN packages are Windows executables and run under Wine; the SCE Linux packages
are i386 binaries. On anything but x86 Linux with Wine, both run in the i386
container built from tools/docker/wine.Dockerfile (Docker or a compatible CLI
named by `EECC_DOCKER`). Packages are downloaded on first use into
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
import shlex
import shutil
import subprocess
import sys
import tarfile
import urllib.error
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
URL = "https://github.com/decompme/compilers/releases/download/compilers/{}"
SUFFIXES = (".tar.xz", ".tar.gz")
PINNED = {
    "ee-gcc2.9-990721": "ad2ea68afff2be25d21a1d51a75e8a0eea8f259018e6580622355cd01b95676b",
    "ee-gcc2.9-991111": "99cb5db603cd985b50fc6851157020ad69489f2227309ccf825bd43ac7bc19dd",
    "ee-gcc2.9-991111-01": "ed684fd98f89d36b0121caab311052089103e3b36241fcef4338cc9ea41c75b8",
    "ee-gcc2.9-991111a": "f07d1f38afa847197fb816237dbce64e79b2d37b738cb93fa4df3ac7aa1d16f3",
    "ee-gcc2.95.2-273a": "ee9d9a7fccb59aebfa78a5587f6f8059660b91f705acddbc292ad2243c8e562e",
    "ee-gcc2.95.3-114": "dbc2c8c764631788d4cbb4c848c3cb0002fded0f4a95bae39e6d8b794391a6cb",
    "ee-gcc2.95.3-136": "3b6ae6897229ad005aaf1b0afaa1f3cb46e74b4c21a42e01130c07c0c598067f",
    "ee-gcc3.2-030210-beta2": "5244521973d3fa9712cc9f945e6e45c489d69d846ca6639b0c07c3e885a923a1",
    "ee-gcc3.2-030926": "6b92b61e40f80835b165d14fadd57d4046dbee82195599f791626180fe79b8e9",
    "ee-gcc3.2-040921": "8c60ca7482523190e999524a7e4de2379dcf7ffee543c1b5663bfdf6a80ebf0f",
    "ee-gcc2.96": "0590d2ca9da8f5903889d66761220d14b47a8d14ba987ca53db84a1650a1fd0a",
}
DEFAULT = "ee-gcc2.95.3-136"
SN_AS = ("ee-gcc2.95.2-273a", "lib/gcc-lib/ee/2.95.2/ps2eeas.exe")
IMAGE = "godhand-eecc:wine"
DOCKERFILE = ROOT / "tools/docker/wine.Dockerfile"


def ensure_toolchain(name: str) -> Path:
    home = ROOT / "tools/compilers" / name
    if home.exists():
        return home
    home.parent.mkdir(parents=True, exist_ok=True)
    archive = next((p for sfx in SUFFIXES if (p := home.parent / f"{name}{sfx}").exists()), None)
    if archive is None:
        for sfx in SUFFIXES:
            archive = home.parent / f"{name}{sfx}"
            print(f"eecc: downloading {URL.format(name + sfx)}", file=sys.stderr)
            try:
                urllib.request.urlretrieve(URL.format(name + sfx), archive)
                break
            except urllib.error.HTTPError:
                archive.unlink(missing_ok=True)
            except urllib.error.URLError:
                archive.unlink(missing_ok=True)
                raise
        else:
            raise SystemExit(f"eecc: no package named {name}")
    digest = hashlib.sha256(archive.read_bytes()).hexdigest()
    if name in PINNED and digest != PINNED[name]:
        archive.unlink()
        raise SystemExit(f"eecc: {archive.name} SHA-256 {digest}, expected {PINNED[name]}")
    home.mkdir()
    print(f"eecc: {name} SHA-256 {digest}", file=sys.stderr)
    with tarfile.open(archive) as tar:
        tar.extractall(home, filter="tar")
    return home


def driver(home: Path) -> tuple[Path, list[str]]:
    """Locate the gcc driver and the -B paths for its cc1/cc1plus and assembler."""
    gcc = next(p for p in sorted((home / "bin").glob("*gcc*")) if p.is_file())
    libs = sorted((home / "lib/gcc-lib").glob("*/*/")) + sorted((home / "lib/gcc").glob("*/*/"))
    bflags = []
    for d in libs[:1] + [p for p in (home / "ee/bin", home / "mips64r5900el-ps2-elf/bin") if p.exists()]:
        bflags += ["-B", f"{d}/"]
    return gcc, bflags


def ensure_image(docker: str) -> None:
    if subprocess.call([docker, "image", "inspect", IMAGE], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
        print(f"eecc: building {IMAGE}", file=sys.stderr)
        cmd = [docker, "build", "--platform", "linux/386", "-t", IMAGE, "-f", str(DOCKERFILE), str(DOCKERFILE.parent)]
        if subprocess.call(cmd, stdout=sys.stderr):
            raise SystemExit("eecc: image build failed")


def normalize_symtab(obj: Path) -> None:
    """Rewrite the object so every local symbol precedes the globals.

    The EE assemblers append locals (`gcc2_compiled.`, `__FRAME_BEGIN__0`) after
    the globals and set .symtab sh_info inconsistently, which modern GNU ld
    rejects or misreads as globals turned local. objcopy re-sorts the table and
    renumbers relocations without touching section contents.
    """
    objcopy = os.environ.get("CROSS", "mipsel-linux-gnu-") + "objcopy"
    subprocess.check_call([objcopy, str(obj)])


def main() -> int:
    argv = sys.argv[1:]
    name = os.environ.get("EECC_COMPILER", DEFAULT)
    if argv[:1] == ["--compiler"]:
        name, argv = argv[1], argv[2:]
    home = ensure_toolchain(name)
    gcc, bflags = driver(home)
    cwd = Path.cwd().resolve()
    gcc_args = [*bflags, *argv]
    exe = [str(gcc)]
    if gcc.suffix == ".exe":
        # Wine maps the repository's absolute path through drive Z:.
        exe = ["wine", str(gcc)]
    native = sys.platform.startswith("linux") and platform.machine() in ("x86_64", "i386", "i686")
    if native and (gcc.suffix != ".exe" or shutil.which("wine")):
        cmd = [*exe, *gcc_args]
    else:
        docker = os.environ.get("EECC_DOCKER") or shutil.which("docker") or shutil.which("podman")
        if not docker:
            raise SystemExit("eecc: the EE compilers need x86 Linux (and Wine) or Docker/Podman")
        ensure_image(docker)
        cmd = [
            docker, "run", "--rm", "--platform", "linux/386", "-v", f"{ROOT}:{ROOT}", "-w", str(cwd),
            "-e", "WINEDEBUG=-all", IMAGE, *exe, *gcc_args,
        ]
    sn_as = ensure_toolchain(SN_AS[0]) / SN_AS[1] if gcc.suffix == ".exe" else None
    if sn_as and "-c" in argv and "-o" in argv:
        out = argv[argv.index("-o") + 1]
        asm = out + ".sn.s"
        gargs = [*bflags, *("-S" if a == "-c" else a for a in argv)]
        gargs[gargs.index("-o", len(bflags)) + 1] = asm
        gsize = [a for a in argv if a.startswith("-G")][-1:]
        steps = [[*exe, *gargs], [*exe[:-1], str(sn_as), *gsize, "-o", out, asm]]
        if exe[0] != "wine":
            steps[1] = ["wine", str(sn_as), *gsize, "-o", out, asm]
        script = " && ".join(" ".join(shlex.quote(a) for a in step) for step in steps) + f" && rm -f {shlex.quote(asm)}"
        cmd = cmd[: len(cmd) - len(exe) - len(gcc_args)] + ["sh", "-c", script]
    rc = subprocess.call(cmd)
    if rc == 0 and "-o" in argv and argv[argv.index("-o") + 1].endswith(".o"):
        normalize_symtab(Path(argv[argv.index("-o") + 1]))
    return rc


if __name__ == "__main__":
    sys.exit(main())
