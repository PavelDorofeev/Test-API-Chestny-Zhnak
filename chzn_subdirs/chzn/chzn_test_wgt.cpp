#include "chzn_test_wgt.h"
#include "ui_chzn_test_wgt.h"
#include <QSettings>
#include <QAxObject>
#include <QFile>
#include "windows.h"
#include "kb_scanner/kb_wgt/scan_code_dlg.h"
#include "qp/core/meta/meta.h"
#include "chzn_validate.h"
#include "chzn_goods_info.h"
#include "qp/core/json/my_json.h"
#include "qp/core/logging_system/logging_system.h"
#include "qp/gui/qp_wgtstyle.h"
#include "../chzn_api_test/base_version.h"
#include <QDesktopServices>
#include <QDir>
#include <QUrl>
#include <QTextCodec>
#include <iostream>

static const QString reestr_lk_kkt_token = "marking/lk_kkt_token";
static const QString reestr_api_key = "marking/api_key";
static const QString reestr_auth_simpleSignIn = "marking/auth_simpleSignIn";
static const QString reestr_auth_permissive_access = "marking/auth_permissive_access";
static const QString reestr_access_token_id = "marking/access_token_id";
static const QString reestr_gtin = "marking/gtin";
static const QString reestr_ki = "marking/ki";
static const QString reestr_lk_api_key = "marking/lk_api_key";
static const QString reestr_lk_api_key_enabled = "marking/lk_api_key_enabled";
static const QString reestr_api_version = "marking/api_version";
static const QString reestr_kontur = "marking/kontur";
static const QString reestr_inn_uot = "marking/inn_uot";
static const QString reestr_thumbprint_uot = "marking/thumbprint_out";
static const QString reestr_fn_number = "marking/fn_number";
static const QString reestr_lm_login = "marking/lm_login";
static const QString reestr_lm_pw = "marking/lm_pw";


const QString Chzn_Test_Dlg::tempDir = QDir::tempPath()+"\\"+QApplication::organizationName() +"\\" ;
const QString Chzn_Test_Dlg::signed_file_name = "signed_data_out.txt" ;


Chzn_Test_Dlg::Chzn_Test_Dlg( QWidget *parent)
    :
      QFrame(parent),
      ui(new Ui::Chzn_Test_Dlg),
      sett( QApplication::organizationName() , QApplication::applicationName())
{
    ui->setupUi(this);

    // -----------------------------------------------------------

    // -------------------------------------------------------------------
    setAutoFillBackground( false );
    ui->scrollAreaWidgetContents->setAutoFillBackground( false );
    qp::gui::setWindow_woTitle__woFrame_woToolsBtn( this );
    setAttribute( Qt::WA_TranslucentBackground ); // важно

    // -------------------------------------------------------------------
    ui->frame_dark_1->setStyleSheet( QpWgtStyle::get_dark_frame_style() );
    ui->frame_dark_2->setStyleSheet( QpWgtStyle::get_dark_frame_style() );
    ui->frame_dark_3->setStyleSheet( QpWgtStyle::get_dark_frame_style() );
    ui->frame_dark_4->setStyleSheet( QpWgtStyle::get_dark_frame_style() );
    ui->frame_dark_5->setStyleSheet( QpWgtStyle::get_dark_frame_style() );

//    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect( this );
//    shadow->setBlurRadius(40.0);
//    shadow->setColor(QColor(0, 0, 0, 255));
//    shadow->setOffset(0.0);
//    ui->frame_dark_1->setGraphicsEffect( shadow );
    // -------------------------------------------------------------------
    // -----------------------------------------------------------

    setWindowTitle(QString("Тестирование АПИ честного знака версия %1.%2.%3").arg(NVER1).arg(NVER2).arg(STATIC_BUILD_NUMBER));

    ui->lbl_tempDir->setText(Chzn_Test_Dlg::tempDir);

    ui->cmb_api_version->clear();
    ui->cmb_api_version->addItem("v3",3);
    ui->cmb_api_version->addItem("v4",4);

    if( sett.contains("lastBarCode") )
    {
        ui->lbl_code->setText( sett.value("lastBarCode").toString() );
    }


    if( sett.contains( reestr_lk_kkt_token ) && ! sett.value( reestr_lk_kkt_token ).toString().isEmpty())
    {
        ui->ledt_lk_kkt_token->setText( sett.value( reestr_lk_kkt_token ).toString());
    }


    QString key = "marking/cdn"; //+ kkt->getDeviceName();

    if( sett.contains(key) && ! sett.value(key).toString().isEmpty())
    {
        ui->cmb_cdb_list->addItem( sett.value(key).toString() );
    }

    if( sett.contains( reestr_api_key ) && ! sett.value( reestr_api_key ).toString().isEmpty())
    {
        ui->ledt_api_key->setText( sett.value( reestr_api_key ).toString() );
    }

    if( sett.contains( reestr_auth_simpleSignIn ) && ! sett.value( reestr_auth_simpleSignIn ).toString().isEmpty())
    {
        ui->ledt_auth_simpleSignIn->setText( sett.value( reestr_auth_simpleSignIn ).toString() );
    }


    if( sett.contains( reestr_auth_permissive_access ) && ! sett.value( reestr_auth_permissive_access ).toString().isEmpty())
    {
        ui->ledt_auth_permissive_access->setText( sett.value( reestr_auth_permissive_access ).toString() );
    }

    if( sett.contains( reestr_access_token_id ) && ! sett.value( reestr_access_token_id ).toString().isEmpty())
    {
        ui->ledt_access_token_id->setText( sett.value( reestr_access_token_id ).toString() );
    }

    if( sett.contains( reestr_gtin ) && ! sett.value( reestr_gtin ).toString().isEmpty())
    {
        ui->ledt_gtin->setText( sett.value( reestr_gtin ).toString() );
    }

    if( sett.contains( reestr_ki ) && ! sett.value( reestr_ki ).toString().isEmpty())
    {
        ui->ledt_ki->setText( sett.value( reestr_ki ).toString() );
    }


    if( sett.contains( reestr_lk_api_key ) && ! sett.value( reestr_lk_api_key ).toString().isEmpty())
    {
        ui->ledt_lk_api_key->setText( sett.value( reestr_lk_api_key ).toString() );
    }

    if( sett.contains( reestr_lk_api_key_enabled ))
    {
        ui->gr_lk_api_key->setChecked( sett.value( reestr_lk_api_key_enabled ).toBool()) ;
    }


    if( sett.contains( reestr_kontur ) && ! sett.value( reestr_kontur ).toString().isEmpty())
    {
        ui->cmb_konturType->setCurrentIndex( sett.value( reestr_kontur ).toInt() );
    }

    if( sett.contains( reestr_api_version ) && ! sett.value( reestr_api_version ).toString().isEmpty())
    {
        ui->cmb_api_version->setCurrentIndex( sett.value( reestr_api_version ).toInt() );
    }

    if( sett.contains( reestr_inn_uot ) && ! sett.value( reestr_inn_uot ).toString().isEmpty())
    {
        ui->ledt_inn_uot->setText( sett.value( reestr_inn_uot ).toString() );
    }

    if( sett.contains( reestr_thumbprint_uot) && ! sett.value( reestr_thumbprint_uot ).toString().isEmpty())
    {
        ui->ledt_thumbprint->setText( sett.value( reestr_thumbprint_uot ).toString() );
    }

    if( sett.contains( reestr_fn_number) && ! sett.value( reestr_fn_number ).toString().isEmpty())
    {
        ui->ledt_fn_num->setText( sett.value( reestr_fn_number ).toString() );
    }

    if( sett.contains( reestr_lm_login) && ! sett.value( reestr_lm_login ).toString().isEmpty())
    {
        ui->ledt_lm_login->setText( sett.value( reestr_lm_login ).toString() );
    }

    if( sett.contains( reestr_lm_pw) && ! sett.value( reestr_lm_pw ).toString().isEmpty())
    {
        ui->ledt_lm_pw->setText( sett.value( reestr_lm_pw ).toString() );
    }


}

