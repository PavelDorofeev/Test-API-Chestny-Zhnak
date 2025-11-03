#ifndef QP_PRETTY_DLG_H
#define QP_PRETTY_DLG_H

#include <QDialog>
#include <QFrame>


#include "qp/gui/dll_qp_gui_global.h"

class LIB_PREFIX_QP_GUI QpPrettyDlg : public QDialog
{
    Q_OBJECT
public:
    explicit QpPrettyDlg(QWidget *parent = 0);

    static int show_pretty_dlg_with_transparency_sides( QWidget * wgtInto);
    
signals:
    
};

#endif // QP_PRETTYDLG_H
