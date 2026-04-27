#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
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
    void on_sendBtn_clicked();

    void on_selectBtn_clicked();

    void send_file_head();//发送文件头信息
    void send_file_text();//发送文件文本
private:
    Ui::MainWindow *ui;

    QTcpSocket msocket;

    QFile file;
    QString fileName;

    qint64 filesize;
    qint64 sendsize;



};

#endif // MAINWINDOW_H
