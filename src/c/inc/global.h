#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef DEBUG
#define db_put(x)      printf("\033[30m%s: [debug]\033[0m", #x)
#define db_dump(x)     printf("\033[30m%s: [debug]\033[0m\n", #x)
#define db_say(x)      printf("\033[30m%s\033[0m\n", (x))
#else
#define db_put(x)
#define db_dump(x)
#define db_say(x)
#endif

#endif // GLOBAL_H