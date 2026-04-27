import numpy as np
'''
#################np.random随机数函数#################
np.random.rand()    #[0,1)均匀分布
np.random.randn()   #标准正态分布
np.random.randint() #[low,high)
np.random.seed()
'''
a = np.random.rand(3,4,5)
np.random.randn()
b = np.random.randint(100,200,(3,4))
np.random.seed()
'''
#################np.random随机数函数#################
np.random.shuffle(a)    #a的第一轴进行随机排列，改变数组
np.random.permutation(a) #a的第一轴进行随机排列,不改变原数组
np.random.choice(a[,size=,replace=,p]) #p概率
'''
np.random.shuffle(a)    #a的第一轴进行随机排列，改变数组
np.random.permutation(a) #a的第一轴进行随机排列,不改变原数组
np.random.choice(b,(3,2),replace=False,p= b/np.sum(b)) #p概率

'''
#################np.random随机数函数#################
np.random.shuffle(a)    #a的第一轴进行随机排列，改变数组
np.random.permutation(a) #a的第一轴进行随机排列,不改变原数组
np.random.choice(a[,size=,replace=,p]) #p概率
'''
a = np.random.uniform(0,10,(3,4))    #均匀分布
b = np.random.normal(10,5,(3,4))    #正态分布，loc均值，scale标准差
c = np.random.poisson(lam,size)         #泊松分布，










