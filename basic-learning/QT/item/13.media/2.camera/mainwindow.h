#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraInfo>
#include <QtDebug>
#include <QCameraViewfinder>
#include <QCameraImageCapture>


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
    void on_startBtn_clicked();
    void save_photo(int id, const QImage &preview);
    void on_captureBtn_clicked();

private:
    Ui::MainWindow *ui;
    QCamera *camera;
    QCameraViewfinder* viewfinder;
    QCameraImageCapture *imageCapture;
};

#endif // MAINWINDOW_H
