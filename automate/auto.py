import os
import shutil
import time

filepath = "list.txt"

clean_path = "clean.bat" 
quick_path = "quick.bat"



start_time = time.time()  

with open(filepath, 'r') as file:
    lines = file.readlines()

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

    os.chdir("automate")



end_time = time.time()     
print(f"generate for {len(lines)} msg done in {end_time - start_time} seconds\n")

def count_c_h_lines(folder_path):
    total_lines = 0
    file_count = 0

    for root, _, files in os.walk(folder_path):
        for file in files:
            if file.endswith(".c") or file.endswith(".h"):
                file_path = os.path.join(root, file)

                try:
                    with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
                        line_count = sum(1 for _ in f)
                        total_lines += line_count
                        file_count += 1
                        #print(f"{file_path} : {line_count} lines")
                except:
                    print(f"Cannot read: {file_path}")

    print(f"\nTotal .c/.h files: {file_count/2}")
    print(f"Total lines of code: {total_lines/2}")

    return total_lines


folder = "full_message"   # đường dẫn file xuất ra

os.chdir("..")
count_c_h_lines(folder)
os.chdir("automate")