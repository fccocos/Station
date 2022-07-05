#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitSystemModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitSystemModel()
{
    model = new QFileSystemModel(this);
    /*将当前路径作为文件系统数据模型的根路径*/
    model->setRootPath(QDir::currentPath());
    /*为三个视图组件添加数据模型*/
    ui->treeView->setModel(model);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    /*关联三个视图组件的信号和槽*/
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->listView, SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->tableView, SLOT(setRootIndex(QModeIndex)));

}
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    /*判断当前点击对象是否是一个目录*/
    ui->checkBox->setChecked(model->isDir(index));
    ui->label_4->setText(model->filePath(index));
    ui->label_3->setText(model->type(index));
    ui->label_2->setText(model->fileName(index));
    int size = model->size(index)/1024;
    if(size<1024)
        ui->label->setText(QString("%1 KB").arg(size));
    else if(size == 0)
        ui->label->setText(QString("%1 B").arg(model->size(index)));
    else
        ui->label->setText(QString("%.1lf MB").arg(size));

}

