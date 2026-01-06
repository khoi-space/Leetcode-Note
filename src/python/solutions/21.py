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
Problem 21: Merge Two Sorted Lists
LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/
:explain: 
"""

INFO = True
APR = 1
if APR == 1:
    apr_idea = "Dynamic Programming"
    time_cmplx = "m+n"
    space_cmplx = "1"
elif APR == 2:
    apr_idea = "Recursion"
    time_cmplx = "m+n"
    space_cmplx = "m+n"

db.DEBUG = True
# Implement
class Solution(object):
    if APR == 1:
        def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            cur = dummy

            while list1 and list2:
                if list1.val > list2.val:
                    cur.next = list2
                    list2 = list2.next
                else:
                    cur.next = list1
                    list1 = list1.next
                
                cur = cur.next
            
            # Merge the rest of longer list
            if list1:
                cur.next = list1
            else:
                cur.next = list2
            
            return dummy.next
    elif APR == 2:
        def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
            if not list1 or not list2:
                return list1 if list1 else list2

            if list1.val > list2.val:
                list1, list2 = list2, list1

            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1

def test21():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    class Case:
        def __init__(self, list1, list2, exp):
            #Inputs
            self.list1 = list1
            self.list2 = list2
            #Expected
            self.exp = exp

    cases = [
        ([1,2,4], [1,3,4], [1,1,2,3,4,4]),
        ([], [], []),
        ([], [0], [0])
    ]

    sol = Solution()

    for i, (list1, list2, exp) in enumerate(cases):
        list1 = ListNode.create_from_list(list1)
        list2 = ListNode.create_from_list(list2)
        exp = ListNode.create_from_list(exp)
        inputs = [list1, list2]
        res = sol.mergeTwoLists(list1, list2)

        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print()

if __name__ == "__main__":
    test21()
