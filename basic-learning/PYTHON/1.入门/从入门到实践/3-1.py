bicycles = ['trek','cannondale','redline','specialized']
print(bicycles)
print(bicycles[0])
print(bicycles[0].title())
print(bicycles[-1])
message = "I would like to own a "+bicycles[-1].title()+" today"
print(message)
bicycles.append('BMW')#在最后一位插入元素
print(bicycles)
bicycles.insert(0,'audi')#在指定位置插入元素
print(bicycles)
del bicycles[0]#删除指定元素
print(bicycles)
del bicycles[-1]
print(bicycles)
popped_bicycles = bicycles.pop()#删除最后一个
print(popped_bicycles)
print(bicycles)
bicycles.append('BMW')
bicycles.append('specialized')
print(bicycles)
bicycles.remove('BMW')#根据值删除元素
print(bicycles)
bicycles.append('bmw')
bicycles.sort()
print(bicycles)
bicycles.sort(reverse=True)
print(bicycles)
