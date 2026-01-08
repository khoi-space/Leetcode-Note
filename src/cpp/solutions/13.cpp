#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Right-to-left + array int";
string time_cmplx = "";
string space_cmplx = "";
#elif APR == 2
string apr_idea = "Left-to-right + hashmap";
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 13: Roman to Integer
 * LeetCode: https://leetcode.com/problems/roman-to-integer/
*/
class Solution {
public:
    #if APR == 1
    int romanToInt(string s) {
        static int val[256] = {};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int prev_val = 0;
        int result = 0;

        for (int i = s.length() - 1; i >= 0; --i) { // Move from right to left (no more jumping)
            int cur_val = val[(unsigned char)s[i]];
            result += (cur_val < prev_val) ? -cur_val : cur_val;
            prev_val = cur_val;
        }

        return result;
    }
    #elif APR == 2
    int romanToInt(string s) {
        unordered_map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int result = 0;

        for (size_t i = 0; i < s.length(); ++i) { // Move from left to right
            if (i+1 < s.length() && val[s[i]] < val[s[i+1]]) {
                result += val[s[i + 1]] - val[s[i]];
                ++i;
            } else {
                result += val[s[i]];
            }
        }

        return result;
    }
    #endif
};


void test13() {
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
        {"I", 1},
        {"III", 3},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000},
        {"LVIII", 58},     // L(50) + V(5) + III(3)
        {"MCMXCIV", 1994}, // M(1000) + CM(900) + XC(90) + IV(4)
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.s;

        // Result
        auto res = sol.romanToInt(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
