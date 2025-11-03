#include "chzn_validate.h"
#include "my_gui/msg.h"


#include <QSslConfiguration>
#include <QNetworkRequest>

#include "abstract_kkt/a_kkt.h"
#include "abstract_kkt/marking/chzn_response.h"
#include "qp/ntw/qp_networkaccessmanager.h"
#include "qp/ntw/dbg/dbg_network.h"
#include "abstract_kkt/marking/chzn_goods.h"

ChZn_Validate::ChZn_Validate( QObject * parent ) :
    QObject(parent),
    ADbg()
{

}

ChZnResponse ChZn_Validate::validate(  aKKT *kkt, const QString &cdn, const QByteArray &barCd)
{
    // ----------------------------------------------------------
    // проверка запрета продаж в ЧЗ
    // ----------------------------------------------------------

    ChZnResponse resp;

    QString token = kkt->getDeviceMarkingToken();

    QVariantMap mm;

    mm.insert("cdn" , "cdn01.crpt.ru");
    mm.insert("marking_token" , kkt->getDeviceMarkingToken());

    QVariantMap body;
    body.insert("inn", "7804437548");
    QVariantList codes;

    //Scan_Code_Dlg::MarkingCode markingCode = barCodeDlg->getScannedCode();
    QString gtin = barCd.mid(0 , 31 );
    codes.append( gtin );

    body.insert("codes" , codes );

    QString jsn = QtJson::serialize1( body );

    if( ! token.isEmpty() )
    {

        if( ! vrt_get_codes_check_v4( mm , QVariant(), resp ) )
            ;


        qDebug() << resp;

        if ( resp.code != 0 )
        {
            QString err = QString("Ошибка в ответе честного знака !\n ответ:    "+jsn);
            kkt->emit_sig_log( err , qp::gui::LOG_STYLE_ERROR);

            Msg::mess( 0 ,
                       "Проверка кода маркировки в честном знаке",
                       err );

            return resp;
        }

        if( resp.codeLst.at(0).realizable == 0 )
        {
            QString err = QString("Ошибка проверки кода маркировки в честном знаке!\n (%1)").arg("Товара нет в обороте!");
            kkt->emit_sig_log( err , qp::gui::LOG_STYLE_ERROR);

            Msg::mess( 0 ,
                       "Ошибка!",
                       err );
        }



        QString success = QString("Проверка кода маркировки в честном знаке завершилась Успешно!");
        kkt->emit_sig_log( success , qp::gui::LOG_STYLE_RECEIVE2);

        kkt->emit_sig_log( resp.fullInfo() , qp::gui::LOG_STYLE_RECEIVE2);


        /*Msg::mess( 0 , "Проверка кода маркировки",
                   success,
                   "<pre>"+resp.fullInfo()+"</pre>",
                   myGui::HTML_MODE
                   );*/
        return resp;
    }
    else
    {

        Msg::mess( 0 , "Проверка кода маркировки",
                   QString("Онлайн проверка кода маркировки завершилась успешно!")
                   .arg( "[M+]" ),
                   "Проверка наличия в обороте в честном знаке НЕ ПРОВОДИЛАСЬ, только онлайн проверка через ОФД"
                   );
    }

    return resp;

}

