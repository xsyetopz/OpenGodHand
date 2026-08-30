"""CLI command orchestration over the package boundaries."""

from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import subprocess

from .elf import parse_sndata, read_elf
from .repository import (
    BUILD,
    ORIGINAL,
    REFERENCE,
    ROOT,
    TARGET,
    input_manifest,
    provenance,
    sha256,
)
from .schema import exact_keys, validate_provenance, validate_record
from .serialization import sidecar, write_json, write_jsonl

COLLECTION_CONTRACTS = {
    "sections": ("godhand.sections.v4", "complete-for-elf-section-table"),
    "symbols": ("godhand.symbols.v5", "complete-for-sndata-records"),
    "functions": (
        "godhand.functions.v5",
        "mechanically-promoted-unique-code-addresses",
    ),
}


def verify_input(_: argparse.Namespace) -> None:
    if not TARGET.is_file():
        raise SystemExit(f"missing target executable: {TARGET}")
    manifest = input_manifest()
    write_json(ORIGINAL / "hashes.json", manifest)
    print(f"verified {len(manifest['files'])} private input files")


def extract(ns: argparse.Namespace) -> None:
    iso = ORIGINAL / "SLUS-21503.iso"
    if not iso.is_file():
        raise SystemExit(f"missing private ISO: {iso}")
    out = BUILD / "extracted"
    if out.exists() and ns.clean:
        shutil.rmtree(out)
    out.mkdir(parents=True, exist_ok=True)
    subprocess.run(["bsdtar", "-xf", str(iso), "-C", str(out)], check=True)
    files = []
    for path in sorted(out.rglob("*")):
        if path.is_file() and path.name != "manifest.json":
            files.append(
                {
                    "path": path.relative_to(out).as_posix(),
                    "sha256": sha256(path),
                    "size": path.stat().st_size,
                }
            )
    write_json(
        out / "manifest.json",
        {
            "schema": "godhand.extracted-manifest.v2",
            "provenance": provenance("extract"),
            "source_iso_sha256": sha256(iso),
            "files": files,
        },
    )
    print(f"extracted ISO to {out.relative_to(ROOT)}")


def analyze(_: argparse.Namespace) -> None:
    if not TARGET.is_file():
        raise SystemExit("run just verify-input first or provide original/SLUS-21503")
    elf, sections, programs = read_elf(TARGET)
    sndata = next((s for s in sections if s["name"] == ".sndata"), None)
    executable_ranges = [
        (int(s["address"], 16), int(s["address"], 16) + s["size"])
        for s in sections
        if s["flags"] & 4 and s["type_name"] != "SHT_NOBITS"
    ]
    records = parse_sndata(TARGET, sndata, executable_ranges) if sndata else []
    address_counts: dict[str, int] = {}
    for record in records:
        if record["classification"] == "function-candidate":
            address_counts[record["address"]] = (
                address_counts.get(record["address"], 0) + 1
            )
    for record in records:
        if (
            record["classification"] == "function-candidate"
            and address_counts.get(record["address"], 0) != 1
        ):
            record["classification"], record["confidence"] = (
                "ambiguous-address",
                "unknown",
            )
    symbols = [
        {
            "id": f"target:GAME/symbol:sndata-record-{x['record']:05d}",
            "kind": "symbol-evidence",
            "name": x["name"],
            "address": x["address"],
            "record": x,
            "evidence": [x["evidence"]],
            "confidence": x["confidence"],
            "status": {
                "identified": bool(x["name"]),
                "decompiled": False,
                "functional": False,
                "matching": None,
            },
        }
        for x in records
    ]
    functions = [
        {
            "id": f"target:GAME/function:{x['address']}",
            "kind": "function",
            "name": x["name"],
            "address": x["address"],
            "record": x,
            "evidence": [x["evidence"]],
            "confidence": "strong",
            "status": {
                "identified": True,
                "decompiled": False,
                "functional": False,
                "matching": None,
            },
        }
        for x in records
        if x["classification"] == "function-candidate"
    ]
    REFERENCE.mkdir(exist_ok=True)
    elf["programs"] = programs
    write_json(REFERENCE / "elf.json", elf)
    write_jsonl(REFERENCE / "sections.jsonl", sections)
    write_json(
        REFERENCE / "sections.json",
        sidecar(
            "sections.jsonl",
            "godhand.sections.v4",
            sections,
            "complete-for-elf-section-table",
        ),
    )
    evidence = {
        "schema": "godhand.sndata.v2",
        "provenance": provenance("analyze"),
        "section": sndata,
        "decoder": "embedded-sndata-v1",
        "raw_preserved": bool(sndata),
        "note": "Unknown records are retained verbatim.",
    }
    if sndata:
        raw = TARGET.read_bytes()[sndata["offset"] : sndata["offset"] + sndata["size"]]
        (REFERENCE / "sndata.bin").write_bytes(raw)
        evidence["raw_sha256"] = hashlib.sha256(raw).hexdigest()
    write_json(REFERENCE / "sndata.json", evidence)
    write_jsonl(REFERENCE / "symbols.jsonl", symbols)
    write_json(
        REFERENCE / "symbols.json",
        sidecar(
            "symbols.jsonl",
            "godhand.symbols.v5",
            symbols,
            "complete-for-sndata-records",
        ),
    )
    write_jsonl(REFERENCE / "functions.jsonl", functions)
    write_json(
        REFERENCE / "functions.json",
        sidecar(
            "functions.jsonl",
            "godhand.functions.v5",
            functions,
            "mechanically-promoted-unique-code-addresses",
        ),
    )
    for name, schema in [
        ("globals.json", "godhand.globals.v2"),
        ("types.json", "godhand.types.v2"),
        ("vtables.json", "godhand.vtables.v2"),
        ("files.json", "godhand.files.v2"),
    ]:
        write_json(
            REFERENCE / name,
            {
                "schema": schema,
                "provenance": provenance("analyze"),
                "entities": [],
                "status": "no-supported-evidence",
            },
        )
    write_json(
        REFERENCE / "compiler-evidence.json",
        {
            "schema": "godhand.compiler-evidence.v2",
            "provenance": provenance("analyze"),
            "claims": [],
            "fallback": "C++20",
            "status": "unknown",
        },
    )
    print(f"analyzed {len(sections)} ELF sections; preserved .sndata={bool(sndata)}")


