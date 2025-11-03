#include "onlineres.h"

MarkingRes::MarkingRes():
    ADbg(),
    mrkCodeType_2100(-1)
{

}

QString MarkingRes::markingCodeTypeToStr( int mrkCodeType ) const
{
    switch ( mrkCodeType )
    {
    case  0 :
        return "0 Тип кода маркировки не идентифицирован (код маркировки отсутствует, не может быть прочитан или может быть прочитан, но не может быть распознан)";
    case  1 :
        return "1 Короткий код маркировки 3";
    case  2 :
        return "2 Код маркировки со значением кода проверки длиной 88 символов, подлежащим проверке в ФН";
    case  3 :
        return "3 Код маркировки со значением кода проверки длиной 44 символа, не подлежащим проверке в ФН";
    case  4 :
        return "4 Код маркировки со значением кода проверки длиной 44 символа, подлежащим проверке в ФН";
    case  5 :
        return "5 Код маркировки со значением кода проверки длиной 4 символа, не подлежащим проверке в ФН";
    default:
        return "тип кода маркировки не идентифицирован";
    }
}

QString MarkingRes::fullInfo( int level ) const
{
    QString str;
    str.reserve(700);

    str.append( offline.fullInfo() );

    str.append("\n "+ markingCodeTypeToStr( mrkCodeType_2100));

    str.append( onlineOfd.fullInfo() );

    //str.append( onlineChzn.fullInfo() );

    return str;
}

MarkingRes MarkingRes::from_Variant( const QVariant &var )
{
    MarkingRes onlRes;

    if( ! var.isValid())
        return onlRes;

    onlRes = qvariant_cast<MarkingRes>( var );

    return onlRes;
}

