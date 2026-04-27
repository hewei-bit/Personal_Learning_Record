#include "v4l2client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    v4l2client w;
    w.show();

    return a.exec();
}
