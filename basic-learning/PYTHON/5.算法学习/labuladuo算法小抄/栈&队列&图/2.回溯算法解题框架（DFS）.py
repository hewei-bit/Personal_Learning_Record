"""
1、 路径： 也就是已经做出的选择。
2、 选择列表： 也就是你当前可以做的选择。
3、 结束条件： 也就是到达决策树底层， ⽆法再做选择的条件

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        #做选择
        将路径从选择列表中取出
        路径add
        backtrack(路径, 选择列表)
        #撤销选择
        路径remove
        该选择加回选择列表


"""
from typing import List


# 全排列
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        track = []

        def backtrack(nums: List[int], track: List[int], res: List[List[int]]):
            # 触发条件
            if len(track) == len(nums):
                res.append(track[:])
                return
            for num in nums:
                # 排除不合法
                if num in track:
                    continue
                # #做选择
                track.append(num)
                backtrack(nums, track, res)
                # 撤销选择
                track.pop()

        backtrack(nums, track, res)
        return res


# N皇后


# 目标和


if __name__ == '__main__':
    pass
    # s = [1, 2, 3]
    # obj = Solution().permute(s)
