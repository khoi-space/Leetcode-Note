#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 2
#ifdef INFO
#if APR == 1
string apr_idea = "Math";
string time_cmplx = "n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Parity Counting";
string time_cmplx = "n";
string space_cmplx = "1";
#elif APR == 3
string apr_idea = "Prefix Parity scan";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 3432: Count Partitions with Even Sum Difference
 * LeetCode: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
*/
class Solution {
public:
    #if APR == 1
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        return totalSum % 2 == 0 ? nums.size() - 1 : 0;
    }
    #elif APR == 2
    int countPartitions(vector<int>& nums) {
        int oddCount = 0;
        for (int num : nums) {
            if (num % 2 != 0) {
                ++oddCount;
            }
        }
        return (oddCount % 2 == 0) ? nums.size() - 1 : 0;
    }
    #elif APR == 3
    int countPartitions(vector<int>& nums) {
        bool totalOdd = false;
        for (int num : nums) {
            if (num % 2 != 0) {
                totalOdd = !totalOdd;
            }
        }

        bool prefixOdd = false;
        int partitions = 0;
        for (size_t i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] % 2 != 0) {
                prefixOdd = !prefixOdd;
            }
            bool suffixOdd = totalOdd ^ prefixOdd;
            if (prefixOdd == suffixOdd) {
                ++partitions;
            }
        }
        return partitions;
    }
    #endif
};


void test3432() {
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
        {{1, 2}, 0},
        {{1, 1}, 1},
        {{2, 4, 6}, 2},
        {{3, 5, 7}, 0},
        {{0, 0, 0, 0}, 3},
        {{10}, 0},
        {{1, 2, 3, 4}, 3},
        {{1, 3, 5, 7}, 3},
        {{2, 3, 5, 8, 13}, 0},
        {{1000000000, 1000000000}, 1},
        {{1, -1, 1, -1}, 3},
        {{4, 4, 4, 4, 4, 4}, 5},
        {{1, 0, 1}, 2},
        {{5, -3, 2}, 2},
        {{9, -4, -5}, 2},
        {{7, 7, 7, 7, 7}, 0},
        {{2, 2, 2, 2, 3}, 0},
        {{2, 2, 2, 2, 2}, 4},
        {{1, 2, 3, 4, 5, 6}, 0},
        {{8, 1, 1, 8}, 3}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.countPartitions(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
