"""
69. x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2

"""


class Solution:
    def mySqrt(self, x: int) -> int:
        left, right,ans = 0, x,-1
        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid
            if square <= x:
                left = mid + 1
            else:
                right = mid - 1
        ans = mid
        return ans


if __name__ == '__main__':
    x = 89
    print(Solution().mySqrt(x))
