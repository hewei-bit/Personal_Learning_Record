class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return
            # 找到了
        if root.val == key:
            # 左子树或者右子树为空
            if root.left is None: return root.right
            if root.right is None: return root.left
            # 左子树或右子树不为空
            # 获取右子树的最小值
            minNode = self.getmin(root.right)
            root.val = minNode.val
            root.right = self.deleteNode(root.right, minNode.val)
        # 前往右子树
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        # 前往左子树
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        return root

    def getmin(self, root: TreeNode):
        while root.left is not None:
            root = root.left
        return root


if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(4)
    d = TreeNode(3)
    e = TreeNode(5)
    b.left = a
    b.right = c
    c.left = d
    c.right = e
