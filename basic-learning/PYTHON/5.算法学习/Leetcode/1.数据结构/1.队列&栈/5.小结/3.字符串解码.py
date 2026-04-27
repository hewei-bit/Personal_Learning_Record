"""
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"

"""


class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return ""
        res = ""
        num = 0
        stack = []
        for c in s:
            if c == "[":
                stack.append([num, res])
                res, num = "", 0
            elif c == "]":
                cur_num, last_res = stack.pop()
                res = last_res + cur_num * res
            elif "0" <= c <= "9":
                num = num * 10 + int(c)
            else:
                res += c
        return res


if __name__ == '__main__':
    s = "3[a]2[bc]"
    s1 = "3[a2[c]]"
    s2 = "100[leetcode]"
    obj = Solution().decodeString(s2)
    print(obj)
