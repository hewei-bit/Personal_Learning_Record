#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    qDebug() << cameras.size();
    foreach (const QCameraInfo &cameraInfo,cameras)
    {
        qDebug() << cameraInfo.deviceName();
        qDebug() << cameraInfo.description();
        ui->comboBox->addItem(cameraInfo.deviceName());
    }
//    for (const QCameraInfo &cameraInfo : cameras){}
//    for each(const QCameraInfo &cameraInfo in cameras){}


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    //QCamera can be used with QCameraViewfinder for viewfinder display
    camera = new QCamera(ui->comboBox->currentText().toUtf8(),this);

    // viewfinder = new QCameraViewfinder(); //它间接继承了QWidget，如果不设置父窗口，则
    //它做为一个独立的窗口显示
    viewfinder = new QCameraViewfinder(ui->widget);
    //设置显示大小跟父控件一样大
    viewfinder->resize(ui->widget->size());
    viewfinder->show();

    camera->setViewfinder(viewfinder);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();//设置完成后，要进行摄像头，否则，摄像头不会工作

    imageCapture = new QCameraImageCapture(camera);

    //当它抓拍到一帧数据时，会发送一个信号
    //void QCameraImageCapture::imageCaptured(int id, const QImage &preview)
    connect(imageCapture,&QCameraImageCapture::imageCaptured,this,&MainWindow::save_photo);


}

void MainWindow::on_captureBtn_clicked()
{
   imageCapture->capture();
   qDebug() << "capture";
}

void MainWindow::save_photo(int id, const QImage &preview)
{
    qDebug() << id;
    QPixmap map = QPixmap::fromImage(preview);
    map = map.scaled(ui->label->size());
    ui->label->setPixmap(map);
}
