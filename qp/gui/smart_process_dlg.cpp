#include "smart_process_dlg.h"
#include "ui_smart_process_dlg.h"

#include <QDebug>
#include <QScrollBar>
#include <QMetaMethod>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QDir>
#include <QUrl>
#include <QFileDialog>
#include <QDesktopServices>
#include <QApplication>
#include <QGraphicsDropShadowEffect>

#include "qp/core/meta/qpsingleshottimer.h"
#include "qp/gui/qp_gui.h"


QString Smart_Process_Dlg::reestr_tlv_files = QString::fromUtf8( "tlv_documents/lastDir" );


Smart_Process_Dlg::Smart_Process_Dlg( QWidget *parent,
                                      const QObject * SlotOwner,
                                      const QString &hdr,
                                      const QString &txt1,
                                      const QString &txt2,
                                      const QString &Slot_name ,
                                      const QList<const QObject*> &ObjLst,
                                      const QList<QVariant>& Pars,
                                      bool CloseWindowOnFinished,
                                      bool Silent
                                      )
    :
      QDialog( parent ),
      ui(new Ui::Smart_Process_Dlg),
      resInvokeMethod( false ),
      slot_name(Slot_name),
      pars( Pars),
      closeWindowOnFinished(CloseWindowOnFinished),
      silent(Silent),
      sett( QApplication::organizationName() , QApplication::applicationName() ),
      tmr(0)



{
    ui->setupUi(this);

    /*
         ВАЖНО : В КОНСТPУКТОPЕ PОДИТЕЛЕ (SizeRememberDlg) НЕ ВЫЗЫВАЮТСЯ ВИPТУАЛЬНЫЕ ФУНКЦИИ ПОТОМКА
         ПОЭТОМУ init() здесь
     */
    //        init();

    setObjectName( Slot_name );


    //--------------------------------------------------------------------------------

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect( this );
    shadow->setBlurRadius(45.0);
    shadow->setColor(QColor(0, 0, 0, 250));
    shadow->setOffset(0.0);
    ui->frame_dark_1->setGraphicsEffect( shadow );

    QString str1 = ".QFrame{\n"\
            "    background:  #cad4f1;\n"\
            "    border-radius:"+QString::number( QApplication::fontMetrics().height())+"px;\n"\
            "}\n";
    QString str2 = ".QFrame{\n"\
            "    background:  #cad4f1;\n"\
            "    border-radius:"+QString::number( QApplication::fontMetrics().height())+"px;\n"\
            "    border: 1px solid rgb(200,200,200,125);\n"\
            "}\n";

    ui->frame_dark_1->setStyleSheet( str1 );
    ui->frame_dark_2->setStyleSheet( str2 );


    setSizeGripEnabled( true );

    //--------------------------------------------------------------------------------
    slotOwner = SlotOwner;

    ui->lbl_header->setText(hdr);
    ui->lbl_text1->setText(txt1);

    ui->lbl_text2->appendHtml( QString( "<h1>"+txt2+"</h1>"));

    ui->btn_wait->setVisible( false );

    // -- подключаем sig_finished / sig_log
    foreach( const QObject* obj , ObjLst)
    {

        bool bbb = connect( obj , SIGNAL( sig_finished(QString,bool)), this , SLOT( slot_finished(QString,bool)));

        if( ! bbb )
            QMessageBox::critical( this ,
                                   "Error",
                                   QString("error: connecting signal(sig_finished ) / slot (slot_finished)")
                                   );

        bbb = connect( obj , SIGNAL( sig_log(QString , qp::gui::LOG_STYLE)),
                       this , SLOT( slot_log(QString , qp::gui::LOG_STYLE)));

        if( ! bbb )
        {
            QMessageBox::critical( this ,
                                   "Error",
                                   QString("error: connecting signal(sig_log) / slot (slot_log)")
                                   );
            qDebug()<< "657474658675857847";
        }
    }

    // -----------------------------------------------------------
    QApplication::setOverrideCursor(Qt::WaitCursor);


    tmr =  new QpSingleShotTimer( 200 ,
                                  slotOwner,
                                  slot_name,
                                  pars,
                                  parent ) ;

    if ( ! connect ( tmr , SIGNAL(sig_retResult(bool, QVariant)),
                     this , SLOT(slot_retResult(bool, QVariant))) )
    {
        QMessageBox::critical( this ,
                               "Error",
                               "connecting signal - slot is false");
        ;
    }

    // -----------------------------------------

    qp::gui::setWindow_woTitle__woFrame_woToolsBtn( this );


    setAttribute(Qt::WA_TranslucentBackground );

    // -----------------------------------------


    ui->lbl_header->setTextInteractionFlags(Qt::TextSelectableByMouse);

    ui->lbl_text1->setTextInteractionFlags(Qt::TextSelectableByMouse);

    ui->lbl_text2->setTextInteractionFlags(Qt::TextSelectableByMouse);


    QP_ASSERT ( connect ( ui->lbl_text1 , SIGNAL(linkActivated(QString) ),
                          this , SLOT(slot_linkActivated(QString))) == true);



    //---------------------- move window to center ------------------------------

    //    QSize sz = qp::gui::screen_size();
    //    int w_w = sz.width()/10;
    //    int h_h = sz.height()/10;
    //    int offsetW = ( sz.width() / w_w ) /2;
    //    int offsetH = ( sz.height() / h_h ) /2;
    //    //qDebug() << QDesktopWidget::geometry();

    //    setGeometry( offsetW, offsetH,  w_w , h_h);

    //    int screenH = QApplication::desktop()->screenGeometry().height();
    //    int screenH_07 = (int)screenH *0.7;

    //    int AppFntHeight = QApplication::fontMetrics().height();

    //    int hh = qMin( screenH_07 , AppFntHeight * 30 );

    //    int screenW_05 = (int)hh *0.5;

    //    int ww = qMin( screenW_05 , AppFntHeight * 30 );


    QRect rectDlg( 0, 0, width(), height() );		// Window rectangle

    QPoint screenCenter = QApplication::desktop()->screenGeometry().center();

    QPoint to = screenCenter - rectDlg.center() ;


    QP_ASSERT( connect( ui->scrollArea->verticalScrollBar(), SIGNAL( rangeChanged(int,int) ),
                        this, SLOT(slot_rangeChanged(int,int)) )== true);

    //QFont font = QApplication::font();

    //font.setFamily("Monospace");  выставляется стилями в <p>
    //font.setStyleHint(QFont::TypeWriter);

    adjustSize();
}

