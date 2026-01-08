#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Nested loops";
string time_cmplx = "n^3";
string space_cmplx = "n";
#elif APR == 2
string apr_idea = "Two pointers";
string time_cmplx = "n^2";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 15: 3Sum
 * LeetCode: https://leetcode.com/problems/3sum/
*/
class Solution {
public:
    #if APR == 1
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> satisfy_sum_arr = {nums[i], nums[j], nums[k]};
                        bool arrExsited = false;
                        for (int l = 0; l < (int)ans.size(); ++l) {
                            if (satisfy_sum_arr == ans[l]) {
                                arrExsited = true;
                                break;
                            }
                        }
                        if (arrExsited == false) {
                            ans.push_back(satisfy_sum_arr);
                        }
                    }
                }
            }
        }
        return ans;
    }
    #elif APR == 2
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    --k;
                } else if (total < 0) {
                    ++j;
                } else { // total == 0
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;

                    while (nums[j] == nums[j-1] && j < k) {
                        ++j;
                    }
                }
            }
        }
        return ans;
    }
    #endif
};


void test15() {
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
        vector<vector<int>> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{-1,0,1,2,-1,-4}, {{-1,-1,2},{-1,0,1}}},
        {{0,1,1}, {}},
        {{0,0,0}, {{0,0,0}}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.nums;

        // Result
        auto res = sol.threeSum(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
