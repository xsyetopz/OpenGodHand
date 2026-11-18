"""Data-side helpers for tools/linkgen.py: constant `.rodata` sections that
replace runs of original rodata units, and positional symbol names."""

from __future__ import annotations

import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fncmp  # noqa: E402


def rodata_span(obj: Path, name: str, raw: bytes, units: list[tuple[int, int]]) -> list[int] | None:
    """Return the original rodata units (addresses, ascending) that the object's
    `name` section reproduces byte for byte, or None.

    Only a section without relocations of its own qualifies (floats, strings,
    constant tables), so its bytes are final before linking. They must equal
    the original bytes at a unit boundary and end on one, and be aligned to
    the section's alignment; linkgen places the section at the first unit and
    drops the covered ones."""
    with obj.open("rb") as f:
        elf = ELFFile(f)
        sec = elf.get_section_by_name(name)
        if sec is None or elf.get_section_by_name(".rel" + name) or elf.get_section_by_name(".rela" + name):
            return None
        data = sec.data()
        align = max(sec["sh_addralign"], 1)
    if not data:
        return None
    ends = {v + sz for v, sz in units}
    for n, (uv, _sz) in enumerate(units):
        if uv % align or uv + len(data) not in ends:
            continue
        if raw[uv + fncmp.TEXT_OFF : uv + fncmp.TEXT_OFF + len(data)] == data:
            return [v for v, _s in units[n:] if v < uv + len(data)]
    return None


def positional_address(name: str, unit_at: dict[int, str]) -> int | None:
    """Address of an original unit that source code names by position
    (`func_<addr>` for text, `D_<addr>` for data) while the symbol table gives
    it another name, so the link must define the positional name."""
    m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", name)
    if m and int(m[1], 16) in unit_at:
        return int(m[1], 16)
    return None


def matches(obj: Path, vram: int, sym: str, span: int, raw: bytes) -> bool:
    try:
        got, relocs, _names = fncmp.compiled(obj, sym)
    except (SystemExit, FileNotFoundError):
        return False
    off = vram + fncmp.TEXT_OFF
    want = raw[off : off + span]
    # The unit span includes alignment padding after the function body.
    if len(got) > len(want) or want[len(got) :].strip(b"\0"):
        return False
    for i in range(0, len(got), 4):
        mask = fncmp.MASK.get(relocs.get(i), 0xFFFFFFFF)
        g, w = struct.unpack_from("<I", got, i)[0], struct.unpack_from("<I", want, i)[0]
        if (g ^ w) & mask:
            return False
    return True


def find_symbol(obj: Path, vram: int, sym: str, span: int, raw: bytes, taken: set[str]) -> str:
    """Return the compiled symbol for the unit at `vram`: `sym` when the object
    has its section, otherwise the one other function section whose bytes equal
    the original (a member function the compiler named by mangling, such as a
    macro-generated `operator>>`). Identical bodies are taken in symbol order;
    falls back to `sym` when none matches."""
    if not obj.exists():
        return sym
    with obj.open("rb") as f:
        elf = ELFFile(f)
        if elf.get_section_by_name(f".text.{sym}") is not None:
            return sym
        found = [
            s.name for s in elf.get_section_by_name(".symtab").iter_symbols()
            if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int)
            and s.name not in taken and elf.get_section(s["st_shndx"]).name == f".text.{s.name}"
        ]
    hits = [n for n in found if matches(obj, vram, n, span, raw)]
    return hits[0] if hits else sym


