def MyGen():
    print("生成器被执行")
    yield 1
    yield 2

def libs():
    a = 0
    b = 1
    while (1):
        a,b = b,a+b
        yield a



