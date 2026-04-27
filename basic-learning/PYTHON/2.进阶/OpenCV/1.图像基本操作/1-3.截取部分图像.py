import cv2
import matplotlib.pyplot as plt
import numpy as np

img = cv2.imread('car.jpg')
# 截取部分图像
car = img[0:100, 0:100]
# 颜色通道提取
blue, green, red = cv2.split(img)

cv2.imshow('car', car)
cv2.waitKey(0)
