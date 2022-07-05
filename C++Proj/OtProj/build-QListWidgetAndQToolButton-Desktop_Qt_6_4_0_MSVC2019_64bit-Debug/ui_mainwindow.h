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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actInitList;
    QAction *actClearList;
    QAction *actInsertItem;
    QAction *actAddItem;
    QAction *actDelCurItem;
    QAction *actSelectAll;
    QAction *actSelectNone;
    QAction *actSelectInvs;
    QAction *actQuit;
    QAction *actSelPopMenu;
    QWidget *centralwidget;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QToolButton *ListInitTbtn;
    QToolButton *ListClearTbtn;
    QToolButton *ListInsertTbtn;
    QToolButton *listAppendTbtn;
    QToolButton *listDelTbtn;
    QWidget *page_3;
    QWidget *page_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QToolButton *selectItemTbtn;
    QToolButton *selectAllTbtn;
    QToolButton *selectNoneTbtn;
    QToolButton *selectInvsTbtn;
    QWidget *tab_2;
    QTreeWidget *treeWidget;
    QWidget *tab_3;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actInitList = new QAction(MainWindow);
        actInitList->setObjectName("actInitList");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icon/initialization.png"), QSize(), QIcon::Normal, QIcon::Off);
        actInitList->setIcon(icon);
        actClearList = new QAction(MainWindow);
        actClearList->setObjectName("actClearList");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actClearList->setIcon(icon1);
        actInsertItem = new QAction(MainWindow);
        actInsertItem->setObjectName("actInsertItem");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Icon/insert.png"), QSize(), QIcon::Normal, QIcon::Off);
        actInsertItem->setIcon(icon2);
        actAddItem = new QAction(MainWindow);
        actAddItem->setObjectName("actAddItem");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actAddItem->setIcon(icon3);
        actDelCurItem = new QAction(MainWindow);
        actDelCurItem->setObjectName("actDelCurItem");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/Icon/delete-fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDelCurItem->setIcon(icon4);
        actSelectAll = new QAction(MainWindow);
        actSelectAll->setObjectName("actSelectAll");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Icon/select-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSelectAll->setIcon(icon5);
        actSelectNone = new QAction(MainWindow);
        actSelectNone->setObjectName("actSelectNone");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Icon/all_noselects.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSelectNone->setIcon(icon6);
        actSelectInvs = new QAction(MainWindow);
        actSelectInvs->setObjectName("actSelectInvs");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Icon/selectInvs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actSelectInvs->setIcon(icon7);
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName("actQuit");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/Icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon8);
        actSelPopMenu = new QAction(MainWindow);
        actSelPopMenu->setObjectName("actSelPopMenu");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(-10, 0, 801, 541));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName("toolBox");
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 284, 451));
        ListInitTbtn = new QToolButton(page);
        ListInitTbtn->setObjectName("ListInitTbtn");
        ListInitTbtn->setGeometry(QRect(30, 20, 151, 22));
        ListClearTbtn = new QToolButton(page);
        ListClearTbtn->setObjectName("ListClearTbtn");
        ListClearTbtn->setGeometry(QRect(30, 70, 151, 22));
        ListInsertTbtn = new QToolButton(page);
        ListInsertTbtn->setObjectName("ListInsertTbtn");
        ListInsertTbtn->setGeometry(QRect(30, 120, 151, 22));
        listAppendTbtn = new QToolButton(page);
        listAppendTbtn->setObjectName("listAppendTbtn");
        listAppendTbtn->setGeometry(QRect(30, 170, 151, 22));
        listDelTbtn = new QToolButton(page);
        listDelTbtn->setObjectName("listDelTbtn");
        listDelTbtn->setGeometry(QRect(30, 230, 151, 22));
        toolBox->addItem(page, QString::fromUtf8("QListWidget\346\223\215\344\275\234"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 284, 451));
        toolBox->addItem(page_3, QString::fromUtf8("QTreeWidget\346\223\215\344\275\234"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 284, 451));
        toolBox->addItem(page_2, QString::fromUtf8("QTableWidget\346\223\215\344\275\234"));
        splitter->addWidget(toolBox);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        listWidget = new QListWidget(tab);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setCheckState(Qt::Unchecked);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 180, 551, 331));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 61, 16));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 20, 201, 21));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(390, 20, 80, 20));
        selectItemTbtn = new QToolButton(tab);
        selectItemTbtn->setObjectName("selectItemTbtn");
        selectItemTbtn->setGeometry(QRect(30, 70, 161, 22));
        selectAllTbtn = new QToolButton(tab);
        selectAllTbtn->setObjectName("selectAllTbtn");
        selectAllTbtn->setGeometry(QRect(290, 70, 161, 22));
        selectNoneTbtn = new QToolButton(tab);
        selectNoneTbtn->setObjectName("selectNoneTbtn");
        selectNoneTbtn->setGeometry(QRect(30, 120, 161, 22));
        selectInvsTbtn = new QToolButton(tab);
        selectInvsTbtn->setObjectName("selectInvsTbtn");
        selectInvsTbtn->setGeometry(QRect(290, 120, 161, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 20, 551, 481));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableWidget = new QTableWidget(tab_3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 60, 501, 381));
        tabWidget->addTab(tab_3, QString());
        splitter->addWidget(tabWidget);
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
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        horizontalLayout = new QHBoxLayout(dockWidgetContents);
        horizontalLayout->setObjectName("horizontalLayout");
        treeWidget_2 = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName("treeWidget_2");

        horizontalLayout->addWidget(treeWidget_2);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        toolBar->addSeparator();
        toolBar->addAction(actClearList);
        toolBar->addAction(actInsertItem);
        toolBar->addAction(actAddItem);
        toolBar->addAction(actDelCurItem);
        toolBar->addAction(actInitList);
        toolBar->addAction(actSelectAll);
        toolBar->addAction(actSelectNone);
        toolBar->addAction(actSelectInvs);

        retranslateUi(MainWindow);
        QObject::connect(actSelPopMenu, &QAction::triggered, actSelectInvs, qOverload<>(&QAction::trigger));
        QObject::connect(actQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actInitList->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
        actClearList->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        actInsertItem->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
#if QT_CONFIG(tooltip)
        actInsertItem->setToolTip(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\351\241\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actAddItem->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
#if QT_CONFIG(tooltip)
        actAddItem->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\351\241\271", nullptr));
#endif // QT_CONFIG(tooltip)
        actDelCurItem->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
        actSelectAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        actSelectNone->setText(QCoreApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", nullptr));
        actSelectInvs->setText(QCoreApplication::translate("MainWindow", "\345\217\215\351\200\211", nullptr));
        actQuit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actSelPopMenu->setText(QCoreApplication::translate("MainWindow", "\351\241\271\351\200\211\346\213\251", nullptr));
        ListInitTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnListInit", nullptr));
        ListClearTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnListClear", nullptr));
        ListInsertTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnListInsert", nullptr));
        listAppendTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnListAppend", nullptr));
        listDelTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnListDelete", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "QTreeWidget\346\223\215\344\275\234", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "QTableWidget\346\223\215\344\275\234", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Item1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Item2", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\217\230\345\214\226\351\241\271", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\345\217\257\347\274\226\350\276\221", nullptr));
        selectItemTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnSelectItem", nullptr));
        selectAllTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnSelectAll", nullptr));
        selectNoneTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnSelectNone", nullptr));
        selectInvsTbtn->setText(QCoreApplication::translate("MainWindow", "tBtnSelectInvs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "QListWidet", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "QTreeWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "QTableWidget", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
