#include "chzn_goods_info.h"


ChZnGoodsInfo::ChZnGoodsInfo()
    :ADbg(),
      applicationDate(QString()),
      batchNumber(QString()),
      brand(QString()),
      cis(QString()),
      cisWithoutBrackets(QString()),
      productGroupId(-1),
      isMultipleSales(-1),
      markWithdraw(-1)
{

}


bool ChZnGoodsInfo::fillFromJson( const QVariant &var )
{
    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    bool ok;

    QVariantMap mm = var.toMap();

    if( mm.contains("applicationDate") && mm.value("applicationDate").canConvert(QVariant::String))
        applicationDate = mm.value("applicationDate").toString();

    if( mm.contains("batchNumber") && mm.value("batchNumber").canConvert(QVariant::String))
        batchNumber = mm.value("batchNumber").toString();

    if( mm.contains("brand") && mm.value("brand").canConvert(QVariant::String))
        brand = mm.value("brand").toString();

    if( mm.contains("cis") && mm.value("cis").canConvert(QVariant::String))
        cis = mm.value("cis").toString();

    if( mm.contains("cisWithoutBrackets") && mm.value("cisWithoutBrackets").canConvert(QVariant::String))
        cisWithoutBrackets = mm.value("cisWithoutBrackets").toString();


    if( mm.contains("emissionDate") && mm.value("emissionDate").canConvert(QVariant::String))
        emissionDate = mm.value("emissionDate").toString();


    if( mm.contains("emissionType") && mm.value("emissionType").canConvert(QVariant::String))
        emissionType = mm.value("emissionType").toString();


    if( mm.contains("generalPackageType") && mm.value("generalPackageType").canConvert(QVariant::String))
        generalPackageType = mm.value("generalPackageType").toString();


    if( mm.contains("gtin") && mm.value("gtin").canConvert(QVariant::String))
        gtin = mm.value("gtin").toString();


    if( mm.contains("introducedDate") && mm.value("introducedDate").canConvert(QVariant::String))
        introducedDate = mm.value("introducedDate").toString();

    if( mm.contains("ownerInn") && mm.value("ownerInn").canConvert(QVariant::String))
        ownerInn = mm.value("ownerInn").toString();

    if( mm.contains("ownerName") && mm.value("ownerName").canConvert(QVariant::String))
        ownerName = mm.value("ownerName").toString();

    if( mm.contains("packageType") && mm.value("packageType").canConvert(QVariant::String))
        packageType = mm.value("packageType").toString();


    if( mm.contains("partialSaleInfo") && mm.value("partialSaleInfo").canConvert(QVariant::Map))
    {

        if( mm.contains("correctRest") && mm.value("correctRest").canConvert(QVariant::Int))
            partialSaleInfo.correctRest = mm.value("producerInn").toInt();

        if( mm.contains("innerUnitCount") && mm.value("innerUnitCount").canConvert(QVariant::Int))
            partialSaleInfo.innerUnitCount = mm.value("innerUnitCount").toInt();

        if( mm.contains("rest") && mm.value("rest").canConvert(QVariant::Int))
            partialSaleInfo.rest = mm.value("rest").toInt();

        if( mm.contains("soldUnitCount") && mm.value("soldUnitCount").canConvert(QVariant::Int))
            partialSaleInfo.soldUnitCount = mm.value("soldUnitCount").toInt();


    }


    if( mm.contains("producedDate") && mm.value("producedDate").canConvert(QVariant::String))
        producedDate = mm.value("producedDate").toString();

    if( mm.contains("producerInn") && mm.value("producerInn").canConvert(QVariant::String))
        producerInn = mm.value("producerInn").toString();

    if( mm.contains("producerName") && mm.value("producerName").canConvert(QVariant::String))
        producerName = mm.value("producerName").toString();

    if( mm.contains("introducedDate") && mm.value("introducedDate").canConvert(QVariant::String))
        packageType = mm.value("introducedDate").toString();

    if( mm.contains("productGroup") && mm.value("productGroup").canConvert(QVariant::String))
        productGroup = mm.value("productGroup").toString();



    if( mm.contains("productName") && mm.value("productName").canConvert(QVariant::String))
        productName = mm.value("productName").toString();

    if( mm.contains("requestedCis") && mm.value("requestedCis").canConvert(QVariant::String))
        requestedCis = mm.value("requestedCis").toString();


    if( mm.contains("status") && mm.value("status").canConvert(QVariant::String))
        status = mm.value("status").toString();


    if( mm.contains("statusEx") && mm.value("statusEx").canConvert(QVariant::String))
        statusEx = mm.value("statusEx").toString();


    if( mm.contains("tnVedEaes") && mm.value("tnVedEaes").canConvert(QVariant::String))
        tnVedEaes = mm.value("tnVedEaes").toString();


    if( mm.contains("tnVedEaesGroup") && mm.value("tnVedEaesGroup").canConvert(QVariant::String))
        tnVedEaesGroup = mm.value("tnVedEaesGroup").toString();



        // ---------------------------------------------------

    if( mm.contains("productGroupId") && mm.value("productGroupId").canConvert(QVariant::Int))
        productGroupId = mm.value("productGroupId").toInt();

    if( mm.contains("isMultipleSales") && mm.value("isMultipleSales").canConvert(QVariant::Int))
        isMultipleSales = mm.value("isMultipleSales").toInt();

    if( mm.contains("markWithdraw") && mm.value("markWithdraw").canConvert(QVariant::Int))
        markWithdraw = mm.value("markWithdraw").toInt();




    return true;
}

