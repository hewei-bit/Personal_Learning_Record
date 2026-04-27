"""
438. 找到字符串中所有字母异位词
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

"""
from typing import List
import collections


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        need = collections.defaultdict(int)
        window = collections.defaultdict(int)
        for c in p:
            need[c] += 1
        # 左右指针
        left, right = 0, 0
        vaild = 0
        l = len(need)
        res = []
        while right < len(s):
            e = s[right]
            right += 1
            # 右移操作
            if need[e] > 0:
                window[e] += 1
                if window[e] == need[e]:
                    vaild += 1
            # 判断窗口是否需要收缩
            while (right - left) >= len(p):
                if vaild == l:
                    res.append(left)
                d = s[left]
                left += 1
                if need[d] > 0:
                    if window[d] == need[d]:
                        vaild -= 1
                    window[d] -= 1

        return res


if __name__ == '__main__':
    s = "cbaebabacd"
    p = "abc"
    obj = Solution().findAnagrams(s, p)
    print(obj)