Chzn_Test_Dlg::~Chzn_Test_Dlg()
{
    delete ui;
}

void Chzn_Test_Dlg::parseNewBarCode( const QString & barCode)
{

    ui->ledt_gtin->setText( barCode.mid(2,14) );
    sett.setValue( reestr_gtin,  ui->ledt_gtin->text());

    QString ki = getKI( barCode );

    ui->ledt_ki->setText( ki );
    sett.setValue( reestr_ki ,  ki);

}

void Chzn_Test_Dlg::on_btn_scan_bar_code_clicked()
{
    ui->lbl_code->setText(  scan_bar_code_with_scanner() );

    sett.setValue("lastBarCode" ,  ui->lbl_code->text());

    parseNewBarCode( ui->lbl_code->text() );

}


QString Chzn_Test_Dlg::scan_bar_code_with_scanner()
{
    Scan_Code_Dlg * markirivkaDlg = new Scan_Code_Dlg( 0 );

    markirivkaDlg->setModal( false );

    markirivkaDlg->setGS_isPresent( false );

    if( markirivkaDlg->exec() == Scan_Code_Dlg::ACCEPTED)
    {
        return markirivkaDlg->getScannedCode();
    }

    return "";
}

//void Chzn_Test_Dlg::on_btn_test_clicked()
//{

//    // sThumbprint - отпечаток сертификата, используемого для подписи; строка,
//    // представляющая отпечаток в шестнадцатеричном виде
//    // пример 195934d72dcdf69149901d6632aca4562d8806d8
//    // ТекстДляПодписи должен быть в Base64
//    // bDetached - Истина/Ложь - откреплённая(для подписания документов)/прикреплённая(для

//    //получения токена авторизации) подпись
//    // Функция ПодписатьТекст(ТекстДляПодписи, sThumbprint, bDetached)
//    QByteArray txt = QString("randomdata").toUtf8().toBase64();
//    QString sThumbprint = "950418e91cf9a5dc56895c905591fbe70c70cc83";


//    int CADESCOM_BASE64_TO_BINARY = 1; // Входные данные пришли в Base64

//    int CADESCOM_CADES_TYPE = 1; // Тип усовершенствованной подписи

//    int CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME = 0; // Атрибут штампа времени подписи

//    QAxWidget *wgt = new QAxWidget( this );

//    if( ! wgt->setControl("CAdESCOM.CPSigner") )
//    {
//        QMessageBox::warning( 0 ,
//                              "Предупреждение!",
//                              "CAdESCOM.CPSigner не установлен на ПК\n"\
//                              "идентификатор \"CAdESCOM.CPSigner\" отсутствует в реестре"
//                              );
//    }

//    QAxObject *wordApp = new QAxObject("Word.Application");
//    //интерфейс к подобъекту - коллекция скрытых документов
//    QAxObject *wordDoc = wordApp->querySubObject("Documents()");

//    qDebug() << "---------------- verbs() ------------------------";
//    //    foreach ( QString str,  wgt->verbs() )
//    //        qDebug() << "verb :" << str;

//    qDebug() << "---------------- wgt->propertyBag().keys() -------------------";

//    //    foreach( QString name, wgt->propertyBag().keys())
//    //        ;qDebug() << name << ":353453425435454";// << wgt->propertyBag().value( name);

//    QAxObject* obj= wgt->querySubObject("Certificate");
//    if (obj)
//    {
//        qDebug()<< "querySubObject(Certificates()) =0";

//    }



//    //    getCertificateByThumbprint( sThumbprint );
//    //oSigner = Новый COMОбъект("CAdESCOM.CPSigner");

//    // Объект, задающий параметры создания и содержащий информацию об усовершенствованной     подписи.

//    //    oSigner.Certificate = ПолучитьСертификатПоОтпечатку(sThumbprint);

//    //    oSigningTimeAttr = Новый COMОбъект("CAdESCOM.CPAttribute");
//    //    oSigningTimeAttr.Name = CAPICOM_AUTHENTICATED_ATTRIBUTE_SIGNING_TIME;
//    //    oSigningTimeAttr.Value = ТекущаяДата();
//    //    oSigner.AuthenticatedAttributes2.Add(oSigningTimeAttr);
//    //    ТекстДляПодписи = СокрЛП(ТекстДляПодписи);
//    //    oSignedData = Новый COMОбъект("CAdESCOM.CadesSignedData");
//    //    // Объект CadesSignedData предоставляет свойства и методы для работы с
//    //    усовершенствованной подписью.
//    //    oSignedData.ContentEncoding = CADESCOM_BASE64_TO_BINARY;
//    //    SignedData.Content = СокрЛП(ТекстДляПодписи);
//    //    EncodingType = 0;
//    //    sSignedMessage = oSignedData.SignCades(oSigner, CADESCOM_CADES_TYPE, bDetached,
//    //    EncodingType);
//    //    // Метод добавляет к сообщению усовершенствованную подпись.
//    //    Возврат sSignedMessage; // Подпись в формате Base64
//    //    КонецФункции
//    //    //Отпечаток - строка HEX
//    //    Функция ПолучитьСертификатПоОтпечатку(ОтпечатокСтр)
//    //    Рез = Неопределено; // Найденный сертификат (Com-объект)
//    //    CAPICOM_CURRENT_USER_STORE = 2;
//    //    //2 - Искать сертификат в ветке "Личное" хранилища.
//    //    890CAPICOM_MY_STORE = "My";
//    //    // Указываем, что ветку "Личное" берем из хранилища текущего пользователя
//    //    CAPICOM_STORE_OPEN_READ_ONLY = 0; // Открыть хранилище только на чтение
//    //    oStore = Новый COMОбъект("CAdESCOM.Store"); // Объект описывает хранилище сертификатов
//    //    oStore.Open(CAPICOM_CURRENT_USER_STORE, CAPICOM_MY_STORE,
//    //    CAPICOM_STORE_OPEN_READ_ONLY); // Открыть хранилище сертификатов
//    //    // 1 вариант: поиск сертификата по отпечатку
//    //    CAPICOM_CERTIFICATE_FIND_SHA1_HASH = 0;
//    //    Certificates = oStore.Certificates.Find(CAPICOM_CERTIFICATE_FIND_SHA1_HASH,
//    //    ОтпечатокСтр);
//    //    Рез = Certificates.Item(1);
//    //    //2 вариант: обходом по коллекции и сравнение с отпечатком
//    //    //Для Каждого ТекСертификат Из oStore.Certificates Цикл
//    //    //ТекОтпечаток = ТекСертификат.Thumbprint; // возвращается отпечаток в
//    //    шестнадцатеричном виде
//    //    //Если ВРЕГ(ТекОтпечаток) = ВРЕГ(ОтпечатокСтр) Тогда //Рез = ТекСертификат;
//    //    //Прервать;
//    //    //КонецЕсли;
//    //    //КонецЦикла;
//    //    oStore.Close(); // Закрыть хранилище сертификатов и освободить объект 61
//    //    Возврат Рез;
//    //    КонецФункции

//    //wgt->dynamicCall("Close()");

//    wgt->deleteLater();
//}

