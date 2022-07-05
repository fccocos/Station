#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    Q_CLASSINFO("author","gunfire")
    Q_CLASSINFO("company","UPC")
    Q_CLASSINFO("version","1.0.0")

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *qbtn;
    void showWidgetsInWidget();
};
#endif // WIDGET_H
