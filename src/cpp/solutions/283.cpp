// Turn on/off debug mode
#undef DEBUG
#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "";
string time_cmplx = "n";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 283: Move Zeroes
 * LeetCode: https://leetcode.com/problems/move-zeroes/
*/
class Solution {
public:
    #if APR == 1
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; ++r) {
            if (nums[r] != 0) {
                swap(nums[r], nums[l]);
                ++l;
                db_var(l);
            }
        }
    }
    #endif
};


void test283() {
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
        vector<int> nums;
        // Expect
        vector<int> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{0,1,0,3,12}, {1,3,12,0,0}},
        {{0}, {0}},
        {{1,1,0,1,1}, {1,1,1,1,0}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        sol.moveZeroes(in1);
        auto res = in1;

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
