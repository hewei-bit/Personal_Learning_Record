#include "myserial.h"
#include "ui_myserial.h"

void myserial::init()
{
    ui->port_comboBox->clear();
    serialinfos = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo serialinfo,serialinfos)
    {
        qDebug() << serialinfo.portName();
        qDebug() << serialinfo.description();
        qDebug() <<serialinfo.manufacturer();
        qDebug() << serialinfos.size();
        ui->port_comboBox->addItem(serialinfo.portName());
    }
}

QSerialPort::Parity myserial::selectParityBits(const QString &value)
{
    if(value == "NoParity")
    {
        qDebug() << "NoParity";
        return QSerialPort::NoParity;
    }
    if(value == "EvenParity")
    {
        return QSerialPort::EvenParity;
    }
    if(value == "OddParity")
    {
        return QSerialPort::OddParity;
    }
    if(value == "SpaceParity")
    {
        return QSerialPort::SpaceParity;
    }
    if(value == "MarkParity")
    {
        return QSerialPort::MarkParity;
    }
    else
    {
        return QSerialPort::UnknownParity;
    }
}

QSerialPort::StopBits myserial::selectStopBits(const QString &value)
{
    if(value == "OneStop")
    {
        qDebug() << "onestop";
        return QSerialPort::OneStop;
    }
    if(value == "OneAndHalf")
    {
        return QSerialPort::OneAndHalfStop;
    }
    if(value == "TwoStop")
    {
        return QSerialPort::TwoStop;
    }
    else
    {
        return QSerialPort::UnknownStopBits;
    }
}

QSerialPort::DataBits myserial::selectDataBits(const QString &value)
{
    switch (value.toUShort()) {
        case 5:return QSerialPort::Data5;
        case 6:return QSerialPort::Data6;
        case 7:return QSerialPort::Data7;
        case 8:
        qDebug() << "8";
        return QSerialPort::Data8;
        default:return QSerialPort::UnknownDataBits;
    }
}

QSerialPort::BaudRate myserial::selectBaudRate(const QString &value)
{
    switch (value.toInt())
    {
        case 1200:return QSerialPort::Baud1200;
        case 2400:return QSerialPort::Baud2400;
        case 4800:return QSerialPort::Baud4800;
        case 9600:return QSerialPort::Baud9600;
        case 19200:return QSerialPort::Baud19200;
        case 38400:return QSerialPort::Baud38400;
        case 57600:return QSerialPort::Baud57600;
        case 115200:qDebug() << "115200";return QSerialPort::Baud115200;
        default:return QSerialPort::UnknownBaud;
    }
}

myserial::myserial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myserial)
{
    ui->setupUi(this);

//    mserial =new QSerialPort(this);
    timer=new QTimer(this);


    portIsOpen = false;
    Hex_recv = false;
    Hex_send = false;
    text_recv = false;
    text_send = false;
    autoSend = false;
    show_recvtime = false;
    send_newline = false;

    ui->spinBox->setMaximum(1000000);

    ui->text_recv_radioBtn->setChecked(true);
//    ui->hex_recv_radioBtn->setChecked(true);
    ui->text_send_radioBtn->setChecked(true);
//    ui->hex_send_radioBtn->setChecked(true);

    ui->auto_sendcheckBox->setChecked(true);
    ui->send_newline_checkBox->setChecked(true);

    //获取串口信息
    init();






}

myserial::~myserial()
{
    delete ui;
}

void myserial::read_data()
{
    QByteArray array = mserial.readAll();
    qDebug() << array;
    //获取原来文本
//    QString data = ui->recv_textBrowser->toPlainText();
    QString data;
    //接收时间
    if(ui->show_recvtime_checkBox->isChecked())
    {
        QTime nowTime=QTime::currentTime();
        data+="\n"+nowTime.toString("HH:mm:ss")+"\n";
    }
    //选择格式
    if(ui->text_recv_radioBtn->isChecked())
        data = QString(array);
    else if(ui->hex_recv_radioBtn->isChecked())
        data = QString(array.toHex());
    //重新输入文本
//    ui->recv_textBrowser->setPlainText(data);

    ui->recv_textBrowser->insertPlainText(data);
    //改变光标位置
//    QTextCursor cursor=ui->recv_textBrowser->textCursor();
//    cursor.movePosition(QTextCursor::End);
//    ui->recv_textBrowser->setTextCursor(cursor);

//    ui->recv_textBrowser->append(data);
    //统计
    ui->sRNumLabel->setNum(ui->sRNumLabel->text().toInt()+array.size());
}

