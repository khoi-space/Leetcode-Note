from typing import List, Optional, Dict, Set, Tuple
import collections
import heapq
import itertools
import math

from inc.test import *

"""
Problem 17: Letter Combinations of a Phone Number
LeetCode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
"""

#Implement function
class Solution(object):
    def letterCombination(self, digits: str) -> List[str]:
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

        for d in digits:
            new_res = []
            for prefix in res:
                for char in digit_to_letters[d]:
                    new_res.append(prefix + char)
                res = new_res

        return res

def test17():
    class Case:
        def __init__(self, digits, exp):
            #Inputs
            self.digits = digits
            #Expected
            self.exp = exp

    cases = [
        Case("23", ["ad","ae","af","bd","be","bf","cd","ce","cf"]),
        Case("2", ["a","b","c"])
    ]

    sol = Solution()

    for i, c in enumerate(cases):
        res = sol.letterCombination(c.digits)
        assertTest(res, c.exp, i)


if __name__ == "__main__":
    test17()
