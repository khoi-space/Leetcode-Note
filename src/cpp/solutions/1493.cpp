// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/**
 * Problem 1493: Longest Subarray of 1's After Deleting One Element
 * @input: binary array nums
 * @output: size of the longest non-empty subarray containing only 1's in the array after deleting one element
*/
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

void test1493() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> nums;

        int exp;
        vector<int> exp_nums;
    };

    vector<Case> cases = {
        {{1,1,0,1}, 3, {1,1,1}},
        {{0,1,1,1,0,1,1,0,1}, 5, {0,1,1,1,1,1,0,1}},
        {{1,1,1}, 2, {1,1}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = longestSubarray(c.nums);
        assertTest(res, c.exp, i);
        assertTest(c.nums, c.exp_nums, i);
    }
}
