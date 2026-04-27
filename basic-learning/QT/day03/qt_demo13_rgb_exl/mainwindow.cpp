#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->redSlider->setMaximum(255);
    ui->greenSlider->setMaximum(255);
    ui->blueSlider->setMaximum(255);

   QString str =  ui->plletenLabel->styleSheet();

   qDebug() << "str = " << str; //提取字符串中的内容，并设置给对应控件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColor(const QString &color)
{
    //设置样式背景
    ui->plletenLabel->setStyleSheet(color);
}

void MainWindow::on_redSlider_sliderMoved(int position)
{
    //获取滑动条的值，并设置调色板的色
    int red = ui->redSlider->value();
    int green = ui->greenSlider->value();
    int blue = ui->blueSlider->value();
    ui->redEdit->setText(QString::number(red));

   // QString color("background-color: rgb(20, 170, 20);")
    //字符串拼接
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);
    qDebug() << "color = " << color;
    //设置样式背景
    setColor(color);
}

void MainWindow::on_greenSlider_sliderMoved(int position)
{
    //获取滑动条的值，并设置调色板的色
    int red = ui->redSlider->value();
    int green = ui->greenSlider->value();
    int blue = ui->blueSlider->value();
    ui->greenEdit->setText(QString::number(green));

   // QString color("background-color: rgb(20, 170, 20);")
    //字符串拼接
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);
    qDebug() << "color = " << color;
    //设置样式背景
    setColor(color);
}

void MainWindow::on_blueSlider_sliderMoved(int position)
{
    //获取滑动条的值，并设置调色板的色
    int red = ui->redSlider->value();
    int green = ui->greenSlider->value();
    //int blue = ui->blueSlider->value();
    ui->blueEdit->setText(QString::number(position));

   // QString color("background-color: rgb(20, 170, 20);")
    //字符串拼接
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(position);
    qDebug() << "color = " << color;
    //设置样式背景
    setColor(color);
}
