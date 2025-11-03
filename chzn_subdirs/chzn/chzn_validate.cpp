#include "chzn_validate.h"
#include "qp/core/json/my_json.h"

#include <QMessageBox>
#include <QSslConfiguration>
#include <QNetworkRequest>

//#include "abstract_kkt/a_kkt.h"
#include "chzn_response.h"
#include "chzn_goods_info.h"
#include "qp/ntw/qp_networkaccessmanager.h"
#include "qp/ntw/dbg/dbg_network.h"
#include "chzn_goodsinfo_lst.h"
#include "qp/core/logging_system/logging_system.h"

ChZn_Validate::ChZn_Validate( QObject * parent ) :
    QObject(parent),
    ADbg()
{

}

ChZnResponseLst ChZn_Validate::validate(  const QString &token, const QString &cdn, const QByteArray &barCd)
{
    // ----------------------------------------------------------
    // проверка запрета продаж в ЧЗ
    // ----------------------------------------------------------

    ChZnResponseLst resp;

    //    QString token = kkt->getDeviceMarkingToken();

    QVariantMap mm;

    mm.insert("cdn" , "cdn01.crpt.ru");
    mm.insert("marking_token" , token);

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

        resp = vrt_get_codes_check_v4_cdn( mm , QVariant() );



        qDebug() << resp;

        if ( resp.code != 0 )
        {
            QString err = QString("Ошибка в ответе честного знака !\n ответ:    "+jsn);
            emit sig_log( err , qp::gui::LOG_STYLE_ERROR);

            QMessageBox::warning( 0 ,
                       "Проверка кода маркировки в честном знаке",
                       err );

            return resp;
        }

        if( resp.codeLst.at(0).realizable == 0 )
        {
            QString err = QString("Ошибка проверки кода маркировки в честном знаке!\n (%1)").arg("Товара нет в обороте!");
            emit sig_log( err , qp::gui::LOG_STYLE_ERROR);

            QMessageBox::warning( 0 ,
                       "Ошибка!",
                       err );
        }



        QString success = QString("Проверка кода маркировки в честном знаке завершилась Успешно!");
        emit sig_log( success , qp::gui::LOG_STYLE_RECEIVE2);

        emit sig_log( resp.fullInfo() , qp::gui::LOG_STYLE_RECEIVE2);


        /*QMessageBox::warning( 0 , "Проверка кода маркировки",
                   success,
                   "<pre>"+resp.fullInfo()+"</pre>",
                   myGui::HTML_MODE
                   );*/
        return resp;
    }
    else
    {

        QMessageBox::warning( 0 , "Проверка кода маркировки",
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
    NtwQueryAnsw answ = ntwQuery( GET, request, &ok, QByteArray(), false );

    responseObj = QtJson::parse1(answ.response );

    if( ! responseObj.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ answ.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = responseObj.toMap();

    if( ! mm.contains("code"))
    {
        emit sig_log( "ошибка парсинга ( отсутсвует code) : "+ answ.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( answ.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( answ.response  , qp::gui::LOG_STYLE_ERROR );
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
            emit sig_log( "в списке должны быть оюъекты [{...},{...}]: " + answ.response  , qp::gui::LOG_STYLE_ERROR );
            goto err;
        }
        QVariantMap hh = var.toMap();

        if( ! hh.contains("host") || ! hh.value("host").canConvert(QVariant::String))
        {
            emit sig_log( "ключ host в списке отсутсвует или не корректен: " + answ.response , qp::gui::LOG_STYLE_ERROR );
            goto err;
        }

        slst.append( hh.value("host").toString() );

    }


    emit sig_finished("успешно" , false );
    return slst;

err:
    emit sig_finished( "завершено с ошибкой: "+ answ.response , true );

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


    QVariantMap mm;
    QVariantList lst;
    uint avgTimeMs;
    QVariant answ;
    NtwQueryAnsw answ1;


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


    answ1 = ntwQuery( GET, request, &ok );
    if( ! ok )
        goto err;



    answ = QtJson::parse1(answ1.response );

    if( ! answ.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ answ1.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answ.toMap();

    if( ! mm.contains("code"))
    {
        emit sig_log( "ошибка парсинга ( отсутсвует code) : "+ answ1.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( answ1.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( mm.value("code").toInt( &ok) != 0 || !ok)
    {
        if( mm.contains("description") && mm.value("description").canConvert( QVariant::String) )
        {
            emit sig_log( "description"+mm.value("description").toString()  , qp::gui::LOG_STYLE_ERROR );
        }
        emit sig_log( answ1.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("avgTimeMs") || ! mm.value("avgTimeMs").canConvert( QVariant::UInt) )
    {

        emit sig_log( "json параметр avgTimeMs отсутствует: "+answ1.response  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    avgTimeMs = mm.value("avgTimeMs").toUInt();


    emit sig_finished("успешно" , false );
    return avgTimeMs;

err:

    emit sig_finished( "завершено с ошибкой: "+ answ1.response , true );

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
    NtwQueryAnsw answ;
    QVariant answVar;
    QVariantMap mm;


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

    if ( ! common_prepare_url_and_request( params, QVariant(), request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);



    qDebug() << request.url();

    emit sig_log( QString("Запрос авторизации") , qp::gui::LOG_STYLE_SEND2 );


    // ------------------------------------------------------------------
    answ = ntwQuery( GET, request, &ok  );
    if( ! ok )
        goto err;
    // ------------------------------------------------------------------



    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answVar.toMap();

    if ( ! mm.contains("uuid") || ! mm.value("uuid").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр uuid отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("data") || ! mm.value("data").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр data отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }



    emit sig_finished("успешно" , false );
    return answ.response;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return answ.response;

}

QString ChZn_Validate::ret_err( const NtwQueryAnsw &answ) const
{
    QVariant var = QtJson::parse1( answ.response );

    if( var.canConvert( QVariant::Map) || var.canConvert( QVariant::List))
    {
        QString str = QtJson::serialize1( var );

        return QString("%1\n%2")
                .arg( qp::dbg_ntw::toStr_NetworkError( answ.ntwErrCode) )
                .arg( str );
    }
    else
    {
        return QString("%1\n%2")
                .arg( qp::dbg_ntw::toStr_NetworkError( answ.ntwErrCode) )
                .arg( answ.response );
    }
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
    NtwQueryAnsw answ;
    QVariantMap mm;

    QVariant answVar;
    //QByteArray signed_data;


    HTTP_TYPE http_type;


    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("Запрос авторизации") , qp::gui::LOG_STYLE_SEND2 );

    QString body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );

    // ----------------------------------------------------------------------
    answ = ntwQuery( POST, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;

    // ----------------------------------------------------------------------


    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answVar.toMap();

    if ( ! mm.contains("token") || ! mm.value("token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр token отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    Bearer_token = mm.value("token").toString();

    emit sig_finished("успешно" , false );
    return Bearer_token;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

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

    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString  body;
    NtwQueryAnsw answ;
    QVariantMap mm;

    QVariant answVar;

    //QVariantMap params = params2;

    if( ! bodyObj.contains("data") || bodyObj.value("data").toString().isEmpty())
    {
        emit sig_log( "параметр data не передан в теле зароса (или не корректен)" ,qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    //body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT ); // в одну строку


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

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );

    answ = ntwQuery( POST, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answVar.toMap();

    if ( ! mm.contains("access_token") || ! mm.value("access_token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр access_token отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("id_token") || ! mm.value("id_token").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр id_token отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("expires_in") || ! mm.value("expires_in").canConvert( QVariant::Int) )
    {
        emit sig_log( "json параметр expires_in отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    if ( ! mm.contains("token_type") || ! mm.value("token_type").canConvert( QVariant::String) )
    {
        emit sig_log( "json параметр token_type отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

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
    QString  body;
    NtwQueryAnsw answ;

    QVariant answVar;

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

    emit sig_log( QString("Получить информацию о товаре") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit(), false );


    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answVar.toMap();

    if ( ! mm.contains("results") || ! mm.value("results").canConvert( QVariant::List) )
    {
        emit sig_log( "json параметр results отсутствует: "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    emit sig_log( QtJson::serialize1( mm ) , qp::gui::LOG_STYLE_RECEIVE2 );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return mm;
}

QVariant ChZn_Validate::slot_get_short_product_info( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    QVariantMap str = get_short_product_info( params , bodyObj );

    return str;
}

QVariantMap ChZn_Validate::get_short_product_info( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QVariantMap mm;

    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString  body;
    NtwQueryAnsw answ;

    QVariant answVar;

    /*
            Метод получения краткой информации о товаре
            Метод возвращает краткую или полную информацию о продукте (товаре).
            Требует обязательного указания одного из следующих параметров: идентификатор товара, код
            товара (штрих-код) с указанием идентификатора торговой сети, который относится к
            запрашиваемому аккаунту.
            Если указаны более одного из обязательных параметров, то возвращается результат выборки,
            соответствующий данному алгоритму:
            • good_id — при указании, возвращается товар с соответствующим идентификатором или
            ошибка 404. При этом код товара (штрих код) игнорируется;
            • gtin — при указании, возвращается товар с соответствующим кодом товара (штрих код) или
            ошибка 404;
            • gtins и good_ids — при указании, возвращается результат выборки по обоим параметрам.
            При указании одного из параметров gtin или good_id и одного из параметров gtins или good_ids,
            возвращается ошибка 400.
            Тип приватности: публичный
            URL: /nk/short-product
            Метод: GET
            Пример запроса:
            curl -X GET "<url стенда>/nk/short-product?gtin=0000000000000"
            -H "accept: application/json"
            -H "Authorization: Bearer <ТОКЕН>"
    */

    QVariantMap params2;
    params2.insert("gtins", params.value("gtins"));


    body = QtJson::serialize1( bodyObj , &ok, QtJson::JSON_DEFAULT );

    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товаре") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit(), false );


    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answVar.toMap();

    if ( ! mm.contains("results") || ! mm.value("results").canConvert( QVariant::List) )
    {
        emit sig_log( "json параметр results отсутствует: "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    emit sig_log( QtJson::serialize1( mm ) , qp::gui::LOG_STYLE_RECEIVE2 );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return mm;
}


QVariant ChZn_Validate::slot_get_cises_info( const  QVariantMap &params , const  QVariantList &bodyObj)
{
    ChZnGoodsInfoLst goodsLst = get_cises_info( params , bodyObj );

    qDebug() << goodsLst ;

    return QVariant::fromValue ( goodsLst);
}

ChZnGoodsInfoLst ChZn_Validate::get_cises_info( const  QVariantMap &params , const  QVariantList &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара


    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString  body;
    NtwQueryAnsw answ;
    ChZnGoodsInfoLst goodsLst;

    QVariant answVar;
    QVariantList varLst;

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

    emit sig_log( QString("Получить информацию о товарах по КИ") , qp::gui::LOG_STYLE_SEND2 );


    // -----------------------------------------------------------------------------
    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit(), false );
    // -----------------------------------------------------------------------------

    goodsLst.networkError = answ.ntwErrCode;

    // все равно считываем данные тела, не выходим

    answVar = QtJson::parse1( answ.response);

    if( ! answVar.canConvert(QVariant::List) ) // v4 будет лист
    {
        goto err;
    }

    varLst = answVar.toList();

    if( varLst.count() == 0)
    {
        emit sig_log(  "пустой список в ответе : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    // заполняем лист

    if ( ! goodsLst.fillFromJson( varLst ) )
    {
        emit sig_log(  "ошибка парсинга принятого json тела : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    emit sig_log(  QtJson::serialize1( varLst , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return goodsLst;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return goodsLst;


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
    QString  body;
    NtwQueryAnsw answ;

    QVariantMap mm;


    QVariant answVar;


    /*

    */

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товаре") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answVar.toMap();


    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return mm;


}

QVariant ChZn_Validate::common_cmd_with_log_Dlg( QWidget *wgt,
                                                 const QVariantMap &params ,
                                                 const QVariant &bodyObj,
                                                 const QString &slotName ,
                                                 const QString &title )
{
    //ChZn_Validate chzn( wgt );

    QVariant retVal;

    bool bbb = qp::gui::call_slot( wgt ,

                                   this ,

                                   title,

                                   "",

                                   "Ждите идет процесс...",

                                   slotName,

                                   QList<const QObject*>() << this,

                                   QList<QVariant>() << params << bodyObj ,

                                   retVal,

                                   false
                                   );

    if( ! bbb )
        return false ;

    return retVal;
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
    QString  body;
    NtwQueryAnsw answ;
    QVariantMap mm;


    QVariant answVar;


    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    emit sig_log( QString("Проверка наличия в ГИС МТ указанного КИ") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit() , false );

    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answVar.toMap();


    if ( ! mm.contains("result")  )
    {
        emit sig_log( "json параметр result отсутствует: "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }


    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return mm;
}

QVariant ChZn_Validate::slot_get_cises_check_history_create( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QVariantMap str = get_cises_check_history_create( params , bodyObj );

    return str;
}
QVariantMap ChZn_Validate::get_cises_check_history_create( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString  body;
    NtwQueryAnsw answ;

    QVariantMap mm;

    QVariant answVar;


    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );


    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    emit sig_log( QString("формирования выгрузки по запросам codes/check") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    if( ! ok )
        goto err;



    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answVar.toMap();


    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return mm;


}

QVariant ChZn_Validate::slot_get_cises_check_history_receive( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QVariantMap str = get_cises_check_history_receive( params , bodyObj );

    return str;
}
QVariantMap ChZn_Validate::get_cises_check_history_receive( const  QVariantMap &params , const  QVariantMap &bodyObj)
{
    QNetworkRequest request;

    QUrl urlLk;

    bool ok;
    QString  body;
    NtwQueryAnsw answ;
    QVariantMap mm;

    QVariant answVar;

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );

    HTTP_TYPE http_type;

    common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type);

    request.setUrl(urlLk);


    emit sig_log( QString("Метод получения результата выгрузки codes/check") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok  );
    if( ! ok )
        goto err;



    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    mm = answVar.toMap();


    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished("успешно" , false );
    return mm;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return mm;


}

bool ChZn_Validate::common_prepare_lm_url_and_request( const  QVariantMap &params, const QVariant & bodyObj, QNetworkRequest& request, QUrl & urlLk ,HTTP_TYPE &http_type)
{
    urlLk.setScheme("http");
    urlLk.setPort(5995);

    qDebug()  << "55555999555 " << QtJson::serialize1( params ) ;
    qDebug()  << "bodyObj " << QtJson::serialize1( bodyObj ) ;
    // ----------------------------------------------------------

    request.setRawHeader("Accept","application/json" );

    //QVariantMap();
    if ( ! bodyObj.isNull() && ( bodyObj.canConvert( QVariant::Map) && bodyObj.toMap().count() != 0 ))
    {
        http_type = POST;
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }
    else
        http_type = GET;
    // ----------------------------------------------------------

    QString cmdName = params.value("cmd").toString() ;


    //    int kontur = params.value("kontur").toInt();
    //    int ver = params.value("api_version").toInt();

    //    if( kontur == 0)
    urlLk.setHost( "127.0.0.1" );         // продуктивный
    //    else if( kontur == 1)
    //        urlLk.setHost( "markirovka.sandbox.crptech.ru" );         // тестовый
    // ----------------------------------------------------------


    //if( ver == 3)
    urlLk.setPath("/api/v1"+cmdName);
    //    else
    //        urlLk.setPath("/api/v4/true-api"+cmdName);

    // ----------------------------------------------------------

    if( ! params.contains("Basic_token") || params.value("Basic_token").toString().isEmpty() )
    {
        emit sig_log("Authorization: Basic не передан" ,qp::gui::LOG_STYLE_ERROR);
        return false;
    }

    request.setRawHeader( "Authorization","Basic "+params.value("Basic_token").toString().toLocal8Bit()+"" );


    if( ! params.contains("X-ClientId") || params.value("X-ClientId").toString().isEmpty() )
    {
        emit sig_log("X-ClientId: номер фискального накопителя не передан" ,qp::gui::LOG_STYLE_ERROR);
        return false;
    }

    request.setRawHeader( "X-ClientId",params.value("X-ClientId").toString().toLocal8Bit()+"" );



    return true;

}

bool ChZn_Validate::common_prepare_url_and_request( const  QVariantMap &params, const QVariant & bodyObj, QNetworkRequest& request, QUrl & urlLk ,HTTP_TYPE &http_type)
{
    urlLk.setScheme("https");
    urlLk.setPort(443);

    //qDebug()  << "4444444" << QtJson::serialize1( params );
    // ----------------------------------------------------------

    request.setRawHeader("accept","application/json" );

    if ( ! bodyObj.isNull() )
    {
        http_type = POST;
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }
    else
        http_type = GET;
    // ----------------------------------------------------------

    QString cmdName = params.value("cmd").toString() ;


    if( params.contains( "cdn" ) )
    {
        // ----------------------------------------------------------
        // это проверки кодов маркировки через cdn площадки
        // ----------------------------------------------------------

        if( ! params.contains("X-API-KEY") || params.value("X-API-KEY").toString().isEmpty() )
        {
            sig_log("не указан токен контрольно-кассовой техиники (X-API-KEY)" , qp::gui::LOG_STYLE_ERROR);
            return false;
        }
        QString cdn = params.value( "cdn" ).toString();

        QStringList lst = cdn.split(':');

        if( lst.count() == 2 )
        {
            int port = QVariant(lst.at( 1 )).toInt();

            urlLk.setPort( port );

            cdn = lst.at( 0 );
        }

        qDebug() << "params.value( cdn )" << params.value( "cdn" );
        urlLk.setHost( cdn );

        request.setRawHeader("X-API-KEY", params.value("X-API-KEY").toString().toLocal8Bit() );

        urlLk.setPath("/api/v4/true-api" + cmdName);
    }
    else
    {
        // ----------------------------------------------------------
        // это работа с лк честного знака
        // ----------------------------------------------------------

        int kontur = params.value("kontur").toInt();
        int ver = params.value("api_version").toInt();

        if( kontur == 0)
            urlLk.setHost( "markirovka.crpt.ru" );         // продуктивный
        else if( kontur == 1)
            urlLk.setHost( "markirovka.sandbox.crptech.ru" );         // тестовый
        // ----------------------------------------------------------


        if( ver == 3)
            urlLk.setPath("/api/v3/true-api"+cmdName);
        else
            urlLk.setPath("/api/v4/true-api"+cmdName);

        // ----------------------------------------------------------

        if( params.contains("gtin") )
        {
            urlLk.addQueryItem("gtin" , params.value("gtin").toString() );
        }

        if( params.contains("lk_api_key") )
        {
            urlLk.addQueryItem("apikey" , params.value("lk_api_key").toString() );
        }
        else if( params.contains("X-API-KEY") && ! params.value("X-API-KEY").toString().isEmpty() )
        {

            request.setRawHeader("X-API-KEY", params.value("X-API-KEY").toString().toLocal8Bit() );

        }
        else if( params.contains("Bearer_token") && ! params.value("Bearer_token").toString().isEmpty() )
        {
            QString Bearer_token = params.value("Bearer_token").toString();
            if( ! Bearer_token.isEmpty())
                request.setRawHeader( "Authorization","Bearer "+Bearer_token.toLocal8Bit()+"" );
        }

    }

    return true;

}

QVariant ChZn_Validate::slot_get_nk_product( const  QVariantMap &params , const QVariantMap &body)
{
    Nk_Product_Lst pro = get_nk_product( params, body);

    return QVariant::fromValue( pro );
}


Nk_Product_Lst ChZn_Validate::get_nk_product( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QNetworkRequest request;
    QVariantList ll;
    Nk_Product_Lst nk_product_lst;

    QUrl urlLk;

    bool ok;
    NtwQueryAnsw answ;
    QVariantMap mm;


    QVariant answVar;


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
        GET
    */

    //    QVariantMap params2 = params;

    //    QVariantList cisesLst = params2.value("cises").toList();





    HTTP_TYPE http_type; ;


    if ( ! common_prepare_url_and_request( params, QVariant() , request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товаре") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , QByteArray() , false );


    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answVar.toMap();

    //    if ( ! mm.contains("access_token") || ! mm.value("access_token").canConvert( QVariant::String) )
    //    {
    //        emit sig_log( "json параметр access_token отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
    //        goto err;
    //    }

    nk_product_lst.fillFromJson( answVar );

    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );

    emit sig_finished("успешно" , false );

    return nk_product_lst;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return nk_product_lst;


}

QVariant ChZn_Validate::slot_get_nk_short_product( const  QVariantMap &params , const QVariantMap &body)
{
    QString str = get_nk_short_product( params, body);

    return str;
}


QString ChZn_Validate::get_nk_short_product( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QString product_info;

    QNetworkRequest request;
    QVariantList ll;

    QUrl urlLk;

    bool ok;
    NtwQueryAnsw answ;
    QVariantMap mm;


    QVariant answVar;


    /*
            10.9. Метод получения краткой информации о товаре
            Метод возвращает краткую или полную информацию о продукте (товаре).
            Требует обязательного указания одного из следующих параметров: идентификатор товара, код
            товара (штрих-код) с указанием идентификатора торговой сети, который относится к
            запрашиваемому аккаунту.
            Если указаны более одного из обязательных параметров, то возвращается результат выборки,
            соответствующий данному алгоритму:
            • good_id — при указании, возвращается товар с соответствующим идентификатором или
            ошибка 404. При этом код товара (штрих код) игнорируется;
            • gtin — при указании, возвращается товар с соответствующим кодом товара (штрих код) или
            ошибка 404;
            • gtins и good_ids — при указании, возвращается результат выборки по обоим параметрам.
            При указании одного из параметров gtin или good_id и одного из параметров gtins или good_ids,
            возвращается ошибка 400.
            Тип приватности: публичный
            URL: /nk/short-product
            Метод: GET
            Пример запроса:
            curl -X GET "<url стенда>/nk/short-product?gtin=0000000000000"
            -H "accept: application/json"
            -H "Authorization: Bearer <ТОКЕН>"
    */


    HTTP_TYPE http_type; ;


    if ( ! common_prepare_url_and_request( params, QVariant() , request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товаре") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , QByteArray() , false );


    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answVar.toMap();

    //    if ( ! mm.contains("access_token") || ! mm.value("access_token").canConvert( QVariant::String) )
    //    {
    //        emit sig_log( "json параметр access_token отсутствует: "+ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
    //        goto err;
    //    }

    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );

    product_info = mm.value("id_token").toString();



    emit sig_finished("успешно" , false );
    return product_info;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return product_info;


}

QVariant ChZn_Validate::slot_get_nk_feed_product( const  QVariantMap &params , const QVariantMap &body)
{
    QString str = get_nk_feed_product( params, body);

    return str;
}


QString ChZn_Validate::get_nk_feed_product( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    // Метод получения информации о товаре по GTIN товара

    QString product_info;

    QNetworkRequest request;
    QVariantList ll;

    QUrl urlLk;

    bool ok;
    NtwQueryAnsw answ;
    QVariantMap mm;


    QVariant answVar;


    /*
        10.10. Метод получения карточки товара, в том числе
        неопубликованной карточки
        Метод возвращает всю имеющуюся информацию о продукте, то есть все заполненные атрибуты
        карточки товара независимо от статуса самой карточки, в отличие от метода product, который
        возвращает информацию только по опубликованным карточкам. Требует обязательного указания
        следующих параметров: идентификатор товара (goodId), код товара (штрих-код) и указание
        apikey владельца товара.
        Если указаны оба обязательных параметра, то возвращается результат выборки по good_id. При
        этом код товара игнорируется.
        Если указан один из параметров gtin или good_id и один из параметров gtins или good_ids, то
        возвращается ошибка 400.
        Тип приватности: публичный
        URL: /nk/feed-product
        Метод: GET
        Пример запроса:
        curl -X GET "<url стенда>/nk/feed-product?gtin=0000000000000&format=xml"
        -H "accept: application/json"
        757-H "Authorization: Bearer <ТОКЕН>"
    */

    HTTP_TYPE http_type; ;


    if ( ! common_prepare_url_and_request( params, QVariant() , request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("Получить информацию о товаре") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok , QByteArray() , false );


    answVar = QtJson::parse1(answ.response );

    if( ! answVar.canConvert(QVariant::Map) )
    {
        emit sig_log(  "ошибка парсинга : "+ ret_err(answ)  , qp::gui::LOG_STYLE_ERROR );
        goto err;
    }
    mm = answVar.toMap();

    if ( ! mm.contains("result") || ! mm.value("result").canConvert( QVariant::List) )
    {
        goto err;
    }

    emit sig_log(  QtJson::serialize1( mm , &ok , QtJson::JSON_PRETTY_PRINT )  , qp::gui::LOG_STYLE_RECEIVE );

    product_info = mm.value("id_token").toString();



    emit sig_finished("успешно" , false );
    return product_info;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return product_info;


}



NtwQueryAnsw ChZn_Validate::ntwQuery( HTTP_TYPE qqType,
                                      QNetworkRequest &request,
                                      bool *ok,
                                      const QByteArray &body,
                                      bool log_answ )
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

    QByteArray response;
    QVariant answVar;

    if( qqType == POST)
        emit sig_log( "--> " + body , qp::gui::LOG_STYLE_SEND );

    QEventLoop loop;

    QNetworkReply *reply =0 ;

    NtwQueryAnsw answ;

    // ---------------------------------------------
    if( qqType == GET)
        reply = qnam.get( request );

    else if( qqType == POST)
        reply = qnam.post( request , body );

    // ---------------------------------------------

    qp::meta::cnct(reply, SIGNAL(finished()),&loop, SLOT(quit()));

    loop.exec();

    QNetworkReply::NetworkError err = reply->error();

    if( err  != QNetworkReply::NoError)
    {
        qDebug()<< "\n networkErr : " << response;

        emit sig_log( "завершилось с ошибкой: " + qp::dbg_ntw::toStr_NetworkError(reply->error())  , qp::gui::LOG_STYLE_ERROR );


        response = reply->readAll();

        answVar = QString("%2")
                .arg( QString::fromUtf8( response ) );


        //emit sig_log( "<-- "+response , qp::gui::LOG_STYLE_ERROR ); не надо здесь


        reply->deleteLater();
        reply = 0;

        answ.response = response;
        answ.ntwErrCode =  (int)err;
        return answ ;
    }

    if( ok !=0 )
        *ok = true;

    response = reply->readAll();

    if( log_answ )
        emit sig_log( "<-- "+QString::fromUtf8( response )  , qp::gui::LOG_STYLE_RECEIVE );


    QVariant mm = QtJson::parse1( response );

    bool ok1;
    answVar = QtJson::serialize1( mm , &ok1 );


    reply->deleteLater();
    reply = 0;

    answ.response = response;
    answ.ntwErrCode =  (int)err;
    return answ ;
}

QVariant ChZn_Validate::slot_get_codes_check( const QVariantMap &params,  const QVariantMap &bodyObj)
{
    ChZnResponseLst chznResp = vrt_get_codes_check_v4( params, bodyObj);

    return QVariant::fromValue( chznResp );
}

ChZnResponseLst ChZn_Validate::vrt_get_codes_check_v4( const QVariantMap &params,  const QVariant &bodyObj)
{

    NtwQueryAnsw answ;

    QNetworkRequest request;
    bool ok;
    QString body;

    QVariant mm;
    QUrl urlLk;

    ChZnResponseLst chznResp;


    HTTP_TYPE http_type;

    if ( ! common_prepare_url_and_request( params, bodyObj, request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);

    qDebug() << "request.url()" << request.url().toString();

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_OPTIONS(QtJson::JSON_DEFAULT | QtJson::JSON_UNESCAPED_UNICODE) );


    answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit() , false );

    mm = QtJson::parse1( answ.response );

    if ( ! chznResp.fillFromJson( mm ) )
    {
        QString err = QString("Ошибка в парсинге ответа честного знака !");

        QMessageBox::warning( 0 ,
                   "Проверка кода маркировки в честном знаке",
                   err );
        goto err;

    }

    emit sig_log( prettyJson( answ.response ) , qp::gui::LOG_STYLE_RECEIVE );


    emit sig_finished( "завершено успешно", false );
    return chznResp;

err:

    emit sig_log( "завершение с ошибкой:" + ret_err( answ ), qp::gui::LOG_STYLE_ERROR );

    emit sig_finished( "завершение с ошибкой", true);

    return chznResp;
}

ChZnResponseLst ChZn_Validate::vrt_get_codes_check_v4_cdn( const QVariantMap &params,  const QVariant &bodyObj)
{

    QString sBody, sBody2;

    QVariantList lst;
    QString cdn, marking_token;

    NtwQueryAnsw answ;

    ChZnResponseLst respLst;


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


    answ = ntwQuery( http_type, request, &ok , sBody.toLocal8Bit() , false );

    mm = QtJson::parse1( answ.response );

    if ( ! mm.canConvert( QVariant::Map) )
    {
        QString err = QString("Ошибка в парисинге ответа честного знака !");
        ////kkt->emit_sig_log( err , qp::gui::LOG_STYLE_ERROR);

        QMessageBox::warning( 0 ,
                   "Проверка кода маркировки в честном знаке",
                   err );
        goto err;

    }

    if ( ! respLst.fillFromJson( mm ) )
    {
        emit sig_log( QtJson::serialize1( mm ), qp::gui::LOG_STYLE_ERROR );
        goto err;
    }

    emit sig_log( QtJson::serialize1( mm ), qp::gui::LOG_STYLE_RECEIVE );

    emit sig_finished( "завершено успешно", false );
    return respLst;

err:
    emit sig_finished( "завершение с ошибкой", true);
    return respLst;
}

QString ChZn_Validate::fullInfo( int level ) const
{
    return QString();
}

QVariant ChZn_Validate::slot_get_lm_init( const  QVariantMap &params , const QVariantMap &body)
{
    QString str = get_lm_init( params, body);

    return str;
}


bool ChZn_Validate::get_lm_init( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    /*
    • Продуктивный контур – https://rsapi.crpt.ru
    • Тестовый контур – https://suz-rsapi.sandbox.crptech.ru

        Метод инициализации ЛМ ЧЗ
        Метод предназначен для инициализации (обязательное условие для начала работы) ЛМ ЧЗ после
        установки.
        Хост ЛМ ЧЗ: http://127.0.0.1:5995
        Метод: POST
        URL: /api/v1/init
        Пример строки запроса:
        curl -X POST "<url хоста>/api/v1/init"
        -H "Content-Type: application/json"
        -H "Authorization: Basic YWRtaW46YWRtaW4="
        -H "X-ClientId: номер фискального накопителя"
        -d {"token": "X-API-KEY (Аутентификационный токен участника оборота)"}
    */

    QNetworkRequest request;
    QUrl urlLk;

    bool ok;
    QString  body;

    NtwQueryAnsw answ;


    HTTP_TYPE http_type;


    if ( ! common_prepare_lm_url_and_request( params, bodyObj , request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("инициализации ЛМ ЧЗ") , qp::gui::LOG_STYLE_SEND2 );

    body = QtJson::serialize1( bodyObj , &ok , QtJson::JSON_DEFAULT );

    answ = ntwQuery( http_type, request, &ok ,  body.toLocal8Bit() );
    if( ! ok )
        goto err;



    emit sig_finished("успешно" , false );
    return true;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return false;
}
QVariant ChZn_Validate::slot_get_lm_status( const  QVariantMap &params , const QVariantMap &body)
{
    QString str = get_lm_status( params, body);

    return str;
}


bool ChZn_Validate::get_lm_status( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    /*
        2.5.2 Метод проверки статуса ЛМ ЧЗ
        Метод предназначен для проверки статуса ЛМ ЧЗ (для готовности использования status должен
        быть ready)
        Хост ЛМ ЧЗ: http://127.0.0.1:5995
        Метод: GET
        URL: /api/v1/status
        Пример строки запроса:
        curl -X GET "<url хоста>/api/v1/status"
        -H "Content-Type: application/json"
        -H "Authorization: Basic YWRtaW46YWRtaW4="
        -H "X-ClientId: номер фискального накопителя"
    */

    QNetworkRequest request;
    QUrl urlLk;

    bool ok;

    NtwQueryAnsw answ;
    QVariantMap mm;


    HTTP_TYPE http_type; ;


    if ( ! common_prepare_lm_url_and_request( params, QVariant() , request, urlLk , http_type) )
        goto err;

    request.setUrl(urlLk);

    qDebug() << request.url();

    emit sig_log( QString("проверка статуса ЛМ ЧЗ") , qp::gui::LOG_STYLE_SEND2 );


    answ = ntwQuery( http_type, request, &ok );
    if( ! ok )
        goto err;


    emit sig_log( prettyJson( answ.response ) , qp::gui::LOG_STYLE_RECEIVE2);

    /*
    • при отсутствии синхронизации ЛМ ЧЗ с серверной частью в течение 72 часов
    переходит в статус sync_error, после чего проверять продукцию будет невозможно
    • 72 часа считаются с даты и времени, указанных в атрибуте lastSync
    • необходимо учитывать, что атрибутивный состав ответа может расширяться
*/
    emit sig_finished("успешно" , false );
    return true;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return false;
}


QVariant ChZn_Validate::slot_get_lm_cis_check( const  QVariantMap &params , const QVariantMap &body)
{
    LmResponseLst lmResp = get_lm_cis_check( params, body);

    return QVariant::fromValue( lmResp ) ;
}


LmResponseLst ChZn_Validate::get_lm_cis_check( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    /*
            2.5.3 Методы проверки КИ в ЛМ ЧЗ
            Примечание: при попытке проверить КИ в статусе ЛМ ЧЗ, отличающимся от статуса «ready» —
            вернётся ошибка с http-кодом 400, в теле ответа в зависимости от статуса может быть:
            • "errorCode": 4045 (для статусов «not_configured» или «initialization»)
            • "errorCode": 4050 (статус «sync_error», в который ЛМ ЧЗ переходит через 72 часа без
            синхронизации с серверной частью)
            2.5.3.1 GET-метод проверки КИ в ЛМ ЧЗ (устаревший)
            Метод предназначен для проверки кода идентификации по «чёрным спискам»
            Хост ЛМ ЧЗ: http://127.0.0.1:5995
            Метод: GET
            URL: /api/v1/cis/check?cis={cis}42
            ООО «Оператор-ЦРПТ»
            123022, г. Москва, ул. Рочдельская д.15 стр.16А
            support@crpt.ru, www.crpt.ru
            т. 8 (499) 350-85-59
            Пример строки запроса:
            curl -X GET "<url хоста>/api/v1/cis/check?cis=01048657365749062155esJWe"
            -H "Content-Type: application/json"
            -H "Authorization: Basic YWRtaW46YWRtaW4="
            -H "X-ClientId: номер фискального накопителя"
    */

    QNetworkRequest request;
    QUrl urlLk;

    LmResponseLst responseLst;
    bool ok;
    QString body;
    NtwQueryAnsw answ;
    QVariant var;


    HTTP_TYPE http_type; ;


    if ( ! common_prepare_lm_url_and_request( params, bodyObj , request, urlLk , http_type) )
        goto err;


    emit sig_log( QString("проверка КИ в ЛМ ЧЗ") , qp::gui::LOG_STYLE_SEND2 );


    if( bodyObj.count() == 0  )
    {
        if( ! params.contains("cis") )
        {
            emit sig_log( QString("параметр cis не передан") , qp::gui::LOG_STYLE_SEND2 );
            goto err;
        }

        urlLk.addQueryItem( "cis", params.value("cis").toString());
        request.setUrl(urlLk);

        answ = ntwQuery( http_type, request, &ok  );
    }
    else
    {
        // тут может быть устаревший post запрос
        request.setUrl(urlLk);
        body = QtJson::serialize1( bodyObj );

        answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    }

    var = QtJson::parse1( answ.response , ok );

    if( ! ok )
        goto err;

    qDebug() << answ.response;

    if ( ! responseLst.fillFromJson( var ) )
        goto err;

    emit sig_log( prettyJson( answ.response ) , qp::gui::LOG_STYLE_RECEIVE2);



    /*
    • при отсутствии синхронизации ЛМ ЧЗ с серверной частью в течение 72 часов
    переходит в статус sync_error, после чего проверять продукцию будет невозможно
    • 72 часа считаются с даты и времени, указанных в атрибуте lastSync
    • необходимо учитывать, что атрибутивный состав ответа может расширяться
*/
    emit sig_finished("успешно" , false );
    return responseLst;

err:
    emit sig_finished( "завершено с ошибкой: "+ret_err(answ) , true );

    return responseLst;
}

QVariant ChZn_Validate::slot_get_lm_cis_outCheck( const  QVariantMap &params , const QVariantMap &body)
{
    bool str = get_lm_cis_outCheck( params, body);

    return str;
}


bool ChZn_Validate::get_lm_cis_outCheck( const  QVariantMap &params , const QVariantMap &bodyObj)
{
    /*
            2.5.3.4 POST-метод проверки КИ в ЛМ ЧЗ (целевой)
            Хост ЛМ ЧЗ: http://127.0.0.1:599551
            ООО «Оператор-ЦРПТ»
            123022, г. Москва, ул. Рочдельская д.15 стр.16А
            support@crpt.ru, www.crpt.ru
            т. 8 (499) 350-85-59
            Метод: POST | GET
            URL: /api/v1/cis/outCheck
            Пример строки запроса:
            curl -X POST "<url хоста>/api/v1/cis/outCheck
            -H "Content-Type: application/json"
            -H "Authorization: Basic YWRtaW46YWRtaW4="
            -H "X-ClientId: номер фискального накопителя"
            -d "{"cis_list":["string"]}"
    */

    QNetworkRequest request;
    QUrl urlLk;

    bool ok;
    QString  body;
    NtwQueryAnsw answ;


    HTTP_TYPE http_type; ;


    if ( ! common_prepare_lm_url_and_request( params, bodyObj , request, urlLk , http_type) )
        goto err;


    emit sig_log( QString("проверка КИ в ЛМ ЧЗ (целевой)") , qp::gui::LOG_STYLE_SEND2 );


    if( bodyObj.count() == 0  )
    {
        if( ! params.contains("cis") )
        {
            emit sig_log( QString("параметр cis не передан") , qp::gui::LOG_STYLE_SEND2 );
            goto err;
        }

        urlLk.addQueryItem( "cis", params.value("cis").toString());
        request.setUrl(urlLk);

        answ = ntwQuery( http_type, request, &ok  );
    }
    else
    {
        // тут может быть устаревший post запрос
        request.setUrl(urlLk);
        body = QtJson::serialize1( bodyObj );
        answ = ntwQuery( http_type, request, &ok , body.toLocal8Bit() );
    }

    if( ! ok )
        goto err;


    emit sig_log( prettyJson( ret_err(answ) ) , qp::gui::LOG_STYLE_RECEIVE2);

    /*
    • при отсутствии синхронизации ЛМ ЧЗ с серверной частью в течение 72 часов
    переходит в статус sync_error, после чего проверять продукцию будет невозможно
    • 72 часа считаются с даты и времени, указанных в атрибуте lastSync
    • необходимо учитывать, что атрибутивный состав ответа может расширяться
*/
    emit sig_finished("успешно" , false );
    return true;

err:
    emit sig_finished( "завершено с ошибкой: "+ ret_err(answ) , true );

    return false;
}

QString ChZn_Validate::prettyJson( const QString & in ) const
{
    bool ok;
    QVariant var = QtJson::parse1( in , ok );

    if( ! ok || ! var.canConvert( QVariant::Map ))
    {
        QString ("не удалось конвертировать строку в красивый вариант с отсупами и переносами %1")
                .arg( in);
    }

    QString prettyResponse = QtJson::serialize1( var.toMap() );

    return prettyResponse;

}
