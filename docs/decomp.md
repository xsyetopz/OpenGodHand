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
- Short loops: every backward branch in the game spans at least six
  instructions (target through delay slot), padded with `nop`s before the
  branch. That is SN's R5900 short-loop workaround; ps2eeas 1.8.19 lacks it,
  so `tools/shortloop.py` pads the compiler output and eecc.py reassembles.
  Never write the nops in source.
- Dead fragments: unreferenced `addiu sp,sp,N; nop` pairs sit between some
  functions. `tools/splitfuncs.py` gives them their own `frag_<VRAM>` units so
  the following function starts at its real entry. The old automatic name
  stays defined at the fragment, because other code takes the entry address
  as `%lo(func_<fragment> + 8)`.
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
   `MATCH` means identical bytes outside relocated fields, and each relocated
   field (`jal`, `%hi`, `%lo`) resolves to the original address under the
   symbol table of the last build that passed the sha1 check
   (`build/SLUS_215.03.ok.elf`); a wrong
   symbol prints `sym (0xVAL) is not the original target`. Iterate on the
   source until it matches; don't change flags per function. The build gate
   (`linkgen.py`) runs before the link and masks relocated fields, so the
   final sha1 is the authority. A callee already matched under its real name
   must be declared under that name, or the gate reports `refs func_...`.
   Check whether an address is taken with `tools/claimed.py 0xADDR`; drafts
   under `#ifdef NONMATCHING` are marked `// DRAFT: GAME 0x...`, not
   `FUNCTION`, so they claim nothing.
5. Integration: `.venv/bin/python tools/configure.py && ninja` must end with
   `build/SLUS_215.03: OK`.

## Source conventions

- Class layouts use the original member offsets; unknown regions are
  `char _padXXX[n]` placeholders. Unknown fields are named `m_unkXXX` by offset.
- Data the function reads keeps its splat name (`D_003BF160`) as an `extern`
  until the data itself is decompiled.
- Compiled `.rodata`/`.data` is not linked yet (only `.text.*` is), and the
  gate keeps any function that references them in asm. With `-G0` a literal
  load (`lui at,%hi(.LC0); lwc1 $f0,%lo(.LC0)(at)`) has the same encoding as a
  load of an extern, so reference the original constant instead:
  `extern const float D_0041C2A0;` or, inside a larger unit,
  `extern const float D_0041C280[]; ... D_0041C280[8]`. String literals work
  the same way (`extern const char D_0044A870[];`). Switch jump tables still
  need their own `.rodata`; skip those.
- Keep a function in asm (no annotation) until it matches. A non-matching
  attempt worth keeping goes inside `#ifdef NONMATCHING` with a comment naming
  its address and remaining difference, so it neither links nor collides with
  the asm unit's symbol.
- Functions with no symbol (`func_XXXXXXXX`) are declared `extern "C"` so the
  call links against the asm label.

## Codegen idioms

These source shapes reproduce patterns this compiler emits only one way:

- `long long` is 128-bit (`sq`, 0x20 stride). Use `long` for 64-bit `sd`, and
  an `unsigned` field for `lwu`.
- `and; sltu` comes from `unsigned t = x & m; return t != 0;`. Writing
  `return (x & m) != 0;` gives `sra/andi` instead.
- A branchy bool masked with `andi 0xFF` comes from an inline helper that
  returns `unsigned char`, compared with `== 0` or `== 1`.
- A conditional assignment of two constants becomes `movz`. Where the
  original branches, an early `return` sometimes avoids it.
- Store order in source is not always the emitted order: delay-slot filling
  moves the last store first. When stores mismatch, permute them.
- `if (p) g(p); return p;` matches only as `int r = a; if (a) r = g(a); return r;`.
- A derived constructor `if (p) { base(p); p->vt = X; } return p;` builds
  the vtable in `v1` only when `base` is declared returning `void *`; a `void`
  declaration frees `v0` and the vtable lands there.
- `andi; xori; beqz` on a flag comes from `unsigned char t = f ^ 1; if ((t & 1) == 0)`.
- Lazy singletons: `if (!G) { ctor(); func_0031EEA8(&G, name, dtor); } return &G;`,
  where `name` is the rodata string extern.
- Base destructor calls need `extern "C" void _$_7cPlBase(T *);`.
- Flags tested with `lwu; dsra` need `long f = (unsigned)s->flags; (f >> n) & 1`.
- Quadword vector copies (`lqc2 $vf4; sqc2 $vf4`) come from inline asm, as in
  `cObjCopyVec` (`src/game/cObj.h`):
  `__asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(src) : "memory");`.
  `sqc2 $vf0` zero/identity-initialises a 16-byte-aligned local. Plain struct
  or `mode(TI)` assignment emits `lq`/`sq` instead. fncmp disassembles these
  as `ldc2`/`sdc2`.

## SCE library regions

Most of 0x320000-0x3BBF20 saves registers with `sd` and tail-calls with `j`.
That code was built by SCE ee-gcc 3.2 (`ee-gcc3.2-030926` or `-040921`, -O2),
not ProDG 2.95.3; `fncmp.py --compiler ee-gcc3.2-030926` compares against it.
