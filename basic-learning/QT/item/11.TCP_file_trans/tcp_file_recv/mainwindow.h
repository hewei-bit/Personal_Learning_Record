#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QHostAddress>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void new_client();
    void read_data();
private:
    Ui::MainWindow *ui;
    QTcpServer mserver;
    QFile file;
    QString fileName;
    quint64 filesize;
    quint64 recvsize;


};

#endif // MAINWINDOW_H