ChZnGoodsInfo ChZnGoodsInfo::from_Variant( const QVariant &var )
{
    ChZnGoodsInfo resp;

    if( ! var.isValid())
    {
        qDebug() << "6454354654";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<ChZnGoodsInfo>( var );
}

QString ChZnGoodsInfo::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n ----- информация от товаре -----"));

    str.append( QString("\n\t applicationDate  : %1").arg( applicationDate ));
    str.append( QString("\n\t batchNumber      : %1").arg( batchNumber ));
    str.append( QString("\n\t brand            : %1").arg( brand ));
    str.append( QString("\n\t cis              : %1").arg( cis ));
    str.append( QString("\n\t cisWithoutBrackets : %1").arg( cisWithoutBrackets ));
    str.append( QString("\n\t emissionDate     : %1").arg( emissionDate ));
    str.append( QString("\n\t emissionType     : %1").arg( emissionType ));
    str.append( QString("\n\t expirationDate   : %1").arg( expirationDate ));
    str.append( QString("\n\t generalPackageType : %1").arg( generalPackageType ));
    str.append( QString("\n\t gtin             : %1").arg( gtin ));
    str.append( QString("\n\t introducedDate   : %1").arg( introducedDate ));
    str.append( QString("\n\t ownerInn         : %1").arg( ownerInn ));
    str.append( QString("\n\t ownerName        : %1").arg( ownerName ));
    str.append( QString("\n\t packageType      : %1").arg( packageType ));
    str.append( QString("\n\t correctRest       : %1").arg( partialSaleInfo.correctRest ));
    str.append( QString("\n\t innerUnitCount    : %1").arg( partialSaleInfo.innerUnitCount ));
    str.append( QString("\n\t rest              : %1").arg( partialSaleInfo.rest ));
    str.append( QString("\n\t soldUnitCount     : %1").arg( partialSaleInfo.soldUnitCount ));
    str.append( QString("\n\t producedDate      : %1").arg( producedDate ));
    str.append( QString("\n\t producerInn       : %1").arg( producerInn ));
    str.append( QString("\n\t producerName         : %1").arg( producerName ));
    str.append( QString("\n\t productGroup        : %1").arg( productGroup ));
    str.append( QString("\n\t productGroupId          : %1").arg( productGroupId ));
    str.append( QString("\n\t productName          : %1").arg( productName ));
    str.append( QString("\n\t requestedCis       : %1").arg( requestedCis ));
    str.append( QString("\n\t status             : %1").arg( status ));
    str.append( QString("\n\t statusEx         : %1").arg( statusEx ));
    str.append( QString("\n\t tnVedEaes        : %1").arg( tnVedEaes ));
    str.append( QString("\n\t tnVedEaesGroup       : %1").arg( tnVedEaesGroup ));
    str.append( QString("\n\t isMultipleSales   : %1").arg( isMultipleSales ));
    str.append( QString("\n\t markWithdraw   : %1").arg( markWithdraw ));

    return str;
}

