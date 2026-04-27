#ifndef SERIALRFID_H
#define SERIALRFID_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

namespace Ui {
class SerialRfid;
}

#ifdef __cplusplus
extern "C" {
#endif

#include <termios.h>
#include <unistd.h>
#include <strings.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define USART1 "/dev/ttySAC1"

#ifdef __cplusplus
}
#endif

class SerialRfid : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialRfid(QWidget *parent = nullptr);
    ~SerialRfid();
    int PiccRequest();//发起请求
    int PiccAnticoll();//防碰撞
     char calBCC( char* buf,int n);//校验和计算
private slots:
    void on_getCardId_clicked();

    void on_openBtn_clicked();
    void updateCardId();
     void read_data();
private:
    Ui::SerialRfid *ui;
    QSerialPort serial;
    QTimer *timer;
};

#endif // SERIALRFID_H
