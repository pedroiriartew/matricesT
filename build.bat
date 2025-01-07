@echo off
:: Compile command
clang++ -v main.cpp -o MatrizTransform.exe -std=c++17 -Wall -luser32 -lgdi32 -lopengl32

::Build successful?
if %errorlevel% neq 0 (
    echo Build failed!
    exit /b %errorlevel%
)

echo Build succeeded!