"""Lower the C++ spellings in a permuter base.c to C that pycparser parses.

The lowering touches base.c only. The candidates the permuter writes are
compiled as C++ by compile.sh, which undoes every rewrite below, so the code
generator sees the original constructs and scores stay comparable.

  struct/class names   C needs `struct` before a tag; C++ does not. Each tag
                       gets `typedef struct Tag Tag;` first (legal C++ too),
                       `class` becomes `struct`, access labels are dropped
                       (layout and codegen do not depend on them).
  enum tags            `typedef enum Tag Tag;` follows each definition.
  bool                 becomes CXX_bool, declared `typedef int CXX_bool;`;
                       compile.sh deletes that line and defines CXX_bool as bool.
  *_cast<T>(x)         becomes the C cast ((T)(x)), same conversion for the
                       arithmetic and pointer casts the drafts use.

Not lowered (the draft stays unpermutable): references, member functions,
constructors, operator overloads, default arguments, inheritance.
"""

from __future__ import annotations

import re

BOOL_TYPEDEF = "typedef int CXX_bool;"
TAG = re.compile(r"\b(?:struct|class|union)\s+([A-Za-z_]\w*)\s*(?=[{;])")
CAST = re.compile(r"\b(?:static|reinterpret|const)_cast\s*<([^<>]*(?:<[^<>]*>[^<>]*)*)>\s*\(")


def _casts(text: str) -> str:
    """Rewrite X_cast<T>(e) as ((T)(e)), balancing the parentheses of e."""
    while m := CAST.search(text):
        depth, i = 1, m.end()
        while i < len(text) and depth:
            depth += {"(": 1, ")": -1}.get(text[i], 0)
            i += 1
        text = f"{text[:m.start()]}(({m.group(1).strip()})({text[m.end():i - 1]})){text[i:]}"
    return text


def lower(text: str) -> str:
    """base.c text with the common C++-only spellings rewritten as C."""
    text = _casts(text)
    text = re.sub(r"^\s*(?:public|private|protected)\s*:\s*$", "", text, flags=re.M)
    text = re.sub(r"\bclass\b(?=\s+\w+\s*[{;])", "struct", text)
    text = re.sub(r"\benum\s+([A-Za-z_]\w*)\s*\{[^{}]*\}\s*;", lambda m: f"{m.group(0)}\ntypedef enum {m.group(1)} {m.group(1)};", text)
    head = []
    for tag in dict.fromkeys(TAG.findall(text)):
        if not re.search(rf"\btypedef\b[^;{{}}]*\b{tag}\s*;", text):
            head.append(f"typedef struct {tag} {tag};")
    if re.search(r"\bbool\b", text):
        text = re.sub(r"\bbool\b", "CXX_bool", text)
        head.append(BOOL_TYPEDEF)
    return "\n".join(head) + "\n" + text if head else text
