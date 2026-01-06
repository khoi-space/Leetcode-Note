#ifndef COMPARE_H
#define COMPARE_H

#include <vector>
#include <cmath>
#include "../inc/listnode.h"

// (No use anymore)

// Compare basic types (int, double, char, string,...)
template<typename T>
inline bool isEqual(const T& lhs, const T& rhs, bool unorder_cmp = false) {
    return lhs == rhs;
}

// Compare linked lists
inline bool isEqual(ListNode *lhs, ListNode* rhs, bool unorder_cmp = false) {
    if (unorder_cmp) {
        // Sort two ListNode first
        ListNode::sort(lhs);
        ListNode::sort(rhs);
    }
    while (lhs && rhs) {
        if (lhs->val != rhs->val) return false;
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return !lhs && !rhs;
}

// Compare vectors
inline bool isEqual(vector<int> lhs, vector<int> rhs, bool unorder_cmp = false) {
    if (unorder_cmp) {
        std::sort(lhs.begin(), lhs.end());
        std::sort(lhs.begin(), rhs.end());
    }

    return lhs == rhs;
}

#endif // COMPARE_H