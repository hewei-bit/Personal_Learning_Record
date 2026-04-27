"""
面试题28. 对称的二叉树(easy)
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True

        def helper(t1: TreeNode, t2: TreeNode):
            if t1 is None and t2 is None:
                return True
            if t1 is None or t2 is None:
                return False
            if t1.val != t2.val:
                return False
            return helper(t1.left, t2.right) and helper(t1.right, t2.left)

        return helper(root.left, root.right)


if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(20)
    root.right = TreeNode(20)
    # root.right.right = TreeNode(7)
    # root.right.left = TreeNode(15)

    print(Solution().isSymmetric(root))
