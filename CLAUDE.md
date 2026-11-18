# CLAUDE.md

Byte-for-byte matching decompilation of God Hand (PS2, SLUS-21503); `SLUS_215.03: OK` from `ninja` is the only acceptable build. The ISO and extracted files stay out of git. Only game code is decompiled; SDK, CRI, newlib and libio come from upstream or stay asm, and `tools/progress.py` counts the Game category alone.

- `.venv/bin/python tools/fncmp.py [-q] FILE 0xADDR` compares one function (exit 0 = MATCH; without `-q` it prints a side-by-side diff).
- `.venv/bin/python tools/claimed.py [0xADDR]` names an address's owner, or with no argument prints duplicate claims (empty = clean).
- `bash tools/gate.sh`, run in the background, builds a snapshot and commits it only on `SLUS_215.03: OK`. `just build` builds; `just live` serves progress.
- Compiling goes through Docker, which the sandbox blocks: `fncmp.py`, `ninja`, `just build` and `gate.sh` run with `dangerouslyDisableSandbox: true` (a boolean).
- Game code: ee-gcc 2.95.3-136, `-O2 -G0`, C++. A source overrides it with `// COMPILER:` and `// FLAGS:` in its first four lines.
- `// FUNCTION: GAME 0xADDR` marks a match; `// DRAFT: GAME 0xADDR` sits under `#ifdef NONMATCHING` with a one-line note of variants tried. Sources stay at or below 300 lines.
- `fncmp.py` skips .rodata relocation targets, so code loading literals is confirmed only by the full build.
- zsh: unquoted `$a` stays one argument (write calls out); `echo == x` fails (quote it). `grep` is ugrep with pattern limits; long patterns use `LC_ALL=C /usr/bin/grep`.
- `wc -l`, `cat`, `xargs` and `grep PATTERN` with an empty file list wait on stdin forever; pass `< /dev/null`.
- `$TMPDIR` differs inside and outside the sandbox; shared scratch goes in `src/scratch/` (gitignored) or `build/`.
- Subagent foreground commands stop after 180 s. Long jobs start in the background; finished jobs send a notification, and `sleep` polling is blocked.
- `git checkout -- FILE` discards other agents' edits and `rm -rf "$VAR"` is refused; revert with Edit and remove explicit paths.
- Subagents: `decomp-worker` matches drafts, `lookup` answers read-only questions. Their prompt cache lasts 5 minutes; replace an idle worker instead of resuming it.
