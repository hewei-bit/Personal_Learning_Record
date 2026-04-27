"""
第一步 明确dp数组含义
第二步 定义base case
第三步 找状态转移方程


第一步要明确两点，「状态」和「选择」。
先说状态，如何才能描述一个问题局面？只要给几个物品和一个背包的容量限制，就形成了一个背包问题呀。所以状态有两个，就是「背包的容量」和「可选择的物品」。
再说选择，也很容易想到啊，对于每件物品，你能选择什么？选择就是「装进背包」或者「不装进背包」嘛。

for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 择优(选择1，选择2...)
"""


# 一、斐波那契数列
# 1、暴力递归
class Solution1:
    def fib1(self, N: int):
        if N == 1 or N == 2:
            return 1
        return self.fib1(N - 1) + self.fib1(N - 2)


# 2、带备忘录的递归解法
class Solution2:
    def fib2(self, N: int):
        if N < 1:
            return 0
        memo = [0] * (N + 1)
        return help(memo, N)

    def help(self, memo: list, N: int):
        if N == 1 or N == 2:
            return 1
        if memo[N] != 0:
            return memo[N]
        memo[N] = help(memo, N - 1) + help(memo, N - 2)
        return memo[N]


# 3、dp 数组的迭代解法
class Solution3:
    def fib3(self, N: int):
        dp = [0] * (N + 1)
        dp[1] = dp[2] = 1
        for i in range(3, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[N]


# print(fib3(20))


# 二、凑零钱问题
"""
def coinChange(coins: List[int], amount: int):
    # 定义： 要凑出⾦额 n， ⾄少要 dp(n) 个硬币
    def dp(n):
        # 做选择， 选择需要硬币最少的那个结果
        for coin in coins:
        res = min(res, 1 + dp(n - coin))
        return res
    # 我们要求的问题是 dp(amount)
    return dp(amount)

"""



# 1、暴力递归
class Solution1_1:
    def coinChange(self, coins: list, amount: int):
        def dp(n):
            # base case
            if n == 0:
                return 0
            if n < 0:
                return -1
            # 求最小值，所以初始化为正无穷
            res = float('INF')
            for coin in coins:
                subproblem = dp(n - coin)
                # 子问题无解，跳过
                if subproblem == -1:
                    continue
                res = min(res, 1 + subproblem)

            return res if res != float('INF') else -1

        return dp(amount)


# 2、带备忘录的递归解法
class Solution1_2:
    def coinChange(self, coins: list, amount: int):
        memo = dict()

        def dp(n):
            # base case
            if n == 0:
                return 0
            if n < 0:
                return -1
            # 求最小值，所以初始化为正无穷
            res = float('INF')
            for coin in coins:
                subproblem = dp(n - coin)
                # 子问题无解，跳过
                if subproblem == -1: continue
                res = min(res, 1 + subproblem)

            memo[n] = res if res != float('INF') else -1
            return memo[n]

        return dp(amount)


# 3、dp 数组的迭代解法
class Solution1_3:
    def coinChange(self, coins: list, amount: int):
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(len(dp)):
            for coin in coins:
                if (i - coin) < 0:
                    continue
                dp[i] = min(dp[i], 1 + dp[i - coin])
        return -1 if (dp[amount] == amount + 1) else dp[amount]


coins = [1, 2, 5]
amount = 11
print(Solution1_1().coinChange(coins, amount))