void Chzn_Test_Dlg::getCertificateByThumbprint(const QString &Thumbprint)
{
    //	Результат = Неопределено; // Найденный сертификат (Com-объект)

    int CAPICOM_CURRENT_USER_STORE = 2; //2 - искать сертификат в ветке "Личное" хранилища.
    QString CAPICOM_MY_STORE = "My"; // указываем, что ветку "Личное" берем из хранилища текущего пользователя
    int CAPICOM_STORE_OPEN_READ_ONLY = 0; // Открыть хранилище только на чтение


    QAxWidget *oStore = new QAxWidget( this );

    //    qp::meta::cnct( oStore, SIGNAL(exception(int,QString,QString,QString)),
    //                    this, SIGNAL(slot_exception(int,QString,QString,QString)));

    if( ! oStore->setControl("CAdESCOM.Store") )
    {
        QMessageBox::warning( this ,
                              "Предупреждение!",
                              "CAdESCOM.Store не установлен на ПК\n"\
                              "идентификатор \"CAdESCOM.Store\" отсутствует в реестре"
                              );
    }

    //QAxObject obj;

    //obj.initializeLicensedHelper()

    // Открыть хранилище сертификатов.  // This method does not return a value.

    qDebug()<<"Open("<<CAPICOM_CURRENT_USER_STORE<<","<<CAPICOM_MY_STORE<<","<<CAPICOM_STORE_OPEN_READ_ONLY<<")";

    oStore->dynamicCall("Open(int,QString,int)",
                        CAPICOM_CURRENT_USER_STORE,
                        CAPICOM_MY_STORE,
                        CAPICOM_STORE_OPEN_READ_ONLY);

    //qDebug()<< res;

    QAxObject *object = 0;
    VARIANTARG res;
    VariantInit(&res);
    QList< QVariant > vars;

    QByteArray rettype;
    //    if ( ! oStore->dynamicCallHelper("Certificates", &res, vars, rettype))
    //        return 0;

    void *ddd=0;
    //QUuid uuid =
    GUID gg;
    //    long oii = oStore->queryInterface( QUuid( "4552F41D-0C10-4C60-90FB-0D33709575D1" )  , &ddd  );
    //long oii = oStore->queryInterface( QUuid( IID_ICPCertificateStatus )  , &ddd  );

    //    /qDebug()<< "querySubObject(Certificates()) =0" << oii ;

    // Вариант 1: поиск сертификата по отпечатку

    object= oStore->querySubObject("Certificates()");
    if (object)
    {
        qDebug()<< "querySubObject(Certificates()) =0";

    }
    // Вариант 1: поиск сертификата по отпечатку
    //int CAPICOM_CERTIFICATE_FIND_SHA1_HASH = 0;

    //Certificates = oStore.Certificates.Find(CAPICOM_CERTIFICATE_FIND_SHA1_HASH, Отпечаток);

    //	Результат = Certificates.Item(1);

    qDebug()<<"querySubObject(Certificates)";

    QAxObject * Certificates = oStore->querySubObject("Certificates");

    qDebug()<< "Certificates"<<Certificates;

    if (Certificates)
    {
        qDebug()<< "Certificates ok";

    }

    //QVariant res2 = oStore->dynamicCall("Certificates()");
    //QVariant res2 = oStore->property("Certificates");
    //    qDebug()<< res2;

    // Вариант 2: обходом по коллекции и сравнение с отпечатком
    //	Для Каждого ТекСертификат Из oStore.Certificates Цикл
    //		ТекОтпечаток = ТекСертификат.Thumbprint; // возвращается отпечаток в шестнадцатеричном виде
    //		Если ВРЕГ(ТекОтпечаток) = ВРЕГ(ОтпечатокСтр) Тогда
    //			Результат = ТекСертификат;
    //			Прервать;
    //		КонецЕсли;
    //	КонецЦикла;

    //oStore->dynamicCall("Close()"); // Закрыть хранилище сертификатов и освободить объект 61

    oStore->deleteLater();

    //	Возврат Результат;

}

void Chzn_Test_Dlg::slot_exception(int p , const QString &str1, const QString &str2, const QString &str3)
{
    qDebug() <<"slot_exception"<< p << str1 << str2 << str3;
}


