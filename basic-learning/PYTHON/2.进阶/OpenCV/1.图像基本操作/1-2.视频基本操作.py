import cv2
import matplotlib.pyplot as plt
import numpy as np

# 打开摄像头，0代表的是设备id，如果有多个摄像头，可以设置其他数值
vc = cv2.VideoCapture('1.mp4')
# 检查是否正确打开
if vc.isOpened():
    open, frame = vc.read()
else:
    open = False

while open:
    # 读取摄像头,它能返回两个参数，第一个参数是bool型的ret，
    # 其值为True或False，代表有没有读到图片；
    # 第二个参数是frame，是当前截取一帧的图片
    ret, frame = vc.read()
    if frame is None:
        break
    if ret == True:
        # 翻转 0:上下颠倒 大于0水平颠倒   小于180旋转
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        cv2.imshow('result', gray)
        # 这个语句： if cv.waitKey(10) & 0xFF == ord('q')，
        # 和视频中的 c = cv.waitKey(40)  if c == 27 含义如下：
        # 1.后来我发现他关闭是esc键关闭，就是只有语句：c == 27
        # 时是用esc关闭的,点窗口的×是不能关闭的
        # 2. 当时我不知道视频是esc关闭窗口，
        # 就百度了一下，用了我笔记的方法，按q关闭
        if cv2.waitKey(10) & 0xFF == 27:
            break
vc.release()
cv2.destroyAllWindows()
