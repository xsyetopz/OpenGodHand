from __future__ import annotations

import tempfile
import unittest
from pathlib import Path

from tools.godhand_tool.repository import (
    CLI_ENTRYPOINT,
    ROOT,
    candidate_identity,
    tool_sha256,
)

PACKAGE_ROOT = ROOT / "tools" / "godhand_tool"


class CandidateIdentityTests(unittest.TestCase):
    def test_ruff_cache_creation_and_mutation_are_ignored(self) -> None:
        with tempfile.TemporaryDirectory(dir=ROOT) as temporary:
            cache_names = (
                ".ruff_cache",
                "__pycache__",
                ".mypy_cache",
                ".pytest_cache",
                ".nox",
                ".tox",
                ".pyright",
                ".cache",
            )
            before = candidate_identity()
            for index, cache_name in enumerate(cache_names):
                cache = Path(temporary) / cache_name
                cache.mkdir()
                (cache / f"content_{index}").write_text("first", encoding="utf-8")
            created = candidate_identity()
            (Path(temporary) / ".ruff_cache" / "content_0").write_text(
                "second", encoding="utf-8"
            )
            mutated = candidate_identity()

        self.assertEqual(before, created)
        self.assertEqual(created, mutated)

    def test_private_original_creation_and_mutation_are_ignored(self) -> None:
        original_root = ROOT / "original"
        with tempfile.TemporaryDirectory(dir=original_root) as temporary:
            private_file = Path(temporary) / "new-private-input.bin"
            before = candidate_identity()
            private_file.write_bytes(b"first")
            created = candidate_identity()
            private_file.write_bytes(b"second")
            mutated = candidate_identity()

        self.assertEqual(before, created)
        self.assertEqual(created, mutated)


class ToolHashTests(unittest.TestCase):
    def test_current_module_change_changes_hash(self) -> None:
        module = PACKAGE_ROOT / "elf.py"
        original = module.read_bytes()
        before = tool_sha256()
        try:
            module.write_bytes(original + b"\n")
            changed = tool_sha256()
        finally:
            module.write_bytes(original)
        self.assertNotEqual(before, changed)
        self.assertEqual(before, tool_sha256())

    def test_nested_module_add_change_remove_changes_hash(self) -> None:
        before = tool_sha256()
        with tempfile.TemporaryDirectory(dir=PACKAGE_ROOT) as temporary:
            nested_module = Path(temporary) / "nested_module.py"
            nested_module.write_text("VALUE = 1\n", encoding="utf-8")
            added = tool_sha256()
            nested_module.write_text("VALUE = 2\n", encoding="utf-8")
            changed = tool_sha256()
            nested_module.unlink()
            removed = tool_sha256()

        self.assertNotEqual(before, added)
        self.assertNotEqual(added, changed)
        self.assertEqual(before, removed)

    def test_nested_ephemeral_caches_are_ignored(self) -> None:
        cache_names = (
            ".ruff_cache",
            "__pycache__",
            ".mypy_cache",
            ".pytest_cache",
            ".nox",
            ".tox",
            ".pyright",
            ".cache",
        )
        with tempfile.TemporaryDirectory(dir=PACKAGE_ROOT) as temporary:
            before = tool_sha256()
            for index, cache_name in enumerate(cache_names):
                cache = Path(temporary) / cache_name
                cache.mkdir()
                (cache / f"module_{index}.py").write_text(
                    "VALUE = 1\n", encoding="utf-8"
                )
            created = tool_sha256()
            (Path(temporary) / ".ruff_cache" / "module_0.py").write_text(
                "VALUE = 2\n", encoding="utf-8"
            )
            mutated = tool_sha256()

        self.assertEqual(before, created)
        self.assertEqual(created, mutated)

    def test_wrapper_change_changes_hash(self) -> None:
        original = CLI_ENTRYPOINT.read_bytes()
        before = tool_sha256()
        try:
            CLI_ENTRYPOINT.write_bytes(original + b"\n")
            changed = tool_sha256()
        finally:
            CLI_ENTRYPOINT.write_bytes(original)
        self.assertNotEqual(before, changed)
        self.assertEqual(before, tool_sha256())


if __name__ == "__main__":
    unittest.main()
