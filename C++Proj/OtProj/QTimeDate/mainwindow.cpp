#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initDateTime();
    initTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initTimer()
{
    fTimer = new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000); // 1s
    connect(fTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

void MainWindow::on_getDateTimeBtn_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();

    ui->timeEdit->setTime(curDateTime.time());
    ui->timeLineEdit->setText(curDateTime.toString("hh:mm:ss"));

    ui->dateEdit->setDate(curDateTime.date());
    ui->dateLineEdit->setText(curDateTime.toString("yyyy-MM-dd"));

    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->dateTimeLineEdit->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));

}


void MainWindow::on_settingTimeBtn_clicked()
{
    QString timeStr = ui->timeLineEdit->text();
    /*出去timeStr中的前后空格*/
    timeStr = timeStr.trimmed();
    /*将获取的时间字符串转换为QTime格式时间*/
    if(!timeStr.isEmpty())
    {
        QTime time = QTime::fromString(timeStr, "hh:mm:ss");
        ui->timeEdit->setTime(time);
    }
}

void MainWindow::initDateTime()
{
    QDateEdit* dateEdit = ui->dateEdit;
    QDateTimeEdit* datetimeEdit = ui->dateTimeEdit;
    datetimeEdit->setDisplayFormat(QString("yyyy-MM-dd hh:mm:ss"));
    dateEdit->setDisplayFormat(QString("yyyy-MM-dd"));
    datetimeEdit->setCalendarPopup(true);
    dateEdit->setCalendarPopup(true);


}

void MainWindow::on_settingDateBtn_clicked()
{
    QString dateStr = ui->dateLineEdit->text();
    /*除去dateStr中的前后空格*/
    dateStr = dateStr.trimmed();
    /*将获取的时间字符串转换为Qdate格式时间*/
    if(!dateStr.isEmpty())
    {
        QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
        ui->dateEdit->setDate(date);
    }
}


void MainWindow::on_settingDateTimeBtn_clicked()
{
    QString datetimeStr = ui->dateTimeLineEdit->text();
    datetimeStr = datetimeStr.trimmed();
    if(!datetimeStr.isEmpty())
    {
        QDateTime datetime = QDateTime::fromString(datetimeStr, "yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(datetime);
    }

}


void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    QString dateStr = date.toString("yyyy年M月d日");
    ui->showDateLineEdit->setText(dateStr);
}


void MainWindow::on_pushButton_8_clicked()
{
  this->close();
}

void MainWindow::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    ui->hourLcdNumber->display(curTime.hour());
    ui->minLcdNumber->display(curTime.minute());
    ui->secLcdNumber_3->display(curTime.second());
    int va = ui->progressBar->value();
    va++;
    if(va>100)
        va=0;
    ui->progressBar->setValue(va);

}
void MainWindow::on_timerStartBtn_clicked()
{
    fTimer->start();
    fTimeCounter.currentTime();
    ui->timerStartBtn->setEnabled(false);
    ui->timeStopBtn->setEnabled(true);
    ui->timerCircleSpinBox->setEnabled(false);
}


void MainWindow::on_timeStopBtn_clicked()
{
    fTimer->stop();
    int tmMsec = fTimeCounter.msec();
    int ms = tmMsec%1000;
    int sec = tmMsec/1000;
    QString str = QString::asprintf("流逝时间: %d 秒, %d 毫秒", sec, ms);
    ui->elapsTimeLab->setText(str);
    ui->timerStartBtn->setEnabled(true);
    ui->timeStopBtn->setEnabled(false);
    ui->settingCircleBtn->setEnabled(true);


}

