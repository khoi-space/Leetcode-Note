#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <fstream>
#include <string>

#define DEBUG

#ifdef DEBUG
    /**
     * Usage:
     *  db(msg)         : to shout a useless msg
     *  db_info(msg)    : to shout a info msg
     *  db_warn(msg)    : to shout a warnign msg (unusual behavior)
     *  db_error(msg)   : to shout a error msg (to track before crash)
     *  db_var(x)       : to dump name and value of x
     *  db_loc()        : to track the line and file
     */
    #define db(msg)         std::cout << "[DEBUG] " << msg << std::endl;
    #define db_info(msg)    std::cout << "\033[7m[INFO]\033[0m " << msg << std::endl;
    #define db_warn(msg)    std::cout << "\033[33m[WARN]\033[0m " << msg << std::endl;
    #define db_error(msg)   std::cout << "\033[31m[ERROR]\033[0m " << msg << std::endl;
    #define db_var(x)       std::cout << "[VAR] " << #x << " = " << x << std::endl;
    #define db_loc()        std::cout << "[LOC] " << __FILE__ << ":" << __LINE__ << std::endl;
#else
#define db(msg)
    #define db_info(msg)
    #define db_warn(msg)
    #define db_error(msg)
    #define db_var(x)  
    #define db_loc()
#endif

#endif // DEBUG_H