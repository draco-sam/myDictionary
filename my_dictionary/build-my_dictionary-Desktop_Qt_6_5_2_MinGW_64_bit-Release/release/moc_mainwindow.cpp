/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../my_dictionary/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "get_tree_flag",
    "",
    "flag",
    "menu_bar_show_hide",
    "change",
    "dict_table_view_open",
    "dict_item_double_clicked",
    "QModelIndex",
    "index",
    "config_table_dict_main_window",
    "close_widget",
    "widget_test",
    "change_widget",
    "receive_string_list",
    "list",
    "tree_check_flag"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[19];
    char stringdata5[7];
    char stringdata6[21];
    char stringdata7[25];
    char stringdata8[12];
    char stringdata9[6];
    char stringdata10[30];
    char stringdata11[13];
    char stringdata12[12];
    char stringdata13[14];
    char stringdata14[20];
    char stringdata15[5];
    char stringdata16[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "get_tree_flag"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 4),  // "flag"
        QT_MOC_LITERAL(31, 18),  // "menu_bar_show_hide"
        QT_MOC_LITERAL(50, 6),  // "change"
        QT_MOC_LITERAL(57, 20),  // "dict_table_view_open"
        QT_MOC_LITERAL(78, 24),  // "dict_item_double_clicked"
        QT_MOC_LITERAL(103, 11),  // "QModelIndex"
        QT_MOC_LITERAL(115, 5),  // "index"
        QT_MOC_LITERAL(121, 29),  // "config_table_dict_main_window"
        QT_MOC_LITERAL(151, 12),  // "close_widget"
        QT_MOC_LITERAL(164, 11),  // "widget_test"
        QT_MOC_LITERAL(176, 13),  // "change_widget"
        QT_MOC_LITERAL(190, 19),  // "receive_string_list"
        QT_MOC_LITERAL(210, 4),  // "list"
        QT_MOC_LITERAL(215, 15)   // "tree_check_flag"
    },
    "MainWindow",
    "get_tree_flag",
    "",
    "flag",
    "menu_bar_show_hide",
    "change",
    "dict_table_view_open",
    "dict_item_double_clicked",
    "QModelIndex",
    "index",
    "config_table_dict_main_window",
    "close_widget",
    "widget_test",
    "change_widget",
    "receive_string_list",
    "list",
    "tree_check_flag"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   77,    2, 0x0a,    3 /* Public */,
       6,    0,   80,    2, 0x0a,    5 /* Public */,
       7,    1,   81,    2, 0x0a,    6 /* Public */,
      10,    0,   84,    2, 0x0a,    8 /* Public */,
      11,    0,   85,    2, 0x0a,    9 /* Public */,
      12,    0,   86,    2, 0x0a,   10 /* Public */,
      13,    0,   87,    2, 0x0a,   11 /* Public */,
      14,    1,   88,    2, 0x0a,   12 /* Public */,
      16,    0,   91,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'get_tree_flag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'menu_bar_show_hide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'dict_table_view_open'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dict_item_double_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        // method 'config_table_dict_main_window'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'close_widget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'widget_test'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'change_widget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receive_string_list'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'tree_check_flag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->get_tree_flag((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->menu_bar_show_hide((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->dict_table_view_open(); break;
        case 3: _t->dict_item_double_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 4: _t->config_table_dict_main_window(); break;
        case 5: _t->close_widget(); break;
        case 6: _t->widget_test(); break;
        case 7: _t->change_widget(); break;
        case 8: _t->receive_string_list((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 9: _t->tree_check_flag(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(bool );
            if (_t _q_method = &MainWindow::get_tree_flag; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
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

// SIGNAL 0
void MainWindow::get_tree_flag(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
