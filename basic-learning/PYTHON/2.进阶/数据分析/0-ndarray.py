import numpy as np

'''
####################属性####################
a.ndim  # 秩
a.shape  # 对象尺寸，矩阵m行n列
a.size  # 元素个数  m*n
a.dtype  # 元素类型 ('int32   ')
a.itemsize  # 每个元素大小

'''

a = np.array([0, 1, 2, 3])
b = np.array([1, 2, 3], dtype=np.int32)

'''
##################创建ndarray数组###################
a = np.arange(n)        #从0-1
a = np.ones(shape)      #全1
a = np.zeros(shape)     #全0
a = np.full(shape,val)  #全val
a = np.eye(n)           #创建n*n正方形矩阵

np.zeros_like(a)
np.ones_linke(a)
np.full_like(a,val)

np.linspace()
np.concatentate()

'''
c = np.arange(6)
d = np.ones((3, 6))
e = np.eye(5, dtype=np.int)
f = np.zeros((3, 6), dtype=np.int32)
g = np.full((2, 3), 4)

np.zeros_like(a)

g = np.linspace(1, 10, 5)
h = np.concatentate((a,b))

'''
###############ndarray数组的维度变换###############
a.reshape(shape)    #不改变数组
a.resize(shape)     #改变数组
a.swapaxes(ax1,ax2) #n个维度中两个进行调换
a.flatten()         #降维   

new_a = a.astype(new_type) #创建新数组
'''

'''
################ndarray数组向列表转换############
ls = a.tolist（）
'''

'''
###############多维数组的索引和切片##############
a = np.arange(24).reshape(2,3,4)
a[0,0,0]
a[:,1,-3]
a[:,1:3,:]
a[:,:,::2]
b = a.tolist()
b[0][0][0]
'''

'''
######################一元函数###################
#元素级运算
np.abs() np.fabs()
np.sqrt()
np.square()
np.log2() np.log() np.log10()
np.ceil()       #不超过元素的整数值
np.floor()

np.rint()       #四舍五入
np.modf()       #小数整数分离成两个数字
np.cos() np.cosh()
np.sin() np.sinh()
np.tan() np.tanh()
np.exp()
np.sign()       #元素符号值

######################二元函数###################
+-*/**
np.maximum(f,g) np.fmax(f,g)
np.minimum()    np.fmin()
np.mod(x,y)
np.copysign()
> < >= <= == !=
'''








