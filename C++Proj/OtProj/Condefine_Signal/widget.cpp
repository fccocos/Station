#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->sonWidget = new SonWidget;
    sonWidget->show();
    sonWidget->setWindowTitle("son");
    //sonWidget->setParent(this);
    btn = new QPushButton("隐藏父窗口 显示子窗口",this);
    btn->move(300,200);
    connect(btn,&QPushButton::clicked,this,&Widget::covert);
    connect(sonWidget,&SonWidget::show_hide_signal, this, &Widget::signal_cb);
}

Widget::~Widget()
{
}
void Widget::covert()
{
    sonWidget->show();
    this->hide();
}
void Widget::signal_cb(int a)
{
    qDebug()<<a;
    sonWidget->hide();
    this->show();
}
