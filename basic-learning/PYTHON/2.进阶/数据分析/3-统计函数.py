import numpy as np
'''
###################统计函数######################
np.sum(a,axis=None)
np.mean(a,axis=None)
np.average(a,axis=None,weights=None)
np.std(a,axis=None)                 #标准差
np.var(a,axis=None)                 #方差

np.max(a)
np.min(a)
np.argmax(a)
np.argmin(a)            #一维下标
np.unravel_index(np.argmax(a),a.shape)      #一维下标转多维下标
np.ptp(a)               #最大值和最小值的差
np.median(a)

#################梯度函数##################
np.gradient(f)
'''
a = np.arange(24).reshape((3,8))
b = np.sum(a,axis=None)
c = np.mean(a,axis=None)
d = np.average(a,axis=0,weights=[10,5,1])
e = np.std(a,axis=None)
f = np.var(a,axis=None)


