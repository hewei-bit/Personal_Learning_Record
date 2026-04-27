#ifndef VIDEODISPLAY_H
#define VIDEODISPLAY_H

#include <QDialog>
#include <QtGui>
#include "v4l2.h"
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class VideoDisplay;
}

class VideoDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit VideoDisplay(QWidget *parent = 0);
    ~VideoDisplay();

private slots:
    void beginCapture();
    void flushBuff();
    void savebmpData();
    void tcp_receive();
private:
    Ui::VideoDisplay *ui;
    pass_data pd;
    QTimer *timer;
    QTcpSocket *socket;
    QTcpServer *tcp_server;
    int start_tcp;
    unsigned char *bufrgb;
};

#endif // VIDEODISPLAY_H
