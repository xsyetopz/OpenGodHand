"""Canonical JSON and JSONL sidecar serialization."""

from __future__ import annotations

import json
import pathlib
from typing import Any

from .repository import REFERENCE, provenance, sha256


def write_json(path: pathlib.Path, value: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(
        json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


def write_jsonl(path: pathlib.Path, records: list[dict[str, Any]]) -> None:
    """Write canonical one-record-per-line JSON without incidental whitespace."""
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(
        "".join(
            json.dumps(record, separators=(",", ":"), sort_keys=True) + "\n"
            for record in records
        ),
        encoding="utf-8",
    )


def jsonl_sha256(path: pathlib.Path) -> str:
    return sha256(path)


def sidecar(
    path: str, schema: str, records: list[dict[str, Any]], status: str
) -> dict[str, Any]:
    records_path = REFERENCE / path
    return {
        "schema": schema,
        "provenance": provenance("analyze"),
        "records_file": records_path.name,
        "record_count": len(records),
        "records_sha256": jsonl_sha256(records_path),
        "status": status,
    }
