#ifndef COMPARE_H
#define COMPARE_H

#include <stdbool.h>
#include <string.h>
#include "../inc/listnode.h"

// ===== Comparison functions for basic types =====

// Compare two integers
static inline bool isEqualInt(int a, int b) {
	return a == b;
}

// ===== Comparison functions for arrays =====

// Compare two int arrays
static inline bool isEqualArray(const int* arr1, int len1, const int* arr2, int len2) {
	if (len1 != len2) return false;
	for (int i = 0; i < len1; ++i) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

// ===== Comparison functions for linked lists =====

// Compare two linked lists
static inline bool isEqualList(ListNode* list1, ListNode* list2) {
	while (list1 && list2) {
		if (list1->val != list2->val) return false;
		list1 = list1->next;
		list2 = list2->next;
	}
	return !list1 && !list2;
}

// ===== Generic comparison function pointers =====
// cmp_int: Compare two int values (for generic assertion)
static inline bool cmp_int(const void* a, const void* b) {
	return *(const int*)a == *(const int*)b;
}

// cmp_list: Compare two linked lists (for generic assertion)
static inline bool cmp_list(const void* a, const void* b) {
	const ListNode* node_a = (const ListNode*)a;
	const ListNode* node_b = (const ListNode*)b;
	while (node_a && node_b) {
		if (node_a->val != node_b->val) return false;
		node_a = node_a->next;
		node_b = node_b->next;
	}
	return !node_a && !node_b;
}

// cmp_array: Compare two int arrays (for generic assertion)
typedef struct {
	const int* data;
	int len;
} IntArray;

static inline bool cmp_array(const void* a, const void* b) {
	const IntArray* arr_a = (const IntArray*)a;
	const IntArray* arr_b = (const IntArray*)b;
	if (arr_a->len != arr_b->len) return false;
	for (int i = 0; i < arr_a->len; ++i) {
		if (arr_a->data[i] != arr_b->data[i]) return false;
	}
	return true;
}

#endif // COMPARE_H