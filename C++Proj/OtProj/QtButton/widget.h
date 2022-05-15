#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
     QPushButton *btn;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
