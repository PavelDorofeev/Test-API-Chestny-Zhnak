#ifndef MARKIRIVKA_DLG_H
#define MARKIRIVKA_DLG_H

#include <QDialog>
#include <QValidator>
#include <QSettings>

namespace Ui {
class Scan_Code_Dlg;
}
#include "marking/markingcode.h"

#include "../dll_kb_scanner_global.h"

class LIB_PREFIX_KB_SCANNER  Scan_Code_Dlg : public QDialog
{
    Q_OBJECT
    
public:



    explicit Scan_Code_Dlg(  QWidget *parent = 0);
    ~Scan_Code_Dlg();


    
    enum SCAN_RESULT
    {
        CANCEL=0,
        ACCEPTED
    };


    void accept();
    void reject();

    QByteArray getScannedCode();

    void setGS_isPresent( bool isPresent);

    QValidator * Validator;
    void update();

signals:

    void sig_scannedCode(const MarkingCode&);

public slots:

    void slot_enter_finished( );
    void slot_symbol_readden(const uchar );
    void slot_ledt_redefineGS();
    void slot_auto_detect_replacement(const QList<quint32> &lst);
    void slot_some_errors(const QString&);


private slots:


    void on_btn_cancel_clicked();

    void on_btn_clear_clicked();

    void on_btn_accept_clicked();

    //void on_chk_GS_isAllow_toggled(bool checked);

    void slot_focusOnIn();

    void slot_focusOnRedefineLedt();

    void on_btn_show_log_clicked();


    void on_btn_save_redifinedGS_clicked();

    void on_chk_closeWin_afterEnter_toggled(bool checked);

    void on_chk_showBase64_clicked(bool checked);

    void on_chk_clearAfterScanned_clicked(bool checked);

    void on_btn_show_app_log_clicked();

    void on_ledt_redefineGS_returnPressed();


    void on_chk_auto_detection_clicked(bool checked);

    void on_chk_enable_log_clicked(bool checked);


signals:

    void sig_focusOnIn();
    void sig_focusOnRedefineLedt();

private:
    Ui::Scan_Code_Dlg *ui;

    QByteArray markingCode;

    bool GS_isPresent;
    void setCodecForScanner();
    void restoreCodec();
    void saveCodec();
    QTextCodec * savedCodecForLocale;
    QTextCodec * savedCodecForTr;
    QTextCodec * savedCodecForCStrings;

    bool GS_isAllow;
    bool clearAfterScanned;
    bool hasError;

    QSettings sett;

    bool closeWinAfterEnter;
    QString format( const QList<quint32> &lst );

    bool new_GS_replacement;

};


#endif // MARKIRIVKA_DLG_H
