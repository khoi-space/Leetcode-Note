#include "../inc/global.h"
#include "../inc/test.h"
#include "../utils/compare.h"
#include "../utils/print.h"

// Debug mode
#define DEBUG
#include "../inc/debug.h"

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
static char apr_idea[40] = "Brute-force";
static char time_cmplx[20] = "n^2";
static char space_cmplx[20] = "1";
#elif APR == 2
static char apr_idea[40] = "Two-pass hash table";
static char time_cmplx[20] = "n";
static char space_cmplx[20] = "n";
#elif APR == 3
static char apr_idea[40] = "One-pass hash table";
static char time_cmplx[20] = "n";
static char space_cmplx[20] = "n";
#endif
#endif

/*
Problem 1: Two Sum
LeetCode: https://leetcode.com/problems/two-sum/
*/
#if APR == 1
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == target - nums[i]) {
                int* result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                db_log(result[0]);
                db_see(result[0]);
                return result;
            }
        }
    }
    // Return an empty array if no solution is found
    *returnSize = 0;
    return malloc(sizeof(int) * 0);
}
#elif APR == 2
int* twoSum(int*nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; ++i) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            int* res = malloc(sizeof(int) * 2);
            res[0] = item->value;
            res[1] = i;

            *returnSize = 2;
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return res;
        }

        item = malloc(sizeof(struct hashTable));
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }
    *returnSize = 0;

    // No valid pair found, return an empty array
    return malloc(sizeof(int) * 0);
}
#elif APR == 3
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable {
        int key;
        int value;
        UT_hash_handle hh;
    } *hashTable = NULL, *item;

    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        HASH_FIND_INT(hashTable, &complement, item);
        if (item) {
            int* res = malloc(sizeof(int) * 2);
            res[0] = item->value;
            res[1] = i;
            *returnSize = 2;
            HASH_CLEAR(hh, hashTable);
            return res;
        }

        item = malloc(sizeof(struct hashTable));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    *returnSize = 0;
    HASH_CLEAR(hh, hashTable);
    return malloc(0);
}
#endif

void test1() {
    #ifdef INFO
    printf("\033[35m=========== INFO ===========\033[0m\n");
    printf("FILE: %s", __FILE__);
    printf("APPROACH %d: %s\n", APR, apr_idea);
    printf("  + Time Complexity: O(%s)\n", time_cmplx);
    printf("  + Space Complexity: O(%s)\n", space_cmplx);
    #endif
    
    printf("\033[35m========== TESTCASE ========\033[0m\n");
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

    int* res = malloc(sizeof(int) * 2);
    int rn;
    int numCases = (int)(sizeof(cases)/sizeof(cases[0]));
    for (int i = 0; i < numCases; ++i) {
        struct Case c = cases[i];
        res = twoSum(c.nums, c.n, c.target, &rn);

        if (assertTest(res, rn, c.exp, c.en, i, sizeof(int), cmp_int, print_int) == false) {
            printf("   Input    : ");
            IntArray input = {c.nums, c.n};
            print_array(&input);
            printf("\n");
        }
    }
}