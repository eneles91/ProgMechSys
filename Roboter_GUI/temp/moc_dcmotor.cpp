/****************************************************************************
** Meta object code from reading C++ file 'dcmotor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dcmotor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dcmotor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dcmotor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,   25,   25,   25, 0x05,
      26,   25,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   65,   25,   25, 0x0a,
      72,   25,   25,   25, 0x0a,
      87,   25,   25,   25, 0x0a,
     103,   25,   25,   25, 0x0a,
     115,   25,   25,   25, 0x0a,
     136,   25,   25,   25, 0x0a,
     165,  187,   25,   25, 0x0a,
     193,  215,   25,   25, 0x0a,
     221,  243,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dcmotor[] = {
    "Dcmotor\0sgnSpeed(double)\0\0"
    "sgnErrorSpeed(double)\0slot_setPwm(int)\0"
    "pwmVal\0slot_forward()\0slot_backward()\0"
    "slot_stop()\0slot_pidController()\0"
    "slot_getDisplayInformation()\0"
    "slot_setPGain(double)\0pGain\0"
    "slot_setIGain(double)\0iGain\0"
    "slot_setDGain(double)\0dGain\0"
};

void Dcmotor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dcmotor *_t = static_cast<Dcmotor *>(_o);
        switch (_id) {
        case 0: _t->sgnSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->sgnErrorSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->slot_setPwm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_forward(); break;
        case 4: _t->slot_backward(); break;
        case 5: _t->slot_stop(); break;
        case 6: _t->slot_pidController(); break;
        case 7: _t->slot_getDisplayInformation(); break;
        case 8: _t->slot_setPGain((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->slot_setIGain((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->slot_setDGain((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dcmotor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dcmotor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Dcmotor,
      qt_meta_data_Dcmotor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dcmotor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dcmotor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dcmotor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dcmotor))
        return static_cast<void*>(const_cast< Dcmotor*>(this));
    return QObject::qt_metacast(_clname);
}

int Dcmotor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Dcmotor::sgnSpeed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dcmotor::sgnErrorSpeed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
