"""
35. 搜索插入位置(easy)

二分查找
"""
from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        right = len(nums) - 1
        left = 0
        size = len(nums)
        if nums[size - 1] < target:
            return size

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif target > nums[mid]:
                left = mid + 1
            else:
                right = mid-1
        return left


if __name__ == '__main__':
    l = [0, 1, 8, 20, 203, 221]
    obj = Solution().searchInsert(l, 12)
    print(obj)
