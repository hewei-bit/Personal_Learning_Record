#include "qmplayer.h"
#include "ui_qmplayer.h"
#include <QFileDialog>
Qmplayer::Qmplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Qmplayer)
{
    ui->setupUi(this);
}

Qmplayer::~Qmplayer()
{

    delete ui;
}

void Qmplayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(mprocess.state() == QProcess::Running)
    {
        mprocess.kill();
        mprocess.waitForFinished();
    }
    QString fileName= item->text();
    QStringList argments;
    argments << "-slave"<<"-quiet"
             <<"-zoom"<<"-wid"
            <<QString::number(ui->show_label->winId())<<fileName;

    mprocess.start("D:/Software/mplayer-svn-38109/mplayer.exe",argments);
}

void Qmplayer::on_addBtn_clicked()
{



    QStringList mediafiles = QFileDialog::getOpenFileNames(this,"选择播放列表");
    ui->listWidget->addItems(mediafiles);


}
