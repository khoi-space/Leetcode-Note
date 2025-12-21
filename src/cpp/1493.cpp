#include "test.h"
#include "global.h"
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
    return 0;
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
