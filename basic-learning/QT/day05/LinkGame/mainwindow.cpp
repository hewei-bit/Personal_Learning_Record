#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int i = 1;
    for (int y = 0;y < 4;y++) {
        for (int x = 0; x < 4; ++x) {
            buttons[y][x] = new QPushButton(this->centralWidget());
            buttons[y][x]->resize(50,50);
            buttons[y][x]->move(100+x*75,100+y*75);
            buttons[y][x]->setIconSize(QSize(50,50));
            QString iconPath = QString(":/picture/p%1.png").arg(i++);
            buttons[y][x]->setIcon(QIcon(iconPath));

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
