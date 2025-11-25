# generate_all.py
import pandas as pd
import re
import os
from jinja2 import Environment, FileSystemLoader

# ---- Config ----
EXCEL_PATH = "data_xlsx/data_excel.xlsx"
TEMPLATES_DIR = "templates"
OUTPUT_DIR = "output"

env = Environment(loader=FileSystemLoader(TEMPLATES_DIR), trim_blocks=True, lstrip_blocks=True)
os.makedirs(OUTPUT_DIR, exist_ok=True)

generated_files = set()

def ceil_to_standard_bits(n):
    """Trả về 8/16/32/64 bit cho n"""
    if not isinstance(n, int):
        return 0
    bits = n.bit_length()
    if bits <= 8:
        return 8
    elif bits <= 16:
        return 16
    elif bits <= 32:
        return 32
    elif bits <= 64:
        return 64
    else:
        raise ValueError(f"Number too large for 64-bit: {n}")

# Thêm filter vào Jinja environment
env.filters['stdbit'] = ceil_to_standard_bits


def safe_write(path, content):
    if path in generated_files:
        print(f"Skip (already generated): {path}")
        return
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)
    generated_files.add(path)
    print(f"Generated: {path}")


# -------------------------
# 1) Load workbook sheets
# -------------------------
wb = pd.read_excel(EXCEL_PATH, sheet_name=None)
types_df = wb.get("Types", pd.DataFrame())
primitives_df = wb.get("Primitives", pd.DataFrame())
messages_df = wb.get("Messages", pd.DataFrame())


# -------------------------
# 2) Keep original check_if_primitive (sheet-based)
# -------------------------
# def check_if_primitive(ie_type_name):
#     """
#     Giữ logic cũ: kiểm tra sheet 'Primitives' để biết IE_Type có phải primitive.
#     Trả về dict:
#       {"isprimitive": bool, "primitive_name": str or None}
#     """
#     if ie_type_name is None:
#         return {"isprimitive": False, "primitive_name": None}

#     match = primitives_df[primitives_df["IE_Name"] == ie_type_name]
#     if match.empty:
#         return {"isprimitive": False, "primitive_name": None}

#     asn1_type = str(match.iloc[0].get("ASN1_Type", "")).strip()
#     asn1_type_clean = re.sub(r"\(.*?\)", "", asn1_type).strip()

#     primitive_types = ["ENUMERATED", "INTEGER", "OCTET STRING", "PrintableString", "BIT STRING"]
#     if any(pt in asn1_type_clean for pt in primitive_types):
#         return {"isprimitive": True, "primitive_name": asn1_type}
#     return {"isprimitive": False, "primitive_name": None}


# -------------------------
# 3) Parse IE_Type text (from sheet Types)
# -------------------------
import re

def extract_base_type(s: str):
    """Lấy primitive type trước dấu '(' nếu có."""
    return s.split("(")[0].strip()


