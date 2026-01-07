#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 2
#ifdef INFO
#if APR == 1
string apr_idea = "Brute-force";
string time_cmplx = "n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Push to vector";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 6: Zigzag Conversion
 * LeetCode: https://leetcode.com/problems/zigzag-conversion/
*/
class Solution {
public:
    #if APR == 1
    string convert(string s, int numRows) {
        if (numRows == 1 || (int)s.size() <= numRows) return s;
        string result;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int row = 0; row < numRows; ++row) {
            for (int i = row; i < n; i += cycleLen) {
                result += s[i];
                // If not first row or last row, make a gap
                int secondIdx = i + cycleLen - 2 * row;
                if (row != 0 && row != numRows - 1 && secondIdx < n) {
                    result += s[secondIdx];
                }
            }
        }
        return result;
    }
    #elif APR == 2
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.length()) return s;
        
        int idx = 0, d = 1;
        vector<vector<char>> rows(numRows);

        for (char c : s) {
            rows[idx].push_back(c);
            if (idx == 0) {
                d = 1;
            } else if (idx == numRows - 1) {
                d = -1;
            }
            idx += d;
        }

        string ans;
        for (const auto& row : rows) {
            for (char c : row) {
                ans += c;
            }
        }

        return ans;
    }


    #endif
};


void test6() {
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
        int numRows;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"A", 1, "A"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.s;

        // Result
        auto res = sol.convert(c.s, c.numRows);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
