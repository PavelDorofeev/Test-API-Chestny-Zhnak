#include "markingcode.h"

MarkingCode::MarkingCode(  ):
    ADbg(),
    fullCode(QString()),
    gtin(QString()),
    cis(QString())

{
//    MarkingCode::parseFullCode( FullCode , this );
}


QString MarkingCode::fullInfo( int level ) const
{
    QString str;
    str.reserve( 1000 );

    str.append("\n\n----- MarkingCode ------");
    str.append( QString("\n\t full : %1").arg( fullCode));
    str.append( QString("\n\t gtin : %1").arg( gtin));
    str.append( QString("\n\t cis  : %1").arg( cis));

    return str;

}


bool MarkingCode::fillFormFullCode( const QString & fullCd , MarkingCode &mrk)
{
    //-------------------------------------------------------------------

    mrk.fullCode = fullCd;

    int pos91 = fullCd.indexOf( QLatin1Char(0x1d) );

    if( pos91 < 0)
    {
        qWarning() << "полный код маркировки на содержит ни одного символа 0x1d" << fullCd;
        return false;
    }


    mrk.cis = fullCd.mid(0 , pos91 );

    if( pos91 < 16 )
    {
        qWarning() << "не удается выделить gtin из кода маркировки" << fullCd;
        return false;
    }

    mrk.gtin = mrk.cis.mid( 2 , 14 );

    return true;

}
