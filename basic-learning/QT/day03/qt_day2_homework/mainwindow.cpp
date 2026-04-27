#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

QString comment[] = {"你的人品太差了。",
                     "你应该有干坏事的嗜好吧?","你的人品很好。",
                    "你应该很多好事?"};
//QString comment1[] = {"你的人品很好。"
//                     "你应该很多好事?"};
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

void MainWindow::on_starttestBtn_clicked()
{
     //如果出来的结果要根据系统随机分配，评价和得分都是由系统自动分配
    int sorce = rand() % 100; //(0~99)
    int index = rand() % 4; //(0~3) //防止数组越界

    qDebug() << "sorce = " << sorce << "index = " << index ;
    ui->nameLabel->setText(ui->inputNameEdit->text());
    ui->scoreLabel->setText(QString::number(sorce));
    ui->commentLabel->setText(comment[index]);

}
