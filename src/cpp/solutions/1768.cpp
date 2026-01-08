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
 * Problem 1768: Merge Strings Alternately
 * LeetCode: https://leetcode.com/problems/merge-strings-alternately/
*/
class Solution {
public:
    #if APR == 1
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < (int)word1.size() || idx2 < (int)word2.size()) {
            if (idx1 < (int)word1.size()) {
                ans += word1[idx1];
                ++idx1;
            }
            if (idx2 < (int)word2.size()) {
                ans += word2[idx2];
                ++idx2;
            }
        }
        return ans;
    }
    #endif
};


void test1768() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string word1;
        string word2;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {"abc", "pqr", "apbqcr"},
        {"ab", "pqrs", "apbqrs"},
        {"abcd", "pq", "apbqcd"}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.word1;
        auto &in2 = c.word2;

        // Result
        auto res = sol.mergeAlternately(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
