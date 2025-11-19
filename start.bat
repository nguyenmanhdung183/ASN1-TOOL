@echo off
:: Kiểm tra xem Python đã được cài đặt chưa
python --version >nul 2>nul
if %errorlevel% neq 0 (
    echo Python is not installed. Please install Python first.
    pause
    exit /b
)

:: Kiểm tra xem môi trường ảo đã tồn tại chưa
if exist "venv" (
    echo Virtual environment already exists.
) else (
    :: Tạo môi trường ảo
    echo Creating virtual environment...
    python -m venv venv
)

:: Kích hoạt môi trường ảo
echo Activating virtual environment...
call .\venv\Scripts\activate

:: Cài đặt các thư viện từ requirements.txt (nếu file này tồn tại)
if exist requirements.txt (
    echo Installing packages from requirements.txt...
    pip install -r requirements.txt
) else (
    echo requirements.txt not found.
)

echo Setup completed successfully!
pause
