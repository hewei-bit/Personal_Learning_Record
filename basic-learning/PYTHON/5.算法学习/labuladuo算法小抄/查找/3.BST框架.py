class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


"""
BST 框架
void BST(TreeNode root, int target) {
 if (root.val == target)
     // 找到目标，做点什么
 if (root.val < target) 
     BST(root.right, target);
 if (root.val > target)
     BST(root.left, target);
}
"""


class Solution:
    def traverse(self, root: TreeNode):
        # root需要做什么？在这做
        # 其他操作抛给框架
        self.traverse(root.left)
        self.traverse(root.right)

    # 1.给所有节点加一
    def plusone(self, root: TreeNode):
        if not root:
            return
        root.val += 1
        self.plusone(root.left)
        self.plusone(root.right)

    # 2.如何判断两棵二叉树是否完全相同
    def isSameTree(self, root1: TreeNode, root2: TreeNode):
        # 都为空，相同
        if root1 is None and root2 is None:
            return True
        # 一个空一个不空，不相同
        if root1 is None or root2 is None:
            return False
        # 两个不空，val不一样
        if root1.val != root2.val:
            return False
        # root1和root2比完了
        return self.isSameTree(root1.left, root2.left) and self.isSameTree(root1.right, root2.right)

    # 3.判断是否为二叉搜索树
    def isValidBST_recursive(self, root: TreeNode):
        return self.isValidBSThelp(root, None, None)

    def isValidBSThelp(self, root: TreeNode, min: TreeNode, max: TreeNode):
        if not root:
            return True
        if min and root.val <= min.val:
            return False
        if max and root.val >= min.val:
            return False
        return self.isValidBSThelp(root.left, min, root) and self.isValidBSThelp(root.right, root, max)

    def isValidBST_iteration(self, root: TreeNode) -> bool:
        if not root:
            return True
        pre = float('-inf')
        stack = []
        node = root
        # 中序遍历
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

    # 4.在BST中查找一个数是否存在
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return None
        if root.val == val:
            return root
        if root.val < val:
            return self.searchBST(root.right, val)
        if root.val > val:
            return self.searchBST(root.left, val)

    # 5.在BST中插入一个数
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        if root.val < val:
            root.right = self.insertIntoBST(root.right, val)
        if root.val > val:
            root.left = self.insertIntoBST(root.left, val)
        return root

    # 6.在BST中删除一个数
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return
            # 找到了
        if root.val == key:
            # 左子树或者右子树为空
            if root.left is None:
                return root.right
            if root.right is None:
                return root.left
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
