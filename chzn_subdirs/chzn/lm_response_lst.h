#ifndef LM_RESPONSE_LST_H
#define LM_RESPONSE_LST_H

#include "lm_responsecode.h"


#include "../dll_chzn_global.h"
class LIB_PREFIX_CHZN LmResponseLst : public ADbg
{
public:
    LmResponseLst();

    /*
    {
        "code":0,
        "codes":    [
            {
                "cis":"0104603586014674215012516137746",
                "gtin":"04603586014674",
                "isBlocked":false,
                "isGreyGtin":false,
                "printView":"0104603586014674215012516137746"
            }
        ],
        "description":"ok",
        "inst":"84c4d96a-1c44-4660-a1a2-1b0220f72d07",
        "reqId":"36a8eed9-b8f9-899b-5cd0-b2114b102dc6",
        "reqTimestamp":1748622685213
    }
    */

    int code;
    QString description;
    int reqTimestamp;       // Дата и время формирования запроса
    QString reqId;          // Уникальный идентификатор запроса

    QString response;       // ответ сервера ЧЗ

    QList<LmResponseCode> codeLst;

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;

    static LmResponseLst from_Variant( const QVariant &var );

};

Q_DECLARE_METATYPE(LmResponseLst);

#endif // LM_RESPONSE_LST_H
