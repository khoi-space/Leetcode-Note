// #include "test.h"
#include "inc/test.h"
#include "inc/global.h"

int main(int argc, char* argv[]) {
    #ifndef TEST_TO_RUN
    #define TEST_TO_RUN 0
    #endif

    #if TEST_TO_RUN == 0
        test0();
    #elif TEST_TO_RUN == 1
        test1();
    #elif TEST_TO_RUN == 2
        test2();
    #elif TEST_TO_RUN == 21
        test21();
    #elif TEST_TO_RUN == 1339
        test1339();
    #else
        printf("Unknown TEST_TO_RUN value");
    #endif
    return 0;
}