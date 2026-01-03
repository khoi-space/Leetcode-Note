// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/**
 * Problem 1732: Find the Highest Altitude
 * @input: integer array "gain" of length "n" where gain[i] is the net gain in altitude between i and i+1
 * @output: the highest altitude of a point
*/
int largestAltitude(vector<int>& gain) {
    int _size = gain.size();
    vector<int> altitudes(_size + 1);
    int highest_altitude = 0;
    altitudes[0] = 0;

    for (int i = 0; i < _size; ++i) {
        altitudes[i + 1] = altitudes[i] + gain[i];
    }

    for (int altitude : altitudes) {
        highest_altitude = max(highest_altitude, altitude);
    }
    return  highest_altitude;
}


void test1732() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> gain;
        int exp;
    };

    vector<Case> cases = {
        {{-5,1,5,0,-7}, 1},
        {{-4,-3,-2,-1,4,3,2}, 0}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        int res = largestAltitude(c.gain);
        assertTest(res, c.exp, i);
    }
}
