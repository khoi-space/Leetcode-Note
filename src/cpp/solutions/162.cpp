#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Linear";
string time_cmplx = "n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Binary Search";
string time_cmplx = "logn";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 162: Find Peak Element
 * LeetCode: https://leetcode.com/problems/find-peak-element/
*/
class Solution {
public:
    #if APR == 1
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return 0;
        int n = nums.size();
        bool wait_for_lower = false; // 1 indicates taller, -1 indicates shorter
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                wait_for_lower = true;
            } else if (nums[i - 1] > nums[i]) {
                if (wait_for_lower == true) return (i - 1); // i-1 is a peak
            }
        }
        if (wait_for_lower == false) return 0;
        else if (wait_for_lower == true) return n-1;
        return 0;
    }
    #elif APR == 2
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
            #if DEBUG
            cout << left << " " << mid << " " << right << endl;
            #endif
        }
        return left;
    }
    #endif
};


void test162() {
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
        vector<int> accepted_exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,3,1}, {2}},
        {{1,2,1,3,5,6,4}, {1,5}},
        {{2,2,2,2,2,2}, {0,1,2,3,4,5}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.findPeakElement(in1);
        bool found = true;
        for (int exp : c.accepted_exp) {
            if (res == exp) {
                found = true;
                break;
            }
        }
        if(assertTest(found, true, i) == false) {
            // cout << "   Input    : " << in1 << endl;
        }
    }
}
