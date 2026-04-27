#include "login.h"
#include "ui_login.h"
#include "mainsystem.h"
#include <QtDebug>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //建立信号与槽
    connect(ui->loginBtn,&QPushButton::clicked,this,&Login::loginBtnClicked);
    
}

Login::~Login()
{
    delete ui;
}
//在QT中，GUI是由UI线程来进行管理
void Login::loginBtnClicked()
{
    qDebug() << "==========";
     //[1]获得用户输入的用户名和密码
    QString username = ui->userEdit->text();
    QString password = ui->passwordEdit->text();
    qDebug() << "username = " << username << " password = " << password;
    //[2] 判断用户名和密码是否正确
    if(username == "root" && password == "123456")
    {
          //[3] 跳转到主界面
        MainSystem* ms = new MainSystem(this); //this 代表着从当前界面跳转到MainSystem
        ms->show();

        //将当前界面进行隐藏
        this->hide();
    }else {
      //当用户名或者密码出错，要提示用户 --- 消息盒子
//        QMessageBox msgBox;
//         msgBox.setText("用户名或者密码出错.");
//         msgBox.exec();
         //更加便利
         QMessageBox::warning(this,"用户登录提示","用户名或者密码出错");
    }

}
