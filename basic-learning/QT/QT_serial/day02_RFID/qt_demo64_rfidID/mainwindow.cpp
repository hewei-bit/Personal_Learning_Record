#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readrfidid.h"




LED::LED(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    while(1)
    {
        readCardId(); //在功能需求来进行读取

        sleep(1);
    }

}

LED::~LED()
{
    delete ui;
}
