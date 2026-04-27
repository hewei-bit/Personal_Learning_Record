#include "filerecv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileRecv w;
    w.show();

    return a.exec();
}
