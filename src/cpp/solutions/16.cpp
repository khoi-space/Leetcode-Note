#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Sorting + Two Pointers";
string time_cmplx = "n^2";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 16: 3Sum Closest
 * LeetCode: https://leetcode.com/problems/3sum-closest/
 * @explain: find 3 integers such that the sum is closest to <target>
*/
class Solution {
public:
    #if APR == 1
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        ans = nums[0] + nums[1] + nums[2]; // starting sum

        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // Did calculate this one before

            int j = i+1;
            int k = n-1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                
                if (abs(total - target) < abs(ans - target)) {
                    ans = total;
                }

                if (total < target) {
                    ++j;
                } else if (total > target) {
                    --k;
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
    #endif
};


void test16() {
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
        int target;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{-1,2,1,-4}, 1, 2},
        {{0,0,0}, 1, 0}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.nums;
        auto in2 = c.target;

        // Result
        auto res = sol.threeSumClosest(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
