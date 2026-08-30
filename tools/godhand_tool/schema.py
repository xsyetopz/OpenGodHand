"""Closed schemas and evidence-record validation."""

from __future__ import annotations

from typing import Any

from .repository import PROVENANCE_STATUS, REQUIRED_PROVENANCE


def validate_provenance(value: Any, expected: dict[str, Any], command: str) -> None:
    if not isinstance(value, dict) or set(value) != set(REQUIRED_PROVENANCE):
        raise SystemExit(f"invalid closed provenance fields for {command}")
    if any(
        not isinstance(value[key], str) or not value[key] for key in REQUIRED_PROVENANCE
    ):
        raise SystemExit(f"malformed provenance fields for {command}")
    for key in REQUIRED_PROVENANCE:
        if value[key] != expected[key]:
            raise SystemExit(f"invalid provenance {key} for {command}")
    if value["status"] not in {PROVENANCE_STATUS}:
        raise SystemExit(f"invalid provenance status for {command}")
    if value["command"] != command:
        raise SystemExit(f"invalid provenance command for {command}")


def exact_keys(value: dict[str, Any], keys: set[str], label: str) -> None:
    if set(value) != keys:
        raise SystemExit(f"invalid fields in {label}")


def hex_word(value: Any, label: str) -> int:
    if (
        not isinstance(value, str)
        or len(value) != 10
        or not value.startswith("0x")
        or any(c not in "0123456789abcdef" for c in value[2:])
    ):
        raise SystemExit(f"invalid address/word in {label}")
    try:
        return int(value, 16)
    except ValueError:
        raise SystemExit(f"invalid address/word in {label}")


def evidence_record(value: Any, record: int, offset: int, label: str) -> None:
    if not isinstance(value, dict):
        raise SystemExit(f"invalid evidence in {label}")
    exact_keys(value, {"artifact", "kind", "offset", "record", "section"}, label)
    if value != {
        "artifact": "original/SLUS-21503",
        "kind": "sndata",
        "offset": offset,
        "record": record,
        "section": ".sndata",
    }:
        raise SystemExit(f"invalid evidence in {label}")


def validate_record(record: dict[str, Any], collection: str, line: int) -> None:
    label = f"{collection}.jsonl:{line}"
    if collection == "sections":
        exact_keys(
            record,
            {
                "address",
                "alignment",
                "entry_size",
                "flags",
                "index",
                "info",
                "link",
                "name",
                "offset",
                "payload_present",
                "raw_header_hex",
                "sha256",
                "size",
                "type",
                "type_name",
            },
            label,
        )
        if not isinstance(record["index"], int) or record["index"] < 0:
            raise SystemExit(f"invalid section index in {label}")
        for key in (
            "alignment",
            "entry_size",
            "flags",
            "info",
            "link",
            "offset",
            "size",
            "type",
        ):
            if not isinstance(record[key], int) or record[key] < 0:
                raise SystemExit(f"invalid section integer in {label}")
        if not isinstance(record["name"], str) or not isinstance(
            record["type_name"], str
        ):
            raise SystemExit(f"invalid section string in {label}")
        hex_word(record["address"], label)
        if record["type_name"] != (
            "SHT_NOBITS" if record["type"] == 8 else str(record["type"])
        ):
            raise SystemExit(f"invalid section type name in {label}")
        if not isinstance(record["payload_present"], bool):
            raise SystemExit(f"invalid section payload flag in {label}")
        if (
            not isinstance(record["raw_header_hex"], str)
            or len(record["raw_header_hex"]) != 80
            or any(c not in "0123456789abcdef" for c in record["raw_header_hex"])
        ):
            raise SystemExit(f"invalid section raw header in {label}")
        if record["type_name"] == "SHT_NOBITS":
            if record["payload_present"] or record["sha256"] is not None:
                raise SystemExit(f"invalid NOBITS section in {label}")
        elif (
            not isinstance(record["sha256"], str)
            or len(record["sha256"]) != 64
            or any(c not in "0123456789abcdef" for c in record["sha256"])
        ):
            raise SystemExit(f"invalid section digest in {label}")
        return

    exact_keys(
        record,
        {"address", "confidence", "evidence", "id", "kind", "name", "record", "status"},
        label,
    )
    if record["kind"] != (
        "function" if collection == "functions" else "symbol-evidence"
    ):
        raise SystemExit(f"invalid kind in {label}")
    if not isinstance(record["name"], (str, type(None))) or record[
        "confidence"
    ] not in {"strong", "unknown"}:
        raise SystemExit(f"invalid name/confidence in {label}")
    address = hex_word(record["address"], label)
    inner = record["record"]
    if not isinstance(inner, dict):
        raise SystemExit(f"invalid source record in {label}")
    exact_keys(
        inner,
        {
            "address",
            "classification",
            "confidence",
            "evidence",
            "name",
            "raw_hex",
            "raw_offset",
            "record",
            "word0",
            "word1",
            "word2",
            "word2_meaning",
        },
        label,
    )
    if (
        inner["address"] != record["address"]
        or hex_word(inner["address"], label) != address
    ):
        raise SystemExit(f"address mismatch in {label}")
    if (
        not isinstance(inner["record"], int)
        or inner["record"] < 0
        or not isinstance(inner["raw_offset"], int)
        or inner["raw_offset"] < 0
    ):
        raise SystemExit(f"invalid source record numbers in {label}")
    if inner["classification"] not in {
        "function-candidate",
        "symbol-evidence",
        "ambiguous-address",
        "truncated",
    }:
        raise SystemExit(f"invalid classification in {label}")
    if inner["confidence"] not in {"strong", "unknown"} or not isinstance(
        inner["word2_meaning"], str
    ):
        raise SystemExit(f"invalid source confidence in {label}")
    if (
        not isinstance(inner["name"], (str, type(None)))
        or not isinstance(inner["raw_hex"], str)
        or len(inner["raw_hex"]) != 24
    ):
        raise SystemExit(f"invalid source payload in {label}")
    for key in ("word0", "word1", "word2"):
        hex_word(inner[key], label)
    if hex_word(inner["word1"], label) != address:
        raise SystemExit(f"word/address mismatch in {label}")
    evidence_record(inner["evidence"], inner["record"], inner["raw_offset"], label)
    if not isinstance(record["evidence"], list) or record["evidence"] != [
        inner["evidence"]
    ]:
        raise SystemExit(f"invalid evidence linkage in {label}")
    status = record["status"]
    if not isinstance(status, dict):
        raise SystemExit(f"invalid status in {label}")
    exact_keys(status, {"decompiled", "functional", "identified", "matching"}, label)
    if (
        any(
            not isinstance(status[key], bool)
            for key in ("decompiled", "functional", "identified")
        )
        or status["matching"] is not None
    ):
        raise SystemExit(f"invalid status values in {label}")
    if collection == "functions":
        if (
            record["id"] != f"target:GAME/function:{record['address']}"
            or record["confidence"] != "strong"
            or inner["classification"] != "function-candidate"
            or inner["confidence"] != "strong"
            or status["identified"] is not True
        ):
            raise SystemExit(f"invalid function contract in {label}")
    else:
        if (
            record["id"] != f"target:GAME/symbol:sndata-record-{inner['record']:05d}"
            or record["confidence"] != inner["confidence"]
            or status["identified"] != bool(record["name"])
        ):
            raise SystemExit(f"invalid symbol contract in {label}")
