#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Compare with reverse version";
string time_cmplx = "logn";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 9: Palindrome Number
 * LeetCode: https://leetcode.com/problems/palindrome-number/
*/
class Solution {
public:
    #if APR == 1
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev_num = 0;
        while (x > rev_num) {
            rev_num = rev_num * 10 + x % 10;
            x /= 10;
        }

        return (x == rev_num) || (x == rev_num / 10);
    }
    #endif
};


void test9() {
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
        int x;
        // Expect
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {121, true},
        {-121, false},
        {10, false},
        {0, true},
        {12321, true},
        {1221, true},
        {123, false}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.x;

        // Result
        auto res = sol.isPalindrome(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