def derived_addresses(obj: Path, sym: str, vram: int, raw: bytes, skip: set[str]) -> dict[str, int]:
    """Original addresses of the named symbols that `sym` calls or addresses,
    read from the original instructions at the compiled relocation sites
    (`jal` targets, `lui`/`addiu`/load pairs), less the addend the compiled
    word carries. A name whose sites disagree, or that is in `skip`, is left out.
    Defining such a name at that address in the link lets a function that
    references data or code of the asm units link without compiled copies."""
    try:
        got, relocs, names = fncmp.compiled(obj, sym)
    except (SystemExit, FileNotFoundError):
        return {}
    want = raw[vram + fncmp.TEXT_OFF : vram + fncmp.TEXT_OFF + len(got)]
    his: dict[str, list[int]] = {}
    found: dict[str, set[int]] = {}

    def word(buf: bytes, off: int) -> int:
        return struct.unpack_from("<I", buf, off)[0]

    for off, kind in sorted(relocs.items()):
        name = names.get(off)
        if name is None or name in skip or off + 4 > len(want):
            continue
        if kind == 4:  # R_MIPS_26
            found.setdefault(name, set()).add((((word(want, off) & 0x3FFFFFF) - (word(got, off) & 0x3FFFFFF)) << 2) | (vram & 0xF0000000))
        elif kind == 5:  # R_MIPS_HI16
            his.setdefault(name, []).append(((word(want, off) & 0xFFFF) - (word(got, off) & 0xFFFF)) & 0xFFFF)
        elif kind == 6 and name in his:  # R_MIPS_LO16 after its HI16
            lo = (word(want, off) & 0xFFFF) - (word(got, off) & 0xFFFF)
            found.setdefault(name, set()).add(((his[name][-1] << 16) + (lo if lo < 0x8000 else lo - 0x10000)) & 0xFFFFFFFF)
    return {n: next(iter(a)) for n, a in found.items() if len(a) == 1}


def jump_table(obj: Path, sym: str, vram: int, span: int, raw: bytes, units: list[tuple[int, int]]) -> tuple[int, str, bytes | None, list[int], set[str]] | None:
    """Return (first unit address, input section, trimmed bytes or None, covered
    unit addresses, other function sections the table points at) when `sym`'s only data reference is one `.rodata` section
    made of jump tables, possibly beside strings, over consecutive original
    units.

    The section must be aligned to its first unit and end inside the last
    covered unit, with only zero padding after it. Each word relocated against `.text.<sym>` (a
    section-relative offset) plus `vram` must equal the original table word;
    words relocated against named symbols (vtable slots) are the linker's; other words must equal the original bytes. The
    original bytes between the section's end and the unit's end must be zero.
    Anything else makes the section differ and returns None, so the function
    stays gated as before."""
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        names = set()
        for rs in elf.iter_sections():
            if not isinstance(rs, RelocationSection) or elf.get_section(rs["sh_info"]).name != f".text.{sym}":
                continue
            for r in rs.iter_relocations():
                t = symtab.get_symbol(r["r_info_sym"])
                if isinstance(t["st_shndx"], int):
                    n = elf.get_section(t["st_shndx"]).name
                    if t["st_info"]["type"] == "STT_SECTION" and n.startswith(".rodata"):
                        names.add(n)
        if len(names) != 1:
            return None
        sec = elf.get_section_by_name(names.pop())
        data, align = sec.data(), max(sec["sh_addralign"], 1)
        rel = elf.get_section_by_name(f".rel{sec.name}")
        entries, foreign, deps = set(), set(), set()
        for r in rel.iter_relocations() if rel else ():
            t = symtab.get_symbol(r["r_info_sym"])
            other = elf.get_section(t["st_shndx"]).name if t["st_info"]["type"] == "STT_SECTION" else ""
            if other and not other.startswith(".text."):
                return None  # a pointer into compiled data has no original address
            if other and other != f".text.{sym}":
                deps.add(other)  # a vtable slot: valid only while that function is linked
            (entries if other == f".text.{sym}" else foreign).add(r["r_offset"])
    # The assembler pads the section to its alignment; zero bytes after the
    # last real byte are not content.
    used = len(data.rstrip(b"\0")) + 3 & ~3
    if not entries or used == 0 or max(entries | foreign) >= used:
        return None
    word = lambda b, i: struct.unpack_from("<I", b, i)[0]
    for n, (uv, _size) in enumerate(units):
        if uv % align:
            continue
        end = next((v + s for v, s in units[n:] if v + s >= uv + used), None)
        if end is None:
            continue
        cut = min(len(data), end - uv)
        base = uv + fncmp.TEXT_OFF
        want = raw[base : base + max(end - uv, len(data))]
        if cut < used or any(want[cut:end - uv]) or any(data[cut:]):
            continue
        if all(
            (word(data, i) + vram == word(want, i) and 0 <= word(data, i) < span)
            if i in entries else i in foreign or data[i : i + 4] == want[i : i + 4]
            for i in range(0, cut - cut % 4, 4)
        ) and data[cut - cut % 4 : cut] == want[cut - cut % 4 : cut]:
            covered = [v for v, _s in units[n:] if v < end]
            return uv, sec.name, data[:cut] if cut < len(data) else None, covered, deps
    return None
