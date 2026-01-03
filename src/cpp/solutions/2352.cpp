// #define DEBUG
// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

#define MAX_APR 2
#define APR     1

static string apr_caption = "";

/**
 * Problem 2352: Equal Row and Column Pairs
 * @input: a 0-indexed nxn int matrix
 * @output: num of pairs (r_i, c_j) such that row r_i == col c_j
*/
int equalPairs(vector<vector<int>>& grid) {
    #if APR == 1
    apr_caption = "Key is a vector in hashmap";

    map<vector<int>, int> mp;
    int ans = 0;
    int row_size = grid.size();
    int col_size = grid[0].size();

    for (vector<int> row : grid) {
        mp[row]++;
    }

    for (int j = 0; j < col_size; ++j) {
        vector<int> col;
        for (int i = 0; i < row_size; ++i) {
            col.push_back(grid[i][j]);
        }

        ans += mp[col];
    }

    return ans;
    #elif APR == 2
    apr_caption = "Key is a string in hashmap";

    unordered_map<string, int> row_map;
    int n = grid.size();
    int ans = 0;

    auto vec2str = [](const vector<int>& v) {
        string s;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (i > 0) s += ",";
            s += to_string(v[i]);
        }
        return s;
    };

    // Storing row to hashmap
    for (const auto& row : grid) {
        row_map[vec2str(row)]++;
    }

    // Check each col with hashmap
    for (int j = 0; j < n; ++j) {
        vector<int> col;
        for (int i = 0; i < n; ++i) {
            col.push_back(grid[i][j]);
        }
        ans += row_map[vec2str(col)];
    }
    return ans;
    #endif
}

void test2352() {
    struct Case {
        vector<vector<int>> grid;
        int exp;
    };

    vector<Case> cases = {
        {{{3,2,1},{1,7,6},{2,7,7}}, 1}, // (row 2, col 1)
        {{{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}}, 3} // (r0,c0), (r2,c2), (r3,c2)
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = equalPairs(c.grid);
        assertTest(res, c.exp, i);
    }

    #ifdef APR
    cout << "--------------------------------" << endl;
    cout << "\033[34mApproach:\033[0m " << APR << " / " << MAX_APR << endl;
    cout << "\033[1m>>>> " << apr_caption << "\033[0m" << endl;
    #endif
}
