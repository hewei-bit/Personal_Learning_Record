import serial #串口包
import time
import re
import pymysql

log = 0 #设置一个log记录，初始值0，用于记录数据次数

s = serial.Serial("com4",115200,timeout=3)
db = pymysql.connect(
    host = 'localhost',
    port = 3306,
    user = 'root',
    password = 'root',
    db = "python",
    charset = "utf8"
)
cursor = db.cursor()

while True:
    #每次接收，log+1
    log += 1

    localtime = time.asctime(time.localtime(time.time()))#调用本地时间

    data_pre = s.readline()

    #初步处理数据

    data = str(data_pre)[2:-3] #把最先用n读取的数据强制转换成字符串，去掉头尾
    #使用正则表达式截取相关内容
    device_name = "".join(re.findall(r"n(.+?)t",data))
    temp_value = "".join(re.findall(r"t(.+?)h",data))
    humi_value = "".join(re.findall(r"h(.+?)l",data))
    light_value = "".join(re.findall(r"l(.+?)a",data))
    ammonia_value = "".join(re.findall(r"a(.+?)e",data))


    #规定接收时间
    local_time = time.strftime("%Y-%m-%d %H:%M:%S",time.localtime())

    if data == 0000:
        d_name = 'none'
        td = 'unknow'
        hd = 'unknow'
        ld = 'unknow'
        ad = 'unknow'
        print("the monitor system cant recevice data from hardware...Please chick the device running status")

        #SQL语言，把数据插入数据库
        sql = "INSERT INTO moniter_MonitorData02DB(log_id,d_name,rec_time,tem_v,rh_v,light_v,ag_v)VALUS('%d','%s','%s','%d','%d','%f','%f')" % (
            log,d_name,local_time,td,hd,ld,ad
        )
        cursor.execute(sql)#执行上述数据库语言
        db.commit()#提交命令
    else:
        d_name = device_name
        td = int(temp_value)
        hd = int(humi_value)
        ld = float(light_value)
        ad = float(ammonia_value)
        print("NO.",log,"rectime is:",local_time,"value is :",d_name,td,hd,ld,ad)

        # SQL语言，把数据插入数据库
        sql = "INSERT INTO moniter_MonitorData02DB(log_id,d_name,rec_time,tem_v,rh_v,light_v,ag_v)VALUS('%d','%s','%s','%d','%d','%f','%f')" % (
            log, d_name, local_time, td, hd, ld, ad
        )
        cursor.execute(sql)  # 执行上述数据库语言
        db.commit()#提交命令

cursor.close()#结束数据库标记
db.close()#关闭数据库连接





