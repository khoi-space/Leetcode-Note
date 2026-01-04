#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

class Debug {
public:
    bool enable = false;
    template<typename T>
    void see(const char* label, T x, bool newl = true) const {
        if (enable) {
            std::cout << label << ": " << x;
            if (newl) std::cout << std::endl;
            else std::cout << " | ";
        }
    }

    void say(const std::string& msg, bool newl = true) const {
        if (enable) {
            std::cout << msg;
            if (newl) std::cout << std::endl;
            else std::cout << " | ";
        }
    }
};

#define db_see(x) db.see(#x, x)

#endif // DEBUG_H