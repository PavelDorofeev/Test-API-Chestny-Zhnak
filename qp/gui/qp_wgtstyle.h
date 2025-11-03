#ifndef QP_WGTSTYLE_H
#define QP_WGTSTYLE_H

#include <QString>
#include <QSize>

#include "qp/gui/dll_qp_gui_global.h"

class LIB_PREFIX_QP_GUI QpWgtStyle
{
public:
    QpWgtStyle();

    static const QString grayBlueCloudsColor;
    static const QString lightYellowColor;

    static QString get_dark_frame_style( );
    static QString get_light_frame_style( );
    static QString get_tableview_style( );
    static QString get_QScrollArea_style( );
    static QString get_button_style( );

    static QSize get_icon_size_for_tabWidget();

    static QString add_QTabWidget_Styles( int emSz = QpWgtStyle::fontHeight(),
                                          const QString &unit = "px",
                                          const QString &background = grayBlueCloudsColor,
                                          const QString &foreground = lightYellowColor,
                                          const QString &tabUnselected = "#888");

    static QString add_Msg_Dialog_Styles( int emSz = QpWgtStyle::fontHeight(),
                                          const QString &unit = "px",
                                          const QString &background = grayBlueCloudsColor,
                                          const QString &bordercolor = "blue",
                                          const QString &tabUnselected = "#888");

    static QString add_QPushButton_Styles( int emSz = QpWgtStyle::fontHeight(),
                                          const QString &unit = "px",
                                          const QString &background = grayBlueCloudsColor,
                                          const QString &bordercolor = "blue",
                                          const QString &tabUnselected = "#888");

    static QString add_QLineEdit_Styles( int emSz = QpWgtStyle::fontHeight(),
                                           const QString &unit = "px",
                                           const QString &background = grayBlueCloudsColor,
                                           const QString &bordercolor = "blue",
                                           const QString &tabUnselected = "#888");

    static QString add_CheckBox_Styles( int emSz = QpWgtStyle::fontHeight(),
                                          const QString &unit = "px",
                                          const QString &background = grayBlueCloudsColor,
                                          const QString &bordercolor = "blue",
                                          const QString &tabUnselected = "#888");

    static QString add_QDialog_Styles(int emSz = QpWgtStyle::fontHeight(),
                                      const QString &unit = "px",
                                      const QString &background = grayBlueCloudsColor,
                                      const QString &foreground = lightYellowColor,
                                      const QString &tabUnselected = "#888");

    static QString add_QGroupBox_Styles(int emSz = QpWgtStyle::fontHeight(),
                                      const QString &unit = "px",
                                      const QString &background = grayBlueCloudsColor,
                                      const QString &foreground = lightYellowColor,
                                      const QString &tabUnselected = "#888");

    static int fontHeight();
};

#endif // QPWGTSTYLE_H