void Smart_Process_Dlg::slot_rangeChanged(int min ,int max)
{
    //qDebug()<< "slot_rangeChanged min" <<min<<" max"<<max;

    if( max >0 )
        ui->scrollArea->verticalScrollBar()->setValue( max );
}


void Smart_Process_Dlg::slot_retResult(bool ResInvokeMethod, const QVariant& RetValue)
{
    retVal = RetValue;
    resInvokeMethod = ResInvokeMethod;


    if( ! resInvokeMethod )
    {

        const QMetaObject* metaObject = slotOwner->metaObject();

        QStringList methods;

        bool foundMethodName = false;

        for(int i = metaObject->methodOffset(); i < metaObject->methodCount(); ++i)
        {
            if( QString::fromLatin1(metaObject->method(i).signature()) == slot_name)
                foundMethodName = true;
        }

        if( ! foundMethodName )
        {
            QApplication::setOverrideCursor( Qt::ArrowCursor );


            QMessageBox::warning( this ,
                                  "Error (Smart_Process_Dlg)",
                                  QString("result: Object has not a slot name '%1'.")
                                  .arg(slot_name )
                                  );

            return;
        }

        QString pp;

        foreach( QVariant var, pars )
        {
            if(! pp.isEmpty())
                pp.append(QLatin1String(","));

            pp.append( var.typeName());
        }

        QApplication::setOverrideCursor( Qt::ArrowCursor );

        QMessageBox::warning( this ,
                              "Ошибка",
                              QString("некорректные параметры передаются в слот  '%1(%2)' , также тип возвращаемого значения должен быть QVariant.")
                              .arg(slot_name )
                              .arg( pp )
                              );
    }
}

bool Smart_Process_Dlg::getInvokeMethodResult()const
{
    return resInvokeMethod;
}

QVariant Smart_Process_Dlg::getRetValue() const
{
    return retVal;
}

Smart_Process_Dlg::~Smart_Process_Dlg()
{
    qDebug() << "~Smart_Process_Dlg() objectName" << objectName();//

    delete ui;
}



