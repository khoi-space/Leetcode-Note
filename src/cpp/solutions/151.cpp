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
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 151: Reverse Words in a String
 * LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/
 * @explain: " hello world " -> "world hello"
*/
class Solution {
public:
    #if APR == 1
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string res;
        for (int i = words.size() - 1; i >= 0; --i) {
            res += words[i];
            if (i != 0) {
                res += " ";
            }
        }
        return res;
    }
    #endif
};


void test151() {
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
        string s;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {"the sky is blue", "blue is sky the"},
        {"  hello world  ", "world hello"},
        {"a good   example", "example good a"}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.s;

        // Result
        auto res = sol.reverseWords(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
