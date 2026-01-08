#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 2
#ifdef INFO
#if APR == 1
string apr_idea = "Brute-force";
string time_cmplx = "";
string space_cmplx = "";
#elif APR == 2
string apr_idea = "Greatest Common Divisor";
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 1071: Greatest Common Divisor of Strings
 * LeetCode: https://leetcode.com/problems/greatest-common-divisor-of-strings/
 * @explain: "ABABAB" & "ABAB" -> "AB" is a divisor
*/
class Solution {
private:
    string joinWords(string str, int k) {
        string ret = "";
        for (int i = 0; i < k; ++i) {
            ret += str;
        }
        return ret;
    }

    bool valid(string str1, string str2, int k) {
        int len1 = str1.size();
        int len2 = str2.size();
        if (len1 % k > 0 || len2 % k > 0) {
            return false;
        } else {
            string base = str1.substr(0, k);
            int n1 = len1 / k, n2 = len2 / k;
            return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
        }
    }
public:
    #if APR == 1
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }
    }
    #elif APR == 2
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";

        int gcd_len = __gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_len);
    }
    #endif
};


void test1071() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        string str1;
        string str2;
        // Expect
        string exp;
    };

    vector<Case> cases = {
        // {{}}
        {"ABCABC", "ABC", "ABC"},
        {"ABABAB", "ABAB", "AB"},
        {"LEET", "CODE", ""},
        {"AAAAAB", "AAA", ""}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.str1;
        auto &in2 =c.str2;

        // Result
        auto res = sol.gcdOfStrings(in1, in2);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
