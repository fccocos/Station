#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "qwdoublespindelegate.h"
#include "qwcomboboxdelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   //Q_OBJECT
private:
    /*自定代理*/
    QWDoubleSpinDelegate doubleSpinDelegate;
    QWComboBoxDelegate comboBoxDelegate;
    void initWithDelegate();


    QLabel *curOpenFile; // 当前开文件
    QLabel *curCellCoord; // 当前选中的单元格坐标
    QLabel *curCellContent; // 当前选中的单元格中的内容
    QStandardItemModel *model; // 标准项数据模型
    QItemSelectionModel *selection; // 项选择模型
    /*初始化基本内容*/
    void init();
    /*通过字符串列表来初始化数据模型*/
    void initModelFromStringList(QStringList & strList);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFileOpen_triggered();

    void on_actFileSaveAs_triggered();

    void on_actModelDataPreview_triggered();

    void on_actAddLine_triggered();

    void on_actInsLine_triggered();

    void on_actDelLine_triggered();

    void on_actLeft_triggered();

    void on_actRight_triggered();

    void on_actCenter_triggered();

    void on_actBold_triggered();

    void on_actQuit_triggered();

    /*自定义槽函数*/
    void on_tableViewCell_currentChanged(const QModelIndex &current, const QModelIndex &previous);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
