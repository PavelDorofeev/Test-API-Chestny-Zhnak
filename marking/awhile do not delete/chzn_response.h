#ifndef CHZN_RESPONSE_H
#define CHZN_RESPONSE_H

#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"

#include "../dll_akkt_global.h"
class LIB_PREFIX_AKKT ChZnResponseCode : public ADbg
{
public:
    ChZnResponseCode();

    QString cis;                // КИ / КиЗ из запроса
    QString printView;          // КИ без криптоподписи / КиЗ
    QString gtin;               // Код товара
    QString message;            // Сообщение об ошибке
    QString packageType;        // Тип упаковки

    QString producerInn;        // ИНН производителя
    QString productionSerialNumber;

    int valid;
    int verified;
    int found;      // Признак наличия КМ в ГИС МТ
    int realizable; // Признак возможности реализации КИ /КиЗ
    // Признак показывает, находится ли КИ / КиЗ в статусе «В обороте», то есть выполнено ли необходимое условие для реализации в розницу.

    int utilised;   // Признак нанесения КИ / КиЗ на упаковку
    int isBlocked;  // Признак заблокированного КМ
    int isOwner;    // Признак того, что в запросе указан владелец кода
    int isTracking; // Признак старта прослеживаемости в товарной группе
    int sold;       // Признак продажи товара
    int grayZone;

    int errorCode;
/*
        0 - ошибки отсутствуют;
        1 — «Ошибка валидации КМ»;
        2 — «КМ не содержит GTIN»;
        3 — «КМ не содержит серийный номер»;
        4 — «КМ содержит недопустимые символы»;
        5 — «Ошибка верификации криптоподписи КМ (формат крипто-подписи не соответствует типу КМ)»;
        6 — «Ошибка верификации криптоподписи КМ (крипто-подпись не валидная)»;
        7 — «Ошибка верификации криптоподписи КМ (крипто-ключ не валиден)»;
        8 — «КМ не прошел верификацию в  стране эмитента;
        9 — «Найденные AI в КМ не поддерживаются»;
        10 — «КМ не найден в ГИС МТ»
*/
    QString expireDate;         // Дата и время истечения срока годности
    QString productionDate;     // Дата производства продукции

    QVariantList groupIds;      // Массив идентификаторов товарных групп

    bool fillFromJson( const QVariant &var );

    QString fullInfo() const ;
};


class ChZnResponse : public ADbg
{
public:
    ChZnResponse();

    int code;
    QString description;
    int reqTimestamp;       // Дата и время формирования запроса
    QString reqId;          // Уникальный идентификатор запроса

    QString response;       // ответ сервера ЧЗ

    QList<ChZnResponseCode> codeLst;

    bool fillFromJson( const QVariant &var );

    QString fullInfo() const ;

    static ChZnResponse from_Variant( const QVariant &var );
};

Q_DECLARE_METATYPE(ChZnResponse);

#endif // CHZN_RESPONSE_H
