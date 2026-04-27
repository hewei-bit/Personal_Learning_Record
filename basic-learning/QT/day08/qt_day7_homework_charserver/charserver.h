#ifndef CHARSERVER_H
#define CHARSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class CharServer;
}

class CharServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharServer(QWidget *parent = nullptr);
    ~CharServer();

private slots:
    void on_startBtn_clicked();

    void on_clearBtn_clicked();

    void on_sendBtn_clicked();

    void newClient();
    void readData();
private:
    Ui::CharServer *ui;
    QTcpServer server;
    QTcpSocket *socket;
};

#endif // CHARSERVER_H
