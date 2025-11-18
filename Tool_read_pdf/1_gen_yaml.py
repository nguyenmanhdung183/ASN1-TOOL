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

# Danh sách phần mở rộng cần xóa
extensions = ["*.txt", "*.yaml", "*.json"]

for ext in extensions:
    for file in glob.glob(ext):
        try:
            os.remove(file)
            print(f"Deleted: {file}")
        except Exception as e:
            print(f"Error deleting {file}: {e}")



pdf_path = "./O-RAN_E2AP.WG3.TS.E2AP-R004-v07.00.pdf"
TARGET_TYPE = "E2setupRequest"


def extract_ref_from_type(ftype):
    ftype = ftype.strip()
    # {{X}}
    m = re.search(r"\{\s*\{\s*([A-Za-z0-9'\-]+)\s*\}\s*\}", ftype)
    if m: return m.group(1)
    # {X}
    m = re.search(r"\{\s*([A-Za-z0-9'\-]+)\s*\}", ftype)
    if m: return m.group(1)
    # ProtocolIE-SingleContainer { {X} }
    m = re.search(r"SingleContainer\s*\{[^}]*\{\s*([A-Za-z0-9'\-]+)\s*\}[^}]*\}", ftype, re.I)
    if m: return m.group(1)
    # SEQUENCE OF X
    m = re.search(r"SEQUENCE\s+OF\s+([A-Za-z0-9'\-]+)", ftype, re.I)
    if m: return m.group(1)
    # OF X
    m = re.search(r"OF\s+([A-Za-z0-9'\-]+)", ftype, re.I)
    if m: return m.group(1)
    return ftype.split()[0]

def extract_sequence_of_singlecontainer_by_lines(lines, blocks):
    """
    Duyệt từng dòng, nếu thấy:
    - Dòng hiện tại: có 'List' và 'SEQUENCE'
    - Dòng hiện tại hoặc dòng sau: có 'SingleContainer' và '{{X}}'
    → Trích xuất name và inner_type
    """
    for i in range(len(lines) - 1):
        line1 = lines[i].strip()
        line2 = lines[i + 1].strip() if i + 1 < len(lines) else ""

        # Kết hợp 2 dòng để tìm
        combined = (line1 + " " + line2).replace("\n", " ")

        # Tìm name ::= SEQUENCE ... List
        m_name = re.search(r"([A-Za-z0-9'\-]+)\s*::=\s*SEQUENCE", combined)
        if not m_name:
            continue
        name = m_name.group(1).strip()

        if "List" not in name:
            continue

        # Tìm {{X}} trong 2 dòng
        m_inner = re.search(r"\{\s*\{\s*([A-Za-z0-9'\-]+)\s*\}\s*\}", line1 + line2)
        if not m_inner:
            continue
        inner_type = m_inner.group(1).strip()

        # Phải có SingleContainer trong 1 trong 2 dòng
        if not (re.search(r"SingleContainer", line1, re.I) or re.search(r"SingleContainer", line2, re.I)):
            continue

        # Đã đủ điều kiện → lưu
        blocks[name] = {
            "kind": "SEQUENCE-OF-SINGLECONTAINER",
            "content": inner_type
        }
        print(f"[DEBUG] Found via lines: {name} → {inner_type}")

# ============================================================
# PDF extraction
# ============================================================


