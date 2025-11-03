#ifndef TRANSPARENCY_DLG_SIDES_H
#define TRANSPARENCY_DLG_SIDES_H

#include <QDialog>

namespace Ui {
class Transparency_Dlg_Sides;
}

#include "qp/gui/dll_qp_gui_global.h"

class LIB_PREFIX_QP_GUI Transparency_Dlg_Sides : public QDialog
{
    Q_OBJECT
    
public:
    explicit Transparency_Dlg_Sides( QWidget *parent = 0 , bool DeleteCentralWgtOnExit = true );
    ~Transparency_Dlg_Sides();

    void adjustSize();
    QSize minimumSizeHint( ) const;
    QSize sizeHint( ) const;

    void set_centralWidget( QWidget * wgt);
    void set_margins( int width, int height);
    void set_proportions( int ww1, int ww2, int ww3, int hh1, int hh2, int hh3 );

    void repaintCental();

    static int showWithTransparentWrapperDlg( QDialog * centralWgt, bool DeleteCentralWgtOnExit= false, int stretch=1);

    int ret_result;
    
public Q_SLOTS:

private:
    Ui::Transparency_Dlg_Sides *ui;
    QWidget *parentWdg;
    QWidget *centralWgt;
    bool deleteCentralWgtOnExit;
    //QWidget * wgtOldParent;
};

#endif // TRANSPARENCY_DLG_SIDES_H
