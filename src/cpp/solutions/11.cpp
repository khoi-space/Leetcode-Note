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
string time_cmplx = "n^2";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Two Pointers";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 11: Container With Most Water
 * LeetCode: https://leetcode.com/problems/container-with-most-water/
*/
class Solution {
public:
    #if APR == 1
    int maxArea(vector<int>& height) {
        int _size = height.size();
        int max_area = 0;
        for (int i = 0; i < _size; ++i) {
            for (int j = 0; j < _size; ++j) {
                if (j != i) {
                    int min_height = min(height[i], height[j]);
                    int width = abs(j - i);
                    int area = min_height * width;
                    if (area > max_area) max_area = area;
                }
            }
        }
        return max_area;
    }
    #elif APR == 2
    int maxArea(vector<int>& height) {
        int _size = height.size();
        int l = 0;
        int r = _size - 1;
        int max_area = 0;

        while (l < r) {
            int min_height = min(height[l], height[r]);
            int width = r - l;
            int area = min_height * width;
            if (max_area < area) max_area = area;

            if (height[l] < height[r]) ++l;
            else --r;
        }
        return max_area;
    }
    #endif
};


void test11() {
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
        vector<int> height;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,8,6,2,5,4,8,3,7}, 49},
        {{1,1}, 1}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.height;

        // Result
        auto res = sol.maxArea(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
