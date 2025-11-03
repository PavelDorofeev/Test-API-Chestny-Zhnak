#include "qp_multicombobox.h"

#include <QStylePainter>
#include <QMouseEvent>
#include <QDebug>
#include "qp/gui/qpmulticomboboxitemsdelegate.h"
//#include "abstract_kkt/qp_treeitem_2.h"


QpMultiComboBox::QpMultiComboBox(QWidget *parent) :
    QComboBox(parent)
  ,selectable(true)
{
    //setStyleSheet("QComboBox { combobox-popup: 1px }");
    dlgt = new QpMultiComboBoxItemsDelegate( this );

    setItemDelegate( dlgt );

}


QpMultiComboBox::~QpMultiComboBox()
{
}

void QpMultiComboBox::set_MaxBitsNumberSelecting(int maxNum)
{
    dlgt->checkedBitsLimit = maxNum;
}

void QpMultiComboBox::wheelEvent(QWheelEvent *event)
{

}
//void QpMultiComboBox::mousePressEvent( QMouseEvent *evt )
//{
//    // сработка при выпадании списка  ( клик по стрелке вниз)
////    if( ! selectable )
////        return;

//    qDebug() << "QpMultiComboBox::mousePressEvent:" <<evt->pos();
//    QComboBox::mousePressEvent(evt);
//}

//void QpMultiComboBox::mouseReleaseEvent( QMouseEvent *evt )
//{
//    // сработка при сворачивании выпавшего списка ( клик по стрелке вниз)

////    if( ! selectable )
////        return;

//    qDebug() << "QpMultiComboBox::mouseReleaseEvent:" <<evt->pos();

//    QComboBox::mouseReleaseEvent(evt);

//}

//void QpMultiComboBox::keyPressEvent(QKeyEvent *evt)
//{
//    if( ! selectable )
//        return;


//    qDebug() << "QpMultiComboBox::keyPressEvent text:" <<evt->text();

//    QComboBox::keyPressEvent(evt);

//}

//void QpMultiComboBox::inputMethodEvent(QInputMethodEvent *evt)
//{

//    qDebug() << "QpMultiComboBox::inputMethodEvent :"
//                // <<evt->attributes()
//             << evt->preeditString()
//             << evt->commitString()
//             << "currentIndex" << currentIndex()
//                ;


//    QComboBox::inputMethodEvent(evt);

//}



void QpMultiComboBox::slot_something_changed()
{
    //repaint();

    emit sig_something_changed();
}

bool QpMultiComboBox::fill_bitsMaskContent( const QHash<int,QString> & ll , const uint currVal)
{
    QHash<int,QString>::ConstIterator  it2 = ll.constBegin();

    while( it2 != ll.constEnd() )
    {
        int val = 1 << it2.key(); // номер бита

        addItem( it2.value() , val );

        it2++;
    }

    set_mask_bits( currVal );


    return true;
}

bool QpMultiComboBox::set_mask_bits( const uint newVal )
{

    uint oldVal = get_complexValue();

    clearAllBits();

    uint ii = newVal;

    for(int bitNumber = 0; bitNumber< 32; bitNumber++) // по битам идем
    {
        if( ii & 0x01)
        {
            int tt = 1 << ii;
            setCheckedItem( tt );
        }

        ii = ii >> 1;
    }

    if( newVal != oldVal)
        emit sig_something_changed();

    return true;
}
void QpMultiComboBox::setCheckedItem( const int dataVal) const
{
    int foundIndex = findData( dataVal );

    Q_ASSERT(foundIndex>=0);

    QStandardItemModel *standartModel = qobject_cast<QStandardItemModel*>(model());

    if ( foundIndex >=0 )
    {
        standartModel->item( foundIndex )->setData( Qt::Checked, Qt::CheckStateRole );
    }
}

bool QpMultiComboBox::set_mask_bits_2( const uint newVal )
{
    /*
      на входе число из нескольких установленных бит
    */
    uint oldVal = get_complexValue();

    clearAllBits();

    uint ii = newVal;

    for(int bitNumber = 0; bitNumber< 32; bitNumber++) // по битам идем
    {
        if( ii & 0x01)
        {
            setBitNumber( bitNumber , 1 );
        }

        ii = ii >> 1;
    }

    if( newVal != oldVal)
        emit sig_something_changed();

    return true;
}

