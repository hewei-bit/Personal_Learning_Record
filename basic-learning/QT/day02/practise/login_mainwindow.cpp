#include "login_mainwindow.h"
#include "ui_login_mainwindow.h"
#include "welcome.h"

#include <QtDebug>
#include <QMessageBox>

using namespace std;

Login_MainWindow::Login_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login_MainWindow)
{
    ui->setupUi(this);
    //建立信号与槽
    connect(ui->resign,&QPushButton::clicked,this,&Login_MainWindow::LoginSuccess);
    connect(ui->login,&QPushButton::clicked,this,&Login_MainWindow::LoginSuccess);
}

Login_MainWindow::~Login_MainWindow()
{
    delete ui;
}

void Login_MainWindow::LoginSuccess()
{
    qDebug() << "------";
//    ui->username_lineEdit->insert("root");
//    ui->password_lineEdit->insert("123456");

    QString Qpassword = ui->password_lineEdit->text();
//    string password = string((const char *)Qpassword.toLocal8Bit());
    QString Qusername = ui->username_lineEdit->text();
//    string username = string((const char *)Qusername.toLocal8Bit());
    if(Qpassword == "111"&& Qusername == "qqq")
    {
//        ui->textBrowser->setText("1111");
        welcome* ms = new welcome(this);


        ms->show();
        connect(ms,&welcome::sendname,ms,&welcome::showname);
        emit ms->sendname(Qusername);
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,"用户登录提示","用户名或者密码出错");

    }
}
