#include "lm_response_lst.h"


// ---------------------------------------------------------
LmResponseLst::LmResponseLst()
    :ADbg(),
      code(-1),
      description(QString()),
      reqTimestamp(0),
      reqId(QString())
{

}

bool LmResponseLst::fillFromJson( const QVariant &var )
{
    LmResponseLst resp;
    codeLst.clear();

    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    bool ok;

    QVariantMap mm = var.toMap();

    if( mm.contains("code") && mm.value("code").canConvert(QVariant::Int))
        code = mm.value("code").toInt( &ok);

    if( mm.contains("description") && mm.value("description").canConvert(QVariant::String))
        description = mm.value("description").toString();


    if( mm.contains("reqTimestamp") && mm.value("reqTimestamp").canConvert(QVariant::Int))
        reqTimestamp = mm.value("reqTimestamp").toInt( &ok);

    if( mm.contains("reqId") && mm.value("reqId").canConvert(QVariant::String))
        reqId = mm.value("reqId").toString();

    if( mm.contains("codes") && mm.value("codes").canConvert(QVariant::List))
    {
        QVariantList lst = mm.value("codes").toList();

        foreach( QVariant var , lst)
        {
            LmResponseCode item;

            if ( ! item.fillFromJson(var) )
                ;

            codeLst.append( item );

        }
    }


    return true;
}

QString LmResponseLst::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n --------- ChZnResponse ---------"));
    str.append( QString("\n code              : %1").arg( code ));
    str.append( QString("\n description       : %1").arg( description ));
    str.append( QString("\n reqTimestamp      : %1").arg( reqTimestamp ));
    str.append( QString("\n reqId             : %1").arg( reqId ));

    int cnt = 1;
    foreach(LmResponseCode code, codeLst)
    {
        str.append(QString("\n ---------- %1 ----------").arg(cnt++));
        str.append( code.fullInfo());
    }

    return str;
}

LmResponseLst LmResponseLst::from_Variant( const QVariant &var )
{
    LmResponseLst resp;

    if( ! var.isValid())
    {
        qDebug() << "45645635465464";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<LmResponseLst>( var );
}

