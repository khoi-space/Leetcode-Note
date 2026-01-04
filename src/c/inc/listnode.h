// C-compatible singly linked list utilities
#ifndef LISTNODE_H
#define LISTNODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

static inline ListNode* list_create_from_array(const int* arr, int size) {
    if (size <= 0 || arr == NULL) return NULL;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    head->next = NULL;
    ListNode* cur = head;
    for (int i = 1; i < size; ++i) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = arr[i];
        node->next = NULL;
        cur->next = node;
        cur = node;
    }
    return head;
}

static inline void list_print(const ListNode* head) {
    const ListNode* cur = head;
    while (cur != NULL) {
        if (cur->next != NULL) {
            printf("%d->", cur->val);
        } else {
            printf("%d\n", cur->val);
        }
        cur = cur->next;
    }
}

static inline void list_free(ListNode* head) {
    while (head != NULL) {
        ListNode* next = head->next;
        free(head);
        head = next;
    }
}

#endif // LISTNODE_H