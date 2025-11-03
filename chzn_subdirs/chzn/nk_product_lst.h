#ifndef NK_PRODUCT_LST_H
#define NK_PRODUCT_LST_H


#include <QMetaType>
#include <QList>

#include "qp/core/dbg/abstract_dbg.h"
#include "nk_product.h"

class Nk_Product;

#include "../dll_chzn_global.h"

class LIB_PREFIX_CHZN Nk_Product_Lst : public ADbg
{
public:
    Nk_Product_Lst();

    QList<Nk_Product> productLst;

    static Nk_Product_Lst from_Variant( const QVariant &var );

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;
};

Q_DECLARE_METATYPE(Nk_Product_Lst);

#endif // NK_PRODUCT_LST_H
