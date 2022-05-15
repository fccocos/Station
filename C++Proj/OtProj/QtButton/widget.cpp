#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
     btn = new QPushButton();
    //btn = new QPushButton(this);//构造函数时 指定父对象

    // 如果不给按钮指定父类对象，那么按钮和窗口时单独显示 如果给按钮指定了父对象
    //只要父对象显示了，按钮也会显示
    btn->show();
    btn->setParent(this);//指定按钮的父亲是窗口
    btn->setText("登录");

    //上述代码等价于
    // btn = new QPushButton("登入",this);//构造函数时，指定父对象和设置文本
    btn->resize(100,50);//设置按钮的大小
    btn->move(100,100);
}

Widget::~Widget()
{
}

