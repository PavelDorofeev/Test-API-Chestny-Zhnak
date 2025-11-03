#ifndef CHZN_VALIDATE_H
#define CHZN_VALIDATE_H

#include <QMetaType>
#include "scanner/kb_wgt/scan_code_dlg.h"
#include "qp/core/dbg/abstract_dbg.h"
#include "qp/gui/qp_gui.h"
#include "abstract_kkt/marking/chzn_goods.h"

class aKKT;
class ChZnResponse;
class ChZn_Goods;
class QNetworkRequest;

#include "../dll_akkt_global.h"
class LIB_PREFIX_AKKT ChZn_Validate : public QObject, public ADbg
{
    Q_OBJECT
public:

    enum HTTP_TYPE{
        GET,
        POST
    };

    ChZn_Validate( QObject *parent );

    ChZnResponse validate( aKKT *kkt, const QString &cdn, const QByteArray &barCd);


    bool vrt_get_codes_check_v4( const QVariantMap &params, const QVariant &bodyObj, ChZnResponse &resp);
    bool vrt_get_codes_check_v4_cdn( const QVariantMap &params, const QVariant &bodyObj, ChZnResponse &resp);


    QString fullInfo( int level = 0 ) const;

    QString  get_auth_key( const QVariantMap &params , const QVariantMap &bodyObj );
    QString get_auth_simpleSignIn( const QVariantMap &params  , const QVariantMap &bodyObj );
    QVariantMap get_auth_permissive_access( const QVariantMap &params , const QVariantMap &bodyObj );
    QVariantMap get_product_info( const QVariantMap &params , const QVariantMap &body);
    QVariantList get_cises_info( const QVariantMap &params , const  QVariantList &bodyObj );
    QVariantMap get_cises_ease_info( const QVariantMap &params , const  QVariantMap &bodyObj );
    QVariantMap get_cises_check( const QVariantMap &params , const  QVariantMap &bodyObj );
    QString get_nk_product( const QVariantMap &params , const QVariantMap &body);

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
    QVariant slot_get_cises_info( const QVariantMap &params , const  QVariantList &bodyObj) ;
    QVariant slot_get_cises_ease_info( const QVariantMap &params , const  QVariantMap &bodyObj) ;
    QVariant slot_get_cises_check( const QVariantMap &params , const  QVariantMap &bodyObj) ;
    QVariant slot_get_nk_product( const QVariantMap &params , const QVariantMap &bodyObj);
    void common_prepare_url_and_request( const  QVariantMap &params, const QVariant & bodyObj, QNetworkRequest& request, QUrl & urlLk ,HTTP_TYPE &http_type );



private:
    QString ntwQuery( HTTP_TYPE tt, QNetworkRequest &request, bool *ok=0, const QByteArray &body=QByteArray());
};

#endif // CHZN_VALIDATE_H
