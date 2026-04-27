#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtDebug>
#include <QFile>

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

void MainWindow::on_openBtn_clicked()
{

    //QString
    //getOpenFileName(QWidget *parent = nullptr,
    //const QString &caption = QString(),
    //const QString &dir = QString(),
    //const QString &filter = QString(),
    //QString *selectedFilter = nullptr, QFileDialog::Options options = Options())

    QString fileName = QFileDialog::getOpenFileName(this);
    qDebug() << fileName; //返回值为一个文件名并且带绝对路径

    //打开文件
    QFile file(fileName);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return;
    //读取内容
        QByteArray array =  file.readAll(); //读取文件中所有的内容
    //显示文件内容在控件上 ---- 文本浏览
        //QByteArray --->自动转换成QString
     ui->contentBrower->setPlainText(array);    //关闭文件
     file.close();
}

void MainWindow::on_saveBtn_clicked()
{
    QString saveFileName = QFileDialog::getSaveFileName(this);

    QFile file(saveFileName);


         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         //得到UI组件上的内容，并写入到文件中
        QString data =  ui->contentBrower->toPlainText();

        //将数据写入到文件中
        //QString 不能自动转换成QByteArray
        file.write(data.toUtf8());

        //关闭文件
        file.close();
}
