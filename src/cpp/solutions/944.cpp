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
 * Problem 944: Delete Columns to Make Sorted
 * LeetCode: https://leetcode.com/problems/delete-columns-to-make-sorted/
 * @explain: return count of col that are not sorted lexicographically
*/
class Solution {
public:
    #if APR == 1
    int minDeletionSize(vector<string>& strs) {
        int strs_size = strs.size();
        int str_len = strs[0].length();
        int cnt = 0;

        for (int i = 0; i < str_len; ++i) { //column i
            for (int j = 1; j < strs_size; ++j) { //word j
                if (strs[j][i] - '0' < strs[j-1][i] - '0') {
                    ++cnt;
                    // Move to next column
                    break;
                }
            }
        }
        return cnt;
    }
    #endif
};


void test944() {
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
        {{"cba","daf","ghi"}, 1},
        {{"a","b"}, 0},
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
