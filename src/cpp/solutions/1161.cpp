#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
// #undef DEBUG

// Display info of the approach
#define INFO
#define APR 2
#ifdef INFO
#if APR == 1
string apr_idea = "BFS";
string time_cmplx = "n";
string space_cmplx = "n";
#elif APR == 2
string apr_idea = "DFS";
string time_cmplx = "n";
string space_cmplx = "n";
#endif
#endif

/**
 * Problem 1161: Maximum Level Sum of a Binary Tree
 * LeetCode: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
*/
class Solution {
public:
    #if APR == 1
    int maxLevelSum(TreeNode* root) {
        int max_sum = INT_MIN;
        int lv_max_sum = 0, lv = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            lv++;
            int sum_at_this_lv = 0;
            // Iterate over all nodes in this level
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum_at_this_lv += node->val;

                // Push child node to queue
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (max_sum < sum_at_this_lv) {
                max_sum = sum_at_this_lv;
                lv_max_sum = lv;
            }
        }
        return lv_max_sum;
    }
    #elif APR == 2
private:
    void _dfs(TreeNode* node, int lv, vector<int>& sum_at_lv) {
        if(node == nullptr) {
            return;
        }

        if ((int)sum_at_lv.size() == lv) { // Travel to a new level
            sum_at_lv.push_back(node->val);
        } else {
            sum_at_lv[lv] += node->val;
        }

        _dfs(node->left, lv + 1, sum_at_lv);
        _dfs(node->right, lv + 1, sum_at_lv);
    }
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sum_at_lv;
        _dfs(root, 0, sum_at_lv);

        // Travel through sum_at_lv to find max_sum and return its level
        int max_sum = INT_MIN;
        int lv_max_sum = 0;

        for (int i = 0; i < (int)sum_at_lv.size(); ++i) {
            if (max_sum < sum_at_lv[i]) {
                max_sum = sum_at_lv[i];
                lv_max_sum = i + 1; // because level is 1-indexed
            }
        }

        return lv_max_sum;
    }
    #endif
};


void test1161() {
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
        {{1,7,0,7,-8,null,null}, 2},
        {{989,null,10250,98693,-89388,null,null,null,-32127}, 2}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        TreeNode* root = TreeNode::createTree(c.root);
        // Inputs
        auto in1 = root;

        // Result
        auto res = sol.maxLevelSum(root);

        if(assertTest(res, c.exp, i) == false) {
            cout << "   Input    : " << in1 << endl;
        }
    }
}
