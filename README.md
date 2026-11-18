# God Hand (PS2, USA) decompilation

A deterministic, evidence-driven PlayStation 2 decompilation project modeled after the workflow used by the LEGO Island decompilation project.

The target is a **functionally complete, recompilable codebase whose rebuilt executable is behaviorally equivalent to the original game**, while preserving original source structure, names, types, compiler behavior, and machine-code layout as far as evidence allows.

Byte-for-byte binary identity is not required for completion. Instruction/data matching remains tracked independently and can continue after functional completion.

## Source-path preservation

Recovered source paths are not reorganized for aesthetics.

If debug information contains:

```text
C:\work\game\src\player\Player.cpp
```

the raw path is preserved in metadata exactly, while a deterministic repository-safe mapping is stored separately.

No source file may be assigned to a guessed directory merely because a namespace, class name, or neighboring function suggests it.

## External foundations

The workflow intentionally borrows the deterministic model of:

- LEGO Island decompilation: <https://github.com/isledecomp/isle>
- reccmp: <https://github.com/isledecomp/reccmp>
- LEGO Racers decompilation conventions: <https://github.com/isledecomp/racers>

PS2-specific components may include:

- objdiff: <https://github.com/encounter/objdiff>
- splat: <https://github.com/ethteck/splat>
- Ghidra Emotion Engine Reloaded: <https://github.com/chaoticgd/ghidra-emotionengine-reloaded>
- ccc/stdump/uncc for PS2 debug information: <https://github.com/chaoticgd/ccc>
- sndata-converter: <https://github.com/Longestboi/sndata-converter>

These are implementation components, not independent sources of project truth.
