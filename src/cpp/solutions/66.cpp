//#define DEBUG
// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

#define MAX_APR 1
#define APR     1

/**
 * Problem 66: Plus One
 * @input: large integer in array (no leading 0's)
 * @output: increment the large int by one
*/
vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    int i = digits.size() - 1;
    while (i >= 0 && carry == 1) {
        int raw = digits[i] + carry;
        digits[i] = raw % 10;
        carry = raw / 10;
        i--;
    }

    if (carry == 1) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

void test66() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> digits;
        vector<int> exp;
    };

    vector<Case> cases = {
        {{1,2,3},{1,2,4}},
        {{4,3,2,1},{4,3,2,2}},
        {{9},{1,0}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        auto res = plusOne(c.digits);
        assertTest(res, c.exp, i);
    }
}
