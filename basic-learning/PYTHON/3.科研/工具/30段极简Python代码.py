#1重复元素判定
def all_unique(lst):
    return len(lst) == len(set(lst))
x = [1,1,2,3,4,2,3,4,5]
y = [1,2,3,4,5]
all_unique(x)#False
all_unique(y)#True

#2字符元素判定
from collections import Counter
def anagram(first,second):
    return Counter(first) == Counter(second)
anagram("abc3","3cba") # True

#3内存占用
import sys
variable = 30
print(sys.getsizeof(variable))#24

#4字节占用
def byte_size(string):
    return(len(string.encode('utf-8')))
byte_size("xiaolian")

#5打印 N 次字符串
n = int(input())
string = input()
print(string * n)

#6.大写第一个字母
s = input()
print(s.title())

#7.分块
from math import ceil
from math import ceil
def chunk(lst, size):
    return list(
        map(lambda x: lst[x * size:x * size + size],
            list(range(0, ceil(len(lst) / size)))))
chunk([1,2,3,4,5],2)# [[1,2],[3,4],5]

#8. 压缩
def compact(lst):
    return list(filter(bool, lst))
compact([0, 1, False, 2, '', 3, 'a', 's', 34])
# [ 1, 2, 3, 'a', 's', 34 ]

#9. 解包
array = [['a', 'b'], ['c', 'd'], ['e', 'f']]
transposed = zip(*array)
print(transposed)
# [('a', 'c', 'e'), ('b', 'd', 'f')]


#10. 链式对比
a = 3
print( 2 < a < 8) # True
print(1 == a < 2) # False

#11. 逗号连接
hobbies = ["basketball", "football", "swimming"]

print("My hobbies are: " + ", ".join(hobbies))
# My hobbies are: basketball, football, swimming

#12. 元音统计
import re
def count_vowels(str):
    return len(re.findall(r'[aeiou]', str, re.IGNORECASE))

count_vowels('foobar') # 3
count_vowels('gym') # 0

#13. 首字母小写
def decapitalize(string):
    return str[:1].lower() + str[1:]

decapitalize('FooBar') # 'fooBar'

#14. 展开列表
def spread(arg):
    ret = []
    for i in arg:
        if isinstance(i, list):
            ret.extend(i)
        else:
            ret.append(i)
    return ret

def deep_flatten(lst):
    result = []
    result.extend(
        spread(list(map(lambda x: deep_flatten(x) if type(x) == list else x, lst))))
    return result


deep_flatten([1, [2], [[3], 4], 5]) # [1,2,3,4,5]