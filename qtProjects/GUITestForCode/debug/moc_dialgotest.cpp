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
    QByteArrayData data[13];
    char stringdata0[153];
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
QT_MOC_LITERAL(5, 40, 10), // "changeName"
QT_MOC_LITERAL(6, 51, 9), // "changeSex"
QT_MOC_LITERAL(7, 61, 15), // "showQuestionMsg"
QT_MOC_LITERAL(8, 77, 16), // "showInfomaingMsg"
QT_MOC_LITERAL(9, 94, 14), // "showWarningMsg"
QT_MOC_LITERAL(10, 109, 15), // "showCriticalMsg"
QT_MOC_LITERAL(11, 125, 12), // "showAboutMsg"
QT_MOC_LITERAL(12, 138, 14) // "showAboutQtMsg"

    },
    "dialgoTest\0showFile\0\0showColor\0showFont\0"
    "changeName\0changeSex\0showQuestionMsg\0"
    "showInfomaingMsg\0showWarningMsg\0"
    "showCriticalMsg\0showAboutMsg\0"
    "showAboutQtMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialgoTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 4: _t->changeSex(); break;
        case 5: _t->showQuestionMsg(); break;
        case 6: _t->showInfomaingMsg(); break;
        case 7: _t->showWarningMsg(); break;
        case 8: _t->showCriticalMsg(); break;
        case 9: _t->showAboutMsg(); break;
        case 10: _t->showAboutQtMsg(); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
