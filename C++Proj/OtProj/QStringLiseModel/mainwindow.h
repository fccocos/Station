#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

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
    void on_reviewListBtn_clicked();

    void on_addItemBtn_clicked();

    void on_insItemBtn_clicked();

    void on_delCurItemBtn_clicked();

    void on_clearList_clicked();

    void on_clearTextBtn_clicked();

    void on_displayBtn_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    void initStringListModel();
};
#endif // MAINWINDOW_H
