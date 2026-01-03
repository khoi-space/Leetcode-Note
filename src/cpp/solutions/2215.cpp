//#define DEBUG
// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

#define MAX_APR 1
#define APR     1

vector<int> getElementOnlyInFirst(vector<int>& first, vector<int>& second) {
    unordered_set<int> only_in_first;
    unordered_set<int> exist_in_second; // Use for remove the duplicate nums in the second list

    // Insert num in the second list to set (so that skip the duplicate elements)
    for (int num : second) {
        exist_in_second.insert(num);
    }

    // Interate over each element and check distinct in the first list
    for (int num : first) {
        if (exist_in_second.find(num) == exist_in_second.end()) {
            only_in_first.insert(num);
        }
    }

    return vector<int> (only_in_first.begin(), only_in_first.end());
}

/**
 * Problem 2215: Find the Difference of Two Arrays
 * @input: 2 0-indexed int arrs
 * @output: a list of size 2 where:
 * + ans[0] has all distinct num in nums1 which are not in nums2
 * + ans[1] has all distinct num in nums2 which are not in nums1
*/
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int> only_in_nums1 = getElementOnlyInFirst(nums1, nums2);
    vector<int> only_in_nums2 = getElementOnlyInFirst(nums2, nums1);

    return {only_in_nums1, only_in_nums2};
}

void test2215() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> nums1;
        vector<int> nums2;
        vector<vector<int>> exp;
    };

    vector<Case> cases = {
        {{1,2,3}, {2,4,6}, {{1,3},{4,6}}},
        {{1,2,3,3}, {1,1,2,2}, {{3},{}}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        auto res = findDifference(c.nums1, c.nums2);
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        assertTest(res, c.exp, i);
    }
}
