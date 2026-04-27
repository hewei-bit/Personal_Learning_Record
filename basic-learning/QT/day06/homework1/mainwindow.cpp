#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建线程
    th = new Mythread(this);
    th->setObjectName("th");
    //连接信号与槽
    connect(th,&Mythread::send,this,&MainWindow::show_picture);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_Btn_clicked()
{
    th->start();
}

void MainWindow::on_stop_Btn_clicked()
{
    th->terminate();
}

void MainWindow::show_picture(QString dirName)
{
    QPixmap map(dirName);
    QSize laSize=ui->label->size();//label是要显示图片的label的名称
//    QFileInfo fileinfo(dirName);//获取文件信息
    QImage image = QImage(dirName);//获取文件名
    QImage image1 = image.scaled(laSize,Qt::IgnoreAspectRatio);//重新调整图像大小以适应窗口
    ui->label->setPixmap(QPixmap::fromImage(image1));//显示

}
