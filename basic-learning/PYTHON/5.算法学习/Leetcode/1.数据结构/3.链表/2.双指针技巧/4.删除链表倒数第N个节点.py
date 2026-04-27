"""
19. 删除链表的倒数第N个节点(Medium)
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast = head
        while n > 0:
            fast = fast.next
            n -= 1
        if fast is None:
            return head.next

        slow = head
        while fast.next != None:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head



