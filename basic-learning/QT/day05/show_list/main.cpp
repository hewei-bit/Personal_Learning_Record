#include "show_list.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    show_list w;
    w.show();

    return a.exec();
}
