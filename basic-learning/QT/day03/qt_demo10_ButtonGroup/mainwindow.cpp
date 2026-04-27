#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //将代码中的对象与UI文件中的对象混合一起使用
    btnGroupSex = new QButtonGroup(this);
    btnGroupSex->addButton(ui->manBtn,0);
    btnGroupSex->addButton(ui->womanBtn,1);
    ui->manBtn->setChecked(true); //默认选择一个

    connect(ui->manBtn,&QRadioButton::clicked,this,&MainWindow::onSexRadioChecked);
    connect(ui->womanBtn,&QRadioButton::clicked,this,&MainWindow::onSexRadioChecked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSexRadioChecked()
{
    qDebug() << ui->manBtn->isChecked();
    qDebug() << ui->womanBtn->isChecked();

   int checkId =  btnGroupSex->checkedId();
   switch (checkId) {
    case 0:
       qDebug() << "你选择了做男人";
       break;
    case 1:
       qDebug() << "你选择了做女人";
       break;
    case -1:
       qDebug() << "你不选择做女人，也不选择做男人";
       break;
   }
}
