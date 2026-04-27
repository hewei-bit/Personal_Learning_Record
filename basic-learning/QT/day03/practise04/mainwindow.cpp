#include "mainwindow.h"
#include "ui_mainwindow.h"

QString name_list[] = {"hewei","aming",
                     "511","115",
                    "lulu","aji"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mTimer = new QTimer(this);

    connect(mTimer,&QTimer::timeout,this,&MainWindow::show_list);
    mTimer->setInterval(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    mTimer->start();
}

void MainWindow::on_stopBtn_clicked()
{
    mTimer->stop();
    ui->show_label_2->setText(ui->list_label->text());
}

void MainWindow::show_list()
{
    int num = rand() % 6;
    ui->list_label->setText(name_list[num]);
}

void MainWindow::select_anyone()
{

}
