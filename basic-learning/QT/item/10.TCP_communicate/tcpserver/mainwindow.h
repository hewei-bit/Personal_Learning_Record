#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QHostAddress>
#include <QTextCodec>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void newClient();
    void readData();

private slots:
    void on_start_Btn_clicked();

    void on_send_Btn_clicked();

    void on_clear_Btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer server;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
