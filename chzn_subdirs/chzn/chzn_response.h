#ifndef CHZN_RESPONSE_H
#define CHZN_RESPONSE_H

#include "chzn_responsecode.h"


#include "../dll_chzn_global.h"
class LIB_PREFIX_CHZN ChZnResponseLst : public ADbg
{
public:
    ChZnResponseLst();

    int code;
    QString description;
    int reqTimestamp;       // Дата и время формирования запроса
    QString reqId;          // Уникальный идентификатор запроса

    QString response;       // ответ сервера ЧЗ

    QList<ChZnResponseCode> codeLst;

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;

    static ChZnResponseLst from_Variant( const QVariant &var );
};

Q_DECLARE_METATYPE(ChZnResponseLst);

#endif // CHZN_RESPONSE_H
