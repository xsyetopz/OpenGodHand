# God Hand decompilation

Byte-for-byte matching decompilation of God Hand (PS2, SLUS-21503). `ninja` rebuilds `original/extracted/SLUS_215.03` and checks its SHA-1; `SLUS_215.03: OK` is the only acceptable build result. The ISO and everything extracted from it stay out of git.

Only game code is decompiled and counted. SDK, CRI ADX/Sofdec, newlib and libio come from upstream sources or stay as original asm; `tools/objdiff_config.py` `region()` assigns the categories and `tools/progress.py` counts the Game category alone.

## Commands

| Task | Command |
|---|---|
| Compare one function | `.venv/bin/python tools/fncmp.py -q FILE 0xADDR` (exit 0 = MATCH) |
| Owner of an address | `.venv/bin/python tools/claimed.py 0xADDR` (prints the file or `free`) |
| Duplicate claims | `.venv/bin/python tools/claimed.py` (prints nothing when clean) |
| Build, verify, commit | `bash tools/gate.sh` in the background; commits "Worker matches batch" |
| Full build | `just build` |
| Progress map | `just live` (http://127.0.0.1:8765/) |
| Permuter setup | `.venv/bin/python tools/permute.py FILE 0xADDR` |
| Remove library code from src | `.venv/bin/python tools/unclaim.py FILE 0xADDR...` |

`tools/eecc.py` compiles through Docker (OrbStack). The sandbox blocks the Docker socket, so `fncmp.py`, `eecc.py`, `ninja`, `just build` and `tools/gate.sh` run with the sandbox disabled.

## Source tags

- `// FUNCTION: GAME 0xADDR` marks a matched function.
- `// DRAFT: GAME 0xADDR` marks an unmatched one, inside `#ifdef NONMATCHING`, with a one-line note listing the variants tried and the remaining differing-word count.
- A tag flips to FUNCTION only after `fncmp.py` reports MATCH.
- `fncmp.py` does not check relocations against section symbols (.rodata literals). A MATCH on code that loads rodata still needs the full build.
- Sources stay at or below 300 lines; `tools/gate.sh` refuses longer ones.

## Compilers

| Code | Compiler | Flags |
|---|---|---|
| Game (C++) | SN ProDG ee-gcc 2.95.3-136 (default) | `-O2 -G0` |
| CRI | ee-gcc 2.96 | |
| newlib libm | ee-gcc2.9-991111 | `-fno-builtin -Wa,-mips4 -Iinclude/newlib -Iinclude/newlib/machine` |

A source overrides the defaults with `// COMPILER: NAME` and `// FLAGS: ...` in its first four lines (`tools/configure.py` `source_build`). `fncmp.py --compiler NAME` tries another package from `tools/compilers` for one comparison.

## Shell

The interactive shell is zsh with macOS (BSD) userland.

- zsh does not split unquoted variables: `for a in "f.cpp 0x1"; do cmd $a; done` passes one argument. Write each call out, or use `${=a}`.
- zsh expands a word starting with `=` as a command path: `echo == $f` fails with `= not found`. Quote separators: `echo "== $f"`.
- `grep` is a shell function backed by ugrep with regex complexity limits. Long `.{0,N}` patterns fail; use `LC_ALL=C /usr/bin/grep`.
- BSD `sed` has no `\S`, and `sed -i` needs an argument (`sed -i ''`). BSD `paste` needs a file operand (`paste -sd, -`).
- A command that reads stdin when its file list is empty (`wc -l`, `cat`, `grep PATTERN`, `xargs`) waits forever. Give it `< /dev/null` or make sure the list is not empty.
- `$TMPDIR` differs between sandboxed and unsandboxed commands. Files shared between both kinds go under `build/` or `/private/tmp/claude-501/`.
- `rm -rf "$VAR"` with a variable target is refused. Remove explicit paths.
- `git checkout -- FILE` discards other workers' uncommitted edits in that file. Revert your own change with Edit.

## Long-running commands

- Subagent foreground commands stop after 180 s and move to the background. Builds and permuter runs belong in the background from the start; `fncmp.py` alone finishes well within the limit.
- Background commands send a notification when they finish. `sleep` followed by reading the output file is blocked; wait for the notification or use Monitor.
- Tool parameters are typed: `dangerouslyDisableSandbox` takes `true`, not `"true"`, and Bash and Monitor calls require `description`.

## Workers

- `decomp-worker` (Sonnet, medium effort) matches drafts. `lookup` (Haiku, high effort) answers read-only questions and stays under 100k tokens of context.
- A worker checks `claimed.py 0xADDR` before starting on an address. An address already tagged FUNCTION elsewhere is done.
- Workers never commit, never edit `tools/`, and report tool bugs and permission denials instead of working around them.
- The subagent prompt cache lasts 5 minutes. A worker idle longer than that is replaced by a fresh one rather than resumed.
