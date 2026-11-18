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
- Dead fragments: unreferenced `addiu sp,sp,N; nop` pairs, and other
  straight-line `insn; nop` leftovers followed by alignment nops (such as
  `sw $v0,0xA0($a0); nop` at 0x13D030), sit between some functions. `tools/splitfuncs.py` gives them their own `frag_<VRAM>` units so
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

A draft that differs only in register allocation or scheduling is searched
mechanically with decomp-permuter, cloned into `tools/ext/decomp-permuter`:

    .venv/bin/python tools/permute.py src/game/Fn145238.cpp 0x145238
    .venv/bin/python tools/eecc.py --serve eecc-perm
    EECC_CONTAINER=eecc-perm .venv/bin/python tools/ext/decomp-permuter/permuter.py -j4 build/permuter/00145238

The permuter parses C only. `tools/permute_cxx.py` rewrites the common C++
spellings in base.c (bare struct/class tags, `bool`, `*_cast<T>`), and the
generated compile.sh undoes them so candidates still build as C++. Drafts with
references, member functions, operators or inheritance stay unpermutable.
`tools/permute_triage.py` scores every draft into `build/permuter/scores.tsv`
to pick the cheapest candidates. Off x86 Linux each compile otherwise starts
Wine in a fresh container; the served container keeps one wineserver running
and cuts a compile from about 2.5 s to 1 s.

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
  the same way (`extern const char D_0044A870[];`). Jump tables are linked
  with their function; see the next item.
- Jump tables: a `switch` function that matches under fncmp links together
  with its table. linkgen places the object's `.rodata` over the original
  `jtbl_` unit (replacing `asm/data/rodata/<addr>.o`) when that section is
  exactly the table: address-aligned, every relocated word equals the original
  target, and every other word equals the original bytes. Size may differ by
  zero padding only: an original unit may end in zero words past the section,
  and SN as pads a game section to 16 bytes, which linkgen trims in the gated
  copy (patching `sh_size`, so `.rel.rodata` survives) when the dropped tail is
  zero and unrelocated. Extra `.rodata` in the object (strings, floats, a second
  table) keeps the function gated in asm; split such a function into its own
  source file. Annotate it `// FUNCTION` as usual (example: 0x122A50).
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
- gcc emits the last-written byte store first and the rest in source order, so to get stores `2F5,2F6,2F7` write `2F6,2F7,2F5`.
- `if (p) g(p); return p;` matches only as `int r = a; if (a) r = g(a); return r;`.
- A derived constructor `if (p) { base(p); p->vt = X; } return p;` builds
  the vtable in `v1` only when `base` is declared returning `void *`; a `void`
  declaration frees `v0` and the vtable lands there.
- `andi; xori; beqz` on a flag comes from `unsigned char t = f ^ 1; if ((t & 1) == 0)`.
- Lazy singletons: `if (!G) { ctor(); func_0031EEA8(&G, name, dtor); } return &G;`,
  where `name` is the rodata string extern.
- Base destructor calls need `extern "C" void _$_7cPlBase(T *);`.
- Flags tested with `lwu; dsra` need `long f = (unsigned)s->flags; (f >> n) & 1`.
- Flags tested with `lw; dsrl; andi` on an `int` field or global need both
  steps in separate unsigned 64-bit locals:
  `unsigned long f = (unsigned long)p->flags; unsigned long b = (f >> n) & 1; if (b)`.
  Folding the test into the `if` emits `dsll32; dsra32` and drops the `andi`.
  For a negated guard, `long x = (f >> 1) & 1; if (!x)` avoids an `xori`.
- `lbu; ...; sw v,0($sp)` followed by a branch on the register comes from
  passing a widened `unsigned char` member to an inline helper that takes
  `const int &`: `static inline int IsSet(const int &v) { return v != 0; }`
  (or `Gt(const int &v, int n)`), called as `IsSet(*(unsigned char *)(p + 0x2B4))`.
  GCC 2.95 spills the temporary and keeps testing the register.
- Quadword vector copies (`lqc2 $vf4; sqc2 $vf4`) come from inline asm, as in
  `cObjCopyVec` (`src/game/cObj.h`):
  `__asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(src) : "memory");`.
  `sqc2 $vf0` zero/identity-initialises a 16-byte-aligned local. Plain struct
  or `mode(TI)` assignment emits `lq`/`sq` instead. fncmp disassembles these
  as `ldc2`/`sdc2`.
