#include "qp_prettydlg.h"

#include "transparency_dlg_sides.h"
#include "qp/gui/qp_gui.h"

QpPrettyDlg::QpPrettyDlg(QWidget *parent) :
    QDialog(parent)
{

}

int QpPrettyDlg::show_pretty_dlg_with_transparency_sides( QWidget * wgtInto)
{
    Transparency_Dlg_Sides dlg ( 0 );

    dlg.setAttribute( Qt::WA_TranslucentBackground );

    qp::gui::setWindow_woTitle__woFrame_woToolsBtn( &dlg );


    dlg.set_centralWidget( wgtInto );

    dlg.showMaximized();

    int res = dlg.exec();

    return res ;
}


