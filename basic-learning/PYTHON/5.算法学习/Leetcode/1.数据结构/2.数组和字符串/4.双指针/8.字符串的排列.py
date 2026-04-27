"""
567.字符串的排列
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False

"""

import collections


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        need = collections.defaultdict(int)
        window = collections.defaultdict(int)
        # 目标放入字典
        for c in s1:
            need[c] += 1
        left, right = 0, 0
        vaild = 0
        l = len(need)
        while right < len(s2):
            e = s2[right]  # e 是将移入窗口的字符
            right += 1  # 右移窗口
            # 进行窗口内数据的一系列更新
            if need[e] > 0:
                window[e] += 1
                if window[e] == need[e]:
                    vaild += 1
            # 判断左侧窗口是否要收缩
            while right - left >= len(s1):
                if vaild == l:
                    return True
                d = s2[left]  # d是将移出窗口的字符
                left += 1  # 左移窗口
                # 进行窗口内数据的一系列更新
                if need[d] > 0:
                    if window[d] == need[d]:
                        vaild -= 1
                    window[d] -= 1

        # 未找到符合条件的子串
        return False


if __name__ == '__main__':
    S = "abcdxabcde"

    T = "abcdeabcdx"
    obj = Solution().checkInclusion(T, S)
    print(obj)
