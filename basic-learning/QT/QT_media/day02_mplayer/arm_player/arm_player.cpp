#include "arm_player.h"
#include "ui_arm_player.h"

ARM_player::ARM_player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ARM_player)
{
    ui->setupUi(this);
}

ARM_player::~ARM_player()
{
    delete ui;
}

void ARM_player::on_addBtn_clicked()
{
    if(mProcess.state() == QProcess::Running)
    {
        mProcess.kill();
        mProcess.waitForFinished();
    }

    QString cmd = QString("mplayer -slave -quiet "
                          "-geometry 0:0 -zoom -x %1 -y %2 "
                          "/zero/qttest.mp4")
                            .arg(ui->label->width())
                            .arg(ui->label->height());
    qDebug() << "cmd = " << cmd;

    mProcess.start(cmd);


}
