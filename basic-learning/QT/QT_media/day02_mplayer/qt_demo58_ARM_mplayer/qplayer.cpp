#include "qplayer.h"
#include "ui_qplayer.h"
#include <QFileDialog>
#include <QtDebug>
QPlayer::QPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QPlayer)
{
    ui->setupUi(this);
}

QPlayer::~QPlayer()
{
    delete ui;
}

void QPlayer::on_addBtn_clicked()
{

    if(mProcess.state() == QProcess::Running)
    {
        mProcess.kill();
        mProcess.waitForFinished();
    }

    //利用第三方播放器来实现视频播放
    //mplayer -slave -quiet -geometry 0:0 -zoom -x 800 -y 400 /GZ13_qt/qttest.mp4
    QString cmd = QString("mplayer -slave -quiet "
                          "-geometry 0:0 -zoom -x %1 -y %2 "
                          "/zero/qttest.mp4")
                            .arg(ui->label->width())
                            .arg(ui->label->height());
    qDebug() << "cmd = " << cmd;

    mProcess.start(cmd);

#if 0
     //打开文件对话框，增加播放列表
   QStringList mediaFiles =   QFileDialog::getOpenFileNames(this,"选择媒体文件");

   ui->listWidget->addItems(mediaFiles);
#endif

}

//void QPlayer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
//{
//      if(mProcess.state() == QProcess::Running)
//      {
//          mProcess.kill();
//          mProcess.waitForFinished();
//      }

//      //获取播放列表中选中条目，以做要播放的文件
//      QString fileName = item->text();

//      //创建一个播放的可选参数列表
//      QStringList argments;
//      //mpalyer -slave -quiet -wid 窗口ID号 媒体的路径
//      argments << "-slave" << "-quiet" <<
//               "-zoom"<<
//             "-wid" << QString::number(ui->label->winId())<<
//                  fileName;
//      //利用第三方播放器来实现视频播放
//      mProcess.start("C:/GZ2027/mplayer-svn-38109/mplayer.exe",argments);
//}
