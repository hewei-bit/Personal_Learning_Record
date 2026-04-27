import xlrd
import xlwt
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import csv


def readexcel():
    workbook = xlrd.open_workbook(r'D:\练习+项目\PythonLearning\PythonLearning\进阶\数据分析\test.xlsx')
    print(workbook.sheet_names())
    sheet2 = workbook.sheet_by_name('A')
    nrows = sheet2.nrows
    ncols = sheet2.ncols
    print(nrows, ncols)
    x = sheet2.col_values(0)
    y = sheet2.col_values(1)
    print(x, y)
    cell_A = sheet2.cell(1, 1).value
    print(cell_A)
    return x, y


def writeexcel():
    stus = [['年', '月'], ['2018', '02'], ['2019', '02'], ['2020', '02']]
    excel = xlwt.Workbook()
    sheet = excel.add_sheet('B')
    row = 0
    for stu in stus:
        col = 0
        for i in stu:
            sheet.write(row, col, i)
            col = col + 1
        row = row + 1
    excel.save('test1.xls')


def drawHist(x, y):
    # np.random.seed(0)
    # mu, sign = 100, 20
    # a = np.random.normal(mu, sign, size=100)

    plt.ylabel("纵轴：振幅", fontproperties='SimHei', fontsize=20, color='green')
    plt.xlabel("横轴：时间", fontproperties='SimHei', fontsize=20)
    plt.plot(x, y, 'r--')

    plt.show()


if __name__ == '__main__':
    x, y = readexcel()
    drawHist(x, y)
    # writeexcel()