void Smart_Process_Dlg::slot_finished( QString description ,
                                       bool error )
{

    //qWarning() <<"Smart_Process_Dlg::slot_finished"<<description << error;

    // -------------------------------------------------------
    //  finished process execute
    // -------------------------------------------------------

    if( ! description.isEmpty() ) // message
    {
        QString description2 = description;
        description2 = description2.replace(QLatin1String("\n"), QLatin1String("<br>"));

        description2 = description2.replace(" ", "&nbsp;");

        QString style;//= qp::gui::LOG_STYLE_ERROR
        if( error )
            style = " "+qp::gui::styleToHtmlAttr ( qp::gui::LOG_STYLE_ERROR);
        else
            style = " "+qp::gui::styleToHtmlAttr ( qp::gui::LOG_STYLE_PLAINTEXT);

        int hh = QApplication::fontMetrics().height()*1.2;
        style.append( QString("; font-size:%1px;").arg(hh) );


        ui->lbl_text2->appendHtml( "<p style=\"" + style + "\">"+description2+"</p>" );


        repaint();

    }

    // -----------------------------------------------------------------

    QApplication::setOverrideCursor( Qt::ArrowCursor );  // !!!!!!!!!!!!!!!!!!! а почему бы нет

    // -----------------------------------------------------------------


    if( silent ) // по любому выходим всегда, не смотря на ошибки ни на что
    {
        accept();
    }

    // --------------------------------------

    if( error ) // сигнал об ошибке
    {
        if ( closeWindowOnFinished )
            accept();

    }
    else if ( ! error )
    {
        if ( closeWindowOnFinished )
            accept();
    }

    // окно остается видимым на экране



}

void Smart_Process_Dlg::slot_log( const QString &str , qp::gui::LOG_STYLE style )
{

    //     qDebug() << "   Smart_Process_Dlg::slot_log repaint"<<str;


    if( ! str.isEmpty() ) // message or error
    {
        QString description2 = str;

        description2 = description2.replace(QLatin1String("&"), QLatin1String("&amp;"));
        description2 = description2.replace(QLatin1String("<"), QLatin1String("&lt;"));
        description2 = description2.replace(QLatin1String(">"), QLatin1String("&gt;"));

        description2 = description2.replace(QLatin1String("\n"), QLatin1String("<br>"));

        description2 = description2.replace(" ", "&nbsp;");
        description2 = description2.replace('\t', "&nbsp;&nbsp;&nbsp;&nbsp;"); // хорошо работает

        // странно но <p>..</p> большой текст, надо font-size проставлять стилями
        int hh = QApplication::fontMetrics().height();

        ui->lbl_text2->appendHtml( "<p style=\""+
                                   qp::gui::styleToHtmlAttr( style )
                                   +QString(" font-size:%1px;").arg(hh) +"\">"
                                   +description2
                                   +"</p>"
                                   );

        //repaint(); // тормозит , 100мс на отрисовку

    }
}

void Smart_Process_Dlg::slot_linkActivated(QString href)
{
    //qDebug() << "href " << href;

    ////????QDesktopServices::openUrl( QUrl(href) );

}

void Smart_Process_Dlg::on_btn_Close_clicked()
{
    QApplication::setOverrideCursor( Qt::ArrowCursor);

    accept();
    //emit closeWidget();
}

QString Smart_Process_Dlg::getReestrPrefix() const
{
    return QString("Smart_Process_Dlg");
}

QSize Smart_Process_Dlg::getMinimumSize() const
{
    return QDialog::minimumSize();
}


void Smart_Process_Dlg::on_btn_save_to_file_clicked()
{
    QApplication::setOverrideCursor( Qt::WaitCursor );

    QFile file;

    QString dir="";

    if ( sett.contains( reestr_tlv_files ) )
    {
        QString rDir = sett.value( reestr_tlv_files ).toString();
        if( QDir(rDir).exists())
            dir =  sett.value( reestr_tlv_files ).toString();
    }

    QFileDialog fileDlg;

    QApplication::setOverrideCursor(Qt::ArrowCursor);

    QString fileName = fileDlg.getSaveFileName( this ,
                                                "Сохранить файл",
                                                dir,
                                                "*.txt");

    if( fileName.isEmpty())
        goto err;

    file.setFileName(fileName );

    if ( ! file.open( QFile::WriteOnly ) )
        goto err;


    qint64 len = file.write( ui->lbl_text2->toPlainText().toUtf8() );

    qDebug() << "len" <<len << file.bytesToWrite();

    if( file.bytesToWrite() > 0)
    {
        if( ! file.waitForBytesWritten(10000))
        {
            goto err;
        }
    }

    file.close();

    if ( QMessageBox::warning( this , "Сохраняем документ в файл",
                               "Файл сохранен успешно\n\n"\
                               "Открыть для просмотра?",
                               QMessageBox::Yes,
                               QMessageBox::No
                               ) == QMessageBox::Yes)
    {
        QDesktopServices::openUrl( QUrl::fromLocalFile( fileName ) );

    }

    return;

err:

    file.close();

    QMessageBox::warning( this , "Ошибка",
                          "Файл не сохранен");
}

void Smart_Process_Dlg::on_btn_maximizedShow_clicked()
{
    int margin = 50;
    QSize newSize = qp::gui::screen_size() - QSize( margin , margin );
    setGeometry( margin/2 , margin/2 , newSize.width() , newSize.height() );
    //showMaximized(); // почему-то не на всеь экран
    setMinimumSize( newSize );
    updateGeometry();

}
