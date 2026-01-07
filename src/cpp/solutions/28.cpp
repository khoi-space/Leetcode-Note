#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Slicing";
string time_cmplx = "m*n";
string space_cmplx = "m";
#endif
#endif

/**
 * Problem 28: Find the Index of the First Occurrence in a String
 * LeetCode: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 * @input: string haystack and needle
 * @output: idx of the first occurrence of needle (-1 if not)
*/
class Solution {
public:
    #if APR == 1
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;

        for (size_t i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }

        return -1;
    }
    #endif
};


void test28() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << __FILE__ << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endifS

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string haystack;
        string needle;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {"sadbutsad", "sad", 0},
        {"leetcode", "leeto", -1}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.haystack;
        auto in2 = c.needle;

        // Result
        auto res = sol.strStr(c.haystack, c.needle);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
