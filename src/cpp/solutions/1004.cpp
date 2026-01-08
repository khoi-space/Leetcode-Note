#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Sliding windows";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 1004: Max Consecutive Ones III
 * LeetCode: https://leetcode.com/problems/max-consecutive-ones-iii/
*/
class Solution {
public:
    #if APR == 1
    int longestOnes(vector<int>& nums, int k) {
        int _size = nums.size();
        int max_len = 0;
        int left = 0;
        int zero_count = 0;
        
        for (int right = 0; right < _size; ++right) {
            if (nums[right] == 0) {
                ++zero_count;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    --zero_count;
                }
                ++left;
            }

            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
    #endif
};


void test1004() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums;
        int k;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,1,1,0,0,0,1,1,1,1,0}, 2, 6},
        {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;
        auto &in2 = c.k;

        // Result
        auto res = sol.longestOnes(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
