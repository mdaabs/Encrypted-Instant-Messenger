/****************************************************************************
** Meta object code from reading C++ file 'tabdialog.h'
**
** Created: Tue May 13 03:48:24 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tabdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TabDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   33,   10,   10, 0x08,
      60,   10,   10,   10, 0x08,
      83,   78,   74,   10, 0x08,
     110,   11,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TabDialog[] = {
    "TabDialog\0\0t\0senttomain(string*)\0f,l\0"
    "testrev(string,string)\0delmytab(int)\0"
    "int\0item\0newconvo(QListWidgetItem*)\0"
    "sendtoser(string*)\0"
};

void TabDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TabDialog *_t = static_cast<TabDialog *>(_o);
        switch (_id) {
        case 0: _t->senttomain((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 1: _t->testrev((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 2: _t->delmytab((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: { int _r = _t->newconvo((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->sendtoser((*reinterpret_cast< string*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TabDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TabDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TabDialog,
      qt_meta_data_TabDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TabDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TabDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TabDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabDialog))
        return static_cast<void*>(const_cast< TabDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TabDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TabDialog::senttomain(string * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
