import sys
while True:
    try:
        n = int(input())
        set1 = set()
        for i in range(n):
            set1.add(int(input()))

        nums = list(set1)
        nums.sort()
        for i in nums:
            print(i)
    except:
        break