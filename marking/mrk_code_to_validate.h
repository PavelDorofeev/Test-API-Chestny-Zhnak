#ifndef MRK_CODE_TO_VALIDATE_H
#define MRK_CODE_TO_VALIDATE_H

#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"


#include "dll_marking_global.h"

class LIB_PREFIX_MARKING MRK_CODE_TO_VALIDATE : public ADbg
{
public:

    enum MRK_CODE_TO_VALIDATE_SOURCE{
        FOR_MAIN_THREAD,
        FOR_EXT_CMD
    };

    MRK_CODE_TO_VALIDATE():
        res_t2106(-1),
        testKontur(false)
    {}

    MRK_CODE_TO_VALIDATE( MRK_CODE_TO_VALIDATE_SOURCE src,
                          const QByteArray & FullCode,
                          const QString &ProductName=QString(),
                          int rest2106 = -1);

    MRK_CODE_TO_VALIDATE_SOURCE source;

    QByteArray fullCode;

    QString productName;

    bool allowInvalidMrkCodesWithCashier; // для М-

    void set_allowInvalidMrkCodesWithCashier( bool);

    int res_t2106;

    QString kkt_error;

    bool testKontur;

    QString fullInfo(  int level =0 ) const;



};

Q_DECLARE_METATYPE(MRK_CODE_TO_VALIDATE);

#endif // MRK_CODE_TO_VALIDATE_H
