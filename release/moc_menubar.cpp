/****************************************************************************
** Meta object code from reading C++ file 'menubar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/mainwindow/menubar/menubar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menubar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gui__MenuBar_t {
    QByteArrayData data[10];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Gui__MenuBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Gui__MenuBar_t qt_meta_stringdata_Gui__MenuBar = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 7),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 12),
QT_MOC_LITERAL(4, 35, 7),
QT_MOC_LITERAL(5, 43, 6),
QT_MOC_LITERAL(6, 50, 7),
QT_MOC_LITERAL(7, 58, 5),
QT_MOC_LITERAL(8, 64, 10),
QT_MOC_LITERAL(9, 75, 12)
    },
    "Gui::MenuBar\0openRom\0\0openGameDisc\0"
    "library\0config\0exitNow\0about\0updateText\0"
    "updateConfig\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gui__MenuBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,
       3,    0,   55,    2, 0x06,
       4,    0,   56,    2, 0x06,
       5,    0,   57,    2, 0x06,
       6,    0,   58,    2, 0x06,
       7,    0,   59,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x0a,
       9,    0,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gui::MenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuBar *_t = static_cast<MenuBar *>(_o);
        switch (_id) {
        case 0: _t->openRom(); break;
        case 1: _t->openGameDisc(); break;
        case 2: _t->library(); break;
        case 3: _t->config(); break;
        case 4: _t->exitNow(); break;
        case 5: _t->about(); break;
        case 6: _t->updateText(); break;
        case 7: _t->updateConfig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MenuBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::openRom)) {
                *result = 0;
            }
        }
        {
            typedef void (MenuBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::openGameDisc)) {
                *result = 1;
            }
        }
        {
            typedef void (MenuBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::library)) {
                *result = 2;
            }
        }
        {
            typedef void (MenuBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::config)) {
                *result = 3;
            }
        }
        {
            typedef void (MenuBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::exitNow)) {
                *result = 4;
            }
        }
        {
            typedef void (MenuBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MenuBar::about)) {
                *result = 5;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Gui::MenuBar::staticMetaObject = {
    { &QMenuBar::staticMetaObject, qt_meta_stringdata_Gui__MenuBar.data,
      qt_meta_data_Gui__MenuBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *Gui::MenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gui::MenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gui__MenuBar.stringdata))
        return static_cast<void*>(const_cast< MenuBar*>(this));
    return QMenuBar::qt_metacast(_clname);
}

int Gui::MenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Gui::MenuBar::openRom()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Gui::MenuBar::openGameDisc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Gui::MenuBar::library()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Gui::MenuBar::config()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Gui::MenuBar::exitNow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Gui::MenuBar::about()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
