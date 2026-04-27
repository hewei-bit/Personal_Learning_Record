from typing import List

# 2.寻找左侧边界的二分查找
class Solution2:
    def binarySearch(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1

        left, right = 0, len(nums)
        # 搜索区间为[left,right)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid

        # 检查出界
        if left != len(nums) and nums[left] == target:
            return left
        return -1
