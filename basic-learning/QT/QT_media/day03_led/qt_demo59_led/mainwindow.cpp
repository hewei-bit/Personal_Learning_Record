#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
//在嵌入式中，qt应用程序要访问linux系统中头文件，是C程序实现的一个操作系统
//在C++中，使用C语言接口和头文件方法
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isLedState = false;

    //打开设备文件

    fd = ::open("/dev/gec6818_led_drv",O_WRONLY);
    if(fd == -1)
    {
        qDebug() << "open led eraaaror";
        return;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    ::close(fd);
}

void MainWindow::on_switchBtn_clicked()
{
    char user_buf[2];
    if(!isLedState)
    {
        //开灯
         user_buf[0] = 8;
         user_buf[1] = 1; //表示灯按下
        isLedState = true;
        ui->switchBtn->setText("灯已开");
        //选择控制第几个灯-7 8 9 10，另外，1---开灯  0 --- 关灯 ---根据生活的逻辑来下发命令
        ::write(fd,user_buf,sizeof (user_buf));
    }else {
        //关灯
        user_buf[0] = 8;
        user_buf[1] = 0; //表示灯松开
        isLedState = false;
         ui->switchBtn->setText("灯已关");
         ::write(fd,user_buf,sizeof (user_buf));
    }
}
