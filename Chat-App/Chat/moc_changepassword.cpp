/****************************************************************************
** Meta object code from reading C++ file 'changepassword.h'
**
** Created: Tue May 13 03:48:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "changepassword.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changepassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_changepassword[] = {

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
      16,   15,   15,   15, 0x05,
      31,   29,   15,   15, 0x05,
      54,   52,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   15,   15,   15, 0x0a,
      91,   15,   15,   15, 0x0a,
     100,   15,   15,   15, 0x0a,
     121,  119,   15,   15, 0x0a,
     143,   15,   15,   15, 0x0a,
     160,   29,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_changepassword[] = {
    "changepassword\0\0logconnect()\0g\0"
    "receivedthis(string)\0p\0connectworked(QString*)\0"
    "changepass()\0cancel()\0toggleConnection()\0"
    "t\0sendMessage(QString*)\0receiveMessage()\0"
    "checkiftrue(string)\0"
};

void changepassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        changepassword *_t = static_cast<changepassword *>(_o);
        switch (_id) {
        case 0: _t->logconnect(); break;
        case 1: _t->receivedthis((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->connectworked((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 3: _t->changepass(); break;
        case 4: _t->cancel(); break;
        case 5: _t->toggleConnection(); break;
        case 6: _t->sendMessage((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 7: _t->receiveMessage(); break;
        case 8: _t->checkiftrue((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData changepassword::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject changepassword::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_changepassword,
      qt_meta_data_changepassword, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &changepassword::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *changepassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *changepassword::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_changepassword))
        return static_cast<void*>(const_cast< changepassword*>(this));
    return QDialog::qt_metacast(_clname);
}

int changepassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void changepassword::logconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void changepassword::receivedthis(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void changepassword::connectworked(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
