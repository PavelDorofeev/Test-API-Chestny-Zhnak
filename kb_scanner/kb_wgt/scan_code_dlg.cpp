#include "scan_code_dlg.h"
#include "ui_scan_code_dlg.h"
#include <QDebug>
#include <QTextCodec>
#include <QUrl>
#include <QDesktopServices>


#include <QRegExp>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QDesktopServices>

#include "qp/gui/qp_gui.h"
#include "qp/core/meta/meta.h"
#include "kb_wgt/datamatrix_text_edit.h"
#include "kb_wgt/scannerlog.h"
#include "qp/core/logging_system/logging_system.h"
#include "qp/gui/qp_wgtstyle.h"


//--------------------------------------------------
// проверка загрузки/инициализации кода
//--------------------------------------------------
int static_init_scan_code_dlg()
{
    qDebug("init scan_code_dlg");
    return 1;
}
static int someArray[] = {static_init_scan_code_dlg()} ;

static const QString reestr_showBase64 = "showBase64";
static const QString reestr_clearAfterScanned = "clearAfterScanned";
static const QString reestr_closeWinAfterEnter = "closeWinAfterEnter";
static const QString reestr_log_isAllowed = "log_isAllowed";



Scan_Code_Dlg::Scan_Code_Dlg(  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scan_Code_Dlg),
    sett( QApplication::organizationName() , QApplication::applicationName()),
    new_GS_replacement(false),
    hasError(false)
{
    ui->setupUi(this);

    qDebug() << "\n\n ---------------- Scan_Code_Dlg ------------------\n\n";


    setAttribute(Qt::WA_TranslucentBackground);

    qp::gui::setWindow_woTitle__woFrame_woToolsBtn( this );

    setAutoFillBackground( false );
    //---------------------------------------------------------------------------

    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect( this );
    shadow1->setBlurRadius(10.0);
    shadow1->setColor(QColor(44, 44, 44, 160));
    shadow1->setOffset(5.0);
    ui->dialogTopFrame->setGraphicsEffect( shadow1 );

    ui->dialogTopFrame->setStyleSheet( QpWgtStyle::get_dark_frame_style() );

    //---------------------------------------------------------------------------



    qp::meta::cnct (ui->plte_datamatrix, SIGNAL(sig_enter_finished()),
                    this, SLOT(slot_enter_finished()));

    qp::meta::cnct (ui->plte_datamatrix, SIGNAL(sig_symbol_readden(uchar)),
                    this, SLOT(slot_symbol_readden(uchar)));

    qp::meta::cnct (ui->plte_datamatrix, SIGNAL(sig_auto_detect_replacement(QList<quint32>)),
                    this, SLOT(slot_auto_detect_replacement(QList<quint32>)));

    qp::meta::cnct (ui->plte_datamatrix, SIGNAL(sig_some_errors(QString)),
                    this, SLOT(slot_some_errors(QString)));

    qp::meta::cnct ( this, SIGNAL(sig_focusOnIn()),
                     this, SLOT(slot_focusOnIn()));

    qp::meta::cnct ( this, SIGNAL(sig_focusOnRedefineLedt()),
                     this, SLOT(slot_focusOnRedefineLedt()));



    saveCodec();

    setCodecForScanner();

    //on_chk_GS_isAllow_toggled( GS_isAllow );

    //ui->plte_datamatrix->set_GS_isAllow( GS_isAllow );

    //--------------------------------------------------------

    QRegExp RegExp("^(0x[0-9][0-9])(,0x[0-9][0-9])$");

    Validator = new QRegExpValidator(RegExp, this);


    // -------------------------------------------------------
    // здесь 0х42 из реестра восстанавливаем
    // -------------------------------------------------------


    if (sett.contains( "redefineGS") && ! sett.value( "redefineGS").toString().isEmpty())
    {
        QString und = sett.value( "redefineGS").toString();

        ui->ledt_redefineGS->setText( und );

        slot_ledt_redefineGS();
    }
    else
    {
        ui->ledt_redefineGS->clear();
        slot_ledt_redefineGS();
    }


    if (sett.contains( reestr_closeWinAfterEnter))
    {
        ui->chk_closeWin_afterEnter->setChecked(sett.value( reestr_closeWinAfterEnter).toBool());
        closeWinAfterEnter = ui->chk_closeWin_afterEnter->isChecked();
    }
    else
    {
        ui->chk_closeWin_afterEnter->setChecked( false  );
        closeWinAfterEnter = false;
    }

    if (sett.contains( reestr_log_isAllowed))
    {
        bool allowed = sett.value( reestr_log_isAllowed).toBool();
        ui->chk_enable_log->setChecked( allowed );
        ui->plte_datamatrix->set_log_isAllow( allowed );
    }
    else
    {
        ui->chk_enable_log->setChecked( false  );
        ui->plte_datamatrix->set_log_isAllow( false );
    }

    ui->fr_showBase64->setVisible( false );

    if (sett.contains( reestr_showBase64))
    {
        bool showBase64 = sett.value( reestr_showBase64).toBool();
        ui->chk_showBase64->setChecked( showBase64);
        ui->fr_showBase64->setVisible( showBase64 );
    }
    else
    {
        ui->chk_showBase64->setChecked( false  );
        ui->fr_showBase64->setVisible( false );
    }

    if (sett.contains( reestr_clearAfterScanned))
    {
        ui->chk_clearAfterScanned->setChecked( sett.value(reestr_clearAfterScanned).toBool() );
        clearAfterScanned = ui->chk_clearAfterScanned->isChecked();
    }
    else
    {
        ui->chk_clearAfterScanned->setChecked( false  );
        clearAfterScanned = false;
    }

    adjustSize();

}

