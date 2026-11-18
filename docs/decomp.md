# Decompiling functions

A function counts as done when its C++ compiles to the original bytes and the
full build still reproduces `SLUS_215.03` byte for byte.

## Toolchain

- Compiler: SN Systems ProDG ee-gcc 2.95.3 (decomp.me package
  `ee-gcc2.95.3-136`), C++ with GCC 2 mangling. Its prologues save callee-saved
  registers with `sq` (`addiu sp,-0x20; sq s0,0x10(sp); sd ra,0(sp)`), which
  the SCE gcc 2.9x/2.96 builds never emit, and it does not enable strict
  aliasing at -O2. Build 136 is the only package that matches every function
  decompiled so far; builds 114 and 273a miss `cMessage::ckMessage`.
- Assembler: SN ps2eeas 1.8.19.316 (shipped in `ee-gcc2.95.2-273a`), not the
  package's GNU as. The compiler emits reorder-mode assembly and the assembler
  chooses hazard nops: 1.8.19 keeps a `nop` between `mtc1` and the FPU
  instruction reading that register, as the game does; GNU as omits it, and
  ps2eeas 1.9.x additionally pads a load used across a branch, which the game
  never does. `tools/eecc.py` runs `-c` as `-S` followed by ps2eeas.
- A build-time gate (`tools/linkgen.py`) links an annotated function only when
  its bytes match and every symbol it references exists in the final link;
  otherwise the asm unit stays. `build/linkgen.tsv` lists each annotated
  function's status (`match`, `differ`, `refs ...`).
- `tools/eecc.py` runs the Windows executables under Wine, in the i386
  container from `tools/docker/wine.Dockerfile` unless the host is x86 Linux
  with Wine. The SCE "GCC2096 SCE3020" string in the executable belongs to the
  linked SCE libraries, not the game code.
- Flags: `tools/configure.py` `CXXFLAGS` (`-O2 -G0 -ffunction-sections ...`).
  `-ffunction-sections` does not change code bytes; it lets the linker place each
  function at its original address.
- Docker invocations need the Claude Code sandbox disabled.

## Workflow

1. Pick a unit from `asm/text/units.tsv` (`VRAM  SIZE  NAME`). The asm is
   `asm/text/<VRAM>.s`.
2. Draft C++: `.venv/bin/python tools/ext/m2c/m2c.py -t mipsee-gcc-c++ asm/text/<VRAM>.s`
   gives a starting point; demangle `NAME` for the real signature
   (`getMeshNum__C6cModel` is `cModel::getMeshNum() const`).
3. Write the function in `src/game/<Class>.cpp`, declaring the class in
   `src/game/<Class>.h`. Put `// FUNCTION: GAME 0x<VRAM>` on the line above each
   definition; configure.py uses it to replace the asm unit.
4. Compare: `.venv/bin/python tools/fncmp.py src/game/<Class>.cpp 0x<VRAM>`.
   `MATCH` means identical bytes with relocated fields masked. Iterate on the
   source until it matches; don't change flags per function.
5. Integration: `.venv/bin/python tools/configure.py && ninja` must end with
   `build/SLUS_215.03: OK`.

## Source conventions

- Class layouts use the original member offsets; unknown regions are
  `char _padXXX[n]` placeholders. Unknown fields are named `m_unkXXX` by offset.
- Data the function reads keeps its splat name (`D_003BF160`) as an `extern`
  until the data itself is decompiled.
- Functions whose compiled output needs its own `.rodata` (string literals,
  float constants, switch jump tables) or `.data` cannot be linked yet: the
  linker script takes only `.text.*` from compiled objects. Skip them for now.
- Keep a function in asm (no annotation) until it matches. A non-matching
  attempt worth keeping goes inside `#ifdef NONMATCHING` with a comment naming
  its address and remaining difference, so it neither links nor collides with
  the asm unit's symbol.
- Functions with no symbol (`func_XXXXXXXX`) are declared `extern "C"` so the
  call links against the asm label.
