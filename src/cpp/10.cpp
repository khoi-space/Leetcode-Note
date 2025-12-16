#include "test.h"
 #include "global.h"
using namespace std;

/**
 * Problem 10: Regular Expression Matching
 * @input: string s and pattern p
 * * Note: In pattern p:
 * + '.': matches any single char
 * + '*': matches zero or more of the preceding element
 * @output: boolean expression
 */
bool isMatch(string s, string p) {
    
}

void test10() {
    struct Case {
        string s;
        string p;
        bool exp;
    };

    vector<Case> cases = {
        {"aa", "a", false},
        {"aa", "a*", true},
        {"ab", ".*", true}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        bool res = isMatch(cases[i].s, cases[i].p);
        assertTest(res, cases[i].exp, i);
    }
}