#include "datamatrix_text_edit.h"
#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>

#include "qp/core/dbg/dbg_core.h"


DatamatrixTextEdit::DatamatrixTextEdit(QWidget *parent) :
    QPlainTextEdit(parent),
    readden(0),
    //ShiftModifier(false),
    is_GS_present( 0 ),
    autoDetection( false ),
    replacedCnt(0)
{
    barcode.reserve(257);
    barcode.clear();

    //tmr.start();

}

//void  DatamatrixTextEdit::set_GS_isAllow( bool GSisAllow)
//{
//    GS_isAllow = GSisAllow;
//}

void  DatamatrixTextEdit::set_log_isAllow( bool logisAllow)
{
    log_isAllowed = logisAllow;

    log.clear();

    log.reserve( 1000 );
}

void DatamatrixTextEdit::addLog(  QKeyEvent *evt , int nativeScanCode_XT , unsigned char ucha , const QString & txt)
{
    log.append( QString("\n %1 : ").arg( tmr.elapsed() , 4 ,10 , QLatin1Char('0')));
    //log.append( QString(" key x%1").arg( evt->key(), 8 , 16 , QLatin1Char('0') ) );
    log.append( QString("  XT 0x%1").arg( nativeScanCode_XT, 2 , 16 , QLatin1Char('0')));

    if( nativeScanCode_XT == 0x35 )
        qDebug() << "0000000" <<ucha;

    log.append( QString("   decode 0x%1").arg( ucha, 2 , 16 , QLatin1Char('0')));

    if( txt.length() == 1 )
        log.append( QString("   char '%1' ").arg( txt ));
    else
        log.append( QString("   '%1' ").arg( txt ));

    if( evt->modifiers() & Qt::ShiftModifier)
        log.append(" with Shift");


}

bool DatamatrixTextEdit::testReplace( QKeyEvent *evt,  const quint32 &nativeScanCode_XT, const uchar &ucha, bool modif)
{
    // ---------------------------------------------------------------
    // тут можно задать замену нужных нам символов на GS
    // ---------------------------------------------------------------

    //qDebug() << lstSumbolsSetToConvertToGS;

    if( replacedCnt < lstSumbolsSetToConvertToGS.size()
            && lstSumbolsSetToConvertToGS.at( replacedCnt ) == nativeScanCode_XT )
    {
        // ---------------------------------------------------------------
        // продолжаем считывание сканкодов , накапливаем
        // ---------------------------------------------------------------

        //if( ! modif )
        arr[ replacedCnt ] = ucha; // это тестовое представление сохраняем
        // ucha это не текстовое представление

        replacedCnt++;

        if( replacedCnt == lstSumbolsSetToConvertToGS.size() ) //считали все подряд
        {
            QString str;
            for( int ii=0; ii < replacedCnt; ii++)
            {
                str.append( QString("0x%1 ").arg( lstSumbolsSetToConvertToGS.at(ii), 2 , 16 , QLatin1Char('0')) );
            }

            log.append(QString("\n redefine %1 to GS (0x1d)")
                       .arg( str)
                       );

            is_GS_present++;
            emit sig_symbol_readden( 0x1d ); // передаем всех

            replacedCnt = 0;
        }


        evt->accept();
        readden++;
        return true;
    }
    else if ( replacedCnt > 0) // накапливали, но не подошло
    {
        for( int ii=0; ii < replacedCnt; ii++)
        {
            uchar cr = arr[ ii ];

            if( cr != 0 ) // посылаем только изображаемые символы
                emit sig_symbol_readden( cr ); // передаем всех
        }
        replacedCnt = 0;

    }

    // --------------------------------------------------------------------------------

    return false;
}

