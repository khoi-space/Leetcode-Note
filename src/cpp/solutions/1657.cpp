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
 * Problem 1657: Determine if Two Strings Are Close
 * LeetCode: https://leetcode.com/problems/determine-if-two-strings-are-close/
 * @explain: 2 strs are clos if can attain on from the other string by:
 * + Operation 1: swap 2 chars
 * + Operation 2: transform every occurrence of one existing char into another existing char
 * Can do multiple times
*/
class Solution {
public:
    #if APR == 1
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;

        // Check if are there any alien char between word1 and word2
        unordered_map<char, int> char_freq_in_word1, char_freq_in_word2;
        for (char c : word1) char_freq_in_word1[c]++;
        for (char c : word2) char_freq_in_word2[c]++;

        if (char_freq_in_word1.size() != char_freq_in_word2.size()) return false;
        for (auto& it : char_freq_in_word1) {
            if (char_freq_in_word2.find(it.first) == char_freq_in_word2.end()) {
                return false;
            }
        }

        // Check if are there any alien freq between word1 and word2
        unordered_map<int, int> freq_count1, freq_count2;
        for (auto it : char_freq_in_word1) freq_count1[it.second]++;
        for (auto it : char_freq_in_word2) freq_count2[it.second]++;

        if (freq_count1.size() != freq_count2.size()) return false;
        for (const auto& p : freq_count1) {
            if (freq_count2[p.first] != p.second) return false;
        }
        return true;
    }
    #endif
};


void test1657() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string word1;
        string word2;
        // Expect
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {"abc", "bca", true},
        {"a", "aa", false},
        {"cabbba", "abbccc", true},
        {"abbzzca", "babzzcz", false}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.word1;
        auto &in2 = c.word2;

        // Result
        auto res = sol.closeStrings(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
