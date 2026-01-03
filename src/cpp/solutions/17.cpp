// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

// #define MAX_APR 1
// #define APR     1

static string apr_idea = "";

/**
 * Problem 17: Letter Combinations of a Phone Number
 * LeetCode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * @input:
 * @output:
 */

void test17() {
    struct Case {
        // add fields
    };

    vector<Case> cases = {
        // {{}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        // auto res = solve(...);
        // assertTest(res, c.exp, i);
    }

    #ifdef APR
    cout << "--------------------------------" << endl;
    cout << "\033[1m\033[34mApproach:\033[0m " << APR << " / " << MAX_APR << endl;
    cout << ">>>> " << apr_idea << endl;
    #endif
}
