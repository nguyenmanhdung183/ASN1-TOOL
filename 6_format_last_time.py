# thay thế các e2ap_BIT STRING bằng ASN1BitStr32 
import os

STRING_A = "e2ap_BIT STRING"
STRING_B = "ASN1BitStr32"

TARGET_DIRS = ["merged_output", "output"]

EXTENSIONS = [".c", ".h"]

def replace_in_file(filepath):
    with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()

    new_content = content.replace(STRING_A, STRING_B)

    if new_content != content:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(new_content)
        print(f"Đã thay thế trong: {filepath}")

def process_directory(directory):
    if not os.path.exists(directory):
        print(f"Thư mục không tồn tại: {directory}")
        return

    for root, _, files in os.walk(directory):
        for file in files:
            if any(file.endswith(ext) for ext in EXTENSIONS):
                filepath = os.path.join(root, file)
                replace_in_file(filepath)

def main():
    for d in TARGET_DIRS:
        process_directory(d)

if __name__ == "__main__":
    main()
