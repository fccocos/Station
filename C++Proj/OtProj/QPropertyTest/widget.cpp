#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMetaClassInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    showWidgetsInWidget();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showWidgetsInWidget()
{
    qbtn = new QPushButton(this);
    QObject *object = qbtn;
    qbtn->setProperty("flat", true);
    qDebug() << "QPushButton::Flat"<<object->property("flat").toBool();
    qDebug()<<"classInfo Number:"<<this->metaObject()->classInfoCount();
    for(int i = 0; i<this->metaObject()->classInfoCount(); i++)
    {
        QMetaClassInfo qmcinfo = this->metaObject()->classInfo(i);
        qDebug() << "classInof["<<i<<"]: "<<qmcinfo.name()<<"——"<<qmcinfo.value();
    }


}
