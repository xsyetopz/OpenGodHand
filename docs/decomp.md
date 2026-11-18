# Decompiling functions

A function counts as done when its C++ compiles to the original bytes and the
full build still reproduces `SLUS_215.03` byte for byte.

## Toolchain

- Compiler: SCE ee-gcc 2.96 (`2.96-ee-001003-1`), C++ (GCC 2 mangling), run by
  `tools/eecc.py` (native on x86 Linux, Docker `linux/386` elsewhere).
- Flags: `tools/configure.py` `CXXFLAGS` (`-O2 -G0 -ffunction-sections ...`).
  `-ffunction-sections` does not change code bytes; it lets the linker place each
  function at its original address. Compiler flags are still being confirmed;
  report functions that only match with extra flags.
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
- Keep a function in asm (no annotation) until it matches; non-matching
  attempts stay out of `src/game/`.
