#ifndef QWCOMBOBOXDELEGATE_H
#define QWCOMBOBOXDELEGATE_H

#include <QStyledItemDelegate>
#include <QWidget>


class QWComboBoxDelegate : public QStyledItemDelegate
{
      Q_OBJECT
public:
    QWidget*
    createEditor(QWidget* parent, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    void
    setEditorData(QWidget* editor, const QModelIndex &index) const Q_DECL_OVERRIDE;

    void
    setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex &index) const Q_DECL_OVERRIDE;

    void
    updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;


    explicit QWComboBoxDelegate(QObject *parent = nullptr);
};

#endif // QWCOMBOBOXDELEGATE_H
