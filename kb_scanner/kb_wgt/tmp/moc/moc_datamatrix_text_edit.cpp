/****************************************************************************
** Meta object code from reading C++ file 'datamatrix_text_edit.h'
**
** Created: Mon 3. Nov 20:30:19 2025
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../datamatrix_text_edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamatrix_text_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DatamatrixTextEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      41,   19,   19,   19, 0x05,
      71,   67,   19,   19, 0x05,
     115,   19,   19,   19, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_DatamatrixTextEdit[] = {
    "DatamatrixTextEdit\0\0sig_enter_finished()\0"
    "sig_symbol_readden(uchar)\0lst\0"
    "sig_auto_detect_replacement(QList<quint32>)\0"
    "sig_some_errors(QString)\0"
};

void DatamatrixTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DatamatrixTextEdit *_t = static_cast<DatamatrixTextEdit *>(_o);
        switch (_id) {
        case 0: _t->sig_enter_finished(); break;
        case 1: _t->sig_symbol_readden((*reinterpret_cast< const uchar(*)>(_a[1]))); break;
        case 2: _t->sig_auto_detect_replacement((*reinterpret_cast< const QList<quint32>(*)>(_a[1]))); break;
        case 3: _t->sig_some_errors((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DatamatrixTextEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DatamatrixTextEdit::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_DatamatrixTextEdit,
      qt_meta_data_DatamatrixTextEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DatamatrixTextEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DatamatrixTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DatamatrixTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DatamatrixTextEdit))
        return static_cast<void*>(const_cast< DatamatrixTextEdit*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int DatamatrixTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
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
void DatamatrixTextEdit::sig_enter_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DatamatrixTextEdit::sig_symbol_readden(const uchar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DatamatrixTextEdit::sig_auto_detect_replacement(const QList<quint32> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DatamatrixTextEdit::sig_some_errors(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
