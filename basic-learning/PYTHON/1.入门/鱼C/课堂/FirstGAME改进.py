import random
secret = random.randint(1,10)
print('----------白球王的成才之路----------')
temp = input ("猜猜我现在心里想的是什么数字：")
guess = int(temp)
while guess != secret:
    temp = input ("猜错啦请重新输入：")
    guess = int(temp)
    if guess == secret:
        print ("你是我肚子里的蛔虫吗")
        print("你猜中了也没有奖励哈哈")
    else:
        if guess > secret:
            print("你猜的数字大了呀")
        else:
            print("你猜的数字太小了喔")
print ("游戏结束啦，哈哈哈哈")
    
