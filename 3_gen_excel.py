#!/usr/bin/env python3
"""
parse_e2ap_to_excel_terminal.py
Đọc O-RAN E2AP PDF → Tìm E2SetupRequest → In ra terminal 3 bảng Excel:
- Primitives
- Messages
- Types
→ KHÔNG GHI FILE → CHỈ IN RA CONSOLE
→ ĐÚNG ĐỊNH DẠNG BẢNG + T_VALUE + ProtocolIE-Container
"""

import re
import sys
import pdfplumber
from typing import Dict, List, Any, Optional

PDF_PATH = "Tool_read_pdf/O-RAN_E2AP.WG3.TS.E2AP-R004-v07.00.pdf"
TARGET_TYPE = "E2setupRequest"

# ===================================================================
# 1. ĐỌC PDF
# ===================================================================
def extract_text_from_pdf(path: str) -> str:
    try:
        with pdfplumber.open(path) as pdf:
            return "\n".join(page.extract_text() or "" for page in pdf.pages)
    except Exception as e:
        print(f"Error reading PDF with pdfplumber: {e}")
        sys.exit(1)

# ===================================================================
# 2. TÌM ASN.1 BLOCKS
# ===================================================================
def extract_asn1_blocks(text: str) -> Dict[str, Dict]:
    blocks = {}

    # SEQUENCE / CHOICE / SET
    for kind in ("SEQUENCE", "CHOICE", "SET"):
        pattern = rf"([A-Za-z0-9'-]+)\s*::=\s*{kind}\s*\{{"
        for m in re.finditer(pattern, text):
            name = m.group(1)
            start = m.end() - 1
            end, content = find_balanced(text, start)
            if end:
                blocks[name] = {"kind": kind, "content": content.strip()}

    # ProtocolIE-Container
    for m in re.finditer(r"([A-Za-z0-9'-]+)IEs\s*::=\s*SEQUENCE\s*\(.*ProtocolIE-Container", text):
        name = m.group(1) + "IEs"
        blocks[name] = {"kind": "IE-CONTAINER", "content": ""}

    # ALIAS
    for m in re.finditer(r"^([A-Za-z0-9'-]+)\s*::=\s*([^\n]+)", text, re.MULTILINE):
        name, rhs = m.groups()
        if name not in blocks:
            blocks[name] = {"kind": "ALIAS", "content": rhs.strip()}

    return blocks

def find_balanced(text: str, start: int) -> tuple[Optional[int], str]:
    assert text[start] == "{"
    depth = 0
    i = start
    while i < len(text):
        if text[i] == "{": depth += 1
        elif text[i] == "}": 
            depth -= 1
            if depth == 0: return i + 1, text[start + 1:i]
        i += 1
    return None, ""

# ===================================================================
# 3. PARSE FIELDS
# ===================================================================
def parse_fields(content: str) -> List[tuple[str, str]]:
    fields = []
    parts = re.split(r",\s*(?=[a-zA-Z])", content.replace("\n", " "))
    for part in parts:
        part = part.strip()
        if not part or part in {"...", ".."}: continue
        m = re.match(r"([a-zA-Z0-9'-]+)\s+(.+)", part)
        if m:
            fields.append((m.group(1), m.group(2).split()[0]))
        else:
            fields.append((part.split()[0], "UNKNOWN"))
    return fields

# ===================================================================
# 4. BUILD TREE + COLLECT DATA
# ===================================================================
class Node:
    def __init__(self, name: str, kind: str = "UNKNOWN", primitive: bool = False):
        self.name = name
        self.kind = kind
        self.primitive = primitive
        self.children: List[Node] = []

def build_tree(name: str, blocks: Dict, visited: set) -> Node:
    if name in visited: return Node(name, "RECURSIVE")
    visited.add(name)

    node = Node(name)
    block = blocks.get(name, {})

    if not block:
        node.primitive = any(t in name.upper() for t in ["INTEGER", "OCTET", "ENUM", "PRINTABLE"])
        node.kind = "PRIMITIVE" if node.primitive else "EXTERNAL"
        return node

    kind = block["kind"]
    node.kind = kind

    if kind == "ALIAS":
        ref = block["content"].split()[0]
        child = build_tree(ref, blocks, visited.copy())
        node.children.append(child)
        return node

    if kind in ("SEQUENCE", "CHOICE"):
        content = block.get("content", "")
        fields = parse_fields(content)
        for fname, ftype in fields:
            child = build_tree(ftype, blocks, visited.copy())
            child.name = fname  # override name
            node.children.append(child)

    return node

