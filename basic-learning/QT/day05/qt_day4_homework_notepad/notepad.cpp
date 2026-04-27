#include "notepad.h"
#include "ui_notepad.h"

#include <QFile>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QtDebug>
#include <QTextCursor>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    QLabel *msgLabel = new QLabel;

     msgLabel->setStyleSheet(" QLabel{ color: red }");



     msgLabel->setText("Ready :");

     ui->statusBar->addWidget(msgLabel); //在左边

     QLineEdit* e = new QLineEdit();
     QPushButton* b = new QPushButton("Button");


     ui->statusBar->addPermanentWidget(e);//放状态栏右边部分
     ui->statusBar->addPermanentWidget(b);
//    QIcon icon(":/pic/save.png");

//        ui->pushButton->setIconSize(QSize(ui->pushButton->width(),
//                                         ui->pushButton->height()));
      //  ui->pushButton->setIcon(icon);
    ui->plainTextEdit->setStyleSheet("background-image: url(:/pic/notpadbg.jpg);");
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionbackgroud_triggered()
{
       QColor color =  QColorDialog::getColor();
       QString style = QString("background-color: rgb(%1, %2, %3);")
               .arg(color.red())
               .arg(color.green())
               .arg(color.blue());
       ui->plainTextEdit->setStyleSheet(style);
}

void Notepad::on_actionopen_triggered()
{
      QString filePath =   QFileDialog::getOpenFileName(this);

      //打开文件
      QFile file(filePath);

     if(!file.open(QIODevice::ReadWrite))
         return;

     QByteArray  data = file.readAll();

     ui->plainTextEdit->setPlainText(data);
    ui->statusBar->showMessage(QString::number(data.size()));
     file.close();
}

void Notepad::on_actionsave_triggered()
{

}

void Notepad::on_actionfont_triggered()
{
    bool ok;
  QFont font =  QFontDialog::getFont(&ok,this);
  ui->plainTextEdit->setFont(font);
  if(ok)
  {

  }
}

void Notepad::on_actionabout_notepad_triggered()
{

}

void Notepad::on_plainTextEdit_cursorPositionChanged()
{
           QPoint ponit;
      QTextCursor cursor = ui->plainTextEdit->cursorForPosition(ponit);
    qDebug() <<  cursor.position();
     //qDebug() <<  ponit.x() << ponit.y();

}
