#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Greedy";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 3090: Maximum Length Substring With Two Occurrences
 * LeetCode: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
*/
class Solution {
public:
    #if APR == 1
    int minumumBoxes(vector<int>& apple, vector<int>& capacity) {
        int num_boxes = 0;

        int sum = 0;
        for (int i : apple) {
            sum += i;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());
        while (sum > 0) {
            sum -= capacity[num_boxes];
            num_boxes += 1;
        }

        return num_boxes;
        // Time: O(n)
        // Space: depend on sorting O(1) if in-place, O(n) otherwise 
    }
    #endif
};


void test3090() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> apple;
        vector<int> capacity;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,3,2}, {4,3,1,5,2}, 2},
        {{5,5,5}, {2,4,2,7}, 4}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.apple;
        auto &in2 = c.capacity;

        // Result
        auto res = sol.minumumBoxes(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
