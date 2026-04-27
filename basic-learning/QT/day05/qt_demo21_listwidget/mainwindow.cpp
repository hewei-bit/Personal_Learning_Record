#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //this->centralWidget() ----针对QMainWindow类
    listWidget = new QListWidget(this->centralWidget());
    listWidget->resize(200,this->height());
    listWidget->addItem("条目一");

    QStringList items; //字符串列表

    items << "条目二"<<"条目三"<<"条目四" << "条目五";
    listWidget->addItems(items);

    listWidget->addItem(new QListWidgetItem("条目六",listWidget));
    listWidget->addItem(new QListWidgetItem(QIcon(":/pic/open.png"),"条目七",listWidget));

    connect(listWidget,&QListWidget::itemDoubleClicked,this,&MainWindow::doubleListWidgetClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doubleListWidgetClicked(QListWidgetItem *item)
{
//    qDebug() << "doubleListWidgetClicked ";

    QDialog *d = new QDialog(this);
    d->resize(100,100);
    d->show();
    //QMessageBox::information(this,"sss","kwg ");
  qDebug() << item->data(0).toString(); //获得文本上的信息
}
