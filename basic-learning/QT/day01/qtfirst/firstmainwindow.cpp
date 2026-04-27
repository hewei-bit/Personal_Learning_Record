#include "firstmainwindow.h"
#include "ui_firstmainwindow.h"
#include "ui_mainwindow.h"
FirstMainWindow::FirstMainWindow(QWidget *parent) :
    QMainWindow(parent),
    //ui(new Ui::FirstMainWindow)
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //给当前类设置一个界面
}

FirstMainWindow::~FirstMainWindow()
{
    delete ui;
}
