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
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,   20,   27,   27, 0x0a,
      28,   27,   27,   27, 0x0a,
      38,   27,   27,   27, 0x0a,
      49,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dcmotor[] = {
    "Dcmotor\0setPwm(int)\0pwmVal\0\0forward()\0"
    "backward()\0stop()\0"
};

void Dcmotor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dcmotor *_t = static_cast<Dcmotor *>(_o);
        switch (_id) {
        case 0: _t->setPwm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->forward(); break;
        case 2: _t->backward(); break;
        case 3: _t->stop(); break;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE