#include "qwmianwind.h"
#include "ui_qwmianwind.h"

QWMianWind::QWMianWind(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMianWind)
{
    ui->setupUi(this);
    initUI();
    initSignalSlots();
}

QWMianWind::~QWMianWind()
{
    delete ui;
}
void QWMianWind::initUI()
{
    /*在状态上添加label标签*/
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件: ");
    ui->statusbar->addWidget(fLabCurFile); // 添加到状态栏 QMainWindow为UI的类型

    /*在状态栏上添加进度条*/
    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(150);
    progressBar1->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1);

    /*在工具上添加组件*/
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addSeparator();//分隔条
    ui->toolBar->addWidget(new QLabel("字体"));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->textEdit);
}

// 信号与槽的关联
void QWMianWind::initSignalSlots()
{
    connect(spinFontSize, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinBoxFontSize_valueChanged(int)));

    connect(comboFont, SIGNAL(currentIndexChanged(const QString &)), this,
            SLOT(on_comboFont_currentIndexChanged(const QString &)));

}


/*********************槽函数定义***************************/

void QWMianWind::on_actBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if(checked)
    {
        fmt.setFontWeight(QFont::Bold);
    }
    else
    {
        fmt.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void QWMianWind::on_actItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void QWMianWind::on_actUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void QWMianWind::on_textEdit_copyAvailable(bool b)
{
    /*根据当前状态自动更新相关Action的enabled属性*/
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(b);
}


void QWMianWind::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    ui->actItalic->setCheckable(fmt.fontItalic());
    ui->actBold->setCheckable(fmt.font().bold());
    ui->actUnderline->setCheckable(fmt.fontUnderline());
}

// 改变字体大小
void QWMianWind::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}

//选择字体
void QWMianWind::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFont(arg1);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


