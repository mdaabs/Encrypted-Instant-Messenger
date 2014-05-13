/****************************************************************************
** Meta object code from reading C++ file 'newuser.h'
**
** Created: Tue May 13 03:48:30 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newuser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_newuser[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      24,   22,    8,    8, 0x05,
      47,   45,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,    8,    8,    8, 0x0a,
      81,    8,    8,    8, 0x0a,
      90,    8,    8,    8, 0x0a,
     111,  109,    8,    8, 0x0a,
     133,    8,    8,    8, 0x0a,
     150,   22,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_newuser[] = {
    "newuser\0\0logconnect()\0g\0receivedthis(string)\0"
    "p\0connectworked(QString*)\0adduser()\0"
    "cancel()\0toggleConnection()\0t\0"
    "sendMessage(QString*)\0receiveMessage()\0"
    "checkiftrue(string)\0"
};

void newuser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        newuser *_t = static_cast<newuser *>(_o);
        switch (_id) {
        case 0: _t->logconnect(); break;
        case 1: _t->receivedthis((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->connectworked((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 3: _t->adduser(); break;
        case 4: _t->cancel(); break;
        case 5: _t->toggleConnection(); break;
        case 6: _t->sendMessage((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 7: _t->receiveMessage(); break;
        case 8: _t->checkiftrue((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData newuser::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject newuser::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_newuser,
      qt_meta_data_newuser, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &newuser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *newuser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *newuser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_newuser))
        return static_cast<void*>(const_cast< newuser*>(this));
    return QDialog::qt_metacast(_clname);
}

int newuser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void newuser::logconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void newuser::receivedthis(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void newuser::connectworked(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