def preprocess_pdf_text(text):
    """
    Gộp các dòng bị cắt tên type do PDF xuống dòng:
    E2nodeComponentConfigAddition-
    ItemIEs E2AP-PROTOCOL-IES ::= {
    → E2nodeComponentConfigAddition-ItemIEs E2AP-PROTOCOL-IES ::= {
    """
    lines = text.splitlines()
    merged = []
    buffer = ""

    for line in lines:
        stripped = line.strip()
        if not stripped:
            if buffer:
                merged.append(buffer)
                buffer = ""
            continue

        # Nếu buffer kết thúc bằng '-' và dòng hiện tại bắt đầu bằng chữ → gộp
        if buffer.endswith("-") and re.match(r"^[A-Za-z0-9'\-]", stripped):
            buffer = buffer + stripped  # 
        else:
            if buffer:
                merged.append(buffer)
            buffer = stripped

    if buffer:
        merged.append(buffer)

    return "\n".join(merged)

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
    """
    FIXED version:
    - Bắt SEQUENCE { ... }
    - Bắt CHOICE { ... }
    - Bắt SET { ... }
    - Bắt SEQUENCE (SIZE..) OF <Type>
    - Bắt SingleContainer {{Type}}
    - Giải quyết case xuống dòng PDF
    """
    area = full_text
    blocks = {}
    lines = full_text.splitlines()
    # ============================================================
    # NORMAL SEQUENCE / CHOICE / SET (có dấu { ... })
    # ============================================================

    seq_pattern = re.compile(
        r"([A-Za-z0-9'\-]+)\s*::=\s*(SEQUENCE|CHOICE|SET)\s*\{",
        flags=re.MULTILINE
    )

    for m in seq_pattern.finditer(area):
        name = m.group(1).strip()
        kind = m.group(2).strip().upper()
        brace_start = m.end() - 1  # vị trí dấu '{'

        end_idx, content = find_balanced_braces(area, brace_start)
        if end_idx:
            blocks[name] = {"kind": kind, "content": content.strip()}
        else:
            blocks[name] = {"kind": kind, "content": ""}

    # # ==============================================
    # # SEQUENCE (SIZE...) OF ProtocolIE-SingleContainer { {X} }  ← BẤT CHẤP XUỐNG DÒNG, SPACE, TAB, -
    # # ==============================================
    # seq_size_of_container_pattern = re.compile(
    #     r"([A-Za-z0-9'\-]+)\s*::=\s*"
    #     r"SEQUENCE\s*\([^)]*\)\s*OF\s*"
    #     r"(?:ProtocolIE[-\s]*SingleContainer|SingleContainer)\s*"
    #     r"\{[^}]*\{\s*([A-Za-z0-9'\-]+)\s*\}[^}]*\}",
    #     flags=re.MULTILINE | re.DOTALL
    # )
    # for m in seq_size_of_container_pattern.finditer(area):
    #     name = m.group(1).strip()
    #     inner_type = m.group(2).strip()
    #     blocks[name] = {
    #         "kind": "SEQUENCE-OF-SINGLECONTAINER",
    #         "content": inner_type
    #     }
    
    
    
    # 1. XỬ LÝ SEQUENCE-OF-SingleContainer THEO DÒNG (Ý TƯỞNG CỦA BẠN)
    extract_sequence_of_singlecontainer_by_lines(lines, blocks)
    
    
    # ============================================================
    # SEQUENCE OF (không kích thước): "SEQUENCE OF X"
    # ============================================================

    seq_of_simple = re.compile(
        r"([A-Za-z0-9'\-]+)\s*::=\s*SEQUENCE\s+OF\s+([A-Za-z0-9'\-]+)",
        flags=re.MULTILINE
    )

    for m in seq_of_simple.finditer(area):
        name = m.group(1).strip()
        ref = m.group(2).strip()
        if name not in blocks:  # tránh ghi đè
            blocks[name] = {
                "kind": "SEQUENCE-OF",
                "content": ref
            }

    # ============================================================
    # ProtocolIE-SingleContainer { {X} }
    # ============================================================

    single_container_pattern = re.compile(
        r"([A-Za-z0-9'\-]+)\s*::=\s*(?:ProtocolIE[- ]?SingleContainer|SingleContainer)\s*\{\s*\{\s*([A-Za-z0-9'\-]+)\s*\}\s*\}",
        flags=re.MULTILINE
    )

    for m in single_container_pattern.finditer(area):
        name = m.group(1).strip()
        inner = m.group(2).strip()

        blocks[name] = {
            "kind": "SINGLE-CONTAINER",
            "content": inner
        }

    # ============================================================
    # IE-LISTS (giữ nguyên code gốc)
    # ============================================================

    for m in re.finditer(
        r"([A-Za-z0-9'\-]+)\s+(?:E2AP-PROTOCOL-IES|PROTOCOL-IES|ProtocolIE-List|ProtocolIE-Container)\s*::=\s*\{",
        area,
        flags=re.IGNORECASE
    ):
        name = m.group(1).strip()
        brace_start = m.end() - 1

        end_idx, content = find_balanced_braces(area, brace_start)
        if end_idx:
            blocks[name] = {"kind": "IE-LIST", "content": content.strip()}
        else:
            blocks[name] = {"kind": "IE-LIST", "content": ""}

    # ============================================================
    # ALIAS / đơn giản "::= Something"
    # ============================================================

    alias_pattern = re.compile(
        r"^([A-Za-z0-9'\-]+)\s*::=\s*([A-Za-z0-9 \(\)\.\-,'<>]+)$",
        flags=re.MULTILINE
    )

    for m in alias_pattern.finditer(area):
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
    in_sequence_block = False  # Đang ở trong SEQUENCE { ... }

    i = 0
    while i < len(s):
        ch = s[i]

        if ch == "{" and depth_brace == 0 and not in_sequence_block:
            # Bắt đầu block SEQUENCE {
            seq_match = re.match(r"\s*SEQUENCE\s*\{", s[i-9:i+1], re.I)
            if seq_match:
                in_sequence_block = True
                # Bỏ qua từ "SEQUENCE {"
                i += len(seq_match.group(0)) - 1
                current.append("{")
                depth_brace += 1
                i += 1
                continue

        if ch == "{":
            depth_brace += 1
        elif ch == "}":
            depth_brace -= 1
            if depth_brace == 0 and in_sequence_block:
                in_sequence_block = False
                # Kết thúc block SEQUENCE }
                token = "".join(current).strip()
                if token:
                    parts.append(token)
                current = []
                i += 1
                continue

        # Chỉ cắt , khi:
        # - Không trong ngoặc
        # - Không trong SEQUENCE block
        # - Không phải , trong type
        if (ch == "," and depth_paren == 0 and depth_brace == 0 and not in_sequence_block):
            token = "".join(current).strip()
            if token:
                parts.append(token)
            current = []
        else:
            current.append(ch)
        i += 1

    # Thêm phần cuối
    last = "".join(current).strip()
    if last:
        parts.append(last)

    return [p.strip() for p in parts if p.strip()]


