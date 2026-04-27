"""
429. N叉树的层序遍历(medium)

"""
from typing import List


class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: Node) -> List[List[int]]:
        if not root:
            return []
        res = []
        cur_level = [root]
        while cur_level:
            temp = []
            next_level = []
            for i in cur_level:
                temp.append(i.val)
                for j in i.children:
                    next_level.append(j)
            res.append(temp)
            cur_level = next_level
        return res
