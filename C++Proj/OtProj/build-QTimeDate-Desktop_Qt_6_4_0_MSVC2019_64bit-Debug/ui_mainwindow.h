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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *getDateTimeBtn;
    QLabel *label_2;
    QLineEdit *timeLineEdit;
    QPushButton *settingTimeBtn;
    QLabel *label_3;
    QLineEdit *dateLineEdit;
    QPushButton *settingDateBtn;
    QLabel *label_4;
    QLineEdit *dateTimeLineEdit;
    QPushButton *settingDateTimeBtn;
    QLabel *label;
    QLabel *label_5;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDateTimeEdit *dateTimeEdit;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLineEdit *showDateLineEdit;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_3;
    QPushButton *timerStartBtn;
    QPushButton *timeStopBtn;
    QLabel *label_7;
    QSpinBox *timerCircleSpinBox;
    QPushButton *settingCircleBtn;
    QLabel *elapsTimeLab;
    QLCDNumber *hourLcdNumber;
    QLCDNumber *minLcdNumber;
    QLCDNumber *secLcdNumber_3;
    QProgressBar *progressBar;
    QPushButton *pushButton_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 30, 461, 241));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 461, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        getDateTimeBtn = new QPushButton(gridLayoutWidget);
        getDateTimeBtn->setObjectName("getDateTimeBtn");

        gridLayout->addWidget(getDateTimeBtn, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        timeLineEdit = new QLineEdit(gridLayoutWidget);
        timeLineEdit->setObjectName("timeLineEdit");

        gridLayout->addWidget(timeLineEdit, 1, 2, 1, 1);

        settingTimeBtn = new QPushButton(gridLayoutWidget);
        settingTimeBtn->setObjectName("settingTimeBtn");

        gridLayout->addWidget(settingTimeBtn, 1, 3, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dateLineEdit = new QLineEdit(gridLayoutWidget);
        dateLineEdit->setObjectName("dateLineEdit");

        gridLayout->addWidget(dateLineEdit, 2, 2, 1, 1);

        settingDateBtn = new QPushButton(gridLayoutWidget);
        settingDateBtn->setObjectName("settingDateBtn");

        gridLayout->addWidget(settingDateBtn, 2, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dateTimeLineEdit = new QLineEdit(gridLayoutWidget);
        dateTimeLineEdit->setObjectName("dateTimeLineEdit");

        gridLayout->addWidget(dateTimeLineEdit, 3, 2, 1, 1);

        settingDateTimeBtn = new QPushButton(gridLayoutWidget);
        settingDateTimeBtn->setObjectName("settingDateTimeBtn");

        gridLayout->addWidget(settingDateTimeBtn, 3, 3, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        timeEdit = new QTimeEdit(gridLayoutWidget);
        timeEdit->setObjectName("timeEdit");

        gridLayout->addWidget(timeEdit, 1, 1, 1, 1);

        dateEdit = new QDateEdit(gridLayoutWidget);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

        dateTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        dateTimeEdit->setObjectName("dateTimeEdit");

        gridLayout->addWidget(dateTimeEdit, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(500, 30, 291, 351));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 30, 61, 16));
        showDateLineEdit = new QLineEdit(groupBox_2);
        showDateLineEdit->setObjectName("showDateLineEdit");
        showDateLineEdit->setGeometry(QRect(80, 30, 191, 21));
        calendarWidget = new QCalendarWidget(groupBox_2);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 70, 271, 241));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(30, 290, 461, 241));
        timerStartBtn = new QPushButton(groupBox_3);
        timerStartBtn->setObjectName("timerStartBtn");
        timerStartBtn->setGeometry(QRect(20, 50, 75, 24));
        timeStopBtn = new QPushButton(groupBox_3);
        timeStopBtn->setObjectName("timeStopBtn");
        timeStopBtn->setGeometry(QRect(120, 50, 75, 24));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 100, 51, 16));
        timerCircleSpinBox = new QSpinBox(groupBox_3);
        timerCircleSpinBox->setObjectName("timerCircleSpinBox");
        timerCircleSpinBox->setGeometry(QRect(80, 100, 91, 22));
        settingCircleBtn = new QPushButton(groupBox_3);
        settingCircleBtn->setObjectName("settingCircleBtn");
        settingCircleBtn->setGeometry(QRect(180, 100, 75, 24));
        elapsTimeLab = new QLabel(groupBox_3);
        elapsTimeLab->setObjectName("elapsTimeLab");
        elapsTimeLab->setGeometry(QRect(220, 50, 53, 16));
        hourLcdNumber = new QLCDNumber(groupBox_3);
        hourLcdNumber->setObjectName("hourLcdNumber");
        hourLcdNumber->setGeometry(QRect(50, 150, 71, 23));
        minLcdNumber = new QLCDNumber(groupBox_3);
        minLcdNumber->setObjectName("minLcdNumber");
        minLcdNumber->setGeometry(QRect(140, 150, 71, 23));
        secLcdNumber_3 = new QLCDNumber(groupBox_3);
        secLcdNumber_3->setObjectName("secLcdNumber_3");
        secLcdNumber_3->setGeometry(QRect(240, 150, 71, 23));
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(40, 200, 271, 23));
        progressBar->setValue(24);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(540, 450, 231, 24));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        getDateTimeBtn->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "         \346\227\266 \351\227\264", nullptr));
        settingTimeBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "        \346\227\245 \346\234\237", nullptr));
        settingDateBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\245\346\234\237", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "      \346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        settingDateTimeBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        label->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "            \345\255\227\347\254\246\344\270\262", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237\351\200\211\346\213\251", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\227\245\346\234\237\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\231\250", nullptr));
        timerStartBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        timeStopBtn->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\221\250\346\234\237", nullptr));
        settingCircleBtn->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\221\250\346\234\237", nullptr));
        elapsTimeLab->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\265\201\351\200\235", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
