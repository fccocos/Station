#ifndef SONWIDGET_H
#define SONWIDGET_H

#include <QWidget>
#include <QPushButton>

class SonWidget : public QWidget
{
    Q_OBJECT
    QPushButton* btn;
public:
    explicit SonWidget(QWidget *parent = nullptr);

signals:
    //信号没有返回值 可以有参数 信号函数不需要定义 只要声明
    void show_hide_signal(int a);
public slots:
    void emit_mySignal();

};

#endif // SONWIDGET_H
