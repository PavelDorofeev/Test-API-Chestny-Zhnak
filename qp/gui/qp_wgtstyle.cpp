#include "qp_wgtstyle.h"

#include <QApplication>
#include <QFont>
#include <QFontMetrics>


const QString QpWgtStyle::grayBlueCloudsColor = QString::fromUtf8("#cad4f1");
const QString QpWgtStyle::lightYellowColor = QString::fromUtf8("#f3f3e6");

QpWgtStyle::QpWgtStyle()
{
}


int QpWgtStyle::fontHeight()
{
    QFontMetrics mtr(  QApplication::font() );


    return mtr.height();
}

QSize QpWgtStyle::get_icon_size_for_tabWidget()
{
    int emSz = QpWgtStyle::fontHeight();
    int sz = emSz*1.5;
    return QSize( sz , sz );
}

QString QpWgtStyle::get_dark_frame_style( )
{
    int emSz = QpWgtStyle::fontHeight();
    QString em1 = QString::number(emSz);
    QString unit = "px";

    /*
        внимание: обрамляем в QFrame{ - почему ?
        потому что только для QFrame беде распространяться
        инеаче бедет для всех вообще виджетов - понятно?
        и для QPushButton и для всех других, потомков текущего виджета,
        которому устанавливается setStyleSheet - понятно?
    */
    return ""\
            ".QFrame{\n"\
            "    background:  "+QpWgtStyle::grayBlueCloudsColor+";\n"\
            "    border-radius:"+em1+unit+";\n"\
            "}\n"
            ;
}

QString QpWgtStyle::get_light_frame_style( )
{
    int emSz = QpWgtStyle::fontHeight();
    QString em1 = QString::number(emSz);
    QString unit = "px";

    /*
        внимание: обрамляем в QFrame{ - почему ?
        потому что только для QFrame беде распространяться
        инеаче бедет для всех вообще виджетов - понятно?
        и для QPushButton и для всех других, потомков текущего виджета,
        которому устанавливается setStyleSheet - понятно?
    */
    return ""\
            ".QFrame{\n"\
            "    background:  "+QpWgtStyle::lightYellowColor+";\n"\
            "    border-radius:"+em1+unit+";\n"\
            "}\n"
            ;
}

QString QpWgtStyle::get_QScrollArea_style( )
{
    int emSz = QpWgtStyle::fontHeight();
    QString em1 = QString::number(emSz);
    QString unit = "px";

    /*
    */
    return ""\
            ".QScrollArea{\n"\
            "    background:  "+QpWgtStyle::lightYellowColor+"   ;\n"\
            "}\n"
            ;
}

QString QpWgtStyle::get_tableview_style( )
{
    int emSz = QpWgtStyle::fontHeight();
    QString em1 = QString::number(emSz);
    QString unit = "px";

    return ""\
            "QTableView{\n"\
            "    background:  #eeeeee;\n"\
            "    border-radius:"+em1+unit+";\n"\
            "}\n"
            ;
    /*
        темный фон хэдера
    "QHeaderView::section{\n"\
    "    background:  #555555;\n"\
    "    color:  #eeeeee;\n"\
    "    padding:  "+em1+unit+";\n"\
    "}\n"

    QHeaderView::section:checked
     {
         background-color: red;
     }

     / стиль индикатора сортировки
     QHeaderView::down-arrow {
         image: url(down_arrow.png);
     }

     QHeaderView::up-arrow {
         image: url(up_arrow.png);
     }
    */
}


QString QpWgtStyle::get_button_style( )
{
    int emSz = QpWgtStyle::fontHeight();
    QString unit = "px";

    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);
    QString em04 = QString::number(emSz*0.4);


    return "\n"\

            "QPushButton{\n"\
            "   padding:"+em03+unit+" "+em1+unit+";\n"\
            "   margin:"+em02+unit+" "+em1+unit+";\n"\
            "   color: #7aa489;\n"\
            "   border-radius:"+em04+unit+";\n"\
            "   outline:none;\n"\
            "   border-style:solid;\n"\
            "   border-width: "+em02+unit+";\n"\
            "   border-radius: 10px;\n"\
            "   border-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 10, stop: 0 #CCCCCC, stop: 1 #AAAAAA);\n"\
            "}\n"\

            "QPushButton:enabled:hover{\n"\
            "   border:"+em02+unit+" solid green;\n"\
            "}\n"\

            "QPushButton:pressed{\n"\
            "   border:"+em02+unit+" solid red;\n"\
            "}\n"\

            "QPushButton:enabled{\n"\
            "   background:#7aa489;\n"\
            "   color:white;\n"\
            "}\n"\

            "QPushButton:!enabled{\n"\
            "   background:gray;\n"\
            "   color:white;\n"\
            "}\n"
            ;
}

