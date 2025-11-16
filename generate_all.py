# generate_all.py
import pandas as pd
from jinja2 import Template, Environment, FileSystemLoader
import os

# Cấu hình Jinja2
env = Environment(loader=FileSystemLoader("templates"), trim_blocks=True, lstrip_blocks=True)

# Đọc Excel
df = pd.read_excel("data_e2setup.xlsx", sheet_name=None)  # Đọc tất cả sheet

# Tạo thư mục output
os.makedirs("output", exist_ok=True)

# =============================
# 1. SINH CÁC IE PRIMITIVE (INTEGER, ENUM, OCTET...)
# =============================
primitive_df = df.get("Primitives", pd.DataFrame())
for _, row in primitive_df.iterrows():
    name = row["IE_Name"]
    asn_type = row["ASN1_Type"]
    template_dir = "templates"

    # Xác định số bits
    maxv = row["Max"] if pd.notna(row["Max"]) else 0
    if maxv <= 255:
        bits = 8
    elif maxv <= 65535:
        bits = 16
    else:
        bits = 32

    # INTEGER có extension
    if "INTEGER" in asn_type and "..." in asn_type:
        h_tmpl = env.get_template("integer_with_ext.h.j2")
        c_tmpl = env.get_template("integer_with_ext.c.j2")
        data = {
            "name": name,
            "min_root": row["Min"],
            "max_root": row["Max"],
            "type": "OSUINT8" if bits == 8 else ("OSUINT16" if bits == 16 else "OSUINT32")
        }

    # INTEGER không extension
    elif "INTEGER" in asn_type:
        h_tmpl = env.get_template("integer_no_ext.h.j2")
        c_tmpl = env.get_template("integer_no_ext.c.j2")
        data = {
            "name": name,
            "min": row["Min"],
            "max": row["Max"],
            "bits": bits,
            "type": "OSUINT8" if bits == 8 else ("OSUINT16" if bits == 16 else "OSUINT32")
        }

    # ENUMERATED
    elif "ENUMERATED" in asn_type:
        items = eval(row["Enum_Items"])
        h_tmpl = env.get_template("enumerated.h.j2")
        c_tmpl = env.get_template("enumerated.c.j2")
        data = {
            "name": name,
            #"items": [{"value": v, "name": n, "string": s, "transidx": t} for v, n, s, t in items]
            "items": [{"value": v, "name": n, "string": s} for v, n, s in items]
        }

    # OCTET STRING (SIZE(n))
    elif "OCTET STRING" in asn_type:
        import re
        match = re.search(r"SIZE\((\d+)\)", asn_type)
        if match:
            # Fixed size
            size = int(match.group(1))
            h_tmpl = env.get_template("octet_string.h.j2")
            c_tmpl = env.get_template("octet_string.c.j2")
            data = {
                "name": name,
                "is_dynamic": False,
                "size": size
            }
        else:
            # Dynamic (no SIZE)
            h_tmpl = env.get_template("octet_string.h.j2")
            c_tmpl = env.get_template("octet_string.c.j2")
            data = {
                "name": name,
                "is_dynamic": True
            }
    #PRINTABLE STRING        
    elif "PrintableString" in asn_type:
        import re
        match = re.search(r"SIZE\((\d+)\.\.(\d+),?\s*\.\.\.\)", asn_type)
        if match:
            min_size = int(match.group(1))
            max_size = int(match.group(2))
            h_tmpl = env.get_template("printable_string.h.j2")
            c_tmpl = env.get_template("printable_string.c.j2")
            data = {
                "name": name,
                "has_constraint": True,
                "min_size": min_size,
                "max_size": max_size
            }
        else:
            h_tmpl = env.get_template("printable_string.h.j2")
            c_tmpl = env.get_template("printable_string.c.j2")
            data = {
                "name": name,
                "has_constraint": False
            }

    else:
        print(f"Skip primitive: {name}")
        continue

    # Ghi file
    with open(f"output/e2ap_{name}.h", "w", encoding="utf-8") as f:
        f.write(h_tmpl.render(data))
    with open(f"output/e2ap_{name}.c", "w", encoding="utf-8") as f:
        f.write(c_tmpl.render(data))
    print(f"Generated primitive: e2ap_{name}.h/c")





