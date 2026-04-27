import serial
portx="COM5"
bps=9600
timex=5
#串口执行到这已经打开 再用open命令会报错
ser = serial.Serial(portx, int(bps), timeout=1, parity=serial.PARITY_NONE,stopbits=1)
if (ser.isOpen()):
    print("open success")
     # 向端口些数据 字符串必须译码
    ser.write("hello".encode())
    while (True):
        line = ser.readline()
        if(line):
            print(line)
            line=0
else:
    print("open failed")
    ser.close()#关闭端口

