#ifndef COMPARE_H
#define COMPARE_H

#include <vector>
#include <cmath>
#include "../inc/listnode.h"
#include "../inc/treenode.h"
#include <iostream>

// (No use anymore)

// Compare basic types (int, double, char, string,...)
template<typename T>
inline bool isEqual(const T& lhs, const T& rhs, bool unorder_cmp = false) {
    return lhs == rhs;
}

// Compare vectors
inline bool isEqual(vector<int> lhs, vector<int> rhs, bool unorder_cmp = false) {
    if (unorder_cmp) {
        std::sort(lhs.begin(), lhs.end());
        std::sort(lhs.begin(), rhs.end());
    }

    return lhs == rhs;
}

// Compare ListNodes
inline bool isEqual(ListNode *lhs, ListNode* rhs, bool unorder_cmp = false) {
    if (unorder_cmp) {
        // Push to vectors and sort them
        std::vector<int> v1, v2;
        while (lhs) {
            v1.push_back(lhs->val);
            lhs = lhs->next;
        }
        while (rhs) {
            v2.push_back(rhs->val);
            rhs = rhs->next;
        }

        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        return v1 == v2;
    } else {
        // Check if 2 listnodes are exactly the same 
        while (lhs && rhs) {
            if (lhs->val != rhs->val) return false;
            lhs = lhs->next;
            rhs = rhs->next;
        }
        return !lhs && !rhs;
    }
}

// Compare TreeNodes
inline void collect(TreeNode* node, std::vector<int>& v) {
    if (!node) return;
    v.push_back(node->val);
    collect(node->left, v);
    collect(node->right, v);
}
inline bool isEqual(TreeNode* lhs, TreeNode* rhs, bool unorder_cmp = false) {
    if (unorder_cmp) {
        // Push to vectors and sort them
        std::vector<int> v1, v2;
        collect(lhs, v1);
        collect(rhs, v2);
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        return v1 == v2;
    } else {
        // Check if 2 treenodes are exactly the same
        if (!lhs && !rhs) return true;
        if (!lhs || !rhs) return false;
        if (lhs->val != rhs->val) return false;
        return isEqual(lhs->left, rhs->left) && isEqual(lhs->right, rhs->right);
    }

}

#endif // COMPARE_H