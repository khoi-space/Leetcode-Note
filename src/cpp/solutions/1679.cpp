#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Two Pointers";
string time_cmplx = "n*logn";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Use unorderd_map";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 1679: Max Number of K-Sum Pairs
 * LeetCode: https://leetcode.com/problems/max-number-of-k-sum-pairs/
*/
class Solution {
public:
    #if APR == 1
    int maxOperations(vector<int>& nums, int k) {
        int _size = nums.size();
        int cnt = 0;
        int l = 0;
        int r = _size - 1;

        sort(nums.begin(), nums.end());
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum < k) {
                ++l;
            } else if (sum > k) {
                --r;
            } else {
                ++cnt;
                ++l;
                --r;
            }
        }
        return cnt;
    }
    #elif APR == 2
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;

        for (int num : nums) {
            int need = k - num;
            if (mp[need] > 0) {
                ++cnt;
                --mp[need];
            } else {
                ++mp[num];
            }
        }
        return cnt;
    }
    #endif
};


void test1679() {
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
        {{1,2,3,4}, 5, 2},
        {{3,1,3,4,3}, 6, 1}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;
        auto &in2 = c.k;

        // Result
        auto res = sol.maxOperations(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
