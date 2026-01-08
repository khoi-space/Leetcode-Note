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
 * Problem 1431: Kids With the Greatest Number of Candies
 * LeetCode: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/
class Solution {
public:
    #if APR == 1
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = 0;
        for (int candy : candies) {
            if (candy > max_candies) {
                max_candies = candy;
            }
        }

        vector<bool> res;
        for (int candy : candies) {
            res.push_back(candy + extraCandies >= max_candies);
        }
        return res;
    }
    #endif
};


void test1431() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> candies;
        int extraCandies;
        // Expect
        vector<bool> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{2,3,5,1,3}, 3, {true,true,true,false,true}},
        {{4,2,1,1,2}, 1, {true,false,false,false,false}},
        {{12,1,12}, 10, {true,false,true}},
        {{2,8,7}, 1, {false,true,true}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.candies;
        auto &in2 = c.extraCandies;

        // Result
        auto res = sol.kidsWithCandies(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
