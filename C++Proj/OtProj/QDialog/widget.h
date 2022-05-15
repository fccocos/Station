#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QWidget>
#include <QDialog>

class Widget : public QWidget
{
    Q_OBJECT
    QPushButton* btn,*btn1;
    QDialog* dialog;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
