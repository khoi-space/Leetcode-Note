#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 2
#ifdef INFO
#if APR == 1
string apr_idea = "Vertical Scanning";
string time_cmplx = "n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Horizontal Scanning";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 14: Longest Common Prefix
 * LeetCode: https://leetcode.com/problems/longest-common-prefix/
*/
class Solution {
public:
    #if APR == 1
    string longestCommonPrefix(vector<string>& strs) {
        stringstream result;
        if (strs.empty()) return "";
        for (size_t i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (size_t j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c)
                    return result.str();
            }
            result << c;
        }
        return result.str();
    }
    #elif APR == 2
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < (int)strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < (int)strs.size(); j++) {
                if (i == (int)strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
    #endif
};


void test14() {
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
        vector<string> strs;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {{"flower","flow","flight"}, "fl"},
        {{"dog","racecar","car"}, ""},
        {{"interview","internet","internal"}, "inter"},
        {{"a"}, "a"},
        {{"",""}, ""},
        {{"ab", "a"}, "a"},
        {{"cir","car"}, "c"},
        {{}, ""}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.strs;

        // Result
        auto res = sol.longestCommonPrefix(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
