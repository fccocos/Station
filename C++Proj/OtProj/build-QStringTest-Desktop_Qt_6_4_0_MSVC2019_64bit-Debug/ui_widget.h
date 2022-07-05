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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *str1ComboBox;
    QComboBox *Str2ComboBox;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *leftBtn;
    QPushButton *toUpperBtn;
    QPushButton *prependBtn;
    QPushButton *rightBtn;
    QPushButton *toLowerBtn;
    QPushButton *AppendBtn;
    QPushButton *sectionBtn;
    QPushButton *simpifiedBtn;
    QPushButton *trimmedBtn;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *sizeBtn;
    QPushButton *countBtn;
    QPushButton *indexOfBtn;
    QPushButton *lastIndexOfBtn;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *endsWidthBtn;
    QPushButton *startsWidth;
    QPushButton *isNullBtn;
    QPushButton *isEmpty;
    QPushButton *containsBtn;
    QLabel *label_3;
    QLineEdit *resultLineEdit;
    QCheckBox *containsCheckBox;
    QSpinBox *countSpinBox;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 21, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 21, 16));
        str1ComboBox = new QComboBox(Widget);
        str1ComboBox->setObjectName("str1ComboBox");
        str1ComboBox->setGeometry(QRect(50, 20, 641, 22));
        str1ComboBox->setEditable(true);
        Str2ComboBox = new QComboBox(Widget);
        Str2ComboBox->setObjectName("Str2ComboBox");
        Str2ComboBox->setGeometry(QRect(50, 50, 641, 22));
        Str2ComboBox->setEditable(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 100, 211, 231));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 211, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leftBtn = new QPushButton(gridLayoutWidget);
        leftBtn->setObjectName("leftBtn");

        gridLayout->addWidget(leftBtn, 2, 0, 1, 1);

        toUpperBtn = new QPushButton(gridLayoutWidget);
        toUpperBtn->setObjectName("toUpperBtn");

        gridLayout->addWidget(toUpperBtn, 1, 0, 1, 1);

        prependBtn = new QPushButton(gridLayoutWidget);
        prependBtn->setObjectName("prependBtn");

        gridLayout->addWidget(prependBtn, 0, 1, 1, 1);

        rightBtn = new QPushButton(gridLayoutWidget);
        rightBtn->setObjectName("rightBtn");

        gridLayout->addWidget(rightBtn, 2, 1, 1, 1);

        toLowerBtn = new QPushButton(gridLayoutWidget);
        toLowerBtn->setObjectName("toLowerBtn");

        gridLayout->addWidget(toLowerBtn, 1, 1, 1, 1);

        AppendBtn = new QPushButton(gridLayoutWidget);
        AppendBtn->setObjectName("AppendBtn");

        gridLayout->addWidget(AppendBtn, 0, 0, 1, 1);

        sectionBtn = new QPushButton(gridLayoutWidget);
        sectionBtn->setObjectName("sectionBtn");

        gridLayout->addWidget(sectionBtn, 3, 1, 1, 1);

        simpifiedBtn = new QPushButton(gridLayoutWidget);
        simpifiedBtn->setObjectName("simpifiedBtn");

        gridLayout->addWidget(simpifiedBtn, 4, 0, 1, 1);

        trimmedBtn = new QPushButton(gridLayoutWidget);
        trimmedBtn->setObjectName("trimmedBtn");

        gridLayout->addWidget(trimmedBtn, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(260, 100, 101, 231));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 81, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sizeBtn = new QPushButton(verticalLayoutWidget);
        sizeBtn->setObjectName("sizeBtn");

        verticalLayout->addWidget(sizeBtn);

        countBtn = new QPushButton(verticalLayoutWidget);
        countBtn->setObjectName("countBtn");

        verticalLayout->addWidget(countBtn);

        indexOfBtn = new QPushButton(verticalLayoutWidget);
        indexOfBtn->setObjectName("indexOfBtn");

        verticalLayout->addWidget(indexOfBtn);

        lastIndexOfBtn = new QPushButton(verticalLayoutWidget);
        lastIndexOfBtn->setObjectName("lastIndexOfBtn");

        verticalLayout->addWidget(lastIndexOfBtn);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(390, 100, 221, 231));
        gridLayoutWidget_2 = new QWidget(groupBox_3);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 10, 221, 221));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        endsWidthBtn = new QPushButton(gridLayoutWidget_2);
        endsWidthBtn->setObjectName("endsWidthBtn");

        gridLayout_2->addWidget(endsWidthBtn, 0, 0, 1, 1);

        startsWidth = new QPushButton(gridLayoutWidget_2);
        startsWidth->setObjectName("startsWidth");

        gridLayout_2->addWidget(startsWidth, 0, 1, 1, 1);

        isNullBtn = new QPushButton(gridLayoutWidget_2);
        isNullBtn->setObjectName("isNullBtn");

        gridLayout_2->addWidget(isNullBtn, 3, 0, 1, 1);

        isEmpty = new QPushButton(gridLayoutWidget_2);
        isEmpty->setObjectName("isEmpty");

        gridLayout_2->addWidget(isEmpty, 3, 1, 1, 1);

        containsBtn = new QPushButton(gridLayoutWidget_2);
        containsBtn->setObjectName("containsBtn");

        gridLayout_2->addWidget(containsBtn, 2, 1, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 390, 53, 16));
        resultLineEdit = new QLineEdit(Widget);
        resultLineEdit->setObjectName("resultLineEdit");
        resultLineEdit->setGeometry(QRect(70, 390, 621, 21));
        containsCheckBox = new QCheckBox(Widget);
        containsCheckBox->setObjectName("containsCheckBox");
        containsCheckBox->setGeometry(QRect(40, 430, 80, 20));
        countSpinBox = new QSpinBox(Widget);
        countSpinBox->setObjectName("countSpinBox");
        countSpinBox->setGeometry(QRect(551, 430, 141, 22));
        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(500, 430, 41, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "str1", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "str2", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\345\255\227\347\254\246\344\270\262", nullptr));
        leftBtn->setText(QCoreApplication::translate("Widget", "left", nullptr));
        toUpperBtn->setText(QCoreApplication::translate("Widget", "toUpper", nullptr));
        prependBtn->setText(QCoreApplication::translate("Widget", "Prepend", nullptr));
        rightBtn->setText(QCoreApplication::translate("Widget", "right", nullptr));
        toLowerBtn->setText(QCoreApplication::translate("Widget", "toLower", nullptr));
        AppendBtn->setText(QCoreApplication::translate("Widget", "Append", nullptr));
        sectionBtn->setText(QCoreApplication::translate("Widget", "section", nullptr));
        simpifiedBtn->setText(QCoreApplication::translate("Widget", "simpified", nullptr));
        trimmedBtn->setText(QCoreApplication::translate("Widget", "trimmed", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\346\225\260\345\255\227", nullptr));
        sizeBtn->setText(QCoreApplication::translate("Widget", "size", nullptr));
        countBtn->setText(QCoreApplication::translate("Widget", "count", nullptr));
        indexOfBtn->setText(QCoreApplication::translate("Widget", "indexOf", nullptr));
        lastIndexOfBtn->setText(QCoreApplication::translate("Widget", "lasIndexOf", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\351\200\273\350\276\221\345\210\244\346\226\255", nullptr));
        endsWidthBtn->setText(QCoreApplication::translate("Widget", "endsWidth", nullptr));
        startsWidth->setText(QCoreApplication::translate("Widget", "startsWidth", nullptr));
        isNullBtn->setText(QCoreApplication::translate("Widget", "isNull", nullptr));
        isEmpty->setText(QCoreApplication::translate("Widget", "isEmpty", nullptr));
        containsBtn->setText(QCoreApplication::translate("Widget", "contains", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\273\223\346\236\234", nullptr));
        containsCheckBox->setText(QCoreApplication::translate("Widget", "contains", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "count()", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
