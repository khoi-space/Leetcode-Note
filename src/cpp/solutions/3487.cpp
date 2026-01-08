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
 * Problem 3487: Maximum Unique Subarray Sum After Deletion
 * LeetCode: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
 * @explain:
 *  + All elements in the subarray are unique.
 *  + The sum of the elements in the subarray is max
*/
class Solution {
public:
    #if APR == 1
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumSet;
        int max_sum = 0;
        for (int num : nums) {
            if (num > 0) {
                positiveNumSet.insert(num);
            }
        }

        if (positiveNumSet.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        
        for (int positive_num : positiveNumSet) {
            max_sum += positive_num;
        }
        return max_sum;
    }
    #endif
};


void test3487() {
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
        {{1,2,3,4,5}, 15},
        {{1,1,0,1,1}, 1},
        {{1,2,-1,-2,1,0,-1}, 3}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.maxSum(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
