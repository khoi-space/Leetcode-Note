#include <iostream>
using namespace std;

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

    // Helper functions
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

    static ListNode* createList(const vector<int>& list) {
        int _size = list.size();
        if (_size == 0) return nullptr;

        ListNode* head = new ListNode(list[0]);
        ListNode* cur = head;
        for (int num : list) {
            cur->next = new ListNode(num);
            cur = cur->next;
        }
        return head;
    }

    void printList() const {
        const ListNode* cur = this;        
        while(cur != nullptr) {
            if (cur->next != nullptr) {
                cout << cur->val << "->";
            } else {
                cout << cur->val << '\n';
            }
            cur = cur->next;
        }
    }

    // Sort linked list using merge sort
    static ListNode* sort(ListNode* head) {
        if (!head || !head->next) return head;

        // Find the middle point
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Sort each half
        ListNode* left = sort(head);
        ListNode* right = sort(mid);

        // Merge two sorted halves
        return merge(left, right);
    }
    // Helper function to merge two sorted lists
    static ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    // Sort linked list with custom comparator
    template <typename Compare>
    static ListNode* sort(ListNode* head, Compare comp) {
        if (!head || !head->next) return head;

        // Find the middle point
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Sort each half
        ListNode* left = sort(head, comp);
        ListNode* right = sort(mid, comp);

        // Merge two sorted halves with comparator
        return merge(left, right, comp);
    }
    // Helper function to merge two sorted lists with comparator
    template <typename Compare>
    static ListNode* merge(ListNode* l1, ListNode* l2, Compare comp) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (comp(l1->val, l2->val)) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};