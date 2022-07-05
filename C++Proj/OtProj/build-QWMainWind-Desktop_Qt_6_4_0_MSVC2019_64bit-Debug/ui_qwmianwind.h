/********************************************************************************
** Form generated from reading UI file 'qwmianwind.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWMIANWIND_H
#define UI_QWMIANWIND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWMianWind
{
public:
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actBold;
    QAction *actItalic;
    QAction *actUnderline;
    QAction *actExit;
    QAction *actFileOpen;
    QAction *actFileOpen_2;
    QAction *actClear;
    QAction *action;
    QAction *actToolbarLab;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QWMianWind)
    {
        if (QWMianWind->objectName().isEmpty())
            QWMianWind->setObjectName("QWMianWind");
        QWMianWind->resize(800, 600);
        actCut = new QAction(QWMianWind);
        actCut->setObjectName("actCut");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Icon/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon);
        actCopy = new QAction(QWMianWind);
        actCopy->setObjectName("actCopy");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Icon/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon1);
        actPaste = new QAction(QWMianWind);
        actPaste->setObjectName("actPaste");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Icon/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon2);
        actBold = new QAction(QWMianWind);
        actBold->setObjectName("actBold");
        actBold->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Icon/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actBold->setIcon(icon3);
        actItalic = new QAction(QWMianWind);
        actItalic->setObjectName("actItalic");
        actItalic->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/Icon/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actItalic->setIcon(icon4);
        actUnderline = new QAction(QWMianWind);
        actUnderline->setObjectName("actUnderline");
        actUnderline->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Icon/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actUnderline->setIcon(icon5);
        actExit = new QAction(QWMianWind);
        actExit->setObjectName("actExit");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon6);
        actFileOpen = new QAction(QWMianWind);
        actFileOpen->setObjectName("actFileOpen");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/Icon/openfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFileOpen->setIcon(icon7);
        actFileOpen_2 = new QAction(QWMianWind);
        actFileOpen_2->setObjectName("actFileOpen_2");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/Icon/newfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actFileOpen_2->setIcon(icon8);
        actClear = new QAction(QWMianWind);
        actClear->setObjectName("actClear");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/Icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon9);
        action = new QAction(QWMianWind);
        action->setObjectName("action");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/Icon/fontset.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon10);
        actToolbarLab = new QAction(QWMianWind);
        actToolbarLab->setObjectName("actToolbarLab");
        actToolbarLab->setCheckable(true);
        centralwidget = new QWidget(QWMianWind);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 20, 751, 501));
        QWMianWind->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QWMianWind);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        QWMianWind->setMenuBar(menubar);
        statusbar = new QStatusBar(QWMianWind);
        statusbar->setObjectName("statusbar");
        QWMianWind->setStatusBar(statusbar);
        toolBar = new QToolBar(QWMianWind);
        toolBar->setObjectName("toolBar");
        QWMianWind->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actFileOpen_2);
        menu->addAction(actFileOpen);
        menu->addSeparator();
        menu->addAction(actExit);
        menu_2->addAction(actCut);
        menu_2->addAction(actPaste);
        menu_2->addAction(actCopy);
        menu_2->addSeparator();
        menu_2->addAction(actClear);
        menu_3->addAction(actBold);
        menu_3->addAction(actItalic);
        menu_3->addAction(actUnderline);
        menu_3->addSeparator();
        menu_3->addAction(actToolbarLab);
        toolBar->addAction(actFileOpen_2);
        toolBar->addAction(actFileOpen);
        toolBar->addAction(actExit);
        toolBar->addAction(actCopy);
        toolBar->addAction(actCut);
        toolBar->addAction(actPaste);
        toolBar->addAction(actClear);
        toolBar->addAction(actBold);
        toolBar->addAction(actItalic);
        toolBar->addAction(actUnderline);
        toolBar->addAction(action);

        retranslateUi(QWMianWind);
        QObject::connect(actCut, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::cut));
        QObject::connect(actCopy, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::copy));
        QObject::connect(actPaste, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::paste));
        QObject::connect(actClear, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::clear));
        QObject::connect(actExit, &QAction::triggered, QWMianWind, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(QWMianWind);
    } // setupUi

    void retranslateUi(QMainWindow *QWMianWind)
    {
        QWMianWind->setWindowTitle(QCoreApplication::translate("QWMianWind", "QWMianWind", nullptr));
        actCut->setText(QCoreApplication::translate("QWMianWind", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        actCut->setToolTip(QCoreApplication::translate("QWMianWind", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("QWMianWind", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actCopy->setText(QCoreApplication::translate("QWMianWind", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        actCopy->setToolTip(QCoreApplication::translate("QWMianWind", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCopy->setShortcut(QCoreApplication::translate("QWMianWind", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actPaste->setText(QCoreApplication::translate("QWMianWind", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        actPaste->setToolTip(QCoreApplication::translate("QWMianWind", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actPaste->setShortcut(QCoreApplication::translate("QWMianWind", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actBold->setText(QCoreApplication::translate("QWMianWind", "\347\262\227\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actBold->setToolTip(QCoreApplication::translate("QWMianWind", "\347\262\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actItalic->setText(QCoreApplication::translate("QWMianWind", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actItalic->setToolTip(QCoreApplication::translate("QWMianWind", "\346\226\234\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actUnderline->setText(QCoreApplication::translate("QWMianWind", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        actUnderline->setToolTip(QCoreApplication::translate("QWMianWind", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actExit->setText(QCoreApplication::translate("QWMianWind", "\351\200\200\345\207\272", nullptr));
        actFileOpen->setText(QCoreApplication::translate("QWMianWind", "\346\211\223\345\274\200...", nullptr));
#if QT_CONFIG(tooltip)
        actFileOpen->setToolTip(QCoreApplication::translate("QWMianWind", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFileOpen->setShortcut(QCoreApplication::translate("QWMianWind", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actFileOpen_2->setText(QCoreApplication::translate("QWMianWind", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        actFileOpen_2->setToolTip(QCoreApplication::translate("QWMianWind", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actFileOpen_2->setShortcut(QCoreApplication::translate("QWMianWind", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actClear->setText(QCoreApplication::translate("QWMianWind", "\346\270\205\347\251\272", nullptr));
#if QT_CONFIG(tooltip)
        actClear->setToolTip(QCoreApplication::translate("QWMianWind", "\346\270\205\347\251\272\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actClear->setShortcut(QCoreApplication::translate("QWMianWind", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        action->setText(QCoreApplication::translate("QWMianWind", "\345\255\227\344\275\223...", nullptr));
#if QT_CONFIG(tooltip)
        action->setToolTip(QCoreApplication::translate("QWMianWind", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actToolbarLab->setText(QCoreApplication::translate("QWMianWind", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276", nullptr));
#if QT_CONFIG(tooltip)
        actToolbarLab->setToolTip(QCoreApplication::translate("QWMianWind", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setTitle(QCoreApplication::translate("QWMianWind", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("QWMianWind", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("QWMianWind", "\346\240\274\345\274\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("QWMianWind", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWMianWind: public Ui_QWMianWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWMIANWIND_H
