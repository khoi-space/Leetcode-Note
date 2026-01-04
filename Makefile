# Source layout
SRC_DIR = src

# Show help
help:
	@echo "Available targets:"
	@echo "  help       - Show this help"
	@echo "  cpp        - Build + run C++ solution: id=<id>"
	@echo "  py         - Run Python solution: id=<id>"
	@echo "  c          - Build + run C solution: id=<id>"

clean: 
	del /f main_cpp.exe 2>nul
	del /f main_c.exe 2>nul

.PHONY: help py cpp c clean run

# --------------- PYTHON SECTION -----------------------
# Run a Python solution by problem id: mingw32-make py id=17

# Python solutions directory
PY_SOL_DIR = $(SRC_DIR)/python/solutions

py:
	@if not defined id (echo Please set problem id e.g., mingw32-make py id=1 & exit /b 1)
	@powershell -NoProfile -Command "Write-Host '----- Python: Problem ${id} -----' -ForegroundColor Blue"
	set PYTHONPATH=$(SRC_DIR)/python & python $(PY_SOL_DIR)/$(id).py

# --------------- C++ SECTION --------------------------
# NOTE: We will run main.cpp because we don't wanna to see too much .exe files (e.g., 1.exe, 2.exe,...)
# Build and run a C++ solution by problem id: mingw32-make cpp id=1
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Isrc/cpp
# Directory of main.cpp 
MAIN_CPP_SRC = $(SRC_DIR)/cpp/main.cpp

cpp:
	@if not defined id (echo Please set problem id, e.g., mingw32-make cpp id=1 & exit /b 1)
	$(CXX) $(CXXFLAGS) -DTEST_TO_RUN=$(id) $(MAIN_CPP_SRC) $(SRC_DIR)/cpp/solutions/$(id).cpp -o main_cpp.exe
	@powershell -NoProfile -Command "Write-Host '----- C++: Problem ${id} -----' -ForegroundColor Blue"
	./main_cpp.exe

# --------------- C SECTION --------------------------
CC = gcc
CFLAGS = -std=c11 -Wall -g -Isrc/c
# Directory of main.c
MAIN_C_SRC = $(SRC_DIR)/c/main.c

# Build and run a C solution by problem id: mingw32-make c id=1
c:
	@if not defined id (echo Please set problem id, e.g., mingw32-make c id=1 & exit /b 1)
	$(CC) $(CFLAGS) -DTEST_TO_RUN=$(id) $(MAIN_C_SRC) $(SRC_DIR)/c/solutions/$(id).c -o main_c.exe
	@powershell -NoProfile -Command "Write-Host '----- C: Problem ${id} -----' -ForegroundColor Blue"
	./main_c.exe

