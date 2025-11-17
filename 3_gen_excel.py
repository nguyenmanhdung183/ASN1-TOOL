#!/usr/bin/env python3
"""
parse_e2ap_asn1.py
Extract ASN.1-like definitions from O-RAN E2AP PDF and build a multi-linked-list tree.
Outputs JSON and prints a readable tree.

PDF default: ./O-RAN_E2AP.WG3.TS.E2AP-R004-v07.00.pdf
"""

import re
import json
import sys
import yaml



import os
import glob

pdf_path = "./O-RAN_E2AP.WG3.TS.E2AP-R004-v07.00.pdf"
TARGET_TYPE = "E2setupRequest"


# ============================================================
# PDF extraction
# ============================================================

def extract_text_from_pdf(path, output_txt_file=None):
    try:
        import pdfplumber
        text_chunks = []
        with pdfplumber.open(path) as pdf:
            for p in pdf.pages:
                t = p.extract_text()
                if t:
                    text_chunks.append(t)
        full_text = "\n".join(text_chunks)

    except Exception:
        import PyPDF2
        reader = PyPDF2.PdfReader(path)
        text_chunks = []
        for p in reader.pages:
            t = p.extract_text()
            if t:
                text_chunks.append(t)
        full_text = "\n".join(text_chunks)

    # Cleanup OCR noise
    full_text = full_text.replace("\u2026", "...")
    full_text = re.sub(r"(?m)^\s*this\s*$", "", full_text, flags=re.IGNORECASE)

    if output_txt_file:
        with open(output_txt_file, "w", encoding="utf-8") as f:
            f.write(full_text)

    return full_text


# ============================================================
# Balanced brace finder
# ============================================================

def find_balanced_braces(text, start_pos):
    assert text[start_pos] == "{"
    depth = 0
    i = start_pos
    while i < len(text):
        ch = text[i]
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i + 1, text[start_pos + 1:i]
        i += 1
    return None, None


# ============================================================
# Extract ASN.1 blocks
# ============================================================

def extract_asn1_blocks(full_text):
    area = full_text
    blocks = {}

    # SEQUENCE / CHOICE / SET
    for m in re.finditer(r"([A-Za-z0-9'\-]+)\s*::=\s*(SEQUENCE|CHOICE|SET)\s*\{", area):
        name = m.group(1).strip()
        kind = m.group(2).strip().upper()
        brace_start = m.end() - 1
        end_idx, content = find_balanced_braces(area, brace_start)
        if end_idx:
            blocks[name] = {"kind": kind, "content": content.strip()}
        else:
            blocks[name] = {"kind": kind, "content": ""}

    # IE-LISTS
    for m in re.finditer(r"([A-Za-z0-9'\-]+)\s+(?:E2AP-PROTOCOL-IES|PROTOCOL-IES|ProtocolIE-List|ProtocolIE-Container)\s*::=\s*\{",
                         area, flags=re.IGNORECASE):
        name = m.group(1).strip()
        brace_start = m.end() - 1
        end_idx, content = find_balanced_braces(area, brace_start)
        if end_idx:
            blocks[name] = {"kind": "IE-LIST", "content": content.strip()}
        else:
            blocks[name] = {"kind": "IE-LIST", "content": ""}

    # ALIAS definitions
    for m in re.finditer(r"^([A-Za-z0-9'\-]+)\s*::=\s*([A-Za-z0-9 \(\)\.\-,'<>]+)$",
                         area, flags=re.MULTILINE):
        name = m.group(1).strip()
        rhs = m.group(2).strip()
        if name not in blocks:
            blocks[name] = {"kind": "ALIAS", "content": rhs}

    return blocks


# ============================================================
# IE-LIST parser
# ============================================================

def parse_ie_list_content(content):
    types = []
    i = 0
    while i < len(content):
        if content[i] == "{":
            end, inner = find_balanced_braces(content, i)
            if not end:
                break
            m = re.search(r"\bTYPE\s+([A-Za-z0-9'\-]+)", inner)
            if m:
                types.append(m.group(1).strip())
            i = end
        else:
            i += 1
    return types


