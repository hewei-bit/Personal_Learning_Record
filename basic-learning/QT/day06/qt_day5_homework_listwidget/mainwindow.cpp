#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFileInfoList>
#include <QtDebug>
#include <QListWidgetItem>
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

void MainWindow::on_openDirBtn_clicked()
{
     //[1]打开一个目录 ，将目录下的文件显示出来
    QString dirpath = QFileDialog::getExistingDirectory(this, tr("Open Directory"));
    ui->opendirEdit->setText(dirpath);

    //[2] 根据目录的路径，将目录转换成一个目录对象
    //在qt中，得到一个对象的方法：构造函数或者静态函数
    QDir dir(ui->opendirEdit->text());

    //[3]遍历目录，并且判断目录中的文件是目录 还是文件
   QFileInfoList infos =  dir.entryInfoList();

   qDebug() << infos.size() << "   " << infos.count() ;

   for (int i=0;i<infos.count();i++) {
       //每遍历一个内容出来，就是要创建一个条目跟它对应
       QListWidgetItem* item = new QListWidgetItem();

       ItemForm* w = new ItemForm;
       qDebug() << infos.at(i).suffix()  ;
       //判断遍历出来的内容是目录还是文件
       if(infos.at(i).isDir()){
           //如果是目录，则目录 的信息设置在自定义的条目
           w->setDir(infos.at(i).fileName());
       }else if (infos.at(i).isFile()) {
           //如果是文件，则将文件 的信息设置在自定义的条目
           w->setFile(infos.at(i).fileName(),infos.at(i).size());
       }

       //设置自定义条目的大小跟条目的尺寸保持一样
       item->setSizeHint(QSize(751,35));
       ui->listWidget->addItem(item);
       ui->listWidget->setItemWidget(item,w);
   }


}
