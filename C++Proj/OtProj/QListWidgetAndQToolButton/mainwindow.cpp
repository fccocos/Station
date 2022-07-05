#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*将spliter填充整个工作区*/
    setCentralWidget(ui->splitter);
    setActionForButton();
    createSelectionPopMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActionForButton()
{
    /*为所有的toolbutton按钮设置关联动作*/
    ui->ListInitTbtn->setDefaultAction(ui->actInitList);
    ui->ListClearTbtn->setDefaultAction(ui->actClearList);
    ui->ListInsertTbtn->setDefaultAction(ui->actInsertItem);
    ui->listAppendTbtn->setDefaultAction(ui->actAddItem);
    ui->listDelTbtn->setDefaultAction(ui->actDelCurItem);

    ui->selectAllTbtn->setDefaultAction(ui->actSelectAll);
    ui->selectNoneTbtn->setDefaultAction(ui->actSelectNone);
    ui->selectInvsTbtn->setDefaultAction(ui->actSelectInvs);

}

void MainWindow::createSelectionPopMenu()
{
    /*创建下拉菜单*/
    QMenu * menuSelection = new QMenu(this);//创建弹出式菜单
    menuSelection->addAction(ui->actSelectAll);
    menuSelection->addAction(ui->actSelectNone);
    menuSelection->addAction(ui->actSelectInvs);
    /*设置tBtnSelectItem按钮*/
    ui->selectItemTbtn->setPopupMode(QToolButton::MenuButtonPopup); // 设置工具按钮的弹出方式
    ui->selectItemTbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // 设置工具按钮的风格
    ui->selectItemTbtn->setDefaultAction(ui->actSelPopMenu); // 为工具俺就设置关联动作
    ui->selectItemTbtn->setMenu(menuSelection); // 设置工具栏的下拉菜单

    /*设置工具上的selectItem按钮*/
    QToolButton *aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aBtn->setDefaultAction(ui->actSelPopMenu);
    aBtn->setMenu(menuSelection);
    ui->toolBar->addWidget(aBtn);

    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actQuit);
}

void MainWindow::on_actInitList_triggered()
{
    QListWidgetItem *aItem; // 每一行是一个Item
    QIcon aIcon;
    aIcon.addFile(":images/Icon/check.png");
    bool chk = ui->checkBox->isChecked();

    ui->listWidget->clear();
    for(int i=0; i<10; i++)
    {
        QString str = QString::asprintf("Item %d", i);
        aItem = new QListWidgetItem;
        aItem->setText(str); // 设置Item的文本标签
        aItem->setIcon(aIcon);
        aItem->setCheckState(Qt::Checked);
        if(chk)
        {
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable
                            |Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        }
        else
        {
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable
                            |Qt::ItemIsEnabled);
            ui->listWidget->addItem(aItem); // 添加一个项
        }
    }
}



void MainWindow::on_actInsertItem_triggered()
{
    QIcon aIcon;
    aIcon.addFile(":images/Icon/check.png");
    bool chk = ui->checkBox->isChecked();

    QListWidgetItem* aItem = new QListWidgetItem("New Inserted Item");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);
    if(chk)
    {
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable
                        |Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
    }
    else
    {
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);

        ui->listWidget->insertItem(ui->listWidget->currentRow()+1, aItem);
    }
}


void MainWindow::on_actClearList_triggered()
{
    ui->listWidget->clear();
}


void MainWindow::on_actDelCurItem_triggered()
{
    int curRow = ui->listWidget->currentRow();
    QListWidgetItem *aItem = ui->listWidget->takeItem(curRow); // 只是移除当前项，并没有删除对象
    delete aItem;
}


void MainWindow::on_actSelectAll_triggered()
{
    int cnt = ui->listWidget->count();
    for(int i=0; i<cnt; i++)
    {
        QListWidgetItem *aItem = ui->listWidget->item(i); // 获取一个item
        aItem->setCheckState(Qt::Checked); // 选中
    }
}


void MainWindow::on_actSelectNone_triggered()
{
    int cnt = ui->listWidget->count();
    for(int i=0; i<cnt; i++)
    {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actSelectInvs_triggered()
{
    int cnt = ui->listWidget->count();
    for(int i=0; i<cnt; i++)
    {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        if(aItem->checkState() == Qt::Checked)
        {
            aItem->setCheckState(Qt::Unchecked);
        }
        else
        {
            aItem->setCheckState(Qt::Checked);
        }

    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    /*当前选中项发生变化*/
    QString str;
    if(current!=nullptr)
    {
        if(previous==nullptr)
        {
            str = "当前项: "+current->text();
        }
        else
        {
            str = "前一项: " + previous->text()+"; 当前项: "+current->text();
        }
        ui->lineEdit->setText(str);
    }
}


void MainWindow::on_actAddItem_triggered()
{
    QListWidgetItem *aItem = new QListWidgetItem("append new Item");
    QIcon aIcon;
    aIcon.addFile(":images/Icon/check.png");
    aItem->setIcon(aIcon);
    bool chk = ui->checkBox->isChecked();
    aItem->setCheckState(Qt::Checked);
    if(chk)
    {
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled
                        |Qt::ItemIsEditable|Qt::ItemIsUserCheckable);
    }
    else
    {
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled
                       |Qt::ItemIsUserCheckable);
    }


    ui->listWidget->addItem(aItem);
}


void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu *menuList = new QMenu(this); // 创建菜单
    menuList->addAction(ui->actInitList);
    menuList->addAction(ui->actInitList);
    menuList->addAction(ui->actClearList);
    menuList->addAction(ui->actAddItem);
    menuList->addAction(ui->actDelCurItem);
    menuList->addSeparator();
    menuList->addAction(ui->actSelPopMenu);
    menuList->addSeparator();
    menuList->addAction(ui->actSelectAll);
    menuList->addAction(ui->actSelectInvs);
    menuList->addAction(ui->actSelectNone);
    menuList->addSeparator();
    menuList->addAction(ui->actQuit);

    menuList->exec(QCursor::pos());

    delete menuList;

}

