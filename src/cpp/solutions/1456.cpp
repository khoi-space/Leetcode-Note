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
 * Problem 1456: Maximum Number of Vowels in a Substring of Given Length
 * LeetCode: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int s_len = s.length();
        int max_vowel_len = 0;
        int cur_vowel_len = 0;

        for (int i = 0; i < k; ++i) {
            cur_vowel_len += (isVowel(s[i])) ? 1 : 0;
        }
        max_vowel_len = cur_vowel_len;

        for (int i = k; i < s_len; ++i) {
            if (max_vowel_len == k) return k; // The window are all vowels
            cur_vowel_len += isVowel(s[i]) ? 1 : 0;
            cur_vowel_len -= isVowel(s[i-k]) ? 1 : 0;

            max_vowel_len = max(max_vowel_len, cur_vowel_len);
        }
        return max_vowel_len;
    }
private:
    #if APR == 1
    bool isVowel(char c) {
        static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        return (vowels.find(c) != vowels.end());
    }
    #elif APR == 2
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
    #endif
};


void test1456() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string s;
        int k;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {"abciiidef", 3, 3},
        {"aeiou", 2, 2},
        {"leetcode", 3, 2}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.s;
        auto &in2 = c.k;

        // Result
        auto res = sol.maxVowels(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
