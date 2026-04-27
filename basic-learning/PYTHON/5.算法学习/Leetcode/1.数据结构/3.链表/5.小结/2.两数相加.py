"""
2. 两数相加(medium)
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        res = head
        carry = 0

        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            num = x + y + carry
            carry = num // 10
            res.next = ListNode(num % 10)
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            res = res.next
        if carry != 0:
            res.next = ListNode(1)
        return head.next

if __name__ == '__main__':

    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    e = ListNode(5)
    a.next = e

    b.next = c
    c.next = d
    n1 = a
    n2 = b
    obj = Solution().addTwoNumbers(n1,n2)
    for i in range(3):
        print(obj.val)
        obj = obj.next