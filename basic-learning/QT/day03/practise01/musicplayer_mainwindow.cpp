#include "musicplayer_mainwindow.h"
#include "ui_musicplayer_mainwindow.h"

Musicplayer_MainWindow::Musicplayer_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Musicplayer_MainWindow)
{
    ui->setupUi(this);

    init();

}

Musicplayer_MainWindow::~Musicplayer_MainWindow()
{
    delete ui;
}

void Musicplayer_MainWindow::init()
{
    isStatus = false; //未操作
    ui->begin_pushButton->setEnabled(true);
    ui->close_pushButton_5->setEnabled(false);
    ui->stop_conti_pushButton->setEnabled(false);
    ui->next_pushButton_4->setEnabled(false);
    ui->return_pushButton_2->setEnabled(false);
}

void Musicplayer_MainWindow::on_begin_pushButton_clicked()
{
    ui->close_pushButton_5->setEnabled(true);
    ui->stop_conti_pushButton->setEnabled(true);
    ui->begin_pushButton->setEnabled(false);

}

void Musicplayer_MainWindow::on_stop_conti_pushButton_clicked()
{
    if(!isStatus)
    {
        ui->stop_conti_pushButton->setText("继续");
        isStatus = true;
    }
    else {
        ui->stop_conti_pushButton->setText("zanting");
        isStatus = false;
    }
}

void Musicplayer_MainWindow::on_close_pushButton_5_clicked()
{

}
