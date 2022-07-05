#include "qwcomboboxdelegate.h"

#include <QComboBox>

QWComboBoxDelegate::QWComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}


QWidget*
QWComboBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QComboBox* comboBox = new QComboBox(parent);
    QSize mini_s(50,100);
    comboBox->setMinimumSize(mini_s);
    QSize max_s(50000, 100000);
    comboBox->setMaximumSize(max_s);
    comboBox->setFrame(false); // 没有边框
    return comboBox;


}

void
QWComboBoxDelegate::setEditorData(QWidget* editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentText(value);
}

void
QWComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex &index) const
{
    QComboBox* comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText();
    model->setData(index, value);
}

void
QWComboBoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
