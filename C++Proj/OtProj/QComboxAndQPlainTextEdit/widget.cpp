#include "widget.h"
#include "ui_widget.h"
#include <QMenu>
#include <QTextBlock>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_initItemsBtn_clicked()
{
    QIcon icon;
    icon.addFile("./Icon/logo.ico");
    ui->comboBox->clear();
    for(int i=0; i<20; ++i)
    {
        ui->comboBox->addItem(icon, QString::asprintf("项目 %d", i));//带图标
        ui->comboBox->addItem(QString::asprintf("项目 %d", i));
    }
    ui->comboBox_2->clear();
    QStringList strList;
    strList<<"北京"<<"上海"<<"深圳"<<"武汉"<<"杭州"<<"长沙"<<"岳阳"<<"临淄";
    ui->comboBox_2->addItems(strList);

}


void Widget::on_pushButton_2_clicked()
{
    ui->comboBox->clear();
}


void Widget::on_pushButton_3_clicked()
{
    QMap<QString, int> City_Zone;
    City_Zone.insert("北京", 10);
    City_Zone.insert("上海", 21);
    City_Zone.insert("天津", 22);
    City_Zone.insert("大连", 411);
    City_Zone.insert("锦州",416);
    City_Zone.insert("徐州",516);
    City_Zone.insert("福州",516);
    City_Zone.insert("青岛", 532);
    ui->comboBox_2->clear();
    foreach(const QString &str, City_Zone.keys())
        ui->comboBox_2->addItem(str,City_Zone.value(str));
}


void Widget::on_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1);
    if(ui->checkBox->isChecked())
    {
         ui->comboBox->setEditable(true);
    }
    else
    {
        ui->comboBox->setEditable(false);
    }
}


void Widget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu* menu = ui->plainTextEdit->createStandardContextMenu();
    menu->exec(pos);
}


void Widget::on_pushButton_4_clicked()
{
    /*
     * 获取QTextDocument--内存文本对象，以文本块的方式存储。
     * 一个文本块就是一个段落，每个段落以回车符结束。
    */
    QTextDocument* txtDoc = ui->plainTextEdit->document();
    int bCnt = txtDoc->blockCount(); // 获取块数
    for(int i=0; i<bCnt; ++i)
    {
        QTextBlock tb = txtDoc->findBlockByNumber(i);
        ui->comboBox_2->addItem(tb.text());
    }


}


void Widget::on_pushButton_5_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_checkBox_2_stateChanged(int arg1)
{
   Q_UNUSED(arg1);
    if(ui->checkBox_2->isChecked())
    {
        ui->plainTextEdit->setReadOnly(true);
    }
    else
    {
        ui->plainTextEdit->setReadOnly(false);
    }
}