QString QpWgtStyle::add_QTabWidget_Styles( int emSz,
                                           const QString &unit,
                                           const QString &background,
                                           const QString &foreground,
                                           const QString &tabUnselected)
{
    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);

    /*
    "   background:transparent; \n"\

    "QTabWidget::pane{\n"\
    "   outline:none;\n"\
    "   background: "+background+";\n"\
    "}\n"\
    */
    return ""\
            "\nQTabWidget{\n"\
            "   outline:none;\n"\
            "}\n"\

            "QTabWidget::tab-bar:top{\n"\
            "   left:"+em2+unit+"; \n"\
            "   right:"+em2+unit+"; \n"\
            "}\n"\


            "#frame_light{\n"\
            "    background:  "+foreground+";\n"\
            "    border-radius:"+em1+unit+";\n"\
            "}\n"\

            "#frame_light2{\n"\
            "    background: "+foreground+";\n"\
            "    border-radius:"+em1+unit+";\n"\
            "}\n"\

            "#frame_light3{\n"\
            "    background: blue;\n"\
            "    border-radius:"+em1+unit+";\n"\
            "}\n"\

            "QWidget > QTabWidget:pane{\n"\
            "    background: "+foreground+";\n"\
            "    padding-left:"+em05+unit+";  \n"\
            "    padding-right:"+em05+unit+";  \n"\
            "    padding-bottom:"+em05+unit+";  \n"\
            "    margin:0px;  \n"\
            "    border-radius:"+em05+unit+";\n"\
            "}\n"\

            "QTabBar{\n"\
            "   outline:none;\n"\
            "   margin:0px;\n"\
            "   border:0 thin transparent;\n"\
            "   border-color:transparent;\n"\
            "   border-width: 0"+unit+";\n"\
            "}\n"\

            "QTabBar::tab{\n"\
            "   outline:none;\n"\
            "   padding:"+em05+unit+" "+em05+unit+";\n"\
            "   border:0"+unit+" thin transparent;\n"\
            "   border-color:transparent;\n"\
            "   border-width: 0"+unit+";\n"\

            "}\n"\

            "QTabBar::tab:selected{\n"\
            "   border:0px;\n"\
            "   border-color:transparent;\n"\
            "   border-width: 0px;\n"\
            "   background: "+foreground+";\n"\
            "}\n"\

            "QTabBar::tab:!selected{\n"\
            "   border-bottom:0px;\n"\
            "   background: #e2f0c9;\n"\
            "   color: "+tabUnselected+";\n"\
            "}\n"\

            "QTabBar::tab:top:first{\n"\
            "   margin-left:"+em03+unit+";\n"\
            "}\n"\

            "QTabBar::tab:top{\n"\
            "   border-top-left-radius:"+em05+unit+";\n"\
            "   border-top-right-radius:"+em05+unit+";\n"\
            "   background:transparent;\n"\
            "   margin-right:"+em1+unit+";   \n"\
            "   border:0"+unit+";\n"\
            "}\n"\


            "QTabBar::tab:top:selected {\n"\
            "   border-bottom: 0"+unit+"; \n"\
            "   margin-top:"+em02+unit+";\n"\
            "   background: "+foreground+";\n"\
            "}\n"\

            "QTabBar::tab:top:!selected {\n"\
            "   border-bottom: 1"+unit+"; \n"\
            "   margin-top:"+em05+unit+";\n"\
            "   background: #e2f0c9;\n"\
            "}\n"\


            "QTabBar::tab:right{\n"\
            "   padding:"+em1+unit+";    \n"\
            "   margin-top:"+em05+unit+";    \n"\
            "   border-top-left-radius:"+em1+unit+";\n"\
            "   border-bottom-left-radius:"+em1+unit+";\n"\
            "}\n"\

            "QTabBar::tab:right:first{\n"\
            "   margin-top:"+em05+unit+";   \n"\
            "}\n"\

            "QTabBar::tab:right:last{\n"\
            "   margin-bottom:"+em2+unit+";  \n"\
            "}\n"\

            "QTabBar::tab:right:selected {\n"\
            "   margin-left:"+em05+unit+";    \n"\
            "}\n"\

            "QTabBar::tab:right:!selected {\n"\
            "   margin-left:"+em1+unit+";    \n"\
            "}\n"\

