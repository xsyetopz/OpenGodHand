#!/usr/bin/env python3
"""Serve a live decomp-progress treemap and refresh it when sources or objects change.

Usage:
  python tools/live.py [--port 8765] [--interval 5]     (or `just live`)

Open http://127.0.0.1:8765/ . The page polls /progress.json every 3 s and flashes
newly matched functions. A watcher thread stats src/**/*.c* and build/src/**/*.o and
build/actual/*.o every INTERVAL seconds; only when an mtime changed it runs
`tools/configure.py` (to pick up new source files), `ninja report` (which compiles only
stale sources) and `tools/progress.py --json --no-build`. With no change it does no
work. A failing refresh (the tree caught mid-edit by a concurrent session) keeps the last
good progress.json and retries every INTERVAL until it succeeds. The server answers conditional requests, so an unchanged json costs a 304.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import threading
import time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUILD = ROOT / "build"
ROUTES = {"/": ROOT / "tools/live.html", "/index.html": ROOT / "tools/live.html",
          "/progress.json": BUILD / "progress.json", "/status.json": BUILD / "live_status.json"}


class Handler(SimpleHTTPRequestHandler):
    def translate_path(self, path: str) -> str:
        return str(ROUTES.get(path.split("?", 1)[0], ROOT / "build/.missing"))

    def end_headers(self) -> None:
        self.send_header("Cache-Control", "no-cache")  # revalidate via Last-Modified
        super().end_headers()

    def log_message(self, *a) -> None:
        pass


def snapshot() -> dict[str, float]:
    """mtimes of everything whose change can alter the report."""
    files = [*ROOT.joinpath("src").rglob("*.c*"), *ROOT.joinpath("src").rglob("*.h"),
             *BUILD.joinpath("src").rglob("*.o"), *BUILD.joinpath("actual").glob("*.o")]
    scratch = ROOT / "src/scratch"
    snap = {}
    for f in files:
        if f.is_relative_to(scratch):  # configure.py ignores scratch experiments
            continue
        try:
            snap[str(f)] = f.stat().st_mtime
        except OSError:
            pass
    return snap


def refresh() -> str | None:
    """Rebuild progress.json; return None on success, else the reason the tree is unsettled.

    A failed step leaves the previous progress.json in place, so the page keeps the last
    good treemap."""
    steps = [[sys.executable, "tools/configure.py"], ["ninja", "report"],
             [sys.executable, "tools/progress.py", "--json", "--no-build"]]
    for cmd in steps:
        try:
            r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
        except OSError as e:
            return f"{cmd[-1]}: {e}"
        if r.returncode:
            lines = [l for l in (r.stdout + r.stderr).strip().splitlines() if not l.startswith("ninja:")]
            return f"{cmd[-1]}: {lines[-1][:300] if lines else 'failed'}"
    return None


def write_status(pending: str | None) -> None:
    BUILD.mkdir(exist_ok=True)
    (BUILD / "live_status.json").write_text(json.dumps({"ok": pending is None, "message": pending or "", "t": time.time()}))


def watch(interval: float) -> None:
    """Refresh on change; while a refresh fails, retry every tick until the tree settles.

    The working tree is edited concurrently by decomp sessions, so a refresh can observe a
    transient state (a source mid-rename that duplicates an address, a half-written file,
    a concurrent ninja run). Such failures are expected and only delay the update."""
    last, pending = None, None
    while True:
        try:
            snap = snapshot()
            if snap != last or pending is not None:
                last = snap
                reason = refresh()
                last = snapshot()  # the refresh itself may rebuild objects
                if reason is None:
                    print(f"live: refreshed {time.strftime('%H:%M:%S')}", flush=True)
                elif reason != pending:  # log each distinct transient state once
                    print(f"live: waiting for tree to settle ({reason})", flush=True)
                if reason != pending or reason is None:
                    write_status(reason)
                pending = reason
        except Exception as e:  # the watcher thread must outlive any single bad tick
            pending = f"{type(e).__name__}: {e}"
            print(f"live: tick error ({pending}); retrying", flush=True)
        time.sleep(interval)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--port", type=int, default=8765)
    ap.add_argument("--interval", type=float, default=5.0, help="seconds between change checks")
    args = ap.parse_args()
    try:
        srv = ThreadingHTTPServer(("127.0.0.1", args.port), Handler)
    except OSError as e:
        raise SystemExit(f"live: port {args.port} unavailable ({e.strerror}); another live.py may be "
                         f"running (`lsof -i :{args.port}`), or pass --port N")
    threading.Thread(target=watch, args=(args.interval,), daemon=True).start()
    print(f"live: http://127.0.0.1:{args.port}/  (Ctrl-C to stop)", flush=True)
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass
    return 0


if __name__ == "__main__":
    sys.exit(main())
