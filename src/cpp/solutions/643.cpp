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
 * Problem 643: Maximum Average Subarray I
 * LeetCode: https://leetcode.com/problems/maximum-average-subarray-i/
 * @explain: find a contiguous subarray of length k that has the max avg
*/
class Solution {
public:
    #if APR == 1
    double findMaxAverage(vector<int>& nums, int k) {
        long int cur_sum = 0, max_sum = 0;

        // Init cur_sum and max_sum of the first k elements
        for (int i = 0; i < k; ++i) {
            cur_sum += nums[i];
        }
        max_sum = cur_sum;

        for (int i = k; i < (int)nums.size(); ++i) {
            // Subtract the left element of the window
            // Add the right element of the window
            cur_sum += nums[i];
            cur_sum -= nums[i - k];

            max_sum = max(max_sum, cur_sum);
        }
        return (double)max_sum / k;
    }
    #endif
};


void test643() {
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
        int k;
        // Expect
        double exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,12,-5,-6,50,3}, 4, 12.75000},
        {{5}, 1, 5.00000},
        {{0,1,1,3,3}, 4, 2.00000}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;
        auto &in2 = c.k;

        // Result
        auto res = sol.findMaxAverage(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
