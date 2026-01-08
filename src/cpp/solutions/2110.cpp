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
 * Problem 2110: Number of Smooth Descent Periods of a Stock
 * LeetCode: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
*/
class Solution {
public:
    #if APR == 1
    long long getDescentPeriods(vector<int>& prices) {
        int prev_smth = 0;
        long long sum = prices.size();
        for (int i = 1; i < (int)prices.size(); ++i) {
            if (prices[i-1] - prices[i] == 1) {
                prev_smth++;
                sum += prev_smth;
            } else {
                prev_smth = 0;
            }
        }
        return sum;
    }
    #endif
};


void test2110() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> prices;
        // Expect
        long long exp;
    };

    vector<Case> cases = {
        // {{}}
        {{3,2,1,4}, 7},
        {{8,6,7,7}, 4},
        {{1}, 1}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.prices;

        // Result
        auto res = sol.getDescentPeriods(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
