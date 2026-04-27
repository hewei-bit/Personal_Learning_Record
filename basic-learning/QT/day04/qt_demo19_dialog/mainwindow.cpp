#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
#include <QtDebug>
#include <QColorDialog>
#include <QInputDialog>
#include <QDir>
#include <QLineEdit>
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

//输入修改的内容
void MainWindow::on_conentBtn_clicked()
{
    bool ok;
     QString text = QInputDialog::getText(this, tr("修改内容"),
                                          tr("请输入:"), QLineEdit::Normal,
                                          QDir::home().dirName(), &ok);
     if (ok && !text.isEmpty())
         ui->label->setText(text);
}

//背景颜色设置
void MainWindow::on_backgroudBtn_clicked()
{

   // QColor
   // getColor(const QColor &initial = Qt::white, QWidget *parent = nullptr, const QString &title = QString(), QColorDialog::ColorDialogOptions options = ColorDialogOptions())

    QColor color = QColorDialog::getColor();
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    QString style = QString("background-color: rgb(%1, %2, %3);")
            .arg(red).arg(green).arg(blue);
    ui->label->setStyleSheet(style);

}

//字体设置
void MainWindow::on_fontsetBtn_clicked()
{
    //
    bool ok;
   QFont font =  QFontDialog::getFont(&ok,QFont("Helvetica [Cronyx]", 10),this,"哈哈");
   //this代表当前对话框显示在那个窗口上
   ui->label->setFont(font);
   if(ok)
   {
       qDebug() << font.toString();
   }else {
        qDebug() << ok;
   }
}
