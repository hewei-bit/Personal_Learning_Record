import requests
import json
from datetime import datetime
import matplotlib.pyplot as plt

money = 100
fundCode = '160135'  # 基金代码
pageIndex = 1
startDate = '2018-08-21'
endDate = '2020-03-03'
header = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:69.0) Gecko/20100101 Firefox/69.0',
    'Referer': 'http://fundf10.eastmoney.com/jjjz_{0}.html'.format(fundCode)
}
url = 'http://api.fund.eastmoney.com/f10/lsjz?fundCode={0}&pageIndex={1}&pageSize=5000&startDate={2}&endDate={3}&_=1555586870418?'.format(
    fundCode, pageIndex, startDate, endDate)


def getHTMLText(url, header):
    try:
        r = requests.get(url, timeout=30, headers=header)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        result = json.loads(r.text)
        return result
    except:
        print("爬取异常")


def dealList(html):
    total = [0] * 5  # 到期后总份额
    count = [0] * 5  # 每日定投次数
    total_money = []
    for j in html['Data']['LSJZList'][::-1]:
        if j['JZZZL'] == '':
            pass
        else:
            weekday = int(datetime.strptime(j['FSRQ'], '%Y-%m-%d').weekday())
            DWJZ = float(j['DWJZ'])  # 净值
            total[weekday] += money / DWJZ
            count[weekday] += 1
    for t, i in enumerate(total):
        total_money.append(i * DWJZ)
        print("周{0}定投最终金额{1}".format(t + 1, i * DWJZ), "定投{0}次".format(count[t]))
    print(total)
    print(count)
    return total_money, total, count


def drawBar(total_money, total, count):
    plt.rcParams['font.sans-serif'] = ['SimHei']  # windows 用来正常显示中文标签
    plt.figure(figsize=(15, 10), dpi=80)
    # 标题
    plt.title('{0}基金模拟定投收益图'.format(fundCode), fontsize=25, color='blue')
    # Y轴范围
    minytick = int(min(total_money)) - 1000
    maxytick = int(max(total_money)) + 1000
    # X轴范围
    x_list = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri']
    x = range(len(x_list))
    # 到期后总收益率
    profit_list = [round((i - 100 * j) / (100 * j), 4) for i, j in zip(total_money, count)]
    # 绘制最终收益金额
    plt.bar(x, [i for i in total_money],label='该日定投最终收益', width=0.4, color='y')
    # 参数 m、m2、r 用来调整高度比例
    m = sum(total_money) / 5
    m2 = min(profit_list)
    r = 50000
    # 绘制最终收益率
    plt.bar([i + 0.4 for i in x], [(i - m2) * r + m for i in profit_list], \
            label='该日定投收益率', width=0.4, color='r')
    # 图标
    plt.legend(loc="upper left")
    # 绘制X,Y轴
    plt.xlabel('This Is X Axis', fontsize=15)
    plt.ylabel('This Is Y Axis', fontsize=15)
    plt.xticks(x, x_list, size=15)
    plt.ylim(minytick, maxytick)
    plt.yticks(range(minytick, maxytick, 200), size=15)  # y坐标
    # 获得坐标轴的句柄
    ax = plt.gca();
    ax.spines['left'].set_linewidth(3) ; ####设置左边坐标轴的粗细
    ax.spines['bottom'].set_linewidth(3) ; ###设置底部坐标轴的粗细
    for a, b, c in zip(x, total_money, count):
        plt.text(a, b + 0.05, '%.1f' % b, ha='center', va='bottom', fontsize=15)
        plt.text(a, b + 200, '定投{}次'.format(c), ha='center', va='bottom', fontsize=15, color='r')
    for a, b in zip(x, profit_list):
        plt.text(a + 0.4, (b - m2) * r + m, '%.4f' % b, ha='center', va='bottom', fontsize=15)

    plt.text(2, maxytick + 300, '时间：{0}至{1}'.format(startDate, endDate), fontsize=20)
    plt.grid(axis="y")  # 生成网格
    plt.show()


if __name__ == '__main__':
    html = getHTMLText(url, header)
    # print(html)
    total_money, total, count = dealList(html)
    drawBar(total_money, total, count)
