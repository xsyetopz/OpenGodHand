#!/usr/bin/env python3
"""Render decomp progress as a treemap from objdiff's report.

Usage:
  python tools/progress.py             build build/report.json with ninja, then draw
  python tools/progress.py --no-build  read an existing report (what `ninja progress` uses)
  ninja progress                       same as the first form, through the build graph
  python tools/progress.py --json      write build/progress.json (for tools/live.py) instead of the SVG

The report comes from `tools/bin/objdiff-cli report generate` (see
tools/objdiff_config.py); a function counts as matched when objdiff reports a
fuzzy match of 100%. Output is the self-contained build/progress.svg: one block
per category (game, sdk, libc/runtime, unknown), one labelled rectangle per group sized by code
bytes, and one cell per function (green matched, grey not) in address order. The
overall percentage is printed by code bytes and by function count.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import time
from html import escape
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TITLE = "God Hand"
W, H, TOP = 1600, 900, 40
GREEN, GREY, BG, EDGE = "#3fb950", "#4a4f57", "#14161a", "#0b0c0e"
HEADER = 13  # label strip above a category's groups


def squarify(items: list[tuple[object, float]], x: float, y: float, w: float, h: float):
    """Squarified treemap (Bruls et al.). Returns [(key, x, y, w, h)] for items sorted by size, descending."""
    items = sorted((i for i in items if i[1] > 0), key=lambda i: -i[1])
    total = sum(s for _, s in items)
    out = []
    if not items or w <= 0 or h <= 0:
        return out
    scale = w * h / total
    rest = [(k, s * scale) for k, s in items]

    def worst(row, side):
        s = sum(a for _, a in row)
        return max(max(side * side * a / (s * s), s * s / (side * side * a)) for _, a in row)

    while rest:
        side = min(w, h)
        row = [rest[0]]
        i = 1
        while i < len(rest) and worst(row + [rest[i]], side) <= worst(row, side):
            row.append(rest[i])
            i += 1
        rest = rest[i:]
        s = sum(a for _, a in row)
        if w >= h:  # lay the row as a column on the left
            cw = s / h
            cy = y
            for k, a in row:
                out.append((k, x, cy, cw, a / cw))
                cy += a / cw
            x, w = x + cw, w - cw
        else:
            rh = s / w
            cx = x
            for k, a in row:
                out.append((k, cx, y, a / rh, rh))
                cx += a / rh
            y, h = y + rh, h - rh
    return out


def load(report: Path) -> list[dict]:
    """Flatten the report into groups: name, category, functions [(name, size, matched)]."""
    data = json.loads(report.read_text())
    names = {c["id"]: c["name"] for c in data.get("categories", [])}
    groups = []
    for u in data.get("units", []):
        cats = u.get("metadata", {}).get("progress_categories") or ["unknown"]
        fns = [
            (
                f.get("metadata", {}).get("demangled_name") or f["name"],
                int(f.get("size", 0)),
                f.get("fuzzy_match_percent", 0.0) >= 100.0,
            )
            for f in u.get("functions", [])
        ]
        groups.append({"name": u["name"], "cat": names.get(cats[0], cats[0]), "fns": fns, "size": sum(f[1] for f in fns)})
    return groups


def write_json(groups: list[dict], title: str, path: Path, recent_max: int = 40) -> None:
    """Write summary plus per-function state. `recent` keeps newly matched functions across
    rewrites by reading the previous file, so a page opened later still sees them."""
    now = time.time()
    old, recent = None, []
    if path.exists():
        try:
            prev = json.loads(path.read_text())
            recent = prev.get("recent", [])
            old = {(g["name"], f[0]) for g in prev["groups"] for f in g["fns"] if f[2]}
        except (ValueError, KeyError, IndexError):
            pass
    fresh = [
        {"fn": f[0], "group": g["name"], "t": now}
        for g in groups
        for f in g["fns"]
        if f[2] and old is not None and (g["name"], f[0]) not in old
    ]
    fns = [f for g in groups for f in g["fns"]]
    doc = {
        "title": title,
        "updated": now,
        "functions": {"matched": sum(f[2] for f in fns), "total": len(fns)},
        "bytes": {"matched": sum(f[1] for f in fns if f[2]), "total": sum(f[1] for f in fns)},
        "recent": (fresh + recent)[:recent_max],
        "groups": [
            {"name": g["name"], "cat": g["cat"], "size": g["size"], "fns": [[n, s, int(ok)] for n, s, ok in g["fns"]]}
            for g in groups
        ],
    }
    tmp = path.with_suffix(".tmp")
    tmp.write_text(json.dumps(doc, separators=(",", ":")))
    tmp.replace(path)  # readers never see a partial file


def cells(g: dict, x: float, y: float, w: float, h: float, out: list[str]) -> None:
    n = len(g["fns"])
    matched = sum(1 for f in g["fns"] if f[2])
    cols = max(1, min(n, round((n * w / h) ** 0.5)))
    rows = -(-n // cols)
    cw, ch = w / cols, h / rows
    if min(cw, ch) < 2.5:  # too dense for cells: one block shaded by the matched share
        out.append(f'<rect x="{x:.2f}" y="{y:.2f}" width="{w:.2f}" height="{h:.2f}" fill="{GREEN if matched * 2 > n else GREY}"/>')
        return
    gap = 1 if min(cw, ch) >= 4 else 0.5
    for i, (name, size, ok) in enumerate(g["fns"]):
        cx, cy = x + (i % cols) * cw, y + (i // cols) * ch
        out.append(
            f'<rect x="{cx + gap / 2:.2f}" y="{cy + gap / 2:.2f}" width="{cw - gap:.2f}" height="{ch - gap:.2f}" '
            f'fill="{GREEN if ok else GREY}"><title>{escape(name)} ({size} bytes)'
            f'{" - matched" if ok else ""}</title></rect>'
        )


def render(groups: list[dict], title: str) -> str:
    out = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{W}" height="{H}" viewBox="0 0 {W} {H}" '
        'font-family="Helvetica,Arial,sans-serif">',
        f'<rect width="{W}" height="{H}" fill="{BG}"/>',
        f'<text x="12" y="27" font-size="22" fill="#e6e6e6" font-weight="bold">{escape(title)}</text>',
    ]
    cats: dict[str, list[dict]] = {}
    for g in groups:
        cats.setdefault(g["cat"], []).append(g)
    area = (4, TOP, W - 8, H - TOP - 4)
    for cat, cx, cy, cw, ch in squarify([(c, sum(g["size"] for g in gs)) for c, gs in cats.items()], *area):
        gs = cats[cat]
        out.append(f'<rect x="{cx:.2f}" y="{cy:.2f}" width="{cw:.2f}" height="{ch:.2f}" fill="{EDGE}" stroke="#2c3037"/>')
        head = HEADER if ch > 3 * HEADER and cw > 60 else 0
        if head:
            m = sum(1 for g in gs for f in g["fns"] if f[2])
            out.append(
                f'<text x="{cx + 4:.1f}" y="{cy + 10:.1f}" font-size="10" fill="#9aa0a6">'
                f'{escape(cat)} ({m}/{sum(len(g["fns"]) for g in gs)})</text>'
            )
        for g, gx, gy, gw, gh in squarify([(g["name"], g["size"]) for g in gs], cx + 1, cy + head + 1, cw - 2, ch - head - 2):
            g = next(q for q in gs if q["name"] == g)
            inner = 1.0 if gw > 8 and gh > 8 else 0.0
            cells(g, gx + inner, gy + inner, gw - 2 * inner, gh - 2 * inner, out)
            out.append(
                f'<rect x="{gx:.2f}" y="{gy:.2f}" width="{gw:.2f}" height="{gh:.2f}" fill="none" stroke="{EDGE}" stroke-width="1">'
                f'<title>{escape(g["name"])}: {sum(1 for f in g["fns"] if f[2])}/{len(g["fns"])} functions</title></rect>'
            )
            if gw > 7 * len(g["name"]) + 6 and gh > 22:
                out.append(
                    f'<text x="{gx + 4:.1f}" y="{gy + 12:.1f}" font-size="11" fill="#ffffff" stroke="#000" '
                    f'stroke-width="2.5" paint-order="stroke">{escape(g["name"])}</text>'
                )
    out.append("</svg>")
    return "\n".join(out) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--report", type=Path, default=ROOT / "build/report.json")
    ap.add_argument("--out", type=Path, default=ROOT / "build/progress.svg")
    ap.add_argument("--json", action="store_true", help="write build/progress.json instead of the SVG")
    ap.add_argument("--no-build", action="store_true", help="do not run ninja to refresh the report")
    args = ap.parse_args()
    if not args.no_build:
        subprocess.run(["ninja", "-C", str(ROOT), str(args.report.relative_to(ROOT))], check=True)
    groups = load(args.report)
    fns = [f for g in groups for f in g["fns"]]
    total_n, done_n = len(fns), sum(1 for f in fns if f[2])
    total_b, done_b = sum(f[1] for f in fns), sum(f[1] for f in fns if f[2])
    pct = 100.0 * done_n / total_n if total_n else 0.0
    title = f"{TITLE}: {pct:.2f}% ({done_n}/{total_n})"
    args.out.parent.mkdir(parents=True, exist_ok=True)
    if args.json:
        args.out = args.out.with_suffix(".json")
        write_json(groups, title, args.out)
    else:
        args.out.write_text(render(groups, title))
    print(f"{title}")
    print(f"functions: {done_n}/{total_n} = {pct:.2f}%")
    print(f"code bytes: {done_b}/{total_b} = {100.0 * done_b / total_b if total_b else 0.0:.2f}%")
    print(f"groups: {len(groups)}; wrote {args.out.relative_to(ROOT) if args.out.is_relative_to(ROOT) else args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
