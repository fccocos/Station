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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actFileOpen;
    QAction *actFileSaveAs;
    QAction *actModelDataPreview;
    QAction *actAddLine;
    QAction *actInsLine;
    QAction *actDelLine;
    QAction *actLeft;
    QAction *actRight;
    QAction *actCenter;
    QAction *actBold;
    QAction *actQuit;
    QWidget *centralwidget;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actFileOpen = new QAction(MainWindow);
        actFileOpen->setObjectName("actFileOpen");
        actFileSaveAs = new QAction(MainWindow);
        actFileSaveAs->setObjectName("actFileSaveAs");
        actModelDataPreview = new QAction(MainWindow);
        actModelDataPreview->setObjectName("actModelDataPreview");
        actAddLine = new QAction(MainWindow);
        actAddLine->setObjectName("actAddLine");
        actInsLine = new QAction(MainWindow);
        actInsLine->setObjectName("actInsLine");
        actDelLine = new QAction(MainWindow);
        actDelLine->setObjectName("actDelLine");
        actLeft = new QAction(MainWindow);
        actLeft->setObjectName("actLeft");
        actRight = new QAction(MainWindow);
        actRight->setObjectName("actRight");
        actCenter = new QAction(MainWindow);
        actCenter->setObjectName("actCenter");
        actBold = new QAction(MainWindow);
        actBold->setObjectName("actBold");
        actBold->setCheckable(true);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName("actQuit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(0, 0, 791, 531));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName("groupBox");
        tableView = new QTableView(groupBox);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 20, 371, 501));
        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName("groupBox_2");
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 20, 371, 501));
        splitter->addWidget(groupBox_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actFileOpen);
        toolBar->addAction(actFileSaveAs);
        toolBar->addAction(actModelDataPreview);
        toolBar->addAction(actAddLine);
        toolBar->addAction(actInsLine);
        toolBar->addAction(actDelLine);
        toolBar->addAction(actLeft);
        toolBar->addAction(actRight);
        toolBar->addAction(actCenter);
        toolBar->addAction(actBold);
        toolBar->addAction(actQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actFileOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        actFileSaveAs->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\346\226\207\344\273\266", nullptr));
        actModelDataPreview->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\236\213\346\225\260\346\215\256\351\242\204\350\247\210", nullptr));
        actAddLine->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245\350\241\214", nullptr));
        actInsLine->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\241\214", nullptr));
        actDelLine->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\214", nullptr));
        actLeft->setText(QCoreApplication::translate("MainWindow", "\345\261\205\345\267\246", nullptr));
        actRight->setText(QCoreApplication::translate("MainWindow", "\345\261\205\345\217\263", nullptr));
        actCenter->setText(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255", nullptr));
        actBold->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "TableView", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "PlainTextEdit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
