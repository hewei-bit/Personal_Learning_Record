#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isRunning = 0;
    //打开设备文件

    fd = ::open("/dev/gz13_led_drv",O_WRONLY);
    if(fd == -1)
    {
        qDebug() << "open led error";
        return;
    }
    connect(&timer,&QTimer::timeout,this,&MainWindow::Running_water_light);
    timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    ::close(fd);
}

void MainWindow::on_d7Btn_clicked()
{

}

void MainWindow::Running_water_light()
{

    char databuf[2]; //根据驱动来定义数据格式
                     //databuf[0] --- 代表灯的状态：0 --- 关灯，1 ---开灯

                //databuf[1] ---- 代表灯的编号 ：7 8 9 10
         if(isRunning == 0)
         {
             //D7
            databuf[0] = 0; //关灯
            databuf[1] = 10;
            write(fd,databuf,sizeof(databuf));

            databuf[0] = 1; //开灯
            databuf[1] = 7;
            write(fd,databuf,sizeof(databuf));
         }else if (isRunning == 1) {
             //D8
             databuf[0] = 0; //关灯
             databuf[1] = 7;
             write(fd,databuf,sizeof(databuf));

             databuf[0] = 1; //开灯
             databuf[1] = 8;
             write(fd,databuf,sizeof(databuf));
         }else if (isRunning == 2) {
             //D9
             databuf[0] = 0; //关灯
             databuf[1] = 8;
             write(fd,databuf,sizeof(databuf));

             databuf[0] = 1; //开灯
             databuf[1] = 9;
             write(fd,databuf,sizeof(databuf));
         }else if (isRunning == 3) {
             //D10
             databuf[0] = 0; //关灯
             databuf[1] = 9;
             write(fd,databuf,sizeof(databuf));

             databuf[0] = 1; //开灯
             databuf[1] = 10;
             write(fd,databuf,sizeof(databuf));
         }

         isRunning++;
         if(isRunning == 4)
         {
             isRunning = 0;
         }

}
