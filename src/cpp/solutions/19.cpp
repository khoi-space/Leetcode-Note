#include "../inc/global.h"
using namespace std;

// Turn on/off debug mode
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "";
string time_cmplx = "";
string space_cmplx = "";
#endif
#endif

/**
 * Problem 19: Remove Nth Node From End of List
 * LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
class Solution {
public:
    #if APR == 1
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* ptr = dummy;

        // Make a space_length of n from head to dummy
        for (int i = 0; i < n; ++i) {
            head = head->next;
        }

        // Move head to tail
        while (head != nullptr) {
            head = head->next;
            ptr = ptr->next;
        }

        // Remove the target node
        ptr->next = ptr->next->next;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
    #endif
};


void test19() {
    #ifdef INFO
    cout << "\033[35m=========== INFO ===========\033[0m" << endl;
    cout << "FILE: " << __FILE__ << endl;
    cout << "APPROACH " << APR << ": " << apr_idea << endl;
    cout << "  + Time Complexity: O(" << time_cmplx << ")" << endl;
    cout << "  + Space Complexity: O(" << space_cmplx << ")" << endl;
    #endif

    cout << "\033[35m========== TESTCASE ========\033[0m\n";
    struct Case {
        // Inputs
        vector<int> head;
        int n;
        // Expect
        vector<int> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,3,4,5}, 2, {1,2,3,5}},
        {{1}, 1, {}},
        {{1,2}, 1, {1}}
    };


    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        ListNode* head = ListNode::createList(c.head);
        ListNode* exp = ListNode::createList(c.exp);
        // Inputs
        auto in1 = head;
        auto in2 = c.n;

        // Result
        auto res = sol.removeNthFromEnd(in1, in2);

        if(assertTest(res, exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
