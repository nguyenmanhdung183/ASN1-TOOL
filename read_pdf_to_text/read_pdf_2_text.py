# -*- coding: utf-8 -*-
"""
Tool trích xuất ASN.1 sạch từ file PDF O-RAN E2AP (v07.00)
→ Giữ nguyên toàn bộ định dạng và chỉ loại bỏ header/footer.
"""

import re
from pypdf import PdfReader

PDF_PATH = "O-RAN_E2AP.WG3.TS.E2AP-R004-v07.00.pdf"
OUTPUT_TXT = "E2AP_ASN1_v07.00_clean_raw.txt"

reader = PdfReader(PDF_PATH)


raw_text = ""
for page_num in range(103, 156):  
    text = reader.pages[page_num].extract_text()
    if text:
        raw_text += text + "\n" 

lines = raw_text.splitlines()

# Các pattern cần lọc bỏ 
garbage_patterns = [
    r"^O-RAN\.WG3\.TS\.E2AP-R004-v07\.00",  # Header tài liệu
    r"© \d{4} by the O-RAN ALLIANCE",  # Bản quyền O-RAN
    r"© \d{4}\. 3GPP",  # Bản quyền 3GPP
    r"^Page \d+ of \d+$",  # Số trang
    r"^\d+$",  # Dòng chỉ chứa số (số trang hoặc mục)
    r"^Figure ",  # Các hình vẽ
    r"^Table ",  # Các bảng
    r"^\s*List of figures",  # Danh sách hình vẽ
    r"^\s*List of tables",  # Danh sách bảng
    r"^\s*Contents",  # Mục lục
    r"^Technical Specification",  # Tiêu đề phần kỹ thuật
]

asn1_lines = []

for line in lines:
    stripped = line.strip()

    # Loại bỏ các dòng rác
    if any(re.match(pat, stripped) for pat in garbage_patterns):
        continue

    # Giữ lại dòng trống
    if stripped == "":
        asn1_lines.append("")
        continue

    # Nếu dòng có nội dung ASN.1 thì giữ nguyên
    asn1_lines.append(line)

# Ghi lại toàn bộ văn bản vào file txt
with open(OUTPUT_TXT, "w", encoding="utf-8") as f:
    for field in asn1_lines:
        f.write(field + "\n")

print(f"Hoàn tất! Đã trích xuất nội dung và lưu vào {OUTPUT_TXT}")




def remove_blank_lines_inside_braces_v2(input_file, output_file=None):
    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    result_lines = []
    brace_level = 0 

    for line in lines:
        stripped_line = line.strip()

        # Đếm số dấu { và } trong dòng
        open_braces = line.count('{')
        close_braces = line.count('}')

        # Cập nhật mức độ lồng ngoặc trước khi xử lý dòng trống
        brace_level += open_braces

        # Nếu đang trong ngoặc (brace_level > 0) và dòng trống, bỏ qua
        if brace_level > 0 and stripped_line == '':
            # Cập nhật mức độ lồng ngoặc tiếp cho trường hợp dòng trống có dấu }
            brace_level -= close_braces
            continue

        result_lines.append(line)

        # Cập nhật mức độ lồng ngoặc sau khi xử lý dòng (để xử lý đúng trường hợp đóng ngoặc trong dòng)
        brace_level -= close_braces

    out_file = output_file if output_file else input_file
    with open(out_file, 'w', encoding='utf-8') as f:
        f.writelines(result_lines)

# Ví dụ gọi hàm
remove_blank_lines_inside_braces_v2('E2AP_ASN1_v07.00_clean_raw.txt', 'E2AP_ASN1_v07.00_clean.txt')


# def fix_e2ap_protocol_ies_v1(input_file, output_file=None):
#     with open(input_file, "r", encoding="utf-8") as f:
#         lines = f.readlines()

#     result = []
#     in_ies_block = False
#     collecting_item = False
#     current_item_lines = []

#     # Regex: bắt đầu item
#     item_start_re = re.compile(r'^\s*\{\s*ID\b')

#     # Regex: kết thúc item
#     item_end_re = re.compile(r'\}\s*[\|,]?$')

#     for line in lines:
#         stripped = line.strip()

