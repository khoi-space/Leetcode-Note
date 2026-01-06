#ifndef LISTNODE_H
#define LISTNODE_H

#include "global.h"
using namespace std;

// Forward declaration
struct ListNode;

struct ListNode
{
    int val;
    ListNode* next;

    // Initialization
    ListNode() {
        val = 0; 
        next = nullptr;
    };
    ListNode(int x) {
        val = x; 
        next = nullptr;
    };
    ListNode(int x, ListNode* _next) {
        val = x; 
        next = _next;
    };
    ListNode(const int *arr, int size) {
        ListNode* copy = createList(arr, size);
        val = copy ? copy->val : 0;
        next = copy ? copy->next : 0;
    }
    ListNode(const vector<int> vct) {
        ListNode* copy = createList(vct);
        val = copy ? copy->val : 0;
        next = copy ? copy->next : 0;
    }
    ListNode(const ListNode* list) {
        ListNode* copy = createList(list);
        val = copy ? copy->val : 0;
        next = copy ? copy->next : nullptr;
    }

    /* Helper functions */
    // Create list from array
    static ListNode* createList(const int *arr, int size) {
        if (size == 0) return nullptr;
        
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        
        for (int i = 1; i < size; ++i) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }

    // Create list from vector
    static ListNode* createList(const vector<int>& list) {
        int _size = list.size();
        if (_size == 0) return nullptr;

        ListNode* head = new ListNode(list[0]);
        ListNode* cur = head;
        for (int i = 1; i < _size; ++i) {
            cur->next = new ListNode(list[i]);
            cur = cur->next;
        }
        return head;
    }

    // Create list from list
    static ListNode* createList(const ListNode* list) {
        if (!list) return nullptr;
        ListNode* head = new ListNode(list->val);
        ListNode* cur = head;
        const ListNode* node = list->next;
        while (node) {
            cur->next = new ListNode(node->val);
            cur = cur->next;
            node = node->next;
        }
        return head;
    }

    // Free allocated memory
    static void freeList(ListNode* head) {
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Convert list to str in format: a->b->...
    string list2Str() const {
        stringstream ss;
        const ListNode* cur = this;        
        while(cur != nullptr) {
            if (cur->next != nullptr) {
                ss << cur->val << "->";
            } else {
                ss << cur->val;
            }
            cur = cur->next;
        }
        return ss.str();
    }

    // Sort linked list using bubble sort
    static void sort(ListNode* list, bool ascending = true) {
        if (!list) return;
        bool swapped;
        do {
            swapped = false;
            ListNode* curr = list;
            while (curr && curr->next) {
                if ((ascending && curr > curr->next) || 
                    (!ascending && curr < curr->next)) {
                    std::swap(curr->val, curr->next->val);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    // Overload operator
    bool operator<(const ListNode &other) const {
        return (this->val < other.val);
    }

    bool operator==(const ListNode &other) const {
        return (this->val == other.val);
    }

    bool operator!=(const ListNode &other) const {
        return (this->val != other.val);
    }

    bool operator>(const ListNode &other) const {
        return (this->val > other.val);
    }

    bool operator<=(const ListNode &other) const {
        return (this->val <= other.val);
    }

    bool operator>=(const ListNode &other) const {
        return (this->val >= other.val);
    }
};

#endif // LISTNODE_H