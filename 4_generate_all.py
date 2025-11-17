# generate_all.py
import pandas as pd
from jinja2 import Environment, FileSystemLoader
import os
import re

# Cấu hình Jinja2
env = Environment(loader=FileSystemLoader("templates"), trim_blocks=True, lstrip_blocks=True)

# Đọc Excel
df = pd.read_excel("data_e2setup.xlsx", sheet_name=None)

# Tạo thư mục output
os.makedirs("output", exist_ok=True)

# Danh sách các file đã sinh (để tránh ghi đè)
generated_files = set()

def safe_write(path, content):
    if path in generated_files:
        print(f"Skip (already generated): {path}")
        return
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)
    generated_files.add(path)
    print(f"Generated: {path}")

# =============================
# 1. SINH CÁC IE PRIMITIVE
# =============================
primitive_df = df.get("Primitives", pd.DataFrame())
for _, row in primitive_df.iterrows():
    name = row["IE_Name"].replace('-', '_')
    asn_type = row["ASN1_Type"]

    # Xác định số bits
    maxv = row["Max"] if pd.notna(row["Max"]) else 0
    if maxv <= 255:
        bits = 8
    elif maxv <= 65535:
        bits = 16
    elif maxv <= 4294967295:
        bits = 32
    else:
        bits = 64

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
        data = {"name": name, "items": [{"value": v, "name": n, "string": s} for v, n, s in items]}

    # OCTET STRING
    elif "OCTET STRING" in asn_type:
        match = re.search(r"SIZE\((\d+)\)", asn_type)
        if match:
            size = int(match.group(1))
            h_tmpl = env.get_template("octet_string.h.j2")
            c_tmpl = env.get_template("octet_string.c.j2")
            data = {"name": name, "is_dynamic": False, "size": size}
        else:
            h_tmpl = env.get_template("octet_string.h.j2")
            c_tmpl = env.get_template("octet_string.c.j2")
            data = {"name": name, "is_dynamic": True}

    # PrintableString
    elif "PrintableString" in asn_type:
        match = re.search(r"SIZE\((\d+)\.\.(\d+),?\s*\.\.\.\)", asn_type)
        if match:
            min_size, max_size = int(match.group(1)), int(match.group(2))
            h_tmpl = env.get_template("printable_string.h.j2")
            c_tmpl = env.get_template("printable_string.c.j2")
            data = {"name": name, "has_constraint": True, "min_size": min_size, "max_size": max_size}
        else:
            h_tmpl = env.get_template("printable_string.h.j2")
            c_tmpl = env.get_template("printable_string.c.j2")
            data = {"name": name, "has_constraint": False}

    else:
        print(f"Skip primitive: {name}")
        continue

    safe_write(f"output/e2ap_{name}.h", h_tmpl.render(data))
    safe_write(f"output/e2ap_{name}.c", c_tmpl.render(data))

# =============================
# 2. SINH CHOICE
# =============================
types_df = df.get("Types", pd.DataFrame())
choice_groups = types_df[types_df["ASN1_Type"] == "CHOICE"].groupby("Type_Name")
for choice_name, group in choice_groups:
    choice_name = choice_name.replace('-', '_')
    choices, includes = [], set()
    for _, row in group.iterrows():
        if pd.isna(row["Field_Name"]): continue
        tag = row["Tag/ID"]
        field = row["Field_Name"]
        ctype = row["IE_Type"]
        includes.add(f"e2ap_{ctype}")
        choices.append({"tag": tag, "field": field, "type": ctype, "name": field})
    data = {"name": choice_name, "choices": choices, "includes": sorted(includes)}
    safe_write(f"output/e2ap_{choice_name}.h", env.get_template("choice.h.j2").render(data))
    safe_write(f"output/e2ap_{choice_name}.c", env.get_template("choice.c.j2").render(data))

# =============================
# 3. SINH SEQUENCE (NORMAL + CONTAINER + LIST)
# =============================
seq_groups = types_df[types_df["ASN1_Type"] == "SEQUENCE"].groupby("Type_Name")
seq_order = []  # topological sort: con -> cha

# Thu thập tất cả SEQUENCE
seq_info = {}
for seq_name, group in seq_groups:
    seq_name = seq_name.replace('-', '_')
    fields = []
    is_container = False
    extensible = False
    list_field = None

    for _, row in group.iterrows():
        if row["ASN1_Type"] == "IE":
            ie_id = row["IE_ID_Constant"] if pd.notna(row["IE_ID_Constant"]) else None
            if ie_id: is_container = True
            if pd.notna(row["Extensible"]) and row["Extensible"].lower() == "yes":
                extensible = True
            fields.append({
                "field": row["Field_Name"],
                "ie_type": row["IE_Type"],
                "ie_id_constant": ie_id,
                "criticality": row["Criticality"] if pd.notna(row["Criticality"]) else "reject",
                "presence": row["Presence"].lower() if pd.notna(row["Presence"]) else "mandatory"
            })
        elif row["ASN1_Type"] == "SEQUENCE OF":
            list_field = {
                "ie_type": row["IE_Type"],
                "field": row["Field_Name"],
                "ie_id_constant": row["Tag/ID"]
            }

    seq_info[seq_name] = {
        "fields": fields,
        "is_container": is_container,
        "extensible": extensible,
        "list_field": list_field,
        "group": group
    }

