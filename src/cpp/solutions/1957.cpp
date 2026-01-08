#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Insert to a new string";
string time_cmplx = "n";
string space_cmplx = "n";
#elif APR == 2
string apr_idea = "Two pointers";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 1957: Delete Characters to Make Fancy String
 * LeetCode: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
 * @explain: a fancy string has no 3 consecutive equal chars
*/
class Solution {
public:
    #if APR == 1
    string makeFancyString(string s) {
        if (s.size() < 3) return s;

        string new_fancy_str = "";
        int freq = 1;
        char prev = s[0];
        int n = s.size();

        new_fancy_str.push_back(s[0]);
        for (int i = 1; i < n; ++i) {
            if (s[i] == prev) {
                ++freq;
            } else {
                prev = s[i];
                freq = 1;
            }

            if (freq < 3) new_fancy_str.push_back(s[i]);
        }
        return new_fancy_str;
    }
    #elif APR == 2
    string makeFancyString(string s) {
        if (s.size() < 3) return s;

        int j = 2;
        for (int i = 2; i < (int)s.size(); ++i) {
            if (s[i] != s[j - 1] ||
                s[i] != s[j - 2]) 
            {
                s[j++] = s[i];
            }
        }

        s.resize(j);
        return s;
    }
    #endif
};


void test1957() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string s;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {"leeetcode", "leetcode"},
        {"aaabaaaa", "aabaa"}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.s;

        // Result
        auto res = sol.makeFancyString(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
