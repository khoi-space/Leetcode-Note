#ifndef COMPARE_H
#define COMPARE_H

#include <stdbool.h>
#include <string.h>
#include "../inc/listnode.h"

// ===== Comparison functions for basic types =====
static inline bool isEqualInt(int a, int b) {
	return a == b;
}

// ===== Comparison functions for arrays =====
static inline bool isEqualArray(const int* arr1, int len1, const int* arr2, int len2) {
	if (len1 != len2) return false;
	for (int i = 0; i < len1; ++i) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

// ===== Comparison functions for linked lists =====
static inline bool isEqualList(ListNode* list1, ListNode* list2) {
	while (list1 && list2) {
		if (list1->val != list2->val) return false;
		list1 = list1->next;
		list2 = list2->next;
	}
	return !list1 && !list2;
}

// ===== Comparison functions for tree =====
static inline bool isEqualTree(TreeNode* tree1, TreeNode* tree2) {
	if (tree1 == NULL && tree2 == NULL) return true;
	if (tree1 == NULL || tree2 == NULL) return false;
	if (tree1->val != tree2->val) return false;
	return isEqualTree(tree1->left, tree2->left) && isEqualTree(tree1->right, tree2->right);
}

// ===== Generic comparison function pointers =====
// cmp_int: Compare two int values (for generic assertion)
static inline bool cmp_int(const void* a, const void* b) {
	return *(const int*)a == *(const int*)b;
}

// cmp_list: Compare two listnode (for generic assertion)
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

// cmp_tree: Compare two treenodes (for generic assertion)
static inline bool cmp_tree(const void* a, const void* b) {
	const TreeNode* root_a = (const TreeNode*)a;
	const TreeNode* root_b = (const TreeNode*)b;
	return isEqualTree((TreeNode*)root_a, (TreeNode*)root_b);
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