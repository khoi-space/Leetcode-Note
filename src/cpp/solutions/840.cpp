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

// To handle more sizes
#define MAGIC_SIZE 3

/**
 * Problem 840: Magic Squares In Grid
 * LeetCode: https://leetcode.com/problems/magic-squares-in-grid/
*/
class Solution {
public:
    #if APR == 1
    int numMagicSquareInside(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();

        if (num_rows < MAGIC_SIZE || num_cols < MAGIC_SIZE) return 0;
        int cnt_mgc_sqr = 0;

        for (int row = 0; row + MAGIC_SIZE-1 < num_rows; ++row) {
            for (int col = 0; col + MAGIC_SIZE-1 < num_cols; ++col) {
                if (isMagicSquare(grid, row, col)) {
                    ++cnt_mgc_sqr;
                }
            }
        }

        return cnt_mgc_sqr;
    }
private:
    bool isMagicSquare(const vector<vector<int>>& grid, const int row, const int col) {
        bool seen[MAGIC_SIZE*MAGIC_SIZE + 1] = {false};
        for (int i = 0; i < MAGIC_SIZE; ++i) {
            for (int j = 0; j < MAGIC_SIZE; ++j) {
                int num = grid[row+i][col+j];
                if (num < 1 || num > MAGIC_SIZE*MAGIC_SIZE) return false;
                if (seen[num]) return false;
                seen[num] = true;
            }
        }

        int global_sum = 0;
        // Count the global sum
        for (int i = 0; i < MAGIC_SIZE; ++i) {
            global_sum += grid[row][col+i];
        }
        
        /* Count and check sum of each cols */
        for (int i = 1; i < MAGIC_SIZE; ++i) {
            int col_sum = 0;
            for (int j = 0; j < MAGIC_SIZE; ++j) {
                col_sum += grid[row+i][col+j];
            }

            if (col_sum != global_sum) return false;
        }

        /* Count and check sum of each rows */
        for (int i = 0; i < MAGIC_SIZE; ++i) {
            int row_sum = 0;
            for (int j = 0; j < MAGIC_SIZE; ++j) {
                row_sum += grid[row+j][col+i];
            }

            if (row_sum != global_sum) return false;
        }

        /* Count and check sum of the main diagonal */
        int main_diag_sum = 0;
        for (int i = 0; i < MAGIC_SIZE; ++i) {
            main_diag_sum += grid[row+i][col+i];
        }
        if (main_diag_sum != global_sum) return false;

        /* Count and check sum of the principal diagonal */
        int princ_diag_sum = 0;
        for (int i = 0; i < MAGIC_SIZE; ++i) {
            princ_diag_sum += grid[row+i][col+MAGIC_SIZE-1-i];
        }
        if (princ_diag_sum != global_sum) return false;

        return true;
    }
    #endif
};


void test840() {
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
        {{{4,3,8,4}, {9,5,1,9}, {2,7,6,2}}, 1},
        {{{8}}, 0},
        {{{5,5,5},{5,5,5},{5,5,5}}, 0}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.grid;
        // db_var(in1);

        // Result
        auto res = sol.numMagicSquareInside(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
