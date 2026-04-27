"""
76. 最小覆盖子串

给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
。
"""

import collections


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = collections.defaultdict(int)
        window = collections.defaultdict(int)
        # 目标放入字典
        for c in t:
            need[c] += 1
        needlen = len(need)
        left, right = 0, 0
        vaild = 0
        # 记录最小覆盖子串的起始索引及长度
        start = 0
        length = float('inf')
        while right < len(s):
            # e 是将移入窗口的字符
            e = s[right]
            # 右移窗口
            right += 1
            # 进行窗口内数据的一系列更新
            if need[e] > 0:
                window[e] += 1
                if window[e] == need[e]:
                    vaild += 1
            # 判断左侧窗口是否要收缩
            while vaild == needlen:
                # 在这里更新最小覆盖子串
                if (right - left) < length:
                    start = left
                    length = right - left
                # d是将移出窗口的字符
                d = s[left]
                # 左移窗口
                left +=1
                # 进行窗口内数据的一系列更新
                if need[d] > 0:
                    if window[d] == need[d]:
                        vaild -= 1
                    window[d] -= 1
        # 返回最小覆盖子串
        end = start + length

        return "" if length == float('inf') else s[start:end]


if __name__ == '__main__':
    S = "ADOBECODEBANC"
    T = "ABC"
    obj = Solution().minWindow(S, T)
    print(obj)