bool Chzn_Test_Dlg::startProcess_sign()
{

    QString ret_error;
    QApplication::setOverrideCursor( Qt::WaitCursor );
    QFile signedFile;
    QByteArray rd, wr;
    QProcessEnvironment ee;
    QProcess *process=0;

    QString signedFileNameForCmd = QDir::tempPath()+"\\\\"+QApplication::organizationName()+"\\\\" + Chzn_Test_Dlg::signed_file_name;
    QString signedFileName = Chzn_Test_Dlg::tempDir + signed_file_name;

    QString cmdFileName = Chzn_Test_Dlg::tempDir + "chzn_sign_from_app.cmd";
    QString cmd_process_std_output = Chzn_Test_Dlg::tempDir + "cmd_process_output.txt";
    QString cmd_process_std_error = Chzn_Test_Dlg::tempDir + "cmd_process_error.txt";
    QString csptest_output = Chzn_Test_Dlg::tempDir + "csptest_output.txt";
    QString outStr, errStr;
    QFile errFile, outFile;

    QApplication::setOverrideCursor( Qt::ArrowCursor );

    QMessageBox::warning( this , "Внимание",
                          QString("Cейчас запустим cmd файл для подписи данных строки"\
                                  "от честного знака,\n%1\n%2\n%3\n%4")
                          .arg("Обязательно должен быть установлен КрипроПро.\n")
                          .arg("ЭЦП обязательно должна быть вставлена и установлена в на компьютере (смотрите в приложении 'сертификаты'').\n")
                          .arg("Если далее получаете на следующем этапе подпись на валидна, внимательно проверьте какой подписи отпечаток в указываете.\n")
                          .arg("создаем файл: "+signedFileName)
                          );
    QApplication::setOverrideCursor( Qt::WaitCursor );

    // -----------------------------------------------------------
    // теперь создаем и файл cmd сами здесь
    // -----------------------------------------------------------
    QString cmdText = "@echo off\r\n"\
            "cd %~dp0\r\n"\
            "::chcp 65001 out будет в системной (ОС) кодировке CP1251 \r\n"\
            "::chcp по умолчанию вывод  будет в консольной (ОС) кодировке CP866 \r\n"\
            "echo current dir %1\r\n"\
            "SET PATH=%PATH%;C:\\Program Files (x86)\\Crypto Pro\\CSP;\r\n"\
            "echo tmp =  %tmp%\r\n"\
            "csptest.exe -sfsign -sign -in body.txt -out "+signedFileNameForCmd+" -my "+ui->ledt_thumbprint->text()+" -base64 -add\r\n"\
            "echo ERRORLEVEL:%ERRORLEVEL% \r\n"\
            "exit\r\n";

    QFile cmdfile(cmdFileName);

    cmdfile.open( QIODevice::ReadWrite );
    QByteArray ba =  cmdText.toLocal8Bit();

    if ( ! cmdfile.resize(0) )
    {
        ret_error = "! resize(0) : ошибка очистки файла "+cmdFileName;
        qWarning()<< ret_error;
        goto err;
    }

    cmdfile.seek(0);

    qint64 ll2 = cmdfile.write( ba.constData() );

    if( ll2 != ba.size())
    {
        if ( ! cmdfile.waitForBytesWritten(10000) )
        {
            ret_error = "cmd file is not generated : " + cmdFileName;
            std::cout << ret_error.toLocal8Bit().constData() << std::endl;
            cmdfile.close();
            goto err;
        }
    }

    if ( ! cmdfile.flush() )
    {
        ret_error = "cmd file is written but not flushed : " + cmdFileName;
        std::cout << ret_error.toLocal8Bit().constData() << std::endl;
        cmdfile.close();
        goto err;
    }

    cmdfile.close();
    Sleep(1000);

    //return false;


    qWarning() << "signedFile"<<signedFileName;

    process = new QProcess ( this );

    qp::meta::cnct( process, SIGNAL( started()) ,
                    this, SLOT( slot_process_started()));

    qp::meta::cnct( process, SIGNAL( finished(int,QProcess::ExitStatus)) ,
                    this, SLOT( slot_process_finished(int,QProcess::ExitStatus)));

    qp::meta::cnct( process, SIGNAL(readyReadStandardError()), this, SLOT(slot_readyReadStandardError()) );


    if( ! QFile::exists( cmdFileName ))
    {
        ret_error = "cmd file not found : " + cmdFileName;
        std::cout << ret_error.toLatin1().constData() << std::endl;
        qWarning()<< ret_error;
        goto err;
    }

    //ee =  QProcessEnvironment::systemEnvironment();
    //    ee.insert("PATH", dir);
    //    ee.insert("PATH", libsDir);

    process->setWorkingDirectory( Chzn_Test_Dlg::tempDir );

    //process->setProcessEnvironment(ee);


    qWarning() <<"cmd_process_output" << cmd_process_std_output;

    process->setStandardOutputFile( cmd_process_std_output );
    process->setStandardErrorFile( cmd_process_std_error );

    //QProcess::startDetached("cmd.exe", QString(cmdFileName+" 543454" ).split(' '));

    qWarning() <<"process->start("<<cmdFileName<<")";

    process->start( "cmd.exe");

    qWarning() <<"cmd" << cmdFileName.toLocal8Bit();

    process->write( cmdFileName.toLocal8Bit()+"\n\r" ); // не забывай \r\n везде

    process->write( "exit\n\r"  );
    //----------------------------------------------------------------------------------

    qWarning() <<"process->waitForFinished(..)";

    process->waitForFinished(10000);

    qWarning() <<"process->close()";

    process->close();
    delete process;
    process = 0;


    if( ! QFile::exists( signedFileName ))
    {
        ret_error = "file is not exists " + signedFileName;
        std::cout << ret_error.toLatin1().constData() << std::endl;
        qWarning() << ret_error;
        goto err;
    }

    signedFile.setFileName( signedFileName );

    if( ! signedFile.open( QIODevice::ReadWrite) )
    {
        ret_error = "file is not opened " + signedFileName;
        std::cout << ret_error.toLatin1().constData() << std::endl;
        qWarning() << ret_error;
        goto err;
    }

    rd = signedFile.readAll();

    for( int ii = 0; ii < rd.size(); ii++)
    {
        if( rd.at( ii ) == '\r' || rd.at( ii ) == '\n')
            continue;

        wr.append( rd.at(ii) );
    }

    if ( ! signedFile.resize(0) )
    {
        ret_error = "file " + signedFileName + " opened but is not resized(0)";
        std::cout << ret_error.toLatin1().constData() << std::endl;
        qWarning() << ret_error;
        goto err;
    }

    signedFile.seek(0);

    qint64 ll = signedFile.write( wr);

    if( ll < wr.size() )
    {
        if ( ! signedFile.waitForBytesWritten( 5000 ) )
            goto err;
    }
    else if( ll > wr.size() )
    {
        ret_error = "error with write data to file " + signedFileName;
        std::cout << ret_error.toLatin1().constData() << std::endl;
        qWarning() << ret_error;
        goto err;
    }

    if ( ! signedFile.flush() )
    {
        ret_error = "error with flush file " + signedFileName;
        std::cout << ret_error.toLatin1().constData() << std::endl;
        qWarning() << ret_error;
        goto err;
    }

    signedFile.close();

    outFile.setFileName( cmd_process_std_output );
    if( outFile.open( QIODevice::ReadOnly ) )
    {
        QByteArray ba = outFile.readAll();
        //        qDebug() << "fromLatin1" << QString::fromLatin1( ba );
        //        qDebug() << "fromLocal8Bit" << QString::fromLocal8Bit( ba );
        //        qDebug() << "fromAscii" << QString::fromAscii( ba);

        QTextCodec * localCodec = QTextCodec::codecForLocale();
        qDebug() << "localCodec" << localCodec->name();

        UINT cpSystemInt = GetACP();
        QString cpSystemStr = QString("CP%1").arg(cpSystemInt);
        qDebug() << "cpSystemStr" << cpSystemStr;

        UINT cpConsoleInt = GetOEMCP();
        QString cpConsoleStr = QString("CP%1").arg(cpConsoleInt);
        qDebug() << "cpConsoleStr" << cpConsoleStr;


        QTextCodec *consoleCodec = QTextCodec::codecForName( "CP866");//cpConsoleStr.toLatin1());
        QTextCodec *systemCodec = QTextCodec::codecForName( cpSystemStr.toLatin1());

        outStr = "--------------------------------------------------------------------------\n"+
                consoleCodec->toUnicode( ba ) + "\n" +
                "--------------------------------------------------------------------------";

        if( consoleCodec && systemCodec)
        {
            // -------------------------------------------------------------------------------------------
            // помни в qDebug нельзя выводить прямо QByteArray в кодировке CP866 или CP1251
            // русскиен символы будут отображаться не правильно
            // но можно выводить QString
            // и помни для QString в QDebug:
            // не забудь в main.cpp QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
            // -------------------------------------------------------------------------------------------


            qWarning() <<"------------------------------------------------------------";
            qWarning() << cpConsoleStr << outStr.toUtf8();
            qWarning() <<"------------------------------------------------------------";
            //            qDebug() << cpConsoleStr << consoleCodec->toUnicode( ba );
            //            qDebug()<<"------------------------------------------------------------";
            //            //qDebug() << cpSystemStr << systemCodec->fromUnicode( ba );
            //            qDebug()<<"------------------------------------------------------------";
            //            qDebug() << cpSystemStr << systemCodec->toUnicode( ba );
            //            qDebug()<<"------------------------------------------------------------";
            //            //qDebug() << cpSystemStr <<  ba ;
            //            qDebug()<<"------------------------------------------------------------";
            //            qDebug() << cpSystemStr <<  ba.toHex() ;//.mid(0x60 , 100 ).toHex() ;
            //            qDebug()<<"------------------------------------------------------------";

        }
    }
    outFile.close();

    QApplication::setOverrideCursor( Qt::ArrowCursor );

    QMessageBox::information ( this , "Успешно" ,
                               QString("cmd файл выполнен %1\n\n"\
                                       "--------------------------------------------------------------------------\n"\
                                       "лог выполнения cmd файла:\n%2")
                               .arg( cmdFileName )
                               .arg( outStr )
                               );


    return true;

err:
    QApplication::setOverrideCursor( Qt::ArrowCursor );

    errFile.setFileName( cmd_process_std_error );
    if( errFile.open(QIODevice::ReadOnly) )
    {
        errStr = errFile.readAll();
    }
    errFile.close();
    QMessageBox::critical( this , "Ошибка" ,
                           QString("%1\n\n%2")
                           .arg(ret_error)
                           .arg(errStr)
                           );

    if( process != 0)
    {
        process->close();
        delete process;
    }
    return false;

}


void Chzn_Test_Dlg::slot_process_started()
{
    qDebug()<<"slot_started";
}

void Chzn_Test_Dlg::slot_process_finished(int result , QProcess::ExitStatus status)
{
    //QProcess::ProcessError err = process->error();
}

