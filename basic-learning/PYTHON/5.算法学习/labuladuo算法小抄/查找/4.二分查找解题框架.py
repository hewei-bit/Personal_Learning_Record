from typing import List


# 1.最基本的二分查找算法
# 因为我们初始化 right = nums.length - 1
# 所以决定了我们的「搜索区间」是 [left, right]
# 所以决定了 while (left <= right)
# 同时也决定了 left = mid+1 和 right = mid-1
#
# 因为我们只需找到一个 target 的索引即可
# 所以当 nums[mid] == target 时可以立即返回
class Solution1:
    def binarySearch_1(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        # End Condition: left > right
        return -1


# 2.寻找左侧边界的二分查找

    def binarySearch_2(self, nums: List[int], target: int) -> int:
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


# 3.寻找右侧边界的二分查找

    def binarySearch_3(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        left = 0
        right = len(nums) - 1
        while left + 1 < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid
            else:
                right = mid
        if nums[left] == target:return left
        if nums[right] == target:return right



class Solution2:




if __name__ == '__main__':
    ll = [1, 20, 20, 21, 22, 234, 356]
    print(Solution1().binarySearch_1(ll, 20))
