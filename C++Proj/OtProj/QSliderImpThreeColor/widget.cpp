#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initSlidersProp();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initSlidersProp()
{
    QSlider* r = ui->RHSlider;
    QSlider* g = ui->GHSlider;
    QSlider* b = ui->BHSlider;
    QSlider* a = ui->AHSlider;
    r->setMinimum(0);
    g->setMinimum(0);
    b->setMinimum(0);
    r->setMaximum(255);
    g->setMaximum(255);
    b->setMaximum(255);


    /*单步长*/
    r->setSingleStep(1);
    g->setSingleStep(1);
    b->setSingleStep(1);
    /*按下pgUp或pgDown时滑块移动的步长*/
    r->setPageStep(5);
    g->setPageStep(5);
    b->setPageStep(5);

    /*让滑块的位置值等于value*/
    r->setTracking(true);
    g->setTracking(true);
    b->setTracking(true);
    a->setTracking(true);


}

void Widget::on_RHSlider_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    /*Getting RHSlider's value*/
    int RValue = ui->RHSlider->value();
    int GValue = ui->GHSlider->value();
    int BValue = ui->BHSlider->value();
    int AValue = ui->AHSlider->value();
    /*Setting color*/
    color.setRgb(RValue, GValue, BValue, AValue);
    /*Getting QPalette*/
    QPalette pal = ui->textEdit->palette();
    /*Setting color for QPalette*/
    pal.setColor(QPalette::Base, color); // 设置颜色
    /*Setting the textEdit with palette*/
    ui->textEdit->setPalette(pal);

    ui->textEdit->setText(QString("R:%1\nG:%2\nB:%3\nA:%4\n").arg(RValue).arg(GValue).arg(BValue).arg(AValue));
}


void Widget::on_GHSlider_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    /*Getting RHSlider's value*/
    int RValue = ui->RHSlider->value();
    int GValue = ui->GHSlider->value();
    int BValue = ui->BHSlider->value();
    int AValue = ui->AHSlider->value();
    /*Setting color*/
    color.setRgb(RValue, GValue, BValue, AValue);
    /*Getting QPalette*/
    QPalette pal = ui->textEdit->palette();
    /*Setting color for QPalette*/
    pal.setColor(QPalette::Base, color); // 设置颜色
    /*Setting the textEdit with palette*/
    ui->textEdit->setPalette(pal);
    ui->textEdit->setText(QString("R:%1\nG:%2\nB:%3\nA:%4\n").arg(RValue).arg(GValue).arg(BValue).arg(AValue));
}


void Widget::on_BHSlider_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    /*Getting RHSlider's value*/
    int RValue = ui->RHSlider->value();
    int GValue = ui->GHSlider->value();
    int BValue = ui->BHSlider->value();
    int AValue = ui->AHSlider->value();
    /*Setting color*/
    color.setRgb(RValue, GValue, BValue, AValue);
    /*Getting QPalette*/
    QPalette pal = ui->textEdit->palette();
    /*Setting color for QPalette*/
    pal.setColor(QPalette::Base, color); // 设置颜色
    /*Setting the textEdit with palette*/
    ui->textEdit->setPalette(pal);
    ui->textEdit->setText(QString("R:%1\nG:%2\nB:%3\nA:%4\n").arg(RValue).arg(GValue).arg(BValue).arg(AValue));
}


void Widget::on_AHSlider_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    /*Getting RHSlider's value*/
    int RValue = ui->RHSlider->value();
    int GValue = ui->GHSlider->value();
    int BValue = ui->BHSlider->value();
    int AValue = ui->AHSlider->value();
    /*Setting color*/
    color.setRgb(RValue, GValue, BValue, AValue);
    /*Getting QPalette*/
    QPalette pal = ui->textEdit->palette();
    /*Setting color for QPalette*/
    pal.setColor(QPalette::Base, color); // 设置颜色
    /*Setting the textEdit with palette*/
    ui->textEdit->setPalette(pal);
    ui->textEdit->setText(QString("R:%1\nG:%2\nB:%3\nA:%4\n").arg(RValue).arg(GValue).arg(BValue).arg(AValue));
}

