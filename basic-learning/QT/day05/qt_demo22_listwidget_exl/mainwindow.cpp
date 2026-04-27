#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtDebug>
#include <QFileInfo>
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

void MainWindow::on_actionopen_triggered()
{
       filePath =    QFileDialog::getOpenFileNames(this);
       for (int i=0;i<filePath.size();i++) {
           QFileInfo fileinfo(filePath.at(i));

            ui->listWidget->addItem(fileinfo.fileName());
       }

     qDebug() << filePath; //路径 + 文件名，只将文件名存放到


}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{


}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
       index.row(); //获取行号，做为QStringList元素的下标
      QString fileName =  filePath.at(index.row());

       qDebug() << fileName;
      QFile file(fileName);

     bool isok =  file.open(QIODevice::ReadWrite);
     if(isok)
     {
         QByteArray data = file.readAll();

         ui->plainTextEdit->setPlainText(data);
     }
     file.close();
}
