// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

//#define DEBUG
#define MAX_APR 2
#define APR     2

bool isVowel(char c);

/**
 * Problem 1456: Maximum Number of Vowels in a Substring of Given Length
 * @input: string s, int k
 * @output: maximum num of vowel letters in any substring of s with length k
*/
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

bool isVowel(char c) {
#if APR == 1 
    static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    return (vowels.find(c) != vowels.end());
#elif APR == 2
    c = tolower(c);
    return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
#endif
}

void test1456() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        string s;
        int k;
        int exp;
    };

    vector<Case> cases = {
        {"abciiidef", 3, 3},
        {"aeiou", 2, 2},
        {"leetcode", 3, 2}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = maxVowels(c.s, c.k);
        assertTest(res, c.exp, i);
    }
}
