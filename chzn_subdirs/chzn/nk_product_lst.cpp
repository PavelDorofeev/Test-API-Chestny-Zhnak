#include "nk_product_lst.h"


Nk_Product_Lst::Nk_Product_Lst(): ADbg()
{
}

Nk_Product_Lst Nk_Product_Lst::from_Variant( const QVariant &var )
{
    Nk_Product_Lst resp;

    if( ! var.isValid())
    {
        qDebug() << "6454354654";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<Nk_Product_Lst>( var );
}

bool Nk_Product_Lst::fillFromJson( const QVariant &var )
{
    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    QVariantMap mm = var.toMap();

    if( ! mm.contains("result") || ! mm.value("result").canConvert(QVariant::List))
        return false;

    if( ! mm.contains("apiversion") || ! mm.value("apiversion").canConvert(QVariant::Int))
    {
        Q_ASSERT(1==654545654);
        return false;
    }

    QVariantList varLst = mm.value("result").toList();

    for( int ii=0; ii < varLst.count(); ii++)
    {
        if ( ! varLst.value( ii ).canConvert( QVariant::Map) )
            return false;

        QVariantMap mm = varLst.value( ii ).toMap();

        if( ! mm.contains("good_name") || ! mm.value("good_name").canConvert( QVariant::String))
            return false;

        Nk_Product productInf;

        if ( ! productInf.fillFromJson( mm ) )
        {
            Q_ASSERT(1==464565465);
        }

        productLst.append( productInf);
    }

    return true;


}
QString Nk_Product_Lst::fullInfo( int level ) const
{
    QString str;
    str.reserve(700 * productLst.count());

    str.append( QString("\n ----- информация от товарах -----"));

    for( int ii=0; ii < productLst.count(); ii++)
    {
        str.append( productLst.at(ii).fullInfo());
    }


    return str;
}
