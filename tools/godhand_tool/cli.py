"""Stable command-line parser and dispatch."""

from __future__ import annotations

import argparse

from .commands import analyze, check, extract, future, verify_input


def main() -> None:
    parser = argparse.ArgumentParser()
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("verify-input").set_defaults(func=verify_input)
    p = sub.add_parser("extract")
    p.add_argument("--clean", action="store_true")
    p.set_defaults(func=extract)
    sub.add_parser("analyze").set_defaults(func=analyze)
    sub.add_parser("check").set_defaults(func=check)
    for kind in ("compare", "datacmp", "vtable", "test", "report", "roadmap"):
        sub.add_parser(kind).set_defaults(func=future, kind=kind)
    for kind in ("compare-fn", "context"):
        p = sub.add_parser(kind)
        p.add_argument("address")
        p.set_defaults(func=future, kind=kind)
    args = parser.parse_args()
    args.func(args)