void DatamatrixTextEdit::keyPressEvent(QKeyEvent *evt)
{
    //-------------------------------------------------
    //      здесь на входе просто байты
    //-------------------------------------------------

    //ShiftModifier = false;


    int nn = tmr.elapsed();
    //log.append( "\n elapsed "+QString::number( nn ) + " "+ tmr.toString("hh:mm:ss zzz : ") );

    if( nn == 0 || nn >  10000 ) // 10c
    {
        if( log_isAllowed )
        {
            log.append( QString("\n\n------ pause more %1 seconds (new scanning) -------\n")
                        .arg( nn / 1000 ) );
        }

        is_GS_present = 0;

        replacedCnt = 0;

        tmr.restart();
        readden=0;
        //ShiftModifier = false;
        rawReaddenLst.clear();
    }


    if(evt->type() == QEvent::KeyPress)
    {

        // ---------------------------------------------------------------------
        // тут все очень не просто,  заглавные символы передаются двумя SHIFT и клавиша
        //
        // ---------------------------------------------------------------------

        Qt::KeyboardModifiers mdf = evt->modifiers();
        unsigned char ucha=0x00;

        quint32 nativeScanCode_XT = evt->nativeScanCode();

//        if( log_isAllowed )
//        {
//            log.append(QString("\nnativeScanCode_XT 0x%1 :")
//                       .arg( nativeScanCode_XT, 0 , 16 )
//                       );
//        }
//        if( nativeScanCode_XT == 0x12 )
//            qDebug()<<"sdfsdafdsafdsfd";


        rawReaddenLst.append( nativeScanCode_XT );

        readden++;



        if(  nativeScanCode_XT == 0x3a )
        {
            // --------------------------------------------------------------------------------------
            // 'CapsLock' очень странно, но при включенном CAPLOCKS на обычной клавиатуре
            // в начале передачи и в конце передается CAPLOCKS
            // пропускаем его нафиг
            // --------------------------------------------------------------------------------------
            if( log_isAllowed )
            {
                log.append( "\n skip 0x3a (CAPLOCKS) " );
            }

            evt->accept();
            return;
        }

        if(  mdf  != 0  )
        {
            //            log.append(QString("\n KeyPress mdf x%1").arg( mdf, 8 , 16 , QLatin1Char('0')));
            //            log.append(QString("  xt 0x%1").arg( nativeScanCode_XT, 8 , 16 , QLatin1Char('0')));
            //            log.append(QString("  key 0x%1").arg( evt->key(), 8 , 16 , QLatin1Char('0')));

        }


        if( autoDetection )
        {
            if ( rawReaddenLst.count()> 14 && nativeScanCode_XT == 0x02 && rawReaddenLst.at( readden - 2 ) == 0x0a )
            {
                // КИ 31 символ
                if( readden > 31 && readden < 31 + 10 ) // 6 скан кодов это зебра передает
                {
                    // ---------------------------------------------------------------------------------
                    // предполагаем символы с 32 по найденную '91' сканерной интерпретацией символа GS
                    // ---------------------------------------------------------------------------------
                    QList<quint32> replaced;

                    if( readden - 31 - 2 > 0)
                    {
                        replaced.append( rawReaddenLst.mid(31 , readden - 31 - 2 ));

                        emit sig_auto_detect_replacement( replaced );

                        //lstSumbolsSetToConvertToGS = replaced;
                    }

                    qDebug() << "\n\nreadden 0x0a 0x02" << readden << readdentoStr( rawReaddenLst );
                }
            }

        }
        if(  mdf & Qt::ControlModifier  )
        {
            // ИМЕННО УПPАВЛЯЮЩИЕ СИМВОЛЫ И ЕСТЬ ControlModifier - Ни фига это ошибка

            if ( nativeScanCode_XT == 0x1D )//&& GS_isAllow )
            {
                // мы пропускаем только GS для маркировки

                if( log_isAllowed )
                {
                    log.append( "\n ------ GS received as Ctrl 0x1d ------- " );
                }
                emit sig_symbol_readden( 0x1d );
                is_GS_present++;
            }

            if ( testReplace ( evt , nativeScanCode_XT , ucha , true) )
                ;

            if( log_isAllowed)
                   addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "return with ControlModifier");

            evt->accept();
            return;
        }

        else if(  mdf & Qt::ShiftModifier  )
        {

            if( nativeScanCode_XT == 0x2A )
            {
                if( log_isAllowed)
                    addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "press Left Shift");
                // evt->accept();  НЕ НАДО , НЕЛЬЗЯ

                if ( testReplace ( evt , nativeScanCode_XT , ucha , true) )
                    ;

                if( log_isAllowed)
                       addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "return with ShiftModifier");

                return; // помечаем режим Shift включен, возвращаемся для примема следующих скан кодов

            }
            else if( nativeScanCode_XT == 0x36 )
            {
                if( log_isAllowed)
                    addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "press Right Shift");
                // evt->accept();  НЕ НАДО , НЕЛЬЗЯ

                if ( testReplace ( evt , nativeScanCode_XT , ucha , true) )
                    ;

                if( log_isAllowed)
                    addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "return with ShiftModifier");

                return; // помечаем режим Shift включен, возвращаемся для примема следующих скан кодов

            }

            // ----------------------------------------------------------------------
            // получается так, что следующие коды данных тоже идут с ShiftModifier
            // ----------------------------------------------------------------------
            //ShiftModifier = true;


        }
        else if(  mdf & Qt::AltModifier  )
        {
            if( nativeScanCode_XT == 0x38 )
            {
                if( log_isAllowed)
                    addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "press Alt");
                // evt->accept();  НЕ НАДО , НЕЛЬЗЯ

                if ( testReplace ( evt , nativeScanCode_XT , ucha , true) )
                    ;

            }

            if( log_isAllowed)
                addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "      return AltModifier presents");

            return; // помечаем режим Shift включен, возвращаемся для примема следующих скан кодов
        }

        if ( testReplace ( evt , nativeScanCode_XT , ucha ) )
        {
           if( log_isAllowed)
                  addLog( evt , nativeScanCode_XT , nativeScanCode_XT , "     return with testReplace");

            return;
        }

        // -------------------------------------------------------------
        // почему может падать приложение при приходе F12
        // Это в отладке вызов отладчика
        // -------------------------------------------------------------

        if(  nativeScanCode_XT == 0x1C) // Enter
        {
            if(  readden < 10) // допустим в начале сканер может cr+lf передавать)
            {
                if( log_isAllowed )
                {
                    log.append(QString("\n странно: Enter в начале данных ") );
                }

            }

            qDebug() <<"ENTER";

            if( log_isAllowed)
                addLog( evt , nativeScanCode_XT, nativeScanCode_XT , "ENTER");

            emit sig_enter_finished( );
            evt->accept();
            replacedCnt = 0;
            return;
        }

        // ------------------------------------------------
        if ( scanCodeInvisibleSymbol.contains( nativeScanCode_XT ))
        {
            if( log_isAllowed )
            {
                log.append(QString("\n -----  unexpected code 1 xt 0x%1  '%2'")
                           .arg( nativeScanCode_XT, 2 , 16 , QLatin1Char('0'))
                           .arg( scanCodeInvisibleSymbol.value( nativeScanCode_XT ) ));
            }

            if ( testReplace ( evt , nativeScanCode_XT , ucha , true) )
                return;

        }


        // -------------------------------------------------------------------------
        ucha = decodeWithShift( mdf , nativeScanCode_XT );
        // -------------------------------------------------------------------------
        if( ucha == 0)
        {
            // такого в выдаче сканера быть не должно

            emit sig_some_errors( QString("\nк сожалению скан код 0x%1 не опознан (Shift is %2)\n\n"\
                                          "если не сложно маякните об этом разработчику (значение сканкода 0x%1) на p@kkmspb.ru\n\n")
                                  .arg(nativeScanCode_XT , 2, 16, QLatin1Char('0'))
                                  .arg(mdf & Qt::ShiftModifier )
                                  );
            //            evt->accept();
            //            return;
        }


        //rawRiddenLst.append( ucha );

        if( log_isAllowed)
            addLog( evt , nativeScanCode_XT, ucha , evt->text() );



        //qDebug() << "sig_symbol_readden" << ucha ;
        emit sig_symbol_readden( ucha );

        /*
            В случае если длина считанной последовательности данных равна 29 символам и
            последовательность символов состоит из строчных и прописных латинских букв, цифр и
            символов ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstu
            vwxyz0123456789!"%&'()*+,-./_:;=<>? и не содержит идентификаторов применения (AI)
            сформированных по стандарту GS1.<>?


        /*
            See Qt::Key for the list of keyboard codes.
            These codes are independent of the underlying window system.
            Note that this function does not distinguish between capital and non-capital letters,
            use the text() function (returning the Unicode text the key generated) for this purpose.
            //QKeyCombination yнету в Qt4

            Во всех операционных системах фирмы Microsoft, скан коды из набора 2 (AT)
            преобразуются в скан-коды набора 1 (XT), и все приложения получают уже скан-коды набора
            nativeScanCode это будет XT
        */



    }


    evt->accept();
}

