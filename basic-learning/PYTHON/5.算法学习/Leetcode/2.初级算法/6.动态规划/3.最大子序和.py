"""
53. 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
"""

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        length = len(nums)
        dp = [0] * length
        dp[0] = nums[0]

        for i in range(1, length):
            dp[i] = max(nums[i], nums[i] + dp[i - 1])

        res = float('-inf')
        for i in range(length):
            res = max(res, dp[i])

        return res


if __name__ == '__main__':
    l1 = [1]
    l = [-12, -23, -3, 234, 23, -5]
    obj = Solution().maxSubArray(l)
    print(obj)
