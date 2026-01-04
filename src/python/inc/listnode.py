class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
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
    
    def __repr__(self):
        return f"ListNode({self.val})"
