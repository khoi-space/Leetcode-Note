#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Two pointers";
string time_cmplx = "n^3";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 18: 4Sum
 * LeetCode: https://leetcode.com/problems/4sum/
*/
class Solution {
public:
    #if APR == 1
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-3; ++i) {
            // Skip duplicate starting value
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n-2; ++j) {
                // Skip duplicate starting value
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = n-1;

                while (left < right) {
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (total > target) {
                        --right;
                    } else if (total < target) {
                        ++left;
                    } else { // total == target
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        
                        while (left < right && nums[left] == nums[left-1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right+1]) {
                            --right;
                        }
                    }
                }
            }
        }
        return ans;
    }
    #endif
};


void test18() {
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
        vector<vector<int>> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,0,-1,0,-2,2}, 0, {{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}}},
        {{2,2,2,2,2}, 8, {{2,2,2,2}}},
        {{1000000000,1000000000,1000000000,1000000000}, 0, {}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.nums;
        auto in2 = c.target;

        // Result
        auto res = sol.fourSum(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
