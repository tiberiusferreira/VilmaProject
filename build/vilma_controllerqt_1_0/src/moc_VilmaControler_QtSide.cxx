/****************************************************************************
** Meta object code from reading C++ file 'VilmaControler_QtSide.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/vilma_controllerqt_1_0/src/VilmaControler_QtSide.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VilmaControler_QtSide.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VilmaControler_QtSide[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       9,  159, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      42,   22,   22,   22, 0x05,
      63,   22,   22,   22, 0x05,
      89,   22,   22,   22, 0x05,
     113,   22,   22,   22, 0x05,
     137,   22,   22,   22, 0x05,
     161,   22,   22,   22, 0x05,
     185,   22,   22,   22, 0x05,
     209,   22,   22,   22, 0x05,
     224,   22,   22,   22, 0x05,
     239,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     249,   22,   22,   22, 0x0a,

 // methods: signature, parameters, type, tag, flags
     274,  269,   22,   22, 0x02,
     296,  269,   22,   22, 0x02,
     320,  269,   22,   22, 0x02,
     349,  269,   22,   22, 0x02,
     376,  269,   22,   22, 0x02,
     403,  269,   22,   22, 0x02,
     430,  269,   22,   22, 0x02,
     457,  269,   22,   22, 0x02,
     484,  269,   22,   22, 0x02,
     502,   22,   22,   22, 0x02,
     517,   22,   22,   22, 0x02,
     530,   22,   22,   22, 0x02,
     545,   22,   22,   22, 0x02,
     568,  562,   22,   22, 0x02,
     588,   22,   22,   22, 0x02,
     605,   22,   22,   22, 0x02,
     625,   22,   22,   22, 0x02,

 // properties: name, type, flags
     647,  639, 0x0a095103,
     657,  639, 0x0a095103,
     669,  639, 0x0a095103,
     686,  639, 0x0a095103,
     701,  639, 0x0a095103,
     716,  639, 0x0a095103,
     731,  639, 0x0a095103,
     746,  639, 0x0a095103,
     761,  639, 0x0a095003,

       0        // eod
};

static const char qt_meta_stringdata_VilmaControler_QtSide[] = {
    "VilmaControler_QtSide\0\0gas_jointChanged()\0"
    "brake_jointChanged()\0hand_brake_jointChanged()\0"
    "steering_jointChanged()\0bl_wheel_speedChanged()\0"
    "br_wheel_speedChanged()\0fl_wheel_speedChanged()\0"
    "fr_wheel_speedChanged()\0gearsChanged()\0"
    "updated_info()\0timeout()\0update_vilma_info()\0"
    "name\0setGas_joint(QString)\0"
    "setBrake_joint(QString)\0"
    "setHand_brake_joint(QString)\0"
    "setSteering_joint(QString)\0"
    "setBl_wheel_speed(QString)\0"
    "setBr_wheel_speed(QString)\0"
    "setFl_wheel_speed(QString)\0"
    "setFr_wheel_speed(QString)\0setgears(QString)\0"
    "change_gears()\0accelerate()\0deaccelerate()\0"
    "use_hand_brake()\0value\0use_Steering(float)\0"
    "use_brake_push()\0use_brake_release()\0"
    "reset_state()\0QString\0gas_joint\0"
    "brake_joint\0hand_brake_joint\0"
    "steering_joint\0bl_wheel_speed\0"
    "br_wheel_speed\0fl_wheel_speed\0"
    "fr_wheel_speed\0gears\0"
};

void VilmaControler_QtSide::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VilmaControler_QtSide *_t = static_cast<VilmaControler_QtSide *>(_o);
        switch (_id) {
        case 0: _t->gas_jointChanged(); break;
        case 1: _t->brake_jointChanged(); break;
        case 2: _t->hand_brake_jointChanged(); break;
        case 3: _t->steering_jointChanged(); break;
        case 4: _t->bl_wheel_speedChanged(); break;
        case 5: _t->br_wheel_speedChanged(); break;
        case 6: _t->fl_wheel_speedChanged(); break;
        case 7: _t->fr_wheel_speedChanged(); break;
        case 8: _t->gearsChanged(); break;
        case 9: _t->updated_info(); break;
        case 10: _t->timeout(); break;
        case 11: _t->update_vilma_info(); break;
        case 12: _t->setGas_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->setBrake_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->setHand_brake_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->setSteering_joint((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->setBl_wheel_speed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->setBr_wheel_speed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->setFl_wheel_speed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->setFr_wheel_speed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->setgears((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->change_gears(); break;
        case 22: _t->accelerate(); break;
        case 23: _t->deaccelerate(); break;
        case 24: _t->use_hand_brake(); break;
        case 25: _t->use_Steering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 26: _t->use_brake_push(); break;
        case 27: _t->use_brake_release(); break;
        case 28: _t->reset_state(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VilmaControler_QtSide::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VilmaControler_QtSide::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_VilmaControler_QtSide,
      qt_meta_data_VilmaControler_QtSide, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VilmaControler_QtSide::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VilmaControler_QtSide::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VilmaControler_QtSide::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VilmaControler_QtSide))
        return static_cast<void*>(const_cast< VilmaControler_QtSide*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int VilmaControler_QtSide::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = gas_joint(); break;
        case 1: *reinterpret_cast< QString*>(_v) = brake_joint(); break;
        case 2: *reinterpret_cast< QString*>(_v) = hand_brake_joint(); break;
        case 3: *reinterpret_cast< QString*>(_v) = steering_joint(); break;
        case 4: *reinterpret_cast< QString*>(_v) = bl_wheel_speed(); break;
        case 5: *reinterpret_cast< QString*>(_v) = br_wheel_speed(); break;
        case 6: *reinterpret_cast< QString*>(_v) = fl_wheel_speed(); break;
        case 7: *reinterpret_cast< QString*>(_v) = fr_wheel_speed(); break;
        case 8: *reinterpret_cast< QString*>(_v) = gears(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setGas_joint(*reinterpret_cast< QString*>(_v)); break;
        case 1: setBrake_joint(*reinterpret_cast< QString*>(_v)); break;
        case 2: setHand_brake_joint(*reinterpret_cast< QString*>(_v)); break;
        case 3: setSteering_joint(*reinterpret_cast< QString*>(_v)); break;
        case 4: setBl_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 5: setBr_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 6: setFl_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 7: setFr_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 8: setgears(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VilmaControler_QtSide::gas_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VilmaControler_QtSide::brake_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VilmaControler_QtSide::hand_brake_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void VilmaControler_QtSide::steering_jointChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void VilmaControler_QtSide::bl_wheel_speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void VilmaControler_QtSide::br_wheel_speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void VilmaControler_QtSide::fl_wheel_speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void VilmaControler_QtSide::fr_wheel_speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void VilmaControler_QtSide::gearsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void VilmaControler_QtSide::updated_info()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void VilmaControler_QtSide::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}
QT_END_MOC_NAMESPACE