const QString DatamatrixTextEdit::readdentoStr( const QList<quint32> & lst ) const
{
    QString str;
    str.reserve(100);

    for( int ll=0; ll < rawReaddenLst.count() ; ll++)
        str.append(QString("%1 ").arg( rawReaddenLst.at( ll ), 2 , 16 , QLatin1Char('0')));

    return str;
}

uchar DatamatrixTextEdit::decodeWithShift( const Qt::KeyboardModifiers &mdf , const int &nativeScanCode_XT   )
{
    bool ShiftModifier = false;
    if(  mdf & Qt::ShiftModifier  )
        ShiftModifier = true;

    uchar ucha = 0; // такого в выдаче сканера быть не должно


    if ( ShiftModifier && scanCodeSymbolUpper.contains(nativeScanCode_XT ))
    {
        ucha  = scanCodeSymbolUpper [ nativeScanCode_XT ];

        if( log_isAllowed )
        {
            log.append(QString(" decodeWithShift 0x%1 %2   0x%3 %4 ")
                       .arg( scanCodeSymbolUpper [ nativeScanCode_XT ] ,2 , 16 , QLatin1Char('0'))
                       .arg( scanCodeSymbolUpper [ nativeScanCode_XT ])
                       .arg( ucha, 2 , 16 , QLatin1Char('0'))
                       .arg( ucha)
                       );
        }

    }
    else if ( ! ShiftModifier && scanCodeSymbolLower.contains(nativeScanCode_XT ))
    {
        ucha  = scanCodeSymbolLower [ nativeScanCode_XT ];

        if( log_isAllowed )
        {
//            qDebug()<< QString(" decodeWithShift 0x%1 %2   0x%3 %4 ")
//                       .arg( scanCodeSymbolUpper [ nativeScanCode_XT ] ,2 , 16 , QLatin1Char('0'))
//                       .arg( scanCodeSymbolUpper [ nativeScanCode_XT ])
//                       .arg( ucha, 2 , 16 , QLatin1Char('0'))
//                       .arg( ucha)
//                       ;
        }

    }
    else
    {
        // такого в выдаче сканера быть не должно

        if( log_isAllowed )
        {
            qDebug()<<QString("\n ------ unknown code (with ShiftModifier) xt 0x%1 --------").
                       arg( nativeScanCode_XT, 2 , 16 , QLatin1Char('0'))                       ;
        }
    }

    return ucha;

}

