#ifndef TREENODE_H
#define TREENODE_H

#include "global.h"
using namespace std;

#define null INT_MAX

// Forward declaration
struct TreeNode;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Initializations
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}

    /* Helper functions */
    static TreeNode* createTree(const vector<int>& vals) {
        if (vals.empty() || vals[0] == null) return nullptr;
        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < (int)vals.size()) {
            TreeNode* node = q.front(); q.pop();
            // left
            if (i < (int)vals.size() && vals[i] != null) {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            i++;
            // right
            if (i < (int)vals.size() && vals[i] != null) {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
    
    // Convert tree into string
    static string tree2Str(TreeNode* root, bool fancy = false) {
        if (!fancy) {
            // Preorder
            if (!root) return "null";
            return to_string(root->val) + " (" + tree2Str(root->left) + " " + tree2Str(root->right) + ")";
        } else {
            // Maybe later
            return "";
        }
    }

    // Free allocated memory
    static void freeTree(TreeNode* root) {
        if (!root) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
};

#endif // TREENODE_H