void QpMultiComboBox::setBitNumber( int bitNumber , int val)
{
    int foundIndex = findData( bitNumber );

    Q_ASSERT(foundIndex>=0);



    if ( foundIndex >=0 )
    {
        QStandardItemModel *standartModel = qobject_cast<QStandardItemModel*>(model());

        if( val ==1 )
            standartModel->item( foundIndex )->setData( Qt::Checked, Qt::CheckStateRole );
        else
            standartModel->item( foundIndex )->setData( Qt::Unchecked, Qt::CheckStateRole );
    }
}



uint  QpMultiComboBox::get_complexValue() const
{

    QStandardItemModel *mdl = qobject_cast<QStandardItemModel*>(model());

    Q_ASSERT ( mdl !=0);

    uint retVl=0;

    for (int idx = 0; idx < mdl->rowCount(); idx++ )
    {
        QModelIndex idx0 = mdl->index( idx , 0 );

        bool checked = mdl->data( idx0 , Qt::CheckStateRole).toBool();

        if( checked )
        {
            QVariant vData = itemData( idx );

            bool ok;
            int bitVal = vData.toUInt( &ok ); // это значение бита

            Q_ASSERT(ok==true);

            int iVl = 1 << bitVal; // !!!!!!

            retVl += iVl;
        }
    }

    return retVl;
}

void  QpMultiComboBox::clearAllBits()
{
    QStandardItemModel *mdl = qobject_cast<QStandardItemModel*>(model());

    for (int i = 0; i < mdl->rowCount(); ++i)
    {
        QModelIndex index = mdl->index( i , 0 );

        bool bb = mdl->setData( index , Qt::Unchecked, Qt::CheckStateRole);

        Q_ASSERT( bb ==true);
    }
    //emit sig_something_changed();
    //repaint();

}


void QpMultiComboBox::paintEvent(QPaintEvent *event)
{

    QStandardItemModel *mdl = qobject_cast<QStandardItemModel*>(model());

    QString str;

    for (int i = 0; i < mdl->rowCount(); ++i)
    {
        QModelIndex index = mdl->index( i , 0 );

        bool checked = mdl->data( index , Qt::CheckStateRole).toBool();


        if( checked )
        {
            if(! str.isEmpty())
                str.append(",");

            str.append( itemText( i ));
        }

    }

    QStyleOptionComboBox opt;
    initStyleOption(&opt);

    QStylePainter p(this);
    p.drawComplexControl(QStyle::CC_ComboBox, opt);

    QRect textRect = style()->subControlRect(QStyle::CC_ComboBox, &opt, QStyle::SC_ComboBoxEditField, this);
    opt.currentText = p.fontMetrics().elidedText( str , Qt::ElideRight, textRect.width());
    p.drawControl(QStyle::CE_ComboBoxLabel, opt);

    //QComboBox::paintEvent( event);

}

void QpMultiComboBox::resizeEvent(QResizeEvent *event)
{
}


void QpMultiComboBox::set_selectable( bool bb)
{
    selectable = bb;

    //dlgt->set

    QStandardItemModel * mdl = qobject_cast<QStandardItemModel *>(model());

    if( ! mdl )
        return;

    for( int row=0; row < mdl->rowCount(); row++ )
    {
        QStandardItem *item = mdl->item( row );

        //        if( ! item )
        //            return;

        Qt::ItemFlags flgs = item->flags();

        if( selectable )
        {
            flgs |= Qt::ItemIsEnabled;
            flgs |= Qt::ItemIsSelectable;
            flgs |= Qt::ItemIsEditable;
            flgs |= Qt::ItemIsUserCheckable;
            flgs |= Qt::ItemIsDragEnabled;
            flgs |= Qt::ItemIsDropEnabled;
        }
        else
        {
            flgs &= ~Qt::ItemIsEnabled;
            flgs &= ~Qt::ItemIsSelectable;
            flgs &= ~Qt::ItemIsEditable;
            flgs &= ~Qt::ItemIsUserCheckable;
            flgs &= ~Qt::ItemIsDragEnabled;
            flgs &= ~Qt::ItemIsDropEnabled;
        }

        item->setFlags ( flgs ) ;

        //qDebug() << "set_selectable flgs:" << flgs;
    }

    return;

}

QDebug operator<<(QDebug d,const QpMultiComboBox &cmb) {

    d << "\n------------------ QpMultiComboBox -------------------";

    for( int ii=0; ii < cmb.count(); ii++)
    {
        d << "\n\t "<< ii << " : " << cmb.itemData( ii )<< cmb.itemText( ii );
    }

    d << "\n-------------------------------------------------";

    return d;
}
