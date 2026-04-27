from typing import List
import sys


class Node:
    def __init__(self, val: int):
        self.val = val
        self.next = None


# BFS框架
def BFS(start: Node, target: Node):
    queue = []  # 核心数据结构
    visited = set()  # 避免走回头路

    queue.append(start)  # 将起点加入队列
    visited.add(start)
    step = 0  # 记录扩散步数
    while queue:
        # 将当前队列中的所有节点向四周扩散
        for i in range(len(queue)):
            cur = queue.pop(0)
            # 划重点：这里判断是否到达终点
            if cur == target:
                return step
            # 将 cur 的相邻节点加入队列
            for x in cur:
                if x not in visited:
                    queue.append(x)
                    visited.add(x)
        # 划重点：更新步数在这里
        step += 1


"""
111.二叉树的最小高度
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue = []
        queue.append(root)
        depth = 1
        while queue:
            for i in range(len(queue)):
                cur = queue.pop(0)
                if cur.left == None and cur.right == None:
                    return depth
                if cur.left is not None:
                    queue.append(cur.left)
                if cur.right is not None:
                    queue.append(cur.right)
            depth += 1
        return depth


class Solution_1:
    def plusOne(self, s: str, j: int):
        if s[j] == '9':
            s = s[:j] + '0' + s[j + 1:]
        else:
            s = s[:j] + str(int(s[j]) + 1) + s[j + 1:]

        return s

    def minusOne(self, s: str, j: int):
        if s[j] == '0':
            s = s[:j] + '9' + s[j + 1:]
        else:
            s = s[:j] + str(int(s[j]) - 1) + s[j + 1:]

        return s

    def openLock(self, deadends: List[str], target: str) -> int:
        # 核心结构
        queue = []
        queue.append("0000")
        # 记录穷举过的密码
        visited = set()
        visited.add("0000")
        # 记录需要跳过的死亡密码
        dead = []
        for ch in deadends:
            dead.append(ch)
        # 步数
        step = 0

        while queue:
            for i in range(len(queue)):
                cur = queue.pop(0)
                # print(cur)
                # 判断是否到达终点
                if cur in deadends:
                    continue
                if cur == target:
                    return step
                # 将一个节点的未遍历相邻节点加入队列
                for j in range(4):
                    up = self.plusOne(cur, j)
                    if up not in visited:
                        queue.append(up)
                        visited.add(up)
                    down = self.minusOne(cur, j)
                    if down not in visited:
                        queue.append(down)
                        visited.add(down)
            # 增加步数
            step += 1
        return -1


if __name__ == '__main__':
    dead = ["0201", "0101", "0102", "1212", "2002"]
    tar = "0202"
    obj = Solution_1().openLock(dead, tar)
