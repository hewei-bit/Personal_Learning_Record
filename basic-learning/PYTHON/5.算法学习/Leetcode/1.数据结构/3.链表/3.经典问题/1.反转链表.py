"""
206. 反转链表(简单)
"""



class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head : return None
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre


if __name__ == '__main__':
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    a.next = b
    b.next = c
    c.next = d
    e = a
    for i in range(4):
        print(e.val, end="")
        e = e.next
    obj = Solution().reverseList(a)
    for i in range(4):
        print(obj.val, end="")
        obj = obj.next