void DatamatrixTextEdit::redefine_GS( const QList<quint32> & ba )
{
    lstSumbolsSetToConvertToGS  = ba ;

    qDebug() << "redefine_GS";// << ba.toHex();
}

int DatamatrixTextEdit::contains_GS() const
{
    return is_GS_present;
}

void DatamatrixTextEdit::setAutoDetection( bool on)
{
    autoDetection = on;
}


//static const unsigned char slash = "/";

const QHash<quint32,uchar> DatamatrixTextEdit::scanCodeSymbolLower = QHashBuilder<quint32,uchar>()
//01h    Esc              31h    N
.add( 0x02, QLatin1Char('1').toLatin1())
.add( 0x03, QLatin1Char('2').toLatin1())
.add( 0x04, QLatin1Char('3').toLatin1())
.add( 0x05, QLatin1Char('4').toLatin1())
.add( 0x06, QLatin1Char('5').toLatin1())
.add( 0x07, QLatin1Char('6').toLatin1())
.add( 0x08, QLatin1Char('7').toLatin1())
.add( 0x09, QLatin1Char('8').toLatin1())
.add( 0x0A, QLatin1Char('9').toLatin1())
.add( 0x0B, QLatin1Char('0').toLatin1())
.add( 0x0C, QLatin1Char('-').toLatin1())
.add( 0x0D, QLatin1Char('=').toLatin1())

