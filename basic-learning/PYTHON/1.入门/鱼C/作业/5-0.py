temp = input("不妨猜一下小甲鱼现在心里想的是哪个数字：")
# 这种想法是因为 type(1) 会返回 <class 'int'>，如果 type(temp) 返回结果一致说明输入是整数。
while type(temp) != type(1):
    print("抱歉，输入不合法，",end = '')
    temp = input("请输入一个整数：")
