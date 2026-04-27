import requests
import os

url = "https://images.pexels.com/photos/2607731/pexels-photo-2607731.jpeg?cs=srgb&dl=photo-of-street-surrounded-by-buildings-2607731.jpg&fm=jpg"
root = "D:\练习+项目\PythonLearning\进阶\网络爬虫//"
path = root + 'adcd.jpg'  #url.split('/')[-1]
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url, timeout=30)
        with open(path, 'wb') as f:
            f.write(r.content)
            f.close()
            print("文件保存成功")
    else:
        print("文件已存在")
except:
    print("爬取异常")




