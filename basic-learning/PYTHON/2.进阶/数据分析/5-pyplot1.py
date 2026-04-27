import matplotlib.pyplot as plt
import numpy as np
import matplotlib
import  matplotlib.gridspec as gridspec

'''
####################plot()函数介绍#########################
plt.plot(x,y,format_string,**kwargs)
format_string:
    颜色字符：'b'、'g'、'c'、'#008000'(RGB)、'0.8'(灰度)
    风格字符：'-'、'--'、'-.'、':'、''(空)
    标记字符：'.'、','、'o'、'v'、'^'、'>'、'<'、'1'、'2'、'3'、'4'
            :'s'、'p'、...
**kwargs:
'''
'''
##############中文显示###################
rcParams:
    'font.family'   #用于显示中文字体
    'font.style'    #字体风格
    'font.size'     #字体大小
    
# matplotlib.rcParams['font.family'] = 'SimHei'
# matplotlib.rcParams['font.style'] = 'normal'
# matplotlib.rcParams['font.size'] = '20'
'''
'''
####################文本显示函数##########################
plt.xlabel()
plt.ylabel()
plt.title()
plt.text()
plt.annotate(s, xy=arrow_crd, xytext=text_crd, arrowprops=dict)
'''
"""
##########################pyplot子绘图区域##############################
plt.subplot2grid(GridSpec, CurSpec, colspan=1, rowspan=1)
plt.subplot2grid((3, 3), (0, 0), cosplan=3)
...
plt.subplot2grid((3, 3), (1, 0), colspan=2)
...
plt.subplot2grid((3, 3), (1, 2), rowspan=2)
...
plt.subplot2grid((3, 3), (2, 0))
...
plt.subplot2grid((3, 3), (2, 1))
...

gs = gridspec.GridSpec(3,3)
ax1 = plt.subplot(gs[0,:])
ax2 = plt.subplot(gs[1,:-1])
ax3 = plt.subplot(gs[1:,-1])
ax4 = plt.subplot(gs[2,0])
ax5 = plt.subplot(gs[2,1])

"""



a = np.arange(0.0, 5.0, 0.02)
# plt.plot(a,a*1.5,'go-',a,a*2.5,'rx',a,a*3.5,'*',a,a*4.5,'b-.')
plt.title("正弦波实例 $y=cos(2\pi x)$", fontproperties='SimHei', fontsize=25)
plt.ylabel("纵轴：振幅", fontproperties='SimHei', fontsize=20, color='green')
plt.xlabel("横轴：时间", fontproperties='SimHei', fontsize=20)
plt.plot(a, np.cos(2 * np.pi * a), 'r--')
# plt.text(2, 1, r'$\mu=100$', fontsize=15)
plt.annotate(r'$\mu=100$', xy=(2, 1), xytext=(3, 1.5),
             arrowprops=dict(facecolor='black', shrink=0.1, width=2))

plt.axis([-1, 6, -2, 2])
plt.grid(True)
plt.show()
