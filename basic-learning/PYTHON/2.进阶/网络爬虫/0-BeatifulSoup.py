'''

#http://python123.io/ws/demo.html

<html><head><title>This is a python demo page</title></head>
<body>
<p class="title"><b>The demo python introduces several python courses.</b></p>
<p class="course">Python is a wonderful general-purpose programming language. You can learn Python from novice to professional by tracking the following courses:
<a href="http://www.icourse163.org/course/BIT-268001" class="py1" id="link1">Basic Python</a> and <a href="http://www.icourse163.org/course/BIT-1001870001" class="py2" id="link2">Advanced Python</a>.</p>
</body></html>
'''

import re
from bs4 import BeautifulSoup
import requests

url = "http://python123.io/ws/demo.html"
try:
    r = requests.get(url)
    print(r.raise_for_status(), end=' ')
    r.encoding = r.apparent_encoding
    demo = r.text
    #print(r.text, end='')
    soup = BeautifulSoup(demo, 'html.parser')
    #print(soup.prettify())
    for link in soup.find_all('a'):
        print(link.get('href'), end=' ')
    soup.find_all(['a', 'b'])
    for tag in soup.find_all(True):
        print(tag.name, end=' ')
    for tag in soup.find_all(re.compile('b')):
        print(tag.name, end=' ')
except:
    print("爬取失败")


html="""
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title" name="dromouse"><b>The Dormouse's story</b></p>
<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="xiaodeng"><!-- Elsie --></a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
<a href="http://example.com/lacie" class="sister" id="xiaodeng">Lacie</a>
and they lived at the bottom of a well.</p>
<p class="story">...</p>
"""
soup = BeautifulSoup(html, 'html.parser')
for k in soup.find_all('a'):
    print(k)
    print(k['class'])#查a标签的class属性
    print(k['id'])#查a标签的id值
    print(k['href'])#查a标签的href值
    print(k.string)#查a标签的string

