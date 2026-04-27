x = input('请输入第一个数字\n')  # type: str
y = input('请输入第二个数字\n')
z = input('请输入第三个数字\n')
small = x if(x<y and x<z)else(y if y<z else z)
print('最小值为'+ small)
