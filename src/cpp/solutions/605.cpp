#include "../inc/global.h"
using namespace std;

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
 * Problem 605: Can Place Flowers
 * LeetCode: https://leetcode.com/problems/can-place-flowers/
 * @note: flowers can't be planted in adjacent plots
*/
class Solution {
public:
    #if APR == 1
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Try to plant at the even idx (begin with 0)
        int len = flowerbed.size();
        int remain = n;
        for (int i = 0; i < len && remain != 0; ++i) {
            if (flowerbed[i] == 0) {
                bool empty_left = (i == 0) || (flowerbed[i-1] == 0);
                bool empty_right = (i == len - 1) || (flowerbed[i+1] == 0);

                if (empty_left && empty_right) {
                    flowerbed[i] = 1;
                    --remain;
                }
            }
        }
        return (remain == 0);
    }
    #endif
};


void test605() {
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
        vector<int> flowerbed;
        int n;
        // Expect
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,0,0,0,1}, 1, true},
        {{1,0,0,0,1}, 2, false},
        {{0,0,1,0,1}, 1, true}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.flowerbed;
        auto &in2 = c.n;

        // Result
        auto res = sol.canPlaceFlowers(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
