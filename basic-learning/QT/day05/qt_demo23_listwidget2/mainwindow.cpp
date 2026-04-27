#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

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

void MainWindow::on_addWinBtn_clicked()
{
     //[1] 创建条目
    Form* form = new Form;
    QListWidgetItem* item = new QListWidgetItem();
    //设置条目的大小，最好跟Form是一样大
    item->setSizeHint(QSize(793,46));
    ui->listWidget->addItem(item);
    //给一个条目设置一个窗口为form
    ui->listWidget->setItemWidget(item,form);
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
   qDebug() << "void MainWindow::on_listWidget_doubleClicked()";

}
