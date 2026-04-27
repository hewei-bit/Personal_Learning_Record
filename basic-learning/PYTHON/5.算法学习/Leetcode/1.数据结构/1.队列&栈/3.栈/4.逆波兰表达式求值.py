"""
150. 逆波兰表达式求值

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6

"""
from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        symbol = ["+", "-", "*", "/"]
        recList = []

        if len(tokens) == 0:
            return 0
        for i in tokens:
            if i not in symbol:
                recList.append(i)
            else:
                b = int(recList.pop())
                a = int(recList.pop())
                if i == "+":
                    recList.append(str(a + b))
                elif i == "-":
                    recList.append(str(a - b))
                elif i == "*":
                    recList.append(str(a * b))
                elif i == "/":
                    recList.append(str(int(a / b)))
        return int(recList[0])


if __name__ == '__main__':
    l = ["4", "13", "5", "/", "+"]
    obj = Solution().evalRPN(l)
    print(obj)
