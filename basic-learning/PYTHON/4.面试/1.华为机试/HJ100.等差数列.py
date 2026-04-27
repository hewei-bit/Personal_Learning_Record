import sys
for s in sys.stdin:
    try:
        n = int(s)
        d = 3
        a1 = 2
        an = a1 + (n-1)*d
        sums = (a1 + an)/2 * n
        print(int(sums))
    except:
        print(-1)