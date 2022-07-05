/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *NumLineEdit;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *TotalPriceLineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *calBtn;
    QLineEdit *PriceLineEdit;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *HexLineEdit;
    QLineEdit *DecLineEdit;
    QLineEdit *BinLineEdit;
    QPushButton *DecToBtn;
    QPushButton *BinToBtn;
    QPushButton *HexToBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 70, 581, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        NumLineEdit = new QLineEdit(verticalLayoutWidget);
        NumLineEdit->setObjectName("NumLineEdit");

        gridLayout->addWidget(NumLineEdit, 0, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        TotalPriceLineEdit = new QLineEdit(verticalLayoutWidget);
        TotalPriceLineEdit->setObjectName("TotalPriceLineEdit");

        gridLayout->addWidget(TotalPriceLineEdit, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 2, 1, 1);

        calBtn = new QPushButton(verticalLayoutWidget);
        calBtn->setObjectName("calBtn");

        gridLayout->addWidget(calBtn, 2, 1, 1, 1);

        PriceLineEdit = new QLineEdit(verticalLayoutWidget);
        PriceLineEdit->setObjectName("PriceLineEdit");

        gridLayout->addWidget(PriceLineEdit, 0, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        HexLineEdit = new QLineEdit(verticalLayoutWidget);
        HexLineEdit->setObjectName("HexLineEdit");

        gridLayout_2->addWidget(HexLineEdit, 2, 1, 1, 1);

        DecLineEdit = new QLineEdit(verticalLayoutWidget);
        DecLineEdit->setObjectName("DecLineEdit");

        gridLayout_2->addWidget(DecLineEdit, 0, 1, 1, 1);

        BinLineEdit = new QLineEdit(verticalLayoutWidget);
        BinLineEdit->setObjectName("BinLineEdit");

        gridLayout_2->addWidget(BinLineEdit, 1, 1, 1, 1);

        DecToBtn = new QPushButton(verticalLayoutWidget);
        DecToBtn->setObjectName("DecToBtn");

        gridLayout_2->addWidget(DecToBtn, 0, 2, 1, 1);

        BinToBtn = new QPushButton(verticalLayoutWidget);
        BinToBtn->setObjectName("BinToBtn");

        gridLayout_2->addWidget(BinToBtn, 1, 2, 1, 1);

        HexToBtn = new QPushButton(verticalLayoutWidget);
        HexToBtn->setObjectName("HexToBtn");

        gridLayout_2->addWidget(HexToBtn, 2, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 0, 1, 4);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\273\267", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\225\260\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", " \346\200\273\344\273\267", nullptr));
        calBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\215\201 \345\205\255 \350\277\233 \345\210\266", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\272\214 \350\277\233 \345\210\266", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\215\201 \350\277\233 \345\210\266", nullptr));
        DecToBtn->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        BinToBtn->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        HexToBtn->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242\344\270\272\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