void Chzn_Test_Dlg::slot_readyReadStandardError()
{
    //    QByteArray rd = process->readAllStandardError();

    //    std::cout << rd.data() << std::endl;


    //    err_log.append( rd );
}

void Chzn_Test_Dlg::on_btn_startProcess_sign_clicked()
{
    startProcess_sign();
}


void Chzn_Test_Dlg::on_ledt_gtin_returnPressed()
{
    sett.setValue( reestr_gtin , ui->ledt_gtin->text() );
}


void Chzn_Test_Dlg::on_ledt_lk_api_key_returnPressed()
{
    sett.setValue( reestr_lk_api_key , ui->ledt_lk_api_key->text() );

}

void Chzn_Test_Dlg::on_cmb_konturType_activated( int index )
{
    sett.setValue( reestr_kontur , index );
}


void Chzn_Test_Dlg::on_gr_lk_api_key_clicked( bool checked )
{
    sett.setValue( reestr_lk_api_key_enabled , checked );
}

void Chzn_Test_Dlg::on_gr_lk_api_key_toggled(bool checked)
{
    sett.setValue( reestr_lk_api_key_enabled , checked );
}



void Chzn_Test_Dlg::on_cmb_api_version_activated( int index )
{
    sett.setValue( reestr_api_version , ui->cmb_api_version->currentIndex());
}


QVariant Chzn_Test_Dlg::common_cmd( const QVariantMap &params ,
                                    const QVariant &bodyObj,
                                    const QString &slotName ,
                                    const QString &title,
                                    bool closeWinifSuccessful)
{
    ChZn_Validate chzn( this );

    QVariant retVal;

    bool bbb = qp::gui::call_slot( this ,

                                   &chzn ,

                                   title,

                                   ui->cmb_api_version->itemText( ui->cmb_api_version->currentIndex())+" "+
                                   ui->cmb_konturType->itemText( ui->cmb_konturType->currentIndex())+" ",

                                   "Ждите идет процесс...",

                                   slotName,

                                   QList<const QObject*>() << &chzn,

                                   QList<QVariant>() << params << bodyObj ,

                                   retVal,

                                   closeWinifSuccessful
                                   );

    if( ! bbb )
        return false ;

    return retVal;
}

void Chzn_Test_Dlg::on_btn_getCdnHosts_clicked()
{
    QVariant retVal;

    if( ui->ledt_lk_kkt_token->text().isEmpty() )
    {
        ui->ledt_lk_kkt_token->setFocus();
        return;
    }

    if ( ! sett.contains( reestr_lk_kkt_token ) ||  sett.value( reestr_lk_kkt_token ).toString() != ui->ledt_lk_kkt_token->text() )
    {
        sett.setValue( reestr_lk_kkt_token , ui->ledt_lk_kkt_token->text()  );
    }

    QApplication::setOverrideCursor( Qt::WaitCursor );

    ChZn_Validate chzn( this );

    bool bbb = qp::gui::call_slot( this ,

                                   &chzn ,

                                   "получить cdn площадки",

                                   QString("получить cdn площадки по токену %1")
                                   .arg( ui->ledt_lk_kkt_token->text() ),

                                   "Ждите идет процесс...",

                                   "slot_getCdnHosts",

                                   QList<const QObject*>() << &chzn ,

                                   QList<QVariant>() << ui->ledt_lk_kkt_token->text() << ui->cmb_konturType->currentIndex(),

                                   retVal,

                                   false
                                   );

    if( ! bbb)
        return;

    QVariantList lst;
    if( retVal.canConvert( QVariant::List ))
        lst = retVal.toList();

    ui->cmb_cdb_list->clear();

    qDebug() <<lst;

    foreach(QVariant var, lst )
    {
        ui->cmb_cdb_list->addItem( var.toString() );
    }
}


void Chzn_Test_Dlg::on_btn_chzn_validate_clicked()
{
    /*
            Метод /codes/check предназначен только для проверки продукции перед розничной продажей для
            выполнения требований, предусмотренных ППР 1944 от 21.11.23
    */

    ChZnResponseLst chzn = cdn_codes_check( ui->lbl_code->text().toLocal8Bit());

    if( chzn.code == 0 )
    {

    }

    QString str = ui->cmb_cdb_list->itemText(  ui->cmb_cdb_list->currentIndex()) ;

    QString key = "marking/cdn";

    if( ! sett.contains(key) || sett.value(key).toString() != str)
    {
        sett.setValue( key , str) ;
    }
}

// cdn/health/check



void Chzn_Test_Dlg::on_btn_chzn_cdn_host_check_clicked()
{
    // Описание метода получения состояния CDN-площадки

    ChZnResponseLst answ;

    ChZn_Validate chzn( this );

    if( ui->cmb_cdb_list->currentIndex() == -1)
    {
        ui->cmb_cdb_list->setFocus();
        return ;
    }

    QVariantMap params;

    QString cdn = getDomain( ui->cmb_cdb_list->itemText( ui->cmb_cdb_list->currentIndex()) ) ;
    params.insert( "cdn" , cdn );

    params.insert( "marking_token" , ui->ledt_lk_kkt_token->text() );

    //params.insert( "kontur" , ui->cmb_konturType->currentIndex() );

    QVariant retVal;

    bool bbb = qp::gui::call_slot( this ,

                                   &chzn ,

                                   "Получения состояния CDN-площадки",

                                   cdn,

                                   "Ждите идет процесс...",

                                   "slot_getCdnHostValidation",

                                   QList<const QObject*>() << &chzn,

                                   QList<QVariant>() << params ,

                                   retVal,

                                   false
                                   );

    if( ! bbb )
        return ;

    answ = ChZnResponseLst::from_Variant( retVal );

}

QVariantMap Chzn_Test_Dlg::prepareGtinObj()
{
    QString barCode = ui->lbl_code->text();

    QString gtin = barCode.mid( 3 , 14);

    QVariantList gtins;
    gtins.append( gtin);

    QVariantMap body;

    body.insert( "gtins" , gtins );

    return body;

}


QVariantMap Chzn_Test_Dlg::prepareFullCodeObj()
{
    QByteArray rd = ui->lbl_code->text().toLocal8Bit();

    qDebug() << ui->lbl_code->text();


    QByteArray wr;

    for( int ii=0; ii< rd.size(); ii++ )
    {
        if ( rd.at( ii ) == 0x1d )
        {
            wr.append(QLatin1String("\\u001d") );
        }
        else
            wr.append( rd.at( ii ) );
    }

    QVariantList codesLst;
    codesLst.append( "\""+wr+"\"" );

    QVariantMap body;

    body.insert( "codes" , codesLst );

    qDebug() << QtJson::serialize1( body );
    return body;

}

bool Chzn_Test_Dlg::setBarCode( const QString &barCode )
{
    ui->lbl_code->setText( barCode );

    parseNewBarCode( barCode );

    return true;

}

QVariant Chzn_Test_Dlg::prepareKiList()
{
    QString barCode = ui->lbl_code->text();

    QString ki = getKI( barCode );

    QVariantList gtins;
    gtins.append( ki);

    QVariantList body;

    body.append( gtins );

    return body;


}
QVariantMap Chzn_Test_Dlg::prepareCis() const
{

    /*
        {
            "cis":"0104655555555555212FFFFFFFFFFFF\u001D91LlLl\u001D9212345TtTtT12345TtTtT12345TtTtT12345TtTtTtTt="
        }
    */
    QByteArray rd = ui->lbl_code->text().toLocal8Bit();

    QByteArray wr;

    for( int ii=0; ii< rd.size(); ii++ )
    {
        if ( rd.at( ii ) == 0x1d )
        {
            wr.append(QLatin1String("\\u001D") );
        }
        else
            wr.append( rd.at( ii ) );
    }

    QVariantMap body;

    body.insert( "cis" , "\""+wr+"\"" );

    return body;

}

