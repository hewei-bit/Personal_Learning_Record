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
    int red = ui->redSlider->value();
    int green = ui->greenSlider_2->value();
    int blue = ui->blueSlider_3->value();
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);
    ui->red_num_label->setText(QString::number(red));
    ui->red_lineEdit->setText(QString::number(red));
    qDebug() << "color = " << color;
    ui->label->setStyleSheet(color);

}

void MainWindow::on_greenSlider_2_sliderMoved(int position)
{
    int red = ui->redSlider->value();
    int green = ui->greenSlider_2->value();
    int blue = ui->blueSlider_3->value();
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);
    qDebug() << "color = " << color;
    ui->label->setStyleSheet(color);
}

void MainWindow::on_blueSlider_3_sliderMoved(int position)
{
    int red = ui->redSlider->value();
    int green = ui->greenSlider_2->value();
    int blue = ui->blueSlider_3->value();
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);
    qDebug() << "color = " << color;
    ui->label->setStyleSheet(color);
}
