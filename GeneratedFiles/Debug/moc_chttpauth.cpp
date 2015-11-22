/****************************************************************************
** Meta object code from reading C++ file 'chttpauth.h'
**
** Created: Mon Dec 12 11:55:23 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chttpauth.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chttpauth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CHttpAuth[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      51,   35,   10,   10, 0x08,
      84,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CHttpAuth[] = {
    "CHttpAuth\0\0on_pushButton_clicked()\0"
    "requestId,error\0requestFinishOperation(int,bool)\0"
    "readData(QHttpResponseHeader)\0"
};

const QMetaObject CHttpAuth::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CHttpAuth,
      qt_meta_data_CHttpAuth, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CHttpAuth::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CHttpAuth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CHttpAuth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CHttpAuth))
        return static_cast<void*>(const_cast< CHttpAuth*>(this));
    return QWidget::qt_metacast(_clname);
}

int CHttpAuth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_clicked(); break;
        case 1: requestFinishOperation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: readData((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
