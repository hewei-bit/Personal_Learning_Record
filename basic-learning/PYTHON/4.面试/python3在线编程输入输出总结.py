"""
A+B
类型一：多组输入，组数未知
类型二：多组输入，组数t已知
类型三：多组输入，有终止条件
类型四：多组输入，有终止条件，每行个数已知
类别五：多组输入，有组数t，求一系列和
类型六：多组输入，每行个数已知，一系列和
类型六：多组输入，一系列和
字符串排序
类型一：一行字符串个数n，一行字符串
类型二：多行字符串，空格分隔
类型三：多行字符串，逗号分隔
"""
# A+B
# 类型一：多组输入，组数未知
# 一行只有两个数
while True:
    try:
        a, b = map(int, input().strip().split())
        print(a + b)
    except EOFError:
        break
# 扩展：一行多个数
while True:
    try:
        l = list(map(int, input().strip().split()))
        print(sum(l))
    except EOFError:
        break

# 类型二：多组输入，组数t已知
# 一行两个数
t = int(input())
for i in range(t):
    a, b = map(int, input().strip().split())
# 扩展
t = int(input())
for i in range(t):
    l = list(map(int, input().strip().split()))
    print(sum(l))

# 类型三：多组输入，有终止条件
while True:
    a, b = map(int, input().strip().split())
    if a == 0 and b == 0:
        break
    print(a + b)

# 类型四：多组输入，有终止条件，每行个数已知
while True:
    l = list(map(int, input().strip().split()))
    if len(l) == 1 and l[0] == 0:
        break
    print(sum(l[1:]))

# 类别五：多组输入，有组数t，求一系列和
n = int(input())
for i in range(n):
    l = list(map(int, input().strip().split()))
    print(sum(l[1:]))

# 类型六：多组输入，每行个数已知，一系列和
while True:
    try:
        l = list(map(int, input().strip().split()))
        print(sum(l[1:]))
    except EOFError:
        break

# 类型七：多组输入，一系列和
while True:
    try:
        l = list(map(int, input().strip().split()))
        print(sum(l))
    except EOFError:
        break

# 字符串排序
# 类型一：一行字符串个数n，一行字符串
while True:
    try:
        n = int(input())
        mystr = list(map(str, input().strip().split()))
        mystr.sort()
        print(' '.join(mystr))
    except EOFError:
        break

# 类型二：多行字符串，空格分隔
while True:
    try:
        mystr = input().strip().split()
        mystr.sort()
        print(' '.join(mystr))
    except:
        break

# 类型三：多行字符串，逗号分隔
while True:
    try:
        mystr = input().strip().split(',')
        mystr.sort()
        print(','.join(mystr))
    except:
        break
