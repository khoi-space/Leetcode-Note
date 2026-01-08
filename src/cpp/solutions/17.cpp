#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Backtracking";
string time_cmplx = "4^n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 17: Letter Combinations of a Phone Number
 * LeetCode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
public:
    #if APR == 1
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty()) return res;

        unordered_map<char, string> digit_to_letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        backtrack(digits, 0, "", res, digit_to_letters);

        return res;
    }
private:
    void backtrack(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digit_to_letters) {
        if (idx == (int)digits.length()) {
            res.push_back(comb);
            return;
        }

        string letters = digit_to_letters.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, res, digit_to_letters);
        }
    }
    #endif
};


void test17() {
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
        string digits;
        // Expect
        vector<string> exp;
    };

    vector<Case> cases = {
        // {{}}
        {"23", {"ad","ae","af","bd","be","bf","cd","ce","cf"}},
        {"2", {"a","b","c"}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.digits;

        // Result
        auto res = sol.letterCombinations(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
