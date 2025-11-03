#ifndef CHZN_RESPONSECODE_H
#define CHZN_RESPONSECODE_H

#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"

#include "../dll_chzn_global.h"
class LIB_PREFIX_CHZN ChZnResponseCode : public ADbg
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

    int valid;      // Результат проверки валидности структуры КМ
    int verified;   // Результат проверки криптоподписи КМ
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

    static QString canToSell( const ChZnResponseCode& rc );

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;
};

Q_DECLARE_METATYPE(ChZnResponseCode);

#endif // CHZN_RESPONSECODE_H
