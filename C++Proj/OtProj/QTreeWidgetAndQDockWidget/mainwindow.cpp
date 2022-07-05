#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileNameLab = new QLabel("");
    ui->statusbar->addWidget(fileNameLab); // 将fileNameLab添加到状态栏中
    /*将scrollArea填充整个centralWidget*/
    this->setCentralWidget(ui->scrollArea);
    /*初始化目录树*/
    initTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*目录树初始化*/
void MainWindow::initTree()
{
   QString dataStr = "";
   ui->treeWidget->clear();
   QIcon icon;
   icon.addFile(":images/Icon/folder.png");

   QTreeWidgetItem* item = new QTreeWidgetItem(MainWindow::ItemTop);
   item->setIcon(MainWindow::col1, icon); // 第一列的图片
   item->setText(MainWindow::col1, "图片文件");
   item->setText(MainWindow::col2, "type=itemTop");
   item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable
                  |Qt::ItemIsEnabled|Qt::ItemIsAutoTristate);
   item->setCheckState(MainWindow::col1, Qt::Checked);

   item->setData(MainWindow::col1, Qt::UserRole, QVariant(dataStr));
   ui->treeWidget->addTopLevelItem(item);
}

/*将目录添加到目录树节点中*/
void MainWindow::addFolderItem(QTreeWidgetItem *parItem, QString dirName)
{
    QIcon icon(":image/Icon/open.png");
    QString NodeText = getFinalFolderName(dirName);

    QTreeWidgetItem *item;
    item = new QTreeWidgetItem(MainWindow::ItemGroup);
    item->setIcon(MainWindow::col1, icon);
    item->setText(MainWindow::col1, NodeText);
    item->setText(MainWindow::col2, "type=GroupItem");
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable
                   |Qt::ItemIsEnabled|Qt::ItemIsAutoTristate);
    item->setCheckState(MainWindow::col1, Qt::Checked);
    item->setData(MainWindow::col1,Qt::UserRole, QVariant(dirName));
    parItem->addChild(item);

}

/*添加图片名称到Image节点上*/
void MainWindow::addImageItem(QTreeWidgetItem *parItem, QString aFileName)
{
    QIcon icon(":images/Icon/png.png");
    QString NodeText = getFinalFolderName(aFileName);

    QTreeWidgetItem *item;
    item = new QTreeWidgetItem(MainWindow::ItemImage);
    item->setIcon(MainWindow::col1, icon);
    item->setText(MainWindow::col1, NodeText);
    item->setText(MainWindow::col2, "type=ItemImage");
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable
                   |Qt::ItemIsEnabled|Qt::ItemIsAutoTristate);
    item->setCheckState(MainWindow::col1, Qt::Checked);
    item->setData(MainWindow::col1, Qt::UserRole,QVariant(aFileName));
    parItem->addChild(item);


}

/*显示图片*/
void MainWindow::displayImage(QTreeWidgetItem *item)
{
    QString filename = item->data(col1, Qt::UserRole).toString();
    fileNameLab->setText(filename);
    imag.load(filename);
    on_actZoomFitH_triggered();


}

/*遍历所有改变的节点*/
void MainWindow::changeItemCaption(QTreeWidgetItem *item)
{
    QString str="*"+item->text(col1);
    item->setText(col1, str);
    if(item->childCount()>0)
        for(int i=0; i<item->childCount(); i++)
            changeItemCaption(item->child(i));

}

/*从绝对路径中获取最后一个目录的名字*/
QString MainWindow::getFinalFolderName(const QString &fullPathName)
{
    int cnt = fullPathName.length();
    int i = fullPathName.lastIndexOf("/");
    QString lastDir = fullPathName.right(cnt-i-1);
    return lastDir;
}

/*添加文件动作的槽函数, 其主要作用是在合适的item下将目录添加到这个item下*/
void MainWindow::on_actAddFolder_triggered()
{
    // 选择目录
    QString dir = QFileDialog::getExistingDirectory();
    if(!dir.isEmpty())
    {
        /*获取当前节点作为父节点*/
        QTreeWidgetItem *parItem = ui->treeWidget->currentItem();
        addFolderItem(parItem, dir);

    }
}


