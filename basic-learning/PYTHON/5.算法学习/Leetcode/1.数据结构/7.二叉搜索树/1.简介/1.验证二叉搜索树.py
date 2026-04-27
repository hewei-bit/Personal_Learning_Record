"""
面试题 04.05. 合法二叉搜索树
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        pre = float('-inf')
        stack = []
        node = root

        while stack or node:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if node.val <= pre:
                return False
            pre = node.val
            node = node.right
        return True




if __name__ == '__main__':
    n1 = TreeNode(1)
    n2 = TreeNode(1)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n5 = TreeNode(5)
    n1.left = n2
    # n1.right = n3
    # n2.left = n4
    # n2.right = n5
    obj = Solution().isValidBST(n1)
    print(obj)
