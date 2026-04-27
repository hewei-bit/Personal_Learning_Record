"""
删除链表中的节点
请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:
示例 1:

输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
"""

class ListNode:
    def __init__(self,x:int):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, node:ListNode):
        node.val = node.next.val
        node.next = node.next.next

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
    obj = Solution().deleteNode(a)
    for i in range(4):
        print(obj.val, end="")
        obj = obj.next