.add( 0x10, QLatin1Char('q').toLatin1())
.add( 0x11, QLatin1Char('w').toLatin1())
.add( 0x12, QLatin1Char('e').toLatin1())
.add( 0x13, QLatin1Char('r').toLatin1())
.add( 0x14, QLatin1Char('t').toLatin1())
.add( 0x15, QLatin1Char('y').toLatin1())
.add( 0x16, QLatin1Char('u').toLatin1())
.add( 0x17, QLatin1Char('i').toLatin1())
.add( 0x18, QLatin1Char('o').toLatin1())
.add( 0x19, QLatin1Char('p').toLatin1())

.add( 0x1A, QLatin1Char('[').toLatin1())
.add( 0x1B, QLatin1Char(']').toLatin1())

.add( 0x1E, QLatin1Char('a').toLatin1())
.add( 0x1F, QLatin1Char('s').toLatin1())
.add( 0x20, QLatin1Char('d').toLatin1())
.add( 0x21, QLatin1Char('f').toLatin1())
.add( 0x22, QLatin1Char('g').toLatin1())
.add( 0x23, QLatin1Char('h').toLatin1())
.add( 0x24, QLatin1Char('j').toLatin1())
.add( 0x25, QLatin1Char('k').toLatin1())
.add( 0x26, QLatin1Char('l').toLatin1())

.add( 0x27, QLatin1Char(';').toLatin1())
.add( 0x28, QLatin1Char('\'').toLatin1())
.add( 0x29, QLatin1Char('`').toLatin1())
.add( 0x2B, QLatin1Char('\\').toLatin1())


.add( 0x2C, QLatin1Char('z').toLatin1())
.add( 0x2D, QLatin1Char('x').toLatin1())
.add( 0x2E, QLatin1Char('c').toLatin1())
.add( 0x2F, QLatin1Char('v').toLatin1())
.add( 0x30, QLatin1Char('b').toLatin1())
.add( 0x31, QLatin1Char('n').toLatin1())
.add( 0x32, QLatin1Char('m').toLatin1())

.add( 0x33, QLatin1Char(',').toLatin1())
.add( 0x34, QLatin1Char('.').toLatin1())
.add( 0x35, QLatin1Char('/').toLatin1()) // по факту

.build();

const QHash<quint32,uchar> DatamatrixTextEdit::scanCodeSymbolUpper = QHashBuilder<quint32,uchar>()
//01h    Esc              31h    N
.add( 0x02, QLatin1Char('!').toLatin1())
.add( 0x03, QLatin1Char('@').toLatin1())
.add( 0x04, QLatin1Char('#').toLatin1())
.add( 0x05, QLatin1Char('$').toLatin1())
.add( 0x06, QLatin1Char('%').toLatin1())
.add( 0x07, QLatin1Char('^').toLatin1())
.add( 0x08, QLatin1Char('*').toLatin1())
.add( 0x09, QLatin1Char('(').toLatin1())
.add( 0x0A, QLatin1Char(')').toLatin1())
.add( 0x0B, QLatin1Char('0').toLatin1())
.add( 0x0C, QLatin1Char('-').toLatin1())
//.add( 0x0D, QLatin1Char('_').toLatin1()) // блиат долго искал ошибку
.add( 0x0D, QLatin1Char('+').toLatin1())

