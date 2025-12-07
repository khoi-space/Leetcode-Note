#include "solution.h"
#include "test.h"
using namespace std;

int approach = 0;
/**
 * Problem 1523: Count Odd Numbers in an Interval Range
 * @input: two unsigned int low and high
 * @output: count of odd numbers in [low, high]
 */
int Solution::countOdds(int low, int high) {
    if (approach == 1) {
        // Approach 1
        // If low is even, start from low+1
        // If high is even, end at high-1
        if (low % 2 == 0) ++low;
        if (high % 2 == 0) --high;
        return (high - low) / 2 + 1;
    } else if (approach == 2) {
        // Approach 2
        // Subtract the odd numbers from 0 to high and the odd number from 0 to low-1
        // Equal with (high-0+1)/2 - (low-1+1)/2 
        return (high + 1) / 2 - (low / 2);
    }
    return 0;
}

void Test::test1523() {
    cout << "Approach:\n";
    cout << "1. Readable\n";
    cout << "2. Count from 0\n";
    cout << ">>> "; cin >> approach;

    struct Case {
        int low;
        int high;
        int exp;
    };

    vector<Case> cases = {
        {3, 7, 3},
        {8, 10, 1},
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0},
        {0, 1, 1},
        {1, 10, 5},
        {21, 22, 1},
        {100, 200, 50},
    };

    extern Solution sol;
    bool allPassed = true;

    for (auto& c : cases) {
        int res = sol.countOdds(c.low, c.high);
        if (res != c.exp) {
            allPassed = false;
            cout << "\033[31mFAILED\033[0m: res=" << res << ", exp=" << c.exp << ", low=" << c.low << ", high=" << c.high << endl;
        }
    }
    if (allPassed) {
        cout << "\033[32mPASSED\033[0m\n";
    }
}