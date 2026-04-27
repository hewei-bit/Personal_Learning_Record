"""
题目描述：
给你一个长度为n的01串。现在想让你找出最长的01交替子串（子串可以不连续）
比如：1010,0101是01交替的串，1101则不是。现在你可以把某一个连续的区间进行翻转，即0变1，1变0。
问修改之后的最大01交替子串的长度是多少。

输入描述
输入第一行包含一个整数n （1 <= n <= 100000) 表示01串的长度。 第二行包含一个01串。

输出描述
输出一个数表示符合题意的子串长度

样例输入
8
10000011
样例输出
5
"""

n = int(input())
s = input()
nn = 8
ss = "10000011"


def zeroToone(length: int, str_01: str) -> int:
    if not str_01:
        return 0
    count = 0
    stack = [str_01[0]]
    for i in range(1, length):
        temp = stack.pop()
        if str_01[i] != temp:
            count += 1

        stack.append(str_01[i])
    return count


res = zeroToone(nn, ss)
print(res)
