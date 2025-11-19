@echo off
REM --- Thư mục cần xóa subfolders ---
set "FOLDER=full_message"

REM --- Kiểm tra folder có tồn tại không ---
if not exist "%FOLDER%" (
    echo Thư mục %FOLDER% khong ton tai!
    exit /b
)

REM --- Duyệt tất cả folder con ---
for /d %%D in ("%FOLDER%\*") do (
    echo Da xoa thu muc: %%D
    rmdir /s /q "%%D"
)

echo Hoan thanh xoa tat ca thu muc con trong %FOLDER%.

