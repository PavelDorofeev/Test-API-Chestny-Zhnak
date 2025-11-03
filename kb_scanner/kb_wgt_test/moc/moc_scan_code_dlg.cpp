/****************************************************************************
** Meta object code from reading C++ file 'scan_code_dlg.h'
**
** Created: Tue 22. Jul 17:23:48 2025
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kb_wgt/scan_code_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scan_code_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Scan_Code_Dlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      44,   14,   14,   14, 0x05,
      60,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   14,   14,   14, 0x0a,
     108,   14,   14,   14, 0x0a,
     135,   14,   14,   14, 0x0a,
     162,  158,   14,   14, 0x0a,
     207,   14,   14,   14, 0x0a,
     233,   14,   14,   14, 0x08,
     257,   14,   14,   14, 0x08,
     280,   14,   14,   14, 0x08,
     304,   14,   14,   14, 0x08,
     321,   14,   14,   14, 0x08,
     348,   14,   14,   14, 0x08,
     374,   14,   14,   14, 0x08,
     416,  408,   14,   14, 0x08,
     457,  408,   14,   14, 0x08,
     489,  408,   14,   14, 0x08,
     528,   14,   14,   14, 0x08,
     558,   14,   14,   14, 0x08,
     593,  408,   14,   14, 0x08,
     629,  408,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Scan_Code_Dlg[] = {
    "Scan_Code_Dlg\0\0sig_scannedCode(MarkingCode)\0"
    "sig_focusOnIn()\0sig_focusOnRedefineLedt()\0"
    "slot_enter_finished()\0slot_symbol_readden(uchar)\0"
    "slot_ledt_redefineGS()\0lst\0"
    "slot_auto_detect_replacement(QList<quint32>)\0"
    "slot_some_errors(QString)\0"
    "on_btn_cancel_clicked()\0on_btn_clear_clicked()\0"
    "on_btn_accept_clicked()\0slot_focusOnIn()\0"
    "slot_focusOnRedefineLedt()\0"
    "on_btn_show_log_clicked()\0"
    "on_btn_save_redifinedGS_clicked()\0"
    "checked\0on_chk_closeWin_afterEnter_toggled(bool)\0"
    "on_chk_showBase64_clicked(bool)\0"
    "on_chk_clearAfterScanned_clicked(bool)\0"
    "on_btn_show_app_log_clicked()\0"
    "on_ledt_redefineGS_returnPressed()\0"
    "on_chk_auto_detection_clicked(bool)\0"
    "on_chk_enable_log_clicked(bool)\0"
};

void Scan_Code_Dlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Scan_Code_Dlg *_t = static_cast<Scan_Code_Dlg *>(_o);
        switch (_id) {
        case 0: _t->sig_scannedCode((*reinterpret_cast< const MarkingCode(*)>(_a[1]))); break;
        case 1: _t->sig_focusOnIn(); break;
        case 2: _t->sig_focusOnRedefineLedt(); break;
        case 3: _t->slot_enter_finished(); break;
        case 4: _t->slot_symbol_readden((*reinterpret_cast< const uchar(*)>(_a[1]))); break;
        case 5: _t->slot_ledt_redefineGS(); break;
        case 6: _t->slot_auto_detect_replacement((*reinterpret_cast< const QList<quint32>(*)>(_a[1]))); break;
        case 7: _t->slot_some_errors((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_btn_cancel_clicked(); break;
        case 9: _t->on_btn_clear_clicked(); break;
        case 10: _t->on_btn_accept_clicked(); break;
        case 11: _t->slot_focusOnIn(); break;
        case 12: _t->slot_focusOnRedefineLedt(); break;
        case 13: _t->on_btn_show_log_clicked(); break;
        case 14: _t->on_btn_save_redifinedGS_clicked(); break;
        case 15: _t->on_chk_closeWin_afterEnter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_chk_showBase64_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_chk_clearAfterScanned_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_btn_show_app_log_clicked(); break;
        case 19: _t->on_ledt_redefineGS_returnPressed(); break;
        case 20: _t->on_chk_auto_detection_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_chk_enable_log_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Scan_Code_Dlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Scan_Code_Dlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Scan_Code_Dlg,
      qt_meta_data_Scan_Code_Dlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Scan_Code_Dlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Scan_Code_Dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Scan_Code_Dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scan_Code_Dlg))
        return static_cast<void*>(const_cast< Scan_Code_Dlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int Scan_Code_Dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Scan_Code_Dlg::sig_scannedCode(const MarkingCode & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Scan_Code_Dlg::sig_focusOnIn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Scan_Code_Dlg::sig_focusOnRedefineLedt()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
