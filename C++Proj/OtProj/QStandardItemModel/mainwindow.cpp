#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  init();
    initWithDelegate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*初始化代理*/
void MainWindow::initWithDelegate()
{
    curOpenFile = new QLabel("当前文件: ");
    curCellCoord = new QLabel("当前单元格: ");
    curCellContent = new QLabel("当前内容: ");
    /*将三个标签加入到状态栏*/
    ui->statusbar->addWidget(curOpenFile);
    ui->statusbar->addWidget(curCellCoord);
    ui->statusbar->addWidget(curCellContent);

    /*创建数据模型*/
    model = new QStandardItemModel(this);
    /*创建选择模型*/
    selection = new QItemSelectionModel(model);
    /*连接槽函数和信号函数*/
    connect(selection, SIGNAL(currentChanged(QModelIndex, QModelIndex)),
            this,SLOT(on_tableViewCell_currentChanged(QModelIndex, QModelIndex)));
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selection);

    //为各个列设置
}

/*初始化基本内容*/
void MainWindow::init()
{
    curOpenFile = new QLabel("当前文件: ");
    curCellCoord = new QLabel("当前单元格: ");
    curCellContent = new QLabel("当前内容: ");
    /*加入到状态栏中*/
    ui->statusbar->addWidget(curOpenFile);
    ui->statusbar->addWidget(curCellCoord);
    ui->statusbar->addWidget(curCellContent);

    //创建数据模型
    model = new QStandardItemModel(this);
    //创建选择模型
    selection = new QItemSelectionModel(model); // 绑定到数据模型model上

    connect(selection, SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this, SLOT(on_tableViewCell_currentChanged(QModelIndex, QModelIndex)));
    /*为tableView设置数据模型*/
    ui->tableView->setModel(model);
    /*为tableView设置选择模型*/
    ui->tableView->setSelectionModel(selection);
    /*设置选择模式*/
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    /*设置选择行为*/
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);


    ui->tableView->setItemDelegateForColumn(1, &doubleSpinDelegate);
    ui->tableView->setItemDelegateForColumn(2, &doubleSpinDelegate);
    ui->tableView->setItemDelegateForColumn(3, &doubleSpinDelegate);
    ui->tableView->setItemDelegateForColumn(4, &doubleSpinDelegate);
    ui->tableView->setItemDelegateForColumn(5, &comboBoxDelegate);


}

/*通过字符串列表来初始化数据模型*/
void MainWindow::initModelFromStringList(QStringList & strList)
{
    /*
     * 1. 先处理第0行的字符串,字符串分隔符为","
     * 2. 将处理好的字符串作为表格的标题
     * 3. 接着处理剩余所有行的字符串，这些为表格的内容，同样是以","为分隔符
     * 4. 将处理完毕的数据填充到单元格中
    */
    /*获取文本的函数*/
    int cnt = strList.count();
    /*第0行为表格的标题*/
    /*设置数据模型的行数*/
    model->setRowCount(cnt-1);
    /*获取第0行的字符串*/
    QString header = strList.at(0);
    /*分割字符串header,获取表格的字段*/
    QStringList headerList = header.split(",", /*分割字符*/
                                          Qt::SkipEmptyParts,/*跳过空格部分*/
                                          Qt::CaseSensitive);/*大小写敏感*/
    /*设置表头字段*/
    model->setHorizontalHeaderLabels(headerList);

    /*将剩余行的数据处理后加入到model的数据项中*/
    QStandardItem *item;
    for(int i=1; i<cnt; i++)
    {
        QString data = strList.at(i);
        QStringList dataList = data.split(",", /*分割字符*/
                                      Qt::SkipEmptyParts,/*跳过空格部分*/
                                      Qt::CaseSensitive);/*大小写敏感*/
        for(int j=0; j<dataList.count(); j++)
        {
            item = new QStandardItem(dataList.at(j));
            model->setItem(i-1, j, item);
        }

    }




}

void MainWindow::on_actFileOpen_triggered()
{
    QString path = QCoreApplication::applicationDirPath(); // app的目录路径
    QString filename = QFileDialog::getOpenFileName(this, "title:打开一个文件", path,
                                                    "数据文件(*.txt);;所有文件(*.*)");
    if(filename.isEmpty()) return;

    QStringList fFileContent; // 用于存储打开文件中的所有数据
    QFile aFile(filename);

    if(aFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream aStream(&aFile); // 用文本流的方式读取文本
        ui->plainTextEdit->clear();
        while(!aStream.atEnd())
        {
            // 按行读取文本
            QString strLine = aStream.readLine();
            // 将当前行的内容写入到PlainTextEdit中
            ui->plainTextEdit->appendPlainText(strLine);
            // 将当前行同时也写入到字符串列表中
            fFileContent.append(strLine);
        }
        aFile.close();
        //将当前文件路径加入到curFileOpen标签中
        curOpenFile->setText("当前为文件: "+filename);
        /*初始化数据模型*/
        initModelFromStringList(fFileContent);
    }


}


