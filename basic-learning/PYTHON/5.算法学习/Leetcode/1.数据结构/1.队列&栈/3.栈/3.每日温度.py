"""
请根据每日 气温 列表，重新生成一个列表。
对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，
都是在 [30, 100] 范围内的整数。
"""

from typing import List


class Solution1:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        l = len(T)
        stack = []
        res = [0] * l
        for idx, t in enumerate(T):
            while stack and t > T[stack[-1]]:
                res[stack.pop()] = idx - stack[-1]
            stack.append(idx)
        return res


# 暴力解法
class Solution2:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        d = {}
        ans = [0] * len(T)
        for i in range(len(T) - 1, -1, -1):  # 从后向前遍历
            d[T[i]] = i  # 记录当前问题的最小下标
            tmp = [d[t] - i for t in range(T[i] + 1, 101) if t in d]
            ans[i] = (min(tmp) if tmp else 0)
        return ans


# 单调栈
class Solution3:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        ans = [0] * len(T)
        stack = []
        for i in range(len(T)):
            while stack and T[stack[-1]] < T[i]:
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return ans


if __name__ == '__main__':
    temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    res = Solution2().dailyTemperatures(temperatures)
