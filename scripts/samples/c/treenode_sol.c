
#include "../inc/global.h"
#include "../inc/test.h"
#include "../utils/compare.h"
#include "../utils/print.h"

// Debug mode
#define DEBUG
#include "../inc/debug.h"

// Display info of the approach
#define INFO

// Approach
#define APR 1
#ifdef INFO
#if APR == 1
static char apr_idea[40] = "";
static char time_cmplx[20] = "";
static char space_cmplx[20] = "";
#endif
#endif

/*
Problem 1339: Maximum Product of Splitted Binary Tree
LeetCode: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/
#if APR == 1
// Code
long long total_sum = 0;
long long max_product = 0;
const int MOD = 1e9 + 7;

long long _countTotalSum(struct TreeNode* node) {
    if (!node) return 0;
    return node->val + _countTotalSum(node->left) + _countTotalSum(node->right);
}

long long _countMaxProduct(struct TreeNode* node) {
    if (!node) return 0;

    long long left = _countMaxProduct(node->left);
    long long right = _countMaxProduct(node->right);
    long long sub = node->val + left + right;
    long long product = sub * (total_sum - sub);

    if (product > max_product) max_product = product;

    return sub;
}

int maxProduct(struct TreeNode* root) {
    max_product = 0;
    total_sum = _countTotalSum(root);
    _countMaxProduct(root);
    return max_product % MOD;
}
#endif

void test1339() {
    #ifdef INFO
    printf("\033[35m=========== INFO ===========\033[0m\n");
    printf("FILE: %s", __FILE__);
    printf("APPROACH %d: %s\n", APR, apr_idea);
    printf("  + Time Complexity: O(%s)\n", time_cmplx);
    printf("  + Space Complexity: O(%s)\n", space_cmplx);
    #endif
    
    printf("\033[35m========== TESTCASE ========\033[0m\n");
    struct Case {
        // Input
        int root[20]; int tree_len;
        // Expect
        int exp;

    } cases[] = {
        // {}
        {{1,2,3,4,5,6}, 6, 110},
        {{1,null,2,3,4,null,null,5,6}, 9, 90}
    };

    // Assert test
    struct TreeNode* root;
    int numCases = (int)(sizeof(cases)/sizeof(cases[0]));
    for (int i = 0; i < numCases; ++i) {
        struct Case c = cases[i];

        // Convert array root into TreeNode
        root = tree_create_from_array(c.root, c.tree_len);
        // Solver(...)
        int res = maxProduct(root);
        // Assert Test
        if (assertTest(&res, 0, &c.exp, 0, i, sizeof(int), cmp_int, print_int) == false) {
            // Print input if needed
        }

        free_tree(root);
    }
}