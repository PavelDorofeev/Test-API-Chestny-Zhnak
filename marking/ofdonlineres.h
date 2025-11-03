#ifndef OFDONLINERES_H
#define OFDONLINERES_H

#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"

#include "dll_marking_global.h"

class LIB_PREFIX_MARKING  OnlineOfdRes : public ADbg
{
public:

    typedef enum ONLINE_M_VALIDATION {
        VALIDATION_M_UNDEFINED=-1,
        VALIDATION_M_ONLY=1,
        VALIDATION_M_MINUS,
        VALIDATION_M_PLUS,
        VALIDATION_ERROR,
        VALIDATION_NOT_COMPLETED,
        VALIDATION_SERVER_WRONG
    }ONLINE_M_VALIDATION;

    ONLINE_M_VALIDATION vld_2106;

    int bit_msk_result_2106;

    OnlineOfdRes();

    QString ofd_error_str;

    int readyAccept1;
    int accepted1;
    int declined1;

    QString fullInfo( int level = 0 ) const;

    static OnlineOfdRes from_Variant(QVariant var);

    QString bit_msk_result_2106_toStr( ) const;

    static OnlineOfdRes::ONLINE_M_VALIDATION get_M_2106( int tag_2106_result);

};

Q_DECLARE_METATYPE (OnlineOfdRes);

#endif // OFDONLINERES_H
