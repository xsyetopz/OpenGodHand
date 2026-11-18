"""objdiff project configuration for the progress report.

`configure.py` calls `emit()` to write `objdiff.json` and to obtain the ninja
statements that build the objects objdiff compares. One objdiff unit exists per
group, where a group approximates a translation unit: units are walked in link order and a
new group opens whenever the class of a named function changes (GCC 2.x mangled
name). Free and unnamed `func_*` functions join the preceding group. Groups are
named after their class, `_2`, `_3` on repeats; `sdk` (sce*, Sde*, kernel calls)
and `libc` (memcpy, __builtin_*, ...) are keys of their own, and every unit in the
CRI middleware span forms `cri`. Categories: game, sdk, CRI middleware,
libc/runtime, unknown (groups before the first named function).

target_path  build/expected/<group>.o   all asm units of the group, assembled
                                        from a generated build/expected/<group>.s
base_path    build/actual/<group>.o     the compiled src object (`ld -r` when several)
                                        that defines at least one function of the group;
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


LIBC = set(
    "atanf cosf sinf powf sqrtf memcmp memcpy memmove memset strcat strcmp strcpy strlen strncmp strncpy "
    "_cleanup _exit printf sprintf vsprintf abort __assert atexit atof atoi malloc free strtod strrchr "
    "strtok strtol".split()
)
LIBC_PREFIX = ("__builtin_", "__nw", "__dl", "__vec_", "__throw", "__eh")
KERNEL = set(
    "CreateThread DeleteThread TerminateThread GetThreadId CreateSema DeleteSema SignalSema iSignalSema "
    "WaitSema PollSema FlushCache DelayThread StartThread".split()
)
# CRI ADX/Sofdec code carries few .sndata names, so it is placed by address
# (docs/decomp.md, "CRI middleware") rather than by symbol.
CRI_SPAN = (0x322978, 0x36D1A8)
CATEGORY = {"class": "game", "sdk": "sdk", "cri": "cri", "libc": "libc", "none": "unknown"}
CATEGORY_NAMES = {"game": "Game", "sdk": "SDK", "cri": "CRI middleware", "libc": "libc/runtime", "unknown": "Unknown"}


def class_of(name: str) -> str | None:
    """Class named by a GCC 2.x mangled symbol, or None for free functions and unnamed symbols."""
    m = SPECIAL.match(name)
    candidates = [(m.group(1), m.end(1))] if m else [(x.group(1), x.end(1)) for x in QUALIFIED.finditer(name)]
    for digits, end in candidates:
        n = int(digits)
        cls = name[end : end + n]
        if len(cls) == n and re.fullmatch(r"[A-Za-z_]\w*", cls):
            return cls
    return None


def key_of(name: str) -> tuple[str, str] | None:
    """(kind, key) that opens or continues a group; None folds into the current group."""
    if name.startswith("func_"):
        return None
    if name.startswith(("sce", "Sde")) or name in KERNEL:
        return "sdk", "sdk"
    if name in LIBC or name.startswith(LIBC_PREFIX):
        return "libc", "libc"
    cls = class_of(name)
    return ("class", cls) if cls else None


def group_units(units) -> dict[str, list[tuple[int, int, str]]]:
    """Approximate translation units: walk units in link order and open a group whenever the
    class of a named function differs from the current group's. Unnamed and free functions
    join the current group; any before the first named function form `unknown`."""
    groups: dict[str, list] = {}
    kinds: dict[str, str] = {}
    count: dict[str, int] = defaultdict(int)
    cur_key, cur = None, None
    for u in units:
        k = ("cri", "cri") if CRI_SPAN[0] <= u[0] < CRI_SPAN[1] else key_of(u[2])
        if cur is None or (k is not None and k[1] != cur_key):
            kind, key = k or ("none", "unknown")
            count[key] += 1
            cur = key if count[key] == 1 else f"{key}_{count[key]}"
            cur_key = key
            groups[cur], kinds[cur] = [], kind
        groups[cur].append(u)
    seen: dict[str, str] = {}
    for g in groups:  # macOS file systems are case-insensitive
        if seen.setdefault(g.lower(), g) != g:
            raise SystemExit(f"groups {seen[g.lower()]!r} and {g!r} differ only by case")
    group_units.kinds = kinds
    return groups


def category(group: str) -> str:
    return CATEGORY[group_units.kinds[group]]


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
        "rule ldr\n  command = $ld -EL -r -T config/merge.ld -o $out $in\n  description = LD -r $out",
        "rule report\n  command = tools/bin/objdiff-cli report generate -p . -o $out\n  description = REPORT $out",
        "rule progress\n  command = $py tools/progress.py --no-build\n  description = PROGRESS $out",
    ]
    out_units, expected, actual = [], [], []
    for g in sorted(groups):
        us = groups[g]
        asm = [f"asm/text/{v:08X}.s" for v, _s, _n in us]
        s = ROOT / f"build/expected/{g}.s"
        # Each unit positions its code with `.org` from the start of
        # `.text.unit`, so every unit gets its own section here.
        text = "".join(
            (ROOT / a).read_text().replace(".section .text.unit,", f".section .text.u{v:08X},")
            for a, (v, _s, _n) in zip(asm, us)
        )
        if not s.exists() or s.read_text() != text:  # keep mtime stable for ninja
            s.write_text(text)
        n.append(f"build build/expected/{g}.o: asm_obj build/expected/{g}.s | {' '.join(asm)}")
        expected.append(f"build/expected/{g}.o")
        unit = {
            "name": g,
            "target_path": f"build/expected/{g}.o",
            "metadata": {"progress_categories": [category(g)], "auto_generated": False},
        }
        if len(srcs_of.get(g, ())) == 1:  # a lone object needs no `ld -r`
            unit["base_path"] = next(iter(srcs_of[g]))
        elif srcs_of.get(g):
            n.append(f"build build/actual/{g}.o: ldr {' '.join(sorted(srcs_of[g]))} | config/merge.ld")
            unit["base_path"] = f"build/actual/{g}.o"
            actual.append(unit["base_path"])
        if "base_path" in unit and unit["base_path"] not in actual:
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
        "progress_categories": [{"id": c, "name": n} for c, n in CATEGORY_NAMES.items()],
    }
    (ROOT / "objdiff.json").write_text(json.dumps(cfg, indent=2) + "\n")
    n.append(f"build build/report.json: report objdiff.json {' '.join(expected + actual)} | tools/bin/objdiff-cli")
    n.append("build build/progress.svg: progress build/report.json | tools/progress.py")
    n.append("build report: phony build/report.json")
    n.append("build progress: phony build/progress.svg")
    return n
