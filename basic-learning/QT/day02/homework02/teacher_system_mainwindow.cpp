#include "teacher_system_mainwindow.h"
#include "ui_teacher_system_mainwindow.h"
#include "show_mainwindow.h"
#include "set_mainwindow.h"

#include <QtDebug>
#include <QMessageBox>

teacher_system_MainWindow::teacher_system_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher_system_MainWindow)
{
    ui->setupUi(this);
    connect(ui->teacher_pushButton,&QPushButton::clicked,this,&teacher_system_MainWindow::show_show_ui);
}

teacher_system_MainWindow::~teacher_system_MainWindow()
{
    delete ui;
}

void teacher_system_MainWindow::show_show_ui()
{
    qDebug() << "show_show_ui";
    show_MainWindow* sm = new show_MainWindow(this);
    sm->show();

//    this->close();
}
