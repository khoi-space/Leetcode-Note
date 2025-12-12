#include "solution.h"
#include "test.h"
using namespace std;

int approach = 0;

/**
 * Problem 7: Reverse Integer
 * @input: a signed 32-bit integer x
 * @output: a reverse of x
 */
int Solution::reverse(int x) {
    if (approach == 1) {
        // Approach 1: Pop & push digits
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) // INT_MAX = 2,147,483,647
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) // INT_MIN = -2,147,483,648
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    } else if (approach == 2) {
        // Approach 2: Convert to string
        string conv = "";
        int rev = 0;
        while (x != 0) {
            conv += (char)((x % 10) + '0');
            x /= 10;
        }

        for (char c : conv) {
            int digit = c - '0';
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;
            rev = rev * 10 + digit;
        }
        return rev;
    }
    return 0;
}

void Test::test7() {
    cout << "Approach:\n";
    cout << "1. Pop & push\n";
    cout << "2. Convert to string\n";
    cout << ">>> "; cin >> approach;

    struct Case {
        int x;
        int exp;
    };

    vector<Case> cases = {
        {123, 321},
        {-123, -321},
        {120, 21},
        {123456789, 987654321}
    };

    extern Solution sol;
    bool allPassed = true;
    for (auto& c : cases) {
        static int i = 0;
        ++i;
        int res = sol.reverse(c.x);
        if (res != c.exp) {
            allPassed = false;
            cout << "\033[31mFAILED\033[0m case " << i << ": exp=" << c.exp << " got=" << res << endl;
        }
    }
    
    if (allPassed) {
        cout << "\033[32mPASSED\033[0m\n";
    }
}