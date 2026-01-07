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
Problem 1339: Maximum Product of Splitted Binary Tree
LeetCode: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
:explain: 
"""

INFO = True
APR = 1
if APR == 1:
    apr_idea = ""
    time_cmplx = ""
    space_cmplx = ""
    
db.DEBUG = True
# Implement
class Solution(object):
    if APR == 1:
        def maxProduct(self, root: Optional[TreeNode]) -> int:
            MOD = 10**9 + 7
            self.max_product = 0

            def _countTotalSum(node: Optional[TreeNode]):
                """DFS count total sum of tree"""
                if not node:
                    return 0
                return node.val + _countTotalSum(node.left) + _countTotalSum(node.right)
            
            total_sum = _countTotalSum(root)

            def _countMaxProduct(node: Optional[TreeNode]):
                """DFS find the max product"""
                if not node:
                    return 0
                left = _countMaxProduct(node.left)
                right = _countMaxProduct(node.right)
                subtree = node.val + left + right
                self.max_product = max(self.max_product, subtree * (total_sum - subtree))
                return subtree
            
            _countMaxProduct(root)
            return self.max_product % MOD
def test1339():
    if INFO:
        print(f"\033[35m=========== INFO ===========\033[0m")
        print(f"FILE: {__file__}")
        print(f"APPROACH {APR}: {apr_idea}")
        print(f"  + Time Complexity: O({time_cmplx})")
        print(f"  + Space Complexity: O({space_cmplx})")

    print("\033[35m========== TESTCASE ========\033[0m")
    cases = [
        ([1,2,3,4,5,6], 110),
        ([1,null,2,3,4,null,null,5,6], 90),
        ([], 0),
        ([0], 0)
    ]

    sol = Solution()

    for i, (root, exp) in enumerate(cases):
        inputs = [root]

        # Convert from list to ListNode/TreeNode
        root = TreeNode.create_from_list(root)
        
        #res = sol.solver(input)
        res = sol.maxProduct(root)
        if assertTest(res, exp, i) == False:
            print(f"   Input    : ", end="")
            for input in inputs:
                print(f"{input}", end=" | ")
            print("\n")

if __name__ == "__main__":
    test1339()