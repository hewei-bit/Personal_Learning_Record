"""
724. 寻找数组的中心索引(easy)
"""

from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if not nums:
            return -1
        _sum, left_sum = sum(nums), 0
        for i in range(len(nums)):
            if left_sum*2 + nums[i] == _sum:
                return i
            left_sum += nums[i]
        return -1


if __name__ == '__main__':
    l = [1, 2, 3, 4, 2, 5, 12]
    obj = Solution().pivotIndex(l)
    print(obj)
