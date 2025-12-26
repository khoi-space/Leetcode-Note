#include "test.h"
#include "global.h"
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/**
 * Problem 955: Delete Columns to Make Sorted II
 * @input: n strings with the same length
 * @rule: delete all the chars in indices for each string so that each final array is lexicographically
 * @example: strs = {"abcdef", "uvwxyz"} --del(0,2,3)--> strs = {"bef", "vyz"}
 * @output: minumum of ans.length
*/
int minDeletionSize(vector<string>& strs) {
    int strs_size = strs.size();
    int str_len = strs[0].size();
    // vector<bool> resolved(strs_size - 1, false);
    bool *resolved = new bool[strs_size - 1];
    int unresolved = strs_size - 1;
    int ans = 0;

    for (int col = 0; col < str_len && unresolved > 0; ++col) {
        bool bad = false;

        // Check for violation
        for (int i = 0; i < strs_size - 1; ++i) {
            if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
                bad = true;
                break;
            }
        }

        if (bad) {
            ++ans;
            continue;
        }

        // Update resolved array
        for (int i = 0; i < strs_size - 1; ++i) {
            if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
                resolved[i] = true;
                --unresolved;
            }
        }
    }
    ddelete[] resolved;
    return ans;
}

void test955() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<string> strs;
        int exp;
    };

    vector<Case> cases = {
        {{"ca","bb","ac"}, 1},
        {{"xc","yb","za"}, 0},
        {{"zyx","wvu","tsr"}, 3}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = minDeletionSize(c.strs);
        assertTest(res, c.exp, i);
    }
}