- A v0/v1 (or lui/lw) swap on a global load after a call is fixed by declaring
  the preceding callee with an `int` return (`extern "C" int SetDisable__13cSceAtManagerUs(...)`
  instead of `void`). The unused return value shifts register allocation
  (matched 0x1DFD90, 0x1D4F48, 0x1641B8, 0x17FC58). Check the callee's other call sites in the file.
- A trailing void call that the original keeps as `jal` with a frame, where
  gcc emits a sibling `j`, matches with `__asm__ volatile("");` after the
  call: the barrier ends the tail position. The 2.9 cc1 rejects
  `-fno-optimize-sibling-calls` (matched 0x3B5A50).
- Variadic functions: the toolchains ship no `va-mips.h`, and
  `__builtin_next_arg` always yields the frame top (the slot after the last
  register save), whatever parameter it names. The original's `ap` points at
  the first anonymous register save, `8 * (8 - named)` bytes lower, so write
  `ap = (va_list)((char *)__builtin_next_arg(fmt) - 8 * (8 - named));`
  directly before the call that consumes it; assigned earlier, gcc hoists it
  and reallocates registers (matched newlib `sprintf`, `fprintf`, 0x33B6E8,
  0x38AF78).

## `div.s` padding

Most game `div.s` instructions follow two `nop`s, including some in the middle
of straight-line code. None of the ProDG compilers (2.95.3-114, 2.95.2-273a,
2.95.3-136) emits those nops at `-O2 -S`, and their `cc1plus` has no R5900
divide-errata option; ee-gcc 2.96 pads every `div.s` itself and is the only
package that knows `-mhandle-ee-div-pipeline-bug`. The padding therefore comes
from SN's assembler: the 136 `ps2eeas` (`-Wdivbug-on`) pads one nop next to a
branch or label and never two, and the 1.8.19 build pads nothing.

Below 0x3229D0 the game has 911 `div.s`: 585 after two nops, 261 after none,
62 after one and 3 after three, with both forms inside 48 functions. Address
alignment does not predict the count. The best measured rule (87.6%) is no
padding when `add.s`, `sub.s`, `mul.s`, `cvt.s.w` or `div.s` directly precedes
the divide and two nops otherwise; a label or a branch just before gives two
nops in nearly every case. ee-gcc 2.96 pads two nops even after an FPU
arithmetic op, so the game's tool used a different hazard model, most likely
a later ProDG build than any decomp.me package.

The compiler's scheduling around the divide already matches, so the padding is
recorded in the source and restored between compiling and assembling, the
stage where SN's assembler added it. A `// DIVNOP:` line under a `FUNCTION`
tag lists the nops before each `div.s` of that function in emission order, and
tools/divnop.py inserts them into the compiler's assembly:

    // FUNCTION: GAME 0x2EA798
    // DIVNOP: 2

`python tools/divnop.py 0xADDR` prints the tag from the original function. The
counts include every nop before the divide, so a nop the compiler already
emits there is subtracted from its entry.

## Inlined `cVec` operations

The game's inlined `cVec` copies, subtractions and scales are VU0 macro code
(`lqc2`/`vsub.xyz`/`sqc2`). include/cvecop.h reproduces each sequence as one
asm block with memory operands, so the scalar code around it keeps its
original order; matched uses are 0x138470 and 0x156AC0. Three source shapes
around those helpers decide the layout:

- Normalising is plain C (`len = func_00101E28(v); if (0.0f < len) { inv = 1.0f / len; ... }`).
- A copy from a vector whose address the original keeps in a register uses
  `cvecop_CopyR` through a pointer local; `cvecop_Copy` folds it to a stack offset.
- Locals declared as separate `float v[4], u[4], n[4]` arrays take stack
  offsets in declaration order.

## SCE library regions

