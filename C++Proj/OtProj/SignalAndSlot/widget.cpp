#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
       //创建一个按钮 点击按钮关闭窗口
    QPushButton *p = new QPushButton("关闭",this);
    p->move(100,100);
    //设置连结 点击按钮产生信号 会调用窗口的close函数
    //param1: 信号的发送者
    //param2: 发送的信号
    //param3: 信号接收者
    //param4: 接收者的槽函数
    connect(p,&QPushButton::clicked,this,&QWidget::close);
}

Widget::~Widget()
{
}

