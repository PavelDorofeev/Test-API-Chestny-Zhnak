#ifndef MARKINGCODE_H
#define MARKINGCODE_H


#include <QMetaType>

#include "qp/core/dbg/abstract_dbg.h"

#include "dll_marking_global.h"

class LIB_PREFIX_MARKING  MarkingCode : public ADbg
{
public:

    MarkingCode( );


        QString fullCode;
        QString gtin;
        QString cis;

        QString fullInfo(  int level =0 ) const;

        static bool fillFormFullCode( const QString & Fullcode , MarkingCode &mrk);

};

Q_DECLARE_METATYPE(MarkingCode);

#endif // MARKINGCODE_H
