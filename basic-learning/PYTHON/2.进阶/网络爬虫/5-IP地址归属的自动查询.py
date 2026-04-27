import requests

url = "https://m.ip138.com/ip.asp?ip="


def getHTMLText(url):
    try:
        kv = {'user-agent': 'Mozilla/5.0'}
        r = requests.get(url + '202.204.80.112', headers=kv)
        print(r.status_code)
        r.raise_for_status()  # 如果状态不是200，表示状态异常
        r.encoding = r.apparent_encoding
        return r.text[-500:]
    except:
        return "产生异常"


if __name__ == "__main__":
    print(getHTMLText(url))
