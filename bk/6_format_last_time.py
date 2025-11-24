import os
# thay đổi định dạng của asn1PE_ASN1BitStr32, asn1PD_ASN1BitStr32 thành pe_BitString32, pd_BitString32
# và asn1Init_ASN1BitStr32 thành //asn1Init_ASN
# và asn1Free_ASN1BitStr32 thành //asn1Free_ASN
# trong tất cả các file .c và .h trong thư mục merged_output và output




# --- Quy tắc cũ -> đổi 2 chuỗi ---
STRING_A = "e2ap_BIT STRING"
STRING_B = "ASN1BitStr32"

# --- Quy tắc mới ---
REPLACEMENTS_EXTRA = {
    "asn1PE_ASN1BitStr32": "pe_BitString32",
    "asn1PD_ASN1BitStr32": "pd_BitString32",
    "asn1Init_ASN1BitStr32": "//asn1Init_ASN1BitStr32",
    "asn1Free_ASN1BitStr32": "//asn1Free_ASN1BitStr32",
    "ASN1V_e2ap_maxofTNLA": "32",
    "ASN1V_e2ap_maxnoofErrors": "256",
    "ASN1V_e2ap_maxofE2nodeComponents": "1024",
    "ASN1V_e2ap_maxofRANfunctionID": "256",
    "ASN1V_e2ap_maxofRICactionID": "16",
    "ASN1V_e2ap_maxofTNLA": "32",
    "ASN1V_e2ap_maxofRICrequestID": "1024",
    "ASN1V_e2ap_maxofRICsubscriptions": "2147483648",
    "asn1PrtToStr_ASN1BitStr32":"rtPrintToStringOpenTypeExtBraceText"
}

TARGET_DIRS = ["merged_output", "output"]
EXTENSIONS = [".c", ".h"]


# ---------------------------------------------------------
# HÀM 1: xử lý quy tắc cũ
# ---------------------------------------------------------
def replace_old_rule(content, filepath):
    new_content = content.replace(STRING_A, STRING_B)
    if new_content != content:
        print(f"[OLD] Thay '{STRING_A}' -> '{STRING_B}' trong {filepath}")
        return new_content, True
    return content, False


# ---------------------------------------------------------
# HÀM 2: xử lý quy tắc mới
# ---------------------------------------------------------
def apply_new_rules(content, filepath):
    modified = False
    new_content = content

    for old, new in REPLACEMENTS_EXTRA.items():
        if old in new_content:
            new_content = new_content.replace(old, new)
            modified = True
            print(f"[NEW] Thay '{old}' -> '{new}' trong {filepath}")

    return new_content, modified


# ---------------------------------------------------------
# HÀM 3: xử lý 1 file (gọi cả 2 hàm trên)
# ---------------------------------------------------------
def process_file(filepath):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    modified = False

    # Áp dụng quy tắc cũ
    content, m1 = replace_old_rule(content, filepath)
    modified = modified or m1

    # Áp dụng quy tắc mới
    content, m2 = apply_new_rules(content, filepath)
    modified = modified or m2

    # Ghi lại nếu có thay đổi
    if modified:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
        print(f"→ File đã cập nhật: {filepath}")


# ---------------------------------------------------------
# Xử lý thư mục
# ---------------------------------------------------------
def process_directory(directory):
    if not os.path.exists(directory):
        print(f"Thư mục không tồn tại: {directory}")
        return

    for root, _, files in os.walk(directory):
        for file in files:
            if any(file.endswith(ext) for ext in EXTENSIONS):
                process_file(os.path.join(root, file))


# ---------------------------------------------------------
# MAIN
# ---------------------------------------------------------
def main():
    for d in TARGET_DIRS:
        process_directory(d)

if __name__ == "__main__":
    main()
