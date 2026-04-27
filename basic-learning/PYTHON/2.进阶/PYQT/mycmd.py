# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mycmd.ui'
#
# Created by: PyQt5 UI code generator 5.12.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(797, 633)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.show_label = QtWidgets.QLabel(self.centralwidget)
        self.show_label.setGeometry(QtCore.QRect(60, 140, 121, 21))
        self.show_label.setObjectName("show_label")
        self.show_textBrowser = QtWidgets.QTextBrowser(self.centralwidget)
        self.show_textBrowser.setGeometry(QtCore.QRect(60, 180, 641, 341))
        self.show_textBrowser.setObjectName("show_textBrowser")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(600, 80, 101, 41))
        self.pushButton.setObjectName("pushButton")
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(60, 80, 511, 41))
        self.lineEdit.setObjectName("lineEdit")
        self.input_label = QtWidgets.QLabel(self.centralwidget)
        self.input_label.setGeometry(QtCore.QRect(60, 50, 101, 16))
        self.input_label.setObjectName("input_label")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 797, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.pushButton.clicked.connect(self.letsgo)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def letsgo(self):
        self.show_textBrowser.setText("hello")
        Qpro = QtCore.QProcess()
        Qpro.setProgram('cmd')
        argment = '/c' + 'ipconfig' #self.lineEdit.text()
        Qpro.setArguments([argment])
        Qpro.start()
        # Qpro.start('cmd.exe', ['ipconfig'])
        Qpro.waitForStarted()
        Qpro.waitForFinished()
        result = Qpro.readAll()
        result_new = str(result, encoding='GB18030')
        self.show_textBrowser.setText(result_new)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MyCmd"))
        self.show_label.setText(_translate("MainWindow", "运行结果如下："))
        self.pushButton.setText(_translate("MainWindow", "运行"))
        self.input_label.setText(_translate("MainWindow", "请输入命令："))