# def parse_fields(content):
#     items = split_fields_from_block(content)
#     fields = []
#     for it in items:
#         s = it.strip()
#         if any(e in s for e in ELLIPSIS): continue
#         if "SingleContainer" in s:
#             fields.append((None, s))
#             continue

#         m = re.match(r"^([A-Za-z0-9'\-]+)\s+(.+)", s)
#         if m:
#             fname = m.group(1).strip()
#             ftype = m.group(2).strip()
#             ftype = re.sub(r"\bOPTIONAL\b.*$", "", ftype, flags=re.I).strip()
#             ftype = re.sub(r"\bPRESENCE\b.*$", "", ftype, flags=re.I).strip()
#             ftype = re.sub(r"\bCONSTRAINED BY\b.*$", "", ftype, flags=re.I).strip()
#             fields.append((fname, ftype))
#             continue

#         tokens = re.findall(r"[A-Za-z0-9'\-]+", s)
#         if tokens:
#             fields.append((tokens[0], None))
#             continue
#         fields.append((None, s))
#     return fields


def parse_fields(content):
    items = split_fields_from_block(content)
    fields = []
    for it in items:
        s = it.strip()
        s = re.sub(r'\bthis\b', '----------error-------', s, flags=re.IGNORECASE)
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
    # SEQUENCE-OF-SINGLECONTAINER
    # -------------------------
    if kind == "SEQUENCE-OF-SINGLECONTAINER":
        inner = content.strip()
        child = build_type_tree(inner, blocks, visited.copy())
        #list_node = Node("[]", "SEQUENCE-OF")
        #list_node.children.append(child)
        #node.children.append(list_node)
        node.children.append(child)
        return node
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
            ref = extract_ref_from_type(ftype)


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
    text = preprocess_pdf_text(text)
    print("Extracting ASN.1 blocks…")
    blocks = extract_asn1_blocks(text)
    print(f"Found {len(blocks)} ASN.1 types.")

    # case-insensitive resolve
    real_target = next((k for k in blocks if k.lower() == target.lower()), target)

    print(f"Building tree for: {real_target}")
    tree = build_type_tree(real_target, blocks)

    print("\n--- TREE ---")
    pretty_print(tree)

    out_json = f"./e2_{real_target}_tree.json"
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(tree.to_dict(), f, indent=2, ensure_ascii=False)

    print("\nSaved JSON:", out_json)

    data = to_yaml_dict(tree)
    out_file = f"{real_target}.yaml"
    with open(out_file, "w", encoding="utf-8") as f:
        yaml.dump(data, f, allow_unicode=True, sort_keys=False)

    print(f"Saved YAML → {out_file}")

if __name__ == "__main__":
    tp = TARGET_TYPE
    pp = pdf_path
    if len(sys.argv) >= 2:
        tp = sys.argv[1]
    if len(sys.argv) >= 3:
        pp = sys.argv[2]
    with open('../msg.config', 'r') as file:
        line = file.readline().strip()  # strip() để loại bỏ ký tự trắng dư thừa
        word = line.split()[0] if line else None
    print(word)
    tp = word
    main(pp, tp)


