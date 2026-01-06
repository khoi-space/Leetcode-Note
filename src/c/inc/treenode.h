#ifndef TREENODE_H
#define TREENODE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define null INT_MAX

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Create new node
static inline TreeNode* create_tree_node(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create tree from arry (level-order, use null for empty node)
static TreeNode* tree_create_from_array(const int* vals, int size) {
    if (size == 0 || vals[0] == null) return NULL;
    TreeNode** nodes = (TreeNode**)malloc(size * sizeof(TreeNode*));
    for (int i = 0; i < size; ++i) nodes[i] = NULL;
    nodes[0] = create_tree_node(vals[0]);
    int pos = 1;
    for (int i = 0; i < size && pos < size; ++i) {
        if (!nodes[i]) continue;
        // left
        if (pos < size && vals[pos] != null) {
            nodes[i]->left = create_tree_node(vals[pos]);
            nodes[pos] = nodes[i]->left;
        }
        pos++;
        // right
        if (pos < size && vals[pos] != null) {
            nodes[i]->right = create_tree_node(vals[pos]);
            nodes[pos] = nodes[i]->right;
        }
        pos++;
    }
    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

// Free allocated memory
static void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

#endif // TREENODE_H