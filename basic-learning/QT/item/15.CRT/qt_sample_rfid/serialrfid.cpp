#include "serialrfid.h"
#include "ui_serialrfid.h"
#include <QtDebug>


SerialRfid::SerialRfid(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialRfid)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,&SerialRfid::updateCardId);
    timer->setInterval(1000);
}

SerialRfid::~SerialRfid()
{
    delete ui;
}

void SerialRfid::on_getCardId_clicked()
{
   //建立与串口相关的槽
    connect(&serial,&QSerialPort::readyRead,this,&SerialRfid::read_data);

    //启动定时器，每隔一秒发起一次请求
    timer->start();

}

void SerialRfid::on_openBtn_clicked()
{
      serial.setPort(QSerialPortInfo(ui->portComboBox->currentText()));
      serial.setBaudRate(QSerialPort::Baud9600);
      serial.setParity(QSerialPort::NoParity);
      serial.setDataBits(QSerialPort::Data8);
      serial.setStopBits(QSerialPort::OneStop);

      bool ok = serial.open(QIODevice::ReadWrite);

}

void SerialRfid::updateCardId()
{
        //主机向从机发起请求，写入数据到串口
    PiccRequest();
       //防碰撞
    PiccAnticoll();

}

void SerialRfid::read_data()
{
    qint64 retval;
    char RBuf[128];
         //read(fd,RBuf,8);

   retval = serial.read(RBuf,8);

    if(retval < 0)
    {
        printf("PiccRequest retval = %d\n",retval);

    }
    if(RBuf[2] == 0x00)
    {
        printf("PiccRequest sucess\n");

    }
}

 char SerialRfid::calBCC( char* buf,int n)
{

    int i = 0;
    unsigned char bcc = 0;

    for(;i<n;i++)
    {
        bcc ^= *(buf+i);
    }

    return (~bcc);
}

int SerialRfid::PiccRequest()
{
    //完成数据的写入和读取两个操作
    //数据帧的封装：字符数组或者结构体都可以
     char WBuf[128];


    memset(WBuf,0,128);

    //数据帧为ISO14443A标准的请求命令
    WBuf[0] = 0x07;
    WBuf[1] = 0x02;
    WBuf[2] = 'A';
    WBuf[3] = 0x01;
    WBuf[4] = 0x52;
    WBuf[5] = calBCC(WBuf,WBuf[0]-2);
    WBuf[6] = 0x03;


    serial.write(WBuf,7);

    return 1;
}

//防碰撞，获取范围内最大的ID，该ID值就是一个电子标签的ID值
int SerialRfid::PiccAnticoll()
{
     char WBuf[128],RBuf[128];


    qint64 retval;
    unsigned int ID; //卡的ID

    memset(WBuf,0,128);


    WBuf[0] = 0x08; //帧长
    WBuf[1] = 0x02; // ISO14443A 标准的命令
    WBuf[2] = 'B'; //防碰撞命令
    WBuf[3] = 0x02; //信息长度 = 2
    WBuf[4] = 0x93; //防碰撞 一级碰撞
    WBuf[5] = 0X00;
    WBuf[6] = calBCC(WBuf,WBuf[0]-2);
    WBuf[7] = 0x03;

    serial.write(WBuf,8);

          //监听成功，读取串口从机返回的值
          retval = serial.read(RBuf,10);
          if(retval < 0)
          {
              printf("PiccAnticoll retval = %d\n",retval);

          }
          //应答帧为0，则表示 成功
          if(RBuf[2] == 0x00)
          {
            printf("PiccAnticoll sucess\n");
              //获取ID，返回的ID的值存放在RBuf[4] RBuf[5] RBuf[6] RBuf[7]
              ID = (RBuf[7]<<24) | (RBuf[6]<<16) | (RBuf[5]<<8) | (RBuf[4]);
              printf("PiccAnticoll The Card ID is %x\n",ID);
              return 0;
          }


    return 1;
}

