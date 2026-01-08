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
 * Problem 1732: Find the Highest Altitude
 * LeetCode: https://leetcode.com/problems/find-the-highest-altitude/
 * @input: integer array "gain" of length "n" where gain[i] is the net gain in altitude between i and i+1
 * @output: the highest altitude of a point
*/
class Solution {
public:
    #if APR == 1
    int largestAltitude(vector<int>& gain) {
        int _size = gain.size();
        vector<int> altitudes(_size + 1);
        int highest_altitude = 0;
        altitudes[0] = 0;

        for (int i = 0; i < _size; ++i) {
            altitudes[i + 1] = altitudes[i] + gain[i];
        }

        for (int altitude : altitudes) {
            highest_altitude = max(highest_altitude, altitude);
        }
        return  highest_altitude;
    }
    #endif
};


void test1732() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> gain;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{-5,1,5,0,-7}, 1},
        {{-4,-3,-2,-1,4,3,2}, 0}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.gain;

        // Result
        auto res = sol.largestAltitude(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
