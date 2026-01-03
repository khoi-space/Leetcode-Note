# 📂 STRUCTURE
```
Leetcode/
├── Makefile                 # Build/run targets for C++, Python, and C
├── README.md
├── scripts/
│   └── update_list.py       # Update README (entries, links, counts)
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
    │   └── utils/
    //TODO
    ├── java/
    │   └── solutions/
    ├── javascript/
    │   └── solutions/
    ├── typescript/
    │   └── solutions/
    └── csharp/
        └── solutions/
```
## 📝 NOTE 
File [update_list](scripts/update_list.py) updates [README](README.md):
* Add a new solution entry
* Add a new language to an existed solution
* Count solutions

## 🚀 FUTURE PLANS:
- [ ] Handle with other languages (such as python, java,...)
- [ ] Create an app to:
    * [ ] AI assistant: provide suggestions, analyze errors, generate test cases, explain code.
    * [ ] Statistics & Analytics: progress charts, problem counts by difficulty, tags, solving time, accuracy rate, etc.
    * [ ] Search & Filtering: by tags, difficulty, status, language, solving date, etc.
    * [ ] Personal notes & reminders
    * [ ] Practice mode: random problems, set timers
    * [ ] Roadmap: suggest a roadmap with similar problems




