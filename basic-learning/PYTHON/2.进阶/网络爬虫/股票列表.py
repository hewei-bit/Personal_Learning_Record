# CrawBaiduStocksB.py
import requests
from bs4 import BeautifulSoup
import traceback
import re
import bs4


def getHTMLText(url, code="utf-8"):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = code
        return r.text
    except:
        return ""


def getStockList(lst, stockURL):
    html = getHTMLText(stockURL)
    soup = BeautifulSoup(html, 'html.parser')
    tr = soup.find_all('tr')
    for td in tr:
        if td('a'):
            a = td('a')
            lst.append([a[0].string, a[1].string, a[2].string])
        else:
            continue


def getStockInfo(infoDict,lst, stockURL):
    count = 1
    for stock in lst:
        url = stockURL + stock[0] + ".html"
        html = getHTMLText(url)
        try:
            if html == "":
                continue
            soup = BeautifulSoup(html, 'html.parser')
            stockInfo = soup.find('div', attrs={'class': "qphox header-title mb7"})
            name = stockInfo.h2.string

            # name = stockInfo.find_all(attrs={'class': 'bets-name'})[0]
            infoDict['股票名称{}'.format(stock[0])] = name

            # keyList = stockInfo.find_all('dt')
            # valueList = stockInfo.find_all('dd')
            # for i in range(len(keyList)):
            #    key = keyList[i].text
            #    val = valueList[i].text
            #    infoDict[key] = val

            #with open(fpath, 'a', encoding='utf-8') as f:
            #    f.write(str(infoDict) + '\n')
            count = count + 1
            print("\r当前进度: {:.2f}%".format(count * 100 / len(lst)), end="")
        except:
            count = count + 1
            print("\r当前进度: {:.2f}%".format(count * 100 / len(lst)), end="")
            continue
    return infoDict


def printStoockList(slist, num):
    tplt = '{0:^10}\t{1:{3}^10}\t{2:^10}\t'
    # print(tplt.format('排名', '学校名称', '指标分数', chr(12288)))
    for i in range(num):
        s = slist[i]
        print(tplt.format(s[0], s[1], s[2], chr(12288)))


if __name__ == '__main__':
    stock_list_url = []
    stock_list_url.append('http://www.yz21.org/stock/info/')
    for i in range(2):
        stock_list_url.append('http://www.yz21.org/stock/info/stocklist_{}.html'.format(i + 2))

    slist = []
    for i in stock_list_url:
        getStockList(slist, i)
    printStoockList(slist, 30)

    stock_info_url = 'http://quote.eastmoney.com/sz'
    output_file = 'D:/BaiduStockInfo.txt'
    # getStockList(slist, stock_list_url[i])
    infoDict = {}
    infoDictN = getStockInfo(infoDict,slist, stock_info_url)


