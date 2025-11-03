#ifndef LOCALSOCKET_H
#define LOCALSOCKET_H

#include <QLocalSocket>
#include <QMutex>

#include "qp/ntw/dll_qp_ntw_global.h"

class LIB_PREFIX_QP_NTW LocalSocket : public QLocalSocket
{
    Q_OBJECT
public:
    explicit LocalSocket(QObject *parent = 0);
    
    //static LocalSocket * getPtr();
    qint64 writeMsg( const QString & msg);
    static LocalSocket * get_ptr();

    void setServerConnected( bool );

signals:
    
public slots:

    void slot_starter_connected();
    void slot_critical_log( const QString &str);

private:
    bool connected;
    QMutex mutex;
    QByteArray encode( const QByteArray & baIn);
};

#endif // LOCALSOCKET_H
