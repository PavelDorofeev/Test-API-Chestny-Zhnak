#include "nk_product.h"

Nk_Product::Nk_Product(): ADbg()
  ,good_id(-1)
  ,brand_id(-1)
  ,brand_name(QString())
  ,good_status(QString())
  ,good_name(QString())

{
}


bool Nk_Product::fillFromJson( const QVariant &var )
{
    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    bool ok;

    QVariantMap mm = var.toMap();

    if( mm.contains("brand_name") && mm.value("brand_name").canConvert(QVariant::String))
        brand_name = mm.value("brand_name").toString();

    if( mm.contains("good_name") && mm.value("good_name").canConvert(QVariant::String))
        good_name = mm.value("good_name").toString();

    if( mm.contains("good_status") && mm.value("good_status").canConvert(QVariant::String))
        good_status = mm.value("good_status").toString();


//    if( mm.contains("partialSaleInfo") && mm.value("partialSaleInfo").canConvert(QVariant::Map))
//    {

//        if( mm.contains("correctRest") && mm.value("correctRest").canConvert(QVariant::Int))
//            partialSaleInfo.correctRest = mm.value("producerInn").toInt();

//        if( mm.contains("innerUnitCount") && mm.value("innerUnitCount").canConvert(QVariant::Int))
//            partialSaleInfo.innerUnitCount = mm.value("innerUnitCount").toInt();

//        if( mm.contains("rest") && mm.value("rest").canConvert(QVariant::Int))
//            partialSaleInfo.rest = mm.value("rest").toInt();

//        if( mm.contains("soldUnitCount") && mm.value("soldUnitCount").canConvert(QVariant::Int))
//            partialSaleInfo.soldUnitCount = mm.value("soldUnitCount").toInt();


//    }


//    if( mm.contains("producedDate") && mm.value("producedDate").canConvert(QVariant::String))
//        producedDate = mm.value("producedDate").toString();

//    if( mm.contains("producerInn") && mm.value("producerInn").canConvert(QVariant::String))
//        producerInn = mm.value("producerInn").toString();

//    if( mm.contains("producerName") && mm.value("producerName").canConvert(QVariant::String))
//        producerName = mm.value("producerName").toString();

//    if( mm.contains("introducedDate") && mm.value("introducedDate").canConvert(QVariant::String))
//        packageType = mm.value("introducedDate").toString();

//    if( mm.contains("productGroup") && mm.value("productGroup").canConvert(QVariant::String))
//        productGroup = mm.value("productGroup").toString();



//    if( mm.contains("productName") && mm.value("productName").canConvert(QVariant::String))
//        productName = mm.value("productName").toString();

//    if( mm.contains("requestedCis") && mm.value("requestedCis").canConvert(QVariant::String))
//        requestedCis = mm.value("requestedCis").toString();


//    if( mm.contains("status") && mm.value("status").canConvert(QVariant::String))
//        status = mm.value("status").toString();


//    if( mm.contains("statusEx") && mm.value("statusEx").canConvert(QVariant::String))
//        statusEx = mm.value("statusEx").toString();


//    if( mm.contains("tnVedEaes") && mm.value("tnVedEaes").canConvert(QVariant::String))
//        tnVedEaes = mm.value("tnVedEaes").toString();


//    if( mm.contains("tnVedEaesGroup") && mm.value("tnVedEaesGroup").canConvert(QVariant::String))
//        tnVedEaesGroup = mm.value("tnVedEaesGroup").toString();



//        // ---------------------------------------------------

//    if( mm.contains("productGroupId") && mm.value("productGroupId").canConvert(QVariant::Int))
//        productGroupId = mm.value("productGroupId").toInt();

//    if( mm.contains("isMultipleSales") && mm.value("isMultipleSales").canConvert(QVariant::Int))
//        isMultipleSales = mm.value("isMultipleSales").toInt();

    if( mm.contains("good_id") && mm.value("good_id").canConvert(QVariant::Int))
        good_id = mm.value("good_id").toInt();

    if( mm.contains("brand_id") && mm.value("brand_id").canConvert(QVariant::Int))
        brand_id = mm.value("brand_id").toInt();




    return true;
}

Nk_Product Nk_Product::from_Variant( const QVariant &var )
{
    Nk_Product resp;

    if( ! var.isValid())
    {
        qDebug() << "5675906809747856";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<Nk_Product>( var );
}



bool Nk_Product::isValid() const
{
    if( good_id == -1 )
        return false;
    else if( brand_id == -1 )
        return false;
    else if( brand_name.isNull() )
        return false;
    else if( good_name.isNull())
        return false;

    return true;
}

QString Nk_Product::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n ----- информация от товаре -----"));

    str.append( QString("\n\t brand_name         : %1").arg( brand_name ));
    str.append( QString("\n\t good_name          : %1").arg( good_name ));
    str.append( QString("\n\t good_status        : %1").arg( good_status ));
    str.append( QString("\n\t good_id      : %1").arg( good_id ));
    str.append( QString("\n\t brand_id      : %1").arg( brand_id ));
//    str.append( QString("\n\t brand            : %1").arg( brand ));
//    str.append( QString("\n\t cis              : %1").arg( cis ));
//    str.append( QString("\n\t cisWithoutBrackets : %1").arg( cisWithoutBrackets ));
//    str.append( QString("\n\t emissionDate     : %1").arg( emissionDate ));
//    str.append( QString("\n\t emissionType     : %1").arg( emissionType ));
//    str.append( QString("\n\t expirationDate   : %1").arg( expirationDate ));
//    str.append( QString("\n\t generalPackageType : %1").arg( generalPackageType ));
//    str.append( QString("\n\t gtin             : %1").arg( gtin ));
//    str.append( QString("\n\t introducedDate   : %1").arg( introducedDate ));
//    str.append( QString("\n\t ownerInn         : %1").arg( ownerInn ));
//    str.append( QString("\n\t ownerName        : %1").arg( ownerName ));
//    str.append( QString("\n\t packageType      : %1").arg( packageType ));
//    str.append( QString("\n\t correctRest       : %1").arg( partialSaleInfo.correctRest ));
//    str.append( QString("\n\t innerUnitCount    : %1").arg( partialSaleInfo.innerUnitCount ));
//    str.append( QString("\n\t rest              : %1").arg( partialSaleInfo.rest ));
//    str.append( QString("\n\t soldUnitCount     : %1").arg( partialSaleInfo.soldUnitCount ));
//    str.append( QString("\n\t producedDate      : %1").arg( producedDate ));
//    str.append( QString("\n\t producerInn       : %1").arg( producerInn ));
//    str.append( QString("\n\t producerName         : %1").arg( producerName ));
//    str.append( QString("\n\t productGroup        : %1").arg( productGroup ));
//    str.append( QString("\n\t productGroupId          : %1").arg( productGroupId ));
//    str.append( QString("\n\t productName          : %1").arg( productName ));
//    str.append( QString("\n\t requestedCis       : %1").arg( requestedCis ));
//    str.append( QString("\n\t status             : %1").arg( status ));
//    str.append( QString("\n\t statusEx         : %1").arg( statusEx ));
//    str.append( QString("\n\t tnVedEaes        : %1").arg( tnVedEaes ));
//    str.append( QString("\n\t tnVedEaesGroup       : %1").arg( tnVedEaesGroup ));
//    str.append( QString("\n\t isMultipleSales   : %1").arg( isMultipleSales ));
//    str.append( QString("\n\t markWithdraw   : %1").arg( markWithdraw ));

    return str;
}
