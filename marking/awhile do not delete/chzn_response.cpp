#include "chzn_response.h"


ChZnResponseCode::ChZnResponseCode()
    :ADbg(),
      valid(-1),
      cis(QString())
{

}


bool ChZnResponseCode::fillFromJson( const QVariant &var )
{
    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    bool ok;

    QVariantMap mm = var.toMap();

    if( mm.contains("cis") && mm.value("cis").canConvert(QVariant::String))
        cis = mm.value("cis").toString();

    if( mm.contains("printView") && mm.value("printView").canConvert(QVariant::String))
        printView = mm.value("printView").toString();

    if( mm.contains("gtin") && mm.value("gtin").canConvert(QVariant::String))
        gtin = mm.value("gtin").toString();

    if( mm.contains("message") && mm.value("message").canConvert(QVariant::String))
        message = mm.value("message").toString();

    if( mm.contains("packageType") && mm.value("packageType").canConvert(QVariant::String))
        packageType = mm.value("packageType").toString();

    if( mm.contains("producerInn") && mm.value("producerInn").canConvert(QVariant::String))
        producerInn = mm.value("producerInn").toString();

    if( mm.contains("productionSerialNumber") && mm.value("productionSerialNumber").canConvert(QVariant::String))
        productionSerialNumber = mm.value("productionSerialNumber").toString();


    if( mm.contains("groupIds") && mm.value("groupIds").canConvert(QVariant::List))
        groupIds = mm.value("groupIds").toList();



    if( mm.contains("valid") && mm.value("valid").canConvert(QVariant::Bool))
        valid = mm.value("valid").toBool();

    if( mm.contains("verified") && mm.value("verified").canConvert(QVariant::Bool))
        verified = mm.value("verified").toBool();

    if( mm.contains("realizable") && mm.value("realizable").canConvert(QVariant::Bool))
        realizable = mm.value("realizable").toBool();

    if( mm.contains("utilised") && mm.value("utilised").canConvert(QVariant::Bool))
        utilised = mm.value("utilised").toBool();

    if( mm.contains("isBlocked") && mm.value("isBlocked").canConvert(QVariant::Bool))
        isBlocked = mm.value("isBlocked").toBool();

    if( mm.contains("found") && mm.value("found").canConvert(QVariant::Bool))
        found = mm.value("found").toBool();

    if( mm.contains("isOwner") && mm.value("isOwner").canConvert(QVariant::Bool))
        isOwner = mm.value("isOwner").toBool();


    if( mm.contains("isTracking") && mm.value("isTracking").canConvert(QVariant::Bool))
        isTracking = mm.value("isTracking").toBool();

    if( mm.contains("sold") && mm.value("sold").canConvert(QVariant::Bool))
        sold = mm.value("sold").toBool();

    if( mm.contains("grayZone") && mm.value("grayZone").canConvert(QVariant::Bool))
        grayZone = mm.value("grayZone").toBool();



    if( mm.contains("expireDate") && mm.value("expireDate").canConvert(QVariant::String))
        expireDate =mm.value("expireDate").toString();

    if( mm.contains("productionDate") && mm.value("productionDate").canConvert(QVariant::String))
        productionDate = mm.value("productionDate").toString();

    if( mm.contains("errorCode") && mm.value("errorCode").canConvert(QVariant::Int))
        errorCode = mm.value("errorCode").toInt( &ok);



    return true;
}

QString ChZnResponseCode::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n\t cis              : %1").arg( cis ));
    str.append( QString("\n\t printView        : %1").arg( printView ));
    str.append( QString("\n\t gtin             : %1").arg( gtin ));
    str.append( QString("\n\t message          : %1").arg( message ));
    str.append( QString("\n\t packageType      : %1").arg( packageType ));
    str.append( QString("\n\t producerInn      : %1").arg( producerInn ));
    str.append( QString("\n\t productionSerialNumber  : %1").arg( productionSerialNumber ));
    str.append( QString("\n\t valid            : %1").arg( valid ));
    str.append( QString("\n\t verified         : %1").arg( verified ));
    str.append( QString("\n\t found            : %1").arg( found ));
    str.append( QString("\n\t realizable       : %1").arg( realizable ));
    str.append( QString("\n\t utilised         : %1").arg( utilised ));
    str.append( QString("\n\t isBlocked        : %1").arg( isBlocked ));
    str.append( QString("\n\t isOwner          : %1").arg( isOwner ));
    str.append( QString("\n\t isOwner          : %1").arg( isOwner ));
    str.append( QString("\n\t isTracking       : %1").arg( isTracking ));
    str.append( QString("\n\t sold             : %1").arg( sold ));
    str.append( QString("\n\t grayZone         : %1").arg( grayZone ));
    str.append( QString("\n\t errorCode        : %1").arg( errorCode ));
    str.append( QString("\n\t expireDate       : %1").arg( expireDate ));
    str.append( QString("\n\t productionDate   : %1").arg( productionDate ));

    return str;
}


// ---------------------------------------------------------
ChZnResponse::ChZnResponse()
    :ADbg(),
      code(-1),
      description(QString())
{

}

bool ChZnResponse::fillFromJson( const QVariant &var )
{
    ChZnResponse resp;
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
            ChZnResponseCode item;

            if ( ! item.fillFromJson(var) )
                ;

            codeLst.append( item );

        }
    }


    return true;
}

QString ChZnResponse::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n --------- ChZnResponse ---------"));
    str.append( QString("\n code              : %1").arg( code ));
    str.append( QString("\n description       : %1").arg( description ));
    str.append( QString("\n reqTimestamp      : %1").arg( reqTimestamp ));
    str.append( QString("\n reqId             : %1").arg( reqId ));

    int cnt = 1;
    foreach(ChZnResponseCode code, codeLst)
    {
        str.append(QString("\n ---------- %1 ----------").arg(cnt++));
        str.append( code.fullInfo());
    }

    return str;
}

ChZnResponse ChZnResponse::from_Variant( const QVariant &var )
{
    ChZnResponse resp;

    if( ! var.isValid())
    {
        qDebug() << "45645635465464";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<ChZnResponse>( var );
}
