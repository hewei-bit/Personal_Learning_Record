#ifndef FILERECV_H
#define FILERECV_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class FileRecv;
}

class FileRecv : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileRecv(QWidget *parent = nullptr);
    ~FileRecv();
private slots:
    void new_client();
    void read_data();
private:
    Ui::FileRecv *ui;
    QTcpServer mserver;
    QFile file;
    QString fileName;
    quint64 filesize;
    quint64 recvsize;
};

#endif // FILERECV_H
