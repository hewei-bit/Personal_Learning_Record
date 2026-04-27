# 备注 代码根据自己数据库及存储格式修改

import serial
import pymysql  # 导入pymysql包

# import easygui
log = 0
ser = serial.Serial()

ser.baudrate = 9600  # 设置波特率（这里使用的是stc89c52）
ser.port = 'COM12'  # 端口是COM3
print(ser)
ser.open()  # 打开串口
print(ser.is_open)  # 检验串口是否打开
db = pymysql.connect("localhost", "root", "", "test")  # 打开数据库，配置数据库

cursor = db.cursor()  # 数据库操作
cursor.execute("DROP TABLE IF EXISTS Monitor_Data")  # 如果存在表则重新创建

creatTab = """CREATE TABLE Monitor_Data( # 创建表
    LOG_ID INT NOT NULL,
    temp CHAR(50),
    temp_value CHAR(50),
    guang CHAR(50),
    guang_value CHAR(50)
     )"""

cursor.execute(creatTab)  # 执行数据库语句

while (1):
    # Yes_or_No = easygui.buttonbox("是否良品?", choices=[ 'Yes', 'No', '退出' ])  # 提供简易UI
    # if Yes_or_No == '退出': break
    # if Yes_or_No == 'Yes':
    #     demo = b"2"  # 传入2的ASCII码 这里用b+str强制转换
    # else:
    #     demo = b"1"  # 传入1的ASCII码 这里用b+str强制转换

    # ser.write()
    s = ser.readline()
    log += 1  # 传输次数记录+1
    data_pre = str(s)  # 强制用字符串格式

    data = data_pre[2:-2]  # 取部分数据
    did = data_pre[2:6]  # 分类取有效数据
    did1 = data_pre[8:12]  # 分类取有效数据
    did2 = data_pre[13: 18]  # 分类取有效数据
    did3 = data_pre[20:25]  # 分类取有效数据

    print(log, did, did1, did2, did3)
    sql = "INSERT INTO Monitor_Data(LOG_ID,temp,temp_value,guang,guang_value)VALUES('%d','%s','%s','%s','%s')" % (
        log, did, did1, did2, did3)  # 存入数据库
    cursor.execute(sql)  # 执行数据库语句