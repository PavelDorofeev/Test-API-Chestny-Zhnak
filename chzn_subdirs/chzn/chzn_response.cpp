#include "chzn_response.h"


// ---------------------------------------------------------
ChZnResponseLst::ChZnResponseLst()
    :ADbg(),
      code(-1),
      description(QString()),
      reqTimestamp(-1),
      reqId(QString())
{

}

bool ChZnResponseLst::fillFromJson( const QVariant &var )
{
    ChZnResponseLst resp;
    codeLst.clear();

    if ( ! var.canConvert( QVariant::Map ) )
        return false;

    bool ok;

    QVariantMap mm = var.toMap();

    if( mm.contains("code") && mm.value("code").canConvert(QVariant::Int))
        code = mm.value("code").toInt( &ok);

    if( mm.contains("description") && mm.value("description").canConvert(QVariant::String))
        description = mm.value("description").toString();


    if( mm.contains("reqTimestamp") && mm.value("reqTimestamp").canConvert(QVariant::Int))
        reqTimestamp = mm.value("reqTimestamp").toInt( &ok);

    if( mm.contains("reqId") && mm.value("reqId").canConvert(QVariant::String))
        reqId = mm.value("reqId").toString();

    if( mm.contains("codes") && mm.value("codes").canConvert(QVariant::List))
    {
        QVariantList lst = mm.value("codes").toList();

        foreach( QVariant var , lst)
        {
            ChZnResponseCode item;

            if ( ! item.fillFromJson(var) )
                ;

            codeLst.append( item );

        }
    }


    return true;
}

QString ChZnResponseLst::fullInfo( int level ) const
{
    QString str;
    str.reserve(250);

    str.append( QString("\n --------- ChZnResponse ---------"));
    str.append( QString("\n code              : %1").arg( code ));
    str.append( QString("\n description       : %1").arg( description ));
    str.append( QString("\n reqTimestamp      : %1").arg( reqTimestamp ));
    str.append( QString("\n reqId             : %1").arg( reqId ));

    int cnt = 1;
    foreach(ChZnResponseCode code, codeLst)
    {
        str.append(QString("\n ---------- %1 ----------").arg(cnt++));
        str.append( code.fullInfo());
    }

    return str;
}

ChZnResponseLst ChZnResponseLst::from_Variant( const QVariant &var )
{
    ChZnResponseLst resp;

    if( ! var.isValid())
    {
        qDebug() << "45645635465464";
        Q_ASSERT( var.isValid() );
        return resp;
    }

    return qvariant_cast<ChZnResponseLst>( var );
}

QString ChZnResponseCode::canToSell( const ChZnResponseCode& rc )
{
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

    if( rc.errorCode != 0 )
        return QString("errcode %1 ").arg(rc.errorCode)  + rc.message;

    if( rc.found == 0)
        return "кода маркировки не найден " + rc.message;

    else if( rc.valid == 0)
        return "Структура кода маркировки не валидная " + rc.message;

    else if( rc.verified == 0)
        return "Проверка крипто-подписи завершилась с ошибкой " + rc.message;

    else if( rc.realizable == 0)
        return "КИ в НЕ в обороте" + rc.message;

    else if( rc.utilised == 0)
        return "КИ не нанесён" + rc.message;

    else if( rc.isBlocked == 1)
        return "продукции заблокирована по решению ОГВ" + rc.message;

    //    else if(  rc.sold )
    //        return " товар выведен из оборота или имеет признак множественных продаж";

//    else if(  rc.grayZone )
//        return "Признак принадлежности табачной продукции к «серой зоне»";

    return "ok";

}
