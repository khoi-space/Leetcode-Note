#include "../inc/global.h"
using namespace std;

// Turn off debug mode (uncomment to turn on)
#undef DEBUG

// Display info of the approach
#define INFO
#define APR 1
#ifdef INFO
#if APR == 1
string apr_idea = "Dynamic Programming";
string time_cmplx = "m+n";
string space_cmplx = "1";
#elif APR == 2
string apr_idea = "Recursion";
string time_cmplx = "m+n";
string space_cmplx = "m+n";
#endif
#endif

/**
 * Problem 21: Merge Two Sorted Lists
 * LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/
 * @input:
 * @output:
*/
class Solution {
public:
    #if APR == 1
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
    #elif APR == 2
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            return list1 ? list1 ; list2;
        }

        if (list1->val > list2->val) {
            swap(list1, list2);
        }

        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    #endif
};


void test21() {
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
        vector<int> l1_arr;
        vector<int> l2_arr;
        // Expect
        vector<int> exp;
    };

    vector<Case> cases = {
        // {{}}
        {{1,2,4}, {1,3,4}, {1,1,2,3,4,4}},
        {{}, {}, {}},
        {{}, {0}, {0}},
        {{2}, {1}, {1,2}},
        {{1,3,5}, {2,4,6}, {1,2,3,4,5,6}},
        {{1,2,3}, {}, {1,2,3}},
        {{}, {1,2,3}, {1,2,3}},
        {{5,6,7}, {1,2,3}, {1,2,3,5,6,7}},
        {{1,1,1}, {1,1,1}, {1,1,1,1,1,1}}
    };

    for (int i = 0; i < (int)cases.size(); ++i) {
        Solution sol = Solution();
        Case c = cases[i];
        ListNode* l1 = ListNode::createList(c.l1_arr);
        ListNode* l2 = ListNode::createList(c.l2_arr);
        ListNode* exp = ListNode::createList(c.exp);
        // Inputs
        auto in1 = l1;
        auto in2 = l2;

        // Result
        auto res = sol.mergeTwoLists(l1, l2);

        if(assertTest(res, exp, i) == false) {
            cout << "   Input    : " << in1 << " " << in2 << endl;
        }
    }
}
