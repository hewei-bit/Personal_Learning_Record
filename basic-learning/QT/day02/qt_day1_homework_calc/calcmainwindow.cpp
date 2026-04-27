#include "calcmainwindow.h"
#include "ui_calcmainwindow.h"

CalcMainWindow::CalcMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcMainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("简易计算器");
}

CalcMainWindow::~CalcMainWindow()
{
    delete ui;
}
