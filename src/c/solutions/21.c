
#include "../inc/global.h"
#include "../inc/test.h"
#include "../utils/compare.h"
#include "../utils/print.h"
#include "../inc/debug.h"

// Display info of the approach
#define INFO

// Approach
#define APR 1
#if APR == 1
static char apr_idea[40] = "";
static char time_cmplx[20] = "";
static char space_cmplx[20] = "";
#endif

/*
Problem 21: Merge Two Sorted Lists
LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/
*/
#if APR == 1
// Code
#endif

void test21() {
    #ifdef INFO
    printf("\033[35m=========== INFO ===========\033[0m\n");
    printf("Approach %d: %s\n", APR, apr_idea);
    printf("  + Time Complexity: O(%s)\n", time_cmplx);
    printf("  + Space Complexity: O(%s)\n", space_cmplx);
    #endif
    
    printf("\033[35m========== TESTCASE ========\033[0m\n");
    struct Case {
        // Input

        // Expect

    } cases[] = {
        // {}
    };

    // Assert test
    int numCases = (int)(sizeof(cases)/sizeof(cases[0]));
    for (int i = 0; i < numCases; ++i) {
        struct Case c = cases[i];
        // Solver(...)
        // Assert Test
        if (assertTest(res, rn, c.exp, c.en, i, sizeof(int), cmp_int, print_int) == false) {
            // Print input if needed
        }
    }
}