void MainWindow::on_actFileSaveAs_triggered()
{

}


void MainWindow::on_actModelDataPreview_triggered()
{

}


void MainWindow::on_actAddLine_triggered()
{
    QList<QStandardItem*> aItemList;
    QStandardItem* item;
    for(int i=0; i<model->columnCount();i++)
    {
        item = new QStandardItem("append new cell");
        aItemList<<item;
    }
    model->insertRow(model->rowCount(), aItemList);
    QModelIndex curIndex = model->index(model->rowCount()-1,0);
    selection->clearSelection();
    selection->setCurrentIndex(curIndex, QItemSelectionModel::Select);
}


void MainWindow::on_actInsLine_triggered()
{
    QList<QStandardItem*> aItemList;
    QStandardItem* item;
    for(int i=0; i<model->columnCount(); i++)
    {
        item = new QStandardItem("Insert new cell");
        aItemList << item;
    }
    QModelIndex currentIndex = selection->currentIndex();
    int currentRow = currentIndex.row()+1;
    QModelIndex insIndex = model->index(currentRow, 0);
    model->insertRow(currentRow, aItemList);
    selection->clearSelection();
    selection->setCurrentIndex(insIndex, QItemSelectionModel::Select);

}


void MainWindow::on_actDelLine_triggered()
{
    QModelIndex currentIndex = selection->currentIndex();
    if(currentIndex.row()==model->rowCount()-1)
    {
        model->removeRow(currentIndex.row());
    }
    else
    {
        model->removeRow(currentIndex.row());
        selection->setCurrentIndex(currentIndex,QItemSelectionModel::Select);
    }

}


void MainWindow::on_actLeft_triggered()
{
   if(!selection->hasSelection())return;
   QModelIndexList selectedIndexs = selection->selectedIndexes();
   for(int i=0; i<selectedIndexs.count(); i++)
   {
       QModelIndex aIndex = selectedIndexs.at(i);
       QStandardItem *item = model->itemFromIndex(aIndex);
       item->setTextAlignment(Qt::AlignLeft);
   }

}


void MainWindow::on_actRight_triggered()
{
    if(!selection->hasSelection())return;
    QModelIndexList selectedIndexs = selection->selectedIndexes();
    for(int i=0; i<selectedIndexs.count(); i++)
    {
        QModelIndex aIndex = selectedIndexs.at(i);
        QStandardItem *item = model->itemFromIndex(aIndex);
        item->setTextAlignment(Qt::AlignRight);
    }
}


void MainWindow::on_actCenter_triggered()
{
    if(!selection->hasSelection())return;
    QModelIndexList selectedIndexs = selection->selectedIndexes();
    for(int i=0; i<selectedIndexs.count(); i++)
    {
        QModelIndex aIndex = selectedIndexs.at(i);
        QStandardItem *item = model->itemFromIndex(aIndex);
        item->setTextAlignment(Qt::AlignCenter);
    }
}


void MainWindow::on_actBold_triggered()
{

    if(!selection->hasSelection())return;
    QModelIndexList selectedIndexs = selection->selectedIndexes();
    for(int i=0; i<selectedIndexs.count(); i++)
    {
        QModelIndex aIndex = selectedIndexs.at(i);
        QStandardItem *item = model->itemFromIndex(aIndex);
        QFont font=item->font();
        font.setBold(Qt::Checked);
        item->setFont(font);
    }
}


void MainWindow::on_actQuit_triggered()
{
    this->close();
}

void MainWindow::on_tableViewCell_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    if(current.isValid())
    {
        curCellCoord->setText(QString::asprintf("当前单元格: %d行, %d列",
                                               current.row(), current.column()));
        QStandardItem* item = model->itemFromIndex(current); // 从模型索引中获取item
        /*从item中获取单元格的内容*/
        curCellContent ->setText("当前内容"+item->text());
        QFont font = item->font();
        ui->actBold->setChecked(font.bold()); // 设置动作actBold是否为中选状态, 取决于单元格中内容的字体格式.
    }
}

