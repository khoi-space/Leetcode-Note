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
Problem 17: Letter Combinations of a Phone Number
LeetCode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
:explain: 
"""

INFO = True
APR = 1
if APR == 1:
    apr_idea = "Iterative combination"
    time_cmplx = "4^n"
    space_cmplx = "4^n"
elif APR == 2:
    apr_idea = "Backtracking"
    time_cmplx = "4^n"
    space_cmplx = "n"

db.DEBUG = True
# Implement
class Solution(object):
    if APR == 1:
        def letterCombinations(self, digits: str) -> List[str]:
            if not digits:
                return []
            
            digit_to_letters = {
                '2': 'abc',
                '3': 'def',
                '4': 'ghi',
                '5': 'jkl',
                '6': 'mno',
                '7': 'pqrs',
                '8': 'tuv',
                '9': 'wxyz'
            }

            res = [""]

            for digit in digits:
                new_res = []

                for prefix in res:
                    for char in digit_to_letters[digit]:
                        new_res.append(prefix + char)
                    res = new_res

            return res
    elif APR == 2:
        def letterCombinations(self, digits: str) -> List[str]:
            if not digits:
                return []
            
            digit_to_letters = {
                '2': 'abc',
                '3': 'def',
                '4': 'ghi',
                '5': 'jkl',
                '6': 'mno',
                '7': 'pqrs',
                '8': 'tuv',
                '9': 'wxyz',
            }

            res = []

            def backtrack(idx, comb):
                if idx == len(digits):
                    res.append(comb[:])
                    return
                
                for letter in digit_to_letters[digits[idx]]:
                    backtrack(idx + 1, comb + letter)

            backtrack(0, "")
            return res

def test17():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    cases = [
        ("23", ["ad","ae","af","bd","be","bf","cd","ce","cf"]),
        ("2", ["a","b","c"])
    ]

    sol = Solution()

    for i, (input, exp) in enumerate(cases):
        inputs = [input]
        #res = sol.solver(input)
        res = sol.letterCombinations(input)
        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print("\n")

if __name__ == "__main__":
    test17()
