#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
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

void MainWindow::on_redSlider_sliderMoved(int position)
{
    //获取滑动条的值，并设置调色板的色
    int red = ui->redSlider->value();
   // QString color("background-color: rgb(20, 170, 20);")
    QString color = QString("background-color: rgb(%1, 170, 20);")
                     .arg(red);
    qDebug() << "color = " << color;
    ui->plletenLabel->setStyleSheet(color);
   // ui->plletenLabel->setStyleSheet("background-color: rgb(20, 170, 20);");
}

void MainWindow::on_greenSlider_sliderMoved(int position)
{

}

void MainWindow::on_blueSlider_sliderMoved(int position)
{

}
