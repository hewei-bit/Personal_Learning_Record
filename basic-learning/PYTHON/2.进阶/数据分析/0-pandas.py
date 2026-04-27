import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
'''
pd.Series
pd.DataFrame

'''
d = pd.Series([9, 8, 7, 6], index=['a', 'b', 'c', 'd'])

dt = {'one': pd.Series([9, 8, 7, 6], index=['a', 'b', 'c', 'd']),
      'two': pd.Series([9, 8, 7], index=['a', 'b', 'c'])
      }

f = pd.DataFrame(dt)
f.index
f.columns
f.values
f.loc['a']
f.loc['a', 'one']

'''
###################重新索引#######################

.reindex()
    参数：index,columns
         fill_value
         method
         limit
         copy   

#############索引类型的使用####################
a.index.append()          #
a.index..diff()            #计算差集
a.index..intersection()    #计算交集
a.index..union()           #计算并集
a.index..delete()          #删除元素
a.index..insert()          #


a.drop()          #删除指定行或列
'''
dl = {
    '城市': ['北京', '上海', '广州', '深圳', '沈阳'],
    '环比': ['314', '345', '345', '345', '543'],
    '同比': ['123', '5443', '443', '123', '123.2'],
    '定基': ['121.4', '123', '321.2', '213.2', '232.1']}

d = pd.DataFrame(dl, index=['c1', 'c2', 'c3', 'c4', 'c5'])

d = d.reindex(index=['c5', 'c4', 'c3', 'c2', 'c1'])
d = d.reindex(columns=['城市', '环比', '同比', '定基'])

newc = d.columns.insert(4, '新增')
fnew = d.reindex(columns=newc, fill_value=200)

nc = d.columns.delete(2)
ni = d.index.insert(5, 'c0')
nd = d.reindex(index=ni, columns=nc, method='ffill')

'''
##################数据类型运算#######################
.add()
.sub()
.mul()
.div()
'''

a = pd.DataFrame(np.arange(12).reshape(3, 4))
b = pd.DataFrame(np.arange(20).reshape(4, 5))
a + b
a * b
b.add(a, fill_value=100)
a.mul(b, fill_value=100)
"""
###################数据排序######################
#对索引的排序
.sort_index(axis = 0,ascending= True)
    axis=0      #纵轴
    axis=1      #横轴
#
.sort_values()方法在指定轴上根据数值进行排序，默认升序
Series.sort_values(axis=0, ascending=True)
DataFrame.sort_values(by, axis=0, ascending=True)


"""

b = pd.DataFrame(np.arange(20).reshape(4, 5), index=['c', 'a', 'b', 'd'])
b.sort_index(axis=0, ascending=True)
b.sort_index(axis=0, ascending=False)

b.sort_index(axis=1, ascending=False)

c = b.sort_values(2, axis=0, ascending=True)
c = b.sort_values('a', axis=1, ascending=False)

"""
##############统计分析函数################
.sum()              计算数据的总和，按0轴计算，下同
.count()            非NaN值的数量
.mean() .median()   计算数据的算术平均值、算术中位数
.var() .std()       计算数据的方差、标准差
.min() .max()       计算数据的最小值、最大值

.argmin() .argmax() 计算数据最大值、最小值所在位置的索引位置（自动索引）
.idxmin() .idxmax() 计算数据最大值、最小值所在位置的索引（自定义索引）

.describe() 针对0轴（各列）的统计汇总



###################基本统计分析####################
.cumsum() 依次给出前1、 2、 …、 n个数的和
.cumprod() 依次给出前1、 2、 …、 n个数的积
.cummax() 依次给出前1、 2、 …、 n个数的最大值
.cummin() 依次给出前1、 2、 …、 n个数的最小值



##################累计统计分析#################
.rolling(w).sum() 依次计算相邻w个元素的和
.rolling(w).mean() 依次计算相邻w个元素的算术平均值
.rolling(w).var() 依次计算相邻w个元素的方差
.rolling(w).std() 依次计算相邻w个元素的标准差
.rolling(w).min() .max() 依次计算相邻w个元素的最小值和最大值



##################相关分析函数###############
.cov() 计算协方差矩阵
.corr() 计算相关系数矩阵, Pearson、 Spearman、 Kendall等系数

"""



hprice = pd.Series([3.04,22.93,12.75,22.6,12.33],index=['2008','2009','2010','2011','2012'])
m2 = pd.Series([8.18,18.38,9.13,7.82,6.69],index=['2008','2009','2010','2011','2012'])
hprice.corr(m2)

plt.plot(list(hprice.index),list(hprice.values))
plt.plot(list(m2.index),list(m2.values))
plt.xlabel('年份',fontproperties = 'SimHei',fontsize = 10,color = 'green')
plt.ylabel('m2与房价系数',fontproperties = 'SimHei',fontsize = 10,color = 'blue')
plt.title('房价与m2相关图',fontproperties = 'SimHei',fontsize = 15,color = 'red')
plt.show()


