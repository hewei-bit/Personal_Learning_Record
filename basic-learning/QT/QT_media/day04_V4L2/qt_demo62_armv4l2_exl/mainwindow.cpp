#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagebrowsing.h"

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

void MainWindow::on_picBtn_clicked()
{
    Imagebrowsing* ib = new Imagebrowsing(this);

    ib->show();

    this->hide();
}
