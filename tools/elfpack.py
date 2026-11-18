#!/usr/bin/env python3
"""Reproduce the SN Systems ps2link executable container.

GNU ld places code and data at the correct addresses, but SN's linker writes a
different container: its own section-header order, file offsets, non-loaded
VU overlay sections, and a `.reginfo` stored after the load image. This tool
captures that container as a layout (`describe`), pulls the non-loaded
sections out of a user-supplied executable (`assets`), and writes the final
executable from a GNU ld link plus those inputs (`pack`).
"""

from __future__ import annotations

import argparse
import io
import json
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

SHT_NOBITS = 8
SHF_ALLOC = 2


def _asset_name(name: str) -> str:
    return name.strip(".").replace("..", ".") + ".bin"


def cmd_describe(args) -> int:
    raw = args.elf.read_bytes()
    elf = ELFFile(io.BytesIO(raw))
    eh = elf.header
    layout = {
        "ehdr": {k: eh[k] for k in ("e_entry", "e_flags", "e_shoff", "e_shstrndx")},
        "phdrs": [dict(seg.header) for seg in elf.iter_segments()],
        "file_size": len(raw),
        "sections": [],
    }
    for ph in layout["phdrs"]:
        ph["p_type"] = 1
    for i, sec in enumerate(elf.iter_sections()):
        h = sec.header
        sh_type = struct.unpack_from("<I", raw, eh["e_shoff"] + i * 40 + 4)[0]
        ent = {
            "name": sec.name,
            "type": sh_type,
            "flags": h["sh_flags"],
            "addr": h["sh_addr"],
            "offset": h["sh_offset"],
            "size": h["sh_size"],
            "link": h["sh_link"],
            "info": h["sh_info"],
            "align": h["sh_addralign"],
            "entsize": h["sh_entsize"],
        }
        if i == 0:
            ent["source"] = "null"
        elif sec.name == ".shstrtab":
            ent["source"] = "shstrtab"
        elif sh_type == SHT_NOBITS or h["sh_size"] == 0:
            ent["source"] = "none"
        elif h["sh_flags"] & SHF_ALLOC and h["sh_addr"]:
            ent["source"] = "link"
        else:
            ent["source"] = "asset:" + _asset_name(sec.name)
        layout["sections"].append(ent)
    args.out.write_text(json.dumps(layout, indent=1) + "\n")
    return 0


def cmd_assets(args) -> int:
    layout = json.loads(args.layout.read_text())
    args.out.mkdir(parents=True, exist_ok=True)
    with args.elf.open("rb") as f:
        elf = ELFFile(f)
        for ent in layout["sections"]:
            if ent["source"].startswith("asset:"):
                data = elf.get_section_by_name(ent["name"]).data()
                (args.out / ent["source"][6:]).write_bytes(data)
    return 0


def _shstrtab(names: list[str]) -> tuple[bytes, dict[str, int]]:
    blob = bytearray(b"\0")
    offs = {"": 0}
    # SN's linker interned the string-table names first, then strips .symtab and .strtab.
    for n in [".symtab", ".strtab", ".shstrtab", *names]:
        if n and n not in offs:
            offs[n] = len(blob)
            blob += n.encode() + b"\0"
    return bytes(blob), offs


def cmd_pack(args) -> int:
    layout = json.loads(args.layout.read_text())
    secs = layout["sections"]
    out = bytearray(layout["file_size"])

    with args.linked.open("rb") as f:
        linked = ELFFile(f)
        payload: dict[str, bytes] = {}
        for ent in secs:
            src = ent["source"]
            if src == "link":
                s = linked.get_section_by_name(ent["name"])
                if s is None:
                    raise SystemExit(f"{args.linked}: missing section {ent['name']}")
                if s["sh_addr"] != ent["addr"]:
                    raise SystemExit(f"{ent['name']}: linked at {s['sh_addr']:#x}, expected {ent['addr']:#x}")
                data = s.data()
                # GNU ld rounds section ends up to input alignment; the trailing fill must be zero.
                if len(data) < ent["size"] or any(data[ent["size"] :]):
                    raise SystemExit(f"{ent['name']}: linked size {len(data):#x}, expected {ent['size']:#x}")
                payload[ent["name"]] = data[: ent["size"]]
            elif src.startswith("asset:"):
                payload[ent["name"]] = (args.assets / src[6:]).read_bytes()
        for ent in secs:
            if ent["type"] == SHT_NOBITS:
                s = linked.get_section_by_name(ent["name"])
                if s is not None and s["sh_addr"] != ent["addr"]:
                    raise SystemExit(f"{ent['name']}: linked at {s['sh_addr']:#x}, expected {ent['addr']:#x}")

    strtab, name_off = _shstrtab([e["name"] for e in secs])
    payload[".shstrtab"] = strtab

    for ent in secs:
        data = payload.get(ent["name"])
        if data is None:
            continue
        if ent["source"] != "link" and len(data) != ent["size"]:
            raise SystemExit(f"{ent['name']}: size {len(data):#x}, expected {ent['size']:#x}")
        out[ent["offset"] : ent["offset"] + len(data)] = data

    eh = layout["ehdr"]
    ident = b"\x7fELF\x01\x01\x01" + bytes(9)
    struct.pack_into(
        "<16sHHIIIIIHHHHHH", out, 0, ident, 2, 8, 1, eh["e_entry"], 52, eh["e_shoff"], eh["e_flags"],
        52, 32, len(layout["phdrs"]), 40, len(secs), eh["e_shstrndx"],
    )
    for i, ph in enumerate(layout["phdrs"]):
        struct.pack_into(
            "<8I", out, 52 + i * 32, ph["p_type"], ph["p_offset"], ph["p_vaddr"], ph["p_paddr"],
            ph["p_filesz"], ph["p_memsz"], ph["p_flags"], ph["p_align"],
        )
    for i, ent in enumerate(secs):
        struct.pack_into(
            "<10I", out, eh["e_shoff"] + i * 40, name_off[ent["name"]], ent["type"], ent["flags"], ent["addr"],
            ent["offset"], ent["size"], ent["link"], ent["info"], ent["align"], ent["entsize"],
        )
    args.out.write_bytes(out)
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(required=True)
    p = sub.add_parser("describe", help="write the container layout of an executable")
    p.add_argument("elf", type=Path)
    p.add_argument("out", type=Path)
    p.set_defaults(fn=cmd_describe)
    p = sub.add_parser("assets", help="extract non-loaded sections named by the layout")
    p.add_argument("layout", type=Path)
    p.add_argument("elf", type=Path)
    p.add_argument("out", type=Path)
    p.set_defaults(fn=cmd_assets)
    p = sub.add_parser("pack", help="write the final executable")
    p.add_argument("layout", type=Path)
    p.add_argument("linked", type=Path)
    p.add_argument("assets", type=Path)
    p.add_argument("out", type=Path)
    p.set_defaults(fn=cmd_pack)
    args = ap.parse_args()
    return args.fn(args)


if __name__ == "__main__":
    sys.exit(main())
