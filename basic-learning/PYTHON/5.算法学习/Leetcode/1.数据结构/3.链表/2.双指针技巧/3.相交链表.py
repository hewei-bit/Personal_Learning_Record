"""
160. 相交链表(easy)
"""

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        fast = headA
        slow = headB
        while fast != slow:
            fast = fast.next if fast else headB
            slow = slow.next if slow else headA
        return fast
