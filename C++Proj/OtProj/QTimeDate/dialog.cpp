#include "dialog.h"

Dialog::Dialog(QWidget *parent):
    QDialog(parent),
    dui(new DUI::Dialog)
{
    timer = new QTimer(this);
    timer->stop();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout));
}

void Dialog::on_timer_timeout()
{

}
