"""
104. 二叉树的最大深度(easy)
"""


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# 递归
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return max(left, right) + 1


# BFS 层序遍历
class Solution1:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        depth = 0
        queue = [(1, root)]
        while queue:
            depth, node = queue.pop(0)
            if node.left:
                queue.append((depth + 1, node.left))
            if node.right:
                queue.append((depth + 1, node.right))
        return depth


# DFS 先序遍历
class Solution2:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [(1, root)]
        depth = 0
        while stack:
            cur_depth, node = stack.pop()
            depth = max(depth, cur_depth)
            if node.right:
                stack.append((cur_depth + 1, node.right))
            if node.left:
                stack.append((cur_depth + 1, node.left))
        return depth

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
    obj = Solution2().maxDepth(n1)
    print(obj)
