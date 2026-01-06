from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __eq__(self, other):
        """Overload operator =="""
        if not isinstance(other, ListNode):
            return False
        if self.val != other.val:
            return False
        if self.next is None and other.next is None:
            return True
        if self.next is None or other.next is None:
            return False
        return self.next == other.next

    @staticmethod
    def create_from_list(arr):
        """Create linked list from array/list"""
        if not arr:
            return None
        head = ListNode(arr[0])
        current = head
        for val in arr[1:]:
            current.next = ListNode(val)
            current = current.next
        return head
    
    @staticmethod
    def to_list(head):
        """Convert linked list to array/list"""
        result = []
        current = head
        while current:
            result.append(current.val)
            current = current.next
        return result
    
    def __str__(self):
        """String representation: 1 -> 2 -> 3"""
        result = []
        current = self
        while current:
            result.append(str(current.val))
            current = current.next
        return " -> ".join(result)

# Recognize listnode
def is_listnode(obj):
	return hasattr(obj, 'val') and hasattr(obj, 'next')

# Compare listnode
def listnode_equal(a: Optional[ListNode], b: Optional[ListNode], unorder=False):
	if (unorder == False):
		while a and b:
			if a.val != b.val:
				return False
			a = a.next
			b = b.next
		return a is None and b is None
	else:
		vals_a, vals_b = [], []
		while a:
			vals_a.append(a.val)
			a = a.next
		while b:
			vals_b.append(b.val)
			b = b.next
		return sorted(vals_a) == sorted(vals_b)