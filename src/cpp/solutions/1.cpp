#include "../inc/test.h"
#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO

// Approach
#define APR 1

#ifdef INFO
#if APR == 1
    string apr_idea = "Brute-force";
    string time_cmplx = "n^^2";
    string space_cmplx = "1";
#elif APR == 2
    string apr_idea = "Two-pass Hash Table";
    string time_cmplx = "n";
    string space_cmplx = "n";
#elif APR == 3
    string apr_idea = "One-pass Hash Table";
    string time_cmplx = "n";
    string space_cmplx = "n";
#endif
#endif

Debug db = Debug{true}; // Turn on/off debug mode

/**
 * Problem 1: Two Sum
 * LeetCode: https://leetcode.com/problems/two-sum/
 * @input:
 * @output:
 */
class Solution {
public:
    #if APR == 1
    vector<int> twoSum(vector<int> &nums, int target) {
        int _size = nums.size();
        for (int i = 0; i < _size; i++) {
            for (int j = i + 1; j < _size; j++) {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        // Return an empty vector if no solution is found
        return {};
    }
    #elif APR == 2
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        int _size = nums.size();
        for (int i = 0; i < _size; i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < _size; i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }
        // If no valid pair is found, return an empty vector
        return {};
    }
    #elif APR == 3
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        int _size = nums.size();
        for (int i = 0; i < _size; ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
    #endif
};


void test1() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "Approach " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endif
    cout << "\033[35m========== TESTCASE ========\033[0m\n";

    struct Case {
        // Inputs
        vector<int> nums;
        int target;
        // Expect
        vector<int> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{2,7,11,15}, 9, {0,1}},
        {{3,2,4}, 6, {1,2}},
        {{3,3}, 6, {0,1}}
    };

    Solution sol = Solution();

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        // Inputs
        auto in1 = c.nums;
        auto in2 = c.target;

        // Result
        auto res = sol.twoSum(c.nums, c.target);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << ", " << in2 << endl;
        }
    }
}