void Scan_Code_Dlg::setCodecForScanner()
{
    /*

        Очень важно установить правильно локаль
        т.к. по умолчанию может полчится UTF-8 и это проблема с конвертированием в ASCII
        т.к. сканер передает по умолчанию в ASCII


    */

    QTextCodec * codec = QTextCodec::codecForName("Latin-1"); // это ISO-8859-1
    //QTextCodec * codec = QTextCodec::codecForName("ISO-8859-1"); // это ISO-8859-1
    //QTextCodec * codec = QTextCodec::codecForName("Windows-1252"); // это windows-1252 key(041a) русские
    //QTextCodec * codec = QTextCodec::codecForName("ASCII"); // это 0 НЕ работает
    //GBK");
    //QTextCodec * codec = QTextCodec::codecForName("CP866");
    if( codec == 0)
        Q_ASSERT( 1==34543543);

    QTextCodec::setCodecForLocale( codec );
    //    QTextCodec::setCodecForTr( codec );
    //    QTextCodec::setCodecForCStrings( codec );

    qDebug() << "QTextCodec::codecForLocale()"<<  QTextCodec::codecForLocale()->name();//<< locCdc->fromUnicode( str ) << locCdc->fromUnicode( str );
}

void Scan_Code_Dlg::restoreCodec( )
{
    QTextCodec::setCodecForLocale( savedCodecForLocale );
    //    QTextCodec::setCodecForTr( savedCodecForTr );
    //    QTextCodec::setCodecForCStrings( savedCodecForCStrings );
}

void Scan_Code_Dlg::saveCodec( )
{

    savedCodecForLocale =  QTextCodec::codecForLocale();
    //    savedCodecForTr =  QTextCodec::codecForTr();
    //    savedCodecForCStrings =  QTextCodec::codecForCStrings();

}

void Scan_Code_Dlg::setGS_isPresent( bool isPresent)
{
    GS_isPresent = isPresent;
}

Scan_Code_Dlg::~Scan_Code_Dlg()
{
    delete ui;
}

void Scan_Code_Dlg::slot_symbol_readden(const uchar ch)
{

    //qDebug() << ch ;

    QString str = QChar::fromLatin1( ch );

    if( str.isNull() || str.isEmpty())
        return;


    ui->plte_datamatrix->insertPlainText( str );

    //    if( ! ui->lbl_warning->text().isEmpty())
    //        ui->lbl_warning->clear();
}

