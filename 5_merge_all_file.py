import os
import glob

OUTPUT_DIR = "output"
MERGED_DIR = "merged_output"
MAIN_C_FILE = "output_main.c"
MAIN_H_FILE = "output_main.h"
PREFIX = "e2ap_"

text_to_insert_c_header ="#include \"output_main.h\""
text_to_insert_h_header ="""
#ifndef OUTPUT_MAIN_H
#define OUTPUT_MAIN_H
"""
text_to_insert_h_foter ="#endif"


def add_protocol_files_to_main(c_out, h_out):
    """
    Hàm nối các file có đuôi protocolIEs.h, protocolIEs.c, protocolIEs_element.h, và protocolIEs_element.c vào cuối
    các file output_main.c và output_main.h.
    """
    # Định nghĩa các đuôi file cần nối
    protocol_file_patterns = [
        "*protocolIEs_element.h", "*protocolIEs_element.c",
        "*protocolIEs.h", "*protocolIEs.c"
    ]
    
    # Lấy danh sách tất cả các file khớp với các đuôi trên trong OUTPUT_DIR
    all_protocol_files = []
    for pattern in protocol_file_patterns:
        all_protocol_files.extend(glob.glob(os.path.join(OUTPUT_DIR, pattern)))

    # Nối các file .c và .h vào các file chính
    for file in all_protocol_files:
        file_base = os.path.basename(file)
        
        if file_base.endswith(".c"):
            with open(file, "r", encoding="utf-8") as cf:
                c_out.write(f"// --- Begin of {file_base} ---\n")
                c_out.write(cf.read())  # Nối nội dung của file .c
                c_out.write(f"\n// --- End of {file_base} ---\n\n")
        
        elif file_base.endswith(".h"):
            with open(file, "r", encoding="utf-8") as hf:
                h_out.write(f"// --- Begin of {file_base} ---\n")
                h_out.write(hf.read())  # Nối nội dung của file .h
                h_out.write(f"\n// --- End of {file_base} ---\n\n")



def rectangular_comment(text):
    lines = text.split("\n")
    width = max(len(line) for line in lines)
    border = "/" + "*" * (width + 4) + "/"
    comment_lines = [border]
    for line in lines:
        comment_lines.append(f"/* {line.ljust(width)} */")
    comment_lines.append(border)
    return "\n".join(comment_lines) + "\n\n"

def main():
    os.makedirs(MERGED_DIR, exist_ok=True)

    leaf_files = glob.glob("Tool_read_pdf/*_bottomup_leaf.txt")
    if not leaf_files:
        print("Không tìm thấy file *_bottomup_leaf.txt nào!")
        return

    all_parts = []
    for leaf_file in leaf_files:
        with open(leaf_file, "r", encoding="utf-8") as f:
            for line in f:
                part = line.strip()
                if part and part not in all_parts:
                    all_parts.append(part)

    c_out_path = os.path.join(MERGED_DIR, MAIN_C_FILE)
    h_out_path = os.path.join(MERGED_DIR, MAIN_H_FILE)

    with open(c_out_path, "w", encoding="utf-8") as c_out, open(h_out_path, "w", encoding="utf-8") as h_out:
    
        #-----------------
        c_out.write(text_to_insert_c_header + "\n")
        h_out.write(text_to_insert_h_header + "\n")
        
        # ======================================================
        # THÊM: Ghi doc/header.c và doc/header.h vào đầu file
        # ======================================================
        header_c_path = "doc/header.c"
        header_h_path = "doc/header.h"

        if os.path.isfile(header_c_path):
            with open(header_c_path, "r", encoding="utf-8") as hcf:
                c_out.write("// --- Begin of doc/header.c ---\n")
                c_out.write(hcf.read())
                c_out.write("\n// --- End of doc/header.c ---\n\n")
        else:
            c_out.write(rectangular_comment("Missing: doc/header.c"))

        if os.path.isfile(header_h_path):
            with open(header_h_path, "r", encoding="utf-8") as hhf:
                h_out.write("// --- Begin of doc/header.h ---\n")
                h_out.write(hhf.read())
                h_out.write("\n// --- End of doc/header.h ---\n\n")
        else:
            h_out.write(rectangular_comment("Missing: doc/header.h"))
        # ======================================================
            
        
        
        for part in all_parts:
            part_file_base = PREFIX + part.replace("-", "_")

            c_path = os.path.join(OUTPUT_DIR, part_file_base + ".c")
            h_path = os.path.join(OUTPUT_DIR, part_file_base + ".h")

            if os.path.isfile(c_path):
                with open(c_path, "r", encoding="utf-8") as cf:
                    c_out.write(f"// --- Begin of {part_file_base}.c ---\n")
                    c_out.write(cf.read())
                    c_out.write(f"\n// --- End of {part_file_base}.c ---\n\n")
            else:
                comment = rectangular_comment(f"File .c missing: {part_file_base}.c")
                c_out.write(comment)

            if os.path.isfile(h_path):
                with open(h_path, "r", encoding="utf-8") as hf:
                    h_out.write(f"// --- Begin of {part_file_base}.h ---\n")
                    h_out.write(hf.read())
                    h_out.write(f"\n// --- End of {part_file_base}.h ---\n\n")
            else:
                comment = rectangular_comment(f"File .h missing: {part_file_base}.h")
                h_out.write(comment)
#------------------------
        add_protocol_files_to_main(c_out, h_out)

        h_out.write(text_to_insert_h_foter + "\n")
        
    print(f"Đã tạo file {c_out_path} và {h_out_path} trong thư mục {MERGED_DIR}")

if __name__ == "__main__":
    main()
