/****************************************************************************
** Meta object code from reading C++ file 'encoder.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../encoder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'encoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Encoder[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,   28,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Encoder[] = {
    "Encoder\0sgn_StartCounting()\0\0countTicks()\0"
};

void Encoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Encoder *_t = static_cast<Encoder *>(_o);
        switch (_id) {
        case 0: _t->sgn_StartCounting(); break;
        case 1: _t->countTicks(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Encoder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Encoder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Encoder,
      qt_meta_data_Encoder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Encoder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Encoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Encoder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Encoder))
        return static_cast<void*>(const_cast< Encoder*>(this));
    return QObject::qt_metacast(_clname);
}

int Encoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Encoder::sgn_StartCounting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
