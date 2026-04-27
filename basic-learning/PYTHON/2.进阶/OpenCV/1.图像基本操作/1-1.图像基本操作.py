import cv2
import matplotlib.pyplot as plt
import numpy as np

# 1.cv2.imread(const String& filename,int flags);  读取图片
#     第一个参数是图片地址：“\” "\\" 和"/" "//"   
#     第二个参数是图片读取方式：默认正常读取，如果为0 则为灰度图 
#     2时也是灰色的，测试了其他是彩色的
#
img = cv2.imread('car.jpg')
# 读取灰度图
img2 = cv2.imread('car.jpg', cv2.IMREAD_GRAYSCALE)

# 3.cv2.imshow(const string& winname, InputArray mat) 显示图片窗口
#     第一个参数：窗口名称。如果上面有NamedWindow（）函数，这个名称要与它一样，
#     不然会出现两个窗口，一个是NamedWindow的空白窗口，一个是imshow的图片窗口。
#     第二个参数：要显示的图片。
#     如果窗口是用CV_WINDOW_AUTOSIZE（默认值）标志创建的，那么显示图像原始大小。
#     否则，将图像进行缩放以适合窗口。而imshow 函数缩放图像，取决于图像的深度（目前还不懂啥是深度，回头再补充）
#
cv2.imshow('image', img)
cv2.imshow('image2', img2)

# 4.waitKey(K) 窗口显示时间，单位：毫秒
#   k=0: （也可以是小于0的数值）一直显示，键盘上按下一个数字键即会消失
#   k>0:显示多少毫秒
cv2.waitKey(0)

# 5.删除建立的全部窗口，释放资源
cv2.destroyAllWindows()

# 6.保存
cv2.imwrite('mycar.png', img)





