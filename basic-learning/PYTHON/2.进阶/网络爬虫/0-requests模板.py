import requests
import time

def getHTMLText(url):
    try:
        r = requests.get(url,timeout = 30)
        r.raise_for_status() #如果状态不是200，表示状态异常
        #r.encoding = r.apparent_encoding
        r.text
        return True
    except:
        return False #"爬取异常"

if __name__ == "__main__":
    url = "http://www.baidu.com"
    begin = time.time()
    for i in range(100):
        if getHTMLText(url):
            print("正在进行第%d次爬取"%i)
        else:
            print("ERROR")
    end = time.time()
    print("用时：{:.2f}秒".format(end-begin))


'''
requests.request()
requests.get()
requests.put()
requests.patch()
requests.head()
requests.delete()
requests.options()
requests.post()
'''