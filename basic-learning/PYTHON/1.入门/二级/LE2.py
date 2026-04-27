
TemStr = input("请输入带有符号的温度值")

if TemStr[-1] in ['F','f']:
    C = (eval (TemStr[0 : -1] - 32)/1.8)
    print("转换后的温度是{:.2f}C".format(C))
elif TemStr[-1] in ['C','c']:
    F = eval (TemStr[0 : -1])*1.8 + 32
    print("转换后的温度是{:.2f}F".format(F))
else:
    print("输入格式错误")
