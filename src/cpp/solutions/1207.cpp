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
 * Problem 1207: Unique Number of Occurrences
 * LeetCode: https://leetcode.com/problems/unique-number-of-occurrences/
 * @explain: return true if the num of occurrence of each value is unique
*/
class Solution {
public:
    #if APR == 1
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count freq of each num in arr
        for (int num : arr) {
            ++freq[num];
        }

        // Check if all freqs are unique
        unordered_set<int> seen;
        for (auto f : freq) {
            if (seen.insert(f.second).second == false) return false; 
        }

        return true;
    }
    #endif
};


void test1207() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> arr;
        // Expect
        bool exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,2,1,1,3},true},
        {{1,2}, false},
        {{-3,0,1,-3,1,1,1,-3,10,0}, true}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.arr;

        // Result
        auto res = sol.uniqueOccurrences(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
