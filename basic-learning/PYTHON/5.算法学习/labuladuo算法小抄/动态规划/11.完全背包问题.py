"""
518. 零钱兑换 II
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。
假设每一种面额的硬币有无限个。

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

"""
"""
第一步 明确状态和选择

for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 计算(选择1，选择2...)
"""
"""            
第二歩 确定dp数组含义

首先看看刚才找到的「状态」，有两个，也就是说我们需要一个二维dp数组。
dp[i][j]的定义如下：
若只使用前i个物品，当背包容量为j时，有dp[i][j]种方法可以装满背包。
换句话说，翻译回我们题目的意思就是：
若只使用coins中的前i个硬币的面值，若想凑出金额j，有dp[i][j]种凑法。

base case 为dp[0][..] = 0， dp[..][0] = 1。
因为如果不使用任何硬币面值，就无法凑出任何金额；如果凑出的目标金额为 0，那么“无为而治”就是唯一的一种凑法。
我们最终想得到的答案就是dp[N][amount]，其中N为coins数组的大小。

int dp[N+1][amount+1]
dp[0][..] = 0
dp[..][0] = 1

for i in [1..N]:
    for j in [1..amount]:
        把物品 i 装进背包,
        不把物品 i 装进背包
return dp[N][amount]
"""
"""
第三步，根据「选择」，思考状态转移的逻辑

如果你不把这第i个物品装入背包，也就是说你不使用coins[i]这个面值的硬币，
那么凑出面额j的方法数dp[i][j]应该等于dp[i-1][j]，继承之前的结果。

如果你把这第i个物品装入了背包，也就是说你使用coins[i]这个面值的硬币，
那么dp[i][j]应该等于dp[i][j-coins[i-1]]。

首先由于i是从 1 开始的，所以coins的索引是i-1时表示第i个硬币的面值。

比如说，你想用面值为 2 的硬币凑出金额 5，那么如果你知道了凑出金额 3 的方法，
再加上一枚面额为 2 的硬币，不就可以凑出 5 了嘛。

综上就是两种选择，而我们想求的dp[i][j]是「共有多少种凑法」，
所以dp[i][j]的值应该是以上两种选择的结果之和：

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= amount; j++) {
        if (j - coins[i-1] >= 0)
            dp[i][j] = dp[i - 1][j] 
                     + dp[i][j-coins[i-1]];
return dp[N][W]


最后一步，把伪码翻译成代码，处理一些边界情况。
"""

from typing import List


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[0 for _ in range(amount + 1)] for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 1
        for i in range(1, n + 1):
            for j in range(1, amount + 1):
                if j - coins[i-1] >= 0:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i-1]]
                else:
                    dp[i][j] = dp[i - 1][j]
        return dp[n][amount]


if __name__ == '__main__':
    amount = 5
    coins = [1, 2, 5]
    print(Solution().change(amount,coins))