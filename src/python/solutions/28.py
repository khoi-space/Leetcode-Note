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
Problem 28: Find the Index of the First Occurrence in a String
LeetCode: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
:explain: 
"""

INFO = True
APR = 1
if APR == 1:
    apr_idea = "Slicing"
    time_cmplx = "m*n"
    space_cmplx = "m"

db.DEBUG = True
class Solution(object):
    if APR == 1:
        def strStr(self, haystack: str, needle: str) -> int:
            if len(haystack) < len(needle): return -1

            for i in range(len(haystack)):
                if haystack[i:i+len(needle)] == needle:
                    return i
                
            return -1

def test28():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    cases = [
        ("sadbutsad", "sad", 0),
        ("leetcode", "leeto", -1)
    ]

    sol = Solution()

    for i, (haystack, needle, exp) in enumerate(cases):
        inputs = [haystack, needle]
        res = sol.strStr(haystack, needle)
        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print("\n")

if __name__ == "__main__":
    test28()