#         # Phát hiện dòng bắt đầu block E2AP-PROTOCOL-IES
#         if "E2AP-PROTOCOL-IES ::=" in line and "{" in line:
#             in_ies_block = True
#             result.append(line)
#             continue

#         # Nếu đang bên trong block
#         if in_ies_block:

#             # Nếu đóng block => flush item còn lại
#             if stripped == "}":
#                 if collecting_item and current_item_lines:
#                     merged = " ".join(l.strip() for l in current_item_lines)
#                     result.append(" " + merged + "\n")
#                     collecting_item = False
#                     current_item_lines = []

#                 result.append(line)
#                 in_ies_block = False
#                 continue

#             # Nếu là dòng bắt đầu item
#             if item_start_re.match(line):
#                 # Nếu đang thu item cũ => flush trước
#                 if collecting_item and current_item_lines:
#                     merged = " ".join(l.strip() for l in current_item_lines)
#                     result.append(" " + merged + "\n")
#                     current_item_lines = []

#                 collecting_item = True
#                 current_item_lines.append(line)
#                 continue

#             # Nếu đang gom item
#             if collecting_item:
#                 current_item_lines.append(line)

#                 # Nếu dòng này kết thúc item
#                 if item_end_re.search(stripped):
#                     merged = " ".join(l.strip() for l in current_item_lines)
#                     result.append(" " + merged + "\n")
#                     collecting_item = False
#                     current_item_lines = []

#                 continue

#             # Các dòng khác trong block
#             result.append(line)
#             continue

#         # Ngoài block IEs → ghi nguyên xi
#         result.append(line)

#     # Ghi ra file
#     out_file = output_file if output_file else input_file
#     with open(out_file, "w", encoding="utf-8") as f:
#         f.writelines(result)

import re

def fix_e2ap_protocol_ies_v1(input_file, output_file=None):
    """
    Sửa block E2AP-PROTOCOL-IES trong file ASN.1:
    - Gộp các dòng item bị cắt do PDF xuống dòng (E2nodeComponentConfigAddition- Item -> E2nodeComponentConfigAddition-Item)
    - Giữ nguyên định dạng ASN.1, không sinh khoảng trắng thừa
    """
    with open(input_file, "r", encoding="utf-8") as f:
        lines = f.readlines()

    result = []
    in_ies_block = False
    collecting_item = False
    current_item_lines = []

    # Regex: bắt đầu item
    item_start_re = re.compile(r'^\s*\{\s*ID\b')

    # Regex: kết thúc item
    item_end_re = re.compile(r'\}\s*[\|,]?$')

    for line in lines:
        stripped = line.strip()

        # Phát hiện block E2AP-PROTOCOL-IES
        if "E2AP-PROTOCOL-IES ::=" in line and "{" in line:
            in_ies_block = True
            result.append(line)
            continue

        if in_ies_block:
            # Nếu đóng block => flush item còn lại
            if stripped == "}":
                if collecting_item and current_item_lines:
                    # Gộp các dòng PDF bị cắt '-'
                    buffer = ""
                    for l in current_item_lines:
                        l_strip = l.strip()
                        if buffer.endswith("-"):
                            buffer += l_strip
                        else:
                            if buffer:
                                buffer += " " + l_strip
                            else:
                                buffer = l_strip
                    result.append(" " + buffer + "\n")
                    collecting_item = False
                    current_item_lines = []

                result.append(line)
                in_ies_block = False
                continue

            # Nếu là dòng bắt đầu item
            if item_start_re.match(line):
                if collecting_item and current_item_lines:
                    # flush item cũ
                    buffer = ""
                    for l in current_item_lines:
                        l_strip = l.strip()
                        if buffer.endswith("-"):
                            buffer += l_strip
                        else:
                            if buffer:
                                buffer += " " + l_strip
                            else:
                                buffer = l_strip
                    result.append(" " + buffer + "\n")
                    current_item_lines = []

                collecting_item = True
                current_item_lines.append(line)
                continue

            # Nếu đang gom item
            if collecting_item:
                current_item_lines.append(line)
                # Nếu dòng này kết thúc item
                if item_end_re.search(stripped):
                    buffer = ""
                    for l in current_item_lines:
                        l_strip = l.strip()
                        if buffer.endswith("-"):
                            buffer += l_strip
                        else:
                            if buffer:
                                buffer += " " + l_strip
                            else:
                                buffer = l_strip
                    result.append(" " + buffer + "\n")
                    collecting_item = False
                    current_item_lines = []
                continue

            # Các dòng khác trong block
            result.append(line)
            continue

        # Ngoài block IEs → ghi nguyên xi
        result.append(line)

    # Ghi ra file
    out_file = output_file if output_file else input_file
    with open(out_file, "w", encoding="utf-8") as f:
        f.writelines(result)

    print(f"[INFO] Đã xử lý block E2AP-PROTOCOL-IES và lưu vào {out_file}")


