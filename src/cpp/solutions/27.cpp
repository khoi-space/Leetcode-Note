#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

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
 * Problem 27: Remove Element
 * LeetCode: https://leetcode.com/problems/remove-element/
 * @require: in-place
 * @explain: remove val in nums and return 
*/
class Solution {
public:
    #if APR == 1
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        // Shift left other elements to head (skip val)
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
        }
        
        nums.resize(k);
        return k;
    }
    #endif
};


void test27() {
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
        int val;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{3,2,2,3}, 3, 2},
        {{0,1,2,2,3,0,4,2}, 2, 5}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto& in1 = c.nums;
        auto& in2 = c.val;

        // Result
        auto res = sol.removeElement(in1, in2);
        db_var(c.nums);
        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
