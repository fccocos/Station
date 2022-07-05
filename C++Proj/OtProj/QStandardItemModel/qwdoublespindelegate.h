#ifndef QWDOUBLESPINDELEGATE_H
#define QWDOUBLESPINDELEGATE_H

#include <QStyledItemDelegate>
#include <QWidget>

class QWDoubleSpinDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWDoubleSpinDelegate();

    /*为tableView中的Cell创建一个代理*/
    QWidget*                                         // 返回一个编辑部件
    createEditor(QWidget *parent,                    // 将部件绑定到另一个部件上
                 const QStyleOptionViewItem &option, // 为编辑部件选择一个视图
                 const QModelIndex &index) const     // 将编辑部件和数据进行绑定
    Q_DECL_OVERRIDE;                                 // 重载标志

    /*为自定义的代理绑定数据*/
    void
    setEditorData(QWidget *editor,                     // 上面函数创建的编辑部件
                       const QModelIndex &index) const // 在编辑部件中绑定数据
    Q_DECL_OVERRIDE;

    /*为自定义的代理绑定数据模型*/
    void
    setModelData(QWidget *editor,                     // 上面函数创建的编辑部件
                 QAbstractItemModel *model,           // 数据模型的种类
                 const QModelIndex &index) const      // 模型索引
    Q_DECL_OVERRIDE;

    /*更新编辑器图形*/
    void
    updateEditorGeometry(QWidget *editor,
                       const QStyleOptionViewItem &option,
                       const QModelIndex &index) const
    Q_DECL_OVERRIDE;

};

#endif // QWDOUBLESPINDELEGATE_H
