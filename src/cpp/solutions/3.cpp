#include "../inc/global.h"
using namespace std;



// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Using unordered_set";
string time_cmplx = "n";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 3: Longest Substring Without Repeating Characters
 * LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
class Solution {
public:
    #if APR == 1
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_set<char> seen;
        int left = 0, right = 0;
        int maxLength = 0;
        
        while (right < (int)s.size()) {
            // If character at right is not in current window
            if (seen.find(s[right]) == seen.end()) {
                seen.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                // Remove characters from left until duplicate is removed
                seen.erase(s[left]);
                left++;
            }
        }
        
        return maxLength;
    }
    #endif
};


void test3() {
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
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.s;

        // Result
        auto res = sol.lengthOfLongestSubstring(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
