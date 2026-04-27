"""
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

"""

from typing import List


# 常规
class Solution1:
    def rob(self, nums: List[int]) -> int:
        return self.dp(nums, 0)

    def dp(self, nums: List[int], start):
        if start >= len(nums):
            return 0
        res = max(self.dp(nums, start + 1), nums[start] + self.dp(nums, start + 2))
        return res


# 带备忘录
class Solution2:
    def rob(self, nums: List[int]) -> int:
        length = len(nums)
        memo = [-1] * length
        return self.dp(nums, 0, memo)

    def dp(self, nums: List[int], start: int, memo: List[int]) -> int:
        if start >= len(nums):
            return 0
        if memo[start] != -1:
            return memo[start]
        res = max(self.dp(nums, start + 1, memo), self.dp(nums, start + 2, memo) + nums[start])
        memo[start] = res
        return res


# 自底而上
class Solution3:
    def rob(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 0:
            return 0
        robbed = [0] * (N + 1)
        robbed[0] = 0
        robbed[1] = nums[0]
        for i in range(2, N + 1):
            robbed[i] = max(robbed[i - 1], robbed[i - 2] + nums[i - 1])
        return robbed[i]


# 自底而上化简
class Solution4:
    def rob(self, nums: List[int]) -> int:
        pre1 = 0
        pre2 = 0
        for i in range(len(nums)):
            cur = max(pre2 + nums[i], pre1)
            pre2 = pre1
            pre1 = cur
        return pre1


if __name__ == '__main__':
    l = [1, 2, 3, 1]
    obj = Solution3().rob(l)
    print(obj)
