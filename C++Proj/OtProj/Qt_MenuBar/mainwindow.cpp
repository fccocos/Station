#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //取出菜单栏
    QMenuBar *menuBar1 = this->menuBar();
    //向菜单栏中添加 菜单
    QMenu* filemenu=menuBar1->addMenu("文件");
    QMenu* editmenu=menuBar1->addMenu("编辑");
    //向菜单中添加菜单项
    QAction *openAction = filemenu->addAction("打开");
    //添加分割线
    filemenu->addSeparator();
    QAction *saveAction = filemenu->addAction("保存");

    //获取工具栏
    QToolBar* toolBar = this->addToolBar("");
    //向工具栏中添加菜单项
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    //获取状态栏
    QStatusBar* statusBar = this->statusBar();
    statusBar->addWidget(new QLabel("状态"));

//    //添加铆接部件(浮动窗口)
//    QDockWidget *dockWidget = new QDockWidget("这是一个铆接部件");
//   //将浮动窗口添加到mainwindow中
//    this->addDockWidget(Qt::TopDockWidgetArea,dockWidget);
//    //添加铆接部件(浮动窗口)
//    QDockWidget *dockWidget1 = new QDockWidget("这是一个铆接部件");
//   //将浮动窗口添加到mainwindow中
//    this->addDockWidget(Qt::TopDockWidgetArea,dockWidget1);
    //添加一个文本编辑器
    QTextEdit *textEdit = new QTextEdit();
    //将文本编辑器放入到中心部件中
    this->setCentralWidget(textEdit);

    //定义一个图片对象
    QPixmap pic;
    //加载图片
    pic.load("://avatar");
    //为菜单先添加一个图片
    openAction->setIcon(pic);

}

MainWindow::~MainWindow()
{
}

