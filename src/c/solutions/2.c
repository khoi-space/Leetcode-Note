
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
static char apr_idea[40] = "Elementary Math";
static char time_cmplx[20] = "max(m,n)";
static char space_cmplx[20] = "1";
#endif
#endif
/*
Problem 2: Add Two Numbers
LeetCode: https://leetcode.com/problems/add-two-numbers/
*/
#if APR == 1
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* curr = dummyHead;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = sum % 10;
        curr->next->next = NULL;
        curr = curr->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    struct ListNode* result = dummyHead->next;
    free(dummyHead);  // Free the memory allocated for dummyHead
    return result;
}
#endif

void test2() {
    #ifdef INFO
    printf("\033[35m=========== INFO ===========\033[0m\n");
    printf("FILE: %s", __FILE__);
    printf("APPROACH %d: %s\n", APR, apr_idea);
    printf("  + Time Complexity: O(%s)\n", time_cmplx);
    printf("  + Space Complexity: O(%s)\n", space_cmplx);
    #endif
    
    printf("\033[35m========== TESTCASE ========\033[0m\n");
    struct Case {
        int l1[20]; int l1_len;
        int l2[20]; int l2_len;
        int exp[20]; int exp_len;
    } cases[] = {
        {.l1={2,4,3}, .l1_len=3, .l2={5,6,4}, .l2_len=3, .exp={7,0,8}, .exp_len=3},
        {.l1={0}, .l1_len=1, .l2={0}, .l2_len=1, .exp={0}, .exp_len=1},
        {.l1={9,9,9,9,9,9,9}, .l1_len=7, .l2={9,9,9,9}, .l2_len=4, .exp={8,9,9,9,0,0,0,1}, .exp_len=8}
    };

    struct ListNode *l1, *l2, *exp;
    int numCases = (int)(sizeof(cases)/sizeof(cases[0]));
    for (int i = 0; i < numCases; ++i) {
        struct Case c = cases[i];
        l1 = list_create_from_array(c.l1, c.l1_len);
        l2 = list_create_from_array(c.l2, c.l2_len);
        exp = list_create_from_array(c.exp, c.exp_len);
        struct ListNode* res = addTwoNumbers(l1, l2);
        if (assertTest(res, -1, exp, -1, i, sizeof(int), cmp_list, print_list) == false) {
            printf("  Input    :\n");
            printf("    l1="); print_list(l1);
            printf("    l2="); print_list(l2);
        }
        list_free(l1);
        list_free(l2);
        list_free(exp);
    }
}