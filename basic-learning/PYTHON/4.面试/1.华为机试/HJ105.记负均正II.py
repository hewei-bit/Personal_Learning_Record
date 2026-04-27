

while True:
    try:
        a = input().split()
        pos = []
        neg = []
        for i in a:
            if int(i) >= 0:
                pos.append(int(i))
            else:
                neg.append(int(i))

        neglen = len(neg)
        print(neglen)
        if pos:
            print("%.1f" % (sum(pos) / (len(pos))))
        else:
            print(0.0)
    except:
        break