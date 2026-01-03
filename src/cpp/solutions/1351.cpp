#define DEBUG
// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

#define MAX_APR 1
#define APR     1

/**
 * Problem 1351: Count Negative Numbers in a Sorted Matrix
 * @input: mxn matrix in non-increasing order both row-wise and col-wise
 * @output: count the negative nums
*/
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

void test1351() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<vector<int>> grid;
        int exp;
    };

    vector<Case> cases = {
        {{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}, 8},
        {{{3,2},{1,0}}, 0}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = countNegatives(c.grid);
        assertTest(res, c.exp, i);
    }
}
