#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mylabel.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // MyLabel* ml = new MyLabel(this);
    MyLabel* ml = new MyLabel(ui->centralWidget);
     ml->setText("自定义文本标签控件");

     connect(ui->label,&MyLabel::myonclicked,this,&MainWindow::onClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClicked()
{
     QMessageBox::information(this,"哈哈","label被点击了");
}
