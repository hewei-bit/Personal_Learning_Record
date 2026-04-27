#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_readFileBtn_clicked()
{
     //如果是本地的文件数据，首先将文件转换成一个QFile对象
    QFile file(":/film.json");
   // QFile file(":/11.txt");
   //QFile file("./film.json");
    //对于RES目录 下的资源文件，只能读取，不要进行写操作，打开文件并读取
    bool isok = file.open(QIODevice::ReadOnly);
    qDebug() << "isok = " << isok;
    if(isok)
    {
          QByteArray filmData = file.readAll();
           QTextCodec *codec = QTextCodec::codecForName("UTF-8");
           QString string = codec->toUnicode(filmData);

           qDebug() << "data = " << string;


    }else {
        QMessageBox::information(this,"打开提示","文件路径或者文件名字错误，请重试");
    }

}
