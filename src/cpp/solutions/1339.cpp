#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "";
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 1339: Maximum Product of Splitted Binary Tree
 * LeetCode: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
 * @explain: split the tree into two subtrees. Find the max product of the two sums
*/
class Solution {
    #if APR == 1
private:
    long long total_sum = 0;
    long long max_product = 0;
    const int MOD = 1e9 + 7;

    long long _countTotalSum(TreeNode* node) {
        // DFS
        if (node == nullptr) return 0;
        return node->val + _countTotalSum(node->left) + _countTotalSum(node->right);
    }

    long long _countMaxProduct(TreeNode* node) {
        if (node == nullptr) return 0;

        long long left_prod = _countMaxProduct(node->left);
        long long right_prod = _countMaxProduct(node->right); 
        long long subtree_prod = node->val + left_prod + right_prod;
        max_product = max(max_product, subtree_prod * (total_sum - subtree_prod));
        return subtree_prod;
    }
public:
    int maxProduct(TreeNode* root) {
        total_sum = _countTotalSum(root);
        _countMaxProduct(root); 
        return (int)(max_product % MOD);
    }
    #endif
};


void test1339() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << __FILE__ << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> root;
        // Expect
        int exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,3,4,5,6}, 110},
        {{1,null,2,3,4,null,null,5,6}, 90},
        {{0}, 0},
        {{null}, 0}
    };

    
    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        
        Case c = cases[i];
        // Convertion (for ListNode and TreeNode)
        TreeNode* root = TreeNode::createTree(c.root);
        // Inputs
        auto in1 = root;

        // Result
        auto res = sol.maxProduct(in1);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }

        TreeNode::freeTree(root);
    }
}
