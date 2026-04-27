'''
#week
weekstr = '一二三四五六日'
weekID = eval(input("请输入星期（1-7）:"))
print("星期"+ weekstr[weekID - 1])
'''

'''
for i in range(12):
    print(chr(9800 + i),end = "\n")
'''

'''
import time
scale = 10
print("-----执行开始-----")
for i in range(scale + 1):
    a = '*' * i
    b = '.' * (scale - i)
    c = (i/scale)*100
    print("{:^3.0f}%[{}->{}]".format(c,a,b))
    time.sleep(0.1)
print("-----执行开始-----")
'''

'''
import time
scale = 100
for i in range(scale + 1):
    print("\r{:3}%".format(i),end="")
    time.sleep(0.1)
'''


import time
scale = 20
print("执行开始".center(scale//2,"-"))
start = time.perf_counter()
for i in range(scale + 1):
    a = '*' * i
    b = '.' * (scale - i)
    c = (i/scale)*100
    dur = time.perf_counter() - start
    print("{:^3.0f}%[{}->{}]{:.2f}s".format(c,a,b,dur),end="")
    time.sleep(0.1)
print("\n"+"执行开始".center(scale//2,"-"))
























