#include "chzn_goodsinfo_lst.h"


ChZnGoodsInfoLst::ChZnGoodsInfoLst():
    ADbg(),
    networkError(-1)
{

}

ChZnGoodsInfoLst ChZnGoodsInfoLst::from_Variant( const QVariant &var )
{
    ChZnGoodsInfoLst resp;

    if( ! var.isValid())
    {
        qDebug() << "6454354654";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<ChZnGoodsInfoLst>( var );
}

bool ChZnGoodsInfoLst::fillFromJson( const QVariant &var )
{
    if ( ! var.canConvert( QVariant::List ) )
        return false;

    QVariantList varLst = var.toList();

    for( int ii=0; ii < varLst.count(); ii++)
    {
        if ( ! varLst.value( ii ).canConvert( QVariant::Map) )
            return false;

        QVariantMap mm = varLst.value( ii ).toMap();

        if( ! mm.contains("cisInfo") || ! mm.value("cisInfo").canConvert( QVariant::Map))
            return false;

        ChZnGoodsInfo goodsInf;

        goodsInf.fillFromJson( mm.value("cisInfo").toMap() );

        goodsLst.append( goodsInf);
    }

    return true;


}
QString ChZnGoodsInfoLst::fullInfo( int level ) const
{
    QString str;
    str.reserve(700 * goodsLst.count());

    str.append( QString("\n ----- информация от товарах -----"));

    for( int ii=0; ii < goodsLst.count(); ii++)
    {
        str.append( goodsLst.at(ii).fullInfo());
    }


    return str;
}

