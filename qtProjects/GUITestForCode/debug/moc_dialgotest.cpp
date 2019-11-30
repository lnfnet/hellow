/****************************************************************************
** Meta object code from reading C++ file 'dialgotest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialgotest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialgotest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dialgoTest_t {
    QByteArrayData data[6];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialgoTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialgoTest_t qt_meta_stringdata_dialgoTest = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dialgoTest"
QT_MOC_LITERAL(1, 11, 8), // "showFile"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "showColor"
QT_MOC_LITERAL(4, 31, 8), // "showFont"
QT_MOC_LITERAL(5, 40, 10) // "changeName"

    },
    "dialgoTest\0showFile\0\0showColor\0showFont\0"
    "changeName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialgoTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialgoTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dialgoTest *_t = static_cast<dialgoTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showFile(); break;
        case 1: _t->showColor(); break;
        case 2: _t->showFont(); break;
        case 3: _t->changeName(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject dialgoTest::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialgoTest.data,
      qt_meta_data_dialgoTest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dialgoTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialgoTest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dialgoTest.stringdata0))
        return static_cast<void*>(const_cast< dialgoTest*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialgoTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
