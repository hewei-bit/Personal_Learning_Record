#question 1
'''
def isNUM(n):
    m = type(eval(n))
    try:
        if m == type(1):
            return True
        elif m == type(1.0):
            return True
        elif m == type(1+1j):
            return True
    except:
        return False

a = input('n')
print(isNUM(a))

isNUM()
'''

#question 2
'''
from math import * 
def isPrime(n):
    ns = type(n)
        
    try:
        if ns == type(1):
            if n == 1:
                return False
            else:
                for i in range(2,int(sqrt(n)+1)):
                    if(n%i == 0):
                        return False
                return True
    except:
        print("输入有误！！！")

a = eval(input("请输入一个整数： "))
print(isPrime(a))
'''

#question3
'''
def countstr(str1):
    num_number = char_number = space_number = other_number = 0
    for char in str1:
        if char.isdigit():
            num_number += 1
        elif char.isalpha():
            char_number += 1
        elif char == ' ':
            space_number += 1
        else:
            other_number += 1
 
    print("数字个数：%d,字母个数：%d,空格个数：%d,其他字符：%d" % (num_number,char_number,space_number,other_number))
    return
countstr("4 6as f65sa1f 56as56a as %^$^%")
'''

#question4
'''
from math import *
def dayinsushu(n):
    while n>2:
        k = True
        for i in range(2,int(sqrt(n)+1)):
            if n%i == 0:
                k = False
                break
        if(k == True):
            print(n,end=" ")
        n -=1
n = eval(input())
dayinsushu(n)
'''

#question5
def fabonaci(n):
    if(n == 1 or n == 2):
        return 1
    else:
        return fabonaci(n-1)+fabonaci(n-2)
res = fabonaci(20)
print(res)































