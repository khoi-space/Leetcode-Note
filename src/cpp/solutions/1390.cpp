#include "../inc/global.h"
using namespace std;

// Display info of the approach
#define INFO
#define APR 2
#ifdef INFO
#if APR == 1
string apr_idea = "Direct Divisor Counting";
string time_cmplx = "n x sqrt(m)";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Mathematic";
string time_cmplx = "n x sqrt(m)";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 1390: Four Divisors
 * LeetCode: https://leetcode.com/problems/four-divisors/
*/
class Solution {
public:
    #if APR == 1
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        int required_num_div = 4;
        for (int num : nums) {
            ans += sumDiv(num, required_num_div);
        }
        return ans;
    }
private:
    int sumDiv(int num, int required_num_div) {
        int cnt = 0, sum = 0;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                ++cnt;
                sum += i;

                if (i != num / i) {
                    ++cnt;
                    sum += num / i;
                }
                if (cnt > required_num_div) return 0;
            }
        }
        return (cnt == required_num_div) ? sum : 0;
    }
    #elif APR == 2
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            // Case 1: num = p^3 (p is prime)
            int root = round(pow(num, 1.0/3));
            if (root * root * root == num && isPrime(root)) {
                ans += 1 + root + root*root + num;
                continue;
            }
            // Case 2: num = p * q (p != q, both primes)
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    int j = num / i;
                    if (i != j && isPrime(i) && isPrime(j)) {
                        ans += 1 + i + j + num;
                    }
                    break;
                }
            }
        }
        return ans;
    }
private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    #endif
};

void test1390() {
    #ifdef INFO
    printInfo(__FILE__, APR, apr_idea, time_cmplx, space_cmplx);
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> nums;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{21,4,7}, 32},
        {{21,21}, 64},
        {{1,2,3,4,5}, 0}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        // Inputs
        auto &in1 = c.nums;

        // Result
        auto res = sol.sumFourDivisors(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
