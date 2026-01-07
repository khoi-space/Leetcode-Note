from typing import List, Optional, Dict, Set, Tuple
import collections
import heapq
import itertools
import math

# Local include
from inc.test import assertTest
import inc.debug as db
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

db.DEBUG = True
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
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    class Case:
        def __init__(self, l1, l2, exp_arr):
            self.l1 = l1
            self.l2 = l2
            self.exp_arr = exp_arr

    cases = [
        ([2,4,3], [5,6,4], [7,0,8]),
        ([0], [0], [0]),
        ([9,9,9,9,9,9,9], [9,9,9,9], [8,9,9,9,0,0,0,1])
    ]

    sol = Solution()

    for i, (l1, l2, exp) in enumerate(cases):
        l1 = ListNode.create_from_list(l1)
        l2 = ListNode.create_from_list(l2)
        exp = ListNode.create_from_list(exp)
        inputs = [l1, l2]
        res = sol.addTwoNumbers(l1, l2)

        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print()


if __name__ == "__main__":
    test2()