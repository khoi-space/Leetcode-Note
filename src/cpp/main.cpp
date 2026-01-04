// #include "test.h"
#include "inc/test.h"
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
    #else
        cout << "Unknown TEST_TO_RUN value";
    #endif
    return 0;
}