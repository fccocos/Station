#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStringListModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initStringListModel()
{
    model = new QStringListModel(this);
    QStringList strList;
    strList<<"北京"<<"天津"<<"上海"<<"河南"<<"山东"<<"四川"<<"重庆";
    model->setStringList(strList);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);

}

void MainWindow::on_reviewListBtn_clicked()
{
  if(model->rowCount()!=0)
  {
      ui->listView->setModel(model);
  }
}


void MainWindow::on_addItemBtn_clicked()
{
   model->insertRow(model->rowCount()); // 在尾部插入一行
   QModelIndex index = model->index(model->rowCount()-1, 0);
   model->setData(index, "append a new item", Qt::DisplayRole);
   ui->listView->setCurrentIndex(index); // 设置当前选中的行
}


void MainWindow::on_insItemBtn_clicked()
{
   QModelIndex index =ui->listView->currentIndex();
   model->insertRow(index.row());
   model->setData(index, "insert a new item", Qt::DisplayRole);
   ui->listView->setCurrentIndex(index);

}


void MainWindow::on_delCurItemBtn_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}


void MainWindow::on_clearList_clicked()
{
    model->removeRows(0, model->rowCount());
}


void MainWindow::on_clearTextBtn_clicked()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_displayBtn_clicked()
{
    QStringList tmpList = model->stringList();
    ui->plainTextEdit->clear();
    for(int i=0; i<tmpList.count(); i++)
    {
        ui->plainTextEdit->appendPlainText(tmpList.at(i));
    }
}

