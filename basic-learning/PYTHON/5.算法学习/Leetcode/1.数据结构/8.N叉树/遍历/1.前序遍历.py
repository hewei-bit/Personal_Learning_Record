"""
589
# Definition for a Node.
"""
from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

#非递归
class Solution:
    def preorder(self, root: Node) -> List[int]:
        if not root:
            return []
        stack, res = [], []
        stack.append(root)
        while stack:
            temp = stack.pop()
            res.append(temp.val)
            if temp.children:
                for i in temp.children[::-1]:
                    stack.append(i)
        return res
#递归
class Solution2:
    def preorder(self, root: Node) -> List[int]:
        if not root:
            return []
        res = [root.val]
        if root.children:
            for item in root.children:
                res += self.preorder(item)
        return res


if __name__ == '__main__':
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)
    n1.children = [n2, n3, n4]
    n2.children = [n5]
    obj = Solution2().preorder(n1)
    print(obj)
