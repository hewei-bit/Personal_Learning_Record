#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::led_running()
{
    qDebug() << "ledd_run";
    char databuf[2]; //根据驱动来定义数据格式
                     //databuf[0] --- 代表灯的状态：0 --- 关灯，1 ---开灯

            //databuf[1] ---- 代表灯的编号 ：7 8 9 10
     if(isRunning == 0)
     {
         //D7
        databuf[0] = 0; //关灯
        databuf[1] = 10;
        write(fd,databuf,sizeof(databuf));
        ui->D10Btn->setStyleSheet("background-color: rgb(0, 255, 0)");
qDebug() <<"D7";
        databuf[0] = 1; //开灯
        databuf[1] = 7;
        write(fd,databuf,sizeof(databuf));
        ui->d7Btn->setStyleSheet("background-color: rgb(255, 0, 0)");
     }else if (isRunning == 1) {
         //D8
         databuf[0] = 0; //关灯
         databuf[1] = 7;
         write(fd,databuf,sizeof(databuf));
         ui->d7Btn->setStyleSheet("background-color: rgb(0, 255, 0)");
qDebug() <<"D8";
         databuf[0] = 1; //开灯
         databuf[1] = 8;
         write(fd,databuf,sizeof(databuf));
         ui->D8Btn->setStyleSheet("background-color: rgb(255, 0, 0)");
     }else if (isRunning == 2) {
         //D9
         databuf[0] = 0; //关灯
         databuf[1] = 8;
         write(fd,databuf,sizeof(databuf));
         ui->D8Btn->setStyleSheet("background-color: rgb(0, 255, 0)");

         databuf[0] = 1; //开灯
         databuf[1] = 9;
         write(fd,databuf,sizeof(databuf));
         ui->D9Btn->setStyleSheet("background-color: rgb(255, 0, 0)");
     }else if (isRunning == 3) {
         //D10
         databuf[0] = 0; //关灯
         databuf[1] = 9;
         write(fd,databuf,sizeof(databuf));
         ui->D9Btn->setStyleSheet("background-color: rgb(0, 255, 0)");

         databuf[0] = 1; //开灯
         databuf[1] = 10;
         write(fd,databuf,sizeof(databuf));
         ui->D10Btn->setStyleSheet("background-color: rgb(255, 0, 0)");
     }

     isRunning++;
     if(isRunning == 4)
     {
         isRunning = 0;
     }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isRunning = 0;
    //打开 灯的设备文件
    fd = open("/dev/gz13_led_drv",O_WRONLY); //底层硬件所对应的设备文件，由驱动程序来设置
    if(fd < 0)
    {
        perror("open");
        return;
    }
    qDebug() << "open";

    led_run *lr = new led_run();
    lr->setObjectName("lr");
    connect(lr,&led_run::send,this,&MainWindow::led_running);
    lr->start();


}

MainWindow::~MainWindow()
{
    delete ui;
    ::close(fd);
    qDebug() <<"close";
}

void MainWindow::on_d7Btn_clicked()
{
    char databuf[2];
    static bool flag_7 = true;
    if(flag_7)
    {
        databuf[0] = 1; //开灯
        databuf[1] = 7;
        write(fd,databuf,sizeof(databuf));
    }
    else {
        databuf[0] = 0; //开灯
        databuf[1] = 7;
        write(fd,databuf,sizeof(databuf));
    }
    flag_7 = ~flag_7;
}

void MainWindow::on_D8Btn_clicked()
{

}

void MainWindow::on_D9Btn_clicked()
{

}

void MainWindow::on_D10Btn_clicked()
{

}
