#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  //  MyLabel* ml = new MyLabel(ui->centralWidget);
   // ml->setText("挺好的");

    connect(ui->label,&MyLabel::myclicked,this,&MainWindow::changeMyLabelBackgroud);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeMyLabelBackgroud()
{
    qDebug() << "changeMyLabelBackgroud";
    ui->label->setStyleSheet(QString("color:red;"));
}