void Chzn_Test_Dlg::on_btn_get_product_info_clicked()
{

    /*
            5.5. Получение информации о карточках товара УОТ
            5.5.1. Метод получения информации о товаре по GTIN товара
            В результате успешного выполнения запроса по списку кодов товаров в ответе возвращается
            массив с информацией о товарах по запрошенным КИ. В результирующем * .json также может
            содержаться набор полей, специфичных для товара конкретной товарной группы (см.
            «Справочник "Дополнительные параметры в ответе в зависимости от товарных групп"»).
            Действует следующее ограничение: не более 1000 значений «gtin» («Код товара») в параметре
            «gtins» («Массив кодов товаров»).
            В ответе метода возвращается информация только по карточкам товаров, для которых значения
            признаков «goodTurnFlag» («Признак готовности товара к обороту») и «goodMarkFlag»
            («Признак готовности к маркировке») равны «true».
            5.5.1.1. Версия V4
            Тип приватности: публичный !!!!
   */

    QVariantMap params = common_settings(  "/product/info" );
    //params.remove("Bearer_token");

    common_cmd(  params, prepareGtinObj() , "slot_get_product_info", "Получения информации о товаре по GTIN товара");

}

bool Chzn_Test_Dlg::get_api_key()
{

    /*
        Метод используется для получения "аутентификационного" токена, предназначенного для вызова
        метода «Метод верификации кодов маркировки и получения сокращённой информации о
        товаре» (/codes/check).
    */

    if( ui->ledt_thumbprint->text().isEmpty())
    {
        ui->ledt_thumbprint->setFocus();
        QMessageBox::warning( this , "Ошибка", "укажите отпечаток ЭЦП УОТ");
        return false;
    }

    QVariantMap params =  common_settings( "/auth/key");
    params.remove("Bearer_token");


    QVariant retVal = common_cmd( params , QVariantMap(), "slot_get_auth_key", "Запрос аутентификации" );


    if( retVal.type() == QVariant::Bool && retVal.toBool() == false  )
        return false;

    if( ! retVal.canConvert( QVariant::String))
        return false;

    QString response = retVal.toString();

    QVariant answ =  QtJson::parse1( response);

    if( ! answ.canConvert( QVariant::Map))
        return false;

    QVariantMap mm = answ.toMap();
    qDebug() << QtJson::serialize1( mm );

    ui->ledt_api_key->setText( response );

    if( mm.contains("error_message") )
        return false;

    if( ! mm.contains("data"))
        return false;


    sett.setValue( reestr_api_key , response );


    QString bodyFile = Chzn_Test_Dlg::tempDir + "body.txt";
    QFile file( bodyFile  );

    //qWarning() << "bodyFile"<<bodyFile;

    if( ! file.open( QIODevice::WriteOnly) )
    {
        return false;
    }

    QByteArray wr = mm.value("data").toString().toLocal8Bit();

    qint64 ll = file.write( wr);

    if( ll < wr.size() )
    {
        if ( ! file.waitForBytesWritten( 5000 ) )
            return false;
    }
    else if( ll < wr.size() )
    {
        Q_ASSERT(1==64565465);
    }
    file.close();

    if ( ! startProcess_sign() )
        return false;

    return true;

}
void Chzn_Test_Dlg::on_btn_get_api_key_clicked()
{
   get_api_key();
}

const QString Chzn_Test_Dlg::getkktToken( ) const
{

    return ui->ledt_lk_kkt_token->text();
}

const int Chzn_Test_Dlg::getCurrentCdnHost( ) const
{

    return ui->cmb_cdb_list->currentIndex();
}

bool Chzn_Test_Dlg::is_api_key_used( ) const
{

    return ui->gr_lk_api_key->isChecked();
}

void Chzn_Test_Dlg::on_btn_get_auth_simpleSignIn_clicked()
{
    get_auth_simpleSignIn();
}

bool Chzn_Test_Dlg::get_auth_simpleSignIn()
{

    QFile file1( Chzn_Test_Dlg::tempDir + Chzn_Test_Dlg::signed_file_name  );

    if( ! file1.open( QIODevice::ReadOnly) )
    {
        QMessageBox::warning( this , "Ошибка" , file1.fileName()+" не сгенерирован");
        return false;
    }
    QString signed_data = file1.readAll();

    file1.close();


    bool ok;
    QVariant mm = QtJson::parse1( ui->ledt_api_key->text() , ok );

    if( ! mm .canConvert( QVariant::Map) || ! ok )
        return false;

    QVariantMap bodyObj1 = mm.toMap();

    QVariantMap bodyObj;
    bodyObj.insert("uuid" , bodyObj1.value("uuid"));
    bodyObj.insert("data", signed_data );
    bodyObj.insert("inn", ui->ledt_inn_uot->text().trimmed() );


    QVariant retVal = common_cmd( common_settings("/auth/simpleSignIn"), bodyObj, "slot_get_auth_simpleSignIn" , "Запрос аутентификации");



    ui->ledt_auth_simpleSignIn->setText( retVal.toString() );

    sett.setValue( reestr_auth_simpleSignIn ,  ui->ledt_auth_simpleSignIn->text());

    QVariant var = QtJson::parse1( retVal.toString() );

    QFile file( Chzn_Test_Dlg::tempDir + "auth_simpleSignIn.txt"  );

    if( ! file.open( QIODevice::WriteOnly) )
    {
        return false;
    }
    QByteArray wr = retVal.toString().toLocal8Bit();
    qint64 ll = file.write( wr);
    if( ll < wr.size() )
    {
        if ( ! file.waitForBytesWritten( 5000 ) )
            return false;
    }
    else if( ll < wr.size() )
    {
        Q_ASSERT(1==64565465);
    }
    file.close();

    return true;

}


void Chzn_Test_Dlg::on_btn_get_auth_permissive_access_clicked()
{
    QFile file1( Chzn_Test_Dlg::tempDir + Chzn_Test_Dlg::signed_file_name  );

    if( ! file1.open( QIODevice::ReadOnly) )
    {
        QMessageBox::warning( this , "Ошибка" , file1.fileName()+" не сгенерирован");
        return;
    }
    QString signed_data = file1.readAll();

    file1.close();


    QVariantMap bodyObj;

    //bodyObj.remove("data");
    bodyObj.insert("data", signed_data );


    QVariantMap params = common_settings( "/auth/permissive-access");

    QVariant retVal = common_cmd( params , bodyObj , "slot_get_auth_permissive_access" , "Запрос авторизации" );

    if( retVal.type() == QVariant::Bool && retVal.toBool() == false )
        return ;

    QVariantMap mm = retVal.toMap();

    ui->ledt_auth_permissive_access->setText( mm.value("access_token").toString() );
    ui->ledt_access_token_id->setText(  mm.value("id_token").toString() );


    sett.setValue( reestr_auth_permissive_access ,  ui->ledt_auth_permissive_access->text());
    sett.setValue( reestr_access_token_id ,  ui->ledt_access_token_id->text());

}

