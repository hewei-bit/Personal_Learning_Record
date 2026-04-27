class Rectangle:
    def __init__(self,width = 0,hight = 0):
        self.width = width
        self.hight = hight
    def __setattr__(self, name, value):
        if name == "square":
            self.width = value
            self.hight = value
        else:
            super().__setattr__(name,value)
    def getArea(self):
        return self.width * self.hight

class MyDescription:
    def __get__(self, instance, owner):
        print("getting",self,instance,owner)
    def __set__(self, instance, value):
        print("setting",self,instance,value)
    def __delete__(self, instance):
        print("deleting",instance)

class Test:
    x = MyDescription()


class MyProperty:
    def __init__(self,fget = None,fset = None,fdel = None):
        self.fget = fget
        self.fset = fset
        self.fdel = fdel
    def __get__(self, instance, owner):
        return self.fget(instance)
    def __set__(self, instance, value):
        self.fset(instance,value)
    def __delete__(self, instance):
        self.fdel(instance)

class CountList:
    def __init__(self, * arg):
        self.value = [x for x in arg]
        self.count = {}.fromkeys(range(len(self.value)),0)




