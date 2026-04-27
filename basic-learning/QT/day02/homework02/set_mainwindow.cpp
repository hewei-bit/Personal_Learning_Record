#include "set_mainwindow.h"
#include "ui_set_mainwindow.h"
#include "show_mainwindow.h"
#include "teacher.h"

#include <QtDebug>
#include <QMessageBox>
using namespace std;
set_MainWindow::set_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::set_MainWindow)
{
    ui->setupUi(this);
    connect(ui->makesure_pushButton,&QPushButton::clicked,this,&set_MainWindow::show_show_ui);
}

set_MainWindow::~set_MainWindow()
{
    delete ui;
}

void set_MainWindow::show_show_ui()
{
    qDebug() << "show_show_ui";
    show_MainWindow* sm = new show_MainWindow(this);
    sm->show();
    teacher tt;
    QString Qname = ui->name_lineEdit->text();
    tt.setT_name(Qname.toStdString());
    QString Qposition = ui->position_lineEdit_3->text();
    tt.setT_position(Qposition.toStdString());
    QString Qapartment = ui->apartment_lineEdit_2->text();
    tt.setT_departments(Qapartment.toStdString());

    qDebug() << QString::fromStdString(tt.getT_name()) ;

    connect(sm,&show_MainWindow::sendteacher,sm,&show_MainWindow::showteacher);
    emit sm->sendteacher(tt);

    this->close();

}



