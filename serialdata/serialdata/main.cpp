#include "serialgetdata.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialGetData w;
    w.show();
    return a.exec();
}
