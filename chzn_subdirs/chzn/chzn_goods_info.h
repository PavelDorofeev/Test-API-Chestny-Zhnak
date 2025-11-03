#ifndef CHZN_GOODS_INFO_H
#define CHZN_GOODS_INFO_H

#include <QMetaType>
#include <QList>

#include "qp/core/dbg/abstract_dbg.h"

#include "../dll_chzn_global.h"

typedef struct GoodsPartialSaleInfo{

    int correctRest;
    int innerUnitCount;
    int rest;
    int soldUnitCount;

    GoodsPartialSaleInfo():
        correctRest(-1),
        innerUnitCount(-1),
        rest(-1),
        soldUnitCount(-1)
    {

    }
}GoodsPartialSaleInfo;


class LIB_PREFIX_CHZN ChZnGoodsInfo : public ADbg
{
public:
    ChZnGoodsInfo();
    /*
    [
        {
            "cisInfo":{
                "applicationDate":"2025-01-16T13:46:18.780Z",
                "batchNumber":"010125",
                "brand":"OkVet®",
                "child":[],
                "cis":"0104603586014674215012516137746",
                "cisWithoutBrackets":"0104603586014674215012516137746",
                "emissionDate":"2024-12-28T07:23:13.880Z",
                "emissionType":"LOCAL",
                "expirationDate":"2027-12-28T00:00:00.000Z",
                "generalPackageType":"UNIT",
                "gtin":"04603586014674",
                "introducedDate":"2025-01-17T07:21:06.755Z",
                "isMultipleSales":false,
                "markWithdraw":false,
                "ownerInn":"7804437548",
                "ownerName":"ООО \"МКТ\"",
                "packageType":"UNIT",
                "partialSaleInfo":{
                    "correctRest":true,
                    "innerUnitCount":12,
                    "rest":12,
                    "soldUnitCount":0
                },
                "producedDate":"2025-01-01T00:00:00.000Z",
                "producerInn":"5042113943",
                "producerName":"ООО \"АВЗ С-П\"",
                "productGroup":"vetpharma",
                "productGroupId":26,
                "productName":"Докситрон жевательные таблетки, 100 мг",
                "requestedCis":"0104603586014674215012516137746",
                "status":"INTRODUCED",
                "statusEx":"EMPTY",
                "tnVedEaes":"3004200001",
                "tnVedEaesGroup":"3004"
            }
        }

*/
    QString applicationDate;
    QString batchNumber;
    QString brand;
    QString cis;                // КИ / КиЗ из запроса
    QString cisWithoutBrackets;                // КИ / КиЗ из запроса
    QString emissionDate;
    QString emissionType;
    QString expirationDate;
    QString generalPackageType;
    QString gtin;               // Код товара
    QString introducedDate;
    QString ownerInn;
    QString ownerName;
    QString packageType;

    GoodsPartialSaleInfo partialSaleInfo;

    QString producedDate;
    QString producerInn;
    QString producerName;
    QString productGroup;

    int productGroupId;

    QString productName;
    QString requestedCis;
    QString status;
    QString statusEx;
    QString tnVedEaes;
    QString tnVedEaesGroup;

    int isMultipleSales;
    int markWithdraw;

    static ChZnGoodsInfo from_Variant( const QVariant &var );

    //static QString canToSell( const ChZnGoodsInfo& rc );

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;
};

Q_DECLARE_METATYPE(ChZnGoodsInfo);

#endif // CHZN_GOODS_INFO_H
