/****************************************************************************
** Meta object code from reading C++ file 'kernel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/core/kernel/kernel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Core__Kernel_t {
    QByteArrayData data[10];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Core__Kernel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Core__Kernel_t qt_meta_stringdata_Core__Kernel = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 16),
QT_MOC_LITERAL(4, 47, 7),
QT_MOC_LITERAL(5, 55, 12),
QT_MOC_LITERAL(6, 68, 7),
QT_MOC_LITERAL(7, 76, 6),
QT_MOC_LITERAL(8, 83, 7),
QT_MOC_LITERAL(9, 91, 5)
    },
    "Core::Kernel\0closeMainWindow\0\0"
    "openConfigWindow\0openRom\0openGameDisc\0"
    "library\0config\0exitNow\0about\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Core__Kernel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,
       3,    0,   55,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a,
       5,    0,   57,    2, 0x0a,
       6,    0,   58,    2, 0x0a,
       7,    0,   59,    2, 0x0a,
       8,    0,   60,    2, 0x0a,
       9,    0,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Core::Kernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Kernel *_t = static_cast<Kernel *>(_o);
        switch (_id) {
        case 0: _t->closeMainWindow(); break;
        case 1: _t->openConfigWindow(); break;
        case 2: _t->openRom(); break;
        case 3: _t->openGameDisc(); break;
        case 4: _t->library(); break;
        case 5: _t->config(); break;
        case 6: _t->exitNow(); break;
        case 7: _t->about(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Kernel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Kernel::closeMainWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (Kernel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Kernel::openConfigWindow)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Core::Kernel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Core__Kernel.data,
      qt_meta_data_Core__Kernel,  qt_static_metacall, 0, 0}
};


const QMetaObject *Core::Kernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Core::Kernel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Core__Kernel.stringdata))
        return static_cast<void*>(const_cast< Kernel*>(this));
    return QObject::qt_metacast(_clname);
}

int Core::Kernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Core::Kernel::closeMainWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Core::Kernel::openConfigWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
