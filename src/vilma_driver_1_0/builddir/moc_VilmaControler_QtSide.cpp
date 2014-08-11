/****************************************************************************
** Meta object code from reading C++ file 'VilmaControler_QtSide.h'
**
** Created: Mon Aug 4 03:34:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/VilmaControler_QtSide.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VilmaControler_QtSide.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VilmaControler_QtSide[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
      19,  169, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

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
     249,   22,   22,   22, 0x05,
     269,   22,   22,   22, 0x05,
     289,   22,   22,   22, 0x05,
     309,   22,   22,   22, 0x05,
     325,   22,   22,   22, 0x05,
     341,   22,   22,   22, 0x05,
     357,   22,   22,   22, 0x05,
     379,   22,   22,   22, 0x05,
     401,   22,   22,   22, 0x05,
     423,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     445,   22,   22,   22, 0x0a,
     465,   22,   22,   22, 0x0a,

 // methods: signature, parameters, type, tag, flags
     482,   22,   22,   22, 0x02,
     497,   22,   22,   22, 0x02,
     510,   22,   22,   22, 0x02,
     525,   22,   22,   22, 0x02,
     548,  542,   22,   22, 0x02,
     568,   22,   22,   22, 0x02,
     585,   22,   22,   22, 0x02,
     605,   22,   22,   22, 0x02,

 // properties: name, type, flags
     627,  619, 0x0a095001,
     637,  619, 0x0a095103,
     649,  619, 0x0a095103,
     666,  619, 0x0a095103,
     681,  619, 0x0a095103,
     696,  619, 0x0a095103,
     711,  619, 0x0a095103,
     726,  619, 0x0a095103,
     741,  619, 0x0a095003,
     747,  619, 0x0a095001,
     757,  619, 0x0a095001,
     767,  619, 0x0a095001,
     777,  619, 0x0a095103,
     784,  619, 0x0a095103,
     791,  619, 0x0a095103,
     798,  619, 0x0a095103,
     811,  619, 0x0a095103,
     824,  619, 0x0a095103,
     837,  619, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_VilmaControler_QtSide[] = {
    "VilmaControler_QtSide\0\0gas_jointChanged()\0"
    "brake_jointChanged()\0hand_brake_jointChanged()\0"
    "steering_jointChanged()\0bl_wheel_speedChanged()\0"
    "br_wheel_speedChanged()\0fl_wheel_speedChanged()\0"
    "fr_wheel_speedChanged()\0gearsChanged()\0"
    "updated_info()\0timeout()\0x_positionChanged()\0"
    "y_positionChanged()\0z_positionChanged()\0"
    "xtwistChanged()\0ytwistChanged()\0"
    "ztwistChanged()\0xorientationChanged()\0"
    "yorientationChanged()\0zorientationChanged()\0"
    "worientationChanged()\0update_vilma_info()\0"
    "maintain_speed()\0change_gears()\0"
    "accelerate()\0deaccelerate()\0"
    "use_hand_brake()\0value\0use_Steering(float)\0"
    "use_brake_push()\0use_brake_release()\0"
    "reset_state()\0QString\0gas_joint\0"
    "brake_joint\0hand_brake_joint\0"
    "steering_joint\0bl_wheel_speed\0"
    "br_wheel_speed\0fl_wheel_speed\0"
    "fr_wheel_speed\0gears\0xposition\0yposition\0"
    "zposition\0xtwist\0ytwist\0ztwist\0"
    "xorientation\0yorientation\0zorientation\0"
    "worientation\0"
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
        case 11: _t->x_positionChanged(); break;
        case 12: _t->y_positionChanged(); break;
        case 13: _t->z_positionChanged(); break;
        case 14: _t->xtwistChanged(); break;
        case 15: _t->ytwistChanged(); break;
        case 16: _t->ztwistChanged(); break;
        case 17: _t->xorientationChanged(); break;
        case 18: _t->yorientationChanged(); break;
        case 19: _t->zorientationChanged(); break;
        case 20: _t->worientationChanged(); break;
        case 21: _t->update_vilma_info(); break;
        case 22: _t->maintain_speed(); break;
        case 23: _t->change_gears(); break;
        case 24: _t->accelerate(); break;
        case 25: _t->deaccelerate(); break;
        case 26: _t->use_hand_brake(); break;
        case 27: _t->use_Steering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 28: _t->use_brake_push(); break;
        case 29: _t->use_brake_release(); break;
        case 30: _t->reset_state(); break;
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
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
        case 9: *reinterpret_cast< QString*>(_v) = xposition(); break;
        case 10: *reinterpret_cast< QString*>(_v) = yposition(); break;
        case 11: *reinterpret_cast< QString*>(_v) = zposition(); break;
        case 12: *reinterpret_cast< QString*>(_v) = readXtwist(); break;
        case 13: *reinterpret_cast< QString*>(_v) = readYtwist(); break;
        case 14: *reinterpret_cast< QString*>(_v) = readZtwist(); break;
        case 15: *reinterpret_cast< QString*>(_v) = readXorientation(); break;
        case 16: *reinterpret_cast< QString*>(_v) = readYorientation(); break;
        case 17: *reinterpret_cast< QString*>(_v) = readZorientation(); break;
        case 18: *reinterpret_cast< QString*>(_v) = readWorientation(); break;
        }
        _id -= 19;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setBrake_joint(*reinterpret_cast< QString*>(_v)); break;
        case 2: setHand_brake_joint(*reinterpret_cast< QString*>(_v)); break;
        case 3: setSteering_joint(*reinterpret_cast< QString*>(_v)); break;
        case 4: setBl_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 5: setBr_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 6: setFl_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 7: setFr_wheel_speed(*reinterpret_cast< QString*>(_v)); break;
        case 8: setgears(*reinterpret_cast< QString*>(_v)); break;
        case 12: setXtwist(*reinterpret_cast< QString*>(_v)); break;
        case 13: setYtwist(*reinterpret_cast< QString*>(_v)); break;
        case 14: setZtwist(*reinterpret_cast< QString*>(_v)); break;
        case 15: setXorientation(*reinterpret_cast< QString*>(_v)); break;
        case 16: setYorientation(*reinterpret_cast< QString*>(_v)); break;
        case 17: setZorientation(*reinterpret_cast< QString*>(_v)); break;
        case 18: setWorientation(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 19;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 19;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 19;
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

// SIGNAL 11
void VilmaControler_QtSide::x_positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void VilmaControler_QtSide::y_positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void VilmaControler_QtSide::z_positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void VilmaControler_QtSide::xtwistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void VilmaControler_QtSide::ytwistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, 0);
}

// SIGNAL 16
void VilmaControler_QtSide::ztwistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, 0);
}

// SIGNAL 17
void VilmaControler_QtSide::xorientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, 0);
}

// SIGNAL 18
void VilmaControler_QtSide::yorientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, 0);
}

// SIGNAL 19
void VilmaControler_QtSide::zorientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, 0);
}

// SIGNAL 20
void VilmaControler_QtSide::worientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, 0);
}
QT_END_MOC_NAMESPACE