QVariant ChZn_Validate::slot_getCdnHosts( const QString &marking_token, int kontur)
{
    /*
      только один раз делаем при запуске приложения

    Обновлять список CDN-площадок в соответствии с пунктом 1.4.1 отдельным процессом в
    фоновом режиме необходимо не ранее чем через 6 часов, но не позднее 7 часов.

    */

    /*
        Описание метода получения списка CDN-площадок
        Хост для тестового контура: https://markirovka.sandbox.crptech.ru
        Хост для продуктивного контура: https://cdn.crpt.ru
    */

    QNetworkRequest request;

    QUrl urlLk;
    urlLk.setScheme("https");

    if( kontur == 0)
        urlLk.setHost( "cdn.crpt.ru" );
    else if( kontur == 1)
        urlLk.setHost( "markirovka.sandbox.crptech.ru" );

    urlLk.setPort(443);
    urlLk.setPath("/api/v4/true-api/cdn/info" );

    QString response;
    QVariant responseObj;
    QVariantMap mm;
    QVariantList lst;
    QStringList slst;
    bool ok;


    request.setUrl(urlLk);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
    request.setRawHeader("X-API-KEY", marking_token.toLocal8Bit() );

    qDebug() << request.url();

    emit sig_log( QString("получить список cdn площадок в честном знаке") , qp::gui::LOG_STYLE_SEND2 );


    // ----------------------------------------------
    //          сам запрос
    // ----------------------------------------------
    response = ntwQuery( GET, request, &ok );
    if( ! ok )
        goto err;

    responseObj = QtJson::parse1(response );
    if( ! responseObj.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = responseObj.toMap();

    if( ! mm.contains("code"))
    {
        emit sig_log( "ошибка парсинга ( отсутсвует code) : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("hosts") || ! mm.value("hosts").canConvert( QVariant::List) )
    {

        emit sig_log( "hosts отсутсвует: "+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    lst = mm.value("hosts").toList();

    foreach( QVariant var, lst)
    {
        if( ! var.canConvert( QVariant::Map) )
        {
            emit sig_log( "в списке должны быть оюъекты [{...},{...}]: " + response  , qp::gui::LOG_STYLE_ERROR );
            goto err;
        }
        QVariantMap hh = var.toMap();

        if( ! hh.contains("host") || ! hh.value("host").canConvert(QVariant::String))
        {
            emit sig_log( "ключ host в списке отсутсвует или не корректен: " + response , qp::gui::LOG_STYLE_ERROR );
            goto err;
        }

        slst.append( hh.value("host").toString() );

    }


    emit sig_finished("успешно" , false );
    return slst;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return slst;
}

QVariant ChZn_Validate::slot_getCdnHostValidation( const QVariantMap &pars)
{
    /*
      Описание метода получения состояния CDN-площадки
    */
    QString cdn, marking_token;
    int kontur;

    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response;
    QVariantMap mm;
    QVariantList lst;
    uint avgTimeMs;
    QVariant answ;


    urlLk.setScheme("https");

    if( ! pars.contains("cdn") )
        goto err;

    if( ! pars.contains("marking_token") )
        goto err;

    //    if( ! pars.contains("kontur") )
    //        goto err;

    cdn = pars.value("cdn").toString();
    marking_token = pars.value("marking_token").toString();
    kontur = pars.value("kontur").toInt();


    //if( kontur == 0)
    urlLk.setHost( cdn );
    // else if( kontur == 1)
    //urlLk.setHost( "markirovka.sandbox.crptech.ru" );

    urlLk.setPort(443);

    urlLk.setPath("/api/v4/true-api/cdn/health/check" );



    request.setUrl(urlLk);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
    request.setRawHeader("X-API-KEY", marking_token.toLocal8Bit() );

    qDebug() << request.url();

    emit sig_log( QString("Проверить состояния CDN-площадки %1 ").arg(cdn) , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( GET, request, &ok );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answ.toMap();

    if( ! mm.contains("code"))
    {
        emit sig_log( "ошибка парсинга ( отсутсвует code) : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("avgTimeMs") || ! mm.value("avgTimeMs").canConvert( QVariant::UInt) )
    {

        emit sig_log( "json параметр avgTimeMs отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    avgTimeMs = mm.value("avgTimeMs").toUInt();


    emit sig_finished("успешно" , false );
    return avgTimeMs;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return avgTimeMs;

}


QVariant ChZn_Validate::slot_get_auth_key( const QVariantMap &params , const QVariantMap &bodyObj)
{
    return get_auth_key( params , bodyObj );
}

QString ChZn_Validate::get_auth_key( const QVariantMap &params  , const QVariantMap &bodyObj)
{
    /*
                1.5.1. Запрос авторизации при единой аутентификации
                Метод используется для получения аутентификационного токена по УКЭП:

                    1. Получение пары «uuid—data», где «uuid»—идентификатор текущей аутентификации,
                    «data»—строка на подпись пользователю.

                    2. Отправка в Систему маркировки данных в том же виде, в котором данные были получены
                    (пара «uuid—data»), только теперь «data»—это подписанная УКЭП строка.
                    3. Сервер отвечает на запрос сообщением с кодом 200 (ОК) и возвращает токен, либо
                    сообщением об ошибке.
                    URL: /auth/key
        */

    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response ;
    QVariantMap mm;

    QVariant answ;


    /*
        Базовые адреса демонстрационного контура:
        • https://markirovka.sandbox.crptech.ru/api/v3
        • https://markirovka.sandbox.crptech.ru/api/v4
        Базовые адреса промышленного контура:
        • https://markirovka.crpt.ru/api/v3/true-api;
        • https://markirovka.crpt.ru/api/v4/true-api


        для необязательных параметров должно быть указано значение «null», если не требуется
        указать какое-либо другое значение. Если для необязательного параметра не заполнено
        значение, документ будет обработан с ошибкой

        После успешной аутентификации пользователь сможет работать с методами API и оперировать
        данными исключительно в рамках зарегистрированной им в ГИС МТ товарной группы.

    */

    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, QVariant(), request, urlLk , http_type);

    request.setUrl(urlLk);



    qDebug() << request.url();

    emit sig_log( QString("Запрос авторизации") , qp::gui::LOG_STYLE_SEND2 );


    // ------------------------------------------------------------------
    response = ntwQuery( GET, request, &ok  );
    if( ! ok )
        goto err;
    // ------------------------------------------------------------------



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answ.toMap();

    if ( ! mm.contains("uuid") || ! mm.value("uuid").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр uuid отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("data") || ! mm.value("data").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр data отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }



    emit sig_finished("успешно" , false );
    return response;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return response;

}

QVariant ChZn_Validate::slot_get_auth_simpleSignIn( const QVariantMap &params , const QVariantMap &bodyObj)
{
    return get_auth_simpleSignIn( params , bodyObj );
}

QString ChZn_Validate::get_auth_simpleSignIn( const QVariantMap &params  , const QVariantMap &bodyObj)
{
    /*
        1.5.2. Получение ключа сессии при единой аутентификации
        URL: /auth/simpleSignIn
        */
    QString Bearer_token;

    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response ;
    QVariantMap mm;

    QVariant answ;
    QByteArray sign;



    HTTP_TYPE http_type;
    //qDebug()<<"bodyObj 2121 2 " <<bodyObj;
    //qDebug()<<"bodyObj 2121 2 " << QtJson::serialize1( bodyObj );

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("Запрос авторизации") , qp::gui::LOG_STYLE_SEND2 );

    QString body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );

    // ----------------------------------------------------------------------
    response = ntwQuery( POST, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;

    // ----------------------------------------------------------------------


    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answ.toMap();

    if ( ! mm.contains("token") || ! mm.value("token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр token отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    Bearer_token = mm.value("token").toString();

    emit sig_finished("успешно" , false );
    return Bearer_token;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return Bearer_token;



    return "";
}


QVariant ChZn_Validate::slot_get_auth_permissive_access(  const QVariantMap &pars , const QVariantMap &bodyObj)
{
    QVariantMap mm = get_auth_permissive_access( pars , bodyObj);

    return mm;
}

QVariantMap ChZn_Validate::get_auth_permissive_access(  const QVariantMap &params  , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QString permissive_access_token;

    QNetworkRequest request;
    QVariantList ll;

    QUrl urlLk;

    bool ok;
    QString response , body;
    QVariantMap mm;

    QVariant answ;
    QByteArray sign;


    QFile file("sign_out.txt"  );
    if( ! file.open( QIODevice::ReadOnly) )
    {
        goto err;
    }
    sign = file.readAll();

    body = "{\"data\":\""+sign+"\"}"; // в одну строку


    /*
        Метод используется для получения аутентификационного токена, предназначенного для вызова
        метода «Метод верификации кодов маркировки и получения сокращённой информации о
        товаре» (/codes/check).
        URL: /auth/permissive-access

        !!!!! это уже авторизация , аутентификация была ранее !!!!
    */


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    qDebug() << request.url();

    emit sig_log( QString("получение аутентификационного токена") , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( POST, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answ.toMap();

    if ( ! mm.contains("access_token") || ! mm.value("access_token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр access_token отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("id_token") || ! mm.value("id_token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр id_token отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("expires_in") || ! mm.value("expires_in").canConvert( QVariant::Int) )
    {
        emit sig_log( "json параметр expires_in отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("token_type") || ! mm.value("token_type").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр token_type отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return mm;


}

QVariant ChZn_Validate::slot_get_product_info( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    QVariantMap str = get_product_info( params , bodyObj );

    return str;
}

QVariantMap ChZn_Validate::get_product_info( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QVariantMap mm;

    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response , body;

    QVariant answ;

    /*
            5.5. Получение информации о карточках товара УОТ
            5.5.1. Метод получения информации о товаре по GTIN товара
            В результате успешного выполнения запроса по списку кодов товаров в ответе возвращается
            массив с информацией о товарах по запрошенным КИ. В результирующем * .json также может
            содержаться набор полей, специфичных для товара конкретной товарной группы (см.
            «Справочник "Дополнительные параметры в ответе в зависимости от товарных групп"»).
            Действует следующее ограничение: не более 1000 значений «gtin» («Код товара») в параметре
            «gtins» («Массив кодов товаров»).
            В ответе метода возвращается информация только по карточкам товаров, для которых значения
            признаков «goodTurnFlag» («Признак готовности товара к обороту») и «goodMarkFlag»
            («Признак готовности к маркировке») равны «true».
            5.5.1.1. Версия V4


            10. Методы «Национального каталога»
            Вызов методов «Национального каталога» возможен с использованием авторизации, доступной
            одним из следующих способов:

            • через параметр «apikey», указываемому в параметрах URL запроса. Параметр является
            обязательным, если в заголовке запроса не указан аутентификационный токен ГИС МТ.
            Значение для параметра «apikey» можно получить в личном кабинете Национального
            каталога в разделе «Профиль» → «Данные участника» (поле «API KEY»). Поле «API KEY»
            отображается только для пользователя с ролью «Администратор»;

            • по токену, полученному в результате вызова метода получения аутентификационного токена
            ГИС МТ (см. раздел «Единая аутентификация») и передаваемому в заголовке запроса
            (параметр «Authorization: Bearer <token>»). Параметр является обязательным, если не указан
            «apikey» в параметрах URL запроса.
    */

    QVariantMap params2;
    params2.insert("gtins", params.value("gtins"));


    body = QtJson::serialize1( bodyObj , &ok, QtJson::JSON_DEFAULT );

    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товарах по gtin") , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answ.toMap();

    if ( ! mm.contains("results") || ! mm.value("results").canConvert( QVariant::List) )
    {
        emit sig_log( "json параметр results отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return mm;
}


QVariant ChZn_Validate::slot_get_cises_info( const  QVariantMap &params , const  QVariantList &bodyObj)
{
    QVariantList str = get_cises_info( params , bodyObj );

    return str;
}
QVariantList ChZn_Validate::get_cises_info( const  QVariantMap &params , const  QVariantList &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара


    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response , body;
    QVariantList lst;


    QVariant answ;

    /*
            5.1.2. Метод получения общедоступной информации о КИ по списку
            Метод возвращает подробную информацию о запрашиваемом списке КИ / КиЗ: в одном запросе
            указывается как один КИ / КиЗ, так и несколько (не более 1000). Также метод возвращает
            информацию о КИ товаров, отгруженных из стран ЕАЭС (если отгрузка была оформлена с
            экземплярным указанием КИ).
            Метод не предназначен для проверки сведений при сканировании КИ на ККТ при реализации
            маркированных товаров.
            Для кодов товарных групп «Альтернативная табачная продукция», «Никотиносодержащая
            продукция» и «Табачная продукция»:
            3541. Логика, которая будет поддерживаться до февраля 2025 года: в запросах КИ для единиц
            товаров, групповых упаковок и наборов можно указывать как с включёнными в скобки
            идентификаторами применения (AI): 01, 21, 8005, так и без скобок. В ответе вид
            нормализованного значения кода управляется входным параметром «childsWithoutBrackets»
            («Признак получения кодов вложений без скобок»). По умолчанию (если параметр не
            передан) код возвращается со скобками.

            2. Логика, которая будет поддерживаться с февраля 2025 года: из кодов идентификации
            единиц, групповых упаковок и наборов будут полностью исключены круглые скобки,
            обрамляющие идентификаторы применения (AI): 01, 21, 8005. В ответе коды всегда будут
            возвращаться без скобок.
            ВАЖНО
            Если Ваши API интеграции завязаны на указании кодов со скобками и без,
            то необходимо доработать обмен данными на формат указания и
            получения кодов без обрамляющих скобок
            3. Поиск КИ реализован с МРЦ и без МРЦ для единиц товаров и групповых упаковок. Если
            произойдёт совпадение КИ потребительской упаковки, указанного с учётом МРЦ или иной
            информации, с КИ транспортной упаковки, то в ответе будут выведены значения и по
            потребительской, и по транспортной упаковкам.

            Тип приватности: c токеном авторизации !!!!

            Общедоступная информация:
            • информация о КИ / КиЗ;
            • данные о производителе;
            • дата и время производства;
            • текущий статус в обороте;
            • текущий владелец

            curl -X POST "<url стенда>/cises/info?pg=lp"
            -H "accept: application/json"
            -H "Content-Type: application/json"

            [
            "010460000000000021LLLLLLLLLLLLL"
            ]
    */

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товарах по gtin") , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::List) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    lst = answ.toList();

    if( lst.count() == 0)
    {
        emit sig_log(  "пустой список в ответе : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    emit sig_log(  QtJson::serialize1( lst , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return lst;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return lst;


}

QVariant ChZn_Validate::slot_get_cises_ease_info( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QVariantMap str = get_cises_ease_info( params , bodyObj );

    return str;
}
QVariantMap ChZn_Validate::get_cises_ease_info( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара


    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response , body;
    QVariantMap mm;


    QVariant answ;


    /*

    */

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товарах по gtin") , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answ.toMap();


    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return mm;


}
QVariant ChZn_Validate::slot_get_cises_check( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QVariantMap str = get_cises_check( params , bodyObj );

    return str;
}
QVariantMap ChZn_Validate::get_cises_check( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString response , body;
    QVariantMap mm;


    QVariant answ;


    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    emit sig_log( QString("Проверка наличия в ГИС МТ указанного КИ") , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answ.toMap();


    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return mm;


}

void ChZn_Validate::common_prepare_url_and_request( const  QVariantMap &params, const QVariant & bodyObj, QNetworkRequest& request, QUrl & urlLk ,HTTP_TYPE &http_type)
{
    urlLk.setScheme("https");
    urlLk.setPort(443);
    // ----------------------------------------------------------

    int kontur = params.value("kontur").toInt();
    int ver = params.value("api_version").toInt();

    if( kontur == 0)
        urlLk.setHost( "markirovka.crpt.ru" );         // продуктивный
    else if( kontur == 1)
        urlLk.setHost( "markirovka.sandbox.crptech.ru" );         // тестовый
    // ----------------------------------------------------------

    QString cmdName = params.value("cmd").toString() ;
    if( ver == 3)
        urlLk.setPath("/api/v3/true-api"+cmdName);
    else
        urlLk.setPath("/api/v4/true-api"+cmdName);

    // ----------------------------------------------------------

    if( params.contains("get_gtin") )
    {
        urlLk.addQueryItem("gtin" , params.value("get_gtin").toString() );
    }

    if( params.contains("lk_api_key") )
    {
        urlLk.addQueryItem("apikey" , params.value("lk_api_key").toString() );
    }
    else if( params.contains("access_token") )
    {
        request.setRawHeader("X-Api-Key", params.value("access_token").toString().toLocal8Bit() );
    }
    else
    {
        QString Bearer_token = params.value("Bearer_token").toString();
        if( ! Bearer_token.isEmpty())
        request.setRawHeader( "Authorization","Bearer "+Bearer_token.toLocal8Bit()+"" );
    }

    request.setRawHeader("Accept","application/json" );

    if ( ! bodyObj.isNull() )
    {
        http_type = POST;
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }
    else
        http_type = GET;

}

QVariant ChZn_Validate::slot_get_nk_product( const  QVariantMap &params , const QVariantMap &body)
{
    QString str = get_nk_product( params, body);

    return str;
}


QString ChZn_Validate::get_nk_product( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QString product_info;

    QNetworkRequest request;
    QVariantList ll;

    QUrl urlLk;

    bool ok;
    QString response , body;
    QVariantMap mm;


    QVariant answ;


    /*
        10.8. Метод получения полной информации о товаре
        Метод возвращает краткую или полную информацию о продукте (товаре) и требует
        обязательного указания одного из следующих параметров: идентификатор товара или код товара
        (штрих-код) товара.
        Если указан один из параметров gtin или good_id и один из параметров gtins или good_ids, то
        возвращается ошибка 400.
        Если указаны оба обязательных параметра, то возвращается результат выборки,
        соответствующий параметру good_id. Если карточка товара с данным идентификатором не
        обнаружена, то возвращается ошибка 404 независимо от указания кода товара в запросе.
        Ограничения:
        • не более 10 запросов за 5 минут;
        • не более 25 «gtin» («Глобальный код товара (штрих-код)») / «good_id» («Идентификатор
        товара в каталоге») в одном запросе.

        Тип приватности: публичный !!!
    */

    //    QVariantMap params2 = params;

    //    QVariantList cisesLst = params2.value("cises").toList();





    HTTP_TYPE http_type;// = GET;


    common_prepare_url_and_request( params, QVariant(), request, urlLk , http_type);

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товарах по gtin") , qp::gui::LOG_STYLE_SEND2 );


    response = ntwQuery( http_type, request, &ok  );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answ.toMap();

    if ( ! mm.contains("access_token") || ! mm.value("access_token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр access_token отсутствует: "+response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    product_info = mm.value("id_token").toString();



    emit sig_finished("успешно" , false );
    return product_info;

err:
    emit sig_finished( "завершено с ошибкой: "+ response , true );

    return product_info;


}



QString ChZn_Validate::ntwQuery( HTTP_TYPE qqType, QNetworkRequest &request, bool *ok, const QByteArray &body)
{
    if( ok !=0 )
        *ok = false;

    QString tt;
    if( qqType == GET )
        tt = "GET";
    else if( qqType == POST )
        tt = "POST";

    emit sig_log(request.url().toString() , qp::gui::LOG_STYLE_SEND2 );
    emit sig_log(tt , qp::gui::LOG_STYLE_SEND );

    QString headers;
    foreach( QString key , request.rawHeaderList() )
    {
        headers.append( key + ": " + request.rawHeader( key.toLocal8Bit()) +"\r\n");
    }

    emit sig_log( QString("заголовки:\n%1").arg(headers) , qp::gui::LOG_STYLE_SEND );
    // -------------------------------------------------------------------------------

    request.setSslConfiguration( QSslConfiguration::defaultConfiguration() );

    QpNetworkAccessManager qnam;

    QString response;

    if( qqType == POST)
        emit sig_log( "--> " + body , qp::gui::LOG_STYLE_SEND );

    QEventLoop loop;

    QNetworkReply *reply =0 ;

    if( qqType == GET)
        reply = qnam.get( request );

    else if( qqType == POST)
        reply = qnam.post( request , body );


    qp::meta::cnct(reply, SIGNAL(finished()),&loop, SLOT(quit()));

    loop.exec();

    if( reply->error() != QNetworkReply::NoError)
    {
        response = QString("{\"network error\":\"%1\"}").arg(qp::dbg_ntw::toStr_NetworkError(reply->error()));

        qDebug()<< "\n networkErr : " << response;

        emit sig_log( "завершилось с ошибкой: " + qp::dbg_ntw::toStr_NetworkError(reply->error())  , qp::gui::LOG_STYLE_ERROR );

        response = reply->readAll();

        emit sig_log( "<-- "+response , qp::gui::LOG_STYLE_ERROR );


        reply->deleteLater();
        reply = 0;

        return response;
    }

    if( ok !=0 )
        *ok = true;

    response = reply->readAll();

    emit sig_log( "<-- "+response , qp::gui::LOG_STYLE_RECEIVE );


    QVariant mm = QtJson::parse1( response );

    bool ok1;
    response = QtJson::serialize1( mm , &ok1 );


    reply->deleteLater();
    reply = 0;

    return response;
}

QVariant ChZn_Validate::slot_get_codes_check( const QVariantMap &params,  const QVariantMap &bodyObj)
{
    ChZnResponse chznResp;

    return vrt_get_codes_check_v4( params, bodyObj, chznResp );
}

bool ChZn_Validate::vrt_get_codes_check_v4( const QVariantMap &params,  const QVariant &bodyObj, ChZnResponse &chznResp)
{

    QString sBody, sBody2;

    QVariantList lst;
    QString cdn, marking_token, response;

    QNetworkRequest request;
    bool ok;

    QVariant mm;
    QUrl urlLk;


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type );

    request.setUrl(urlLk);

    QString body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_OPTIONS(QtJson::JSON_DEFAULT | QtJson::JSON_UNESCAPED_UNICODE) );

    qDebug() << request.url();

    //    lst = params.value("codes").toList();

    //    //Должен указываться полный КМ (с крипто-подписью), символ GS (по таблице ASCII—код 029) в составе КМ необходимо экранировать с помощью \u001d
    //    sBody.reserve(200);
    //    sBody.append("{\"codes\":[\n");

    //    // -------------------------------------------------
    //    // почему тут хоровод с \u001d потому-что...
    //    // -------------------------------------------------
    //    for( int ii=0; ii< lst.count(); ii++)
    //    {
    //        QString str = lst.at(ii).toString();

    //        if(! sBody2.isEmpty())
    //            sBody2.append(",\n");

    //        if( str.indexOf( QChar(0x1d) ) >0 )
    //        {
    //            QString str2 = str.replace( QChar(0x1d) , QLatin1String("\\u001d"));


    //            sBody2.append( "\""+str2 +"\"");

    //        }
    //        else
    //            sBody2.append( "\""+str +"\"");
    //    }

    //    sBody.append(sBody2);
    //    sBody.append("\n]}");


    response = ntwQuery( http_type, request, &ok , body.toLocal8Bit());
    if( ! ok )
        goto err;

    mm = QtJson::parse1( response );

    if ( ! chznResp.fillFromJson( mm ) )
    {
        QString err = QString("Ошибка в парисинге ответа честного знака !");
        ////kkt->emit_sig_log( err , qp::gui::LOG_STYLE_ERROR);

        Msg::mess( 0 ,
                   "Проверка кода маркировки в честном знаке",
                   err );
        goto err;

    }

    emit sig_finished( "завершено успешно", false );
    return true;

err:
    emit sig_finished( "завершение с ошибкой", true);
    return false;
}

bool ChZn_Validate::vrt_get_codes_check_v4_cdn( const QVariantMap &params,  const QVariant &bodyObj, ChZnResponse &chznResp)
{

    QString sBody, sBody2;

    QVariantList lst;
    QString cdn, marking_token, response;

    QNetworkRequest request;
    bool ok;

    QVariant mm;
    QUrl urlLk;

    if( ! params.contains("cdn") )
        goto err;

    if( ! params.contains("marking_token") )
        goto err;

    if( ! params.contains("codes") || ! params.value("codes").canConvert( QVariant::List) )
        goto err;

    cdn = params.value("cdn").toString();
    marking_token = params.value("marking_token").toString();


    urlLk.setScheme("https");
    urlLk.setHost( cdn );
    urlLk.setPort(443);
    urlLk.setPath("/api/v4/true-api/codes/check" );

    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, QVariant(), request, urlLk , http_type );

    request.setUrl(urlLk);


    qDebug() << request.url();

    lst = params.value("codes").toList();

    //Должен указываться полный КМ (с крипто-подписью), символ GS (по таблице ASCII—код 029) в составе КМ необходимо экранировать с помощью \u001d
    sBody.reserve(200);
    sBody.append("{\"codes\":[\n");

    // -------------------------------------------------
    // почему тут хоровод с \u001d потому-что...
    // -------------------------------------------------
    for( int ii=0; ii< lst.count(); ii++)
    {
        QString str = lst.at(ii).toString();

        if(! sBody2.isEmpty())
            sBody2.append(",\n");

        if( str.indexOf( QChar(0x1d) ) >0 )
        {
            QString str2 = str.replace( QChar(0x1d) , QLatin1String("\\u001d"));


            sBody2.append( "\""+str2 +"\"");

        }
        else
            sBody2.append( "\""+str +"\"");
    }

    sBody.append(sBody2);
    sBody.append("\n]}");


    response = ntwQuery( http_type, request, &ok , sBody.toLocal8Bit());
    if( ! ok )
        goto err;

    mm = QtJson::parse1( response );

    if ( ! chznResp.fillFromJson( mm ) )
    {
        QString err = QString("Ошибка в парисинге ответа честного знака !");
        ////kkt->emit_sig_log( err , qp::gui::LOG_STYLE_ERROR);

        Msg::mess( 0 ,
                   "Проверка кода маркировки в честном знаке",
                   err );
        goto err;

    }

    emit sig_finished( "завершено успешно", false );
    return true;

err:
    emit sig_finished( "завершение с ошибкой", true);
    return false;
}

QString ChZn_Validate::fullInfo( int level ) const
{
    return QString();
}
