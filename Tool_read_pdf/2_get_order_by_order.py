import yaml
import os

# Lấy danh sách tất cả file .yaml trong thư mục hiện tại
yaml_files = [f for f in os.listdir('.') if f.lower().endswith('.yaml')]

def flatten_yaml_bottom_up(node):
    """
    Trả về danh sách các path từ lá lên gốc
    """
    lines = []

    def dfs(n, path=""):
        for k, v in n.items():
            new_path = f"{path}.{k}" if path else k
            if isinstance(v, dict) and v:
                # đệ quy xuống con trước
                dfs(v, new_path)
            # thêm chính node sau khi xử lý con → bottom-up
            lines.append(new_path)

    dfs(node)
    return lines

for yf in yaml_files:
    with open(yf, "r", encoding="utf-8") as f:
        data = yaml.safe_load(f)

    paths = flatten_yaml_bottom_up(data)

    # Xuất ra file text với cùng tên nhưng .txt
    out_file = os.path.splitext(yf)[0] + "_bottomup.txt"
    with open(out_file, "w", encoding="utf-8") as f:
        for p in paths:
            f.write(p + "\n")

    print(f"{yf} → {out_file} ({len(paths)} dòng, bottom-up)")


import os

# Lưu các leaf đã ghi trước đó
written_leaves = set()

for yf in yaml_files:
    out_file = os.path.splitext(yf)[0] + "_bottomup.txt"
    leaf_file = os.path.splitext(yf)[0] + "_bottomup_leaf.txt"

    with open(out_file, "r", encoding="utf-8") as f:
        lines = f.readlines()

    leaf_lines = [line.strip().split(".")[-1] for line in lines if line.strip()]

    # Ghi vào file, chỉ ghi những leaf chưa xuất hiện
    with open(leaf_file, "w", encoding="utf-8") as f:
        unique_count = 0
        for leaf in leaf_lines:
            if leaf not in written_leaves:
                f.write(leaf + "\n")
                written_leaves.add(leaf)
                unique_count += 1

    print(f"Leaf names → {leaf_file} ({unique_count} dòng mới)")
