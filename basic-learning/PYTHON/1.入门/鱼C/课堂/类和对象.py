# class Hewei:
#     def Setname (self,name):
#         self.name = name
#     def kick(self):
#         print("\n我叫%s，谁在踢我？？？" % self.name)
# a = Hewei()
# a.Setname("Hewei")
# a.kick()
#
# class Xiaohe(Hewei):
#     pass
# b = Xiaohe()
# b.Setname("xiaohe")
# b.kick()

import random as r

class Fish:
    def __init__(self):
        self.x = r.randint(0,10)
        self.y = r.randint(0,10)
    def move(self):
        self.x -= 1
        print("我的位置：",self.x,self.y)

class GoldFish(Fish):
    pass
class Carp(Fish):
    pass
class Salmon(Fish):
    pass

class Shark(Fish):
    def __init__(self):
        super().__init__(self)
        self.hungry = True
    def eat(self):
        if self.hungry:
            print("我要吃吃吃！！！！")
            self.hungry = False
        else:
            print("吃不起了")
