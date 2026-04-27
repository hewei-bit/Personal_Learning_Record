# P(Y|YTH|YTHO)?N    'PN',"PYTHN","PYH","PYTHON"
# PYTHON+            'PYTHON','PYTHONNNN'
# PY[TH]ON           'PYTHON','PYTON','PYHON'
# PY[^TH]ON          'PYON','PYaON','PYbON','PYcON'
# PY{:3}N            'PYN','PYYON','PYYYN'

# ^[a-zA-Z]+$        由26个字母组成的字符串
# ^[a-zA-Z0-9]+$     由26个字母和数字组成的字符串
# ^-?\d+$            整数形式的字符串
# [0-9]*[1-9][0-9]*$ 正整数形式的字符串
# [1-9]\d{5}         中国境内邮政编码
# [\u4e00-\u9fa5]    匹配中文字符

# 0-99       [1-9]?\d
# 100-199    1\d{2}
# 200-249    2[0-4]\d
# 250-255    25[0-5]

# IP地址的正则表达式
# (([1-9?\d|1\d{2}|2[0-4]\d|25[0-5]]).){3}([1-9?\d|1\d{2}|2[0-4]\d|25[0-5])

'''
import re
re.search()
re.match()
re.findall()
re.split()
re.finditer()
re.sub()
等价用法
regex == re.compile()

re.compile()
'''
import re
match = re.search(r'[1-9]\d{5}','BIT 100081')
print(match.string)
print(match.re)
print(match.pos)
print(match.endpos)
print(match.group(0))
print(match.start)
print(match.end)
print(match.span())
match = re.match(r'[1-9]\d{5}','100081 BIT')
print(match.group(0))
for m in re.finditer(r'[1-9]\d{5}','BIT100081 HUANGPU510700'):
    if m:
        print(m.group(0))
print(re.findall(r'[1-9]\d{5}','BIT100081 HUANGPU510700'))
print(re.split(r'[1-9]\d{5}','BIT100081 HUANGPU510700'))
print(re.sub(r'[1-9]\d{5}','zip','BIT100081 HUANGPU510700'))