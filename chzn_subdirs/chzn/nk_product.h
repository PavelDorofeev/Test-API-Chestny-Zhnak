#ifndef NK_PRODUCT_H
#define NK_PRODUCT_H

#include <QMetaType>
#include <QList>

#include "qp/core/dbg/abstract_dbg.h"


#include "../dll_chzn_global.h"

class LIB_PREFIX_CHZN Nk_Product : public ADbg
{
public:
    Nk_Product();

    QString brand_name;
    QString good_name;
    QString good_status;

    int good_id;
    int brand_id;

    bool isValid() const;

    static Nk_Product from_Variant( const QVariant &var );

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;
};

Q_DECLARE_METATYPE(Nk_Product);

#endif // NK_PRODUCT_H
