Python 3.7.1 (v3.7.1:260ec2c36a, Oct 20 2018, 14:57:15) [MSC v.1915 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> a = input('两人的关系是否已经达到了朋友之上，恋人未满')
if a == '不是':
    print('进度条不够,再等等')
elif a == '是':
    b = input('你是不是想和对方进一步发展')
    if b == '不是':
        print('还是做朋友吧')
    elif b =='是':
        c = input('对方是不是想有进一步的发展？')
        if c == '不是':
            print('恭喜获得“好人卡”。')
        elif c == '是':
            print('恭喜你们有情人终成眷属！')
