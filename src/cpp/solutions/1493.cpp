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
 * Problem 1493: Longest Subarray of 1's After Deleting One Element
 * LeetCode: https://leetcode.com/problems/longest-subarray-of-1-s-after-deleting-one-element/
*/
class Solution {
public:
    #if APR == 1
    int longestSubarray(vector<int>& nums) {
        int zero_cnt = 0;
        int nums_size = nums.size();
        int longest_window = 0;
        int cur_zero_idx = -1;
        int last_zero_idx = -1;
        
        int start = 0;

        for (int i = 0; i < nums_size; ++i) {
            if (nums[i] == 0) {
                ++zero_cnt;
                last_zero_idx = cur_zero_idx;
                cur_zero_idx = i;
            }

            while (zero_cnt > 1) {
                zero_cnt -= (nums[start] == 0);
                // zero_del_idx = start;
                ++start;
            }

            if (longest_window < i - start) {
                longest_window = i - start;
                // zero_del_idx = i;
            }
        }
        if (last_zero_idx == -1) {
            nums.erase(nums.begin() + cur_zero_idx);
        } else nums.erase(nums.begin() + last_zero_idx);

        return longest_window;
    }
    #endif
};


void test1493() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums;
        // Expect
        int exp;
        vector<int> nums_exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,1,0,1}, 3, {1,1,1}},
        {{0,1,1,1,0,1,1,0,1}, 5, {0,1,1,1,1,1,0,1}},
        {{1,1,1}, 2, {1,1}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.longestSubarray(in1);

        if(assertTest(res, c.exp, i) == false) {
            // cout << "   Input    : " << c.nums << endl;
        }
        
        if(assertTest(in1, c.nums_exp, i) == false) {
            // cout << "   Input    : " << c.nums << endl;
        }
    }
}
