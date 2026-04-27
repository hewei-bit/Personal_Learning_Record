#京东页面爬取

import requests as rq
try:
    r = rq.get("https://item.jd.com/61782225410.html")
    # r.status_code
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[:1000])
except:
    print("产生异常")