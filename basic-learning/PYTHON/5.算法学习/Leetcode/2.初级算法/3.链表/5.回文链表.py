"""234. 回文链表(easy)"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        else:
            slow = head
            fast = head.next
        Nhead = None
        #一边反转一边向后
        while fast and fast.next:
            temp = slow.next
            fast = fast.next.next
            slow.next = Nhead
            Nhead = slow
            slow = temp



        if fast:#偶数
            fast = slow.next
            slow.next = Nhead
        else:#基数跳过中间的节点
            fast = slow.next
            slow = Nhead

        while fast:
            if fast.val != slow.val:
                return False
            else:
                fast = fast.next
                slow = slow.next
        return True

if __name__ == '__main__':
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(2)
    d = ListNode(1)
    a.next = b
    b.next = c
    c.next = d
    e = a
    for i in range(4):
        print(e.val, end="")
        e = e.next
    obj = Solution().isPalindrome(a)
    print(obj)