#ifndef LM_RESPONSECODE_H
#define LM_RESPONSECODE_H

#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"

#include "../dll_chzn_global.h"
class LIB_PREFIX_CHZN LmResponseCode : public ADbg
{
public:
    LmResponseCode();
/*

        {
            "cis":"0104603586014674215012516137746",
            "gtin":"04603586014674",
            "isBlocked":false,
            "isGreyGtin":false,
            "printView":"0104603586014674215012516137746"
        }
    ],

*/
    QString cis;                // КИ / КиЗ из запроса
    QString gtin;               // Код товара
    int isBlocked;  // Признак заблокированного КМ
    int isGreyGtin;

    QString printView;

    static QString canToSell( const LmResponseCode& rc );

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;
};

#endif // LM_RESPONSECODE_H
