from typing import List, Optional, Dict, Set, Tuple
import collections
import heapq
import itertools
import math

# Local include
from inc.test import *
from inc.debug import *
from inc.listnode import *

"""
Problem 2: Add Two Numbers
LeetCode: https://leetcode.com/problems/add-two-numbers/
:explain: 
"""

INFO = True
APR = 1
if APR == 1:
    apr_idea = "Brute-force"
    time_cmplx = "n^2"
    space_cmplx = "1"
elif APR == 2:
    apr_idea = "Two-pass Hash Table"
    time_cmplx = "n"
    space_cmplx = "n"
elif APR == 3:
    apr_idea = "One-pass Hash Table"
    time_cmplx = "n"
    space_cmplx = "n"

# Implement
class Solution(object):
    if APR == 1:
        def addTwoNumbers(
            self, l1: Optional[ListNode], l2: Optional[ListNode]
        ) -> Optional[ListNode]:
            dummyHead = ListNode(0)
            curr = dummyHead
            carry = 0
            while l1 != None or l2 != None or carry != 0:
                l1_val = l1.val if (l1 != None) else 0
                l2_val = l2.val if (l2 != None) else 0
                column_sum = l1_val + l2_val + carry
                carry = column_sum // 10
                new_node = ListNode(column_sum % 10)
                curr.next = new_node
                curr = curr.next
                l1 = l1.next if (l1 != None) else None
                l2 = l2.next if (l2 != None) else None
            return dummyHead.next

def test2():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"Approach {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    class Case:
        def __init__(self, l1_arr, l2_arr, exp_arr):
            self.l1_arr = l1_arr
            self.l2_arr = l2_arr
            self.exp_arr = exp_arr

    cases = [
        Case([2,4,3], [5,6,4], [7,0,8]),
        Case([0], [0], [0]),
        Case([9,9,9,9,9,9,9], [9,9,9,9], [8,9,9,9,0,0,0,1])
    ]

    sol = Solution()

    for i, c in enumerate(cases):
        l1 = ListNode.create_from_list(c.l1_arr)
        l2 = ListNode.create_from_list(c.l2_arr)
        
        res = sol.addTwoNumbers(l1, l2)
        res_arr = ListNode.to_list(res)
        
        if assertTest(res_arr, c.exp_arr, i) == False:
            print(f"   Input    : {c.l1_arr} + {c.l2_arr}")


if __name__ == "__main__":
    test2()
