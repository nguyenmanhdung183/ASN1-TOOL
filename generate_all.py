# generate_all.py
import pandas as pd
from jinja2 import Template
import os

# Đọc Excel
df = pd.read_excel("data_e2setup.xlsx")

# Tạo thư mục output
os.makedirs("output", exist_ok=True)

for _, row in df.iterrows():
    name = row["IE_Name"]
    asn_type = row["ASN1_Type"]
    template_dir = "templates"

    # Xác định số bits dựa theo giá trị Max (dùng chung cho cả ext / no ext)
    maxv = row["Max"]
    if maxv <= 255:
        bits = 8
    elif maxv <= 65535:
        bits = 16
    else:
        bits = 32

    # =============================
    # INTEGER có extension (...)
    # =============================
    if "INTEGER" in asn_type and "..." in asn_type:
        with open(f"{template_dir}/integer_with_ext.h.j2") as f:
            h_tmpl = Template(f.read())
        with open(f"{template_dir}/integer_with_ext.c.j2") as f:
            c_tmpl = Template(f.read())

        data = {
            "name": name,
            "min_root": row["Min"],
            "max_root": row["Max"],
            "type": (
                "OSUINT8" if bits == 8 else
                ("OSUINT16" if bits == 16 else "OSUINT32")
            )
        }

    # =============================
    # INTEGER không extension
    # =============================
    elif "INTEGER" in asn_type:
        with open(f"{template_dir}/integer_no_ext.h.j2") as f:
            h_tmpl = Template(f.read())
        with open(f"{template_dir}/integer_no_ext.c.j2") as f:
            c_tmpl = Template(f.read())

        data = {
            "name": name,
            "min": row["Min"],
            "max": row["Max"],
            "bits": bits,
            "type": (
                "OSUINT8" if bits == 8 else
                ("OSUINT16" if bits == 16 else "OSUINT32")
            )
        }


    elif "ENUMERATED" in asn_type:
        # ENUMERATED
        items = eval(row["Enum_Items"])  # [(0, "report", "report"), ...]
        with open(f"{template_dir}/enumerated.h.j2") as f:
            h_tmpl = Template(f.read())
        with open(f"{template_dir}/enumerated.c.j2") as f:
            c_tmpl = Template(f.read())

        data = {"name": name, "items": [{"value": v, "name": n, "string": s} for v, n, s in items]}

    else:
        continue

    # Ghi file
    with open(f"output/e2ap_{name}.h", "w", encoding="utf-8") as f:
        f.write(h_tmpl.render(data))
    with open(f"output/e2ap_{name}.c", "w", encoding="utf-8") as f:
        f.write(c_tmpl.render(data))

    print(f"Generated: e2ap_{name}.h/c")