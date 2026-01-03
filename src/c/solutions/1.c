#define DEBUG

#include "inc/test.h"
#include "inc/global.h"
#include "../utils/convert.h"
#include <stdio.h>
#include <stdbool.h>

#define APR 2

/* Brute-force Two Sum in C
* Inputs: nums array, length n, target
* Output: out[0], out[1] indices and outLen=2 if found; else outLen=0
*/
static void twoSum(const int* nums, int n, int target, int out[2], int* outLen) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                out[0] = i;
                out[1] = j;
                *outLen = 2;
                return;
            }
        }
    }
    *outLen = 0;
}

void test1() {
    printf("Approach %d\n", APR);

    struct Case {
        int nums[8];
        int n;
        int target;
        int exp[2];
        int en;
    } cases[] = {
        { {2,7,8,6,4,3}, 6, 9,  {0,1}, 2 },
        { {3,2,4},       3, 6,  {1,2}, 2 },
        { {3,3},         2, 6,  {0,1}, 2 },
        { {1,2,3},       3, 7,  {0,0}, 0 }, /* no solution */
    };

    int res[2];
    int rn;
    int numCases = (int)(sizeof(cases)/sizeof(cases[0]));
    for (int i = 0; i < numCases; ++i) {
        twoSum(cases[i].nums, cases[i].n, cases[i].target, res, &rn);
        assertTestArray(res, rn, cases[i].exp, cases[i].en, i+1);
    }
}