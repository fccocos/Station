#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTreeWidgetItem>

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
    void on_actAddFolder_triggered();

    void on_actAddFile_triggered();

    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_actDelNode_triggered();

    void on_actScanNode_triggered();

    void on_actZoomFitH_triggered();

    void on_actZoomFitW_triggered();

    void on_actZoomRealSize_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomOut_triggered();

    void on_actDockVisible_toggled(bool arg1);

    void on_actDockFloat_triggered(bool checked);

    void on_dockWidget_visibilityChanged(bool visible);

    void on_dockWidget_topLevelChanged(bool topLevel);

private:
    Ui::MainWindow *ui;
    /*声明Tree的三个层级*/
    enum TreeItemType{ItemTop=1001,ItemGroup, ItemImage};
    /*treeWidget中有两列,声明目录树的编号*/
    enum TreeColNum{col1=0, col2};
    QLabel *fileNameLab;
    QPixmap imag;
    float pixRatio=1; // 缩放比例

    void initTree(); // 目录树初始化
    /*将目录添加到目录树节点中*/
    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);
    /*添加图片名称到Image节点上*/
    void addImageItem(QTreeWidgetItem *parItem, QString aFileName);
    /*显示图片*/
    void displayImage(QTreeWidgetItem *item);
    /*遍历所有改变的节点*/
    void changeItemCaption(QTreeWidgetItem *item);
    /*获取目录名*/
    QString getFinalFolderName(const QString &fullPathName);

};
#endif // MAINWINDOW_H
