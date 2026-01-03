//#define DEBUG
// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

#define MAX_APR 1
#define APR     1

/**
 * Problem 1657: Determine if Two Strings Are Close
 * @explain: 2 strs are close if can attain one from the other using:
 * + Operation 1: swap 2 chars
 * + Operation 2: transform every occurrence of one existing char into another existing char 
*/
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

void test1657() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        string word1;
        string word2;
        bool exp;
    };

    vector<Case> cases = {
        {"abc", "bca", true},
        {"a", "aa", false},
        {"cabbba", "abbccc", true},
        {"abbzzca", "babzzcz", false}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        auto res = closeStrings(c.word1, c.word2);
        assertTest(res, c.exp, i);
    }
}
