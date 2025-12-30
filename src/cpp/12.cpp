#include "test.h"
#include "global.h"
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/**
 * Problem 12: Integer to Roman
 * @input: integer num
 * @output: Roman convertion of it
*/
string intToRoman(int num) {
    // Greedy approach
    const vector<pair<int, string>> roman_pairs = {
        {1000, "M"}, {900, "CM"}, 
        {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"}, 
        {50, "L"}, {40, "XL"}, 
        {10, "X"}, {9, "IX"}, 
        {5, "V"}, {4, "IV"}, 
        {1, "I"}
    };

    string roman_str = "";
    for (auto& it : roman_pairs) {
        int value = it.first;
        string symbol = it.second;

        while (num >= value) {
            roman_str += symbol;
            num -= value;
        }
    }

    return roman_str;
}

void test12() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        int num;
        string exp;
    };

    vector<Case> cases = {
        {3749, "MMMDCCXLIX"},
        {58, "LVIII"},
        {1994, "MCMXCIV"}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        string res = intToRoman(c.num);
        assertTest(res, c.exp, i);
    }
}
