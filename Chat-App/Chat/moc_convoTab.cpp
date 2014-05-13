/****************************************************************************
** Meta object code from reading C++ file 'convoTab.h'
**
** Created: Tue May 13 03:48:26 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "convoTab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convoTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_convoTab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,
      30,   10,    9,    9, 0x05,
      54,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_convoTab[] = {
    "convoTab\0\0n\0sendthis(string*)\0"
    "trackingbefore(QString)\0trackingafter(QString)\0"
    "createmessage()\0"
};

void convoTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        convoTab *_t = static_cast<convoTab *>(_o);
        switch (_id) {
        case 0: _t->sendthis((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 1: _t->trackingbefore((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->trackingafter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->createmessage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData convoTab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject convoTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_convoTab,
      qt_meta_data_convoTab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &convoTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *convoTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *convoTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_convoTab))
        return static_cast<void*>(const_cast< convoTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int convoTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void convoTab::sendthis(string * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void convoTab::trackingbefore(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void convoTab::trackingafter(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
