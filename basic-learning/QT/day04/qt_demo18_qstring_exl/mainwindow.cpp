#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QString str = "background-color: rgb(170, 170, 127);";
    QString str =  ui->label->styleSheet();
    qDebug() << str;
    int i = str.indexOf("(");
    int j = str.indexOf(",");
   // qDebug() << "i = " <<i;
    QString red = str.mid(i+1, j-1-i);
    qDebug() << "red = " << red.toInt();

    QString green = str.section(",", 1, 1);

    qDebug() << "green = " << green.toInt();

    //
    int last = 0;
    while ((j = str.indexOf(",",j)) != -1) {
       // qDebug() << " j = " << j;
         last = j;
        j++;
    }

     //qDebug() << "last = " << last;

      int k = str.indexOf(")");
     QString bule = str.mid(last+1,k-1-last);

     qDebug() << "blue = " << bule.toInt();
}

MainWindow::~MainWindow()
{
    delete ui;
}
