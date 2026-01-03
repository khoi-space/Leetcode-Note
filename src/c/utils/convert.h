#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>
#include <stddef.h>
#include "../inc/listnode.h"

static inline void printIntArr(const int* arr, size_t n) {
    printf("[");
    for (size_t i = 0; i < n; ++i) {
        if (i) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]");
}

static inline void printLL(const ListNode* head) {
    list_print(head);
}

#endif // CONVERT_H