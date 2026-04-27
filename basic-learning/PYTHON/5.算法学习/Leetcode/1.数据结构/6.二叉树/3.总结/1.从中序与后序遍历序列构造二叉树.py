"""
105. 从前序与中序遍历序列构造二叉树(medium)
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return
        root = TreeNode(postorder[-1])
        root_id = inorder.index(postorder[-1])
        root.left = self.buildTree(inorder[:root_id], postorder[:root_id])
        root.right = self.buildTree(inorder[root_id + 1:], postorder[root_id:-1])
        return root
