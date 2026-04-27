#ifndef FILESEND_H
#define FILESEND_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class FileSend;
}

class FileSend : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileSend(QWidget *parent = nullptr);
    ~FileSend();

private slots:
    void on_sendBtn_clicked();

    void on_selectBtn_clicked();
    void send_file_head(); //发送文件的头信息
    void send_file_text(); //发送文件内容
private:
    Ui::FileSend *ui;

    QTcpSocket mscoket;

    QFile file;
    QString fileName;
    qint64 filesize;
    qint64 sendsize;

};

#endif // FILESEND_H
