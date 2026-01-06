#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stddef.h>
#include "../inc/listnode.h"
#include "compare.h"

static inline void print_int(const void* a) {
    printf("%d ", *(const int*)a);
}

static inline void print_array(const void* a) {
    const IntArray* arr = (const IntArray*)a;
    printf("[");
    for (int i = 0; i < arr->len; ++i) {
        printf("%d", arr->data[i]);
        if (i < arr->len - 1) printf(", ");
    }
    printf("] ");
}

static inline void print_list(const void* a) {
    const ListNode* node = (const ListNode*)a;
    printf("[");
    while (node) {
        printf("%d", node->val);
        node = node->next;
        if (node) printf(" -> ");
    }
    printf("]\n");
}

#endif // PRINT_H