.add( 0x10, QLatin1Char('Q').toLatin1())
.add( 0x11, QLatin1Char('W').toLatin1())
.add( 0x12, QLatin1Char('E').toLatin1())
.add( 0x13, QLatin1Char('R').toLatin1())
.add( 0x14, QLatin1Char('T').toLatin1())
.add( 0x15, QLatin1Char('Y').toLatin1())
.add( 0x16, QLatin1Char('U').toLatin1())
.add( 0x17, QLatin1Char('I').toLatin1())
.add( 0x18, QLatin1Char('O').toLatin1())
.add( 0x19, QLatin1Char('P').toLatin1())


.add( 0x1A, QLatin1Char('{').toLatin1())
.add( 0x1B, QLatin1Char('}').toLatin1())

.add( 0x1E, QLatin1Char('A').toLatin1())
.add( 0x1F, QLatin1Char('S').toLatin1())
.add( 0x20, QLatin1Char('D').toLatin1())
.add( 0x21, QLatin1Char('F').toLatin1())
.add( 0x22, QLatin1Char('G').toLatin1())
.add( 0x23, QLatin1Char('H').toLatin1())
.add( 0x24, QLatin1Char('J').toLatin1())
.add( 0x25, QLatin1Char('K').toLatin1())
.add( 0x26, QLatin1Char('L').toLatin1())



.add( 0x27, QLatin1Char(':').toLatin1())
.add( 0x28, QLatin1Char('\"').toLatin1())
.add( 0x29, QLatin1Char('~').toLatin1())
.add( 0x2B, QLatin1Char('|').toLatin1())


.add( 0x2C, QLatin1Char('Z').toLatin1())
.add( 0x2D, QLatin1Char('X').toLatin1())
.add( 0x2E, QLatin1Char('C').toLatin1())
.add( 0x2F, QLatin1Char('V').toLatin1())
.add( 0x30, QLatin1Char('B').toLatin1())
.add( 0x31, QLatin1Char('N').toLatin1())
.add( 0x32, QLatin1Char('M').toLatin1())


.add( 0x33, QLatin1Char('<').toLatin1())
.add( 0x34, QLatin1Char('>').toLatin1())
.add( 0x35, QLatin1Char('/').toLatin1() ) // ?
.build();

const QHash<quint32,QString> DatamatrixTextEdit::scanCodeInvisibleSymbol = QHashBuilder<quint32,QString>()
.add( 0x00, QString::fromUtf8("kbd buffer full"))
.add( 0x01, QString::fromUtf8("Esc"))
.add( 0x0E, QString::fromUtf8("Backspace"))
.add( 0x0F, QString::fromUtf8("Tab"))

//??.add( 0x01, QString::fromUtf8("Enter"))
//??.add( 0x0E, QString::fromUtf8("Ctrl"))

.add( 0x36, QString::fromUtf8("Right Shift"))
.add( 0x37, QString::fromUtf8("Grey*")) // 37
.add( 0x38, QString::fromUtf8("Alt")) // 38
.add( 0x39, QString::fromUtf8("SpaceBar"))  // 39
.add( 0x3A, QString::fromUtf8("CapsLock"))
.add( 0x3B, QString::fromUtf8("F1"))
.add( 0x3C, QString::fromUtf8("F2"))
.add( 0x3D, QString::fromUtf8("F3"))
.add( 0x3E, QString::fromUtf8("F4"))
.add( 0x3F, QString::fromUtf8("F5"))
.add( 0x40, QString::fromUtf8("F6"))
.add( 0x41, QString::fromUtf8("F7"))
.add( 0x42, QString::fromUtf8("F8"))
.add( 0x43, QString::fromUtf8("F9"))
.add( 0x44, QString::fromUtf8("F10"))
.add( 0x145, QString::fromUtf8("NumLock"))
.add( 0x46, QString::fromUtf8("ScrollLock"))
.add( 0x147, QString::fromUtf8("Home"))
.add( 0x148, QString::fromUtf8("UpArrow"))
.add( 0x149, QString::fromUtf8("PgUp"))
.add( 0x4A, QString::fromUtf8("Grey-"))
.add( 0x14B, QString::fromUtf8("LeftArrow"))
.add( 0x4C, QString::fromUtf8("Keypad 5"))

