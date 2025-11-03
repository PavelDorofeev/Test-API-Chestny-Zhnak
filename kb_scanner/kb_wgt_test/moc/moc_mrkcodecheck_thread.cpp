/****************************************************************************
** Meta object code from reading C++ file 'mrkcodecheck_thread.h'
**
** Created: Tue 22. Jul 17:02:48 2025
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../marking/mrkcodecheck_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mrkcodecheck_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MrkCodeCheck_Thread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   21,   20,   20, 0x05,
      57,   55,   20,   20, 0x25,
      79,   20,   20,   20, 0x05,
     112,   96,   20,   20, 0x05,
     177,   20,   20,   20, 0x05,
     207,   20,   20,   20, 0x05,
     224,  218,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     266,   20,   20,   20, 0x0a,
     281,  218,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MrkCodeCheck_Thread[] = {
    "MrkCodeCheck_Thread\0\0,,code\0"
    "sig_ilog(QString,int,bool)\0,\0"
    "sig_ilog(QString,int)\0sig_is_working()\0"
    "mrkIn,,,err_str\0"
    "sig_cb_MT_mrk_has_checked(MRK_CODE_TO_VALIDATE,bool,int,QString)\0"
    "sig_addNewMrkCodeToValidate()\0sig_stop()\0"
    "mrkIn\0sig_startToValidate(MRK_CODE_TO_VALIDATE)\0"
    "slot_MT_stop()\0"
    "slot_addNewMrkCodeToValidate(MRK_CODE_TO_VALIDATE)\0"
};

void MrkCodeCheck_Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MrkCodeCheck_Thread *_t = static_cast<MrkCodeCheck_Thread *>(_o);
        switch (_id) {
        case 0: _t->sig_ilog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->sig_ilog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sig_is_working(); break;
        case 3: _t->sig_cb_MT_mrk_has_checked((*reinterpret_cast< const MRK_CODE_TO_VALIDATE(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 4: _t->sig_addNewMrkCodeToValidate(); break;
        case 5: _t->sig_stop(); break;
        case 6: _t->sig_startToValidate((*reinterpret_cast< const MRK_CODE_TO_VALIDATE(*)>(_a[1]))); break;
        case 7: _t->slot_MT_stop(); break;
        case 8: _t->slot_addNewMrkCodeToValidate((*reinterpret_cast< const MRK_CODE_TO_VALIDATE(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MrkCodeCheck_Thread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MrkCodeCheck_Thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MrkCodeCheck_Thread,
      qt_meta_data_MrkCodeCheck_Thread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MrkCodeCheck_Thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MrkCodeCheck_Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MrkCodeCheck_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MrkCodeCheck_Thread))
        return static_cast<void*>(const_cast< MrkCodeCheck_Thread*>(this));
    return QThread::qt_metacast(_clname);
}

int MrkCodeCheck_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void MrkCodeCheck_Thread::sig_ilog(const QString & _t1, int _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void MrkCodeCheck_Thread::sig_is_working()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MrkCodeCheck_Thread::sig_cb_MT_mrk_has_checked(const MRK_CODE_TO_VALIDATE & _t1, bool _t2, int _t3, const QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MrkCodeCheck_Thread::sig_addNewMrkCodeToValidate()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MrkCodeCheck_Thread::sig_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MrkCodeCheck_Thread::sig_startToValidate(const MRK_CODE_TO_VALIDATE & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
