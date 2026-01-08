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
 * Problem 1925: Count Square Sum Triples
 * LeetCode: https://leetcode.com/problems/count-square-sum-triples/
*/
class Solution {
public:
    #if APR == 1
    int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int c = sqrt(a*a + b*b);
                if (c <= n && c*c == a*a + b*b) ++cnt;
            }
        }
        return cnt;
    }
    #endif
};


void test1925() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        int n;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {5, 2},
        {10, 4}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.n;

        // Result
        auto res = sol.countTriples(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
