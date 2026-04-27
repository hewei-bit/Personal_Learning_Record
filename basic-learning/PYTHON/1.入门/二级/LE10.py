'''
import random as r

def printIntro():
    print("模拟两个选手进行N场比赛")
    print("需要两位选手能力值")

def getInputs():
    A = eval(input("请输入A的能力"))
    B = eval(input("请输入B的能力"))
    n = eval(input("请输入模拟的场次"))
    return n,A,B

def simNgames(n,proA,proB):
    winsA,winsB = 0,0
    for i in range(n):
        scoreA,scoreB = simOnegame(proA,proB)
        if scoreA > scoreB:
            winsA += 1
        else:
            winsB += 1
    return winsA,winsB


def simOnegame(proA,proB):
    scoreA,scoreB = 0,0
    serving = "A"
    while not gameover(scoreA,scoreB):
        if serving == "A":
            if r.random() < proA:
                scoreA+=1
            else:
                serving = "B"
        else:
            if r.random() < proB:
                scoreB+=1
            else:
                serving = "A"
    return scoreA,scoreB

def gameover(scoreA,scoreB):
    return scoreA == 15 or scoreB==15


def printSummary(winsA,winsB):
    n = winsA+winsB
    print("模拟开始一共进行了{}场比赛".format(n))
    print("选手A获胜{}场，占比{:0.1%}".format(winsA,winsA/n))
    print("选手B获胜{}场，占比{:0.1%}".format(winsB, winsB/n))


def main():
    printIntro()
    proA,proB,n = getInputs()
    winsA,winsB = simNgames(proA,proB,n)
    printSummary(winsA,winsB)


main()
'''