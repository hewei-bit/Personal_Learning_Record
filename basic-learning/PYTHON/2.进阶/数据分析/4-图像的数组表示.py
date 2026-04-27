from PIL import Image
import numpy as np

'''
b = 255 - a
im = Image.fromarray(b.astype('uint8'))
im.save("D:\练习+项目\PythonLearning\PythonLearning\进阶\数据分析\myy1.jpg")

c = (100/255)*a +150
im = Image.fromarray(c.astype('uint8'))
im.save("D:\练习+项目\PythonLearning\PythonLearning\进阶\数据分析\myy2.jpg")

d = 255*(a/255)**2
im = Image.fromarray(d.astype('uint8'))
im.save("D:\练习+项目\PythonLearning\PythonLearning\进阶\数据分析\myy3.jpg")
'''

a = np.asarray(Image.open("D:\练习+项目\PythonLearning\PythonLearning\进阶\数据分析\myy.jpg").convert('L')).astype('float')
# print(a.shape, a.dtype)
# 预设深度值，取值范围0~100
depth = 50.
grad = np.gradient(a)
grad_x, grad_y = grad
grad_x = grad_x * depth / 100.
grad_y = grad_y * depth / 100.

vec_el = np.pi / 2.2
vec_az = np.pi / 4.
dx = np.cos(vec_el) * np.cos(vec_az)
dy = np.cos(vec_el) * np.sin(vec_az)
dz = np.sin(vec_el)

A = np.sqrt(grad_x ** 2 + grad_y ** 2 + 1.)
uni_x = grad_x / A
uni_y = grad_y / A
uni_z = 1.

b = 255 * (dx * uni_x + dy * uni_y + dz * uni_z)
b = b.clip(0,255)

im = Image.fromarray(b.astype('uint8'))
im.save('D:\练习+项目\PythonLearning\PythonLearning\进阶\数据分析\myy5.jpg')