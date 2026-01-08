#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Nested Search";
string time_cmplx = "n^2";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Two Pointers";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 392: Is Subsequence
 * LeetCode: https://leetcode.com/problems/is-subsequence/
*/
class Solution {
public:
    #if APR == 1
    bool isSubsequence(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        int j = 0;
        for (int i = 0; i < s_size; ++i) {
            // i will travel on s
            bool char_found = false;
            while (j < t_size) {
                // j will travel on t to find the char == s[i]
                if (t[j] == s[i]) {
                    char_found = true;
                    ++j;
                    break;
                }
                ++j;
            }
            if (char_found == false) return false;
        }
        return true;
    }
    #elif APR == 2
    bool isSubsequence(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        int sp = 0;
        int tp = 0;
        while (sp < s_len && tp < t_len) {
            if (t[tp] == s[sp]) {
                ++sp;
            }
            ++tp;
        }
        return sp == s_len;
    }
    #endif
};


void test392() {
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
        string t;
        // Expect
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {"abc", "ahbgdc", true},
        {"axc", "ahbgdc", false},
        {"aaaaaa", "bbaaaa", false}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.s;
        auto &in2 = c.t;

        // Result
        auto res = sol.isSubsequence(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
