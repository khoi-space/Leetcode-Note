#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Elementary Math";
string time_cmplx = "max(m,n)";
string space_cmplx = "1";
#endif
#endif

/**
 * Problem 2: Add Two Numbers
 * LeetCode: https://leetcode.com/problems/add-two-numbers/
 * @input:
 * @output:
*/
class Solution {
public:
    #if APR == 1
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;  // Freeing the memory allocated for dummyHead
        return result;
    }
    #endif
};

void test2() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << __FILE__ << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        vector<int> l1;
        vector<int> l2;
        vector<int> exp;
    };

    vector<Case> cases = {
        {{2,4,3}, {5,6,4}, {7,0,8}},
        {{0}, {0}, {0}},
        {{9,9,9,9,9,9,9}, {9,9,9,9}, {8,9,9,9,0,0,0,1}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        ListNode* l1 = ListNode::createList(c.l1);
        ListNode* l2 = ListNode::createList(c.l2);
        ListNode* exp = ListNode::createList(c.exp);

        auto res = sol.addTwoNumbers(l1, l2);
        if(assertTest(res, exp, i) == false) {
            cout << "   Input    : " << l1 << ", " << l2 << endl;
        }
        
        ListNode::freeList(l1);
        ListNode::freeList(l2);
        ListNode::freeList(exp);
    }
}
