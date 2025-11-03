#ifndef NTWQUERYASNW_H
#define NTWQUERYASNW_H

#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"

#include "../dll_chzn_global.h"

class LIB_PREFIX_CHZN NtwQueryAnsw : public ADbg
{
public:
    NtwQueryAnsw();

    explicit NtwQueryAnsw( const QString& Response, int NtwErrCode);

    QString response;
    int ntwErrCode;

    QString fullInfo( int level =0 ) const ;


};
//Q_DECLARE_METATYPE(NtwQueryAsnw);

#endif // NTWQUERYASNW_H
