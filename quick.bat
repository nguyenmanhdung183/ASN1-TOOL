@echo off
setlocal

REM 1. Chạy 2 script trong thư mục Tool_read_pdf
pushd Tool_read_pdf
echo Running 1_gen_yaml.py...
python 1_gen_yaml.py
if %ERRORLEVEL% neq 0 (
    echo Error occurred in 1_gen_yaml.py, stopping.
    popd
    exit /b 1
)
echo Finished 1_gen_yaml.py
echo ------------------------
echo Running 2_get_order_by_order.py...
python 2_get_order_by_order.py
if %ERRORLEVEL% neq 0 (
    echo Error occurred in 2_get_order_by_order.py, stopping.
    popd
    exit /b 1
)
echo Finished 2_get_order_by_order.py
echo ------------------------
popd

REM 2. Chạy 3 script ở thư mục hiện tại
echo Running 3_gen_excel.py...
python 3_gen_excel.py
if %ERRORLEVEL% neq 0 (
    echo Error occurred in 3_gen_excel.py, stopping.
    exit /b 1
)
echo Finished 3_gen_excel.py
echo ------------------------

echo Running 3_gen_excel_Types.py...
python 3_gen_excel_Types.py
if %ERRORLEVEL% neq 0 (
    echo Error occurred in 3_gen_excel_Types.py, stopping.
    exit /b 1
)
echo Finished 3_gen_excel_Types.py
echo ------------------------

echo Running 4_generate_all.py...
python 4_generate_all.py
if %ERRORLEVEL% neq 0 (
    echo Error occurred in 4_generate_all.py, stopping.
    exit /b 1
)
echo Finished 4_generate_all.py
echo ------------------------

echo Running 5_merge_all_file.py...
python 5_merge_all_file.py
if %ERRORLEVEL% neq 0 (
    echo Error occurred in 5_merge_all_file.py, stopping.
    exit /b 1
)
echo Finished 5_merge_all_file.py
echo ------------------------

endlocal
