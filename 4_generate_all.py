# generate_all.py
import pandas as pd
from jinja2 import Environment, FileSystemLoader
import os
import re

# Cấu hình Jinja2
env = Environment(loader=FileSystemLoader("templates"), trim_blocks=True, lstrip_blocks=True)

# Đọc Excel
#df = pd.read_excel("data_e2setup.xlsx", sheet_name=None)
df = pd.read_excel("data_xlsx/data_excel.xlsx", sheet_name=None)
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
            "type": "OSUINT8" if bits == 8 else ("OSUINT16" if bits == 16 else ("OSUINT32" if bits ==32 else "OSUINT64"))
            #"type": "OSUINT8" if bits == 8 else ("OSUINT16" if bits == 16 else ("OSUINT32"))
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
            "type": "OSUINT8" if bits == 8 else ("OSUINT16" if bits == 16 else ("OSUINT32" if bits ==32 else "OSUINT64"))

            #"type": "OSUINT8" if bits == 8 else ("OSUINT16" if bits == 16 else "OSUINT32")
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
        extensible = row["Extensible"]
        #field = field.replace('-', '_')
        ctype = row["IE_Type"]
        includes.add(f"e2ap_{ctype}")
        
        
                # Chuẩn hoá BIT STRING và tách size
        fixsize = None
        minstr = None
        maxstr = None



        m_bit = re.match(r"BIT\s+STRING(?:\s*\((.*?)\))?", str(ctype), re.IGNORECASE)
        if m_bit:
            ctype = "BIT STRING"   # chuẩn hoá tên C-type

            size_part = m_bit.group(1)
            if size_part:
                size_part = size_part.replace("SIZE", "").replace("(", "").replace(")", "").strip()

                # TH1: dạng SIZE(n)
                m_fixed = re.match(r"(\d+)$", size_part)
                if m_fixed:
                    fixsize = int(m_fixed.group(1))

                # TH2: dạng SIZE(a..b)
                m_range = re.match(r"(\d+)\s*\.\.\s*(\d+)", size_part)
                if m_range:
                    minstr = int(m_range.group(1))
                    maxstr = int(m_range.group(2))
                
                if(fixsize):
                    minstr= fixsize
                    maxstr = fixsize    
        
        #tag = tag.replace("-","_")
        field = field.replace("-","_")
        ctype = ctype.replace("-","_")
        #name = name.replace("-","_")
        
        
        
        
        choices.append({
            "tag": tag,
            "field": field,
            "type": ctype,
            "name": field,
            "fixsize": fixsize,
            "minstr": minstr,
            "maxstr": maxstr,
        })

        
    data = {"name": choice_name, "choices": choices, "includes": sorted(includes), "extensible": extensible}
    safe_write(f"output/e2ap_{choice_name}.h", env.get_template("choice.h.j2").render(data))
    safe_write(f"output/e2ap_{choice_name}.c", env.get_template("choice.c.j2").render(data))

# =============================
# 2.5. SINH SingleContainer
# =============================
single_containers = types_df[types_df["ASN1_Type"] == "SingleContainer"]

for _, row in single_containers.iterrows():
    list_name   = row["Type_Name"].replace("-", "_")                                # E2nodeComponentConfigAddition_List
    item_ies    = row["IE_Type"]                                                    # E2nodeComponentConfigAddition_ItemIEs
    item_type   = item_ies#.replace("IEs", "")                                       # E2nodeComponentConfigAddition_Item
    ie_id       = row["Tag/ID"]                                                     # ID_id_E2nodeComponentConfigAddition
    criticality = row["Criticality"] if pd.notna(row["Criticality"]) else "reject"

    # Size constraint từ cột Min_Value / Max_Value (nếu có)
    min_size = int(row["Min_Value"]) if pd.notna(row["Min_Value"]) else 1
    max_val = row["Max_Value"] if pd.notna(row["Max_Value"]) else "256"
    if max_val in ["maxofE2nodeComponents", "maxofRANfunctionID", "256"]:
        max_size = 256
    elif max_val == "512":
        max_size = 512
    elif max_val == "1024":
        max_size = 1024
    else:
        max_size = int(max_val) if max_val.isdigit() else 256

    data = {
        "list_name":   list_name,
        "item_ies":    item_ies,
        "item_type":   item_type,
        "ie_id":       ie_id,
        "criticality": f"e2ap_Criticality_{criticality}",
        "min_size":    min_size,
        "max_size":    max_size,
    }

    # 1. Sinh ProtocolIE-SingleContainer (ItemIEs) – struct
    # safe_write(f"output/e2ap_{item_ies}.h",
    #            env.get_template("protocol_ie_single.h.j2").render(data))
    # safe_write(f"output/e2ap_{item_ies}.c",
    #            env.get_template("protocol_ie_single.c.j2").render(data))

    # 2. Sinh List: SEQUENCE (SIZE) OF ProtocolIE-SingleContainer<...>
    safe_write(f"output/e2ap_{list_name}.h",
               env.get_template("seq_of_single_container.h.j2").render(data))
    safe_write(f"output/e2ap_{list_name}.c",
               env.get_template("seq_of_single_container.c.j2").render(data))

    print(f"SingleContainer → {list_name} (uses {item_ies})")

