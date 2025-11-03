#include "ntwqueryansw.h"
#include "qp/ntw/ntw.h"
#include <QDebug>

NtwQueryAnsw::NtwQueryAnsw()
    : ADbg(),
    response(QString()),
    ntwErrCode(-1)
{
//    qDebug() << "adsasdsad";

}

NtwQueryAnsw::NtwQueryAnsw( const QString& Response, int NtwErrCode)
    : ADbg(),
    response(Response),
    ntwErrCode(NtwErrCode)
{
//    qDebug() << "adsasdsad";
}

QString NtwQueryAnsw::fullInfo( int level ) const
{
    QString str;
    str.reserve( response.size() +200);

    str.append( QString("\n -------- ответ --------- "));

    str.append( QString("%1\n").arg( qp::dbg_ntw::toStr_NetworkError( ntwErrCode ) ));
    str.append( qp::dbg_ntw::toStr_NetworkError( ntwErrCode ));


    return str;
}