void myserial::on_open_close_serial_Btn_clicked()
{
    if(!portIsOpen)
    {
        //获取选项
        ui->parity_comboBox->currentText();
        ui->stop_comboBox->currentText();
        ui->port_comboBox->currentText();
        ui->baudrate_comboBox->currentText();
        ui->databit_comboBox->currentText();

        //[1]配置串口
        mserial.setPortName(ui->port_comboBox->currentText());
        mserial.setBaudRate(selectBaudRate(ui->baudrate_comboBox->currentText()));
        mserial.setDataBits(selectDataBits(ui->databit_comboBox->currentText()));
        mserial.setParity(selectParityBits(ui->parity_comboBox->currentText()));
        mserial.setStopBits(selectStopBits(ui->stop_comboBox->currentText()));


        //[2]打开串口
        if(! mserial.open(QIODevice::ReadWrite))
        {
            qDebug() << " open port fail";
            QString tips=QString("端口打开失败！\n错误代码：%1").arg(mserial.error());
            QMessageBox::information(this,"错误提示",tips);
            return;
        }
        //[3] 建立与readyRead() 信号的槽函数
        connect(&mserial,&QSerialPort::readyRead,this,&myserial::read_data);
        //改变状态栏
        ui->stateLabel->setText("串口已打开");
        ui->stateLabel->setStyleSheet("color:rgb(30,230,50);");
        //关闭按钮
        ui->open_close_serial_Btn->setText("关闭串口");
        ui->open_close_serial_Btn->setStyleSheet("background-color:rgb(0,255,0);");
        //锁定状态
        ui->port_comboBox->setEnabled(false);
        ui->baudrate_comboBox->setEnabled(false);
        ui->databit_comboBox->setEnabled(false);
        ui->stop_comboBox->setEnabled(false);
        ui->parity_comboBox->setEnabled(false);

        ui->refreshBtn->setEnabled(false);
        ui->sendBtn->setEnabled(true);

        portIsOpen = true;

    }
    else
    {
        mserial.close();
        //状态栏
        ui->stateLabel->setText("串口未打开");
        ui->stateLabel->setStyleSheet("color:rgb(0,0,0);");
        //改变按钮
        ui->open_close_serial_Btn->setText("开启串口");
        ui->open_close_serial_Btn->setStyleSheet("background-color:rgb(255,0,0);");
        //锁定状态
        ui->port_comboBox->setEnabled(true);
        ui->baudrate_comboBox->setEnabled(true);
        ui->databit_comboBox->setEnabled(true);
        ui->stop_comboBox->setEnabled(true);
        ui->parity_comboBox->setEnabled(true);

        ui->refreshBtn->setEnabled(true);
        ui->sendBtn->setEnabled(false);

        portIsOpen=false;
    }
}




void myserial::on_refreshBtn_clicked()
{
    init();
}

bool myserial::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->send_textBrowser)
        {
            if(event->type() == QEvent::KeyPress)//回车键
            {
                 QKeyEvent *k = static_cast<QKeyEvent *>(event);
                 if(k->key() == Qt::Key_Return)
                 {
                     on_sendBtn_clicked();
                     return true;
                 }
            }
        }
        return QWidget::eventFilter(target,event);
 }

void myserial::on_sendBtn_clicked()
{
    if(autoSend == true)//自动发送检查
    {
        timer->start();
        return;
    }


    if(ui->send_textBrowser->document()->toPlainText() == "")//输入框内容为空判断
    {
        mserial.write("\n");
        return;
    }


    QString sendData = ui->send_textBrowser->document()->toPlainText();
    if(send_newline == true)//发送新行检查
    {
        sendData += "\n";
    }

    mserial.write(sendData.toUtf8()); //发送数据
    ui->sTNumLabel->setNum(ui->sTNumLabel->text().toInt()+sendData.size());
    ui->send_textBrowser->clear();

    ui->recv_textBrowser->moveCursor(QTextCursor::End); //复位浏览器

    return;

//    QByteArray sendData(ui->recv_textBrowser->toPlainText().toUtf8());
//    qDebug() << sendData;
//    if(ui->hex_send_radioBtn->isChecked())
//        sendData.toHex();
//    if(ui->send_newline_checkBox->isChecked())
//        sendData+="\n";
//    if(mserial.write(sendData))
//        ui->sTNumLabel->setNum(ui->sTNumLabel->text().toInt()+sendData.size());
//    else
//    {
//        QMessageBox::information(this,"错误提示","写入错误！");
//        return;
//    }

//    ui->recv_textBrowser->moveCursor(QTextCursor::End); //复位浏览器
}

void myserial::on_clear_send_Btn_clicked()
{
    ui->send_textBrowser->clear();
}

void myserial::on_clear_recvBtn_clicked()
{
    ui->recv_textBrowser->clear();
}


void myserial::on_sNumClearBtn_clicked()
{
    ui->sRNumLabel->setNum(0);
    ui->sTNumLabel->setNum(0);
}

void myserial::on_hex_recv_radioBtn_clicked()
{

}
