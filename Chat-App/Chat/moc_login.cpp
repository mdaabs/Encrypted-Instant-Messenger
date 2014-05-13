/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created: Tue May 13 03:48:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "login.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_login[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      20,    6,    6,    6, 0x05,
      36,    6,    6,    6, 0x05,
      54,   52,    6,    6, 0x05,
      75,   52,    6,    6, 0x05,
      97,   95,    6,    6, 0x05,
     118,   52,    6,    6, 0x05,
     138,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     151,    6,    6,    6, 0x0a,
     161,    6,    6,    6, 0x0a,
     175,    6,    6,    6, 0x0a,
     188,    6,    6,    6, 0x0a,
     200,    6,    6,    6, 0x0a,
     211,    6,    6,    6, 0x0a,
     230,   52,    6,    6, 0x0a,
     251,    6,    6,    6, 0x0a,
     268,    6,    6,    6, 0x0a,
     282,    6,    6,    6, 0x0a,
     297,   52,    6,    6, 0x0a,
     313,   52,    6,    6, 0x0a,
     334,   52,    6,    6, 0x0a,
     356,  354,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_login[] = {
    "login\0\0logconnect()\0connectfailed()\0"
    "connectworked()\0t\0gotlogstatus(string)\0"
    "gotkeyandiv(string)\0f\0loginfosend(string*)\0"
    "sendforkey(string*)\0enterlogin()\0"
    "opennew()\0changepassw()\0checklogin()\0"
    "settingsb()\0updateip()\0toggleConnection()\0"
    "sendMessage(string*)\0receiveMessage()\0"
    "connecttrue()\0connectfalse()\0"
    "logoff(string*)\0getlogstatus(string)\0"
    "getkeyandiv(string)\0e\0keyPressEvent(QKeyEvent*)\0"
};

void login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        login *_t = static_cast<login *>(_o);
        switch (_id) {
        case 0: _t->logconnect(); break;
        case 1: _t->connectfailed(); break;
        case 2: _t->connectworked(); break;
        case 3: _t->gotlogstatus((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->gotkeyandiv((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 5: _t->loginfosend((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 6: _t->sendforkey((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 7: _t->enterlogin(); break;
        case 8: _t->opennew(); break;
        case 9: _t->changepassw(); break;
        case 10: _t->checklogin(); break;
        case 11: _t->settingsb(); break;
        case 12: _t->updateip(); break;
        case 13: _t->toggleConnection(); break;
        case 14: _t->sendMessage((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 15: _t->receiveMessage(); break;
        case 16: _t->connecttrue(); break;
        case 17: _t->connectfalse(); break;
        case 18: _t->logoff((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 19: _t->getlogstatus((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 20: _t->getkeyandiv((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 21: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData login::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject login::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_login,
      qt_meta_data_login, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &login::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *login::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_login))
        return static_cast<void*>(const_cast< login*>(this));
    return QDialog::qt_metacast(_clname);
}

int login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void login::logconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void login::connectfailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void login::connectworked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void login::gotlogstatus(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void login::gotkeyandiv(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void login::loginfosend(string * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void login::sendforkey(string * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void login::enterlogin()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
