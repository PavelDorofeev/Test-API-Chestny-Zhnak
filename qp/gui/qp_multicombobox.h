#ifndef QP_MULTICOMBOBOX_H
#define QP_MULTICOMBOBOX_H

#include <QComboBox>
#include <QStandardItem>
#include <QMouseEvent>
#include <QBitArray>
#include <QList>

//#include "equipment/a_subdirs/abstract_kkt/a_kkt.h"
//#include "equipment/a_subdirs/abstract_kkt/qp_treeitem_2.h"

class Qp_TreeItem_2;
class QpMultiComboBoxItemsDelegate;

#include "qp/gui/dll_qp_gui_global.h"
class LIB_PREFIX_QP_GUI QpMultiComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit QpMultiComboBox(QWidget *parent = 0);

    virtual ~QpMultiComboBox();
    
    void clearAllBits();

    void set_MaxBitsNumberSelecting(int maxNum);

    bool fill_bitsMaskContent( const QHash<int,QString> & lst , const uint currVa);

    void wheelEvent(QWheelEvent *event);

    Qp_TreeItem_2 * treeItem;


    bool set_mask_bits( const uint currVal ) ;
    bool set_mask_bits_2( const uint currVal ) ;
    void setBitNumber( int bitNumber , int val) ;
    //void mousePressEvent( QMouseEvent *evt );

    uint get_complexValue() const;

    //void mouseReleaseEvent( QMouseEvent *evt );
    //void keyPressEvent(QKeyEvent *evt);
    //void inputMethodEvent(QInputMethodEvent *evt);

    void set_selectable( bool bb);

    friend LIB_PREFIX_QP_GUI QDebug operator<<(QDebug d,const QpMultiComboBox &cmb);

    void setCheckedItem(const int item) const;

public slots:
    void slot_something_changed();

signals:

    void sig_something_changed();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);


private slots:

private:

    bool selectable;

    QpMultiComboBoxItemsDelegate * dlgt;


};

#endif // QP_MULTICOMBOBOX_H
