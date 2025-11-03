#ifndef CHZN_VALIDATE_123_H
#define CHZN_VALIDATE_123_H

#include <QMetaType>
#include "kb_scanner/kb_wgt/scan_code_dlg.h"
#include "qp/core/dbg/abstract_dbg.h"
#include "lm_response_lst.h"
#include "ntwqueryansw.h"
#include "qp/gui/qp_gui.h"
#include "nk_product_lst.h"

class ChZnResponseLst;
class ChZnGoodsInfo;
class QNetworkRequest;
class ChZnGoodsInfoLst;


#include "../dll_chzn_global.h"
class LIB_PREFIX_CHZN ChZn_Validate : public QObject, public ADbg
{
    Q_OBJECT

public:

    enum HTTP_TYPE{
        GET,
        POST
    };

    explicit ChZn_Validate(QObject *parent = 0);

    ChZnResponseLst validate( const QString &marking_token, const QString &cdn, const QByteArray &barCd);


    ChZnResponseLst vrt_get_codes_check_v4( const QVariantMap &params, const QVariant &bodyObj);
    ChZnResponseLst vrt_get_codes_check_v4_cdn( const QVariantMap &params, const QVariant &bodyObj);


    QString fullInfo( int level =0 ) const;

    QString  get_auth_key( const QVariantMap &params , const QVariantMap &bodyObj );
    QString get_auth_simpleSignIn( const QVariantMap &params  , const QVariantMap &bodyObj );
    QVariantMap get_auth_permissive_access( const QVariantMap &params , const QVariantMap &bodyObj );
    QVariantMap get_product_info( const QVariantMap &params , const QVariantMap &body);
    QVariantMap get_short_product_info( const QVariantMap &params , const QVariantMap &body);
    ChZnGoodsInfoLst get_cises_info( const QVariantMap &params , const  QVariantList &bodyObj );
    QVariantMap get_cises_ease_info( const QVariantMap &params , const  QVariantMap &bodyObj );
    QVariantMap get_cises_check( const QVariantMap &params , const  QVariantMap &bodyObj );
    QVariantMap get_cises_check_history_create( const QVariantMap &params , const  QVariantMap &bodyObj );
    QVariantMap get_cises_check_history_receive( const QVariantMap &params , const  QVariantMap &bodyObj );
    Nk_Product_Lst get_nk_product( const QVariantMap &params , const QVariantMap &body);
    QString get_nk_short_product( const QVariantMap &params , const QVariantMap &body);
    QString get_nk_feed_product( const QVariantMap &params , const QVariantMap &body);
    bool get_lm_init( const QVariantMap &params , const QVariantMap &body);
    bool get_lm_status( const QVariantMap &params , const QVariantMap &body);
    LmResponseLst get_lm_cis_check( const QVariantMap &params , const QVariantMap &body);
    bool get_lm_cis_outCheck( const QVariantMap &params , const QVariantMap &body);

    QVariant common_cmd_with_log_Dlg( QWidget *wgt,
                                      const QVariantMap &params ,
                                      const QVariant &bodyObj,
                                      const QString &slotName ,
                                      const QString &title )  ;

signals:
    void sig_log(const QString &, qp::gui::LOG_STYLE);
    void sig_finished( const QString &str, bool error = true, bool closeWin = false) const; // этот сигнал нужен чтобы общаться с Msg2 диалогом


public slots:
    QVariant slot_getCdnHosts( const QString &marking_token , int kontur = 0) ;
    QVariant slot_getCdnHostValidation( const QVariantMap &params) ;
    QVariant slot_get_codes_check( const QVariantMap &params ,  const QVariantMap &bodyObj) ;
    QVariant slot_get_auth_key( const QVariantMap &params , const QVariantMap &bodyObj) ;
    QVariant slot_get_auth_simpleSignIn( const QVariantMap &params , const QVariantMap &bodyObj );
    QVariant slot_get_auth_permissive_access( const QVariantMap &params , const QVariantMap &bodyObj) ;
    QVariant slot_get_product_info( const QVariantMap &params , const QVariantMap &bodyObj) ;
    QVariant slot_get_short_product_info( const QVariantMap &params , const QVariantMap &bodyObj) ;
    QVariant slot_get_cises_info( const QVariantMap &params , const  QVariantList &bodyObj) ;
    QVariant slot_get_cises_ease_info( const QVariantMap &params , const  QVariantMap &bodyObj) ;
    QVariant slot_get_cises_check( const QVariantMap &params , const  QVariantMap &bodyObj) ;
    QVariant slot_get_cises_check_history_create( const QVariantMap &params , const  QVariantMap &bodyObj) ;
    QVariant slot_get_cises_check_history_receive( const QVariantMap &params , const  QVariantMap &bodyObj) ;
    QVariant slot_get_nk_product( const QVariantMap &params , const QVariantMap &bodyObj);
    QVariant slot_get_nk_short_product( const QVariantMap &params , const QVariantMap &bodyObj);
    QVariant slot_get_nk_feed_product( const QVariantMap &params , const QVariantMap &bodyObj);
    QVariant slot_get_lm_init( const QVariantMap &params , const QVariantMap &bodyObj);
    QVariant slot_get_lm_status( const QVariantMap &params , const QVariantMap &bodyObj);
    QVariant slot_get_lm_cis_check( const QVariantMap &params , const QVariantMap &bodyObj);
    QVariant slot_get_lm_cis_outCheck( const QVariantMap &params , const QVariantMap &bodyObj);



private:
    NtwQueryAnsw ntwQuery( HTTP_TYPE tt, QNetworkRequest &request, bool *ok=0, const QByteArray &body=QByteArray(), bool log_answ = true);
    bool common_prepare_url_and_request( const  QVariantMap &params, const QVariant & bodyObj, QNetworkRequest& request, QUrl & urlLk ,HTTP_TYPE &http_type );
    bool common_prepare_lm_url_and_request( const  QVariantMap &params, const QVariant & bodyObj, QNetworkRequest& request, QUrl & urlLk ,HTTP_TYPE &http_type);
    QString prettyJson( const QString & in ) const ;
    QString ret_err( const NtwQueryAnsw &) const;
};

#endif // CHZN_VALIDATE_123_H
