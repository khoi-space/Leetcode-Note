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
 * Problem 345: Reverse Vowels of a String
 * LeetCode: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * @explain: vowels are 'a', 'e', 'i', 'o' and 'u' in both lower and upper cases
*/
class Solution {
public:
    #if APR == 1
    string reverseVowels(string s) {
        unordered_set<char> vowels_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (vowels_set.find(s[l]) == vowels_set.end()) {
                ++l;
            } else if (vowels_set.find(s[r]) == vowels_set.end()) {
                --r;
            } else {
                // swap s[l] and s[r]
                swap(s.at(l), s.at(r));
                // db_var(s);
        
                // Move the pointer to the next
                ++l;
                --r;
            }
        }
        return s;
    }
    #endif
};


void test345() {
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
        {"IceCreAm", "AceCreIm"},
        {"leetcode", "leotcede"}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.s;

        // Result
        auto res = sol.reverseVowels(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
