/****************************************************************************
** Meta object code from reading C++ file 'piechart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "piechart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piechart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Vilma_controler_t {
    QByteArrayData data[26];
    char stringdata[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Vilma_controler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Vilma_controler_t qt_meta_stringdata_Vilma_controler = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 16),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 18),
QT_MOC_LITERAL(4, 53, 23),
QT_MOC_LITERAL(5, 77, 21),
QT_MOC_LITERAL(6, 99, 12),
QT_MOC_LITERAL(7, 112, 7),
QT_MOC_LITERAL(8, 120, 17),
QT_MOC_LITERAL(9, 138, 12),
QT_MOC_LITERAL(10, 151, 4),
QT_MOC_LITERAL(11, 156, 14),
QT_MOC_LITERAL(12, 171, 19),
QT_MOC_LITERAL(13, 191, 17),
QT_MOC_LITERAL(14, 209, 10),
QT_MOC_LITERAL(15, 220, 12),
QT_MOC_LITERAL(16, 233, 14),
QT_MOC_LITERAL(17, 248, 12),
QT_MOC_LITERAL(18, 261, 5),
QT_MOC_LITERAL(19, 267, 14),
QT_MOC_LITERAL(20, 282, 17),
QT_MOC_LITERAL(21, 300, 9),
QT_MOC_LITERAL(22, 310, 11),
QT_MOC_LITERAL(23, 322, 16),
QT_MOC_LITERAL(24, 339, 14),
QT_MOC_LITERAL(25, 354, 5)
    },
    "Vilma_controler\0gas_jointChanged\0\0"
    "brake_jointChanged\0hand_brake_jointChanged\0"
    "steering_jointChanged\0updated_info\0"
    "timeout\0update_vilma_info\0setGas_joint\0"
    "name\0setBrake_joint\0setHand_brake_joint\0"
    "setSteering_joint\0accelerate\0deaccelerate\0"
    "use_hand_brake\0use_Steering\0value\0"
    "use_brake_push\0use_brake_release\0"
    "gas_joint\0brake_joint\0hand_brake_joint\0"
    "steering_joint\0color\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Vilma_controler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       5,  126, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x05,
       3,    0,  100,    2, 0x05,
       4,    0,  101,    2, 0x05,
       5,    0,  102,    2, 0x05,
       6,    0,  103,    2, 0x05,
       7,    0,  104,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,  105,    2, 0x0a,

 // methods: name, argc, parameters, tag, flags
       9,    1,  106,    2, 0x02,
      11,    1,  109,    2, 0x02,
      12,    1,  112,    2, 0x02,
      13,    1,  115,    2, 0x02,
      14,    0,  118,    2, 0x02,
      15,    0,  119,    2, 0x02,
      16,    0,  120,    2, 0x02,
      17,    1,  121,    2, 0x02,
      19,    0,  124,    2, 0x02,
      20,    0,  125,    2, 0x02,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   18,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      21, QMetaType::QString, 0x00095103,
      22, QMetaType::QString, 0x00095103,
      23, QMetaType::QString, 0x00095103,
      24, QMetaType::QString, 0x00095103,
      25, QMetaType::QColor, 0x00095103,

       0        // eod
};

void Vilma_controler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Vilma_controler *_t = static_cast<Vilma_controler *>(_o);
        switch (_id) {
        case 0: _t->gas_jointChanged(); break;
        case 1: _t->brake_jointChanged(); break;
        case 2: _t->hand_brake_jointChanged(); break;
        case 3: _t->steering_jointChanged(); break;
        case 4: _t->updated_info(); break;
        case 5: _t->timeout(); break;
        case 6: _t->update_vilma_info(); break;
        case 7: _t->setGas_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setBrake_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setHand_brake_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setSteering_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->accelerate(); break;
        case 12: _t->deaccelerate(); break;
        case 13: _t->use_hand_brake(); break;
        case 14: _t->use_Steering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 15: _t->use_brake_push(); break;
        case 16: _t->use_brake_release(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Vilma_controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vilma_controler::gas_jointChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Vilma_controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vilma_controler::brake_jointChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Vilma_controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vilma_controler::hand_brake_jointChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Vilma_controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vilma_controler::steering_jointChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (Vilma_controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vilma_controler::updated_info)) {
                *result = 4;
            }
        }
        {
            typedef void (Vilma_controler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Vilma_controler::timeout)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Vilma_controler::staticMetaObject = {
    { &QQuickItem::staticMetaObject, qt_meta_stringdata_Vilma_controler.data,
      qt_meta_data_Vilma_controler,  qt_static_metacall, 0, 0}
};


const QMetaObject *Vilma_controler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vilma_controler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Vilma_controler.stringdata))
        return static_cast<void*>(const_cast< Vilma_controler*>(this));
    return QQuickItem::qt_metacast(_clname);
}

int Vilma_controler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = gas_joint(); break;
        case 1: *reinterpret_cast< QString*>(_v) = brake_joint(); break;
        case 2: *reinterpret_cast< QString*>(_v) = hand_brake_joint(); break;
        case 3: *reinterpret_cast< QString*>(_v) = steering_joint(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = color(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setGas_joint(*reinterpret_cast< QString*>(_v)); break;
        case 1: setBrake_joint(*reinterpret_cast< QString*>(_v)); break;
        case 2: setHand_brake_joint(*reinterpret_cast< QString*>(_v)); break;
        case 3: setSteering_joint(*reinterpret_cast< QString*>(_v)); break;
        case 4: setColor(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Vilma_controler::gas_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Vilma_controler::brake_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Vilma_controler::hand_brake_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Vilma_controler::steering_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Vilma_controler::updated_info()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Vilma_controler::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
