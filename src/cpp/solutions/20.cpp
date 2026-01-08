#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Push to stack";
string time_cmplx = "n";
string space_cmplx = "n";
#elif APR ==2
string apr_idea = "Combination of stack and hashmap";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 20: Valid Parentheses
 * LeetCode: https://leetcode.com/problems/valid-parentheses/
*/
class Solution {
public:
    #if APR == 1
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if(!st.empty()) {
                if (isPair(st.top(), c)) {
                    st.pop();
                    continue;
                }
            }
            // If !st.empty() or !isPair(last, cur), push cur to st
            st.push(c);
        }
        
        return st.empty();
    }
private:
    bool isPair(char last, char cur) {
        return  (last == '{' && cur == '}') ||
                (last == '[' && cur == ']') ||
                (last == '(' && cur == ')');
    }
    #elif APR ==2
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);
            } else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();        
    }
    #endif
};


void test20() {
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
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},
        {"", true},
        {"(((((", false},
        {"(([]){})", true},
        {"([)", false},
        {"[", false},
        {"]", false}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto in1 = c.s;

        // Result
        auto res = sol.isValid(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
