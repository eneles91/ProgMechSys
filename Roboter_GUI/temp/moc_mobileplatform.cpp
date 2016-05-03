/****************************************************************************
** Meta object code from reading C++ file 'mobileplatform.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mobileplatform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mobileplatform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MobilePlatform[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   33,   33,   33, 0x0a,
      34,   33,   33,   33, 0x0a,
      55,   33,   33,   33, 0x0a,
      74,   33,   33,   33, 0x0a,
      94,   33,   33,   33, 0x0a,
     111,   33,   33,   33, 0x0a,
     127,   33,   33,   33, 0x0a,
     145,  164,   33,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MobilePlatform[] = {
    "MobilePlatform\0slot_followLine()\0\0"
    "slot_endFollowLine()\0slot_moveForward()\0"
    "slot_moveBackward()\0slot_moveRight()\0"
    "slot_moveLeft()\0slot_stopMotion()\0"
    "slot_setSpeed(int)\0speed\0"
};

void MobilePlatform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MobilePlatform *_t = static_cast<MobilePlatform *>(_o);
        switch (_id) {
        case 0: _t->slot_followLine(); break;
        case 1: _t->slot_endFollowLine(); break;
        case 2: _t->slot_moveForward(); break;
        case 3: _t->slot_moveBackward(); break;
        case 4: _t->slot_moveRight(); break;
        case 5: _t->slot_moveLeft(); break;
        case 6: _t->slot_stopMotion(); break;
        case 7: _t->slot_setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MobilePlatform::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MobilePlatform::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MobilePlatform,
      qt_meta_data_MobilePlatform, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MobilePlatform::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MobilePlatform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MobilePlatform::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MobilePlatform))
        return static_cast<void*>(const_cast< MobilePlatform*>(this));
    return QObject::qt_metacast(_clname);
}

int MobilePlatform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
