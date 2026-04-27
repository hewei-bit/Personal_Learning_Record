#include "teachersystem.h"
#include "ui_teachersystem.h"


TeacherSystem::TeacherSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherSystem)
{
    ui->setupUi(this);
}

TeacherSystem::~TeacherSystem()
{
    delete ui;
}

void TeacherSystem::on_teacherBtn_clicked()
{
       //跳转到教师是现界面
       //创建教师
    Teacher mTeacher("张三","电子系","讲师");
    TeacherMainWindow* tmw = new TeacherMainWindow(this);
    tmw->show(); // 显示界面

    //从主界面要发送信息给教师界面，要建立这两个界面的信号与槽
    connect(this,&TeacherSystem::sendTeacherInfo,tmw,&TeacherMainWindow::getTeacherInfo);

    emit sendTeacherInfo(mTeacher); //发送 信息，并携带教师信息

    this->hide();
}


