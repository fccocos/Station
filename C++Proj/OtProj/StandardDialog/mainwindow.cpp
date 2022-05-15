#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QWidget>
#include <QColor>
#include <QFontDialog>
#include <QFont>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QCheckBox>
#include <QtPrintSupport/QPageSetupDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrinter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QList<QAction*> actions;
    QMenuBar* menuBar = this->menuBar();

    QMenu* fileItem = menuBar->addMenu("文件");
    actions.push_back(fileItem->addAction("打开文件夹"));
    actions.push_back(fileItem->addAction("选择颜色"));
    actions.push_back(fileItem->addAction("选择字体"));
    actions.push_back(fileItem->addAction("输入"));
    actions.push_back(fileItem->addAction("模态对话框"));
    actions.push_back(fileItem->addAction("打印纸张相关信息"));
    actions.push_back(fileItem->addAction("打印机设置"));
    actions.push_back(fileItem->addAction("打印预览"));
    actions.push_back(fileItem->addAction("显示操作过程"));
    fileItem->addActions(actions);
    connect(actions[0],&QAction::triggered,this,[]{
        QString str = QFileDialog::getOpenFileName();
        qDebug()<<str;
    });
    connect(actions[1],&QAction::triggered,this,[]{
        QColor col(80,68,32);
        QColor color = QColorDialog::getColor(col,nullptr,"取色器");
        qDebug()<<color;
    });
    connect(actions[2],&QAction::triggered,this,[]{
        bool flag = true;
        QFont font =  QFontDialog::getFont(&flag);
        qDebug()<<font;
    });
    connect(actions[3],&QAction::triggered,this,[]{
        QWidget* widget = new QWidget();
        qDebug()<< QInputDialog::getText(widget,"输入","input");
        qDebug()<<QInputDialog::getInt(widget,"输入","int");
    });
    connect(actions[4],&QAction::triggered,this,[]{
        QMessageBox msg;
        msg.setText("当前文件已修改，是否保存？");
        msg.addButton(QMessageBox::Ok);
        msg.addButton(QMessageBox::No);
        msg.addAction(new QAction(&msg));
        msg.setCheckBox(new QCheckBox(&msg));
        msg.exec();

    });

    connect(actions[5],&QAction::triggered,this,[]{
        qDebug()<<"QPageSetupDialog";
    });

    connect(actions[6],&QAction::triggered,this,[]{
        qDebug()<<"QPrintPreviewDialog";
    });

}

MainWindow::~MainWindow()
{
}

