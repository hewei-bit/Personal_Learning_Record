#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::num = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTimer = new QTimer(this);
    connect(mTimer,&QTimer::timeout,this,&MainWindow::show_sec);
    mTimer->setInterval(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_Btn_clicked()
{
    mTimer->start();

}

void MainWindow::on_reset_Btn_clicked()
{
mTimer->stop();
num=0;
QTime t(0,0,0);
t = t.addMSecs(num);
ui->show_label->setText(t.toString("hh:mm:ss:zzz"));

}

void MainWindow::on_count_Btn_clicked()
{
    ui->textBrowser->append(ui->show_label->text());
}

void MainWindow::on_stop_Btn_clicked()
{
    mTimer->stop();
}

void MainWindow::show_sec()
{
    num++;
    QTime t(0,0,0);
    t = t.addMSecs(num);
    ui->show_label->setText(t.toString("hh:mm:ss:zzz"));
}
