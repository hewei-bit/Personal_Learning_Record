#include "linkgame.h"
#include "ui_linkgame.h"
#include <QtDebug>
LinkGame::LinkGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LinkGame)
{
    ui->setupUi(this);

    //初始化界面
    int i = 1;
    for (int y=0;y<4;y++) {
        for (int x=0;x<4;x++) {
            //将代码中创建的按钮跟UI文件窗口关联起来
            buttons[y][x] = new QPushButton(this->centralWidget());
            buttons[y][x]->resize(75,75); //设置控件的大小
            buttons[y][x]->move(100+x*75,100+y*75); //设置控件的位置
            buttons[y][x]->setIconSize(QSize(75,75));
            QString iconPath = QString(":/pic/image%1.png")
                    .arg(i++);
            buttons[y][x]->setIcon(QIcon(iconPath));

            //建立信号和槽
            connect(buttons[y][x],&QPushButton::clicked,this,&LinkGame::buttonClicked);
        }
    }
}

LinkGame::~LinkGame()
{
    delete ui;
}

//多个对象对应于一个槽函数
void LinkGame::buttonClicked()
{
    qDebug() << "buttonClicked ";
    //在QT中，通过sender()函数。来返回信号的发送者指针，返回的类型是QObject*
    //sender() const : QObject *
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    static QPushButton* lastButton = nullptr;
    //如果没有保存过上次的点击按钮，说明这是第一次点击按钮，保存本次按钮为后面做准备
    if(nullptr == lastButton)
    {
        lastButton = button;
    }else {

        //如果满足游戏规则，才消除游戏
       // if() //如果可以消除则消除
       // {

            lastButton->hide(); //第一次点击的按钮
            button->hide(); //第二次点击的按钮
      //  }


        lastButton = nullptr;
    }

}
