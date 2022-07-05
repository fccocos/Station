#ifndef WIDGET_H
#define WIDGET_H

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
    void on_AppendBtn_clicked();

    void on_prependBtn_clicked();

    void on_toUpperBtn_clicked();

    void on_sectionBtn_clicked();

    void on_leftBtn_clicked();

    void on_rightBtn_clicked();

    void on_simpifiedBtn_clicked();

    void on_trimmedBtn_clicked();

    void on_sizeBtn_clicked();

    void on_countBtn_clicked();

    void on_indexOfBtn_clicked();

    void on_lastIndexOfBtn_clicked();

    void on_endsWidthBtn_clicked();

    void on_startsWidth_clicked();

    void on_containsBtn_clicked();

    void on_isNullBtn_clicked();

    void on_isEmpty_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
