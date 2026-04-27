#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_Btn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this);
    qDebug() << filename;
    //打开文件
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "fopen err!";
        QString failtips = QString("open %1 failure").arg(filename);
        QMessageBox::warning(this,"tips",failtips);
        return ;
    }
    //读取文件
    QByteArray array = file.readAll();
    //显示文件内容到控件上
    ui->textEdit->setPlainText(array);
    //关闭文件
    file.close();

}

void MainWindow::on_save_Btn_clicked()
{
    QString saveFileName = QFileDialog::getSaveFileName(this);
    QFile file(saveFileName);
    //打开文件
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "fopen err!";
        QString failtips = QString("open %1 failure").arg(saveFileName);
        QMessageBox::warning(this,"tips",failtips);
        return ;
    }
    //得到UI组建上的内容
    QString data = ui->textEdit->toPlainText();

    //将数据写入文件
    file.write(data.toUtf8());

    //QString 转换成 QByteArray

    //关闭文件
    file.close();
}

void MainWindow::on_set_font_Btn_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica",14),this,"setFont");
    ui->textEdit->setFont(font);
    if (ok) {
        // font is set to the font the user selected
        qDebug() << font.toString();
    } else {
        // the user canceled the dialog; font is set to the default
        // application font, QApplication::font()
        qDebug() << ok;
    }
}

void MainWindow::on_set_background_Btn_clicked()
{
    QColor color = QColorDialog::getColor();
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    QString style = QString("background-color: rgb(%1, %2, %3);")
            .arg(red).arg(green).arg(blue);
    ui->textEdit->setStyleSheet(style);

}
