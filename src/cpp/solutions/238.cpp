#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Find prefix product and suffix product";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 238: Product of Array Except Self
 * LeetCode: https://leetcode.com/problems/product-of-array-except-self/
 * @explain: ans[i] is equal to the product of other elements except itself
 * @require: must in O(n) time and without division operation
*/
class Solution {
public:
    #if APR == 1
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int *prefix = new int[n];
        int *suffix = new int[n];

        prefix[0] = 1;
        suffix[n - 1] = 1;

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            ans[i] = prefix[i] * suffix[i];
        }

        delete prefix;
        delete suffix;

        return ans;
    }
    #endif
};


void test238() {
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
        // Expect
        vector<int> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,3,4}, {24,12,8,6}},
        {{-1,1,0,-3,3}, {0,0,9,0,0}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.productExceptSelf(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
