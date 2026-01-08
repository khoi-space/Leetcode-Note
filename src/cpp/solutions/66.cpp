#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "";
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 66: Plus One
 * LeetCode: https://leetcode.com/problems/plus-one/
*/
class Solution {
public:
    #if APR == 1
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
    #endif
};


void test66() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << __FILE__ << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> digits;
        // Expect
        vector<int> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,3},{1,2,4}},
        {{4,3,2,1},{4,3,2,2}},
        {{9},{1,0}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.digits;

        // Result
        auto res = sol.plusOne(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
