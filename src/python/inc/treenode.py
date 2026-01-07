from typing import Optional

null = None

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        """Convert treenode to string in preorder"""
        def preorder(node):
            if node is None:
                return "null"
            return f"{node.val} (" + preorder(node.left) + ", " + preorder(node.right) + ")"
        return preorder(self)
    
    def __eq__(self, other):
        """Overload operator =="""
        if not isinstance(other, TreeNode):
            return False
        return (
            self.val == other.val and
            (self.left == other.left) and
            (self.right == other.right)
        )

    @staticmethod
    def create_from_list(arr):
        """Create treenode from array/list (level-order, use None for null node)"""
        if not arr or arr[0] is None:
            return None
        from collections import deque
        root = TreeNode(arr[0])
        q = deque([root])
        i = 1
        while q and i < len(arr):
            node = q.popleft()
            # left
            if i < len(arr) and arr[i] is not None:
                node.left = TreeNode(arr[i])
                q.append(node.left)
            i += 1
            # right
            if i < len(arr) and arr[i] is not None:
                node.right = TreeNode(arr[i])
                q.append(node.right)
            i += 1
        return root

    @staticmethod
    def to_list(root, list):
        """Convert treenode to array/list"""
        if (root == None):
            return
    
        list.append(root.val)
        TreeNode.to_list(root.left, list)
        TreeNode.to_list(root.right, list)
    
# Recognize treenode
def is_treenode(obj):
	return hasattr(obj, 'val') and hasattr(obj, 'left') and hasattr(obj, 'right')

# Compare treenode
def treenode_equal(a: Optional[TreeNode], b: Optional[TreeNode], unorder=False):
    if (unorder == False):
        if a == None and b == None:
            return True
        if a == None or b == None:
            return False
        if a.val != b.val:
            return False
        
        return treenode_equal(a.left, b.left) and treenode_equal(a.right, b.right)

    else:
        a_list, b_list = [], []
        TreeNode.to_list(a, a_list)
        TreeNode.to_list(b, b_list)
        return sorted(a_list) == sorted(b_list)