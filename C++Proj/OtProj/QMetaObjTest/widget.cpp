#include "widget.h"
#include "ui_widget.h"
#include <QMetaProperty>
#include <QMetaClassInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /********自定义代码**********/
    boy = new QPerson("王小明");
    boy->setProperty("age", ui->setBoyAgeSpinBox->value());
    boy->setProperty("score", 95);
    boy->setProperty("sex", "Boy"); // 动态属性
    /*connect函数第二中形参形式，通过指针来指向信号函数和槽函数*/
    connect(boy, &QPerson::ageChanged, this, &Widget::on_ageChanged);

    girl = new QPerson("张晓丽");
    girl->setProperty("age", ui->setGirlAgeSpinBox->value());
    girl->setProperty("score", 89);
    girl->setProperty("sex", "Girl"); // 动态属性
    connect(girl, SIGNAL(ageChanged(int)), this, SLOT(on_ageChanged(int)));

    ui->setBoyAgeSpinBox->setProperty("isBoy", true); // 动态属性
    ui->setGirlAgeSpinBox->setProperty("isBoy", false); // 动态属性

    connect(ui->setGirlAgeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_girlAgeAddBtn_clicked(int)));
    connect(ui->setBoyAgeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(on_boyAgeAddBtn_clicked(int)));

}

Widget::~Widget()
{
    delete ui;
}

//自定义槽函数
/*响应QPerson的ageChanged信号*/
void Widget::on_ageChanged(int value)
{
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson*>(sender()); // 类型投射
    QString hisName = aPerson->property("name").toString();//获取名字
    QString hisSex = aPerson->property("sex").toString(); // 获取性别
    int hisAge = aPerson->property("age").toInt(); // 获取年龄
    ui->textEdit->append(hisName+","+hisSex+","+QString::asprintf(",年龄=%d", hisAge));
}

void Widget::on_spin_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    /*通过属性isBoy来判断操作的是男孩子的SpinBox*/
    if(spinBox->property("isBoy").toBool())
    {
        boy->setAge(spinBox->value());
        ui->textEdit->append(QString("%1").arg(boy->getAge()));
    }
    else
    {
        girl->setAge(spinBox->value());
        ui->textEdit->append(QString("%1").arg(girl->getAge()));
    }

}


void Widget::on_boyAgeAddBtn_clicked()
{

    boy->incAge();
}


void Widget::on_classMetaShowBtn_clicked()
{
    /* 通过boy的metaObject()函数获取QMetaObject对象，
     * 通过QMetaObject对象来分别获取QMetaProperty和QMetaClassInfo
    */
    const QMetaObject *meta = boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->append(QString("类名称:%1\n").arg(meta->className()));
    ui->textEdit->append("property");
    for(int i = meta->propertyOffset();i<meta->propertyCount(); ++i)
    {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue = boy->property(propName).toString();
        ui->textEdit->append(QString("属性名字=%1, 属性值=%2").arg(propName).arg(propValue));

    }
    ui->textEdit->append("");
    ui->textEdit->append("classInfo");
    for(int i=meta->classInfoOffset(); i<meta->classInfoCount(); i++)
    {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->textEdit->append(QString("Name=%1, Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}


void Widget::on_girlAgeAddBtn_clicked()
{

    girl->incAge();
}


void Widget::on_clearTxtBtn_clicked()
{
    ui->textEdit->clear();
}

