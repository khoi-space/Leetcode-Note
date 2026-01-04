#ifndef COMPARE_H
#define COMPARE_H

#include <stdbool.h>
#include <string.h>
#include "../inc/listnode.h"

static inline bool isEqualInt(int lhs, int rhs) {
    return lhs == rhs;
}

static inline bool isEqualStr(const char* lhs, const char* rhs) {
    if (lhs == NULL && rhs == NULL) return true;
    if (lhs == NULL || rhs == NULL) return false;
    return strcmp(lhs, rhs) == 0;
}

static inline bool isEqualList(const ListNode* lhs, const ListNode* rhs) {
    const ListNode* a = lhs;
    const ListNode* b = rhs;
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return a == NULL && b == NULL;
}

static inline bool isEqualArray(const int* a, int na, const int* b, int nb) {
    if (na != nb) return false;
    for (int i = 0; i < na; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Generic dispatch for common types (C11)
#define isEqual(a, b) _Generic((a), \
    int: isEqualInt, \
    const char*: isEqualStr, \
    char*: isEqualStr, \
    ListNode*: isEqualList, \
    const ListNode*: isEqualList, \
    int*: isEqualArray, \
    const int*: isEqualArray \
)(a, b)

#endif // COMPARE_H