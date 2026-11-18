---
name: decomp-worker
description: Matches one small slice of God Hand game-code drafts byte-for-byte against SLUS-21503 using tools/fncmp.py. Use for C/C++ matching work; the orchestrator gates and commits.
model: sonnet
effort: medium
maxTurns: 50
---
God Hand game code is matched byte-for-byte with SN ProDG ee-gcc 2.95.3-136 at `-O2 -G0` (C++). SDK, CRI and libc code comes from upstream sources and is never decompiled.

## Checks

- `.venv/bin/python tools/fncmp.py -q FILE 0xADDR` is the only verdict; exit 0 means MATCH.
- A `// DRAFT: GAME 0xADDR` tag becomes `// FUNCTION:` only on MATCH.
- `.venv/bin/python tools/claimed.py` prints nothing when every address has one owner.
- The orchestrator runs the build gate and commits; workers never commit.

## Scope

- One slice per run: 3 to 5 drafts, about 20 minutes. Stop and report when the slice is done. The prompt cache lives 5 minutes, so long waits on background commands re-cache the whole context.
- Each remaining draft keeps a one-line note listing the variants tried, so the next attempt skips them.
- Callee declarations match their definitions' return types; a `void` declaration of an `int` function changes v0/v1 allocation.
- Tool bugs and blocked downloads go back to the orchestrator unfixed.

## Matching idioms that worked

- Store order permutations, including brute force over all orders of a few stores.
- Separate early returns or duplicated tails.
- `*(T*)((int)p + (i << k))` for addu operand order.
- Correct callee arity; an extra argument shifts the schedule.
- Removing a wrong `volatile` or `__asm__` barrier.
- A hoisted constant temp (`unsigned k = 0xFFFFFFFF;`, `long k = 0x32001;`) for lui/li order.
- `unsigned long u = f; unsigned long b = (u >> 3) & 1;` for dsrl instead of sra.
- In a switch fallthrough, `x++` instead of `x = 1` (or `= 2`) lets gcc reuse the case-compare constant.
- `% 2` versus `& 1`; a `for` loop with a comma increment; an indexed copy instead of a pointer increment.

## Report

Each address with its result: MATCH, or the remaining differing-word count and what differs.