# =============================
# 2. SINH BẢN TIN LỚN (E2SetupRequest)
# =============================
message_df = df.get("Messages", pd.DataFrame())
if not message_df.empty:
    for message_name, group in message_df.groupby("Message_Name"):
        ies = []
        includes = set()
        for _, row in group.iterrows():
            ie_type = row["IE_Type"]
            field_name = row["Field_Name"]
            ie_id = row["IE_ID_Constant"]
            includes.add(f"e2ap_{ie_type}")
            ies.append({
                "ie_type": ie_type,
                "field": field_name,
                "ie_id_constant": ie_id
            })

        data = {
            "message_name": message_name,
            "ies": ies,
            "includes": sorted(includes)
        }

        # Sinh .h (gộp T_VALUE + IE + Container + Message)
        h_tmpl = env.get_template("message.h.j2")
        with open(f"output/e2ap_{message_name}.h", "w", encoding="utf-8") as f:
            f.write(h_tmpl.render(data))

        # Sinh .c (PE/PD + switch case)
        c_tmpl = env.get_template("message.c.j2")
        with open(f"output/e2ap_{message_name}.c", "w", encoding="utf-8") as f:
            f.write(c_tmpl.render(data))

        print(f"Generated message: e2ap_{message_name}.h/c")
# =============================
# 3. SINH T_VALUE UNION + ProtocolIE-Container
# =============================
types_df = df.get("Types", pd.DataFrame())
if not types_df.empty:
    # Gom nhóm theo Parent_Type (ví dụ: E2SetupRequest)
    for parent_type, group in types_df.groupby("Parent_Type"):
        # 1. Sinh T_VALUE union
        fields = []
        includes = set()
        for _, row in group.iterrows():
            field_name = row["Field_Name"]
            ie_type = row["IE_Type"]
            includes.add(f"e2ap_{ie_type}")
            fields.append({"field": field_name, "ie_type": ie_type})

        # T_VALUE .h
        h_tmpl = env.get_template("tvalue.h.j2")
        with open(f"output/e2ap_{parent_type}IEs_T_VALUE.h", "w", encoding="utf-8") as f:
            f.write(h_tmpl.render({
                "parent": parent_type,
                "fields": fields,
                "includes": sorted(includes)
            }))
        print(f"Generated T_VALUE: e2ap_{parent_type}IEs_T_VALUE.h")

        # 2. Sinh ProtocolIE-Container
        container_name = f"{parent_type}IEs"
        h_tmpl = env.get_template("protocol_ie.h.j2")
        with open(f"output/e2ap_{container_name}.h", "w", encoding="utf-8") as f:
            f.write(h_tmpl.render({
                "container_name": container_name,
                "parent": parent_type
            }))
        print(f"Generated container: e2ap_{container_name}.h")
        
# =============================
# 4. SINH CHOICE (E2AP_PDU, GlobalE2node_ID, ...)
# =============================
choice_df = df.get("Types", pd.DataFrame())
if not choice_df.empty:
    # Lọc các dòng có ASN1_Type = "CHOICE"
    choice_groups = choice_df[choice_df["ASN1_Type"] == "CHOICE"].groupby("Type_Name")
    for choice_name, group in choice_groups:
        choices = []
        includes = set()
        for _, row in group.iterrows():
            if pd.isna(row["Field_Name"]): continue
            tag = row["Tag/ID"]
            field = row["Field_Name"]
            choice_type = row["IE_Type"]
            includes.add(f"e2ap_{choice_type}")
            choices.append({
                "tag": tag,
                "field": field,
                "type": choice_type,
                "name": field
            })

        data = {
            "name": choice_name,
            "choices": choices,
            "includes": sorted(includes)
        }

        # Sinh .h
        h_tmpl = env.get_template("choice.h.j2")
        with open(f"output/e2ap_{choice_name}.h", "w", encoding="utf-8") as f:
            f.write(h_tmpl.render(data))

        # Sinh .c
        c_tmpl = env.get_template("choice.c.j2")
        with open(f"output/e2ap_{choice_name}.c", "w", encoding="utf-8") as f:
            f.write(c_tmpl.render(data))

        print(f"Generated CHOICE: e2ap_{choice_name}.h/c")