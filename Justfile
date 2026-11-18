# God Hand SLUS-21503 matching decomp. Run `just --list` for recipes.

venv := ".venv"
py := if os() == "windows" { venv / "Scripts/python.exe" } else { venv / "bin/python" }
iso_in := "original/SLUS-21503.iso"
iso_out := "build/SLUS-21503.iso"

[windows] set shell := ["powershell.exe", "-NoLogo", "-Command"]

# Create .venv from requirements.txt when it is missing.
venv:
    {{ if path_exists(py) == "true" { "python3 -c pass" } else { "python3 -m venv " + venv + " && " + py + " -m pip install -r requirements.txt" } }}

# Turn the ISO into everything configure and build need.
setup iso=iso_in: venv
    {{ py }} tools/setup.py {{ iso }}

# Write build.ninja.
configure:
    {{ py }} tools/configure.py

# Build build/SLUS_215.03 and check its SHA-1.
build: configure
    ninja

# Write build/SLUS-21503.iso with the rebuilt executable and verify it equals the original disc.
iso: build
    {{ py }} tools/iso.py patch {{ iso_in }} SLUS_215.03 build/SLUS_215.03 {{ iso_out }}
    {{ py }} -c "import sys,hashlib;h=lambda p:hashlib.sha1(open(p,'rb').read()).hexdigest();a,b=h(sys.argv[1]),h(sys.argv[2]);print(sys.argv[2]+(': OK' if a==b else ': FAILED'),b);sys.exit(a!=b)" {{ iso_in }} {{ iso_out }}

# Remove build/ and build.ninja (rerun `just setup` afterwards); original/, asm/ and assets/ are kept.
clean:
    {{ py }} -c "import shutil;[shutil.rmtree(d,ignore_errors=True) for d in ('build',)];import os;os.path.exists('build.ninja') and os.remove('build.ninja')"