# =============================
# SINH IE (Protocol-IES) – CHỈ CẦN TÌM DÒNG ASN1_Type == "IE" + IE_Type kết thúc bằng "IEs"
# =============================
# ie_rows = types_df[
#     (types_df["ASN1_Type"] == "IE") &
#     (types_df["IE_Type"].str.endswith("IEs") == False) &  # IE thật, không phải container
#     (types_df["Type_Name"].str.contains("ItemIEs"))       # chỉ lấy XXX-ItemIEs
# ]

# for _, row in ie_rows.iterrows():
#     ies_name    = row["Type_Name"].replace("-", "_")# + "IEs"   # E2nodeComponentConfigAddition_ItemIEs
#     item_type   = row["IE_Type"]                                # E2nodeComponentConfigAddition_Item
#     ie_id       = row["Tag/ID"]
#     criticality = row["Criticality"] if pd.notna(row["Criticality"]) else "reject"

#     data = {
#         "ies_name": ies_name,
#         #"item_type": item_type,
#         "choices": [{"item_type": item_type}],  
#         "ie_id": ie_id,
#         "criticality": f"e2ap_Criticality_{criticality}"
#     }

#     safe_write(f"output/e2ap_{ies_name}.h", env.get_template("ie.h.j2").render(data))
#     safe_write(f"output/e2ap_{ies_name}.c", env.get_template("ie.c.j2").render(data))
#     print(f"IE → e2ap_{ies_name}.h/c")
# Nhóm các dòng dữ liệu có "IE" theo `Type_Name`
# Nhóm các dòng dữ liệu có "IE" theo `Type_Name`
ie_rows = types_df[
    (types_df["ASN1_Type"] == "IE") &  # Kiểm tra ASN1_Type là "IE"
    (~types_df["IE_Type"].str.endswith("IEs")) #&  # Loại bỏ những "IEs"
    #(types_df["Type_Name"].str.contains("ItemIEs"))  # Chỉ lấy các Type_Name chứa "ItemIEs"
]

# Group các dòng theo `Type_Name` để gom tất cả các trường cùng một IE
for ies_name_raw, group in ie_rows.groupby("Type_Name"):
    ies_name = ies_name_raw.replace("-", "_")  # Chuyển "-" thành "_"
    choices = []

    # Lặp qua từng dòng trong nhóm IE để lấy tất cả các trường
    for _, row in group.iterrows():
        item_type = row["IE_Type"]
        field_name = row["Field_Name"]
        optional_val = row.get("Optional")
        presence = "optional" if (pd.notna(optional_val) and str(optional_val).strip() != "") else "mandatory"
      
        field_name = field_name.replace("-","_")

        # Thêm tất cả các trường vào choices
        choices.append({
            "item_type": item_type,
            "field_name": field_name,
            "presence": presence
        })

    # Lấy thông tin chung của `IE`
    ie_id = group.iloc[0]["Tag/ID"]
    criticality = group.iloc[0]["Criticality"] if pd.notna(group.iloc[0]["Criticality"]) else "reject"

    data = {
        "ies_name": ies_name,
        "choices": choices,  # Tất cả các trường được nhóm lại và xuất
        "ie_id": ie_id,
        "criticality": f"e2ap_Criticality_{criticality}"
    }

    # Tạo file header và source code cho `IE`
    safe_write(f"output/e2ap_{ies_name}.h", env.get_template("ie.h.j2").render(data))
    safe_write(f"output/e2ap_{ies_name}.c", env.get_template("ie.c.j2").render(data))
    print(f"IE → e2ap_{ies_name}.h/c ({len(choices)} fields)")


