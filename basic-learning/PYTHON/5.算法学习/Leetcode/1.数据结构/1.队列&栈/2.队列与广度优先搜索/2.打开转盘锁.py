"""
752. 打开转盘锁(medium)
"""

from typing import List


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        if '0000' in deadends:
            return -1
        queue = [('0000', 0)]
        while queue:
            node, step = queue.pop(0)  # 取出一个节点
            # 放入周围节点
            for i in range(4):
                for add in (1, -1):
                    cur = node[:i] + str((int(node[i]) + add) % 10) + node[i + 1:]
                    if cur == target:
                        return step + 1
                    if not cur in deadends:
                        queue.append((cur, step + 1))
                        deadends.add(cur)
        return -1
