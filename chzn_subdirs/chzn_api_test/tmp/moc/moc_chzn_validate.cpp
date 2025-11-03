/****************************************************************************
** Meta object code from reading C++ file 'chzn_validate.h'
**
** Created: Mon 3. Nov 20:40:47 2025
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../chzn/chzn_validate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chzn_validate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChZn_Validate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      72,   53,   14,   14, 0x05,
     114,  104,   14,   14, 0x25,
     145,  141,   14,   14, 0x25,

 // slots: signature, parameters, type, tag, flags
     197,  176,  167,   14, 0x0a,
     241,  227,  167,   14, 0x2a,
     274,  267,  167,   14, 0x0a,
     328,  313,  167,   14, 0x0a,
     374,  313,  167,   14, 0x0a,
     417,  313,  167,   14, 0x0a,
     469,  313,  167,   14, 0x0a,
     526,  313,  167,   14, 0x0a,
     573,  313,  167,   14, 0x0a,
     626,  313,  167,   14, 0x0a,
     672,  313,  167,   14, 0x0a,
     722,  313,  167,   14, 0x0a,
     768,  313,  167,   14, 0x0a,
     829,  313,  167,   14, 0x0a,
     891,  313,  167,   14, 0x0a,
     936,  313,  167,   14, 0x0a,
     987,  313,  167,   14, 0x0a,
    1037,  313,  167,   14, 0x0a,
    1079,  313,  167,   14, 0x0a,
    1123,  313,  167,   14, 0x0a,
    1170,  313,  167,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChZn_Validate[] = {
    "ChZn_Validate\0\0,\0sig_log(QString,qp::gui::LOG_STYLE)\0"
    "str,error,closeWin\0sig_finished(QString,bool,bool)\0"
    "str,error\0sig_finished(QString,bool)\0"
    "str\0sig_finished(QString)\0QVariant\0"
    "marking_token,kontur\0slot_getCdnHosts(QString,int)\0"
    "marking_token\0slot_getCdnHosts(QString)\0"
    "params\0slot_getCdnHostValidation(QVariantMap)\0"
    "params,bodyObj\0"
    "slot_get_codes_check(QVariantMap,QVariantMap)\0"
    "slot_get_auth_key(QVariantMap,QVariantMap)\0"
    "slot_get_auth_simpleSignIn(QVariantMap,QVariantMap)\0"
    "slot_get_auth_permissive_access(QVariantMap,QVariantMap)\0"
    "slot_get_product_info(QVariantMap,QVariantMap)\0"
    "slot_get_short_product_info(QVariantMap,QVariantMap)\0"
    "slot_get_cises_info(QVariantMap,QVariantList)\0"
    "slot_get_cises_ease_info(QVariantMap,QVariantMap)\0"
    "slot_get_cises_check(QVariantMap,QVariantMap)\0"
    "slot_get_cises_check_history_create(QVariantMap,QVariantMap)\0"
    "slot_get_cises_check_history_receive(QVariantMap,QVariantMap)\0"
    "slot_get_nk_product(QVariantMap,QVariantMap)\0"
    "slot_get_nk_short_product(QVariantMap,QVariantMap)\0"
    "slot_get_nk_feed_product(QVariantMap,QVariantMap)\0"
    "slot_get_lm_init(QVariantMap,QVariantMap)\0"
    "slot_get_lm_status(QVariantMap,QVariantMap)\0"
    "slot_get_lm_cis_check(QVariantMap,QVariantMap)\0"
    "slot_get_lm_cis_outCheck(QVariantMap,QVariantMap)\0"
};

void ChZn_Validate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChZn_Validate *_t = static_cast<ChZn_Validate *>(_o);
        switch (_id) {
        case 0: _t->sig_log((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< qp::gui::LOG_STYLE(*)>(_a[2]))); break;
        case 1: _t->sig_finished((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->sig_finished((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->sig_finished((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { QVariant _r = _t->slot_getCdnHosts((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QVariant _r = _t->slot_getCdnHosts((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { QVariant _r = _t->slot_getCdnHostValidation((*reinterpret_cast< const QVariantMap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: { QVariant _r = _t->slot_get_codes_check((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 8: { QVariant _r = _t->slot_get_auth_key((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 9: { QVariant _r = _t->slot_get_auth_simpleSignIn((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 10: { QVariant _r = _t->slot_get_auth_permissive_access((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 11: { QVariant _r = _t->slot_get_product_info((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 12: { QVariant _r = _t->slot_get_short_product_info((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 13: { QVariant _r = _t->slot_get_cises_info((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 14: { QVariant _r = _t->slot_get_cises_ease_info((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 15: { QVariant _r = _t->slot_get_cises_check((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 16: { QVariant _r = _t->slot_get_cises_check_history_create((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 17: { QVariant _r = _t->slot_get_cises_check_history_receive((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 18: { QVariant _r = _t->slot_get_nk_product((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 19: { QVariant _r = _t->slot_get_nk_short_product((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 20: { QVariant _r = _t->slot_get_nk_feed_product((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 21: { QVariant _r = _t->slot_get_lm_init((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 22: { QVariant _r = _t->slot_get_lm_status((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 23: { QVariant _r = _t->slot_get_lm_cis_check((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 24: { QVariant _r = _t->slot_get_lm_cis_outCheck((*reinterpret_cast< const QVariantMap(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ChZn_Validate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChZn_Validate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChZn_Validate,
      qt_meta_data_ChZn_Validate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChZn_Validate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChZn_Validate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChZn_Validate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChZn_Validate))
        return static_cast<void*>(const_cast< ChZn_Validate*>(this));
    if (!strcmp(_clname, "ADbg"))
        return static_cast< ADbg*>(const_cast< ChZn_Validate*>(this));
    return QObject::qt_metacast(_clname);
}

int ChZn_Validate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void ChZn_Validate::sig_log(const QString & _t1, qp::gui::LOG_STYLE _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChZn_Validate::sig_finished(const QString & _t1, bool _t2, bool _t3)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(const_cast< ChZn_Validate *>(this), &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
