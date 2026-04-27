"""
707.设计链表（Medium）
"""
# 自定义单节点
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # 保存链表长度
        self._length = 0
        # 设置哑节点
        self._head = ListNode(0)

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index < 0 or index >= self._length:
            return -1
        cur = self._head
        for _ in range(index + 1):
            cur = cur.next
        return cur.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        # 转化为向索引为0的位置插入节点
        return self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        # 转化为向索引为length的位置插入节点
        return self.addAtIndex(self._length, val)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index < 0:
            index = 0
        if index > self._length:
            return
        pre = self._head
        node = ListNode(val)
        for _ in range(index):
            pre = pre.next
        node.next = pre.next
        pre.next = node
        self._length += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0 or index >= self._length:
            return
        pre = self._head
        for _ in range(index):
            pre = pre.next
        pre.next = pre.next.next
        self._length -= 1

    @property
    def lenth(self):
        return self._length

    @property
    def head(self):
        return self._head



if __name__ == '__main__':
    obj = MyLinkedList()
    obj.addAtHead(435)
    obj.addAtTail(34234)
    obj.addAtIndex(1, 12313)
    print(obj.get(1))
    node = obj.head.next
    for i in range(obj.lenth):
        print(node.val, end=",")
        node = node.next
    print()
    obj.deleteAtIndex(1)
    for i in range(obj.lenth +1):
        print(obj.get(i), end=",")
