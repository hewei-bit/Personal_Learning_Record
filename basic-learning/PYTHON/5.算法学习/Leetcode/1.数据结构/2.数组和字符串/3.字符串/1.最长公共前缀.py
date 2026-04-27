"""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
"""

# 两两比较，找到最短前缀字符串

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        pre, count = strs[0], len(strs)
        for i in range(1, count):
            pre = self.lcp(pre, strs[i])
            if not pre:
                break
        return pre

    def lcp(self, s1: str, s2: str):
        index = 0
        length = min(len(s1), len(s2))
        while index < length and s1[index] == s2[index]:
            index += 1
        return s1[:index]


if __name__ == '__main__':
    s = ["flower", "flow", "flight"]

    print(Solution().longestCommonPrefix(s))
