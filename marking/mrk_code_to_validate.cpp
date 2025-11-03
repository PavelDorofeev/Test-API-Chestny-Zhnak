#include "mrk_code_to_validate.h"

MRK_CODE_TO_VALIDATE::MRK_CODE_TO_VALIDATE( MRK_CODE_TO_VALIDATE_SOURCE src,
                                            const QByteArray & FullCode,
                                            const QString &ProductName,
                                            int rest2106 ):
    source (src),
    fullCode(FullCode),
    productName(ProductName),
    res_t2106(rest2106),
    allowInvalidMrkCodesWithCashier( false ),
    testKontur(false)
{

}


QString MRK_CODE_TO_VALIDATE::fullInfo( int level ) const
{
    QString str;
    str.reserve( 1000 );

    str.append("\n\n----- MRK_CODE_TO_VALIDATE ------");
    str.append( QString("\n\t source : %1").arg( source));
    str.append( QString("\n\t productName  : %1").arg( productName));
    str.append( QString("\n\t fullCode : %1").arg( QString(fullCode)));
    str.append( QString("\n\t res_t2106 : %1").arg( res_t2106));
    str.append( QString("\n\t allowInvalidMrkCodesWithCashier : %1").arg( allowInvalidMrkCodesWithCashier));

    return str;

}


void MRK_CODE_TO_VALIDATE::set_allowInvalidMrkCodesWithCashier( bool on)
{
    allowInvalidMrkCodesWithCashier = on;
}
