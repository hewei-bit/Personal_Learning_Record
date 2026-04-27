#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess;
    //建立与readyRead()信号的槽函数
    connect(process,&QProcess::readyRead,this,&MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runBtn_clicked()
{

    //获取输入的命令
    QString cmd = ui->cmdLineEdit->text();
    //启动这个命令
    process->start(cmd);
}

void MainWindow::readData()
{
      QByteArray result =   process->readAll();
      QTextCodec *codec = QTextCodec::codecForName("GB18030");
       QString string = codec->toUnicode(result);
      qDebug() << string ;
      ui->textBrowser->append(string);
}
