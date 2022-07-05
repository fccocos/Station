#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_calBtn_clicked()
{
    QString str = ui->NumLineEdit->text();
    int num = str.toInt();
    str = ui->PriceLineEdit->text();
    float price = str.toFloat();
    float total = price*num;
    str = QString::asprintf("%.2f",total);
    ui->TotalPriceLineEdit->setText(str);
}


void MainWindow::on_DecToBtn_clicked()
{
    QString str = ui->DecLineEdit->text();
    int val = str.toInt();
    str = QString::number(val, 16);
    str = str.toUpper();
    ui->HexLineEdit->setText(str); // 十六进制

    str = str.setNum(val, 2);
    ui->BinLineEdit->setText(str); // 二进制
}


void MainWindow::on_BinToBtn_clicked()
{
    QString str = ui->BinLineEdit->text();
    bool ok;
    int val = str.toInt(&ok, 2);
    str=QString::number(val,10);
    ui->DecLineEdit->setText(str);

    str=str.setNum(val, 16);
    str = str.toUpper();
    ui->HexLineEdit->setText(str);
}


void MainWindow::on_HexToBtn_clicked()
{
    QString str = ui->HexLineEdit->text();
    bool ok;
    int val = str.toInt(&ok, 16);
    str=str.setNum(val, 2);
    ui->BinLineEdit->setText(str);

    str = QString::number(val, 10);
    ui->DecLineEdit->setText(str);
}

