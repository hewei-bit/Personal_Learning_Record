"""
142. 环形链表 II(Medium)
"""


class ListNode:
    def __init__(self, x):
        self.next = None
        self.val = x


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        fast, slow = head, head
        if fast and fast.next is None:
            return
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        fast = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return fast


class Solution2(object):
    def detectCycle(self, head):
        fast, slow = head, head
        while True:
            if not (fast and fast.next): return
            fast, slow = fast.next.next, slow.next
            if fast == slow: break
        fast = head
        while fast != slow:
            fast, slow = fast.next, slow.next
        return fast


if __name__ == '__main__':
    n1 = ListNode(3)
    n2 = ListNode(2)
    n3 = ListNode(0)
    n4 = ListNode(-4)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n2
    obj = Solution().detectCycle(n1)
    print(obj.val)
