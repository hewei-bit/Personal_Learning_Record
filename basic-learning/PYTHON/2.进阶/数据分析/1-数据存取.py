import numpy as np

'''
##################一维二维数据存储与取出##################
np.savetxt(frame,array,fmt='%.18e',delimiter = None)
frame:文件、字符串产生器
array:存入文件的数组
fmt:写入文件的格式
delimeter:分割字符串，默认空格

np.loadtxt(frame,dtype=np.float,delimiter = None，unpack = False)
frame:文件、字符串产生器
dtype:数据类型
delimeter:分割字符串，默认空格
unpack:
'''

a = np.arange(100).reshape(5, 20)
np.savetxt('a.csv', a, fmt='%d', delimiter=',')
b = np.loadtxt('a.csv', dtype=np.int, delimiter=',')

"""
####################多维数据存储存取##############
a.tofile(frame,sep='',format='%s')
frame:文件、字符串
sep:分隔符，空则写入二进制文件

np.fromfile(frame,dtype=float,count=-1,sep='')
count:读入元素个数，-1表示读入整个文件

"""

a = np.arange(100).reshape(5, 10, 2)
a.tofile('b.dat', sep=',', format='%d')
d = np.fromfile('b.dat', dtype=int, count=-1, sep=',').reshape(5, 10, 2)

'''
################快捷方式#################
np.save(fname,array)
np.savez(fname,array)
np.load(fname)
'''
a = np.arange(100).reshape(5, 10, 2)
np.save('a.npy',a)
b = np.load('a.npy')











