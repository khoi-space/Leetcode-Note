#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

// Uncomment to turn off debug mode
#define DEBUG

#ifdef DEBUG
    #define db_see(x) printf("%s: %d\n", #x, (x))
    #define db_say(msg) printf("%s\n", msg)
#else
    #define db_see(x)
    #define db_say(msg)
#endif

#endif // DEBUG_H