#include "qwmianwind.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWMianWind w;
    w.show();
    return a.exec();
}
