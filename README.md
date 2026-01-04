## 📖 LIST OF SOLUTIONS
>[Click here to view SOL_LIST.md](SOL_LIST.md)

## 📂 STRUCTURE
```
Leetcode/
├── README.md
├── SOL_LIST.md              # Table of contents (use to review or summarize)
├── Makefile                 # Build/run targets for C++, Python, and C
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

## 📃 USER GUIDE
### 1️⃣ __HOW TO CREATE A PROBLEM?__
**Answer:** Use [update_list.py](update_list.py) with these options below:
* *Create a new problem entry*: 
```
PS E:\Git_wp\Leetcode> python .\update_list.py
Add new problem entry? (y/n): y
...
```

* *Create a new language to an existing solution*:
```
PS E:\Git_wp\Leetcode> python .\update_list.py
Add new problem entry? (y/n): n
Add new language for a problem? (y/n): y
...
```

* *Just update solution count*: Choose "NO" for both options above.

✨ **Example of creating a new problem**:
```
PS E:\Git_wp\Leetcode> python .\update_list.py
Add new problem entry? (y/n): y
Problem number: 0
Problem name: dump  
Difficulty (easy/medium/hard): easy
Language:
1. C++
2. C#
3. C
4. Python
5. Java
6. Javascript
7. TypeScript
>>> 1
Created code files:
  E:\Git_wp\Leetcode\src\cpp\solutions\0.cpp
Added problem 0 to ## 🟢Easy
Update test.h
Update main.cpp
Total problem: 1
Updated to file SOL_LIST.md
```

### 2️⃣ __HOW TO RUN A SOLUTION FILE?__
**Answer:** Use Makefile.  
Syntax `mingw32-make <lang> id=<id>`
* lang = [py, cpp, c, cs, js, java, ts]
* id is the problem number

`mingw32-make help` for more detailed.

### 3️⃣ __HOW TO RUN A TESTCASES?__
**Answer:** Init code contains a skeleton of the testcase. Please write your own testcase in it. When running code, the testcase will run too.

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




