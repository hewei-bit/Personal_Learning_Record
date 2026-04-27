#
import requests as rq

try:
    kv = {'wd':'python'}
    r = rq.get("http://www.baidu.com/s",params = kv)
    print(r.request.url)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(len(r.text))
except:
    print("异常")