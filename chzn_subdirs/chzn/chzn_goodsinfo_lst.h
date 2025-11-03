#ifndef CHZN_GOODSINFOLST_H
#define CHZN_GOODSINFOLST_H

#include <QMetaType>
#include <QList>

#include "qp/core/dbg/abstract_dbg.h"
#include"chzn_goods_info.h"

//class ChZnGoodsInfo;

#include "../dll_chzn_global.h"

class LIB_PREFIX_CHZN ChZnGoodsInfoLst : public ADbg
{
public:
    ChZnGoodsInfoLst();

    int networkError;

    QList<ChZnGoodsInfo> goodsLst;

    static ChZnGoodsInfoLst from_Variant( const QVariant &var );

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const ;
};

Q_DECLARE_METATYPE(ChZnGoodsInfoLst);

#endif // CHZN_GOODSINFOLST_H
