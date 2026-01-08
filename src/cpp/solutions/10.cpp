#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Recursion";
string time_cmplx = "2^(s+p)";
string space_cmplx = "s+p";
#elif APR ==2
string apr_idea = "Dynamic Programming";
string time_cmplx = "s+p";
string space_cmplx = "s*p";
#endif
#endif

/**
 * Problem 10: Regular Expression Matching
 * LeetCode: https://leetcode.com/problems/regular-expression-matching/
 * @explain: In patern p:
 *      '.': Matches any single char
 *      '*': Matches zero or more of the preceding element
*/
class Solution {
public:
    #if APR == 1
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
    #elif APR == 2
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; --i) {
            #ifdef DEBUG
            cout << "i=" << i << endl;
            #endif

            for (int j = n-1; j >= 0; --j) {
                bool first_match = (i < m && (s[i] == p[j] || p[j] == '.'));
                if (j+1 < n && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }

                #ifdef DEBUG
                cout << " dp[i][j]=" << dp[i] << endl;
                #endif
            }
        }
        return dp[0][0];
    }
    #endif
};


void test10() {
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
        string p;
        // Expect
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {"aa", "a", false},
        {"aa", "a*", true},
        {"ab", ".*", true}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.s;
        auto in2 = c.p;

        // Result
        auto res = sol.

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
