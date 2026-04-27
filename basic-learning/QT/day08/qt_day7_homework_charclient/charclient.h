#ifndef CHARCLIENT_H
#define CHARCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class CharClient;
}

class CharClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharClient(QWidget *parent = nullptr);
    ~CharClient();

private slots:
    void on_linkBtn_clicked();

    void on_clearBtn_clicked();

    void on_sendBtn_clicked();
    void readData();
private:
    Ui::CharClient *ui;
    QTcpSocket socket;
};

#endif // CHARCLIENT_H
