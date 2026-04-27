"""
704. 二分查找(easy)
"""


from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (right + left) // 2
            if nums[mid] > target:
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] == target:
                return mid

        return -1


if __name__ == '__main__':
    l = [-1, 0, 3, 5, 9, 12]
    obj = Solution().search(l, 9)
    print(obj)