void Scan_Code_Dlg::slot_enter_finished()
{
    qDebug() << "  " << ui->plte_datamatrix->toPlainText().toLocal8Bit();
    qDebug() << "  " << ui->plte_datamatrix->toPlainText().toLocal8Bit().toHex();

    ui->plte_base64->clear();

    markingCode = ui->plte_datamatrix->toPlainText().toLocal8Bit();

    if( new_GS_replacement )
    {
        slot_ledt_redefineGS();
        new_GS_replacement = false;
        ui->chk_auto_detection->setChecked( false );
    }

    //-------------------------------------------------------------------

//    int pos91 = markingCode.indexOf( QLatin1Char(0x1d) );

//    if( pos91 > 0)
//    {
//        markingCode.cis = markingCode.mid(0 , pos91 );

//        if( pos91 > 16 )
//            markingCode.gtin = markingCode.cis.mid( 2 , 14 );

//    }
//    else
//    {
//        ui->lbl_warning->setText( QString::fromUtf8("символы GS отсутствуют в штрих коде маркировки\n"\
//                                                    "такого быть не должно\n"\
//                                                    "скорее всего проверка онлайн не пройдет\n"\
//                                                    "посмотрите лог, что предается сканер"));
//    }

    //-------------------------------------------------------------------

    //-------------------------------------------------------------------

//    int len = markingCode.size();

//    if( len < 14)
//    {
//        ui->lbl_warning->setText( QString ( "unknown bar code lenght %1\n")
//                                  .arg( len )
//                                  );
//        update();
//        return;
//    }

    int gsCnt = ui->plte_datamatrix->contains_GS();

    if( hasError  )
    {
        ui->lbl_warning->setText(QString::fromUtf8("ошибка: не опознан скан код!"));
    }
    else if( gsCnt == 0 )
    {
        ui->lbl_warning->setText(QString::fromUtf8("ошибка: GS разделители отсутствуют!"));
    }
    else
    {
        ui->lbl_warning->setText(QString::fromUtf8("успешно"));
    }
    hasError = false;

    qDebug() << "barcode" << markingCode.toHex().toUpper();




    ui->plte_base64->setPlainText( markingCode.toBase64() );

    if( clearAfterScanned )
        ui->plte_datamatrix->clear();

    if( closeWinAfterEnter && ! hasError && gsCnt != 0)
        accept();
    else
        update();


}

void Scan_Code_Dlg::accept()
{
    restoreCodec();
    QDialog::accept();
}

void Scan_Code_Dlg::update()
{
    //    QPalette p = ui->ledt_redefineGS->palette();

    //    if ( ui->ledt_redefineGS->text().isEmpty())
    //    {
    ////        ui->ledt_redefineGS->setStyleSheet("#ledt_redefineGS { color: lightGray;"); // Set your color but remember that Qt will reduce alpha
    //        p.setColor(QPalette::Mid, Qt::red); // assuming Mid is the color you want to change.
    //    }
    //    else
    //    {
    //        p.setColor(QPalette::Mid, Qt::green); // assuming Mid is the color you want to change.
    ////        ui->ledt_redefineGS->setStyleSheet("#ledt_redefineGS { color: green;"); // usual color
    //    }

    //    ui->ledt_redefineGS->setPalette(p);

    QDialog::update();
}

void Scan_Code_Dlg::reject()
{
    restoreCodec();
    QDialog::reject();
}

QByteArray Scan_Code_Dlg::getScannedCode()
{
    return markingCode;
}


void Scan_Code_Dlg::on_btn_cancel_clicked()
{
    reject();
}

void Scan_Code_Dlg::on_btn_clear_clicked()
{
    //ui->lineEdit->setText( barcode);
    ui->plte_datamatrix->readden = 0;
    ui->plte_datamatrix->clear();
    ui->plte_datamatrix->log.clear();
    ui->lbl_warning->clear();
    ui->plte_base64->clear();

    emit sig_focusOnIn();

}

void Scan_Code_Dlg::on_btn_accept_clicked()
{
    qDebug() << "toPlainText" <<ui->plte_datamatrix->toPlainText();
    qDebug() << "toHex" <<ui->plte_datamatrix->toPlainText().toLocal8Bit().toHex().toUpper();


    restoreCodec();

    accept();
}


//void Scan_Code_Dlg::on_chk_GS_isAllow_toggled(bool checked)
//{
//    GS_isAllow = checked;

//    ui->plte_datamatrix->set_GS_isAllow( checked );

//    emit sig_focusOnIn();

//}
void Scan_Code_Dlg::slot_focusOnIn()
{
    ui->plte_datamatrix->setFocus();
}

void Scan_Code_Dlg::slot_focusOnRedefineLedt()
{
    ui->ledt_redefineGS->setFocus();
}

void Scan_Code_Dlg::on_btn_show_log_clicked()
{
    if( ! ui->chk_enable_log->isChecked())
    {
        emit sig_focusOnIn();
        return;
    }

    ScannerLog * ll = new ScannerLog ( this );

    QString it =  ui->plte_datamatrix->log +"\n\n bar code : "+ ui->plte_datamatrix->toPlainText();

    it.append( +"\n\n base64 : "+ ui->plte_datamatrix->toPlainText().toLocal8Bit().toBase64() );

    ll->setModal( false);

    qWarning()<<"barcode" << it;
    qWarning()<<"base64" << it;

    ll->fillContent( it );

    ll->showMaximized();

    ll->exec();

    ll->deleteLater();

    emit sig_focusOnIn();
}