fix_e2ap_protocol_ies_v1("E2AP_ASN1_v07.00_clean.txt",
                         "E2AP_ASN1_v07.00_formated.txt")


#=================
def fix_sequence_linebreaks(input_file, output_file=None):
    with open(input_file, "r", encoding="utf-8") as f:
        lines = f.readlines()

    result = []
    i = 0
    n = len(lines)

    # -------------------------
    # STEP 1: SEQUENCE OF SingleContainer -> 1 line
    # -------------------------
    while i < n:
        line = lines[i]
        stripped = line.strip()

        # Dòng trống ngoài block -> giữ nguyên
        if not stripped:
            result.append(line)
            i += 1
            continue

        # Nếu dòng chứa SEQUENCE
        if "SEQUENCE" in line:
            # Look ahead trong vài dòng để phát hiện SingleContainer
            look_ahead = [lines[j].strip() for j in range(i, min(i + 2, n))]
            if any("SingleContainer" in l for l in look_ahead):
                # Gom block { … } thành 1 dòng
                current = line.rstrip("\n")
                brace_level = line.count("{") - line.count("}")
                i += 1
                while brace_level > 0 and i < n:
                    l = lines[i].rstrip("\n")
                    # Cập nhật brace level
                    brace_level += l.count("{") - l.count("}")
                    # Chỉ nối nếu dòng không chỉ trống
                    if l.strip():
                        current += " " + l.strip()
                    i += 1
                result.append(current + "\n")
                continue

        # Không phải SEQUENCE OF SingleContainer -> giữ nguyên
        result.append(line)
        i += 1

    # -------------------------
    # STEP 2: SEQUENCE bình thường -> nối continuation lines
    # -------------------------
    temp_lines = result
    result = []
    current = ""
    in_sequence = False

    def is_new_field(line):
        """Field ASN.1 chuẩn: <identifier>  <type> ..."""
        return re.match(r'^[A-Za-z][A-Za-z0-9-]*\s{2,}', line.strip())

    for line in temp_lines:
        stripped = line.strip()

        # Dòng trống ngoài SEQUENCE -> giữ nguyên
        if not stripped and not in_sequence:
            result.append(line)
            continue

        # Bắt đầu SEQUENCE bình thường (không SingleContainer)
        if "SEQUENCE" in line and "{" in line and "SingleContainer" not in line:
            in_sequence = True
            result.append(line)
            continue

        # Kết thúc SEQUENCE
        if in_sequence and stripped == "}":
            if current:
                result.append(current + "\n")
                current = ""
            result.append(line)
            in_sequence = False
            continue

        if in_sequence:
            # Nếu chưa có field -> khởi tạo
            if not current:
                current = line.rstrip("\n")
                continue

            # continuation line (dòng tách PDF)
            if not is_new_field(stripped) and not stripped.startswith("}") and not current.rstrip().endswith((",", ")", "}")):
                current += " " + stripped
                continue

            # field mới -> flush field cũ
            result.append(current + "\n")
            current = line.rstrip("\n")
            continue

        # Ngoài SEQUENCE
        result.append(line)

    # Flush field cuối nếu còn
    if current:
        result.append(current + "\n")

    # Ghi ra file
    out_file = output_file if output_file else input_file
    with open(out_file, "w", encoding="utf-8") as f:
        f.writelines(result)
        
        
        
