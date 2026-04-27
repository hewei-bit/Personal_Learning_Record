"""
动态规划的核心设计思想是数学归纳法。

相信大家对数学归纳法都不陌生，高中就学过，而且思路很简单。
比如我们想证明一个数学结论，那么我们先假设这个结论在 k<n 时成立，
然后想办法证明 k=n 的时候此结论也成立。如果能够证明出来，
那么就说明这个结论对于 k 等于任何数都成立。

类似的，我们设计动态规划算法，不是需要一个 dp 数组吗？我们可以假设 dp[0...i−1]
都已经被算出来了，然后问自己：怎么通过这些结果算出dp[i] ?

直接拿最长递增子序列这个问题举例你就明白了。
不过，首先要定义清楚 dp 数组的含义，即 dp[i] 的值到底代表着什么？

我们的定义是这样的：dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度。
"""

"""
300. 最长上升子序列
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是[2,3,7,101]，它的长度是 4。

"""
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        res = 0
        for i in range(len(nums)):
            res = max(dp[i], res)
        return res


if __name__ == '__main__':
    s = "babad"
    print(Solution().lengthOfLIS(s))
