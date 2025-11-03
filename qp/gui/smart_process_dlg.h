#ifndef SMART_PROCESS_DLG_123_H
#define SMART_PROCESS_DLG_123_H

#include <QDialog>
#include <QFrame>
#include <QMetaType>
#include <QSettings>

#include "qp/core/qp_core.h"
#include "qp/gui/qp_gui.h"


namespace Ui {
class Smart_Process_Dlg;
}

#include "qp/gui/dll_qp_gui_global.h"

class LIB_PREFIX_QP_GUI Smart_Process_Dlg : public QDialog
{
    Q_OBJECT

public:

    explicit Smart_Process_Dlg( QWidget *parent = 0,
                                const QObject * slotOwn =0 ,
                                const QString &hdr=QString(),
                                const QString &txt1=QString(),
                                const QString &txt2=QString(),
                                const QString &slotName=QString() ,
                                const QList<const QObject*> &objLst = QList<const QObject*>(),
                                const QList<QVariant>& pars = QList<QVariant>(),
                                bool closeWindowOnFinished = true, // если false, то окно будет оставаться только при ошибке
                                bool silent = false
            );

    static QString reestr_tlv_files;

    virtual ~Smart_Process_Dlg();


    QpSingleShotTimer * tmr;

    bool getInvokeMethodResult() const ;

    QVariant getRetValue() const ;

    virtual QString getReestrPrefix() const;
    QSize getMinimumSize() const;


signals:
//    void closeWidget();

public slots:


    void slot_log( const QString &description , qp::gui::LOG_STYLE style ); // при экспорте библиотеки проблем нет
    void slot_finished(QString str, bool error); // default values are just in sig_finish

    void slot_rangeChanged(int,int);
    void slot_linkActivated(QString href);

    void on_btn_Close_clicked();

    void slot_retResult(bool resInvokeMethod,const QVariant&);

    void on_btn_save_to_file_clicked();

private slots:

    void on_btn_maximizedShow_clicked();

private:

    QVariant retVal;
    bool resInvokeMethod;

    const QString &slot_name;
    const QList<QVariant>& pars;
    const QObject * slotOwner;
    bool closeWindowOnFinished;
    bool silent;                    // если true, то  окно всегда закрывается автоматом
    QPointF m_mousePoint;

    QSettings sett;

    Ui::Smart_Process_Dlg *ui;
};

// здесь лажает при линковке
//Q_DECLARE_METATYPE(Smart_Process_Dlg);  // чтобы стиль устанавливать "Smart_Process_Dlg{...

#endif // Smart_Process_Dlg_H
