#include "sonwidget.h"

SonWidget::SonWidget(QWidget *parent) : QWidget(parent)
{
   btn = new QPushButton("隐藏子窗口 显示父窗口",this);
   connect(btn, &QPushButton::clicked, this, &SonWidget::emit_mySignal);
}
void SonWidget::emit_mySignal()
{
    emit show_hide_signal(1);
}