# ===================================================================
# 5. IN RA TERMINAL DƯỚI DẠNG BẢNG EXCEL
# ===================================================================
def print_excel_tables(tree: Node, target: str):
    primitives = []
    messages = []
    types = []

    def traverse(node: Node, parent_msg: str = None):
        # Primitives
        if node.primitive:
            name = node.name.split()[0] if " " in node.name else node.name
            asn_type = node.name
            min_v = max_v = enum = ""

            if "INTEGER" in asn_type:
                m = re.search(r"\((\d+)\.\.(\d+)", asn_type)
                if m: min_v, max_v = m.groups()
                asn_type = "INTEGER"
            elif "ENUMERATED" in asn_type:
                asn_type = "ENUMERATED"
                if "Criticality" in name:
                    enum = '[(0,"reject","reject"),(1,"ignore","ignore"),(2,"notify","notify")]'
            elif "OCTET STRING" in asn_type:
                asn_type = "OCTET STRING"
            elif "PrintableString" in asn_type:
                asn_type = "PrintableString"

            primitives.append([name, asn_type, min_v, max_v, enum])
            return

        # Messages + IE + T_VALUE
        if node.kind == "SEQUENCE" and parent_msg is None:
            parent_msg = node.name

        if parent_msg and node.kind != "SEQUENCE":
            ie_type = node.name
            field = ie_type[0].lower() + ie_type[1:]
            if field.endswith("List"): field = field[:-4] + "s"
            ie_id = f"ID_id_{ie_type}"

            messages.append([parent_msg, ie_id, ie_type, field])

            # IE
            types.append([parent_msg, "IE", parent_msg, ie_id, field, ie_type, "reject", "", ""])

            # T_VALUE
            types.append([f"{parent_msg}IEs", "T_VALUE", parent_msg, ie_id, field, ie_type, "reject", "", ""])

        # CHOICE
        if node.kind == "CHOICE":
            tag = 1
            for c in node.children:
                types.append([node.name, "CHOICE", node.name, tag, c.name, c.name, "", "", ""])
                tag += 1

    traverse(tree, target)

    # In bảng
    def print_sheet(title: str, headers: List[str], rows: List[list]):
        if not rows: return
        print(f"\n{'='*100}")
        print(f" SHEET: {title}")
        print(f"{'='*100}")
        widths = [max(len(str(r[i])) for r in rows + [headers]) for i in range(len(headers))]
        print(" | ".join(f"{h:<{w}}" for h, w in zip(headers, widths)))
        print("-" * sum(widths + [3]) * len(headers) // len(headers))
        for row in rows:
            print(" | ".join(f"{str(cell):<{w}}" for cell, w in zip(row, widths)))

    print_sheet("Primitives", ["IE_Name", "ASN1_Type", "Min", "Max", "Enum_Items"], primitives)
    print_sheet("Messages", ["Message_Name", "IE_ID_Constant", "IE_Type", "Field_Name"], messages)
    print_sheet("Types", ["Type_Name", "ASN1_Type", "Parent_Type", "Tag/ID", "Field_Name", "IE_Type", "Criticality", "Optional", "Extensible"], types)

# ===================================================================
# MAIN
# ===================================================================
def main():
    print(f"Reading PDF: {PDF_PATH}")
    text = extract_text_from_pdf(PDF_PATH)
    print("Extracting ASN.1 blocks...")
    blocks = extract_asn1_blocks(text)
    print(f"Found {len(blocks)} ASN.1 types.")

    target = TARGET_TYPE
    real_target = next((k for k in blocks if k.lower() == target.lower()), target)
    print(f"Building tree for: {real_target}")

    tree = build_tree(real_target, blocks, set())
    print_excel_tables(tree, real_target)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        TARGET_TYPE = sys.argv[1]  # gán trực tiếp, không cần global
    main()
