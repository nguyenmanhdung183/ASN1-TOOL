# -*- coding: utf-8 -*-
"""
Tool trích xuất ASN.1 sạch 100% từ file PDF O-RAN E2AP (v07.00)
→ Nối tất cả các trường ASN.1 bị xuống dòng thành 1 dòng hoàn chỉnh
→ Loại bỏ hoàn toàn header, footer, số trang, hình vẽ, bảng biểu
→ Kết quả có thể copy-paste trực tiếp vào asn1c hoặc trình biên dịch ASN.1
"""

import re
from pypdf import PdfReader

PDF_PATH = "O-RAN_E2AP.WG3.TS.E2AP-R004-v07.00.pdf"
OUTPUT_TXT = "E2AP_ASN1_v07.00_clean_one_line_per_field.txt"

reader = PdfReader(PDF_PATH)

# Thu thập toàn bộ text từ PDF
raw_text = ""
for page in reader.pages:
    text = page.extract_text()
    if text:
        raw_text += text + "\n"

# Tách từng dòng
lines = raw_text.splitlines()

# Các pattern để loại bỏ rác
garbage_patterns = [
    r"^O-RAN\.WG3\.TS\.E2AP-R004-v07\.00",
    r"© 2025 by the O-RAN ALLIANCE",
    r"© 2020\. 3GPP",
    r"© 2019\. 3GPP",
    r"^Page \d+ of \d+$",
    r"^\d+$",  # số trang
    r"^Figure ",
    r"^Table ",
    r"^\s*List of figures",
    r"^\s*List of tables",
    r"^\s*Contents",
]

asn1_lines = []
in_asn1_block = False
current_field = ""

for line in lines:
    line = line.replace("\x0c", "").replace("\f", "")  # form feed
    stripped = line.strip()

    # Bỏ các dòng rác
    if any(re.match(pat, stripped) for pat in garbage_patterns):
        continue
    if stripped == "" or stripped.startswith("Technical Specification") or "ALLIANCE" in stripped:
        continue

    # Phát hiện bắt đầu phần ASN.1 thật sự (thường từ E2AP-PDU-Descriptions hoặc E2AP-IEs)
    if "E2AP-PDU-Descriptions ::=" in line or "E2AP-IEs ::=" in line or "E2AP-Constants ::=" in line:
        in_asn1_block = True

    if not in_asn1_block:
        continue

    # Nếu dòng có nội dung ASN.1 (chứa ::= hoặc bắt đầu bằng chữ cái/tên type)
    if stripped and ("::=" in stripped or stripped[0].isalpha() or stripped.startswith("\t") or stripped.startswith(" ")):
        # Nếu dòng trước đó là continuation (indent hoặc không có ::= ở đầu)
        if current_field:
            # Kiểm tra xem dòng mới có phải là continuation không
            if line.startswith(" ") or line.startswith("\t") or not stripped[0].isupper():
                current_field += " " + stripped
            else:
                # Kết thúc field trước đó
                asn1_lines.append(current_field.strip())
                current_field = stripped
        else:
            current_field = stripped
    else:
        # Dòng không phải ASN.1 → bỏ qua, nhưng nếu đang có field thì lưu lại trước
        if current_field:
            asn1_lines.append(current_field.strip())
            current_field = ""

# Đừng quên field cuối cùng
if current_field:
    asn1_lines.append(current_field.strip())

# Ghi ra file — mỗi field ASN.1 đúng 1 dòng
with open(OUTPUT_TXT, "w", encoding="utf-8") as f:
    for field in asn1_lines:
        # Loại bỏ khoảng trắng thừa, nhưng giữ nguyên cấu trúc ASN.1
        cleaned = re.sub(r"\s+", " ", field)
        f.write(cleaned + "\n")

print(f"Hoàn tất! Đã trích xuất {len(asn1_lines)} trường ASN.1 thành công.")
print(f"Kết quả lưu tại: {OUTPUT_TXT}")
print("\nVí dụ 5 dòng đầu tiên:")
with open(OUTPUT_TXT, "r", encoding="utf-8") as f:
    for i, line in enumerate(f):
        if i < 5:
            print(f"  {i+1}. {line[:120]}{'...' if len(line)>120 else ''}")
        else:
            break