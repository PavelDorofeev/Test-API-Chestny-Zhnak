#ifndef ONLINERES_H
#define ONLINERES_H

#include <QMetaType>
#include <QVariant>
#include <QString>
#include <QDateTime>

#include "qp/core/dbg/abstract_dbg.h"
//#include "chzn_response.h"
#include "ofdonlineres.h"
#include "offline_res.h"

#include "dll_marking_global.h"

class LIB_PREFIX_MARKING  MarkingRes : public ADbg
{
public:

    MarkingRes();

    OfflineRes  offline;     // оффлайн проверка в ФН

    OnlineOfdRes onlineOfd;     // онлайн проверка через ФН в ОИСМ

    //ChZnResponse onlineChzn;   // онлайн проверка через честный знак


    int mrkCodeType_2100;
    /*
    // результаты обработки запроса" (тег 2005)
        Состояние бита в зависимости от результата проверки КМ и статуса товара
        1
            "0" - результат проверки КП КМ отрицательный
            "1" - результат проверки КП КМ положительный
        3
            "0" - статус товара некорректен (если реквизит "ответ ОИСМ о статусе товара"
                (тег 2109) принимает значение "2" или "3")
            "1" - статус товара корректен (если реквизит "ответ ОИСМ о статусе товара"
                (тег 2109) принимает значение "1")
        0, 2 Заполняются единицами
        4 - 7 Заполняются нулями

        Примечания:
        1) В случае, если реквизиту "код маркировки" (тег 2000) не присвоено значение (пустая
        строка), то биты 1 и 3 реквизита "результаты обработки запроса" (тег 2005) должны быть
        установлены в состояние "0".
        141. Состояния битов в значении реквизита "результат проверки сведений о товаре" (тег
        2106) кодируются битовыми флагами, описание которых приведено в таблице 110.
    */


    QString markingCodeTypeToStr( int mrkCodeType_2100 ) const;

    QString fullInfo( int level = 0 ) const;

    static MarkingRes from_Variant( const QVariant &var );
};

Q_DECLARE_METATYPE (MarkingRes);

#endif // ONLINERES_H