# ============================================================
# Field parsing (FIXED VERSION)
# ============================================================

ELLIPSIS = {"...", "..", ".", "…", "this", "THIS"}
IDENT = re.compile(r"[A-Za-z0-9'\-]+")
FIELD_LINE_RE = re.compile(r"^\s*([A-Za-z0-9'\-]+)\s+(.+)$")


def split_fields_from_block(content):
    s = content.replace("\n", " ").replace("\r", " ")
    parts = []
    current = []
    depth_paren = 0
    depth_brace = 0

    for ch in s:
        if ch == "(":
            depth_paren += 1
        elif ch == ")":
            if depth_paren > 0:
                depth_paren -= 1
        elif ch == "{":
            depth_brace += 1
        elif ch == "}":
            if depth_brace > 0:
                depth_brace -= 1

        if ch == "," and depth_paren == 0 and depth_brace == 0:
            token = "".join(current).strip()
            if token:
                parts.append(token)
            current = []
        else:
            current.append(ch)

    last = "".join(current).strip()
    if last:
        parts.append(last)

    return [p.strip() for p in parts if p.strip()]


def parse_fields(content):
    items = split_fields_from_block(content)
    fields = []

    for it in items:
        s = it.strip()

        # Case 0: Nếu dòng chỉ là "..." → bỏ
        if s in ELLIPSIS:
            continue

        # Case 1: đúng dạng "name  type"
        m = FIELD_LINE_RE.match(s)
        if m:
            fname = m.group(1).strip()
            ftype = m.group(2).strip()

            # loại bỏ OPTIONAL/PRESENCE nhưng KHÔNG đụng tới '...'
            ftype = re.sub(
                r"\bOPTIONAL\b|\bDEFAULT\b.*$|\bPRESENCE\b.*$|\bCONSTRAINED BY.*$",
                "",
                ftype,
                flags=re.IGNORECASE
            ).strip()

            fields.append((fname, ftype))
            continue

        # Case 2: Nếu trong dòng có fieldName + "..." → vẫn phải giữ fieldName
        tokens = IDENT.findall(s)
        if len(tokens) >= 1 and "..." in s:
            fields.append((tokens[0], None))   # giữ home-eNB-ID
            continue

        # Case 3: 1 token duy nhất → field không có type
        if len(tokens) == 1:
            fields.append((tokens[0], None))
            continue

        # Case 4: fallback
        fields.append((None, s))

    return fields



# ============================================================
# Node + type classifier
# ============================================================

class Node:
    def __init__(self, name, kind="UNKNOWN", is_primitive=False):
        self.name = name
        self.kind = kind
        self.children = []
        self.is_primitive = is_primitive

    def to_dict(self):
        return {
            "name": self.name,
            "kind": self.kind,
            "is_primitive": self.is_primitive,
            "children": [c.to_dict() for c in self.children]
        }


PRIMITIVE_TOKENS = ["INTEGER", "OCTET STRING", "BIT STRING", "BOOLEAN",
                    "ENUMERATED", "NULL", "OBJECT IDENTIFIER", "UTF8String"]


def is_primitive_type(v):
    up = v.upper()
    for t in PRIMITIVE_TOKENS:
        if t in up:
            return True
    return False


# ============================================================
# Tree Builder (recursive)
# ============================================================

