/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue May 13 03:48:22 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      45,   11,   11,   11, 0x05,
      63,   59,   11,   11, 0x05,
      88,   86,   11,   11, 0x05,
     107,   86,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     129,   11,   11,   11, 0x0a,
     149,   11,  145,   11, 0x0a,
     163,   11,   11,   11, 0x0a,
     172,   86,   11,   11, 0x0a,
     191,   11,   11,   11, 0x0a,
     203,   86,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0item\0convonode(QListWidgetItem*)\0"
    "refreshmain()\0f,l\0testrec(string,string)\0"
    "g\0sendtolog(string*)\0sendtologoff(string*)\0"
    "Temprec(string)\0int\0loadFriends()\0"
    "logoff()\0sentosock(string*)\0addfriend()\0"
    "add(QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->convonode((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->refreshmain(); break;
        case 2: _t->testrec((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2]))); break;
        case 3: _t->sendtolog((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 4: _t->sendtologoff((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 5: _t->Temprec((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 6: { int _r = _t->loadFriends();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->logoff(); break;
        case 8: _t->sentosock((*reinterpret_cast< string*(*)>(_a[1]))); break;
        case 9: _t->addfriend(); break;
        case 10: _t->add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::convonode(QListWidgetItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::refreshmain()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::testrec(string _t1, string _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendtolog(string * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sendtologoff(string * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