QVariantMap Chzn_Test_Dlg::common_settings ( const QString &cmdName)
{
    QVariantMap params;

    params.insert( "Bearer_token" , ui->ledt_auth_simpleSignIn->text() );

    params.insert("kontur" , ui->cmb_konturType->currentIndex());

    params.insert("api_version" , ui->cmb_api_version->itemData( ui->cmb_api_version->currentIndex())) ;

    if ( ui->gr_lk_api_key->isChecked() )
        params.insert("lk_api_key", ui->ledt_lk_api_key->text());
    else
        ;//params.insert("bearer_key", ui->ledt_auth_simpleSignIn->text());

    params.insert("cmd" , cmdName);

    return params;
}



Nk_Product Chzn_Test_Dlg::get_nk_product( const QString &gtin , bool closeWinIfSuccessful )
{
    QVariantMap params = common_settings( "/nk/product" );
    params.insert("gtin" , gtin );

    QVariant vv = common_cmd( params , QVariantMap(), "slot_get_nk_product",
                              "получение информации о товаре  в национальном каталоге ЧЗ",
                              closeWinIfSuccessful );

    Nk_Product_Lst nk_product_lst = Nk_Product_Lst::from_Variant( vv );

    if( nk_product_lst.productLst.count() == 1)
    {
        return nk_product_lst.productLst.at(0);
    }

    return Nk_Product();


}

void Chzn_Test_Dlg::on_btn_get_nk_product_clicked()
{

    get_nk_product( ui->ledt_gtin->text() );

}

ChZnGoodsInfoLst Chzn_Test_Dlg::get_cises_info( bool closeWinOnSuccessful )
{

    QVariant retVal = common_cmd( common_settings("/cises/info") , prepareKiList(), "slot_get_cises_info", "получение информации о товаре" , closeWinOnSuccessful);

    return ChZnGoodsInfoLst::from_Variant( retVal );
}

void Chzn_Test_Dlg::on_btn_get_cises_info_clicked()
{
    get_cises_info();
}

void Chzn_Test_Dlg::on_btn_get_cises_ease_info_clicked()
{

    common_cmd( common_settings("/cises/ease/info") , prepareCis(), "slot_get_cises_ease_info", "Проверка" );
}

QString Chzn_Test_Dlg::getDomain(const QString & url )const
{
    QStringList lst = url.split("://");

    if( lst.count() == 1 )
        return url;

    // ------------------------------------
    // отсекаем https://
    // ------------------------------------

    if( lst.count() == 2 )
        return lst.at( 1 );

    return "???? 34253453454354";

}

QString Chzn_Test_Dlg::getKI(const QString & barCode )const
{
    int pos91 = barCode.indexOf( QChar(0x1d));

    if( barCode < 0 )
        return QString();

    return barCode.mid(0 , pos91);
}

QVariant Chzn_Test_Dlg::slot_cdn_codes_check( const QByteArray &barCd )
{
    ChZnResponseLst resp = cdn_codes_check( barCd );

    return QVariant::fromValue( resp ) ;

}

ChZnResponseLst Chzn_Test_Dlg::cdn_codes_check( const QByteArray &barCd , bool closeWinUfSuccessful)
{
    ChZnResponseLst rr;

    if( ui->cmb_cdb_list->currentIndex() < 0 )
    {
        ui->cmb_cdb_list->setFocus();
        return rr;
    }

    QVariantMap params = common_settings("/codes/check");

    params.insert("cdn" ,  getDomain( ui->cmb_cdb_list->itemText( ui->cmb_cdb_list->currentIndex()) ) );

    params.insert("X-API-KEY" , ui->ledt_lk_kkt_token->text());


    QVariant retVal = common_cmd( params , prepareFullCodeObj(), "slot_get_codes_check", "Проверка кода маркировки в честном знаке" , closeWinUfSuccessful);

    rr = ChZnResponseLst::from_Variant( retVal );

    return rr;
}



QVariant Chzn_Test_Dlg::get_codes_check()
{

    /*
            5.1.7.1. Метод верификации кодов маркировки и получения сокращённой информации о товаре
            Метод предназначен для возможности интеграции верхнеуровневого программного обеспечения
            участника оборота товаров с Системой маркировки в случаях верификации КМ.
            Тип приватности: публичный

        */
    QVariantMap params = common_settings(  "/codes/check" );
    params.insert("access_token" , ui->ledt_auth_permissive_access->text());

    QVariantMap bodyMap = prepareFullCodeObj();
    bodyMap.insert( "inn" , ui->ledt_inn_uot->text().trimmed());

    return common_cmd( params , bodyMap, "slot_get_codes_check", "Проверка кода маркировки в честном знаке" );

}

void Chzn_Test_Dlg::on_btn_get_codes_check_clicked()
{
    get_codes_check();
}

void Chzn_Test_Dlg::on_ledt_inn_uot_returnPressed()
{
    sett.setValue( reestr_inn_uot , ui->ledt_inn_uot->text());
}

void Chzn_Test_Dlg::on_ledt_thumbprint_returnPressed()
{
    sett.setValue( reestr_thumbprint_uot , ui->ledt_thumbprint->text());

}


void Chzn_Test_Dlg::on_btn_get_cises_check_clicked()
{
    /*
        5.1.7.2. Метод верификации кода маркировки
        Метод предназначен для проверки наличия в ГИС МТ указанного КИ с криптографической
        частью. Метод ограничен по частоте запросов (допустимая частота запросов метода - 2 секунды)
        и количеству КИ в запросе (максимальное количество КИ в запросе - 1000) и не предназначен
        для вызова с ККТ при сканировании КИ при розничной реализации.
        URL: /cises/check
            {
            "codes":[
            ]
            }

    */
    QVariantMap params = common_settings(  "/cises/check" );
    //params.insert("access_token" , ui->ledt_auth_permissive_access->text());

    QVariantMap bodyMap = prepareFullCodeObj();
    //bodyMap.insert( "inn" , ui->ledt_inn_uot->text().trimmed());

    common_cmd( params , bodyMap, "slot_get_cises_check", "Проверка кода маркировки в честном знаке" );
}

void Chzn_Test_Dlg::on_ledt_lk_kkt_token_returnPressed()
{
    sett.setValue( reestr_lk_kkt_token , ui->ledt_lk_kkt_token->text());
}

void Chzn_Test_Dlg::on_btn_get_cises_check_history_create_clicked()
{
    /*
       Метод формирования выгрузки по запросам codes/check

        curl -X POST "<url контура>/api/v4/true-api/codes/check/history/create"
        -H "Content-Type: application/json"
        -H "X-API-KEY: <Аутентификационный токен участника оборота>"
        -d "{"requests":[{"reqId":"string","reqTimestamp":long]}

        {
            "requests": [
            {
                "reqId": "4d7b09a5-bb9c-43c1-bb0d-1300f95c4afc",
                "reqTimestamp": 1697805311077
            },
            {
                "reqId": "7ee3fbf7-4156-4f7c-b38a-f0230d47f0a1",
                "reqTimestamp": 1697805333099
            },
            {
                "reqId": "46290b32-8625-4cb4-a4e7-d98be938274c",
                "reqTimestamp": 1697805322088
            }
            ]
        }
    */

    QVariantMap params = common_settings(  "/codes/check/history/create" );
    params.insert("X-API-KEY" , ui->ledt_lk_kkt_token->text());

    QVariantMap bodyMap = prepareFullCodeObj();
    QVariantList lst;
    QVariantMap itm1;
    itm1.insert("reqId", ""); // uuid
    itm1.insert("reqTimestamp", 353454354 );
    lst.append( itm1 );
    bodyMap.insert("requests" , lst );

    common_cmd( params , bodyMap, "slot_get_cises_check_history_create", "формирования выгрузки по запросам codes/check" );
}

