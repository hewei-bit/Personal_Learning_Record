import sys
import collections
while True:
    try:
        a = input()
        b = {}
        for i in range(int(a)):
            c, d = map(int, sys.stdin.readline().split())
            if c not in b:
                b[c] = d
            else:
                b[c] = b[c] + d
        for i in sorted(b.keys()):
            print(i, b[i])

    except:
        break

