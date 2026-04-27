#Q1
'''
words = open("1.txt","r").read()
words = " ".join(words)
words = words.split()
print(words)

counts = {}
for word in words:
    counts[word] = counts.get(word,0)+1
items = list(counts.items())
items.sort(key=lambda x:x[1],reverse = True)
for i in range(3):
    word,count = items[i]
    print("{0:<5}{1:>5}".format(word,count))
'''

#Q2
import random
random.seed(0x1010)

s = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM"
ls = []
Firstpsw =""

while len(ls)<8:
    pwd = ""
    for i in range(10):
        pwd += s[random.randint(0,len(s)-1)]
        if pwd[0] in Firstpsw:
            continue
        else:
            ls.append(pwd)
            Firstpsw += pwd[0]
print(ls)
