#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_getDateTimeBtn_clicked();

    void on_settingTimeBtn_clicked();

    void on_settingDateBtn_clicked();

    void on_settingDateTimeBtn_clicked();

    void on_calendarWidget_selectionChanged();

    void on_pushButton_8_clicked();

    void on_timer_timeout();

    void on_timerStartBtn_clicked();

    void on_timeStopBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *fTimer;
    QTime fTimeCounter;
    void initDateTime();
    void initTimer();
};
#endif // MAINWINDOW_H
