#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

    QPushButton* btn;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

//自定义槽函数
public slots:
    void print();
};
#endif // WIDGET_H
