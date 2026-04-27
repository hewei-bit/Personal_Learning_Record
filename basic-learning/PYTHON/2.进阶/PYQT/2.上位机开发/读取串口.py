# coding=gb18030

import serial  # 导入serial包
import time  # 导入time包

s = serial.Serial('com4', 115200, timeout=2)  # 打开串口，后面是串口配置

while True:  # 无限循环读取数据

    localtime = time.asctime(time.localtime(time.time()))  # time包里面调用本地时间的用法
    n = s.readline()  # serial包的用法 读取串口的一行数据
    data_pre = str(n)  # 把读取的数据转换成字符串
    data = data_pre[2:-3]  # 取数据的一部分放进data变量
    print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), data)  # 打印数据和时间
