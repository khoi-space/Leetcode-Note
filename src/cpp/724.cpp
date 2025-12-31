// #define DEBUG
#include "test.h"
#include "global.h"
using namespace std;

#define MAX_APR 1
#define APR     1

/**
 * Problem 724: Find Pivot Index
 * @input: integer array nums
 * @output: pivot index (if no index, return -1)
 * @explain: the pivot index is the index where left_sum == right_sum
*/
int pivotIndex(vector<int>& nums) {
    int right_sum = 0;
    for (int num : nums) {
        right_sum += num;
    }
    debug(nums);
    int left_sum = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        debug(i);
        left_sum += nums[i];
        if (left_sum == right_sum) return i;
        right_sum -= nums[i];
        debug(left_sum);
        debug(right_sum);
    }

    return -1;
}

void test724() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> nums;
        int exp;
    };

    vector<Case> cases = {
        {{1,7,3,6,5,6}, 3},
        {{1,2,3}, -1},
        {{2,1,-1}, 0}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = pivotIndex(c.nums);
        assertTest(res, c.exp, i);
    }
}
