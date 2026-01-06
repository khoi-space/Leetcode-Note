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
Problem 1: Two Sum
LeetCode: https://leetcode.com/problems/two-sum/
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
#Implement function
class Solution(object):
    if APR == 1:
        def twoSum(self, nums: List[int], target: int) -> List[int]:
            db.see(nums)
            for i in range(len(nums)):
                for j in range(i + 1, len(nums)):
                    if nums[j] == target - nums[i]:
                        return [i, j]
            # Return an empty list if no solution is found
            return []
    elif APR == 2:
        def twoSum(self, nums: List[int], target: int) -> List[int]:
            hashmap = {}
            for i in range(len(nums)):
                hashmap[nums[i]] = i
            for i in range(len(nums)):
                complement = target - nums[i]
                if complement in hashmap and hashmap[complement] != i:
                    return [i, hashmap[complement]]
            # If no valid pair is found, return an empty list
            return []
    elif APR == 3:
        def twoSum(self, nums: List[int], target: int) -> List[int]:
            hashmap = {}
            for i in range(len(nums)):
                complement = target - nums[i]
                if complement in hashmap:
                    return [i, hashmap[complement]]
                hashmap[nums[i]] = i
            # Return an empty list if no solution is found
            return []

def test1():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    class Case:
        def __init__(self, nums, target, exp):
            #Inputs
            self.nums = nums
            self.target = target
            #Expected
            self.exp = exp

    cases = [
        ([2,7,11,15], 9, [0,1]),
        ([3,2,4], 6, [1,2]),
        ([3,3], 6, [0,1])
    ]

    sol = Solution()

    for i, (nums, target, exp) in enumerate(cases):
        inputs = [nums, target]
        res = sol.twoSum(nums, target)
        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")


if __name__ == "__main__":
    test1()