The decompilation covers the game's own code only. SDK, CRI middleware and
runtime library code is either built from its upstream source or kept as the
original assembly, because hand-reconstructing third-party libraries reproduces
code that already exists elsewhere. `src/sce/` therefore holds upstream-derived
sources only: GNU libio (`src/sce/libio/`), the gcc-2.95.2 fp-bit and libgcc2
routines (`src/sce/Fn31f*_29.c`) and the ProDG game objects that sit inside the
library span (`src/sce/Fn31y.c`). The compiler evidence below identifies which
toolchain built each library, which is what an upstream or original object must
reproduce.

The SDK and runtime libraries (libsce, libstdc++ such as `endl__FR7ostream`)
save callee-saved registers with `sd` instead of ProDG's `sq`. They occupy
0x31C000-0x36FFFF, 0x384000-0x3A3FFF and 0x3B0000 to the end of `.text`; the
ProDG islands 0x370000-0x383FFF and 0x3A4000-0x3AFFFF are game code.

The libraries come from more than one SCE compiler, all built as C at -O2:

| Range (approximate)  | Compiler            | Evidence                         |
|----------------------|---------------------|----------------------------------|
| 0x31C000-0x327FFF    | mixed 2.9 / 2.96 / ProDG | per object, see below       |
| 0x328098-0x36F048    | `ee-gcc2.96`        | 10 of 10 sampled framed units    |
| 0x3875A8-0x393F30    | `ee-gcc2.9-991111`  | 0x389170, 0x389400 match         |
| 0x3951F8-0x3A4AF0    | `ee-gcc2.9-991111`; framed call wrappers `ee-gcc3.2-030926` + `-fno-optimize-sibling-calls` | leaf/branch units match 2.9; 0x395180, 0x3964A0, 0x398B90 match only 3.2 |
| 0x3B0268-0x3B9458    | `ee-gcc2.9-991111`  | 0x3B2148, 0x3B6B90 match         |
| 0x3B9998-0x3BA900    | `ee-gcc2.96`        | fncmp matches pin both edges     |
| 0x3BA978-end         | `ee-gcc2.9-991111`  | 0x3BAFD0 matches only under 2.9  |

The boundaries follow runs of `sd` versus `sq` prologues; `sq` runs inside the
library span (0x372CB0-0x387430, 0x393FD8-0x394F20, 0x3A53A8-0x3AF7B8, and the
units 0x3BAFF8, 0x3BB058, 0x3BB178, 0x3BB468, 0x3BB4F0, 0x3BB980, 0x3BBA10) are ProDG game code.

A one-call wrapper `void f(){ g(); }` tells 2.9 and 2.96 apart: 2.9 emits a
bare `j` (8 bytes), while 2.96 keeps a dead frame around the tail jump
(`addiu sp; sd ra; ld ra; j; addiu sp`, 20 bytes). Below 0x328000 both shapes
occur, so each object takes whichever compiler its framed functions match.
Within 0x320000-0x328098 the switch from 2.9 to 2.96 lies between 0x3224F8
and 0x3229D0. Framed units below it save `ra` at 0x10 per saved register, as
2.9 does (20 of 20 sampled); units from 0x3229D0 save `ra` at 8 per register,
as 2.96 does (`src/sce/Fn320_29.c` versus `src/sce/Fn320_96.c`).
That span also holds ProDG game objects (`SearchCameraData` at 0x31CE38),
recognisable by `sq` prologues; they match only `ee-gcc2.95.3-136`
(`src/sce/Fn31y.c`: 0x31C238, 0x31CA88, 0x31D2F8, 0x31D6E8), while their
`sd`-saving neighbours stay on 2.9-991111 (`src/sce/Fn31x.c`). The island
0x372CB0-0x387430 is likewise game C++ under the default compiler
(`src/game/Fn37xa.cpp`, `Fn37xw.cpp`); 2.96, 2.9 and 3.2 lose 0x373430 by
16-21 words.
The sign-extending wrappers at 0x38A1D8-0x38BA68 match only ee-gcc 3.2 with
`-fno-optimize-sibling-calls`. ee-gcc 3.2 otherwise matched only small wrappers, which 2.96 also
matches, and loses every larger function by 15-23 words. 2.96 must compile C,
not C++, to match. The 990721 and 991111 variants of 2.9 agree on every
function tested. Leaf functions of 8-20 bytes compile
identically under every package and do not identify the compiler; framed
functions do. `syscall` stubs are hand-written and stay in asm.

