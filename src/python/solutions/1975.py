from typing import List, Optional, Dict, Set, Tuple
import collections
import heapq
import itertools
import math

# Local include
from inc.test import *
import inc.debug as db
from inc.listnode import *

"""
Problem 1975: Maximum Matrix Sum
LeetCode: https://leetcode.com/problems/maximum-matrix-sum/
:explain: 
"""

INFO = True
APR = 1
if APR == 1:
    apr_idea = "If negative count is odd, substract the sum by min_abs_val twice"
    time_cmplx = "n*m"
    space_cmplx = "1"

db.DEBUG = True

# Implement
class Solution(object):
    if APR == 1:
        def maxMatrixSum(self, matrix: List[List[int]]) -> int:
            max_sum = 0
            negative_count = 0
            min_abs_val = float("inf") #MAX
            
            for row in matrix:
                for val in row:
                    max_sum += abs(val)
                    if (val < 0): negative_count += 1

                    min_abs_val = min(min_abs_val, abs(val))
            
            if negative_count % 2 == 1:
                max_sum -= 2 * min_abs_val
            
            return max_sum

def test1975():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"File: {__file__}")
        print(f"Approach {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    class Case:
        def __init__(self, matrix, exp):
            #Inputs
            self.matrix = matrix
            #Expected
            self.exp = exp

    cases = [
        Case([[1,-1],[-1,1]], 4),
        Case([[1,2,3],[-1,-2,-3],[1,2,3]], 16)
    ]

    sol = Solution()

    for i, c in enumerate(cases):
        inputs = [c.matrix]
        res = sol.maxMatrixSum(c.matrix)
        if assertTest(res, c.exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print("\n")

if __name__ == "__main__":
    test1975()
