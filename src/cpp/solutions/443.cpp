#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "In-place";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 443: String Compression
 * LeetCode: https://leetcode.com/problems/string-compression/
*/
class Solution {
public:
    #if APR == 1
    int compress(vector<char>& chars) {
        int i = 0, res = 0;
        while (i < (int)chars.size()) {
            int group_len = 1;
            while (i + group_len < (int)chars.size() && chars[i + group_len] == chars[i]) {
                ++group_len;
            }

            chars[res++] = chars[i];
            if (group_len > 1) {
                for (char c : to_string(group_len)) {
                    chars[res++] = c;
                }
            }
            i += group_len;
        }
        chars.resize(res);
        return res;
    }
    #endif
};


void test443() {
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
        vector<char> chars;
        // Expect
        vector<char> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{'a','a','b','b','c','c','c'}, {'a','2','b','2','c','3'}},
        {{'a'}, {'a'}},
        {{'a','b','b','b','b','b','b','b','b','b','b','b','b'}, {'a','b','1','2'}},
        {{'a','b','c'}, {'a','b','c'}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.chars;

        // Result
        sol.compress(in1);
        auto res = in1;

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
