#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Sum all then subtract num by num";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 724: Find Pivot Index
 * LeetCode: https://leetcode.com/problems/find-pivot-index/
 * @explain: pivot index where left_sum == right_sum (if no idx, return -1)
*/
class Solution {
public:
    #if APR == 1
    int pivotIndex(vector<int>& nums) {
        int right_sum = 0;
        
        for (int num : nums) {
            right_sum += num;
        }
        
        int left_sum = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            left_sum += nums[i];
            if (left_sum == right_sum) return i;
            right_sum -= nums[i];
            db_var(left_sum);
            db_var(right_sum);
        }

        return -1;
    }
    #endif
};


void test724() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,7,3,6,5,6}, 3},
        {{1,2,3}, -1},
        {{2,1,-1}, 0}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;
        // Result
        auto res = sol.pivotIndex(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
