CXX = g++
TARGET = main

# Compiler flags and include paths
CXXFLAGS = -std=c++17 -Wall -g -Isrc/cpp

# Source layout
SRC_DIR = src
LANG = cpp
MAIN_SRC = $(SRC_DIR)/$(LANG)/main.cpp

# Python solutions directory
PY_SOL_DIR = $(SRC_DIR)/python/solutions

# Default sources (no implicit PROBLEM handling)
SOURCES = $(MAIN_SRC)

# Default target prints help (avoid implicit PROBLEM build)
all: help

# Build the main executable (manual use only)
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET).exe
	./$(TARGET).exe

# Run the program
run:
	./$(TARGET).exe

# Clean up generated files (Windows)
clean:
	del /f $(TARGET).exe 2>nul || echo Clean completed

# Rebuild everything
rebuild: clean all

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Show help (default)"
	@echo "  run        - Build and run the program"
	@echo "  clean      - Remove all generated files"
	@echo "  rebuild    - Clean and build"
	@echo "  help       - Show this help"
	@echo "  cpp        - Build+run C++ solution: PROBLEM=<id>"
	@echo "  py         - Run Python solution: PROBLEM=<id>"

.PHONY: all run clean rebuild help

# --------------- PYTHON SECTION -----------------------
# Run a Python solution by problem ID: mingw32-make py PROBLEM=17
py:
	@if not defined PROBLEM (echo Set PROBLEM=ID, e.g., mingw32-make py PROBLEM=1 & exit /b 1)
	@echo Running Python problem $(PROBLEM)...
	set PYTHONPATH=$(SRC_DIR)/python & python $(PY_SOL_DIR)/$(PROBLEM).py

# --------------- C++ SECTION --------------------------
# Build and run a C++ solution by problem ID: mingw32-make cpp PROBLEM=1
cpp:
	@if not defined PROBLEM (echo Set PROBLEM=ID, e.g., mingw32-make cpp PROBLEM=1 & exit /b 1)
	@echo Building C++ problem $(PROBLEM)...
	$(CXX) $(CXXFLAGS) -DTEST_TO_RUN=$(PROBLEM) $(MAIN_SRC) $(SRC_DIR)/$(LANG)/solutions/$(PROBLEM).cpp -o $(TARGET).exe
	./$(TARGET).exe
