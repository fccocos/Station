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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actAddFolder;
    QAction *actAddFile;
    QAction *actZoomIn;
    QAction *actZoomOut;
    QAction *actZoomRealSize;
    QAction *actZoomFitW;
    QAction *actZoomFitH;
    QAction *actDelNode;
    QAction *actQuit;
    QAction *actScanNode;
    QAction *actDockVisible;
    QAction *actDockFloat;
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QTreeWidget *treeWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1011, 624);
        actAddFolder = new QAction(MainWindow);
        actAddFolder->setObjectName("actAddFolder");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Icon/addFloder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAddFolder->setIcon(icon);
        actAddFile = new QAction(MainWindow);
        actAddFile->setObjectName("actAddFile");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Icon/newfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAddFile->setIcon(icon1);
        actZoomIn = new QAction(MainWindow);
        actZoomIn->setObjectName("actZoomIn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Icon/zoom in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomIn->setIcon(icon2);
        actZoomOut = new QAction(MainWindow);
        actZoomOut->setObjectName("actZoomOut");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Icon/zoom out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomOut->setIcon(icon3);
        actZoomRealSize = new QAction(MainWindow);
        actZoomRealSize->setObjectName("actZoomRealSize");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/Icon/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomRealSize->setIcon(icon4);
        actZoomFitW = new QAction(MainWindow);
        actZoomFitW->setObjectName("actZoomFitW");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Icon/fit-width.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomFitW->setIcon(icon5);
        actZoomFitH = new QAction(MainWindow);
        actZoomFitH->setObjectName("actZoomFitH");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Icon/fit-height.png"), QSize(), QIcon::Normal, QIcon::Off);
        actZoomFitH->setIcon(icon6);
        actDelNode = new QAction(MainWindow);
        actDelNode->setObjectName("actDelNode");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Icon/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDelNode->setIcon(icon7);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName("actQuit");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/Icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon8);
        actScanNode = new QAction(MainWindow);
        actScanNode->setObjectName("actScanNode");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/Icon/scan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actScanNode->setIcon(icon9);
        actDockVisible = new QAction(MainWindow);
        actDockVisible->setObjectName("actDockVisible");
        actDockVisible->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/Icon/visible.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDockVisible->setIcon(icon10);
        actDockFloat = new QAction(MainWindow);
        actDockFloat->setObjectName("actDockFloat");
        actDockFloat->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/Icon/Float.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDockFloat->setIcon(icon11);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 621, 521));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 619, 519));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 591, 501));
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1011, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setMinimumSize(QSize(338, 45));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        treeWidget = new QTreeWidget(dockWidgetContents);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(0, 0, 331, 491));
        treeWidget->setMinimumSize(QSize(331, 0));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        toolBar->addAction(actAddFolder);
        toolBar->addAction(actAddFile);
        toolBar->addAction(actZoomIn);
        toolBar->addAction(actZoomOut);
        toolBar->addAction(actZoomRealSize);
        toolBar->addAction(actZoomFitW);
        toolBar->addAction(actZoomFitH);
        toolBar->addAction(actDelNode);
        toolBar->addAction(actQuit);
        toolBar->addAction(actScanNode);
        toolBar->addAction(actDockVisible);
        toolBar->addAction(actDockFloat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actAddFolder->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\233\256\345\275\225...", nullptr));
        actAddFile->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266...", nullptr));
        actZoomIn->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
        actZoomOut->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
        actZoomRealSize->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\345\244\247\345\260\217", nullptr));
        actZoomFitW->setText(QCoreApplication::translate("MainWindow", "\345\220\210\351\200\202\345\256\275\345\272\246", nullptr));
        actZoomFitH->setText(QCoreApplication::translate("MainWindow", "\345\220\210\351\200\202\351\253\230\345\272\246", nullptr));
        actDelNode->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actScanNode->setText(QCoreApplication::translate("MainWindow", "\351\201\215\345\216\206\350\212\202\347\202\271", nullptr));
        actDockVisible->setText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\345\217\257\350\247\201", nullptr));
        actDockFloat->setText(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223\346\265\256\345\212\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
