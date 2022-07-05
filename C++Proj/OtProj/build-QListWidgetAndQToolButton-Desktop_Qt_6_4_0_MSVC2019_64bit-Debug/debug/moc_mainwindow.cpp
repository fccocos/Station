/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QListWidgetAndQToolButton/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[333];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 24), // "on_actInitList_triggered"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 26), // "on_actInsertItem_triggered"
QT_MOC_LITERAL(64, 25), // "on_actClearList_triggered"
QT_MOC_LITERAL(90, 26), // "on_actDelCurItem_triggered"
QT_MOC_LITERAL(117, 25), // "on_actSelectAll_triggered"
QT_MOC_LITERAL(143, 26), // "on_actSelectNone_triggered"
QT_MOC_LITERAL(170, 26), // "on_actSelectInvs_triggered"
QT_MOC_LITERAL(197, 32), // "on_listWidget_currentItemChanged"
QT_MOC_LITERAL(230, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(247, 7), // "current"
QT_MOC_LITERAL(255, 8), // "previous"
QT_MOC_LITERAL(264, 23), // "on_actAddItem_triggered"
QT_MOC_LITERAL(288, 40), // "on_listWidget_customContextMe..."
QT_MOC_LITERAL(329, 3) // "pos"

    },
    "MainWindow\0on_actInitList_triggered\0"
    "\0on_actInsertItem_triggered\0"
    "on_actClearList_triggered\0"
    "on_actDelCurItem_triggered\0"
    "on_actSelectAll_triggered\0"
    "on_actSelectNone_triggered\0"
    "on_actSelectInvs_triggered\0"
    "on_listWidget_currentItemChanged\0"
    "QListWidgetItem*\0current\0previous\0"
    "on_actAddItem_triggered\0"
    "on_listWidget_customContextMenuRequested\0"
    "pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    2,   81,    2, 0x08,    8 /* Private */,
      13,    0,   86,    2, 0x08,   11 /* Private */,
      14,    1,   87,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actInitList_triggered(); break;
        case 1: _t->on_actInsertItem_triggered(); break;
        case 2: _t->on_actClearList_triggered(); break;
        case 3: _t->on_actDelCurItem_triggered(); break;
        case 4: _t->on_actSelectAll_triggered(); break;
        case 5: _t->on_actSelectNone_triggered(); break;
        case 6: _t->on_actSelectInvs_triggered(); break;
        case 7: _t->on_listWidget_currentItemChanged((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[2]))); break;
        case 8: _t->on_actAddItem_triggered(); break;
        case 9: _t->on_listWidget_customContextMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
    QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
    QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<void, std::false_type>,
    QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>

>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
