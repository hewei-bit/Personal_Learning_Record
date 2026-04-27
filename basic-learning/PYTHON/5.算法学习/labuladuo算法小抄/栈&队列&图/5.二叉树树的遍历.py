from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    # 二叉树的前序遍历(medium)
    def preorderTraversal_1(self, root: TreeNode) -> List[int]:
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        resls = []
        stack, node = [], root
        while stack or node:
            while node:
                stack.append(node)
                resls.append(node.val)
                node = node.left
            node = stack.pop()
            node = node.right
        return resls

    def preorderTraversal_2(self, root: TreeNode) -> List[int]:
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        res, stack = [], []
        stack.append(root)
        while stack:
            node = stack.pop()
            res.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return res

    # 二叉树的中序遍历(medium)
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

    # 二叉树的后序遍历(medium)
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        res = []
        stack1 = []
        stack2 = []
        node = root
        stack1.append(node)
        while stack1:
            node = stack1.pop()
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)
            stack2.append(node)
        while stack2:
            res.append(stack2.pop().val)
        return res

    # 二叉树的层序遍历(medium)
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res, cur_level = [], []
        cur_level.append(root)
        while cur_level:
            temp = []
            next_level = []
            for i in cur_level:
                temp.append(i.val)

                if i.left:
                    next_level.append(i.left)
                if i.right:
                    next_level.append(i.right)
            res.append(temp)
            cur_level = next_level
        return res
