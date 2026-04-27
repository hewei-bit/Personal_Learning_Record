'''
f = open('C:\\Users\\10038\\Desktop\\PythonLearning\\二级\\1.txt','a+')
ls = ['中国是一个伟大的国家']
f.seek(2)
f.write('\n')
f.writelines(ls)
f.seek(0)

for line in f :
    print(line)
#f.write('中国是个伟大的国家')
#print(f.read())
f.close()



import turtle as t
t.title('自动轨迹绘制')
t.setup(800,600,0,0)
t.pencolor("red")
t.pensize(5)
#数据读取
datals= []
f = open("data.txt","r")
for line in f:
    line = line.replace("\n","")
    datals.append(list(map(eval,line.split(","))))
f.close()
#自动绘制
for i in range(len(datals)):
    t.pencolor(datals[i][3],datals[i][4],datals[i][5])
    t.fd(datals[i][0])
    if datals[i][1]:
        t.right(datals[i][2])
    else:
        t.left(datals[i][2])


import wordcloud
c = wordcloud.WordCloud()
c.generate("hewei666")
c.to_file("hewei666.png")
'''



