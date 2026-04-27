#ifndef V4L2CLIENT_H
#define V4L2CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>


namespace Ui {
class v4l2client;
}

class v4l2client : public QMainWindow
{
    Q_OBJECT

public:
    explicit v4l2client(QWidget *parent = 0);
    ~v4l2client();

private slots:
    void on_pushButton_clicked();
    void read_data();
    void ShowImage(QByteArray ba);
private:
    Ui::v4l2client *ui;
    QTcpSocket *socket;
    quint64 basize;
};

#endif // V4L2CLIENT_H
