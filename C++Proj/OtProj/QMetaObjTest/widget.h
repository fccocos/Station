#ifndef WIDGET_H
#define WIDGET_H

#include "qperson.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    //自定义槽函数
    void on_ageChanged(int value);

    // spinBox的槽函数
    void on_spin_valueChanged(int arg1);

    //界面中的四个按钮的槽函数
    void on_boyAgeAddBtn_clicked();

    void on_classMetaShowBtn_clicked();

    void on_girlAgeAddBtn_clicked();

    void on_clearTxtBtn_clicked();

private:
    Ui::Widget *ui;
    QPerson *boy;
    QPerson *girl;
};
#endif // WIDGET_H
