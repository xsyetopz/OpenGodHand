"""objdiff project configuration for the progress report.

`configure.py` calls `emit()` to write `objdiff.json` and to obtain the ninja
statements that build the objects objdiff compares. One objdiff unit exists per
group, where a group is a C++ class (from the GCC 2.x mangled name), `sdk` for
`sce*` library functions, or `misc` for free functions and unnamed `func_*`.

target_path  build/expected/<group>.o   all asm units of the group, assembled
                                        from a generated build/expected/<group>.s
base_path    build/actual/<group>.o     `ld -r` of the compiled src objects that
                                        define at least one function of the group;
                                        omitted while the group has none (0%)
"""

from __future__ import annotations

import json
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# `__tf9cOmWeapon`, `_$_7cPlBase`, `__7cPlBase`, `name__C6cEvent`, `name__Q27cRelSys8eRelType`
SPECIAL = re.compile(r"^(?:__tf|__vt_|_\$_)(\d+)")
QUALIFIED = re.compile(r"__(?:C)?(?:Q[2-9_]+)?(\d+)")


def group_of(name: str) -> str:
    """Return the class, `sdk` or `misc` for a symbol name."""
    if name.startswith("sce"):
        return "sdk"
    if name.startswith("func_"):
        return "misc"
    m = SPECIAL.match(name)
    candidates = [(m.group(1), m.end(1))] if m else [(x.group(1), x.end(1)) for x in QUALIFIED.finditer(name)]
    for digits, end in candidates:
        n = int(digits)
        cls = name[end : end + n]
        if len(cls) == n and re.fullmatch(r"[A-Za-z_]\w*", cls):
            return cls
    return "misc"


def group_units(units) -> dict[str, list[tuple[int, int, str]]]:
    groups: dict[str, list] = defaultdict(list)
    for u in units:
        groups[group_of(u[2])].append(u)
    # macOS file systems are case-insensitive; keep group file names distinct.
    seen: dict[str, str] = {}
    for g in sorted(groups):
        if seen.setdefault(g.lower(), g) != g:
            raise SystemExit(f"groups {seen[g.lower()]!r} and {g!r} differ only by case")
    return dict(groups)


def category(group: str) -> str:
    return group if group in ("sdk", "misc") else "classes"


def emit(units, sources: dict[Path, list[int]]) -> list[str]:
    """Write objdiff.json and build/expected/*.s; return ninja statements."""
    groups = group_units(units)
    group_by_addr = {u[0]: g for g, us in groups.items() for u in us}
    srcs_of: dict[str, set[str]] = defaultdict(set)
    for src, addrs in sources.items():
        for a in addrs:
            srcs_of[group_by_addr[a]].add("build/" + str(src.with_suffix(".o")))

    (ROOT / "build/expected").mkdir(parents=True, exist_ok=True)
    n = [
        "rule asm_obj\n  command = $as $ASFLAGS -o $out $in\n  description = AS $out",
        "rule ldr\n  command = $ld -EL -r -o $out $in\n  description = LD -r $out",
        "rule report\n  command = tools/bin/objdiff-cli report generate -p . -o $out\n  description = REPORT $out",
        "rule progress\n  command = $py tools/progress.py --no-build\n  description = PROGRESS $out",
    ]
    out_units, expected, actual = [], [], []
    for g in sorted(groups):
        us = groups[g]
        asm = [f"asm/text/{v:08X}.s" for v, _s, _n in us]
        s = ROOT / f"build/expected/{g}.s"
        text = "".join(f'.include "{a}"\n' for a in asm)
        if not s.exists() or s.read_text() != text:  # keep mtime stable for ninja
            s.write_text(text)
        n.append(f"build build/expected/{g}.o: asm_obj build/expected/{g}.s | {' '.join(asm)}")
        expected.append(f"build/expected/{g}.o")
        unit = {
            "name": g,
            "target_path": f"build/expected/{g}.o",
            "metadata": {"progress_categories": [category(g)], "auto_generated": False},
        }
        if srcs_of.get(g):
            n.append(f"build build/actual/{g}.o: ldr {' '.join(sorted(srcs_of[g]))}")
            unit["base_path"] = f"build/actual/{g}.o"
            actual.append(unit["base_path"])
        out_units.append(unit)

    cfg = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "custom_make": "ninja",
        "custom_args": [],
        "build_target": False,
        "build_base": False,
        "watch_patterns": ["src/**/*.c", "src/**/*.cpp", "src/**/*.h", "include/**/*.h"],
        "units": out_units,
        "progress_categories": [
            {"id": "classes", "name": "Classes"},
            {"id": "sdk", "name": "SDK"},
            {"id": "misc", "name": "Misc"},
        ],
    }
    (ROOT / "objdiff.json").write_text(json.dumps(cfg, indent=2) + "\n")
    n.append(f"build build/report.json: report objdiff.json {' '.join(expected + actual)} | tools/bin/objdiff-cli")
    n.append("build build/progress.svg: progress build/report.json | tools/progress.py")
    n.append("build report: phony build/report.json")
    n.append("build progress: phony build/progress.svg")
    return n
