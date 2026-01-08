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
 * Problem 1351: Count Negative Numbers in a Sorted Matrix
 * LeetCode: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/
class Solution {
public:
    #if APR == 1
    int countNegatives(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int count_negatives = 0;

        for (int row = num_rows - 1; row >= 0; --row) {
            for (int col = num_cols - 1; col >= 0; --col) {
                if (grid[row][col] < 0) ++count_negatives;
                else break; // The rest is no longer negative
            }
        }

        return count_negatives;
    }
    #endif
};


void test1351() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<vector<int>> grid;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}, 8},
        {{{3,2},{1,0}}, 0}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.grid;

        // Result
        auto res = sol.countNegatives(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
