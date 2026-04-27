

'''
guess = eval(input('请输入一个数字'))
print('猜{}了'.format('对'if guess == 99 else '错'))
'''

'''
height,weight = eval(input("请输入身高（米）和体重（公斤）[用逗号隔开]："))
bmi = weight / pow(height,2)
print("你的BMI指数为{}".format(bmi))
who,nat = "",""
if bmi < 18.5:
    who,nat = "偏瘦","偏瘦"
    print("国际上你的体型{}，国内你的体型{}".format(who,nat))
elif 18.5 <= bmi < 24:
    who,nat = "正常","正常"
    print("国际上你的体型{}，国内你的体型{}".format(who,nat))
elif 24 <= bmi < 25:
    who,nat = "正常","偏胖"
    print("国际上你的体型{}，国内你的体型{}".format(who,nat))
elif 25 <= bmi < 28:
    who,nat = "偏胖","偏胖"
    print("国际上你的体型{}，国内你的体型{}".format(who,nat)) 
elif 28 <= bmi < 30:
    who,nat = "偏胖","肥胖"
    print("国际上你的体型{}，国内你的体型{}".format(who,nat))
'''

'''
s = 'PYTHON'
while s != '':
    for c in s:
        if c == 'T':
            break
        print(c,end='')
    s = s[:-1]
'''

'''
pi = 0
N = 100
for k in range(N):
    pi += 1/pow(16,k)*(\
        4/(8*k+1) - 2/(8*k+4) - \
        1/(8*k+5) - 1/(8*k+6))
print("圆周率值是：{}".format(pi))
'''

'''
from random import random
from time import perf_counter
DARTS = 1000*1000
HITS = 0.0
start = perf_counter()
for i in range(1,DARTS + 1):
    x,y = random(),random()
    DIS = pow((x**2 + y**2),0.5)
    if(DIS <= 1.0):
        HITS = HITS + 1
pi =4 * HITS/DARTS
print("蒙特卡洛方法的圆周率是：{:.5f}".format(pi))
print("程序所用的时间：{:.5f}".format(perf_counter() - start))
'''































