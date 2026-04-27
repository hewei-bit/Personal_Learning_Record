"""
203. 移除链表元素(简单)
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        first = ListNode(0)
        first.next = head
        prev = first
        node = prev.next
        while node:
            if node.val == val:
                prev.next = node.next
                node = prev.next
            else:
                prev = prev.next
                node = node.next
        return first.next