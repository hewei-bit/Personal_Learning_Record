


while True:
    try:
        a = input().split()
        print(len(a[-1]) if len(a) > 1 else len(a[0]))
    break