void Scan_Code_Dlg::slot_ledt_redefineGS()
{

    sett.setValue("redefineGS" ,  ui->ledt_redefineGS->text());


    if ( ui->ledt_redefineGS->text().isEmpty()  )
    {
        ui->plte_datamatrix->redefine_GS( QList<quint32>() );
        return;
    }

    QString str = ui->ledt_redefineGS->text();

    QStringList lst = str.split(",");

    QList<quint32> outLst;
    bool res = true ;

    //QRegExp rx("((?:,*)0x([0-9][0-9]))");

    QRegExp rx("[0-9,a-f,A-F]{2,3}"); // может 0x150

    for( int ii=0; ii < lst.count(); ii++ )
    {
        QString itm  = lst.at(ii);

        if( itm.length() != 4 && itm.length() != 5) // может 0x150
        {
            res = false;
            break;
        }

        if( itm.mid(0 , 2 ) != "0x" )
        {
            res = false;
            break;
        }


        QString vv = itm.mid( 2  );

        int pos = rx.indexIn( vv );

        if( pos != 0 )
        {
            res = false;
            break;
        }

        bool ok;
        int iii =  vv.toInt( &ok , 16 ) ;
        if( !ok )
        {
            res = false;
            break;
        }

        outLst.append( (quint32) iii );

    }
    // 0x25,0x55
    qDebug() << "on_ledt_redefineGS_editingFinished"<< lst;

    if( ! res )
    {
        QMessageBox::warning( this , "Error",
                              QString("check your string '%1'\n\n%2 ")
                              .arg(str)
                              .arg("note inb latin kb, for example  0x25,0x55"));

        return;
    }

    ui->plte_datamatrix->redefine_GS( outLst );

    emit sig_focusOnIn();
}

void Scan_Code_Dlg::on_btn_save_redifinedGS_clicked()
{
    slot_ledt_redefineGS();

    emit sig_focusOnIn();
}

void Scan_Code_Dlg::on_chk_closeWin_afterEnter_toggled(bool checked)
{
    closeWinAfterEnter = checked;

    sett.setValue( reestr_closeWinAfterEnter , checked );

    emit sig_focusOnIn();
}

void Scan_Code_Dlg::on_chk_showBase64_clicked(bool checked)
{

    sett.setValue( reestr_showBase64 , checked );
    ui->fr_showBase64->setVisible( checked );

    updateGeometry();
    adjustSize();

    emit sig_focusOnIn();
}

void Scan_Code_Dlg::on_chk_clearAfterScanned_clicked(bool checked)
{
    clearAfterScanned = checked;

    sett.setValue( reestr_clearAfterScanned , checked );

    emit sig_focusOnIn();

}

void Scan_Code_Dlg::on_btn_show_app_log_clicked()
{
    if ( ! QDesktopServices::openUrl( QUrl::fromLocalFile(logging_System::getLogFile())))
        ;
}


void Scan_Code_Dlg::on_ledt_redefineGS_returnPressed()
{
    slot_ledt_redefineGS();

    emit sig_focusOnIn();
}

void Scan_Code_Dlg::on_chk_auto_detection_clicked(bool checked)
{
    ui->plte_datamatrix->setAutoDetection( checked );

    emit sig_focusOnIn();
}

QString Scan_Code_Dlg::format( const QList<quint32> &lst )
{
    QString str;
    str.reserve(100);

    for( int ii=0; ii<lst.count(); ii++)
    {
        if( ! str.isEmpty())
            str.append( ",");

        str.append(QString("0x%1").arg( lst.at(ii) ,2 ,16, QLatin1Char('0') ));

    }

    return str;

}

void Scan_Code_Dlg::slot_auto_detect_replacement(const QList<quint32> &lst)
{
    QString str = format( lst);
    qDebug() << "detect"<<str;
    ui->ledt_redefineGS->setText( str );
    sett.setValue("redefineGS" ,  ui->ledt_redefineGS->text());
    new_GS_replacement = true;
    emit sig_focusOnIn();

}

void Scan_Code_Dlg::slot_some_errors(const QString & errmess)
{
    qDebug() << "errmess"<<errmess;

    ui->plte_datamatrix->appendPlainText( errmess);
    hasError = true;
    emit sig_focusOnIn();

}

void Scan_Code_Dlg::on_chk_enable_log_clicked(bool checked)
{
    sett.setValue( reestr_log_isAllowed , checked );
    ui->plte_datamatrix->set_log_isAllow( checked );

}

