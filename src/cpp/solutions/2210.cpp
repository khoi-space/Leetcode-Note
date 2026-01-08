#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Brute-force Scan";
string time_cmplx = "n^2";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "One Pass with State";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 2210: Count Hills and Valleys in an Array
 * LeetCode: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
*/
class Solution {
public:
    #if APR == 1
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i - 1]) continue;

            int left_flag = 0; // left_flag = 1 if peak, left_flag = -1 if valley
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    left_flag = -1;
                    break;
                } else if (nums[j] > nums[i]) {
                    left_flag = 1;
                    break;
                }
            }

            int right_flag = 0;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[i]) {
                    right_flag = -1; 
                    break;
                } else if (nums[j] > nums[i]) {
                    right_flag = 1;
                    break;
                }
            }

            if (left_flag == right_flag && left_flag*right_flag != 0) {
                ++cnt;
            }
            
        }
        return cnt;
    }
    #elif APR == 2
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int is_taller = 0; // 0 is neither, 1 indicates taller, -1 indicates shorter

        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) continue;

            if (nums[i - 1] < nums[i]) {
                cnt += (is_taller == -1) ? 1 : 0; // found a valley
                is_taller = 1;
            } else if (nums[i - 1] > nums[i]) {
                cnt += (is_taller == 1) ? 1 : 0; // found a hill
                is_taller = -1;
            }
        }
        return cnt;
    }
    #endif
};


void test2210() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{2,4,1,1,6,5}, 3},
        {{6,6,5,5,4,1}, 0},
        {{5,4,4,3,3,3,10,0,-1,5}, 3}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.countHillValley(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
