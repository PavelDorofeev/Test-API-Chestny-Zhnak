#include "abstract_dbg.h"

ADbg::ADbg():lvl(1)
{
}

//QString ADbg::fullInfo( int level ) const
//{
//    return "\n";
//}

QString ADbg::getLeftMargin( int level )
{
    QString str;
    if(level >0)
        return str.fill( QLatin1Char('\t' ) , level );
    return str;
}

QDebug operator<<(QDebug d, const ADbg& st)
{
    d << st.fullInfo();

    return d;
}


