#include "offline_res.h"

OfflineRes::OfflineRes():
    mrkCodeOfflineChecked_2004_1b(-1),
    mrkCodeOfflineIsCorrect_2004_2b(-1),
    failedCause(-1)

{

}

QString OfflineRes::failedCause_toStr() const
{
    QString str;
    str.reserve( 100);


    switch(failedCause)
    {
    case 0:
        return "0 - КМ проверен в ФН";
    case 1:
        return "1 – КМ данного типа не подлежит проверки в ФН";
    case 2:
        return "2 – ФН не содержит ключ проверки кода проверки этого КМ";
    case 3:
        return "3 – Проверка невозможна, так как отсутствуют идентификаторы применения GS1 91 и / или 92 или их формат неверный";
    case 4:
        return "4 –Внутренняя ошибка в ФН при проверке этого КМ";
    default:
        return "Причина того, что КМ не проверен в ФН : не указана" ;

    }

}

QString OfflineRes::fullInfo( int level ) const
{
    QString str;
    str.reserve(1000);

    str.append(QString( "\n ------ OfflineRes -------- "));

    if( mrkCodeOfflineChecked_2004_1b == -1 )
    {
        str.append(QString( "\n\t %1").arg( "код маркировки не проверялся в ФН" ) );
        str.append( "\n\t "+failedCause_toStr());
        return str;
    }

    else if( mrkCodeOfflineChecked_2004_1b == 0 )
    {
        str.append(QString( "\n\t тег 2004 бит 0 : %1 (%2)").arg(mrkCodeOfflineChecked_2004_1b)
                   .arg( "код маркировки не может быть проверен фискальным накопителем" ) );
        str.append( "\n\t "+failedCause_toStr());
        return str;
    }

    str.append(QString( "\n\t тег 2004 бит 0 : %1 (%2)").arg(mrkCodeOfflineChecked_2004_1b)
               .arg( "код маркировки проверен фискальным накопителем с использованием ключа проверки КП" ) );

    if( mrkCodeOfflineIsCorrect_2004_2b == 0)
    {
        str.append(QString( "\n\t тег 2004 бит 1 : %1 (%2)").arg(mrkCodeOfflineChecked_2004_1b)
                   .arg( "отрицательный результат проверки КП КМ фискальным накопителем с использованием ключа проверки КП" ) );
        str.append( "\n\t "+failedCause_toStr());
        return str;
    }

    str.append(QString( "\n\t тег 2004 бит 1 : %1 (%2)").arg(mrkCodeOfflineChecked_2004_1b)
               .arg( "положительный результат проверки КП КМ фискальным накопителем с использованием ключа проверки КП" ) );
    str.append( "\n\t "+failedCause_toStr());

    return str;


}


OfflineRes OfflineRes::from_Variant(QVariant var)
{
    OfflineRes offRes;

    if( ! var.isValid())
        return offRes;

    offRes = qvariant_cast<OfflineRes>( var );

    return offRes;
}
