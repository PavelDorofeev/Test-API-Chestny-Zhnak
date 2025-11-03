#ifndef CHZN_GOODS_H
#define CHZN_GOODS_H

#include <QMetaType>
#include <QList>

#include "qp/core/dbg/abstract_dbg.h"

#include "dll_marking_global.h"

class LIB_PREFIX_MARKING  ChZn_Goods : public ADbg
{
public:
    ChZn_Goods();

    bool fillFromJson( const QVariant &var );

    QString fullInfo( int level =0 ) const;

    static ChZn_Goods from_Variant( const QVariant &var );
};

Q_DECLARE_METATYPE(ChZn_Goods);
Q_DECLARE_METATYPE(QList<ChZn_Goods>);

#endif // CHZN_GOODS_H
