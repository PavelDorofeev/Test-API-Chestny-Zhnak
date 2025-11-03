#include "localsocket.h"
#include <iostream>
#include <QByteArray>
#include <QTime>


//--------------------------------------------------
// проверка загрузки/инициализации кода
//--------------------------------------------------
int static_init_LocalSocket()
{
    qDebug("init LocalSocket");
    return 1;
}
static int someArray[] = {static_init_LocalSocket()} ;


LocalSocket * ptr = 0 ;

LocalSocket::LocalSocket(QObject *parent)
    :
      QLocalSocket(parent),
      connected(false)
{

}

LocalSocket * LocalSocket::get_ptr()
{
    return ptr;
}

void LocalSocket::slot_critical_log( const QString &str)
{
    std::cout << "wmi critical error" << str.toLocal8Bit().constData() << std::endl; // это пойдет на сервер starter ему в лог (через out)

    writeMsg ( str );
}

void LocalSocket::slot_starter_connected()
{
    if( ptr == 0 )
        ptr = this;

    connected = true;

    //??int cnt = writeMsg( QString::fromUtf8( "connecting to starter log server ok" ) );

    qDebug() << "QpApplication::slot_starter_connected()";// << cnt;

}

void LocalSocket::setServerConnected( bool conn)
{
    connected = conn;
}

QByteArray LocalSocket::encode( const QByteArray & baIn)
{
    return baIn.toHex(); // base64 на сервере стартера почему-то глючит ....

    // toHex вроде работает стабильно

}

qint64 LocalSocket::writeMsg( const QString & msg)
{

    //----------------------------------------------------
    // это нам на сервер пойдет
    // отдельно собираем информацию о процессе работы
    // для посылки в лог лк
    //----------------------------------------------------
    QString str = msg;


    QByteArray ba0 = str.toUtf8();

    //qDebug() << "\nLocalSocket::writeMsg baIn.toUtf8().toHex()().append('\n')" << str.toUtf8();


    if( get_ptr() == 0 ) // сервер не работает
    {
        return -1;
    }


    mutex.lock();

    if( ! connected )
    {
        mutex.unlock();
        return -1;
    }

    QByteArray ba = encode( ba0 );

    qint64 cnt = get_ptr()->write( ba );

    if( ! waitForBytesWritten( 10000 ))
        qDebug() << "write waitForBytesWritten TIMEOUT !!??? cnt"<<cnt;
    else
        qDebug() << "write waitForBytesWritten cnt:" << cnt << ba.length() << ba;

    if( cnt <= 0)
        qDebug() << "some error 345643";

    mutex.unlock();

    return cnt;

}