The iostream code at 0x3875A8 onward is GNU libio from the gcc-2.95 branch,
compiled as C++ by `ee-gcc2.9-991111`. `src/sce/libio/` holds that upstream
source (GPL header kept) with trimmed headers that reproduce the original
layout: `_G_off_t` is `long`, `_G_USING_THUNKS` is off (8-byte vtable jump
entries), and `ios` is a virtual base. Its units carry their mangled names in
`config/symbols.sndata.txt`; `config/aliases.ld` maps the libio-internal
callees still in asm and the old `func_` names used by C callers.
Identical one-call thunks match under any name, so their names are checked
against the vtable words: the `_vt$7filebuf` slots put `doallocate` at
0x38EF80 and `overflow`/`underflow`/`sync`/`seekoff` at the next four 0x20
steps, one slot earlier than the raw .sndata list, and each thunk's `jal`
target names the matching `_IO_file_*` routine.

Upstream sources for that region are C files in `src/sce/`. A source selects its
compiler with leading comment lines (within its first four lines), which
configure.py and fncmp.py both read:

```c
// COMPILER: ee-gcc3.2-030926
// FLAGS: -fno-common
```

`COMPILER` names a decomp.me package and replaces the default ProDG build;
`FLAGS` is appended to `CXXFLAGS`. ee-gcc 3.2 sources use that package's own
assembler and skip the short-loop pass, because the SCE code was not built
with SN's workaround.

### CRI middleware

CRI ADX/Sofdec middleware occupies 0x322978-0x36D1A8 and builds with `ee-gcc2.96`.
Every library carries a version string stamped Nov 4 2005 (the CRI SF*/SUD/CFT/MP*/M2V
group: Aug 9 2005); the executable's version table, by library:

- ADXT/PS2EE 9.67 (0x324950), ADXPS2 2.63 (0x325638), ADXRT 3020 (0x3290B8)
- AIXP/PS2EE 2.53 (0x32D1A0), CVFS/PS2EE 2.51 (0x330318), SRD/PS2EE 2.24 (0x330FB8)
- DVCI/PS2EE 2.72 (0x3327D8), HTCI/PS2EE 2.70 (0x333FA0), LSC/PS2EE 2.26 (0x335DE0)
- MFCI/PS2EE 1.15 (0x336318), PS2RNA 1.35 (0x337728), SJRMT 1.03 (0x33AFC0)
- ADXF/PS2EE (0x33F3F0), PL2ENC 1.02 (0x3404B0-0x340580), MWSFD/PS2EE (0x3452D8)
- CRI SFD (0x34DB60), SFH 1.19 (0x35D520), SFX 2.31 (0x35F8A8), SUD 0.05 (0x360790)
- CRI CFT 1.78 (0x360CA0), MPS (0x368CE8), MPV (0x36BE00), M2V (0x36D0E8-0x36D1A8)

Each address is the unit that loads that library's version string. Error strings embed
function names, `E9040801:...(adxf_ChkPrmPt)`; `tools/crinames.py --spans` scans
the asm for units referencing exactly one such name and prints the version-string
spans. Its proposals are applied in `config/symbols.sndata.txt` (`adxf_*` at
0x322978-0x324500, `adxt_StartMemIdx`, `DTX_Create`, `PS2RNA_*`, `DTR_ExecHndl`).

No public CRI library or source matches these 2005 builds. The closest are
the CRI PS2 SDK 1.10 patch 5 on the Internet Archive (`cri-sdk` item: ADXT
8.37, MWSFD 2.31, built 2002), whose `libadxe.a` and `libmwsfde.a` differ at
the instruction level, and the CRI decomps in rez-decomp (2001 ADX,
ee-gcc 2.9) and pes6decomp (2006, non-matching). They serve as references for
names and structure layouts; the CRI span stays as original assembly.

## VU0 macro code

COP2 math (`vadd.xyz`, `vsqrt`, `qmfc2`) comes from inline asm blocks; the
shared helpers live in `include/vu0.h`. Each block holds only the COP2
sequence the compiler cannot emit; surrounding control flow and integer code
stay in C so the function remains readable. Explicit `nop`s inside a VU
template are original hazard padding and are allowed there only.
