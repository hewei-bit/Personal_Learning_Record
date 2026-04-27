#include "softbuttonwin.h"
#include "ui_softbuttonwin.h"
#include <QDebug>
SoftButtonWin::SoftButtonWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SoftButtonWin)
{
    ui->setupUi(this);
    ui->myWidget->hide();

    //给QLineEdit控件安装事件过滤器
    ui->userEdit_2->installEventFilter(this);
    ui->passwordEdit->installEventFilter(this);


}

SoftButtonWin::~SoftButtonWin()
{
    delete ui;
}
/* 事件过滤器函数重写 */ //在该函数中，可以去处理QLineEdit控件事件
bool SoftButtonWin::eventFilter(QObject *watched, QEvent *event)
{

    if ( (watched == ui->userEdit_2) && (event->type() == QEvent::MouseButtonPress) )
    {
        callKeyBoard();
         ui->userEdit_2->setFocus();
    }
    else if ( (watched == ui->passwordEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        callKeyBoard();
        ui->passwordEdit->setFocus();
    }

    return QMainWindow::eventFilter(watched,event);
}

/* 调用软键盘 */
void SoftButtonWin::callKeyBoard()
{
   // qDebug()<<"callKeyBoard";
    ui->myWidget->show();
}


void SoftButtonWin::on_loginBtn_clicked()
{
    //ui->myWidget->hide();

    //登录系统
}

void SoftButtonWin::on_userEdit_2_editingFinished()
{
    ui->myWidget->hide();
}

void SoftButtonWin::on_passwordEdit_editingFinished()
{
    ui->myWidget->hide();
}
