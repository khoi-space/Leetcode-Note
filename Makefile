# Source layout
SRC_DIR = src

# Show help
help:
	@echo Available targets:
	@echo ===SOLUTION COMMANDS===
	@echo + update    - Create/Update a problem
	@echo + cpp       - Build + run C++ solution arg: id=
	@echo + py        - Run Python solution arg: id=
	@echo + c         - Build + run C solution: arg: id=
	@echo ===OTHER HELPERS===
	@echo + doctor    - Check Windows toolchain gcc, g++, python available
	@echo + help      - Show this help
	@echo + run       - run specific fiels with arg file= (just file name is OK)
	@echo + clean     - Remove all .exe files

	@echo ===DANGER ZONE===
	@echo + clear_prj - Init the project

run:
	@if not defined file (echo Please set file. E.g. mingw32-make run file=testing.py & exit /b 1)
	@powershell -NoProfile -Command "$$path = (Get-ChildItem -Recurse -File -Path '$(SRC_DIR)' -Filter '$(file)' | Select-Object -First 1 -ExpandProperty FullName); if (-not $$path) { Write-Host 'File $(file) not found!' ; exit 1 } ; $$ext = [IO.Path]::GetExtension($$path).ToLower(); if ($$ext -eq '.py') { python $$path } elseif ($$ext -eq '.cpp') { g++ $$path -o main_cpp.exe; if ($$LASTEXITCODE -eq 0) { ./main_cpp.exe } } elseif ($$ext -eq '.c') { gcc $$path -o main_c.exe; if ($$LASTEXITCODE -eq 0) { ./main_c.exe } } else { Write-Host ('Unsupported extension: ' + $$ext) ; exit 1 }"
doctor:
	@powershell -NoProfile -Command "$$ok = $$true; if (-not (Get-Command gcc -ErrorAction SilentlyContinue)) { Write-Host 'Missing: gcc' ; $$ok = $false }; if (-not (Get-Command g++ -ErrorAction SilentlyContinue)) { Write-Host 'Missing: g++' ; $$ok = $false }; if (-not (Get-Command py -ErrorAction SilentlyContinue) -and -not (Get-Command python -ErrorAction SilentlyContinue)) { Write-Host 'Missing: python/py' ; $$ok = $false }; if ($$ok) { Write-Host 'Environment OK' } else { exit 1 }"

clean: 
	@cmd /C "if exist *.exe del /Q /F *.exe"
	@cmd /C "for /R $(SRC_DIR) %%f in (*.exe) do @del /Q /F \"%%f\""

clear_prj:
	python clear_project.py

.PHONY: help py cpp c clean run doctor clean clear_prj

# --------------- PYTHON SECTION -----------------------
# Run a Python solution by problem id: mingw32-make py id=17

# Python solutions directory
PY_SOL_DIR = $(SRC_DIR)/python/solutions
update:
	python update_list.py
py:
	@if not defined id (echo Please set problem id e.g., mingw32-make py id=1 & exit /b 1)
	@powershell -NoProfile -Command "Write-Host '----- PYTHON: PROBLEM ${id} -----' -ForegroundColor Blue"
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
	@powershell -NoProfile -Command "Write-Host '----- C++: PROBLLEM ${id} -----' -ForegroundColor Blue"
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
	@powershell -NoProfile -Command "Write-Host '----- C: PROBLEM ${id} -----' -ForegroundColor Blue"
	./main_c.exe

