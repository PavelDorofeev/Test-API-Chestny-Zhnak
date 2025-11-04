#ifndef CHZN_TEST_DLG_H
#define CHZN_TEST_DLG_H

#include <QFrame>
#include <QSettings>
#include <QProcess>
#include <QAxWidget>
#include <QMessageBox>
#include "chzn_response.h"
#include "lm_response_lst.h"
#include "chzn_goods_info.h"
#include "chzn_goodsinfo_lst.h"
#include "nk_product_lst.h"

namespace Ui {
class Chzn_Test_Dlg;
}

class ChZnGoodsInfo;

#include "../dll_chzn_global.h"

class LIB_PREFIX_CHZN Chzn_Test_Dlg : public QFrame
{
    Q_OBJECT
    
public:
    explicit Chzn_Test_Dlg(QWidget *parent = 0);
    ~Chzn_Test_Dlg();

    static QString tempDir;
    static const QString signed_file_name;

    QSettings sett;
    
    QString scan_bar_code_with_scanner();

    QVariant get_codes_check();
    ChZnGoodsInfoLst get_cises_info( bool closeWinOnSuccessful = false);

    bool setBarCode( const QString &barCode );

    void parseNewBarCode( const QString & barCode);

    ChZnResponseLst cdn_codes_check( const QByteArray &barCd , bool closeWinUfSuccessful=false);
    LmResponseLst lm_cis_check(  const QString &ki , bool closeWinIfSuccessful = false);
    Nk_Product get_nk_product( const QString &gtin , bool closeWinIfSuccessful = false);


    bool get_api_key();
    bool get_auth_simpleSignIn();

    const QString getkktToken( ) const;
    const int getCurrentCdnHost( ) const;
    bool is_api_key_used() const ;

public slots:
    void on_btn_scan_bar_code_clicked();

    void slot_exception(int p , const QString &str1, const QString &str2, const QString &str3);

    QVariant slot_cdn_codes_check( const QByteArray &barCd );


private slots:
    void on_btn_getCdnHosts_clicked();

    void on_btn_chzn_validate_clicked();

    void on_btn_chzn_cdn_host_check_clicked();

    void on_btn_get_product_info_clicked();

    void on_btn_get_api_key_clicked();

    void on_btn_get_auth_simpleSignIn_clicked();

    void on_btn_get_auth_permissive_access_clicked();

    //void on_btn_test_clicked();

    void slot_process_started();
    void slot_process_finished(int result , QProcess::ExitStatus status);
    void slot_readyReadStandardError();



    void on_btn_startProcess_sign_clicked();

    void on_btn_get_nk_product_clicked();

    void on_ledt_gtin_returnPressed();

    void on_cmb_konturType_activated(int index);

    void on_gr_lk_api_key_clicked(bool checked);

    void on_cmb_api_version_activated(int index);

    void on_btn_get_cises_info_clicked();

    void on_btn_get_codes_check_clicked();

    void on_ledt_inn_uot_returnPressed();

    void on_ledt_thumbprint_returnPressed();

    void on_btn_get_cises_ease_info_clicked();

    void on_btn_get_cises_check_clicked();

    void on_ledt_lk_kkt_token_returnPressed();

    void on_btn_get_cises_check_history_create_clicked();

    void on_btn_get_cises_check_history_receive_clicked();

    void on_btn_log_clicked();

    void on_btn_lm_init_clicked();

    void on_ledt_fn_num_returnPressed();

    void on_btn_lm_status_clicked();

    void on_btn_lm_cis_check_clicked();

    void on_btn_lm_cis_check_old_clicked();

    void on_btn_lm_cis_outCheck_clicked();

    void on_btn_lm_cis_outCheck_post_clicked();

    void on_ledt_lm_login_returnPressed();

    void on_ledt_lm_pw_returnPressed();

    void on_btn_get_nk_short_product_clicked();

    void on_btn_get_nk_feed_product_clicked();

    void on_gr_lk_api_key_toggled(bool arg1);


    void on_ledt_lk_api_key_editingFinished();

private:
    Ui::Chzn_Test_Dlg *ui;

    void getCertificateByThumbprint(const QString &Thumbprint);
    bool startProcess_sign();
    QVariantMap common_settings ( const QString &cmdName);
    QVariant common_cmd( const QVariantMap &params,
                     const QVariant &body,
                     const QString &slotName ,
                     const QString &title,
                     bool closeWinUfSuccessful = false);

    QVariantMap prepareGtinObj();
    QVariantMap prepareFullCodeObj();
    QVariant prepareKiList();
    QVariantMap prepareCis() const;
    QString getDomain(const QString & url )const;
    QString getKI(const QString & url )const;
    bool testLmLoginPw() const ;
};

#endif // DIALOG_H
