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
Problem 58: Length of Last Word
LeetCode: https://leetcode.com/problems/length-of-last-word/
:explain: 
"""

INFO = True
APR = 2
if APR == 1:
    apr_idea = "Counting from tail"
    time_cmplx = "n"
    space_cmplx = "1"
elif APR == 2:
    apr_idea = "Counting from head"
    time_cmplx = "n"
    space_cmplx = "1"

db.DEBUG = True
# Implement
class Solution(object):
    if APR == 1:
        def lengthOfLastWord(self, s: str) -> int:
            end = len(s) - 1

            while s[end] == " ":
                end -= 1

            checker = end
            while (checker >= 0 and s[checker] != " "):
                checker -= 1

            return end - checker
    elif APR == 2:
        def lengthOfLastWord(self, s: str) -> int:
            length = 0
            counting = False

            for c in s:
                if c != " ":
                    if not counting:
                        # Begin to counting
                        counting = True 
                        length = 1
                    else:
                        length += 1
                else:
                    counting = False

            return length
        
def test58():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    cases = [
        ("Hello World", 5),
        ("   fly me   to   the moon  ", 4),
        ("luffy is still joyboy", 6)
    ]

    sol = Solution()

    for i, (s, exp) in enumerate(cases):
        inputs = [s]
        res = sol.lengthOfLastWord(s)
        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print("\n")

if __name__ == "__main__":
    test58()
