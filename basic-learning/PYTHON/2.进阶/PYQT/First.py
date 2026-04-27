import sys
from PyQt5.QtWidgets import QApplication, QWidget
from mycmd import Ui_MainWindow
from PyQt5 import QtWidgets
if __name__ == '__main__':
    # 创建QApplication类的实例
    app = QtWidgets.QApplication(sys.argv)
    # 创建一个窗口
    w = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(w)
    # 显示窗口
    w.show()

    # 进入程序的主循环，并通过exti确保主循环安全退出
    sys.exit(app.exec())
