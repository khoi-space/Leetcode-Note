#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdbool.h>

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
    #define db(msg)         printf("[DEBUG] %s\n", msg);
    #define db_info(msg)    printf("\033[7m[INFO]\033[0m %s\n", msg);
    #define db_warn(msg)    printf("\033[33m[WARN]\033[0m %s\n", msg);
    #define db_error(msg)   printf("\033[31m[ERROR]\033[0m %s\n", msg);
    #define db_var(x)       printf("[VAR] %s = %d\n", #x, (x));
    #define db_loc()        printf("[LOC] %s:%d\n", __FILE__, __LINE__)
#else
#define db(msg)
    #define db_info(msg)
    #define db_warn(msg)
    #define db_error(msg)
    #define db_var(x)  
    #define db_loc()
#endif

#endif // DEBUG_H