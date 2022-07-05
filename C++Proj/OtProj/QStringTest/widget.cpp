#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_AppendBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    str1.append(str2);

    ui->resultLineEdit->setText(str1);
}


void Widget::on_prependBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    str1.prepend(str2);
    ui->resultLineEdit->setText(str1);
}


void Widget::on_toUpperBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = str1.toUpper();
    ui->resultLineEdit->setText(str1);
}


void Widget::on_sectionBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    wchar_t arr[1];
    str2.toWCharArray(arr);
    str1 = str1.section(arr[0], 1,1);
    ui->resultLineEdit->setText(str1);

}



void Widget::on_leftBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = str1.left(5);
    ui->resultLineEdit->setText(str1);
}


void Widget::on_rightBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = str1.right(5);
    ui->resultLineEdit->setText(str1);
}


void Widget::on_simpifiedBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = str1.simplified(); // 去除前部空格和转义字符
    ui->resultLineEdit->setText(str1);
}


void Widget::on_trimmedBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = str1.trimmed();// 移除前后空格和'\t' '\n' '\v' '\r' ' '
    ui->resultLineEdit->setText(str1);
}


void Widget::on_sizeBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = QString::number(str1.size());
    ui->resultLineEdit->setText(str1);
}


void Widget::on_countBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    str1 = QString::number(str1.count());
    int value = str1.toInt();
    ui->countSpinBox->setValue(value);

}


void Widget::on_indexOfBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    str1 = QString::number(str1.indexOf(str2));
    ui->resultLineEdit->setText(str1);
}


void Widget::on_lastIndexOfBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    str1 = QString::number(str1.lastIndexOf(str2));
    ui->resultLineEdit->setText(str1);
}


void Widget::on_endsWidthBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();

    if(str1.endsWith(str2))
        str1 = "true";
    else str1 = "false";
    ui->resultLineEdit->setText(str1);
}


void Widget::on_startsWidth_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    if(str1.startsWith(str2))
        str1 = "true";
    else str1 = "false";
    ui->resultLineEdit->setText(str1);
}


void Widget::on_containsBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    QString str2 = ui->Str2ComboBox->currentText();
    if(str1.contains(str2, Qt::CaseInsensitive))
        str1 = "true";
    else str1 = "false";
    ui->resultLineEdit->setText(str1);
}


void Widget::on_isNullBtn_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    if(str1.isNull())
        str1 = "true";
    else str1 = "false";

    ui->resultLineEdit->setText(str1);
}


void Widget::on_isEmpty_clicked()
{
    QString str1 = ui->str1ComboBox->currentText();
    if(str1.isEmpty())
        str1 = "true";
    else str1 = "false";
    ui->resultLineEdit->setText(str1);
}

