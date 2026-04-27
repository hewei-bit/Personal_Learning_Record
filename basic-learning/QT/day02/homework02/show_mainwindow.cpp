#include "show_mainwindow.h"
#include "ui_show_mainwindow.h"
#include "set_mainwindow.h"
#include "teacher.h"

#include <QtDebug>
#include <QMessageBox>

show_MainWindow::show_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_MainWindow)
{
    ui->setupUi(this);

    connect(ui->set_pushButton,&QPushButton::clicked,this,&show_MainWindow::show_set_ui);

}

show_MainWindow::~show_MainWindow()
{
    delete ui;
}

void show_MainWindow::show_set_ui()
{
    qDebug() << "show_set_ui";
    set_MainWindow* setM = new set_MainWindow(this);
    setM->show();


    this->close();
}

void show_MainWindow::showteacher(teacher tt)
{
    ui->position_textBrowser_3->setText(QString::fromStdString(tt.getT_position()));
    ui->apartment_textBrowser_2->setText(QString::fromStdString(tt.getT_departments()));
    ui->name_textBrowser->setText(QString::fromStdString(tt.getT_position()));
}
