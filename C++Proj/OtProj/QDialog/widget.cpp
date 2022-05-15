#include "widget.h"
#include <QAction>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    static Widget* that = this;//将this指针全局化
    btn = new QPushButton("打开一个模态对话框", this);
    btn->move(200,100);
    connect(btn,&QPushButton::clicked,this,[]{
        QDialog* dialog = new QDialog();
        dialog->setWindowTitle(tr("Hello,dialog"));
        dialog->exec();
    });

    btn1 = new QPushButton("打开一个非模态对话框", this);
    btn1->move(200,50);
    connect(btn1,&QPushButton::clicked,this,[]{
        QDialog* dialog = new QDialog();
        dialog->setAttribute(Qt::WA_DeleteOnClose);//关闭窗口自动释放
        dialog->setWindowTitle(tr("Hello,dialog"));
        dialog->show();
    });

}

Widget::~Widget()
{
}

