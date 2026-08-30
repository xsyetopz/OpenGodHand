"""ELF section-table and SNR2 evidence extraction."""

from __future__ import annotations

import hashlib
import pathlib
import struct
from typing import Any

from .repository import ROOT, provenance, sha256


def read_elf(
    path: pathlib.Path,
) -> tuple[dict[str, Any], list[dict[str, Any]], list[dict[str, Any]]]:
    data = path.read_bytes()
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        raise ValueError("expected a 32-bit little-endian ELF")
    e = struct.unpack_from("<HHIIIIIHHHHHH", data, 16)
    (
        _,
        machine,
        version,
        entry,
        phoff,
        shoff,
        flags,
        _ehsize,
        _phentsize,
        phnum,
        sph,
        shnum,
        shstr,
    ) = e
    elf = {
        "schema": "godhand.elf.v2",
        "provenance": provenance("analyze"),
        "path": str(path.relative_to(ROOT)),
        "sha256": sha256(path),
        "raw_header_hex": data[:52].hex(),
        "class": "ELF32",
        "endianness": "little",
        "machine": machine,
        "version": version,
        "entry": f"0x{entry:08x}",
        "flags": f"0x{flags:08x}",
        "header": {
            "type": e[0],
            "machine": machine,
            "version": version,
            "entry": entry,
            "program_header_offset": phoff,
            "section_header_offset": shoff,
            "flags": flags,
            "header_size": e[7],
            "program_header_size": e[8],
            "program_header_count": phnum,
            "section_header_size": sph,
            "section_header_count": shnum,
            "section_name_index": shstr,
        },
    }
    programs = []
    for i in range(phnum):
        row = struct.unpack_from("<IIIIIIII", data, phoff + i * e[8])
        programs.append(
            {
                "index": i,
                "type": row[0],
                "offset": row[1],
                "virtual_address": f"0x{row[2]:08x}",
                "physical_address": f"0x{row[3]:08x}",
                "file_size": row[4],
                "memory_size": row[5],
                "flags": row[6],
                "alignment": row[7],
                "raw_hex": data[phoff + i * e[8] : phoff + (i + 1) * e[8]].hex(),
            }
        )
    sections: list[dict[str, Any]] = []
    # Section names are resolved from .shstrtab; unknown names are retained as offsets.
    sh = [
        struct.unpack_from("<IIIIIIIIII", data, shoff + i * sph) for i in range(shnum)
    ]
    names = data[sh[shstr][4] : sh[shstr][4] + sh[shstr][5]]
    for i, row in enumerate(sh):
        name_off, typ, flags_, addr, off, size, link, info, align, entsize = row
        end = names.find(b"\0", name_off)
        name = (
            names[name_off:end].decode("ascii", "replace")
            if end >= 0
            else f"<name+0x{name_off:x}>"
        )
        payload = b"" if typ == 8 else data[off : off + size]
        sections.append(
            {
                "index": i,
                "name": name,
                "type": typ,
                "type_name": "SHT_NOBITS" if typ == 8 else str(typ),
                "flags": flags_,
                "address": f"0x{addr:08x}",
                "offset": off,
                "size": size,
                "link": link,
                "info": info,
                "alignment": align,
                "entry_size": entsize,
                "payload_present": typ != 8,
                "sha256": hashlib.sha256(payload).hexdigest() if typ != 8 else None,
                "raw_header_hex": data[shoff + i * sph : shoff + (i + 1) * sph].hex(),
            }
        )
    return elf, sections, programs


def parse_sndata(
    path: pathlib.Path,
    section: dict[str, Any],
    executable_ranges: list[tuple[int, int]],
) -> list[dict[str, Any]]:
    """Decode the documented SNR2 function table; reject malformed pointers, never guess."""
    data = path.read_bytes()
    base = section["offset"]
    end = base + section["size"]
    raw = data[base:end]
    if raw[:4] != b"SNR2":
        return []
    memdiff = int(section["address"], 16) - base
    count = struct.unpack_from("<I", raw, 16)[0]
    table_addr = struct.unpack_from("<I", raw, 12)[0]
    table = table_addr - memdiff + 12
    if table < base or table + min(count, 1) * 12 > end:
        return []
    out = []
    for i in range(count):
        record = table + i * 12
        if record + 12 > end:
            raise ValueError(f"truncated .sndata record {i} at offset {record - base}")
        word0, word1, word2 = struct.unpack_from("<III", data, record)
        name_addr, function_addr = word0, word1
        name_off = name_addr - memdiff
        name = None
        if base <= name_off < end:
            nul = data.find(b"\0", name_off, end)
            if nul >= 0:
                name = data[name_off:nul].decode("utf-8", "replace") or None
        address = f"0x{function_addr:08x}"
        in_code = any(
            start <= function_addr < finish for start, finish in executable_ranges
        )
        out.append(
            {
                "record": i,
                "raw_offset": record - base,
                "raw_hex": data[record : record + 12].hex(),
                "word0": f"0x{word0:08x}",
                "word1": f"0x{word1:08x}",
                "word2": f"0x{word2:08x}",
                "word2_meaning": "unknown",
                "name": name,
                "address": address,
                "classification": "function-candidate"
                if name and function_addr and in_code
                else "symbol-evidence",
                "confidence": "strong"
                if name and function_addr and in_code
                else "unknown",
                "evidence": {
                    "kind": "sndata",
                    "artifact": "original/SLUS-21503",
                    "record": i,
                    "section": ".sndata",
                    "offset": record - base,
                },
            }
        )
    return out
