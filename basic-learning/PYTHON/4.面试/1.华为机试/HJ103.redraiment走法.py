

while True:
    try:
        a = int(input())
        
        str_input = input().split()
        ll = [int(v) for v in str_input]  # 输入的数组成的集合

        if not ll:
            print(0)
        dp = [1] * len(ll)
        for i in range(len(ll)):
            for j in range(i):
                if ll[i] > ll[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        res = 0
        for i in range(len(ll)):
            res = max(dp[i], res)
        print(res)
    except:
        break