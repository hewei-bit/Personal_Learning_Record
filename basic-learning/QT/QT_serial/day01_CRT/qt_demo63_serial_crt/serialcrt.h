#ifndef SERIALCRT_H
#define SERIALCRT_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class SerialCRT;
}

class SerialCRT : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialCRT(QWidget *parent = nullptr);
    ~SerialCRT();

private slots:
    void on_actionopen_triggered();
    void read_data();
    void on_openBtn_clicked();

private:
    Ui::SerialCRT *ui;
    QSerialPort mserial; //串口类对象
    QList<QSerialPortInfo> infos; //串口信息类
};

#endif // SERIALCRT_H