.add( 0x14D, QString::fromUtf8("RightArrow"))
.add( 0x4E, QString::fromUtf8("Grey+"))
.add( 0x14F, QString::fromUtf8("End"))
.add( 0x150, QString::fromUtf8("DownArrow"))
.add( 0x151, QString::fromUtf8("PgDn"))
.add( 0x152, QString::fromUtf8("Ins"))  // 0x52
.add( 0x153, QString::fromUtf8("Del"))  // 0x53
.add( 0x54, QString::fromUtf8("SysReq"))
.add( 0x55, QString::fromUtf8("F11"))

.add( 0x56, QString::fromUtf8("F"))
.add( 0x57, QString::fromUtf8("F11"))
.add( 0x58, QString::fromUtf8("F12"))
.add( 0x59, QString::fromUtf8("F15"))
.add( 0x5A, QString::fromUtf8("PA1"))
.add( 0x5B, QString::fromUtf8("F13"))
.add( 0x5C, QString::fromUtf8("F14"))
.add( 0x5D, QString::fromUtf8("F15"))

.add( 0x63, QString::fromUtf8("F16"))
.add( 0x64, QString::fromUtf8("F17"))
.add( 0x65, QString::fromUtf8("F18"))
.add( 0x66, QString::fromUtf8("F19"))
.add( 0x67, QString::fromUtf8("F20"))
.add( 0x68, QString::fromUtf8("F21"))
.add( 0x69, QString::fromUtf8("F22"))
.add( 0x6A, QString::fromUtf8("F23"))
.add( 0x6B, QString::fromUtf8("F24"))
.add( 0x6C, QString::fromUtf8("--"))
.add( 0x6D, QString::fromUtf8("EraseEOF"))

.add( 0x6F, QString::fromUtf8("Copy/Play"))

.add( 0x72, QString::fromUtf8("CrSel"))
.add( 0x73, QString::fromUtf8("[*]"))
.add( 0x74, QString::fromUtf8("ExSel"))
.add( 0x75, QString::fromUtf8("--"))
.add( 0x76, QString::fromUtf8("Clear"))

.add( 0x77, QString::fromUtf8("[Note2] Joyst But1"))
.add( 0x78, QString::fromUtf8("[Note2] Joyst But2"))
.add( 0x79, QString::fromUtf8("[Note2] Joyst Right"))
.add( 0x7A, QString::fromUtf8("[Note2] Joyst Left"))
.add( 0x7B, QString::fromUtf8("[Note2] Joyst Up"))
.add( 0x7C, QString::fromUtf8("[Note2] Joyst Down"))
.add( 0x7D, QString::fromUtf8("[Note2] right mouse"))
.add( 0x7E, QString::fromUtf8("[Note2] left mouse"))

.add( 0xAA, QString::fromUtf8("self-test complete"))

.add( 0xE0, QString::fromUtf8("prefix code"))
.add( 0xE1, QString::fromUtf8("prefix code"))
.add( 0xEE, QString::fromUtf8("ECHO"))
//.add( 0xE0, QString::fromUtf8("prefix code (key break)"))
.add( 0xFA, QString::fromUtf8("ACK"))
.add( 0xFC, QString::fromUtf8("diag failure (MF-kbd)"))
.add( 0xFD, QString::fromUtf8("diag failure (AT-kbd)"))
.add( 0xFE, QString::fromUtf8("RESEND"))
.add( 0xFF, QString::fromUtf8("kbd error/buffer full"))





.build();

