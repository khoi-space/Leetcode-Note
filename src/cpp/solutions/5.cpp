#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Expand from centers";
string time_cmplx = "n^2";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 5: Longest Palindromic Substring
 * LeetCode: https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:
    #if APR == 1
    string longestPalindrome(string s) {
        string ans = "";

        for (size_t i = 0; i < s.size(); ++i) {
            string odd = expand(s, i, i); // Check an odd-size palindrome expaned from i
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            string even = expand(s, i, i + 1); // Check an even-size palindrome expanded from i and i+1
            if (even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    }
private:
    string expand(string s, int i, int j) {
        int l = i;
        int r = j;

        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }

        return s.substr(l + 1, r - l - 1);
    }
    #endif
};


void test5() {
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
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {"babad", "bab"},
        {"cbbd", "bb"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.

        // Result
        auto res = sol.

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
