#include "lm_responsecode.h"

LmResponseCode::LmResponseCode(): ADbg(),

    cis(QString()),
    gtin(QString()),
    printView(QString()),
    isBlocked(-1),
    isGreyGtin(-1)
{

}


bool LmResponseCode::fillFromJson( const QVariant &var )
{
    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    QVariantMap mm = var.toMap();

    if( mm.contains("cis") && mm.value("cis").canConvert(QVariant::String))
        cis = mm.value("cis").toString();

    if( mm.contains("printView") && mm.value("printView").canConvert(QVariant::String))
        printView = mm.value("printView").toString();

    if( mm.contains("gtin") && mm.value("gtin").canConvert(QVariant::String))
        gtin = mm.value("gtin").toString();


    if( mm.contains("isBlocked") && mm.value("isBlocked").canConvert(QVariant::Bool))
        isBlocked = mm.value("isBlocked").toBool();


    if( mm.contains("isGreyGtin") && mm.value("isGreyGtin").canConvert(QVariant::Bool))
        isGreyGtin = mm.value("isGreyGtin").toBool();




    return true;
}

QString LmResponseCode::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n\t cis              : %1").arg( cis ));
    str.append( QString("\n\t printView        : %1").arg( printView ));
    str.append( QString("\n\t gtin             : %1").arg( gtin ));
    str.append( QString("\n\t isBlocked        : %1").arg( isBlocked ));
    str.append( QString("\n\t isGreyGtin       : %1").arg( isGreyGtin ));

    return str;
}


QString LmResponseCode::canToSell( const LmResponseCode& rc )
{
    if( rc.isBlocked == 1 )
       return rc.gtin +"\n\nпродукции заблокирована по решению ОГВ";

    if( rc.isGreyGtin == 1)
        return rc.gtin +"\n\nтовар в серой зоне";

    return "ok";

}