void MainWindow::on_actAddFile_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,"选择一个或多个文件","./","Images(*.png *.xpm *.jpg)");
    if(files.isEmpty())
    {
        return;
    }
    QTreeWidgetItem *parItem, *item;
    item = ui->treeWidget->currentItem();
    if(item->type() == ItemImage)
    {
        parItem = item->parent();
    }
    else
    {
        parItem = item;
    }
    for(int i=0; i<files.size(); i++)
    {
        QString aFileName = files.at(i);
        addImageItem(parItem, aFileName);
    }
}

/*当前节点发生变化*/
void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);

    if(current == nullptr)
        return;
    int var = current->type();
    switch(var)
    {
        case MainWindow::ItemTop:
            ui->actAddFile->setEnabled(true);
            ui->actAddFile->setEnabled(true);
            ui->actDelNode->setEnabled(false); //顶层节点不能删除4
            break;
        case MainWindow::ItemGroup:
            ui->actAddFile->setEnabled(true);
            ui->actAddFile->setEnabled(true);
            ui->actDelNode->setEnabled(true);
            break;
        case MainWindow::ItemImage:
            ui->actAddFile->setEnabled(false);
            ui->actAddFile->setEnabled(true);
            ui->actDelNode->setEnabled(true);
            displayImage(current); // 显示图片
            break;

    }
}


void MainWindow::on_actDelNode_triggered()
{
    QTreeWidgetItem * item =  ui->treeWidget->currentItem();
    QTreeWidgetItem * parItem = item->parent();
    parItem->removeChild(item);
    delete item;
}


void MainWindow::on_actScanNode_triggered()
{
    for(int i=0; i<ui->treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem * item = ui->treeWidget->topLevelItem(i); // 顶层节点
        changeItemCaption(item);
    }
}


void MainWindow::on_actZoomFitH_triggered()
{
    int H = ui->scrollArea->height();
    int realH = imag.height();
    pixRatio = float(H)/realH;
    QPixmap pix =imag.scaledToHeight(H=30);
    ui->label->setPixmap(pix);
}


void MainWindow::on_actZoomFitW_triggered()
{
    int W = ui->scrollArea->width();
    int realW = imag.width();
    pixRatio = float(W)/realW;
    QPixmap pix =imag.scaledToWidth(W=40);
    ui->label->setPixmap(pix);
}


void MainWindow::on_actZoomRealSize_triggered()
{
    pixRatio = 1;
    ui->label->setPixmap(imag);
}


void MainWindow::on_actZoomIn_triggered()
{
    pixRatio = pixRatio*1.2;
    int w=pixRatio*imag.width();
    int h=pixRatio*imag.height();
    QPixmap pix = imag.scaled(w,h);
    ui->label->setPixmap(pix);
}


void MainWindow::on_actZoomOut_triggered()
{
    pixRatio = pixRatio*0.8;
    int w=pixRatio*imag.width();
    int h=pixRatio*imag.height();
    QPixmap pix = imag.scaled(w,h);
    ui->label->setPixmap(pix);
}

void MainWindow::on_actDockVisible_toggled(bool arg1)
{
    Q_UNUSED(arg1);
    if(ui->actDockVisible->isChecked())
    {
        ui->dockWidget->setVisible(true);
    }else
    {
        ui->dockWidget->setVisible(false);
    }
}

void MainWindow::on_actDockFloat_triggered(bool checked)
{
    Q_UNUSED(checked);
    if(ui->actDockVisible->isChecked())
    {
        ui->dockWidget->setFloating(true);
    }else
    {
        ui->dockWidget->setFloating(false);
    }
}


void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->actDockVisible->setCheckable(visible);
}


void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    ui->actDockFloat->setCheckable(topLevel);
}

