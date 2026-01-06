#include "inc/global.h"
using namespace std;

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
    #elif TEST_TO_RUN == 3
        test3();
    #elif TEST_TO_RUN == 4
        test4();
    #elif TEST_TO_RUN == 5
        test5();
    #elif TEST_TO_RUN == 6
        test6();
    #elif TEST_TO_RUN == 21
        test21();
    #elif TEST_TO_RUN == 28
        test28();
    #elif TEST_TO_RUN == 1975
        test1975();
    #else
        cout << "Unknown TEST_TO_RUN value";
    #endif
    return 0;
}