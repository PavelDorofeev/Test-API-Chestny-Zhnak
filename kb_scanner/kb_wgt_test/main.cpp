#include <QtGui/QApplication>
#include "dialog.h"

#include "kb_wgt/scan_code_dlg.h"
#include <QDir>
#include <QMessageBox>
#include <QDebug>

#include "qp/core/logging_system/logging_system.h"

const QString add_QDialog_Styles();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("Bit Ltd");
    QApplication::setApplicationName("Test KB scanner");


    // -----------------------------------------------------------------
    //                      logging_System
    // -----------------------------------------------------------------

    logging_System::LOG_TYPES logTypes = (logging_System::LOG_WARNING
                                          |logging_System::LOG_CRITICAL
                                          |logging_System::LOG_FATAL);

    bool logging_history_ON = true;

//#if defined(MY_DEBUG)

    logTypes |= logging_System::LOG_DEBUG; // не подсвечивается , но работает
    logTypes |= logging_System::LOG_WARNING; // не подсвечивается , но работает
    logTypes |= logging_System::LOG_CRITICAL; // не подсвечивается , но работает

    logging_history_ON = false;

//#endif


    QString logDir = QDir::tempPath()+ "\\"+"BIT_Development";

    bool ll = logging_System::init(

                logDir,
                "barcode_scanner_kb_test.log",
                logTypes,
                false,
                logging_history_ON );

    if( ! ll )
    {
        QMessageBox::warning(0,
                  QObject::tr("Ошибка"),
                  QObject::tr("Не удалось создать файл лога bit_driver_kkt.log в каталоге  %1")
                  .arg( logDir ));
        //std::cerr << "err:log file is not created(open)" << std::endl;
        return 0;
    }


    qInstallMsgHandler(logging_System::logCatcher);

    //std::cout << "main appalication logging system is started ok" << std::endl; // это пойдет на сервер starter ему в лог (через out)

    // -----------------------------------------------------------------------

    a.setStyleSheet( add_QDialog_Styles() );


    qWarning() << "start application";
    Scan_Code_Dlg w;

    w.setModal( false );

    w.show();
    
    return a.exec();
}



const QString add_QDialog_Styles()
{
    QSize sz = QSize(1000, 800);//myGui::screen_size();

    int maxH = sz.height();
    int maxW = sz.width();

    int hh07 = floor( (double) maxH * 0.7 );
    int hh09 = floor( (double) maxH / 1.1 );

    int ww07 = floor( (double) maxW *0.7);

    int ww = qMin( hh07  ,  ww07  );

    int ww09 =floor( (double) maxW * 0.9  );




    return
            "QDialog{\n"\
            "   min-height: "+QString::number( hh07 )+"px;\n"\
            "   max-height: "+QString::number( hh09 )+"px;\n"\
            "   min-width: "+QString::number(ww)+"px;\n"\
            "   max-width: "+QString::number( ww09 )+"px;\n"\
            "   background: #eee;\n"\
            "   font-size: 20px;\n"\
            "   border-radius:10px;\n"\
            "}\n" \

            "QPushButton{\n"\
            "   padding: 10px;\n"\
            "   background: #fffcde;\n"\
            "   border-radius:3px;\n"\
            "   border:3 solid white;\n"\
            "   font-size: 16px;\n"\
            "}\n" \
            "QPushButton:hover{\n"\
            "   border:3 solid green;\n"\
            "}\n" \

            "QLineEdit{\n"\
            "   font-size: 16px;\n"\
            "}\n" \

            "QCheckBox{\n"\
            "   font-size: 16px;\n"\
            "}\n" \

            "QComboBox{\n"\
            "   font-size: 16px;\n"\
            "}\n" \

            "QGroupBox, QLabel{\n"\
            "   font-size: 16px;\n"\
            "}\n" \

            "Smart_Process_Dlg{\n"\
            "   font-size: 16px;\n"\
            "}\n"

            "QSizeGrip {"\
            "   /*image: url(:/images/sizegrip.png);*/"\
                "width: 26px;"\
                "height: 26px;"\
                "color: red;"\
            "}\n"

            "#dialogTopFrame{\n"\
            "   font-size: 16px;\n"\
            "   /*padding-left: 15px;\n"\
            "   padding-right: 15px;*/\n"\
            "   /*border-radius: 5px;*/\n"\
            "   border-width: 20px;\n"\
            "   border-color: #ccc;\n"\
            "   background: #ddd;\n"\
            "   border-style: solid;\n"\

            "   /*border-left: 40px solid black;\n"\
            "   border-top: 40px solid black;\n"\
            "   border-right: 40px solid black;\n"\
            "   border-bottom: 40px solid black;\n"\
            "   border-left-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(240, 240, 240));\n"\
            "   border-right-color: qlineargradient(x1:1, y1:, x2:0, y2:0, stop:0 rgb(195,195,195), stop: 1 rgb(240, 240, 240));\n"\
            "   border-top-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 rgb(195,195,195), stop: 1 rgb(240, 240, 240));\n"\
            "   border-bottom-color: qlineargradient(x1:0, y1:1, x2:0, y2:0, stop: 0 rgb(195,195,195), stop: 1 rgb(240, 240, 240));\n"\
            "  */ background-color: rgb(240, 240, 240);\n"\
            "}\n"

           ;
    /*
    "   border-radius:25px;\n"\
            "   border-color: 7880bf;\n"\
            */
}
