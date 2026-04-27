"""
707.设计链表（中等）
"""


class LinkedNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None


class MyLinkedList(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.setinel = LinkedNode(0)
        self.tail = LinkedNode(0)
        self.setinel.next = self.tail
        self.tail.prev = None
        self.length = 0

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        if 0 <= index < self.length:
            if index > self.length - index:
                node = self.tail
                index = self.length - index
                while index:
                    node = node.prev
                    index -= 1
            else:
                node = self.setinel
                while index + 1:
                    node = node.next
                    index -= 1
            return node.val
        else:
            return -1

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: None
        """
        node = LinkedNode(val)
        node.prev = self.setinel
        node.next = self.setinel.next
        self.setinel.next.prev = node
        self.setinel.next = node
        self.length += 1

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: None
        """
        node = LinkedNode(val)
        node.prev = self.tail.prev
        node.next = self.tail
        self.tail.prev.next = node
        self.tail.prev = node
        self.length += 1

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: None
        """
        if index <= 0:
            self.addAtHead(val)
        elif index >= self.length:
            self.addAtTail(val)
        else:
            temp = LinkedNode(val)
            if index > (self.length - index):
                node = self.tail
                index = self.length - index
                while index:
                    node = node.prev
                    index -= 1
                temp.next = node
                temp.prev = node.prev
                node.prev.next = temp
                node.prev = temp
            else:
                node = self.setinel
                while index:
                    node = node.next
                    index -= 1
                temp.next = node.next
                temp.prev = node
                node.next.prev = temp
                node.next = temp
            self.length += 1

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: None
        """
        if 0 <= index < self.length:
            if index > (self.length - index):
                node = self.tail
                index = self.length - index
                while index:
                    node = node.prev
                    index -= 1
                node.prev.next = node.next
                node.next.prev = node.prev
            else:
                node = self.setinel
                while index:
                    node = node.next
                    index -= 1
                node.next = node.next.next
                node.next.prev = node
            self.length -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)



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
    for i in range(obj.lenth + 1):
        print(obj.get(i), end=",")
