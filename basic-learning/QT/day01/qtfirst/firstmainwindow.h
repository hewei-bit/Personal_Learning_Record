#ifndef FIRSTMAINWINDOW_H
#define FIRSTMAINWINDOW_H

#include <QMainWindow>

//namespace Ui {
//class FirstMainWindow;
//}

namespace Ui {
    class MainWindow;
}
//假如一个项目从另外一个项目修改过来，那么UI界面要替换成其他需求界面，但是逻辑代码
//大多数是相同的
class FirstMainWindow : public QMainWindow //继承于QT中的类（窗口类）
{
    Q_OBJECT //元对象宏

public:
    explicit FirstMainWindow(QWidget *parent = nullptr);
    ~FirstMainWindow();

private:
    //Ui::FirstMainWindow *ui; //ui界面的一个指针
    Ui::MainWindow* ui; //指针通常在构造函数初始化列表中进行
};

#endif // FIRSTMAINWINDOW_H
