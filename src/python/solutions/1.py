from typing import List, Optional, Dict, Set, Tuple
import collections
import heapq
import itertools
import math

"""
Problem 1: Two Sum
LeetCode: https://leetcode.com/problems/two-sum/
"""

#Implement function
class Solution(object):
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[j] == target - nums[i]:
                    return [i, j]
        # Return an empty list if no solution is found
        return []

def test1():
    class Case:
        def __init__(self, nums, target, exp):
            #Inputs
            self.nums = nums
            self.target = target
            #Expected
            self.exp = exp

    cases = [
        Case([2,7,11,15], 9, [0,1]),
        Case([3,2,4], 6, [1,2]),
        Case([3,3], 6, [0,1])
    ]

    sol = Solution()

    for i, c in enumerate(cases):
        res = sol.twoSum(c.nums, c.target)
        if res == c.exp:
            print(f"Test case {i+1} passed.")
        else:
            print(f"Test case {i+1} failed: got {res}, expected {c.exp}")
    print("Done.")


if __name__ == "__main__":
    test1()