def build_type_tree(type_name, blocks, visited=None):
    if visited is None:
        visited = set()

    node = Node(type_name)
    if type_name in visited:
        node.kind = "RECURSIVE"
        return node

    visited.add(type_name)

    entry = blocks.get(type_name)
    if not entry:
        if is_primitive_type(type_name):
            node.kind = "PRIMITIVE"
            node.is_primitive = True
            return node

        base = re.sub(r"\(.*\)", "", type_name).strip()
        if base != type_name:
            return build_type_tree(base, blocks, visited)

        node.kind = "PRIMITIVE_OR_EXTERNAL"
        node.is_primitive = True
        return node

    kind = entry["kind"]
    content = entry.get("content", "")
    node.kind = kind

    # -------------------------
    # ALIAS
    # -------------------------
    if kind == "ALIAS":
        rhs = content.strip()
        if is_primitive_type(rhs):
            node.kind = "PRIMITIVE"
            node.is_primitive = True
            return node
        ref = rhs.split()[0]
        child = build_type_tree(ref, blocks, visited.copy())
        node.children.append(child)
        return node

    # -------------------------
    # IE-LIST
    # -------------------------
    if kind == "IE-LIST":
        types = parse_ie_list_content(content)
        for t in types:
            child = build_type_tree(t, blocks, visited.copy())
            node.children.append(child)
        return node

    # -------------------------
    # SEQUENCE / CHOICE / SET
    # -------------------------
    if kind in ("SEQUENCE", "CHOICE", "SET"):
        fields = parse_fields(content)
        for fname, ftype in fields:
            if ftype is None:
                # No type → resolve by name if exists
                if fname and fname in blocks:
                    child = build_type_tree(fname, blocks, visited.copy())
                else:
                    child = Node(fname or "UNKNOWN", "UNKNOWN")
                node.children.append(child)
                continue

            # detect SEQUENCE OF X or {{X}}
            ref = None
            m = re.search(r"\bSEQUENCE\s+OF\s+([A-Za-z0-9'\-]+)", ftype, flags=re.IGNORECASE)
            if m:
                ref = m.group(1)
            else:
                m = re.search(r"\{\s*\{\s*([A-Za-z0-9'\-]+)\s*\}\s*\}", ftype)
                if m:
                    ref = m.group(1)
                else:
                    m = re.search(r"\{\s*([A-Za-z0-9'\-]+)\s*\}", ftype)
                    if m:
                        ref = m.group(1)
                    else:
                        m = re.search(r"\bOF\b\s+([A-Za-z0-9'\-]+)", ftype)
                        if m:
                            ref = m.group(1)
                        else:
                            ref = ftype.split()[0]

            ref = re.sub(r"[,\(\)]", "", ref).strip()

            if is_primitive_type(ref) or is_primitive_type(ftype):
                child = Node(fname or ref, "PRIMITIVE", True)
            else:
                child = build_type_tree(ref, blocks, visited.copy())
                # Bạn yêu cầu: **KHÔNG đổi name → giữ type name 100%**
                # if fname:
                #     child.name = fname

            node.children.append(child)

        return node

    # -------------------------
    # fallback
    # -------------------------
    node.kind = "UNKNOWN"
    return node


# ============================================================
# Print tree
# ============================================================

def pretty_print(node, indent=0):
    pfx = " " * indent
    print(f"{pfx}{node.name}")
    for c in node.children:
        pretty_print(c, indent + 4)


# ======================== YAML EXPORT ===========================

# def to_yaml_dict(node):
#     return {
#         node.name: {
#             "children": [to_yaml_dict(c) for c in node.children]
#         }
#     }

def to_yaml_dict(node):
    if not node.children:
        return {node.name: {}}
    return {
        node.name: {
            c.name: to_yaml_dict(c)[c.name] for c in node.children
        }
    }


# ============================================================
# MAIN
# ============================================================

def main(ppath, target):
    print("Reading PDF text…")
    #text = extract_text_from_pdf(ppath, "a.txt")
    text = extract_text_from_pdf(ppath)
    print("Extracting ASN.1 blocks…")
    blocks = extract_asn1_blocks(text)
    print(f"Found {len(blocks)} ASN.1 types.")

    # case-insensitive resolve
    real_target = next((k for k in blocks if k.lower() == target.lower()), target)

    print(f"Building tree for: {real_target}")
    tree = build_type_tree(real_target, blocks)

    print("\n--- TREE ---")
    pretty_print(tree)



if __name__ == "__main__":
    tp = TARGET_TYPE
    pp = pdf_path
    if len(sys.argv) >= 2:
        tp = sys.argv[1]
    if len(sys.argv) >= 3:
        pp = sys.argv[2]
    main(pp, tp)


