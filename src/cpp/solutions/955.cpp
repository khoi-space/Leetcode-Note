#include "../inc/global.h"
using namespace std;

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
 * Problem 955: Delete Columns to Make Sorted II
 * LeetCode: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
 * @rule:   delete all the chars in indices for each strings so that each final arr is lexicographically
 * @output: min of ans.length
*/
class Solution {
public:
    #if APR == 1
    int minDeletionSize(vector<string>& strs) {
        int strs_size = strs.size();
        int str_len = strs[0].size();
        // vector<bool> resolved(strs_size - 1, false);
        bool *resolved = new bool[strs_size - 1];
        int unresolved = strs_size - 1;
        int ans = 0;

        for (int col = 0; col < str_len && unresolved > 0; ++col) {
            bool bad = false;

            // Check for violation
            for (int i = 0; i < strs_size - 1; ++i) {
                if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ++ans;
                continue;
            }

            // Update resolved array
            for (int i = 0; i < strs_size - 1; ++i) {
                if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
                    resolved[i] = true;
                    --unresolved;
                }
            }
        }
        delete[] resolved;
        return ans;
    }
    #endif
};


void test955() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<string> strs;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{"ca","bb","ac"}, 1},
        {{"xc","yb","za"}, 0},
        {{"zyx","wvu","tsr"}, 3}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.strs;

        // Result
        auto res = sol.minDeletionSize(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
