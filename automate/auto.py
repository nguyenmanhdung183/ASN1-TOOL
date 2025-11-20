import os
import shutil
import time
import glob
import pandas as pd

filepath = "list.txt"

clean_path = "clean.bat"
quick_path = "quick.bat"

# ====== ĐÚNG YÊU CẦU ======
ALL_LEAF_PATH = "./all_bottomup_leaf.txt"     # nằm trong automate
FULL_MESSAGE_DIR = "../full_message"          # đúng vị trí bên ngoài
OUTPUT_E2AP_H = "./E2AP.h"                    # nằm trong automate
OUTPUT_E2AP_C = "./E2AP.c"                    # nằm trong automate



start_time = time.time()

# Xóa file all_bottomup_leaf.txt cũ nếu có
if os.path.exists(ALL_LEAF_PATH):
    os.remove(ALL_LEAF_PATH)

with open(filepath, 'r') as file:
    lines = file.readlines()

#xoá nội dung file E2AP.h và E2AP.c cũ nếu có
if os.path.exists(OUTPUT_E2AP_H):
    os.remove(OUTPUT_E2AP_H)
if os.path.exists(OUTPUT_E2AP_C):
    os.remove(OUTPUT_E2AP_C)
    

# =====================================================
# VÒNG LẶP CHÍNH
# =====================================================

for line in lines:
    line = line.strip()
    print(line)

    # --- Ghi file config ---
    file_path_config = "../msg.config"
    with open(file_path_config, 'w') as config_file:
        config_file.write(line + '\n')
        config_file.write('read_pdf_to_text/E2AP_ASN1_v07.00_final.txt')

    # --- Chạy clean và quick ---
    os.chdir("..")
    os.system(clean_path)
    os.system(quick_path)

    # --- Copy thư mục output và merger_output ---
    src_output = "output"
    src_merger = "merged_output"

    dst_folder = f"full_message/{line}"
    dst_output = f"{dst_folder}/output_{line}"
    dst_merger = f"{dst_folder}/merger_output_{line}"

    os.makedirs(dst_folder, exist_ok=True)

    if os.path.exists(src_output):
        shutil.copytree(src_output, dst_output, dirs_exist_ok=True)
        print(f"Copied {src_output} -> {dst_output}")
    else:
        print(f"{src_output} does not exist.")

    if os.path.exists(src_merger):
        shutil.copytree(src_merger, dst_merger, dirs_exist_ok=True)
        print(f"Copied {src_merger} -> {dst_merger}")
    else:
        print(f"{src_merger} does not exist.")

    # ---------------------------
    # THÊM: GOM LEAF → all_bottomup_leaf.txt
    # ---------------------------
    # chuyển về automate để path chính xác
    os.chdir("automate")

    leaf_files = glob.glob("../Tool_read_pdf/*bottomup_leaf.txt")

    with open(ALL_LEAF_PATH, "a", encoding="utf-8") as out_leaf:
        for lf in leaf_files:
            with open(lf, "r", encoding="utf-8") as f:
                out_leaf.write(f.read())

# =====================================================
# XỬ LÝ SAU KHI CHẠY XONG TẤT CẢ VÒNG LẶP
# =====================================================

print("\n=== Filtering unique leaf entries ===")

unique_fields = []
if os.path.exists(ALL_LEAF_PATH):
    with open(ALL_LEAF_PATH, "r", encoding="utf-8") as f:
        for line in f:
            field = line.strip()
            if field and field not in unique_fields:
                unique_fields.append(field)

print(f"Total unique fields: {len(unique_fields)}")

# =====================================================
# GHÉP FILE C/H THEO DANH SÁCH UNIQUE FIELD
# =====================================================

with open(OUTPUT_E2AP_H, "w", encoding="utf-8") as out_h, \
     open(OUTPUT_E2AP_C, "w", encoding="utf-8") as out_c:

    out_h.write("#ifndef E2AP_H\n#define E2AP_H\n\n")
    out_c.write('#include "E2AP.h"\n\n')

    # ===== THÊM HEADER_E2AP.h VÀ HEADER_E2AP.c LÊN ĐẦU =====
    header_h = "./HEADER_E2AP.h"
    header_c = "./HEADER_E2AP.c"

    if os.path.exists(header_h):
        with open(header_h, "r", encoding="utf-8") as hf:
            out_h.write("// ==== Begin HEADER_E2AP.h ====\n")
            out_h.write(hf.read())
            out_h.write("\n// ==== End HEADER_E2AP.h ====\n\n")
    else:
        print("⚠ HEADER_E2AP.h không tồn tại")

    if os.path.exists(header_c):
        with open(header_c, "r", encoding="utf-8") as cf:
            out_c.write("// ==== Begin HEADER_E2AP.c ====\n")
            out_c.write(cf.read())
            out_c.write("\n// ==== End HEADER_E2AP.c ====\n\n")
    else:
        print("⚠ HEADER_E2AP.c không tồn tại")
    # =========================================================

    # ===== Merge các file c/h theo unique_fields =====
    for field in unique_fields:
        filename_base = field.replace("-", "_")
        found = False

        # duyệt từng thư mục message trong full_message
        for msg_folder in os.listdir(FULL_MESSAGE_DIR):
            msg_path = os.path.join(FULL_MESSAGE_DIR, msg_folder)
            if not os.path.isdir(msg_path):
                continue

            # duyệt tất cả thư mục con
            for root, _, files in os.walk(msg_path):
                for f in files:
                    if f == "e2ap_" + filename_base + ".h":
                        full_path = os.path.join(root, f)
                        with open(full_path, "r", encoding="utf-8") as ff:
                            out_h.write(f"\n// ---- Begin {f} ----\n")
                            out_h.write(ff.read())
                            out_h.write(f"\n// ---- End {f} ----\n")
                        found = True

                    elif f == "e2ap_" + filename_base + ".c":
                        full_path = os.path.join(root, f)
                        with open(full_path, "r", encoding="utf-8") as ff:
                            out_c.write(f"\n// ---- Begin {f} ----\n")
                            out_c.write(ff.read())
                            out_c.write(f"\n// ---- End {f} ----\n")
                        found = True

        if not found:
            print(f"--->Không tìm thấy file cho field: {field}")

    out_h.write("\n#endif // E2AP_H\n")

print("\n=== E2AP.h / E2AP.c generated successfully ===")



end_time = time.time()
print(f"generate for {len(lines)} msg done in {end_time - start_time} seconds\n")
