// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/*
 * Problem 1004: Max Consecutive Ones III
 * @input: binary array nums, int k
 * @output: max of num of consecutive 1's in the array if you can flip at most k 0's.
*/
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
    // Time: O(n)
    // Space: O(n)
}

void test1004() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> nums;
        int k;
        int exp;
    };

    vector<Case> cases = {
        {{1,1,1,0,0,0,1,1,1,1,0}, 2, 6},
        {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10},
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = longestOnes(c.nums, c.k);
        assertTest(res, c.exp, i);
    }
}
