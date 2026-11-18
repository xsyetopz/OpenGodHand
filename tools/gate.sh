#!/bin/bash
# Commits the staged src/include/docs/config tree once a frozen snapshot of it builds byte-identical.
#
#   bash tools/gate.sh        poll every 90 s until one snapshot passes, commit it, exit 0
#
# The snapshot is built in a separate worktree ($GATE_DIR), so workers writing into the main tree
# cannot invalidate a build mid-flight; only the exact verified tree is committed, and the main
# working tree keeps its uncommitted changes. Ignored inputs (ISO extract, asm, toolchains, venv)
# are symlinked into the worktree on first use. A snapshot passes when tools/claimed.py is clean,
# no source exceeds 300 lines, ninja reports SLUS_215.03: OK and linkgen lists no differing unit.
set -u
R=$(cd "$(dirname "$0")/.." && pwd)
G=${GATE_DIR:-${TMPDIR:-/tmp}/gh-gate}
L=$G.log
B=$(git -C "$R" symbolic-ref --short HEAD)
cd "$R"
if [ ! -e "$G/.git" ]; then
  git worktree add -q --detach "$G" HEAD || exit 1
fi
# A path that the worktree already holds as a real directory (original/ keeps a tracked README)
# gets its missing children linked instead, so the ISO extract still reaches the snapshot.
for p in .venv asm assets original tools/bin tools/compilers tools/ext; do
  [ -e "$R/$p" ] || continue
  if [ ! -e "$G/$p" ]; then
    ln -s "$R/$p" "$G/$p"
  elif [ -d "$G/$p" ] && [ ! -L "$G/$p" ]; then
    for c in "$R/$p"/*; do [ -e "$G/$p/${c##*/}" ] || ln -s "$c" "$G/$p/${c##*/}"; done
  fi
done
stage() { git add -A src include docs config && git reset -q -- 'src/game/Probe*' 'src/game/tmp_*' 'src/*/_*'; git write-tree; }
while true; do
  cd "$R"
  if [ -z "$(.venv/bin/python tools/claimed.py 2>&1)" ] && [ -z "$(wc -l src/*/*.c* | awk '$1>300 && $2!="total"')" ]; then
    T=$(stage)
    P=$(git rev-parse HEAD)
    if [ "$T" != "$(git rev-parse 'HEAD^{tree}')" ]; then
      C=$(git commit-tree "$T" -p "$P" -m snapshot)
      cd "$G"
      git checkout -q -f --detach "$C" && git clean -fdq -- src include config
      # The linker reads splat's generated undefined-symbol lists, which live only in the main build/.
      mkdir -p build && for f in undefined_funcs_auto.txt undefined_syms_auto.txt; do
        [ -e "$R/build/$f" ] && cp "$R/build/$f" "build/$f"
      done
      if ! .venv/bin/python tools/configure.py > "$L" 2>&1; then echo "configure failed $(date +%T): $(tail -1 "$L")"; sleep 90; continue; fi
      if ninja -j8 > "$L" 2>&1 && grep -q "SLUS_215.03: OK" "$L" && [ -z "$(awk -F'\t' '$2=="differ"' build/linkgen.tsv)" ] && [ -z "$(.venv/bin/python tools/claimed.py 2>&1)" ]; then
        n=$(grep -o "linkgen: [0-9]* compiled" "$L")
        C2=$(git commit-tree "$T" -p "$P" -m "Worker matches batch ($n)")
        cd "$R"
        # The old-value guard refuses the update if HEAD moved during the build.
        if git update-ref "refs/heads/$B" "$C2" "$P"; then
          git reset -q
          echo "COMMIT $(git log --oneline -1) | $n"
          exit 0
        fi
        echo "HEAD moved $(date +%T)"; continue
      fi
      echo "snapshot failed $(date +%T): $(grep -m3 -iE 'FAILED|differ|MISMATCH|error' "$L" | tr '\n' ' ')"
    else
      echo "nothing to commit"; exit 0
    fi
  fi
  sleep 90
done
