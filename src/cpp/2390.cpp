#define DEBUG
#include "test.h"
#include "global.h"
using namespace std;

#define MAX_APR 2
#define APR     2

static string apr_idea = "";

/**
 * Problem 2390: Removing Stars From a String
 * @input: a string which contains start '*'
 * @output: consider '*' as a backspace cmd, remove its left char and itself
*/
string removeStars(string s) {
    #if APR == 1
    apr_idea = "Copy to a new string";

    string ans = "";
    stack<char> st;
    int cnt_star = 0;
    int _size = s.size();

    for (int i = _size - 1; i >= 0; --i) {
        if (s[i] == '*') {
            ++cnt_star;
        } else {
            if (cnt_star > 0) {
                --cnt_star;
            } else {
                st.push(s[i]);
            }
        }
    }

    int n = st.size();
    for (int i = 0; i < n; ++i) {
        ans += st.top();
        st.pop();
    }

    return ans;
    #elif APR == 2
    apr_idea = "In-place";

    string ans = s;
    int idx = 0;
    
    for (char c : s) {
        if (c != '*') {
            ans[idx] = c;
            ++idx;
        } else {
            if (idx > 0) {
                --idx;
            }
        }
    }

    return ans.substr(0, idx);
    #endif
}

void test2390() {
    struct Case {
        string s;
        string exp;
    };

    vector<Case> cases = {
        {"leet**cod*e", "lecoe"},
        {"erase*****", ""},
        {"abb*cdfg*****x*", "a"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        string res = removeStars(c.s);
        assertTest(res, c.exp, i);
    }

    #ifdef APR
    cout << "--------------------------------" << endl;
    cout << "\033[1m\033[34mApproach:\033[0m " << APR << " / " << MAX_APR << endl;
    cout << ">>>> " << apr_idea << endl;
    #endif
}
