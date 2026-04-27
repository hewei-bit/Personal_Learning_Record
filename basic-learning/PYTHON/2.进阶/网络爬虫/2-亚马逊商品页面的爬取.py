# 亚马逊商品


import requests as rq

url = 'https://www.amazon.cn/dp/B07RXNF2W2/ref=sr_1_1?dchild=1&pf_rd_i=1403206071&pf_rd_m=A1AJ19PSB66TGU&pf_rd_p=15dd4a70-f222-4a03-9fa9-03d126c09a88&pf_rd_r=1W5D4WV6QVR24VBCKQP4&pf_rd_s=merchandised-search-top-3&pf_rd_t=101&qid=1583048703&rw_html_to_wsrp=1&s=amazon-global-store&sr=1-1'
try:
    kv = {'user-agent': 'Mozilla/5.0'}
    r = rq.get(url, headers=kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[1000:2000])
except:
    print("产生异常")
