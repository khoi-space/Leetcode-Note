#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Overwrite + Two Pointers";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 2390: Removing Stars From a String
 * LeetCode: https://leetcode.com/problems/removing-stars-from-a-string/
*/
class Solution {
public:
    #if APR == 1
    string removeStars(string s) {
        string ans = s;
        int idx = 0;
        
        for (char c : s) {
            if (c != '*') {
                ans[idx] = c;
                ++idx;
            } else {
                if (idx > 0) {
                    --idx;
                }
            }
        }

        return ans.substr(0, idx);
    }
    #endif
};


void test2390() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
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
        {"leet**cod*e", "lecoe"},
        {"erase*****", ""},
        {"abb*cdfg*****x*", "a"}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.s;

        // Result
        auto res = sol.removeStars(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
