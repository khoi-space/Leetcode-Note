#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <fstream>
#include <string>

#ifdef DEBUG
    static std::ofstream debugLog("debug.log");
    #define db(x)       std::cout << x << std::endl;
    #define db_dump(x)  std::cout << #x << ": " << x << std::endl;
    #define db_log(x) debugLog << #x << ": " << x << std::endl;
#else
    #define db(x)
    #define db_dump(x)
    #define db_log(x)
#endif

#endif // DEBUG_H