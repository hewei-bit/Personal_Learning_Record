#ifndef QDVWIDGET_H
#define QDVWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QProcess>
#include <QTime>
namespace Ui {
class QdvWidget;
}

class QdvWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QdvWidget(QWidget *parent = nullptr);
    ~QdvWidget();
private slots:
    void play_auto(); //自动播放广告视频，并且在播放完当前视频后，自动播放视频
    void word_auto(); //自动滚动文字广告
    void time_update(); //更新系统时间

private:
    //定义一个进程对象---实现对视频播放控制
    QProcess mprocess;
    //定义一个存放视频的路径列表
        QStringList videoFiles;
    QStringList words; //存放文字广告
    Ui::QdvWidget *ui;
    QTimer textTimer;
    QTimer timeTimer;

    int wordIndex;
    int videoIndex;
};

#endif // QDVWIDGET_H
