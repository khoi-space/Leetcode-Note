//#define DEBUG
#include "test.h"
#include "global.h"
using namespace std;

#define MAX_APR 1
#define APR     1

/**
 * Problem 1207: Unique Number of Occurrences
 * @input: arr of int
 * @output: true if the number of occurrences of each value is unique
 * @explain: occurrence == freq
*/
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

void test1207() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> arr;
        bool exp;
    };

    vector<Case> cases = {
        {{1,2,2,1,1,3},true},
        {{1,2}, false},
        {{-3,0,1,-3,1,1,1,-3,10,0}, true}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        auto res = uniqueOccurrences(c.arr);
        assertTest(res, c.exp, i);
    }
}
