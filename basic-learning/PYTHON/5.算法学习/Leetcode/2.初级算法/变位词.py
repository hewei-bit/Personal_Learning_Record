
"""
变位词算法
"""
#算法1
def anagramSolution1(s1,s2):
    alist = list(s2)
    pos1 = 0
    stillOK = True
    while pos1<len(s1) and stillOK:
        pos2 = 0
        found = False
        while pos2 < len(alist) and not found:
            if s1[pos1] == s2[pos2]:
                found = True
            else:
                pos2 = pos2 + 1
        if found:
            alist[pos2] = None
        else:
            stillOK = False
        pos1 = pos1 + 1
    return stillOK

print(anagramSolution1('abcd','bcda'))

#算法2
def anagramSolution2(s1,s2):
    alist1 = list(s1)
    alist2 = list(s2)

    alist1.sort()
    alist2.sort()

    pos = 0
    stillOK = True
    while pos<len(s1) and stillOK:
        if alist1[pos] == alist2[pos]:
            pos = pos +1
        else:
            stillOK = False
    return stillOK
print(anagramSolution2('abcd','bcda'))

