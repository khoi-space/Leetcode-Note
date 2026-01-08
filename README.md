## 📂 STRUCTURE
```
Leetcode/
├── README.md
├── SOL_LIST.md              # Table of contents (use to review or summarize)
├── Makefile                 # Build/run targets for C++, Python, and C
├── scripts/
|   └── templates/           # Init code templates
└── src/
    ├── cpp/
    │   ├── inc/             # C++ headers
    │   ├── utils/           # C++ utilities
    │   ├── solutions/       # C++ solutions (e.g., 1.cpp, 443.cpp, ...)
    │   └── main.cpp         # C++ entry (dispatches by TEST_TO_RUN)
    ├── c/
    │   ├── inc/             # C headers
    │   ├── utils/           # C utilities
    │   ├── solutions/       # C solutions (e.g., 1.c, ...)
    │   └── main.c           # C entry (dispatches by TEST_TO_RUN)
    ├── python/
    │   ├── inc/             # Python helpers
    │   ├── solutions/       # Python solutions (e.g., 1.py, 17.py)
    // In progress...
    ├── java/
    │   └── solutions/
    ├── javascript/
    │   └── solutions/
    ├── typescript/
    │   └── solutions/
    └── csharp/
        └── solutions/
```
>[Click here to view SOL_LIST.md](SOL_LIST.md)

## 📃 USER GUIDE (Windows)

### ✅ Prerequisites
- Install MinGW-w64 (gcc/g++) and add to PATH.
- Install Python 3 (py launcher or python in PATH).

Quick check environment is ready: `mingw32-make doctor`

### ✨ Create A Problem
Interactive helper (add new problem, add language, or update counts): `python .\update_list.py` or `mingw32-make update`

### 🧐 Run Solutions
**(Recommended)** By problem id (dispatch via language entry points):
```
mingw32-make py   id=11
mingw32-make cpp  id=11
mingw32-make c    id=11
```

Run a file by name (searched under `src/` recursively):
```
mingw32-make run file=testing.py
```

### 🐞 Debug Mode
Every language has a simple debug mode. Please see these files for more information:
| C++ | C | Python |
|-----|---|--------|
|[debug.h](src/cpp/inc/debug.h)|[debug.h](src/cpp/inc/debug.h)|[debug.py](src/python/inc/debug.py)|

### 🧪 Tests
Each solution file has its own testcase function. It's just a framework so please modify and add testcases if needed.
### 🧹 Clean
```
mingw32-make clean
```

## 🚀 FUTURE PLANS:
- [ ] Handle with other languages (such as python, java,...)
- [ ] Auto fetch from LeetCode and push code to Leetcode
- [ ] Create an app to:
    * [ ] AI assistant: provide suggestions, analyze errors, generate test cases, explain code.
    * [ ] Statistics & Analytics: progress charts, problem counts by difficulty, tags, solving time, accuracy rate, etc.
    * [ ] Search & Filtering: by tags, difficulty, status, language, solving date, etc.
    * [ ] Personal notes & reminders
    * [ ] Practice mode: random problems, set timers
    * [ ] Roadmap: suggest a roadmap with similar problems