/*

        QTabBar::tab {
             background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                         stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,
                                         stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);
             border: 2px solid #C4C4C3;
             border-bottom-color: #C2C7CB;
             border-top-left-radius: 4px;
             border-top-right-radius: 4px;
             min-width: 8ex;
             padding: 2px;
         }
*/

            ;

}

QString QpWgtStyle::add_Msg_Dialog_Styles( int emSz,
                                           const QString &unit,
                                           const QString &background,
                                           const QString &bordercolor,
                                           const QString &tabUnselected)
{
    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);

    return "\n"\
            "#dialogTopFrame{\n"\
            "   background:"+background+"; \n"\
            "   border-radius:"+em1+unit+";\n"\
            "   border-color:"+bordercolor+";\n"\
            "   border-width: "+em1+unit+";\n"\
            "   padding:"+em2+unit+";\n"\
            "}\n"\
            ;

}
QString QpWgtStyle::add_QPushButton_Styles( int emSz,
                                           const QString &unit,
                                           const QString &background,
                                           const QString &bordercolor,
                                           const QString &tabUnselected)
{
    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);
    QString em04 = QString::number(emSz*0.4);

    return "\n"\

            "QPushButton{\n"\
            "   padding:"+em05+unit+" "+em1+unit+";\n"\
            "   margin:"+em02+unit+" "+em1+unit+";\n"\
            "   color: #7aa489;\n"\
            "   border-radius:"+em04+unit+";\n"\
            "   outline:none;\n"\
            "   border-style:solid;\n"\
            "   border-width: "+em02+unit+";\n"\
            "   border-radius: 10px;\n"\
            "   border-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 10, stop: 0 #CCCCCC, stop: 1 #AAAAAA);\n"\
            "}\n"\

            "QPushButton:enabled:hover{\n"\
            "   border:"+em02+unit+" solid green;\n"\
            "}\n"\

            "QPushButton:pressed{\n"\
            "   border:"+em02+unit+" solid red;\n"\
            "}\n"\

            "QPushButton:enabled{\n"\
            "   background:#7aa489;\n"\
            "   color:white;\n"\
            "}\n"\

            "QPushButton:!enabled{\n"\
            "   background:gray;\n"\
            "   color:white;\n"\
            "}\n"
            ;

}

