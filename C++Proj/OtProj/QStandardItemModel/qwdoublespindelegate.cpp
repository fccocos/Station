#include "qwdoublespindelegate.h"
#include <QDoubleSpinBox>
QWDoubleSpinDelegate::QWDoubleSpinDelegate()
{

}


/*为tableView中的Cell创建一个代理*/
QWidget*                                         // 返回一个编辑部件
QWDoubleSpinDelegate::createEditor(QWidget *parent,// 将部件绑定到另一个部件上
             const QStyleOptionViewItem &option, // 为编辑部件选择一个视图
             const QModelIndex &index) const     // 将编辑部件和数据进行绑定
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QDoubleSpinBox  *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(50);
    editor->setMaximum(10000);
    return editor;
}

/*为自定义的代理绑定数据*/
void
QWDoubleSpinDelegate::setEditorData(QWidget *editor,                     // 上面函数创建的编辑部件
                   const QModelIndex &index) const // 在编辑部件中绑定数据
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();
    QDoubleSpinBox *doubleSpinBox = static_cast<QDoubleSpinBox*>(editor);
    doubleSpinBox->setValue(value);
}

/*将编辑完的数据更新到数据模型*/
void
QWDoubleSpinDelegate::setModelData(QWidget *editor,                     // 上面函数创建的编辑部件
             QAbstractItemModel *model,           // 数据模型的种类
             const QModelIndex &index) const      // 模型索引
{
    /*将QWidget*类型的editor转换为QDoubleSpinBox*/
    QDoubleSpinBox * doubleSpinBox = static_cast<QDoubleSpinBox*>(editor);
    double value = doubleSpinBox->value();
    model->setData(index, value, Qt::EditRole);
}

/*更新编辑器图形*/
void
QWDoubleSpinDelegate::updateEditorGeometry(QWidget *editor,
                   const QStyleOptionViewItem &option,
                   const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
