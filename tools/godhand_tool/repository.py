"""Paths, hashing, provenance, and private-input inventory."""

from __future__ import annotations

import hashlib
import pathlib
import subprocess
import sys
from typing import Any

ROOT = pathlib.Path(__file__).resolve().parents[2]
ORIGINAL = ROOT / "original"
REFERENCE = ROOT / "reference"
BUILD = ROOT / "build"
TARGET = ORIGINAL / "SLUS-21503"
CONFIG = ROOT / "config" / "project.toml"
CLI_ENTRYPOINT = ROOT / "tools" / "godhand.py"
TOOL_VERSION = "godhand-tools/1"
PROVENANCE_STATUS = "generated"
EXCLUDED_CANDIDATE_DIRS = {".git", ".codegraph", "build", "reference"}
PRIVATE_INPUT_DIRS = {"original"}
EPHEMERAL_DIR_NAMES = {
    ".cache",
    ".coverage",
    ".eggs",
    ".hypothesis",
    ".mypy_cache",
    ".nox",
    ".pytest_cache",
    ".pyright",
    ".ruff_cache",
    ".tox",
    ".venv",
    "__pycache__",
}
REQUIRED_PROVENANCE = (
    "repository_identity",
    "repository_commit",
    "repository_base_identity",
    "candidate_identity",
    "tool",
    "tool_version",
    "tool_sha256",
    "config_sha256",
    "python",
    "command",
    "status",
)


def sha256(path: pathlib.Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def repository_identity() -> str:
    for line in CONFIG.read_text(encoding="utf-8").splitlines():
        if line.strip().startswith("identity"):
            return line.split("=", 1)[1].strip().strip('"')
    raise RuntimeError("config/project.toml has no repository.identity")


def git_identity(*args: str) -> str:
    try:
        return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()
    except (OSError, subprocess.CalledProcessError):
        return "unknown"


def candidate_files() -> list[pathlib.Path]:
    files = []
    for path in sorted(ROOT.rglob("*")):
        relative_parts = path.relative_to(ROOT).parts
        if not path.is_file() or any(
            part in EXCLUDED_CANDIDATE_DIRS
            or part in PRIVATE_INPUT_DIRS
            or part in EPHEMERAL_DIR_NAMES
            or part.endswith(("_cache", ".egg-info"))
            for part in relative_parts
        ):
            continue
        if (
            path.name in {"SLUS-21503", "SLUS-21503.iso", "hashes.json"}
            or "original/extracted" in path.relative_to(ROOT).as_posix()
            or path.suffix in {".pyc", ".pyo"}
        ):
            continue
        files.append(path)
    return files


def candidate_identity() -> str:
    digest = hashlib.sha256()
    for path in candidate_files():
        rel = path.relative_to(ROOT).as_posix().encode()
        digest.update(len(rel).to_bytes(4, "big"))
        digest.update(rel)
        digest.update(bytes.fromhex(sha256(path)))
    return digest.hexdigest()


def tool_files() -> tuple[pathlib.Path, ...]:
    """Return the complete owned executable implementation in stable order."""
    package_root = ROOT / "tools" / "godhand_tool"
    package_files = [
        path
        for path in package_root.rglob("*.py")
        if path.is_file()
        and not any(
            part in EPHEMERAL_DIR_NAMES or part.endswith(("_cache", ".egg-info"))
            for part in path.relative_to(ROOT).parts
        )
    ]
    return tuple(
        sorted(
            (CLI_ENTRYPOINT, *package_files),
            key=lambda item: item.relative_to(ROOT).as_posix(),
        )
    )


def tool_sha256() -> str:
    """Hash paths and contents so additions, removals, and edits are visible."""
    digest = hashlib.sha256()
    for path in tool_files():
        relative = path.relative_to(ROOT).as_posix().encode("utf-8")
        content = path.read_bytes()
        digest.update(b"godhand-tool-file-v1\0")
        digest.update(len(relative).to_bytes(8, "big"))
        digest.update(relative)
        digest.update(len(content).to_bytes(8, "big"))
        digest.update(content)
    return digest.hexdigest()


def provenance(command: str) -> dict[str, Any]:
    try:
        commit = git_identity("rev-parse", "HEAD")
        base = git_identity(
            "rev-list", "--max-parents=0", "--reverse", "HEAD"
        ).splitlines()[0]
    except (OSError, subprocess.CalledProcessError, IndexError):
        commit, base = "unknown", "unknown"
    return {
        "repository_identity": repository_identity(),
        "repository_commit": commit,
        "repository_base_identity": base,
        "candidate_identity": candidate_identity(),
        "tool": "godhand-tools",
        "tool_version": TOOL_VERSION,
        "tool_sha256": tool_sha256(),
        "python": sys.version.split()[0],
        "config_sha256": sha256(CONFIG) if CONFIG.exists() else "missing",
        "command": command,
        "status": PROVENANCE_STATUS,
    }


def input_manifest() -> dict[str, Any]:
    files = []
    for path in sorted(ORIGINAL.rglob("*")):
        if (
            path.is_file()
            and path.name != "hashes.json"
            and path.name != "SLUS-21503"
            and "extracted" not in path.parts
        ):
            files.append(
                {
                    "path": path.relative_to(ROOT).as_posix(),
                    "sha256": sha256(path),
                    "size": path.stat().st_size,
                }
            )
    return {"schema": "godhand.input-manifest.v1", "files": files}
