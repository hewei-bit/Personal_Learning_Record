"""
337. 打家劫舍 III
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.


"""
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# 暴力递归超时！！！！
class Solution1:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        money = root.val
        if root.left is not None:
            money += (self.rob(root.left.left) + self.rob(root.left.right))
        if root.right is not None:
            money += (self.rob(root.right.left) + self.rob(root.right.right))
        return max(money, self.rob(root.left) + self.rob(root.right))


class Solution2:
    def dp(self, root: TreeNode) -> [List[int], list]:
        if not root:
            return [0, 0]  # 列表[0]代表当前节点不偷带来的钱，列表[1]代表当前节点偷带来的钱
        l = self.dp(root.left)  # root的左节点[不偷][偷]带来的钱
        r = self.dp(root.right)  # root的右节点[不偷][偷]带来的钱
        # root节点不偷，则偷左右儿子节点，取左儿子偷或不偷的最大值和右儿子偷或不偷的最大值；
        # root节点偷，则root节点值+左儿子不偷+右儿子不偷。
        return [max(l) + max(r), root.val + l[0] + r[0]]

    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        return max(self.dp(root))  # 取root节点偷或不偷的最大值


if __name__ == '__main__':
    a = TreeNode(3)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(3)
    e = TreeNode(1)
    a.left = b
    a.right = c
    b.right = d
    c.right = e
    obj = Solution2().rob(a)
