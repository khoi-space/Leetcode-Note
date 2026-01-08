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
 * Problem 1523: Count Odd Numbers in an Interval Range
 * LeetCode: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
*/
class Solution {
public:
    #if APR == 1
    int countOdds(int low, int high) {
        // If low is even, start from low+1
        // If high is even, end at high-1
        if (low % 2 == 0) ++low;
        if (high % 2 == 0) --high;
        return (high - low) / 2 + 1;
    }
    #elif APR == 2
    int countOdds(int low, int high) {
        // Subtract the odd numbers from 0 to high and the odd number from 0 to low-1
        // Equal with (high-0+1)/2 - (low-1+1)/2 
        return (high + 1) / 2 - (low / 2);
    }
    #endif
};


void test1523() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        int low;
        int high;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {3, 7, 3},
        {8, 10, 1},
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0},
        {0, 1, 1},
        {1, 10, 5},
        {21, 22, 1},
        {100, 200, 50}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.low;
        auto &in2 = c.high;

        // Result
        auto res = sol.countOdds(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
