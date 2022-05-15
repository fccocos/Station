#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
       btn = new QPushButton();
       btn ->setParent(this);
       btn->setText("打印(print)");
       //注册信号与槽的连接
       connect(btn,&QPushButton::pressed,this,&Widget::print);
}

Widget::~Widget()
{
}

void Widget::print()
{
    qDebug()<<"Qt是嵌入式的界面应用之一";
}
