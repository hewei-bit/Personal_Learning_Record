"""
56. 合并区间(medium)
"""

from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        res = []
        intervals.sort(key=lambda x: x[0])
        for inter in intervals:
            if res == [] or res[-1][1] < inter[0]:
                res.append(inter)
            else:
                res[-1][1] = max(res[-1][1], inter[1])
        return res


if __name__ == '__main__':
    ll = [[1, 6], [2, 3], [7, 9]]
    obj = Solution().merge(ll)
    print(obj)