void Chzn_Test_Dlg::on_btn_get_cises_check_history_receive_clicked()
{

    /*
            1.6.2 Метод получения результата выгрузки
                Хост для тестового контура: https://markirovka.sandbox.crptech.ru
                Хост для продуктивного контура: https://markirovka.crpt.ru
            Метод: GET
            URL: /codes/check/history/receive
            Пример строки запроса:
            curl -X GET "<url контура>/api/v4/trueapi/codes/check/history/receive?queryId=3034fde7-8db6-4456-99ab-aa9e449b42d8"
            -H "Content-Type: application/json"
            -H "X-API-KEY: <Аутентификационный токен участника оборота>"
            Ограничения:
            • частота вызова метода – 1 раз в минуту
    */

    QVariantMap params = common_settings(  "/codes/check/history/receive" );
    params.insert("X-API-KEY" , ui->ledt_lk_kkt_token->text());

    common_cmd( params , QVariantMap(), "slot_get_cises_check_history_receive", "получения результата выгрузки" );

}

void Chzn_Test_Dlg::on_btn_log_clicked()
{
    if ( ! QDesktopServices::openUrl( QUrl::fromLocalFile(logging_System::getLogFile())))
        ;

}

void Chzn_Test_Dlg::on_btn_lm_init_clicked()
{
    QVariantMap params = common_settings(  "/init" );

    if( ! testLmLoginPw() )
        return;
    params.insert("Basic_token" , QString("%1:%2").arg( ui->ledt_lm_login->text()).arg( ui->ledt_lm_pw->text()).toLocal8Bit().toBase64());


    params.insert("X-ClientId" , ui->ledt_fn_num->text().trimmed());

    QVariantMap bodyObj;
    bodyObj.insert("token" , ui->ledt_lk_kkt_token->text() );

    common_cmd( params , bodyObj, "slot_get_lm_init", "инициализации ЛМ ЧЗ" );
}

void Chzn_Test_Dlg::on_ledt_fn_num_returnPressed()
{
    sett.setValue( reestr_fn_number ,  ui->ledt_fn_num->text());
}

void Chzn_Test_Dlg::on_btn_lm_status_clicked()
{
    QVariantMap params = common_settings(  "/status" );

    if( ! testLmLoginPw() )
        return;
    params.insert("Basic_token" , QString("%1:%2").arg( ui->ledt_lm_login->text()).arg( ui->ledt_lm_pw->text()).toLocal8Bit().toBase64());


    params.insert("X-ClientId" , ui->ledt_fn_num->text().trimmed());


    common_cmd( params , QVariantMap() , "slot_get_lm_status", "Проверка статуса ЛМ ЧЗ" );

}

LmResponseLst Chzn_Test_Dlg::lm_cis_check( const QString &ki , bool closeWinIfSuccessful)
{

    LmResponseLst lst;

    QVariantMap params = common_settings(  "/cis/check" );

    if( ! testLmLoginPw() )
        return lst;

    params.insert("Basic_token" , QString("%1:%2").arg( ui->ledt_lm_login->text()).arg( ui->ledt_lm_pw->text()).toLocal8Bit().toBase64());

    params.insert("X-ClientId" , ui->ledt_fn_num->text().trimmed());
    params.insert("cis" , ki);


    QVariant res = common_cmd( params , QVariantMap() , "slot_get_lm_cis_check", "Проверка КИ в ЛМ ЧЗ", closeWinIfSuccessful );

    lst = LmResponseLst::from_Variant( res );

    return lst;
}

void Chzn_Test_Dlg::on_btn_lm_cis_check_clicked()
{
    lm_cis_check( ui->ledt_ki->text().trimmed() );

}

void Chzn_Test_Dlg::on_btn_lm_cis_check_old_clicked()
{

    QVariantMap params = common_settings(  "/cis/check" );

    if( ! testLmLoginPw() )
        return;
    params.insert("Basic_token" , QString("%1:%2").arg( ui->ledt_lm_login->text()).arg( ui->ledt_lm_pw->text()).toLocal8Bit().toBase64());

    params.insert("X-ClientId" , ui->ledt_fn_num->text().trimmed());
    //params.insert("cis" , ui->ledt_ki->text().trimmed());

    QVariantList lst;
    lst.append(ui->ledt_ki->text().trimmed());

    QVariantMap mm;
    mm.insert( "cis_list" , lst );

    common_cmd( params ,mm , "slot_get_lm_cis_check", "Проверка КИ в ЛМ ЧЗ" );

}

void Chzn_Test_Dlg::on_btn_lm_cis_outCheck_clicked()
{

    QVariantMap params = common_settings(  "/cis/outCheck" );

    if( ! testLmLoginPw() )
        return;
    params.insert("Basic_token" , QString("%1:%2").arg( ui->ledt_lm_login->text()).arg( ui->ledt_lm_pw->text()).toLocal8Bit().toBase64());
    params.insert("X-ClientId" , ui->ledt_fn_num->text().trimmed());
    params.insert("cis" , ui->ledt_ki->text().trimmed());


    common_cmd( params , QVariantMap() , "slot_get_lm_cis_outCheck", "Проверка КИ в ЛМ ЧЗ (целевой)" );
}

bool Chzn_Test_Dlg::testLmLoginPw() const
{
    if( ui->ledt_lm_login->text().isEmpty())
    {
        QMessageBox::warning( const_cast<Chzn_Test_Dlg*>(this) , "ошибка" , "логин для локального модуля не указан" );
        ui->ledt_lm_login->setFocus();
        return false;
    }

    if( ui->ledt_lm_pw->text().isEmpty())
    {
        QMessageBox::warning ( const_cast<Chzn_Test_Dlg*>(this) , "ошибка" , "пароль для локального модуля не указан");
        ui->ledt_lm_pw->setFocus();
        return false;
    }

    return true;
}

void Chzn_Test_Dlg::on_btn_lm_cis_outCheck_post_clicked()
{

    QVariantMap params = common_settings(  "/cis/outCheck" );

    if( ! testLmLoginPw() )
        return;
    params.insert("Basic_token" , QString("%1:%2").arg( ui->ledt_lm_login->text()).arg( ui->ledt_lm_pw->text()).toLocal8Bit().toBase64());
    params.insert("X-ClientId" , ui->ledt_fn_num->text().trimmed());

    QVariantList lst;
    lst.append(ui->ledt_ki->text().trimmed());

    QVariantMap mm;
    mm.insert( "cis_list" , lst );

    common_cmd( params ,mm , "slot_get_lm_cis_outCheck", "проверки КИ в ЛМ ЧЗ (целевой)" );

}

void Chzn_Test_Dlg::on_ledt_lm_login_returnPressed()
{
    sett.setValue( reestr_lm_login , ui->ledt_lm_login->text() );
}

void Chzn_Test_Dlg::on_ledt_lm_pw_returnPressed()
{
    sett.setValue( reestr_lm_pw , ui->ledt_lm_pw->text() );
}

void Chzn_Test_Dlg::on_btn_get_nk_short_product_clicked()
{
    QVariantMap params = common_settings(  "/nk/short-product");
    params.insert("gtin" , ui->ledt_gtin->text());

    common_cmd( params , QVariantMap(), "slot_get_nk_short_product", "получение короткой информации о товаре в национальном каталоге ЧЗ" );
}

void Chzn_Test_Dlg::on_btn_get_nk_feed_product_clicked()
{
    QVariantMap params = common_settings(  "/nk/feed-product");
    params.insert("gtin" , ui->ledt_gtin->text());

    common_cmd( params , QVariantMap(), "slot_get_nk_feed_product", "получение короткой информации о товаре в национальном каталоге ЧЗ" );

}

