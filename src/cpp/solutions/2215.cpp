
#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Store to unordered_set";
string time_cmplx = "n + m";
string space_cmplx = "n + m";
#endif
#endif

/**
 * Problem 2215: Find the Difference of Two Arrays
 * LeetCode: https://leetcode.com/problems/find-the-difference-of-two-arrays/
 * @output:
 *  + ans[0] has all distinct nums in nums1 from nums2
 *  + ans[1] has all dictinct nums in nums2 from nums1
*/
class Solution {
public:
    #if APR == 1
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> only_in_nums1 = getElementOnlyInFirst(nums1, nums2);
        vector<int> only_in_nums2 = getElementOnlyInFirst(nums2, nums1);

        return {only_in_nums1, only_in_nums2};
    }
private:
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
    #endif
};


void test2215() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums1;
        vector<int> nums2;
        // Expect
        vector<vector<int>> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,3}, {2,4,6}, {{1,3},{4,6}}},
        {{1,2,3,3}, {1,1,2,2}, {{3},{}}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums1;
        auto &in2 = c.nums2;

        // Result
        auto res = sol.findDifference(in1, in2);

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        if(assertTest(res, c.exp, i, true) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
