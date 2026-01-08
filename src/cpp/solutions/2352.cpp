#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Key is a vector in hashmap";
string time_cmplx = "n";
string space_cmplx = "n";
#elif APR == 2
string apr_idea = "Key is a string in hashmap";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 2352: Equal Row and Column Pairs
 * LeetCode: https://leetcode.com/problems/equal-row-and-column-pairs/
*/
class Solution {
public:
    #if APR == 1
    int equalPairs(vector<vector<int>>& grid) {
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
    }
    #elif APR == 2
    int equalPairs(vector<vector<int>>& grid) {
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
    }
    #endif
};


void test2352() {
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
        {{{3,2,1},{1,7,6},{2,7,7}}, 1}, // (row 2, col 1)
        {{{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}}, 3} // (r0,c0), (r2,c2), (r3,c2)
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.grid;

        // Result
        auto res = sol.equalPairs(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
