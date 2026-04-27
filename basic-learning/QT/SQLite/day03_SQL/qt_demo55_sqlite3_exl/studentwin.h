#ifndef STUDENTWIN_H
#define STUDENTWIN_H

#include <QMainWindow>
#include <sqlite3.h>

namespace Ui {
class StudentWin;
}

class StudentWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWin(QWidget *parent = nullptr);
    ~StudentWin();
    //思路一：全局函数做为类的友元
    friend int callback(void* data ,int col,char** value,char** name);
   //int callback(void* data ,int col,char** value,char** name);
   //int callback(void* data ,int col,char* value[],char* name[])
    //思路二：在类中声明一个全局的函数
    static void updateStudentInfo(QStringList students);
    //思路三 使用QT中的接口函数：应用程序::获取当前活动的窗口---> QWidget*,
    //再将它转换成当前界面类--QWidget* QApplication::activeWindow()
private slots:
    void on_selectBtn_clicked();

    void on_addBtn_clicked();

private:
    Ui::StudentWin *ui;
    sqlite3 *db = nullptr;
    int test;
};

#endif // STUDENTWIN_H
