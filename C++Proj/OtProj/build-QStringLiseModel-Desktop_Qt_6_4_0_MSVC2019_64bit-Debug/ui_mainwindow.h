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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QPushButton *reviewListBtn;
    QPushButton *addItemBtn;
    QPushButton *insItemBtn;
    QPushButton *delCurItemBtn;
    QPushButton *clearList;
    QListView *listView;
    QGroupBox *groupBox_2;
    QPushButton *clearTextBtn;
    QPushButton *displayBtn;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(20, 10, 761, 531));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName("groupBox");
        reviewListBtn = new QPushButton(groupBox);
        reviewListBtn->setObjectName("reviewListBtn");
        reviewListBtn->setGeometry(QRect(20, 30, 75, 24));
        addItemBtn = new QPushButton(groupBox);
        addItemBtn->setObjectName("addItemBtn");
        addItemBtn->setGeometry(QRect(20, 70, 75, 24));
        insItemBtn = new QPushButton(groupBox);
        insItemBtn->setObjectName("insItemBtn");
        insItemBtn->setGeometry(QRect(110, 70, 75, 24));
        delCurItemBtn = new QPushButton(groupBox);
        delCurItemBtn->setObjectName("delCurItemBtn");
        delCurItemBtn->setGeometry(QRect(200, 70, 75, 24));
        clearList = new QPushButton(groupBox);
        clearList->setObjectName("clearList");
        clearList->setGeometry(QRect(290, 70, 75, 24));
        listView = new QListView(groupBox);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(20, 110, 341, 411));
        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName("groupBox_2");
        clearTextBtn = new QPushButton(groupBox_2);
        clearTextBtn->setObjectName("clearTextBtn");
        clearTextBtn->setGeometry(QRect(30, 30, 281, 24));
        displayBtn = new QPushButton(groupBox_2);
        displayBtn->setObjectName("displayBtn");
        displayBtn->setGeometry(QRect(30, 70, 281, 24));
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(20, 120, 311, 401));
        splitter->addWidget(groupBox_2);
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "QListView", nullptr));
        reviewListBtn->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215\345\210\227\350\241\250", nullptr));
        addItemBtn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
        insItemBtn->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
        delCurItemBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
        clearList->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "QPlainTextEidt", nullptr));
        clearTextBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        displayBtn->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\225\260\346\215\256\346\250\241\345\236\213\347\232\204StringList", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
