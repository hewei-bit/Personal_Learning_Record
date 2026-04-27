#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = "helloworld";
    qDebug() <<str;
    qDebug() << str.length() << str.size();//获取字符串长度，两者等价
    qDebug() << str.capacity();
    qDebug() << str.isEmpty(); //没有字符串都返回为true，包含 null和 ""
    qDebug() << str.isNull();//没有字符串返回true，包含null,但不包含""
    //str = ""; //ok
    str.clear(); //清空字符串
    qDebug() << str.length() << str.size();
    str.resize(20); //重置字符串的长度
     qDebug() << str.length() << str.size();

    str.fill('s'); //将字符串，全部用字符's'填充
    qDebug() <<str;
    str.fill('A',3); //size=3,相当于重置了字符串的大小
     qDebug() <<str;
     str.append("hello"); //从末尾追加字符串
     qDebug() <<str;
     str.prepend("HELLO"); //从头部去追加字符串
      qDebug() <<str;

      str.chop(1);
      qDebug() <<str;

      str.remove(2,3); //从下标为2位置开始删除，删除字符个数3
       qDebug() <<str;

       //将数字转换成字符串
       str.setNum(12.5);
        qDebug() <<str;
        //将字符串转换成数字类型
        bool ok;
        double number =  str.toDouble(&ok);
        qDebug() << number << "ok =" << ok;

        /*
        arg()成员函数：字符串通过"%数字"表示argment（参数）占位符，数字从1开始
        */
        str = QString("%1-%2-%3").arg("H").arg(5).arg("L");
        qDebug() <<str;
        str.sprintf("%d,%s",5,"world");

        qDebug() <<str;

       int ret =  str.indexOf("or",5); //根据设置的位置开始查找字符串，
                                      //如果查找成功，返回查找到字符串的位置，否则，-1
        qDebug() <<ret;
        str.insert(2,"A");
        qDebug() << str;
        //background-color: rgb(170, 170, 127); 查找RGB的色彩值


        str = "background-color: rgb(170, 170, 127);";
        qDebug() << str;
        int j = 0;
           j = str.indexOf("(");
             qDebug() << "Found ( tag at index position" << j;
             QString y = str.mid(j+1, 3);
              qDebug() << y;
          while ((j = str.indexOf(",", j)) != -1) {
              qDebug() << "Found ( tag at index position" << j;
              ++j;
          }
}

MainWindow::~MainWindow()
{
    delete ui;
}
