# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        stack, res = [], []
        node = root
        while stack or node:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            res.append(node.val)
            node = node.right
        return res

    def Morris(self, root: TreeNode):
        # Set current to root of binary tree
        curr = root

        while curr is not None:

            if curr.left is None:
                print(curr.data)
                curr = curr.right
            else:
                # Find the previous (prev) of curr
                prev = curr.left
                while prev.right is not None and prev.right != curr:
                    prev = prev.right

                # Make curr as right child of its prev
                if prev.right is None:
                    prev.right = curr
                    curr = curr.left

                # fix the right child of prev
                else:
                    prev.right = None
                    print(curr.data)
                    curr = curr.right


if __name__ == '__main__':
    n1 = TreeNode(1)
    n2 = TreeNode(2)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n5 = TreeNode(5)
    n1.left = n2
    n1.right = n3
    n2.left = n4
    n2.right = n5
    obj = Solution().inorderTraversal(n1)
    print(obj)
