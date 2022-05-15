#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"点击了鼠标,坐标("<<event->x()<<","<<event->y()<<")";
    if(event->button() == Qt::LeftButton)
        qDebug()<<"点击了鼠标左键";
    if(event->button() == Qt::RightButton)
        qDebug()<<"点击了鼠标右键";
    if(event->button() == Qt::MidButton)
        qDebug()<<"点击了鼠标中建";
    if(event->button() == Qt::BackButton)
        qDebug()<<"点击了鼠标后键";
    if(event->button() == Qt::TaskButton)
        qDebug()<<"点击了鼠标得到";
}
