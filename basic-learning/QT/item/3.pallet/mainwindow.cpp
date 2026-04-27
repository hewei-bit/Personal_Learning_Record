#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QColor>
#include <QColorDialog>
#include <QBrush>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(0).arg(0).arg(0);

    ui->label->setStyleSheet(color);

    qDebug() << color;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setcolor(QPalette pal)
{
    QBrush bush = pal.base();
    QColor col = bush.color();
    int r = col.red();
    int g = col.green();
    int b = col.blue();
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(r).arg(g).arg(b);
    ui->label->setStyleSheet(color);

    ui->redSlider->setValue(r);
    ui->greenSlider_2->setValue(g);
    ui->blueSlider_3->setValue(b);
}

void MainWindow::on_redSlider_sliderMoved(int position)
{
    int red = ui->redSlider->value();
    int green = ui->greenSlider_2->value();
    int blue = ui->blueSlider_3->value();
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);
//    ui->red_num_label->setText(QString::number(red));
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
    ui->green_lineEdit_2->setText(QString::number(green));
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
    ui->blue_lineEdit_3->setText(QString::number(blue));
    qDebug() << "color = " << color;
    ui->label->setStyleSheet(color);
}

static int num = 0;

void MainWindow::on_setcolor_Btn_clicked()
{

    num++;
    qDebug() << num;
    num = num % 3;
    int red = ui->redSlider->value();
    int green = ui->greenSlider_2->value();
    int blue = ui->blueSlider_3->value();
    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);

    if(num == 1)
    {
        ui->paltte_1_Btn->setStyleSheet(color);
    }
    if(num == 2)
    {
        ui->paltte_2_Btn->setStyleSheet(color);
    }
    if(num == 0)
    {
        ui->paltte_3_Btn->setStyleSheet(color);
    }
}

void MainWindow::on_paltte_1_Btn_clicked()
{
    QPalette pal = ui->paltte_1_Btn->palette();
    num = 0;
    setcolor(pal);
}

void MainWindow::on_paltte_2_Btn_clicked()
{
    QPalette pal = ui->paltte_2_Btn->palette();
    num =1;
    setcolor(pal);
}

void MainWindow::on_paltte_3_Btn_clicked()
{
    QPalette pal = ui->paltte_3_Btn->palette();
    num =2;
    setcolor(pal);
}