def parse_ie_type_primitive(type_str):
    """
    Trả về metadata primitive chuẩn hoá từ chuỗi IE_Type trong sheet Types.

    Các nhóm bạn yêu cầu:
        bit string  1
        bit string (size(a..b..)) 2
        bit string (size(n)) 3
        bit string (size(a..b)) 4

        integer (size(a..b..)) 5
        integer (size(a..b)) 6
        integer (size(n)) 7

        octet string (size(n)) 8
        octet string 9

        printable string (size(a..b,...)) 10
    """

    out = {
        "is": False,
        "type": None,
        "min": -1,
        "max": -1,
        "fix_size": -1,
        "primitive_id": -1
    }

    if not isinstance(type_str, str):
        return out

    s = type_str.strip()
    s = re.sub(r"\s+", " ", s)

    # ============================================================
    # INTEGER
    # ============================================================
    # INTEGER(a..b..) -> INTEGER(a..b,...)
    #m = re.match(r"INTEGER\s*\(\s*([+-]?\d+)\s*\.\.\s*([+-]?\d+)\s*\.\.\s*\d+\s*\)", s, re.IGNORECASE)
    #m = re.match(r"INTEGER\s*\(\s*([+-]?\d+)\s*\.\.\s*([+-]?\d+)\s*(?:\.\.\.\s*\d+)*\s*\)", s, re.IGNORECASE)
    m = re.match(r"INTEGER\s*\(\s*(\d+)\s*\.\.\s*(\d+)\s*(?:,\s*\.\.\s*)?\s*\)", s, re.IGNORECASE)

    if m:
        out.update({"is": True, "type": "INTEGER",
                    "min": int(m.group(1)), "max": int(m.group(2)),
                    "primitive_id": 5})
        return out

    # INTEGER(a..b)
    m = re.match(r"INTEGER\s*\(\s*([+-]?\d+)\s*\.\.\s*([+-]?\d+)\s*\)", s, re.IGNORECASE)
    if m:
        out.update({"is": True, "type": "INTEGER",
                    "min": int(m.group(1)), "max": int(m.group(2)),
                    "primitive_id": 6})
        return out

    # INTEGER(n)
    m = re.match(r"INTEGER\s*\(\s*SIZE\s*\(\s*(\d+)\s*\)\s*\)", s, re.IGNORECASE)
    #m = re.match(r"INTEGER\s*\(\s*SIZE\s*\(\s*(\d+))", s, re.IGNORECASE)
    if m:
        n = int(m.group(1))
        out.update({"is": True, "type": "INTEGER",
                    "min": n, "max": n, "fix_size": n,
                    "primitive_id": 12})
        return out

    # INTEGER no constraint
    if re.match(r"^INTEGER\b", s, re.IGNORECASE):
        out.update({"is": True, "type": "INTEGER", "primitive_id": 6})
        return out

    # ============================================================
    # OCTET STRING
    # ============================================================
    #m = re.match(r"OCTET STRING\s*\(\s*SIZE\s*\(\s*(\d+))", s, re.IGNORECASE)
    m = re.match(r"OCTET STRING\s*\(\s*SIZE\s*\(\s*(\d+)\s*\)\s*\)", s, re.IGNORECASE)
    if m:
        n = int(m.group(1))
        out.update({"is": True, "type": "OCTET STRING",
                    "min": n, "max": n, "fix_size": n,
                    "primitive_id": 8})
        return out

    if re.match(r"^OCTET STRING\b", s, re.IGNORECASE):
        out.update({"is": True, "type": "OCTET STRING", "primitive_id": 9})
        return out

    # ============================================================
    # BIT STRING
    # ============================================================
    # trước input là BIT STRING(size(a..b..)) -> giờ input sửa thành BIT STRING (SIZE(a..b,...))
    
    #m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)\s*\.\.\s*(\d+)\s*\.\.\s*\d+", s, re.IGNORECASE)
    #m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)\s*\.\.\s*(\d+)\s*\.\.\s*\d+\s*\)\s*\)", s, re.IGNORECASE)
    m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)\s*\.\.\s*(\d+)\s*(?:,\s*\.\.\.\s*)?\s*\)\s*\)", s, re.IGNORECASE)
    if m:
        out.update({"is": True, "type": "BIT STRING",
                    "min": int(m.group(1)), "max": int(m.group(2)),
                    "primitive_id": 2})
        return out

    # BIT STRING(size(n))
    m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)\s*\)\s*\)", s, re.IGNORECASE)
    #m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)", s, re.IGNORECASE)
    if m:
        n = int(m.group(1))
        out.update({"is": True, "type": "BIT STRING",
                    "min": n, "max": n, "fix_size": n,
                    "primitive_id": 3})
        return out

    # BIT STRING(size(a..b))
    m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)\.\.(\d+)\s*\)\s*\)", s, re.IGNORECASE)   #m = re.match(r"BIT STRING\s*\(\s*SIZE\s*\(\s*(\d+)\.\.(\d+)", s, re.IGNORECASE)
    if m:
        out.update({"is": True, "type": "BIT STRING",
                    "min": int(m.group(1)), "max": int(m.group(2)),
                    "primitive_id": 4})
        return out

    # BIT STRING no constraint
    if re.match(r"^BIT STRING\b", s, re.IGNORECASE):
        out.update({"is": True, "type": "BIT STRING", "primitive_id": 1})
        return out

    # ============================================================
    # PrintableString – FULL SUPPORT
    # ============================================================

    # PrintableString(SIZE(a..b,..) – hỗ trợ nhiều cặp range -> PrintableString (SIZE(a..b,...))
    # Lấy toàn bộ bên trong SIZE(...)
    #m = re.match(r"PrintableString\s*\(\s*SIZE\s*\((.*?)\)\s*\)", s, re.IGNORECASE)
    #m = re.match(r"PrintableString\s*\(\s*SIZE\s*\(\s*(.*?)\s*\)\s*\)", s, re.IGNORECASE)
    m = re.match(r"PrintableString\s*\(\s*SIZE\s*\(\s*(.*?)\s*\)\s*\)", s, re.IGNORECASE)
    #m = re.match(r"PrintableString\s*\(\s*SIZE\s*\(\s*(.*)", s, re.IGNORECASE)
    if m:
        size_expr = m.group(1).strip()

        # Trường hợp SIZE gồm nhiều tham số: "1..10, 20..30, 40"
        parts = [p.strip() for p in size_expr.split(",")]

        mins, maxs = [], []

        for p in parts:
            # dạng a..b
            mm = re.match(r"(\d+)\s*\.\.\s*(\d+)", p)
            if mm:
                mins.append(int(mm.group(1)))
                maxs.append(int(mm.group(2)))
                continue

            # dạng a (single)
            mm = re.match(r"(\d+)", p)
            if mm:
                val = int(mm.group(1))
                mins.append(val)
                maxs.append(val)
                continue

        if mins and maxs:
            out.update({
                "is": True,
                "type": "PrintableString",
                "min": min(mins),
                "max": max(maxs),
                "fix_size": min(mins) if min(mins) == max(maxs) else -1,
                "primitive_id": 10
            })
            return out

    # PrintableString (no constraint)
    if re.match(r"^PrintableString\b", s, re.IGNORECASE):
        out.update({"is": True, "type": "PrintableString",
                    "primitive_id": 11})
        return out

    # ============================================================
    # Other simple primitives
    # ============================================================
    simple_prims = [
        "BOOLEAN", "NULL", "ENUMERATED",
        "UTF8String", "IA5String", "VisibleString"
    ]

    for p in simple_prims:
        if re.match(rf"^{p}\b", s, re.IGNORECASE):
            out.update({"is": True, "type": p, "primitive_id": 0})
            return out

    # ============================================================
    # Clean base type
    # ============================================================
    if out["is"]:
        out["type"] = extract_base_type(out["type"])

    return out


def check_if_primitive(asn1_type):
    """
    Nhận vào ASN1_Type (vd: 'OCTET STRING (SIZE(3))')
    Parse bằng parse_ie_type_primitive
    Trả ra metadata primitive chuẩn.
    """

    out = {
        "isprimitive": False,
        "primitive_name": None,#BIT STRING (SIZE(22..32)
        "primitive_type": None,# BIT STRING
        "min": -1,
        "max": -1,
        "fix_size": -1,
        "primitive_id": -1
    }

    if not isinstance(asn1_type, str):
        return out

    parsed = parse_ie_type_primitive(asn1_type)

    out.update({
        "isprimitive": parsed["is"],
        "primitive_name": asn1_type,
        "primitive_type": parsed["type"],
        "min": parsed["min"],
        "max": parsed["max"],
        "fix_size": parsed["fix_size"],
        "primitive_id": parsed["primitive_id"]
    })

    print("primitive name:%s" % out["primitive_name"])
    print("primitive type: %s" % out["primitive_type"])
    return out

# -------------------------
# 4) Generate primitives-based files (keeping your existing primitive generation)
# -------------------------
def gen_primitives_outputs():
    primitive_sheet = primitives_df if not primitives_df.empty else pd.DataFrame()
    for _, row in primitive_sheet.iterrows():
        name_raw = row.get("IE_Name")
        if pd.isna(name_raw):
            continue
        name = str(name_raw).replace('-', '_')
        asn_type = str(row.get("ASN1_Type", ""))

        primitive_info = check_if_primitive(asn_type)

        # Define templates based on ASN.1 type
        try:
            # if "INTEGER" in asn_type and "..." in asn_type:
            #     h_tmpl = env.get_template("integer_with_ext.h.j2")
            #     c_tmpl = env.get_template("integer_with_ext.c.j2")
            #     data = {
            #         "name": name,
            #         "min_root": row.get("Min"),
            #         "max_root": row.get("Max"),
            #         "type": "OSUINT32",
            #         "metadata": primitive_info  # Add metadata
            #     }
            # elif "INTEGER" in asn_type:
            #     h_tmpl = env.get_template("integer_no_ext.h.j2")
            #     c_tmpl = env.get_template("integer_no_ext.c.j2")
            #     data = {
            #         "name": name,
            #         "min": row.get("Min"),
            #         "max": row.get("Max"),
            #         "bits": 32,
            #         "type": "OSUINT32",
            #         "metadata": primitive_info  # Add metadata
            #     }
            if "INTEGER" in asn_type:
                h_tmpl = env.get_template("integer.h.j2")
                c_tmpl = env.get_template("integer.c.j2")
                m = re.search(r"SIZE\((\d+)\)", asn_type)
                if m:
                    data = {"name": name, "is_dynamic": False, "size": int(m.group(1)), "metadata": primitive_info}
                else:
                    data = {"name": name, "is_dynamic": True, "metadata": primitive_info}
            elif "ENUMERATED" in asn_type:
                h_tmpl = env.get_template("enumerated.h.j2")
                c_tmpl = env.get_template("enumerated.c.j2")
                items = []
                if pd.notna(row.get("Enum_Items")):
                    try:
                        items = eval(row.get("Enum_Items"))
                    except Exception:
                        items = []
                data = {"name": name, "items": [{"value": v, "name": n, "string": s} for v, n, s in items], "metadata": primitive_info}
            elif "OCTET STRING" in asn_type:
                print("OCTET STRING DETECT")
                h_tmpl = env.get_template("octet_string.h.j2")
                c_tmpl = env.get_template("octet_string.c.j2")
                m = re.search(r"SIZE\((\d+)\)", asn_type)
                if m:
                    data = {"name": name, "is_dynamic": False, "size": int(m.group(1)), "metadata": primitive_info}
                else:
                    data = {"name": name, "is_dynamic": True, "metadata": primitive_info}
            elif "PrintableString" in asn_type:
                h_tmpl = env.get_template("printable_string.h.j2")
                c_tmpl = env.get_template("printable_string.c.j2")
                m = re.search(r"SIZE\((\d+)\.\.(\d+)", asn_type)
                if m:
                    data = {"name": name, "has_constraint": True, "min_size": int(m.group(1)), "max_size": int(m.group(2)), "metadata": primitive_info}
                else:
                    data = {"name": name, "has_constraint": False, "metadata": primitive_info}
            elif "BIT STRING" in asn_type:
                h_tmpl = env.get_template("bitstring.h.j2")
                c_tmpl = env.get_template("bitstring.c.j2")
                m = re.search(r"SIZE\((\d+)\.\.(\d+)", asn_type)
                if m:
                    data = {"name": name, "has_constraint": True, "min_size": int(m.group(1)), "max_size": int(m.group(2)), "metadata": primitive_info}
                else:
                    data = {"name": name, "has_constraint": False, "metadata": primitive_info}
                
            else:
                print(f"Skip primitive template generation for: {name} ({asn_type})")
                continue

            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{name}.h"), h_tmpl.render(data))
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{name}.c"), c_tmpl.render(data))
        except Exception as e:
            print(f"[WARN] template gen failed for {name}: {e}")


# -------------------------
# 5) Generate CHOICE
# -------------------------
def gen_choice_outputs():
    df = types_df
    if df.empty:
        return
    choice_groups = df[df["ASN1_Type"] == "CHOICE"].groupby("Type_Name")
    for choice_name, group in choice_groups:
        name_clean = str(choice_name).replace('-', '_')
        choices = []
        extensible = None
        primitive_files_data = []  # Danh sách để lưu nội dung các file con primitive

        if "Extensible" in group.columns:
            ext_vals = group["Extensible"].dropna()
            if not ext_vals.empty:
                extensible = str(ext_vals.iloc[0]).strip()

        for _, row in group.iterrows():
            if pd.isna(row.get("Field_Name")):
                continue
            tag = row.get("Tag/ID")
            field = str(row.get("Field_Name"))
            field = field.replace("_", "_")
            ie_type = row.get("IE_Type")
            ie_type_str = "" if pd.isna(ie_type) else str(ie_type)

            # Parse primitive details
            parsed = parse_ie_type_primitive(ie_type_str)
            primitive_sheet = check_if_primitive(ie_type_str)

            # Thêm phần tử cho choice
            choices.append({ # ví dụ 1 bản tin choice có 3 trường thì coi như là mảng 3 phần tử
                "tag": tag,
                "field": field.replace("-", "_"),
                "type": (ie_type_str or "").replace("-", "_"),
                "name": field.replace("-", "_"),
                "primitive": primitive_sheet,
                "primitive_meta": {
                    "is": parsed["is"],
                    "type": parsed["type"],
                    "min": parsed["min"],
                    "max": parsed["max"],
                    "fix_size": parsed["fix_size"],
                    "primitive_id": parsed["primitive_id"]
                }
            })

            # *** Tạo các file con primitive vào trong loop này ***
            primitive_name = str(ie_type_str).replace('-', '_')
            if primitive_sheet['isprimitive']:
                print("dungnm23 primitive name: %s" % primitive_name)
                try:
                    # Xác định template dựa trên primitive type
                    if primitive_sheet["primitive_type"] == 'INTEGER':
                        h_tmpl = env.get_template("integer_intergrate.h.j2")
                        c_tmpl = env.get_template("integer_intergrate.c.j2")
                        #data = {"name": primitive_name, "is_dynamic": True, "metadata": primitive_sheet}
                        metadata = {   "parsed": parsed,  "field_name": field.replace("-", "_") }
                        data = {"is_dynamic": True,"metadata": metadata, "parent_name": name_clean}
                    elif primitive_sheet['primitive_type'] == 'OCTET STRING':
                        h_tmpl = env.get_template("octet_string_intergrate.h.j2")
                        c_tmpl = env.get_template("octet_string_intergrate.c.j2")
                        #data = {"name": primitive_name, "is_dynamic": True, "metadata": primitive_sheet}
                        metadata = {  "parsed": parsed,  "field_name": field.replace("-", "_") }
                        data = {"is_dynamic": True,"metadata": metadata, "parent_name": name_clean}
                    elif primitive_sheet['primitive_type'] == 'BIT STRING':
                        h_tmpl = env.get_template("bitstring_intergrate.h.j2")
                        c_tmpl = env.get_template("bitstring_intergrate.c.j2")
                        #data = {"name": primitive_name, "is_dynamic": True, "metadata": primitive_sheet}
                        metadata = {  "parsed": parsed,  "field_name": field.replace("-", "_") }
                        data = {"is_dynamic": True,"metadata": metadata, "parent_name": name_clean}
                    else:
                        continue  # Các kiểu khác không cần xử lý ở đây
                    print("dungnm23 primitive sheet type: %s" % primitive_sheet['primitive_type'])
                    # tôi muốn data ở đây có chứa metadata
                    # Tạo file con primitive ngay trong loop và lấy nội dung
                    h_file_content = h_tmpl.render(data)
                    c_file_content = c_tmpl.render(data)

                    # Thêm nội dung của các file con primitive vào danh sách
                    primitive_files_data.append({
                        "name": primitive_name,
                        "h_file_content": h_file_content,
                        "c_file_content": c_file_content
                    })

                except Exception as e:
                    print(f"[WARN] primitive template failed for {primitive_name}: {e}")

        # Tạo dữ liệu cho file choice
        data = {
            "name": name_clean,
            "choices": choices,
            "extensible": extensible,
            "primitive_files_data": primitive_files_data  # Gửi thông tin file con vào template
        }
        print(f"dungnm23 choice_h_content: {data['primitive_files_data']}")

        try:
            # Tạo các file choice.h và choice.c, gộp nội dung file con vào
            #choice_h_content = env.get_template("choice.h.j2").render(data)
           #choice_c_content = env.get_template("choice.c.j2").render(data)
            # Viết file choice.h và choice.c
           # safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{name_clean}.h"), choice_h_content)
           # safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{name_clean}.c"), choice_c_content)
            
            safe_write(f"output/e2ap_{name_clean}.h", env.get_template("choice.h.j2").render(data))
            safe_write(f"output/e2ap_{name_clean}.c", env.get_template("choice.c.j2").render(data))
           
        except Exception as e:
            print(f"[WARN] choice template failed for {name_clean}: {e}")

# -------------------------
# 6) Generate SingleContainer
# -------------------------
def gen_single_container_outputs():
    df = types_df
    if df.empty:
        return
    sc_rows = df[df["ASN1_Type"] == "SingleContainer"]
    for _, row in sc_rows.iterrows():
        list_name = str(row.get("Type_Name")).replace("-", "_")
        item_ies = row.get("IE_Type")
        item_type_str = "" if pd.isna(item_ies) else str(item_ies)
        ie_id = row.get("Tag/ID")
        criticality = row.get("Criticality") if pd.notna(row.get("Criticality")) else "reject"

        min_value = int(row.get("Min_Value")) if pd.notna(row.get("Min_Value")) else 1
        max_val_raw = row.get("Max_Value") if pd.notna(row.get("Max_Value")) else "256"

        max_size = max_val_raw

        primitive_sheet = check_if_primitive(item_type_str)
        parsed = parse_ie_type_primitive(item_type_str)

        data = {
            "list_name": list_name,
            "item_ies": item_ies,
            "item_type": item_type_str,
            "ie_id": ie_id,
            "criticality": f"e2ap_Criticality_{criticality}",
            "min_size": min_value,
            "max_size": max_size,
            "primitive": primitive_sheet,
            "primitive_meta": {
                "is": parsed["is"],
                "type": parsed["type"],
                "min": parsed["min"],
                "max": parsed["max"],
                "fix_size": parsed["fix_size"],
                "primitive_id": parsed["primitive_id"]
            }
        }

        try:
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{list_name}.h"), env.get_template("seq_of_single_container.h.j2").render(data))
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{list_name}.c"), env.get_template("seq_of_single_container.c.j2").render(data))
        except Exception as e:
            print(f"[WARN] single container template failed for {list_name}: {e}")
        print(f"SingleContainer → {list_name} (uses {item_ies})")


# -------------------------
# 7) Generate IE (Protocol-IES)
# -------------------------
def gen_ie_outputs():
    df = types_df
    if df.empty:
        return

    # messages original IE 
    
    
    original_ies = set(messages_df["Original_IE_Name"].dropna().unique()) if not messages_df.empty else set()

    ie_rows = df[(df["ASN1_Type"] == "IE") & (~df["IE_Type"].astype(str).str.endswith("IEs"))]

    for ies_name_raw, group in ie_rows.groupby("Type_Name"):
        ies_name = str(ies_name_raw).replace("-", "_")
        choices = []
        for _, row in group.iterrows():
            item_type = row.get("IE_Type")
            field_name = row.get("Field_Name")
            optional_val = row.get("Optional")
            presence = "optional" if (pd.notna(optional_val) and str(optional_val).strip() != "") else "mandatory"
            field_name_clean = str(field_name).replace("-", "_")

            parsed = parse_ie_type_primitive(item_type)
            primitive_sheet = check_if_primitive(item_type)

            choices.append({
                "item_type": item_type,
                "field_name": field_name_clean,
                "presence": presence,
                "primitive": primitive_sheet,
                "primitive_meta": {
                    "is": parsed["is"],#cờ boolean cho biết kiểu này có phải là primitive
                    "type": parsed["type"],
                    "min": parsed["min"],
                    "max": parsed["max"],
                    "fix_size": parsed["fix_size"],
                    "primitive_id": parsed["primitive_id"]
                }
            })

        ie_id = group.iloc[0].get("Tag/ID")
        criticality = group.iloc[0].get("Criticality") if pd.notna(group.iloc[0].get("Criticality")) else "reject"

        ies_name_cleaned = ies_name_raw
        if isinstance(ies_name_cleaned, str) and ies_name_cleaned.endswith("-IEs"):
            ies_name_cleaned = ies_name_cleaned[:-4]
        elif isinstance(ies_name_cleaned, str) and ies_name_cleaned.endswith("IEs"):
            ies_name_cleaned = ies_name_cleaned[:-3]

        data = {"ies_name": ies_name_cleaned, "choices": choices, "ie_id": ie_id, "criticality": f"e2ap_Criticality_{criticality}"}

        try:
            if str(ies_name_raw).endswith("IEs") and str(ies_name_raw) in original_ies:
                safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{ies_name_cleaned.replace('-', '_')}_protocolIEs.h"), env.get_template("ie_big_msg.h.j2").render(data))
                safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{ies_name_cleaned.replace('-', '_')}_protocolIEs.c"), env.get_template("ie_big_msg.c.j2").render(data))
                print(f"IE (BIG) → {ies_name_cleaned} dùng ie_big_msg.h/c")
            else:
                safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{ies_name}.h"), env.get_template("ie.h.j2").render(data))
                safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{ies_name}.c"), env.get_template("ie.c.j2").render(data))
                print(f"IE → {ies_name} dùng ie.h/c")
        except Exception as e:
            print(f"[WARN] ie template failed for {ies_name}: {e}")


# -------------------------
# 8) Generate SEQUENCE
# -------------------------
def gen_sequence_outputs():
    df = types_df
    if df.empty:
        return

    seq_names = df[df["ASN1_Type"].isin(["SEQUENCE", "Container"])]["Type_Name"].unique()

    for seq_name_raw in seq_names:
        seq_name = str(seq_name_raw).replace("-", "_")
        # find child rows
        child_rows = df[(df["Parent_Type"] == seq_name_raw) | ((df["Type_Name"] == seq_name_raw) & (df["ASN1_Type"] == "IE"))]
        fields = []
        seq_fixsize = -1
        seq_minstr = -1
        seq_maxstr = -1
        primitive_files_data = []  # Danh sách để lưu nội dung các file con primitive

        for _, row in child_rows.iterrows():
            field_name_raw = row.get("Field_Name")
            if pd.isna(field_name_raw):
                continue
            field_name = str(field_name_raw).replace("-", "_")
            ie_type = row.get("IE_Type")
            ie_type_str = "" if pd.isna(ie_type) else str(ie_type)
            optional_val = row.get("Optional")
            presence = "optional" if (pd.notna(optional_val) and str(optional_val).strip() != "") else "mandatory"
            parsed = parse_ie_type_primitive(ie_type_str)
            primitive_sheet = check_if_primitive(ie_type_str)


            fields.append({
                "field": field_name,
                "ie_type": ie_type_str.replace("-", "_"),
                "presence": presence,
            
                "primitive": primitive_sheet,
                "primitive_meta": {
                    "is": parsed["is"],
                    "type": parsed["type"],
                    "min": parsed["min"],
                    "max": parsed["max"],
                    "fix_size": parsed["fix_size"],
                    "primitive_id": parsed["primitive_id"]
                }
            })
                        # *** Tạo các file con primitive vào trong loop này ***
            primitive_name = str(ie_type_str).replace('-', '_')
            if primitive_sheet['isprimitive']:
                print("dungnm23 primitive name: %s" % primitive_name)
                try:
                    # Xác định template dựa trên primitive type
                    if primitive_sheet["primitive_type"] == 'INTEGER':
                        h_tmpl = env.get_template("integer_intergrate.h.j2")
                        metadata = {   "parsed": parsed,  "field_name": field_name_raw.replace("-", "_") }
                        data = {"is_dynamic": True,"metadata": metadata, "parent_name": seq_name}
                    elif primitive_sheet['primitive_type'] == 'OCTET STRING':
                        h_tmpl = env.get_template("octet_string_intergrate.h.j2")
                        c_tmpl = env.get_template("octet_string_intergrate.c.j2")
                        metadata = {   "parsed": parsed,  "field_name": field_name_raw.replace("-", "_") }
                        data = {"is_dynamic": True,"metadata": metadata, "parent_name": seq_name}
                    elif primitive_sheet['primitive_type'] == 'BIT STRING':
                        h_tmpl = env.get_template("bitstring_intergrate.h.j2")
                        c_tmpl = env.get_template("bitstring_intergrate.c.j2")
                        metadata = {   "parsed": parsed,  "field_name": field_name_raw.replace("-", "_") }
                        data = {"is_dynamic": True,"metadata": metadata, "parent_name": seq_name}
                    else:
                        continue  # Các kiểu khác không cần xử lý ở đây
                    print("dungnm23 primitive sheet type: %s" % primitive_sheet['primitive_type'])
                    
                    # Tạo file con primitive ngay trong loop và lấy nội dung
                    h_file_content = h_tmpl.render(data)
                    c_file_content = c_tmpl.render(data)

                    # Thêm nội dung của các file con primitive vào danh sách
                    primitive_files_data.append({
                        "name": primitive_name,
                        "h_file_content": h_file_content,
                        "c_file_content": c_file_content
                    })
            
                except Exception as e:
                    print(f"[WARN] SEQ primitive template failed for {primitive_name}: {e}")


        # check extensible
        ext_rows = df[df["Type_Name"] == seq_name_raw]
        extensible = False
        if not ext_rows.empty:
            ext_val = ext_rows.iloc[0].get("Extensible")
            if pd.notna(ext_val) and str(ext_val).strip().lower() in ["yes", "true", "1"]:
                extensible = True

        if not fields and not extensible:
            print(f"Skip empty SEQUENCE: {seq_name}")
            continue

        data = {
            "name": seq_name,
            "fields": fields,
            "choices" :fields,
            "extensible": extensible,
            "fixsize": seq_fixsize,
            "minstr": seq_minstr,
            "maxstr": seq_maxstr,     
            "primitive_files_data": primitive_files_data  # Gửi thông tin file con vào template
        }

        try:
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{seq_name}.h"), env.get_template("seq_normal.h.j2").render(data))
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{seq_name}.c"), env.get_template("seq_normal.c.j2").render(data))
            print(f"SEQUENCE → e2ap_{seq_name}.h/c  ({len(fields)} fields, extensible={extensible})")
        except Exception as e:
            print(f"[WARN] seq template failed for {seq_name}: {e}")


# -------------------------
# 9) Generate MESSAGE
# -------------------------
def gen_message_outputs():
    if messages_df.empty:
        return
    for message_name, group in messages_df.groupby("Message_Name"):
        message_name_clean = str(message_name).replace("-", "_")
        ies = []
        includes = set()

        for _, row in group.iterrows():
            ie_type = row.get("IE_Type")
            ie_type_str = "" if pd.isna(ie_type) else str(ie_type)
            field_name = row.get("Field_Name")
            origin_name = row.get("Original_IE_Name")
            critical = row.get("Critical")
            presence = row.get("Presence")
            ie_id = row.get("IE_ID_Constant")

            includes.add(f"e2ap_{ie_type_str}")

            primitive_sheet = check_if_primitive(ie_type_str)
            parsed = parse_ie_type_primitive(ie_type_str)

            ies.append({
                "ie_type": ie_type_str,
                "field": str(field_name).replace("-", "_") if pd.notna(field_name) else None,
                "ie_id_constant": ie_id,
                "origin_name": origin_name,
                "critical": critical,
                "presence": presence,
                "primitive": primitive_sheet,
                "primitive_meta": {
                    "is": parsed["is"],
                    "type": parsed["type"],
                    "min": parsed["min"],
                    "max": parsed["max"],
                    "fix_size": parsed["fix_size"],
                    "primitive_id": parsed["primitive_id"]
                }
            })

        data = {"message_name": message_name_clean, "ies": ies, "includes": sorted(list(includes))}
        try:
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{message_name_clean + '_protocolIEs_element'}.h"), env.get_template("message.h.j2").render(data))
            safe_write(os.path.join(OUTPUT_DIR, f"e2ap_{message_name_clean + '_protocolIEs_element'}.c"), env.get_template("message.c.j2").render(data))
        except Exception as e:
            print(f"[WARN] message template failed for {message_name_clean}: {e}")


# -------------------------
# Main runner
# -------------------------
def main():
    print("Generating primitives from sheet 'Primitives'...")
    gen_primitives_outputs()
    print("Generating CHOICEs...")
    gen_choice_outputs()
    print("Generating SingleContainers...")
    gen_single_container_outputs()
    print("Generating IEs...")
    gen_ie_outputs()
    print("Generating SEQUENCEs...")
    gen_sequence_outputs()
    print("Generating MESSAGES...")
    gen_message_outputs()
    print("=== DONE ===")


if __name__ == "__main__":
    main()