# Xác định thứ tự sinh: con trước, cha sau
def get_deps(name):
    deps = set()
    info = seq_info.get(name, {})
    for f in info.get("fields", []):
        deps.add(f["ie_type"])
    if info.get("list_field"):
        deps.add(info["list_field"]["ie_type"])
    return deps

from collections import deque
visited = set()
order = []

def dfs(node):
    if node in visited: return
    visited.add(node)
    for dep in get_deps(node):
        if dep in seq_info:
            dfs(dep)
    order.append(node)

for name in seq_info:
    dfs(name)

# =============================
# 4. SINH THEO THỨ TỰ: CON -> CHA
# =============================
for seq_name in order:
    info = seq_info[seq_name]
    fields = info["fields"]
    is_container = info["is_container"]
    extensible = info["extensible"]
    list_field = info["list_field"]

    includes = set(f"e2ap_{f['ie_type']}" for f in fields)
    if list_field:
        includes.add(f"e2ap_{list_field['ie_type']}")

    # === 1. Normal SEQUENCE (không phải container) ===
    if not is_container and not list_field:
        data = {"name": seq_name, "fields": fields, "extensible": extensible}
        safe_write(f"output/e2ap_{seq_name}.h", env.get_template("seq_normal.h.j2").render(data))
        safe_write(f"output/e2ap_{seq_name}.c", env.get_template("seq_normal.c.j2").render(data))
        continue

    # === 2. ProtocolIE-Container (nhiều IE) ===
    if is_container:
        container_name = f"{seq_name}IEs"
        tvalue_fields = [{"field": f["field"], "ie_type": f["ie_type"]} for f in fields]
        safe_write(f"output/e2ap_{container_name}.h", env.get_template("protocol_ie.h.j2").render({
            "container_name": container_name, "parent": seq_name
        }))
        if tvalue_fields:
            safe_write(f"output/e2ap_{seq_name}IEs_T_VALUE.h", env.get_template("tvalue.h.j2").render({
                "parent": seq_name, "fields": tvalue_fields, "includes": sorted(includes)
            }))

    # === 3. SEQUENCE OF (List) ===
    if list_field:
        list_name = list_field["ie_type"]
        item_type = list_name.replace("_List", "_Item")
        item_ies = f"{item_type}IEs"

        # SingleContainer
        safe_write(f"output/e2ap_{item_ies}_T_VALUE.h", env.get_template("tvalue_single.h.j2").render({
            "item_ies": item_ies, "item_type": item_type, "ie_id": list_field["ie_id_constant"]
        }))
        safe_write(f"output/e2ap_{item_ies}.h", env.get_template("protocol_ie_single.h.j2").render({
            "item_ies": item_ies, "item_type": item_type, "ie_id_constant": list_field["ie_id_constant"]
        }))
        safe_write(f"output/e2ap_{item_ies}.c", env.get_template("protocol_ie_single.c.j2").render({
            "item_ies": item_ies, "item_type": item_type, "ie_id_constant": list_field["ie_id_constant"],
            "criticality": "reject"
        }))
        safe_write(f"output/e2ap_{list_name}.h", env.get_template("seq_of.h.j2").render({
            "list_name": list_name, "item_ies": item_ies
        }))

# =============================
# 5. SINH MESSAGE (E2SetupRequest, ...)
# =============================
message_df = df.get("Messages", pd.DataFrame())
for message_name, group in message_df.groupby("Message_Name"):
    message_name = message_name.replace('-', '_')
    ies, includes = [], set()
    for _, row in group.iterrows():
        ie_type = row["IE_Type"]
        field_name = row["Field_Name"]
        ie_id = row["IE_ID_Constant"]
        includes.add(f"e2ap_{ie_type}")
        ies.append({"ie_type": ie_type, "field": field_name, "ie_id_constant": ie_id})

    data = {"message_name": message_name, "ies": ies, "includes": sorted(includes)}
    safe_write(f"output/e2ap_{message_name}.h", env.get_template("message.h.j2").render(data))
    safe_write(f"output/e2ap_{message_name}.c", env.get_template("message.c.j2").render(data))

print("=== TẤT CẢ ĐÃ HOÀN TẤT ===")