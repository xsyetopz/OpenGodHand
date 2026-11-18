#!/usr/bin/env python3
"""One-command setup: turn the user's ISO into the inputs configure.py and ninja need.

Steps (each skipped when its output is already current):
  1. verify the ISO SHA-1
  2. extract SLUS_215.03 and verify its SHA-1 (config/SLUS_215.03.sha1)
  3. write build/SLUS_215.03.rom, the ELF load image splat reads
  4. run splat, split .text into per-function units, extract ELF assets
"""

from __future__ import annotations

import argparse
import hashlib
import io
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
ISO_SHA1 = "2215fb65a9ae391741950970bd88b79ca87d9d05"
ROM_SHA1 = "2a81167afa727a9e4293803a8139192e87cfdf17"
EXE = "SLUS_215.03"


def sha1(data: bytes) -> str:
    return hashlib.sha1(data).hexdigest()


def sha1_file(path: Path) -> str:
    h = hashlib.sha1()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def fail(msg: str) -> "None":
    raise SystemExit(f"setup: error: {msg}")


def run(*cmd: object) -> None:
    print("+", " ".join(str(c) for c in cmd), flush=True)
    subprocess.run([str(c) for c in cmd], cwd=ROOT, check=True)


def load_image(elf_bytes: bytes) -> bytes:
    """Flat memory image of the PT_LOAD segments, equal to `objcopy -O binary --gap-fill=0`."""
    segs = [s for s in ELFFile(io.BytesIO(elf_bytes)).iter_segments() if s["p_type"] == "PT_LOAD" and s["p_filesz"]]
    if not segs:
        fail(f"{EXE} has no loadable segments")
    base = min(s["p_paddr"] for s in segs)
    end = max(s["p_paddr"] + s["p_filesz"] for s in segs)
    image = bytearray(end - base)
    for s in segs:
        off = s["p_paddr"] - base
        image[off : off + s["p_filesz"]] = s.data()
    return bytes(image)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("iso", type=Path, nargs="?", default=ROOT / "original/SLUS-21503.iso")
    args = ap.parse_args()
    iso: Path = args.iso

    if not iso.is_file():
        fail(f"ISO not found: {iso}\n  place your God Hand (USA) disc image there or pass its path")
    got = sha1_file(iso)
    if got != ISO_SHA1:
        fail(f"ISO SHA-1 mismatch for {iso}\n  expected {ISO_SHA1}\n  got      {got}\n  this must be the SLUS-21503 (USA) image")
    print(f"ISO ok: {iso}")

    want_exe = (ROOT / "config" / f"{EXE}.sha1").read_text().split()[0]
    exe = ROOT / "original/extracted" / EXE
    if not (exe.is_file() and sha1_file(exe) == want_exe):
        exe.parent.mkdir(parents=True, exist_ok=True)
        run(sys.executable, "tools/iso.py", "extract", iso, EXE, exe)
    got = sha1_file(exe)
    if got != want_exe:
        fail(f"{EXE} SHA-1 mismatch\n  expected {want_exe}\n  got      {got}")
    print(f"{EXE} ok: {exe}")

    build = ROOT / "build"
    build.mkdir(exist_ok=True)
    rom = build / f"{EXE}.rom"
    if not (rom.is_file() and sha1_file(rom) == ROM_SHA1):
        rom.write_bytes(load_image(exe.read_bytes()))
    got = sha1_file(rom)
    if got != ROM_SHA1:
        fail(f"{rom.name} SHA-1 mismatch\n  expected {ROM_SHA1}\n  got      {got}")
    print(f"{rom.name} ok")

    # splat 0.50.1 runs no binutils during `split` (only create_config does).
    py = sys.executable
    run(py, "-m", "splat", "split", "config/SLUS_215.03.yaml")
    sys.path.insert(0, str(ROOT / "tools"))
    from configure import SECTIONS

    for _name, _vram, end, src, unit_dir in SECTIONS:
        run(py, "tools/splitfuncs.py", src, unit_dir, hex(end))
    run(py, "tools/elfpack.py", "assets", "config/elf_layout.json", exe, "assets/elf")
    print("setup complete: run `just configure build`")
    return 0


if __name__ == "__main__":
    sys.exit(main())