QString QpWgtStyle::add_QLineEdit_Styles( int emSz,
                                            const QString &unit,
                                            const QString &background,
                                            const QString &bordercolor,
                                            const QString &tabUnselected)
{
    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);
    QString em04 = QString::number(emSz*0.4);

    return "\n"\

            ".QLineEdit{\n"\
            "   padding:"+em02+unit+" "+em05+unit+";\n"\
            "   border-radius:"+em03+unit+";\n"\
            "   outline:none;\n"\
            "   text-align: left;\n"\
            "}\n"\
            ;

}
QString QpWgtStyle::add_CheckBox_Styles( int emSz,
                                           const QString &unit,
                                           const QString &background,
                                           const QString &bordercolor,
                                           const QString &tabUnselected)
{
    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);
    QString em04 = QString::number(emSz*0.4);

    return "\n"\

            "QCheckBox{\n"\
            "   padding:"+em03+unit+" "+em1+unit+";\n"\
            "   margin:"+em02+unit+" "+em1+unit+";\n"\
            "   color: #7aa489;\n"\
            "   border-radius:"+em04+unit+";\n"\
            "   outline:none;\n"\
            "   border-style:solid;\n"\
            "   border-width: "+em02+unit+";\n"\
            "   border-radius: 10px;\n"\
            "   border-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 10, stop: 0 #CCCCCC, stop: 1 #AAAAAA);\n"\
            "}\n"\

            "QCheckBox:enabled{\n"\
            "   border:"+em02+unit+" solid green;\n"\
            "}\n"\

            "QCheckBox::indicator:checked{\n"\
            "   border:"+em02+unit+" solid red;\n"\
            "}\n"\

            "QCheckBox:!checked{\n"\
            "   background:#7aa489;\n"\
            "   color:white;\n"\
            "}\n"\

            ;

}
QString QpWgtStyle::add_QGroupBox_Styles( int emSz,
                                         const QString &unit,
                                         const QString &background,
                                         const QString &bordercolor,
                                         const QString &tabUnselected)
{
    QString em2 = QString::number((int)emSz*2);
    QString em05 = QString::number(( int)emSz/2 );
    QString em1 = QString::number(emSz);
    QString em02 = QString::number(emSz*0.2);
    QString em03 = QString::number(emSz*0.3);
    QString em04 = QString::number(emSz*0.4);

    return "\n"\

            "QGroupBox{\n"\
            "   padding:"+em03+unit+" "+em1+unit+";\n"\
            "   border-color: #777777;\n"\
            "   border-style:solid;\n"\
            "   border-width: 2px;\n"\
            "   padding-top: "+em1+unit+";\n"\
            "   border-radius:"+em1+unit+";\n"\
            "}\n"\

            "QGroupBox::title{\n"\
            "   background-color: transparent;\n"\
            "   padding-top: "+em05+unit+";\n"\
            "   padding-left: "+em1+unit+";\n"\
            "}\n"

            ;

}


QString QpWgtStyle::add_QDialog_Styles( int emSz,
                                        const QString &unit,
                                        const QString &background,
                                        const QString &foreground,
                                        const QString &tabUnselected)
{

    //    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #e7effd, stop: 1 #cbdaf1);\n"\
    // "   border-style: outset;\n"\
//    "   border-radius:20px;\n"\

    return  "\n"\
            "#frame_dark{\n"\
            "   background: "+background+";\n"\
            "   border-width: 15px;\n"\
            "   border-color:#888888 ;\n"\
            "}\n"\
            "#topFrameEqptWgt{\n"\
            "   background: gray;\n"\
            "   padding:25px;\n"\
            "   border-width: 15px;\n"\
            "   border-radius: 10px;\n"\
            "   border-color: blue;\n"\
            "}\n"\

            "\n"\
            "#dialogTopFrame{\n"\
            "   background: "+background+";\n"\
            "   padding:25px;\n"\
            "   border-radius: 10px;\n"\
            "}\n"\
            "\n" \
            "/*\n"\
            "не работает QDialog>dialogTopFrame\n"\
            "не работает QDialog#dialogTopFrame\n"\
            "не работает Smart_Process_Dlg\n"\
            "не работает QDialog#Smart_Process_Dlg\n"\
            "не работает #Smart_Process_Dlg\n"\
            "не работает Smart_Process_Dlg\n"\
            "не работает Widget>Smart_Process_Dlg\n"\
            "не работает Widget#Smart_Process_Dlg\n"\
            "*/\n"\
            "QMessageBox{\n"\
            "   messagebox-text-interaction-flags: 5;\n"\
            "   dialog-ok-icon: url(:eqpt/connection-on.svg);\n"\
            "   dialog-cancel-icon: url(cancel.png), url(grayed_cancel.png) disabled;\n"\
            "}\n"\
            "#qt_msgbox_label{\n"\
            "   background: "+background+";\n"\
            "   padding:25px;\n"\
            "   border-width: 15px;\n"\
            "   border-radius: 10px;\n"\
            "   border-color: blue;\n"\
            "   wordwrap: true;\n"\
            "}\n"\
            "#qt_msgboxex_icon_label{\n"\
            "   background: transparent;\n"\
            "}\n"\
            "#qt_msgbox_buttonbox{\n"\
            "   qproperty-centerButtons: true;\n"\
            "   background-color: green;\n"\
            "}\n"\
            ;
}
