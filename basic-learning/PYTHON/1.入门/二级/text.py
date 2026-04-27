#s = input("输入(加解密前)：")


names = ["命运", "寻梦"]
for name in names:
    fi = open(name+"-网络版.txt", "r", encoding="utf-8")
    fo = open(name+"-字符统计.txt", "w", encoding="utf-8")
    txt = fi.read()
    d = {}
    for c in txt:
        d[c] = d.get(c, 0) + 1
    del d['\n']
    ls = list(d.items())
    ls.sort(key=lambda x:x[1], reverse=True)
    for i in range(100):
        ls[i] = "{}:{}".format(ls[i][0], ls[i][1])
    fo.write(",".join(ls[:100]))
    fi.close()
    fo.close()











"""
s=input("解密前")
new= []
for i in s:
    new.append(chr((ord(i)+10451)%20902+ord(i)))
new1 = new
print(new1)
new2 = [str(i) for i in new1]
print(new2)
new3 = "".join(new2)

print(new3)

s = input("")
d ={}
for c in [0x4e00,0x9fa5]:
    for i in range(20902):
        d[chr(i+c)] = chr((i+10451) % 20902 + c)
#print("输出(加解密后)：" + "".join([d.get(c,c) for c in s]))
print("".join([d.get(c,c) for c in s]))



fi = open("侠客行-网络版.txt","r",encoding="utf-8")
fo = open("侠客行-字符统计.txt","w",encoding="utf-8")
ls = []
d = {}
e = {}

txt = fi.read()
for c in txt:
    if 0x4e00 <= ord(c) <= 0x9fa5:
        d[c] = d.get(c,0)+1

new_sys2 = sorted(d.items(),  key=lambda d: d[1], reverse=True)
print(new_sys2)
new_sys3 = sorted(d.items(),  key=lambda d: d[0], reverse=False)
print(new_sys3)

for key in d:
    ls.append("{0}(0x{1:x}):{2}".format(key,ord(key),d[key]))
lt = ",".join(ls)
fo.write(lt)
fo.close()
fi.close()



import jieba
fi = open("射雕英雄传-网络版.txt", "r", encoding='utf-8')
txt = fi.read()
fi.close()
ls = jieba.lcut(txt)
d = {}
for w in ls:
    d[w] = d.get(w, 0) + 1
for c in "\n，“”。？！：；":
    del d[c]
lt = []
for i in range(8):
    mx = 0
    mxj = 0
    for j in d:
        if d[j]>mx:
            mx = d[j]
            mxj = j
    lt.append(mxj)
    del d[mxj]
print(",".join(lt))

import random
random.seed(0x1010)
s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*"
ls = []
excludes = ""
while len(ls) < 10:
    pwd = ""
    for i in range(10):
        pwd += s[random.randint(0, len(s)-1)]
    if pwd[0] in excludes:
        continue
    else:
        ls.append(pwd)
        excludes += pwd[0]

# 直接打印
print("\n".join(ls))

# 或写入文件
fo = open("随机密码.txt", "w")
fo.write("\n".join(ls))
fo.close()"""