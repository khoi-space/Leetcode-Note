#include "test.h"
#include "global.h"
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/**
 * Problem 3074: Apple Redistribution into Boxes
 * @input: apple[i] represents the size of each apple, capacity[i] represent the size of each box
 * @output: the minimum of boxes need to select to redistribute these n packs of apples into boxes
*/
int minumumBoxes(vector<int>& apple, vector<int>& capacity) {
    int num_boxes = 0;

    int sum = 0;
    for (int i : apple) {
        sum += i;
    }

    sort(capacity.begin(), capacity.end(), greater<int>());
    while (sum > 0) {
        sum -= capacity[num_boxes];
        num_boxes += 1;
    }

    return num_boxes;
    // Time: O(n)
    // Space: depend on sorting O(1) if in-place, O(n) otherwise
}

void test3074() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> apple;
        vector<int> capacity;
        int exp;
    };

    vector<Case> cases = {
        {{1,3,2}, {4,3,1,5,2}, 2},
        {{5,5,5}, {2,4,2,7}, 4}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = minumumBoxes(c.apple, c.capacity);
        assertTest(res, c.exp, i);
    }
}
