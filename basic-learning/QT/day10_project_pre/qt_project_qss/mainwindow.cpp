#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //给指定的控件设置样式
   // ui->pushButton->setStyleSheet("QPushButton,QCheckBox { color: red;"
      //                            "background-color: blue }");

    //给一个窗口上控件设置样式 QMainWindow ---> 继承于QWidget

//    this->setStyleSheet("QPushButton,QCheckBox { color: red;"
//                                                    "background-color: blue }");
    // this->setStyleSheet("*{color: red}");
//    ui->lineEdit->setStyleSheet("QLineEdit {"
//                                "border: 2px solid gray;"
//                                "border-radius: 10px;"
//                                "padding: 0 8px;"
//                                "background: yellow;"
//                                "selection-background-color: darkgray;}");

//    ui->checkBox->setStyleSheet("QCheckBox::indicator {"
//                               "width: 13px;"
//                                "height: 13px;"
//                            "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
