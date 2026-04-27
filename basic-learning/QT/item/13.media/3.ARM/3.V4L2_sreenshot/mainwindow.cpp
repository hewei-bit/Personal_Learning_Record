#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QtDebug>
#include <QDate>

#include "connect_database.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),bufrgb(nullptr)
{
    ui->setupUi(this);
    pd.dev_name = (char*)"/dev/video7";




    connect(&timer,&QTimer::timeout,this,&MainWindow::flushButff);
    timer.setInterval(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_2_clicked()
{
    QImage image(bufrgb,640,480,QImage::Format_RGB888);
         ui->displaytLabel->setPixmap(QPixmap::fromImage(image));
    QDate nowdate = QDate::currentDate();
    QString filename = QString("%1.png").arg(nowdate.toString("yyyy-MM-dd"));
    image.save(filename);
    qDebug() << filename;
//    printf("save");
//    return_data(&pd);
    QPixmap pixmap = QPixmap::fromImage(image);


    ui->shotlabel->setPixmap(pixmap.scaled(ui->shotlabel->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
//    ui->startBtn->setDisabled(0);


    QSqlQuery query;


    query.exec(QString("INSERT INTO namelist(name) VALUES('%1')").arg(filename));
}

void MainWindow::on_startBtn_clicked()
{
    int flag = init_dev(&pd);
    if(flag == -1)
    {
        QMessageBox::information(this,"tip","no device");
        exit(1);
    }else if (flag == -2) {
        QMessageBox::information(this,"tip"," device is worng");
        exit(2);
   } else if (flag == -3) {
        QMessageBox::information(this,"tip"," can not open device");
        exit(3);
   }
    ui->startBtn->setDisabled(1);
    timer.start(); //开启捕获数据
}

void MainWindow::flushButff()
{
    read_frame(&pd); //读取数据

    if(!bufrgb)
        bufrgb = (unsigned char *)malloc(640*480*3);
    memset(bufrgb,0,640*480*3);

    convert_yuv_to_rgb_buffer((unsigned char*)pd.buffers[pd.buf.index].start,
            bufrgb,640,480);

    QImage image(bufrgb,640,480,QImage::Format_RGB888);
         ui->displaytLabel->setPixmap(QPixmap::fromImage(image));

    return_data(&pd);
}

void MainWindow::on_startBtn_3_clicked()
{
    //打开数据库
    if(!createConnection("sreenshot.db"))
    {
       qDebug() << "cannot open db";
//        return 1;
    }

    QSqlQuery query;

    qDebug() << "open success";

    QString sqlSelect = QString("SELECT * FROM namelist"); //* 代表所有字段的信息
    if(!query.exec(sqlSelect))
    {
          qDebug() << "Error:Failed to select record";
    }else
    {

        qDebug() << "success select record";
        //如果语句执行成功，要真正执行查询操作

        for (int i = 0;query.next();i++)
        { //按行来进行遍历

            int id = query.value(0).toInt();
            QString name = query.value(1).toString();


            qDebug() << "id" << id<< name ;


            ui->listWidget->addItem(name);


        }
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}