def check(_: argparse.Namespace) -> None:
    for command in ("python3", "git", "just"):
        if shutil.which(command) is None:
            raise SystemExit(f"required command unavailable: {command}")
    tracked = subprocess.run(
        ["git", "ls-files", "--error-unmatch", "original/SLUS-21503"],
        cwd=ROOT,
        capture_output=True,
        text=True,
        check=False,
    )
    if tracked.returncode == 0:
        raise SystemExit("private target is tracked: original/SLUS-21503")
    ignored = subprocess.run(
        ["git", "check-ignore", "-q", "original/SLUS-21503"], cwd=ROOT, check=False
    )
    if ignored.returncode != 0:
        raise SystemExit("private target is not ignored: original/SLUS-21503")
    required = [
        "elf.json",
        "sections.json",
        "sndata.json",
        "symbols.json",
        "functions.json",
        "globals.json",
        "types.json",
        "vtables.json",
        "files.json",
        "compiler-evidence.json",
    ]
    record_files = ["symbols.jsonl", "functions.jsonl", "sections.jsonl"]
    missing = [p for p in required + record_files if not (REFERENCE / p).is_file()]
    if missing:
        raise SystemExit(
            "missing generated metadata; run just analyze: " + ", ".join(missing)
        )
    expected_provenance = provenance("analyze")
    expected_sections = read_elf(TARGET)[1]
    expected_sndata = next(
        (s for s in expected_sections if s["name"] == ".sndata"), None
    )
    expected_ranges = [
        (int(s["address"], 16), int(s["address"], 16) + s["size"])
        for s in expected_sections
        if s["flags"] & 4 and s["type_name"] != "SHT_NOBITS"
    ]
    expected_records = (
        parse_sndata(TARGET, expected_sndata, expected_ranges)
        if expected_sndata
        else []
    )
    expected_counts: dict[str, int] = {}
    for item in expected_records:
        if item["classification"] == "function-candidate":
            expected_counts[item["address"]] = (
                expected_counts.get(item["address"], 0) + 1
            )
    for item in expected_records:
        if (
            item["classification"] == "function-candidate"
            and expected_counts[item["address"]] != 1
        ):
            item["classification"], item["confidence"] = "ambiguous-address", "unknown"
    expected_collections = {
        "sections": expected_sections,
        "symbols": [
            {
                "id": f"target:GAME/symbol:sndata-record-{x['record']:05d}",
                "kind": "symbol-evidence",
                "name": x["name"],
                "address": x["address"],
                "record": x,
                "evidence": [x["evidence"]],
                "confidence": x["confidence"],
                "status": {
                    "identified": bool(x["name"]),
                    "decompiled": False,
                    "functional": False,
                    "matching": None,
                },
            }
            for x in expected_records
        ],
        "functions": [
            {
                "id": f"target:GAME/function:{x['address']}",
                "kind": "function",
                "name": x["name"],
                "address": x["address"],
                "record": x,
                "evidence": [x["evidence"]],
                "confidence": "strong",
                "status": {
                    "identified": True,
                    "decompiled": False,
                    "functional": False,
                    "matching": None,
                },
            }
            for x in expected_records
            if x["classification"] == "function-candidate"
        ],
    }
    all_ids: list[str] = []
    allowed_statuses = {
        "generated",
        "unknown",
        "complete-for-sndata-records",
        "mechanically-promoted-unique-code-addresses",
        "no-supported-evidence",
    }
    for name in required:
        doc = json.loads((REFERENCE / name).read_text(encoding="utf-8"))
        if not isinstance(doc, dict) or not doc.get("schema", "").startswith(
            "godhand."
        ):
            raise SystemExit(f"invalid schema in reference/{name}")
        validate_provenance(doc.get("provenance"), expected_provenance, "analyze")
        collection = name.removesuffix(".json")
        if name in {"functions.json", "symbols.json", "sections.json"}:
            exact_keys(
                doc,
                {
                    "provenance",
                    "records_file",
                    "record_count",
                    "records_sha256",
                    "schema",
                    "status",
                },
                f"reference/{name}",
            )
            expected_schema, expected_status = COLLECTION_CONTRACTS[collection]
            if doc["schema"] != expected_schema or doc["status"] != expected_status:
                raise SystemExit(
                    f"invalid collection sidecar contract in reference/{name}"
                )
        if doc.get("status") not in allowed_statuses and name not in {
            "elf.json",
            "sections.json",
            "sndata.json",
            "compiler-evidence.json",
        }:
            raise SystemExit(f"invalid status in reference/{name}")
        if name in {"functions.json", "symbols.json", "sections.json"}:
            if "entities" in doc or not isinstance(doc.get("records_file"), str):
                raise SystemExit(
                    f"record-oriented metadata must use JSONL: reference/{name}"
                )
            expected_records_file = name.removesuffix(".json") + ".jsonl"
            if doc["records_file"] != expected_records_file:
                raise SystemExit(f"invalid JSONL linkage in reference/{name}")
            if not isinstance(doc.get("record_count"), int) or doc["record_count"] < 0:
                raise SystemExit(f"invalid record count in reference/{name}")
            records_path = REFERENCE / doc["records_file"]
            if records_path.name != doc["records_file"] or not records_path.is_file():
                raise SystemExit(f"missing JSONL records for reference/{name}")
            raw_lines = records_path.read_text(encoding="utf-8").splitlines(
                keepends=True
            )
            if any(not line.endswith("\n") for line in raw_lines):
                raise SystemExit(
                    f"JSONL records must end each line with newline: {records_path}"
                )
            if (
                not isinstance(doc.get("records_sha256"), str)
                or len(doc["records_sha256"]) != 64
            ):
                raise SystemExit(f"invalid JSONL digest in reference/{name}")
            if sha256(records_path) != doc["records_sha256"]:
                raise SystemExit(f"JSONL content digest mismatch for reference/{name}")
            parsed_records = []
            for line_number, line in enumerate(raw_lines, 1):
                if not line.strip():
                    raise SystemExit(
                        f"blank JSONL record at {records_path}:{line_number}"
                    )
                try:
                    record = json.loads(line)
                except json.JSONDecodeError as exc:
                    raise SystemExit(
                        f"invalid JSONL at {records_path}:{line_number}: {exc}"
                    )
                if not isinstance(record, dict):
                    raise SystemExit(
                        f"malformed JSONL record at {records_path}:{line_number}"
                    )
                validate_record(record, collection, line_number)
                parsed_records.append(record)
                if collection != "sections":
                    all_ids.append(record["id"])
            if len(raw_lines) != doc["record_count"]:
                raise SystemExit(f"JSONL record count mismatch for reference/{name}")
            if parsed_records != expected_collections[collection]:
                raise SystemExit(
                    f"records do not match authoritative source for reference/{name}"
                )
            order_values = [
                record["index"]
                if collection == "sections"
                else record["record"]["record"]
                for record in parsed_records
            ]
            expected_order = (
                list(range(len(order_values)))
                if collection in {"sections", "symbols"}
                else sorted(order_values)
            )
            if order_values != expected_order or len(set(order_values)) != len(
                order_values
            ):
                raise SystemExit(
                    f"non-deterministic record ordering in reference/{name}"
                )
        else:
            for entity in doc.get("entities", []):
                if entity.get("id"):
                    all_ids.append(entity["id"])
    if len(all_ids) != len(set(all_ids)):
        raise SystemExit("duplicate canonical entity IDs")
    recorded = json.loads((REFERENCE / "elf.json").read_text())
    if recorded["sha256"] != sha256(TARGET):
        raise SystemExit("reference/elf.json does not match original/SLUS-21503")
    sections_doc = json.loads((REFERENCE / "sections.json").read_text())
    sections_path = REFERENCE / sections_doc["records_file"]
    sections = [
        json.loads(line)
        for line in sections_path.read_text(encoding="utf-8").splitlines()
        if line
    ]
    if len(sections) != sections_doc["record_count"]:
        raise SystemExit("sections JSONL record count mismatch")
    sndata = next((s for s in sections if s["name"] == ".sndata"), None)
    if (
        not sndata
        or sha256(REFERENCE / "sndata.bin")
        != json.loads((REFERENCE / "sndata.json").read_text())["raw_sha256"]
    ):
        raise SystemExit(".sndata raw evidence mismatch")
    manifest = ORIGINAL / "hashes.json"
    target_size = TARGET.stat().st_size
    raw_target = TARGET.read_bytes()
    for section in sections:
        if section["type_name"] == "SHT_NOBITS":
            if section["payload_present"] or section["sha256"] is not None:
                raise SystemExit(
                    f"SHT_NOBITS section has a file payload/hash: {section['name']}"
                )
        elif section["offset"] + section["size"] > target_size:
            raise SystemExit(f"section exceeds target file: {section['name']}")
        elif (
            section["sha256"]
            != hashlib.sha256(
                raw_target[section["offset"] : section["offset"] + section["size"]]
            ).hexdigest()
        ):
            raise SystemExit(f"section payload mismatch: {section['name']}")
    if (
        sndata["type_name"] == "SHT_NOBITS"
        or REFERENCE.joinpath("sndata.bin").read_bytes()
        != raw_target[sndata["offset"] : sndata["offset"] + sndata["size"]]
    ):
        raise SystemExit(".sndata section bytes do not match target")
    if not manifest.is_file() or any(
        x["path"] == "original/SLUS-21503"
        for x in json.loads(manifest.read_text())["files"]
    ):
        raise SystemExit("private target is present in the input manifest")
    if json.loads(manifest.read_text()).get("files") != input_manifest()["files"]:
        raise SystemExit("input manifest is stale or nondeterministic")
    extracted_manifest = BUILD / "extracted" / "manifest.json"
    if not extracted_manifest.is_file():
        raise SystemExit("missing mandatory extraction manifest; run just extract")
    extracted = json.loads(extracted_manifest.read_text())
    expected_extract = provenance("extract")
    validate_provenance(extracted.get("provenance"), expected_extract, "extract")
    if extracted.get("schema") != "godhand.extracted-manifest.v2" or extracted.get(
        "source_iso_sha256"
    ) != sha256(ORIGINAL / "SLUS-21503.iso"):
        raise SystemExit("stale or invalid extraction manifest provenance")
    listed = set()
    for item in extracted.get("files", []):
        if item["path"] in listed:
            raise SystemExit("duplicate extraction manifest path")
        listed.add(item["path"])
        p = extracted_manifest.parent / item["path"]
        if (
            not p.is_file()
            or p.stat().st_size != item["size"]
            or sha256(p) != item["sha256"]
        ):
            raise SystemExit(f"extracted manifest mismatch: {item['path']}")
    actual = {
        p.relative_to(extracted_manifest.parent).as_posix()
        for p in extracted_manifest.parent.rglob("*")
        if p.is_file() and p.name != "manifest.json"
    }
    if listed != actual:
        raise SystemExit("extraction manifest is not current")
    print(
        "check: schemas, provenance, input/reference consistency, .sndata, and private boundary passed"
    )


def future(ns: argparse.Namespace) -> None:
    label = ns.kind.replace("-", " ")
    suffix = f" ({ns.address})" if getattr(ns, "address", None) else ""
    print(f"UNVERIFIED: {label} is future scope{suffix}")