# =============================
# 4. SINH SEQUENCE (cả normal SEQUENCE và ProtocolIE-Container)
# =============================
sequence_rows = types_df[
    (types_df["ASN1_Type"] == "SEQUENCE") #| (types_df["ASN1_Type"] == "Container") |(types_df["ASN1_Type"] == "IE")  # một số SEQUENCE được định nghĩa dưới dạng IE cha
]

# Lấy danh sách các SEQUENCE cần sinh (dựa vào Type_Name duy nhất)
sequence_names = types_df[types_df["ASN1_Type"].isin(["SEQUENCE", "Container"])]["Type_Name"].unique()

for seq_name_raw in sequence_names:
    seq_name = seq_name_raw.replace('-', '_')

    # Tìm tất cả các IE con thuộc về SEQUENCE này
    # Điều kiện: Parent_Type == seq_name_raw HOẶC Type_Name == seq_name_raw (trường hợp SEQUENCE chính)
    child_rows = types_df[
        (types_df["Parent_Type"] == seq_name_raw) |
        ((types_df["Type_Name"] == seq_name_raw) & (types_df["ASN1_Type"] == "IE"))
    ]

    fields = []
    for _, row in child_rows.iterrows():
        field_name_raw = row["Field_Name"]
        if pd.isna(field_name_raw):
            continue

        field_name = field_name_raw.replace('-', '_')
        ie_type = row["IE_Type"]

        # Xác định presence: nếu cột Optional có giá trị (Yes/O, v.v.) → optional
        optional_val = row.get("Optional")
        presence = "optional" if (pd.notna(optional_val) and str(optional_val).strip() != "") else "mandatory"

        fields.append({
            "field": field_name,
            "ie_type": ie_type,
            "presence": presence,
        })
        
        field_name = field_name.replace("-","_")

    # Kiểm tra extensible
    extensible = False
    ext_row = types_df[types_df["Type_Name"] == seq_name_raw]
    if not ext_row.empty:
        ext_val = ext_row.iloc[0].get("Extensible")
        if pd.notna(ext_val) and str(ext_val).strip().lower() in ["yes", "true", "1"]:
            extensible = True

    # Nếu không có field nào → bỏ qua (tránh sinh file rỗng)
    if not fields and not extensible:
        print(f"Skip empty SEQUENCE: {seq_name}")
        continue

    data = {
        "name": seq_name,
        "fields": fields,
        "extensible": extensible
    }

    # Sinh file .h và .c dùng đúng template seq_normal
    safe_write(f"output/e2ap_{seq_name}.h",
               env.get_template("seq_normal.h.j2").render(data))
    safe_write(f"output/e2ap_{seq_name}.c",
               env.get_template("seq_normal.c.j2").render(data))

    print(f"SEQUENCE → e2ap_{seq_name}.h/c  ({len(fields)} fields, extensible={extensible})")
# =============================
# 5. SINH MESSAGE (E2SetupRequest, ...)
# =============================
message_df = df.get("Messages", pd.DataFrame())
for message_name, group in message_df.groupby("Message_Name"):
    message_name = message_name.replace('-', '_')
    message_name = message_name# +"element"
    ies, includes = [], set()
    for _, row in group.iterrows():
        ie_type = row["IE_Type"]
        field_name = row["Field_Name"]
        origin_name = row["Original_IE_Name"]
        critical = row["Critical"]
        presence = row["Presence"]
        ie_id = row["IE_ID_Constant"]
        includes.add(f"e2ap_{ie_type}")
        #ies.append({"ie_type": ie_type, "field": field_name, "ie_id_constant": ie_id})
        ies.append({
            "ie_type": ie_type,
            "field": field_name,
            "ie_id_constant": ie_id,
            "origin_name": origin_name,   # <-- thêm dòng này
            "critical": critical,
            "presence": presence,
        })

        field_name = field_name.replace("-","_")

    data = {"message_name": message_name, "ies": ies, "includes": sorted(includes)}
    safe_write(f"output/e2ap_{message_name+"_protocolIEs_element"}.h", env.get_template("message.h.j2").render(data))
    safe_write(f"output/e2ap_{message_name+"_protocolIEs_element"}.c", env.get_template("message.c.j2").render(data))

print("=== TẤT CẢ ĐÃ HOÀN TẤT ===")