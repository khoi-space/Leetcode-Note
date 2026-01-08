#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Pop & Push Digits";
string time_cmplx = "logn";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Convert to string";
string time_cmplx = "logn";
string space_cmplx = "logn";
#endif
#endif

/**
 * Problem 7: Reverse Integer
 * LeetCode: https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
    #if APR == 1
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) // INT_MAX = 2,147,483,647
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) // INT_MIN = -2,147,483,648
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
    #elif APR == 2
    int reverse(int x) {
        string conv = "";
        int rev = 0;
        while (x != 0) {
            conv += (char)((x % 10) + '0');
            x /= 10;
        }

        for (char c : conv) {
            int digit = c - '0';
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;
            rev = rev * 10 + digit;
        }
        return rev;
    }
    #endif
};


void test7() {
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
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {123, 321},
        {-123, -321},
        {120, 21},
        {123456789, 987654321}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.x;

        // Result
        auto res = sol.reverse(c.x);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
