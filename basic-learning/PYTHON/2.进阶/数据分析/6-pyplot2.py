import matplotlib.pyplot as plt
import numpy as np
import matplotlib
import matplotlib.gridspec as gridspec

'''
########################基础绘图函数####################

plt.plot()                          #绘制坐标图
plt.boxplot()                       #绘制箱型图
plt.bar(left,height,width,bottom)   #绘制一个条形图
plt.barh(width,bottom,left,height)  # 绘制一个横向条形图
plt.polar(theta, r)                 #绘制极坐标图
plt.pie(data, explode)              # 绘制饼图

plt.psd(x,NFFT=256,pad_to,Fs)       # 绘制功率谱密度图
plt.specgram(x,NFFT=256,pad_to,F)   # 绘制谱图
plt.cohere(x,y,NFFT=256,Fs)         #绘制X‐Y的相关性函数
plt.scatter(x,y)                    #绘制散点图，其中， x和y长度相同
plt.step(x,y,where)                 # 绘制步阶图
plt.hist(x,bins,normed)             #绘制直方图

plt.contour(X,Y,Z,N)                # 绘制等值图
plt.vlines()                        # 绘制垂直图
plt.stem(x,y,linefmt,markerfmt)     # 绘制柴火图
plt.plot_date()                     # 绘制数据日期
'''


# 饼图绘制
def drawPie():
    labels = 'Frog', 'Cat', 'Dog', 'Mouse'
    sizes = [15, 30, 45, 10]
    explode = (0, 0.1, 0, 0)

    plt.pie(sizes, explode=explode, labels=labels, autopct='%1.1f%%',
            shadow=False, startangle=90)
    plt.axis('equal')
    plt.show()


# 直方图绘制
def drawHist():
    np.random.seed(0)
    mu, sign = 100, 20
    a = np.random.normal(mu, sign, size=100)

    plt.hist(a, 10, density=1, histtype='stepfilled', facecolor='b', alpha=0.75)
    plt.title('Histogram')

    plt.show()


# 绘制极坐标
def drawBar():
    N = 20
    theta = np.linspace(0.0, 2 * np.pi, N, endpoint=False)  # 与极轴夹角
    radii = 10 * np.random.rand(N)  # 与原点距离
    width = np.pi / 2 * np.random.rand(N)  # 线宽

    ax = plt.subplot(111, projection='polar')
    bars = ax.bar(theta, radii, width=width, bottom=0.0)

    for r, bar in zip(radii, bars):
        bar.set_facecolor(plt.cm.viridis(r / 10.))
        bar.set_alpha(0.5)
    plt.show()

def drawSandian():
    fig,ax = plt.subplots()
    ax.plot(10*np.random.randn(100),10*np.random.randn(100),'o')
    ax.set_title('Simple Scatter')
    plt.show()

#drawSandian()
#drawBar()
N = 150
r = 2 * np.random.rand(N)
theta = 2 * np.pi * np.random.rand(N)
area = 200 * r**2
colors = theta

ax = plt.subplot(111, projection='polar')
c = ax.scatter(theta, r, c=colors, s=area, cmap='hsv', alpha=0.65)

plt.show()