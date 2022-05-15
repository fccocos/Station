#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "sonwidget.h"
#include <QtDebug>

class Widget : public QWidget
{
    Q_OBJECT
    QPushButton * btn;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    SonWidget* sonWidget;
public slots:
    void covert();
    void signal_cb(int a);
};
#endif // WIDGET_H
