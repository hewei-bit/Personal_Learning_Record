#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>



namespace Ui {
class myserial;
}

class myserial : public QMainWindow
{
    Q_OBJECT

public:
    explicit myserial(QWidget *parent = nullptr);
    ~myserial();

    void init();
    QSerialPort::Parity selectParityBits(const QString &value);
    QSerialPort::StopBits selectStopBits(const QString &value);
    QSerialPort::DataBits selectDataBits(const QString &value);
    QSerialPort::BaudRate selectBaudRate(const QString &value);
    bool eventFilter(QObject *target, QEvent *event);//事件过滤器
public slots:
    void read_data();
private slots:


    void on_refreshBtn_clicked();

    void on_sendBtn_clicked();

    void on_clear_send_Btn_clicked();

    void on_clear_recvBtn_clicked();

    void on_open_close_serial_Btn_clicked();

    void on_sNumClearBtn_clicked();

    void on_hex_recv_radioBtn_clicked();

private:
    Ui::myserial *ui;
    QSerialPort mserial;//串口类对象
    QList<QSerialPortInfo> serialinfos;//串口类信息
    QTimer *timer;

    bool portIsOpen;
    bool Hex_recv;
    bool Hex_send;
    bool text_recv;
    bool text_send;
    bool autoSend;
    bool show_recvtime;
    bool send_newline;

    unsigned char fontNum;



};

#endif // MYSERIAL_H
