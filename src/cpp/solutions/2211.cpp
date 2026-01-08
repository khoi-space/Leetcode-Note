#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Simulation";
string time_cmplx = "n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Counting";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 2211: Count Collision on a Road
 * LeetCode: https://leetcode.com/problems/count-collision-on-a-road/
 * @explain: Cars run at same speed:
 *  ans += 2 if 2 cars move  inn opposite dir
 *  ans += 1 if one car stays and collides with another car
 * @dict: 'L' - left, 'R' - right, 'S' - stay
*/
class Solution {
public:
    #if APR == 1
    int countCollisions(string directions) {
        int collision_count = 0;
        int right_move_count = -1;
        for (char direction : directions) {
            if (direction == 'L') {
                if (right_move_count >= 0) {
                    collision_count += right_move_count + 1;
                    right_move_count = 0;
                }
            } else if (direction == 'S') {
                if (right_move_count > 0) {
                    collision_count += right_move_count;
                }
                right_move_count = 0;
            } else if (direction == 'R') {
                if (right_move_count >= 0) {
                    ++right_move_count;
                } else {
                    right_move_count = 1;
                }
            } else {
                return -1;
            }
        }
        return collision_count;
    }
    #elif APR == 2
    int countCollisions(string directions) {
        int collision_count = 0;
        int n = directions.size();
        int l = 0, r = n - 1;
        // Skip all left at head
        while (l < n && directions[l] == 'L') {
            ++l;
        }
        // Skip all right at tail
        while (r >= l && directions[r] == 'R') {
            --r;
        }

        // Count values that not 'S' in the rest
        for (int i = l; i <= r; ++i) {
            char d = directions[i];
            if (d == 'S') continue;
            if (d != 'L' && d != 'R') return -1; // Invalid
            ++collision_count;
        }
        return collision_count;
    }
    #endif
};


void test2211() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string directions;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {"RLRSLL", 5},
        {"LLRR", 0},
        {"SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR", 20},
        {"S", 0},
        {"R", 0},
        {"L", 0},
        {"RS", 1},
        {"SL", 1},
        {"RRLL", 4},
        {"RRSLL", 4},
        {"LRLSL", 3},
        {"RLRL", 4},
        {"SR", 0},
        {"LS", 0},
        {"SSSS", 0},
        {"", 0},
        {"RRS", 2},
        {"LLS", 0},
        {"SRS", 1},
        {"RSL", 2},
        {"RXRL", -1} // Invalid directions
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.directions;

        // Result
        auto res = sol.countCollisions(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