fix_sequence_linebreaks("E2AP_ASN1_v07.00_formated.txt",
                         "E2AP_ASN1_v07.00_final.txt")






def merge_sequence_singlecontainer(input_file, output_file=None):
    """
    Gom các block SEQUENCE thành 1 dòng nếu:
    - Dòng hiện tại chứa SEQUENCE
    - Dòng kế tiếp không phải dòng trống
    - Dòng hiện tại hoặc dòng kế tiếp chứa SingleContainer
    Nối toàn bộ block đến hết dấu { ... } hoặc dòng kết thúc không phải "-"
    """
    with open(input_file, "r", encoding="utf-8") as f:
        lines = f.readlines()

    merged_lines = []
    i = 0
    n = len(lines)

    while i < n:
        line = lines[i].rstrip("\n")
        stripped = line.strip()

        # Lấy dòng tiếp theo
        next_line = lines[i+1].rstrip("\n") if i + 1 < n else ""
        next_line_not_empty = next_line.strip() != ""

        # Kiểm tra điều kiện gộp
        cond_sequence = "SEQUENCE" in line
        cond_single = "SingleContainer" in line or "SingleContainer" in next_line

        if cond_sequence and next_line_not_empty and cond_single:
            # Bắt đầu gom block
            current = line
            brace_level = current.count("{") - current.count("}")

            i += 1
            while i < n and (brace_level > 0 or current.rstrip().endswith("-")):
                l = lines[i].strip()
                if l:  # bỏ dòng trống
                    # Nếu dòng trước kết thúc bằng "-", nối liền không thêm space
                    if current.rstrip().endswith("-"):
                        current = current.rstrip() + l.lstrip()
                    else:
                        current += " " + l
                    brace_level += l.count("{") - l.count("}")
                i += 1

            merged_lines.append(current + "\n")
        else:
            merged_lines.append(line + "\n")
            i += 1

    # Ghi ra file
    out_file = output_file if output_file else input_file
    with open(out_file, "w", encoding="utf-8") as f:
        f.writelines(merged_lines)

        
merge_sequence_singlecontainer("E2AP_ASN1_v07.00_final.txt",
                               "E2AP_ASN1_v07.00_final.txt")


import re

def replace_braces_inline_only(input_file, output_file=None):
    """
    Thay thế { { -> {{ và } } -> }} chỉ khi cả hai dấu ngoặc nằm trên cùng 1 dòng.
    """
    with open(input_file, "r", encoding="utf-8") as f:
        lines = f.readlines()

    new_lines = []
    for line in lines:
        # Thay { { -> {{
        line = re.sub(r'\{\s+\{', '{{', line)
        # Thay } } -> }}
        line = re.sub(r'\}\s+\}', '}}', line)
        new_lines.append(line)

    out_file = output_file if output_file else input_file
    with open(out_file, "w", encoding="utf-8") as f:
        f.writelines(new_lines)

replace_braces_inline_only("E2AP_ASN1_v07.00_final.txt",
                          "E2AP_ASN1_v07.00_final.txt")

def fix_spacing_inside_double_braces(input_file, output_file=None):
    """
    Trong {{ ... }}:
    - Nếu có duy nhất 1 dấu cách giữa 2 ký tự -> xoá
    - Nếu có >=2 dấu cách -> giữ nguyên
    """

    pattern = re.compile(r"\{\{(.*?)\}\}")

    def fix_content(content):
        # Chỉ xoá spacing 1 dấu giữa hai ký tự
        return re.sub(r"([A-Za-z0-9\-]) ([A-Za-z0-9])", r"\1\2", content)

    with open(input_file, "r", encoding="utf-8") as f:
        text = f.read()

    def replace(match):
        inner = match.group(1)
        fixed_inner = fix_content(inner)
        return "{{" + fixed_inner + "}}"

    fixed_text = pattern.sub(replace, text)

    out_file = output_file if output_file else input_file
    with open(out_file, "w", encoding="utf-8") as f:
        f.write(fixed_text)

    print(f"[OK] Fixed spacing inside {{}} → {out_file}")

fix_spacing_inside_double_braces("E2AP_ASN1_v07.00_final.txt",
                                 "E2AP_ASN1_v07.00_final.txt")    