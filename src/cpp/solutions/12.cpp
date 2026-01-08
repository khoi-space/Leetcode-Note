#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Greedy";
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 12: Integer to Roman
 * LeetCode: https://leetcode.com/problems/integer-to-roman/
*/
class Solution {
public:
    #if APR == 1
    string intToRoman(int num) {
        // Create a dictionary
        const vector<pair<int, string>> roman_pairs = {
            {1000, "M"}, {900, "CM"}, 
            {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, 
            {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, 
            {5, "V"}, {4, "IV"}, 
            {1, "I"}
        };

        string roman_str = "";
        for (auto& it : roman_pairs) {
            int value = it.first;
            string symbol = it.second;

            while (num >= value) {
                roman_str += symbol;
                num -= value;
            }
        }

        return roman_str;
    }
    #endif
};


void test12() {
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
        int num;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {3749, "MMMDCCXLIX"},
        {58, "LVIII"},
        {1994, "MCMXCIV"}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.num;

        // Result
        auto res = sol.intToRoman(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
