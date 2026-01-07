#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "If negative count is odd, substract the sum by min_abs_val twice";
string time_cmplx = "n*m";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 1975: Maximum Matrix Sum
 * LeetCode: https://leetcode.com/problems/maximum-matrix-sum/
 * @input: integer matrix [n x n]
 * @output: maximum sum of the matrix after using the operation below:
 *  + Choose any two adjacent elem of matrix and multiply each by -1
*/
class Solution {
public:
    #if APR == 1
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total_sum = 0;
        int min_abs_val = INT_MAX;
        int negative_count = 0;

        for (vector<int>& row : matrix) {
            for (int val : row) {
                total_sum += abs(val);
                if (val < 0) ++negative_count;
                min_abs_val = min(min_abs_val, abs(val));
            }
        }

        if (negative_count % 2 == 1) {
            total_sum -= 2 * min_abs_val;
        }

        return total_sum;
    }
    #endif
};


void test1975() {
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
        vector<vector<int>> matrix;
        // Expect
        long long exp;
    };

    vector<Case> cases = {
        // {{}}
        {{{1,-1},{-1,1}}, 4},
        {{{1,2,3},{-1,-2,-3},{1,2,3}}, 16}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.matrix;

        // Result
        auto res = sol.maxMatrixSum(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
