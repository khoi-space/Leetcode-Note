// #define DEBUG
#include "inc/test.h"
#include "inc/global.h"
#include <iostream>
using namespace std;

//#define DEBUG
#define MAX_APR 1
#define APR     1

/**
 * Problem 19: Remove Nth Node From End of List
 * @input: the head of a linked list
 * @output: remove the Nth node FROM THE END of the list and return the head
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);

    for (int i = 0; i < n; ++i) {
        head = head->next;
    }

    while (head != nullptr) {
        head = head->next;
        dummy = dummy->next;
    }

    dummy->next = dummy->next->next;

    ListNode* result
}

void test19() {
    cout << "Approach " << APR << " / " << MAX_APR << endl;

    struct Case {
        vector<int> head_list;
        int n;
        vector<int> exp_list;
    };

    vector<Case> cases = {
        {{1,2,3,4,5}, 2, {1,2,3,5}},
        {{1}, 1, {}},
        {{1,2}, 1, {1}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Case c = cases[i];
        ListNode* head = ListNode::createList(c.list);
        ListNode* exp = ListNode::createList(c.exp_list);
        ListNode* res = removeNthFromEnd(head, c.n);
        assertTest(res, exp, i);
    }
}
