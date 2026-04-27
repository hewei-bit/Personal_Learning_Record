#include "filesend.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileSend w;
    w.show();

    return a.exec();
}
