/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *RHSlider;
    QSlider *GHSlider;
    QSlider *BHSlider;
    QSlider *AHSlider;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        RHSlider = new QSlider(Widget);
        RHSlider->setObjectName("RHSlider");
        RHSlider->setGeometry(QRect(100, 70, 160, 22));
        RHSlider->setOrientation(Qt::Horizontal);
        GHSlider = new QSlider(Widget);
        GHSlider->setObjectName("GHSlider");
        GHSlider->setGeometry(QRect(100, 120, 160, 22));
        GHSlider->setOrientation(Qt::Horizontal);
        BHSlider = new QSlider(Widget);
        BHSlider->setObjectName("BHSlider");
        BHSlider->setGeometry(QRect(100, 170, 160, 22));
        BHSlider->setOrientation(Qt::Horizontal);
        AHSlider = new QSlider(Widget);
        AHSlider->setObjectName("AHSlider");
        AHSlider->setGeometry(QRect(100, 220, 160, 22));
        AHSlider->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(340, 70, 271, 161));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 53, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 120, 53, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 170, 53, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 220, 53, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "R", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "G", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "B", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
