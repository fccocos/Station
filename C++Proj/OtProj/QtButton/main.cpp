#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(600,400);
    w.setWindowTitle("hello qt");
    w.show();
    return a.exec();
}
