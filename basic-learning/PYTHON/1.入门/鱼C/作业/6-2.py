#i = 0
#while i<200:
    #if (i%2 == 1)and(i%3 == 2)and(i%4 == 3)and(i%5 == 4)and(i%6 == 5):
   #     print('i')
  #  else:
 #       i +=7
#    i+=1
x = 7
i = 1
flag = 0

while i <= 100:
    if (x%2 == 1) and (x%3 == 2) and (x%5 == 4) and (x%6==5):
        flag = 1
    else:
        x = 7 * (i+1) # 根据题意，x一定是7的整数倍，所以每次乘以7
    i += 1

if flag == 1:
    print('阶梯数是：', x)
else:
    print('在程序限定的范围内找不到答案！')
