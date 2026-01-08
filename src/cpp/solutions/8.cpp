#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Math";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 8: String to Integer (atoi)
 * LeetCode: https://leetcode.com/problems/string-to-integer-atoi/
*/
class Solution {
public:
    #if APR == 1
    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0;
        int n = s.size();

        // Skip leading whitespace
        while (i < n && s[i] == ' ') {
            ++i;
        }

        // Check if we've reached the end
        if (i == n) {
            return 0;
        }

        // Check sign
        int sign = 1;
        if (s[i] == '+') {
            sign = 1;
            ++i;
        } else if (s[i] == '-') {
            sign = -1;
            ++i;
        }

        // Read digits and convert to int
        long res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
                return sign == 1 ? INT_MAX : INT_MIN; 
            }
            ++i;
        }
        return (int)(sign * res);
    }
    #endif
};


void test8() {
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
        string s;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {"432", 432},
        {"42", 42},
        {" -042", -42},
        {"1337c0d3", 1337},
        {"0-1", 0},
        {"don't convert this", 0},
        {"-91283472332", INT_MIN},
        {"-2147483648", INT_MIN},
        {"91283472332", INT_MAX},
        {"2147483647", INT_MAX}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.s;

        // Result
        auto res = sol.myAtoi(c.s);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
