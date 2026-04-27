import easygui as g
import  sys
g.msgbox("嗨，欢迎进入第一个界面小游戏！！！")
msg = "请问你叫什么名字"
title = "问卷调查"
choices = ['何蔚','小何蔚','小何','小蔚']
choice = g.choicebox(msg,title,choices)

g.msgbox("你的选择是："+str(choice),"结果")
msg = "你希望重新开始小游戏吗"
title = "请选择"
if g.ccbox(msg,title):
    pass
else:
    sys.exit(0)