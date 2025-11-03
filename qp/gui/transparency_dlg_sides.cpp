#include "transparency_dlg_sides.h"
#include "ui_transparency_dlg_sides.h"

#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>
#include <QGraphicsDropShadowEffect>
#include <QApplication>
#include <QDesktopWidget>
#include <QDialog>

#include "qp/gui/qp_gui.h"

Transparency_Dlg_Sides::Transparency_Dlg_Sides( QWidget *parent, bool DeleteCentralWgtOnExit) :
    QDialog(parent),
    ui(new Ui::Transparency_Dlg_Sides),
    parentWdg( parent ),
    centralWgt(0)
{
    ui->setupUi(this);

    /*
      -------------------------------------------------------------------------------
        НЕ В КОЕМ СЛУЧАЕ НЕ УСТАНАВЛИВАЙ ГЛОБАЛЬНО СТИЛЯМ QDialog min/max размеры
        ИНАЧЕ ЗДЕСЬ ПPОТPАХАЕШЬ ВСЕ МОЗГИ !!!
      -------------------------------------------------------------------------------
    */

    deleteCentralWgtOnExit = DeleteCentralWgtOnExit; // для деструктора сохраняем


    setAttribute( Qt::WA_TranslucentBackground);
    // все окно прозрачно, но центральный виджет будет не прозрачным, если opacity не включено
//    setWindowOpacity(1.8);

    qp::gui::setWindow_woTitle__woFrame_woToolsBtn( this );

    //set_centeralWidget( centralWgt );

    /*
        Blur: если виджет сплошного цвета, то blur размывает виджет по краям
    */
    //    QGraphicsBlurEffect * blurR = new QGraphicsBlurEffect( this );
    //    blurR->setBlurRadius( 10 );

    //    QGraphicsBlurEffect * blurL = new QGraphicsBlurEffect( this );
    //    blurL->setBlurRadius( 10 );

    //    QGraphicsBlurEffect * blurT = new QGraphicsBlurEffect( this );
    //    blurT->setBlurRadius( 10 );

    //    QGraphicsBlurEffect * bluBL = new QGraphicsBlurEffect( this );
    //    bluBL->setBlurRadius( 10 );

    //    ui->frameTop->setGraphicsEffect( blurT );
    //    ui->frameBottom->setGraphicsEffect( bluBL );
    //    ui->frameLeft->setGraphicsEffect( blurL );
    //    ui->frameRight->setGraphicsEffect( blurR );

    //    QGraphicsBlurEffect * blur = new QGraphicsBlurEffect( this );
    //    blur->setBlurRadius( 10 );
    //    setGraphicsEffect( blur );


    QString str1 = ""\
            ".QFrame{\n"\
            "    background:  #cad4f1;\n"\
            "}\n"
            ;
    QString str2 = ""\
            ".QFrame{\n"\
            "    background:  transparent;\n"\
            "}\n"
            ;

    //    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect( this );
    //    shadow->setBlurRadius(19.0);
    //    shadow->setColor(QColor(0, 0, 0, 220));
    //    shadow->setOffset(8.0);
    //    ui->frameInCenter->setGraphicsEffect( shadow );


        QGraphicsOpacityEffect * opacT = new QGraphicsOpacityEffect( this );
        opacT->setOpacity( 0.5 );

        QGraphicsOpacityEffect * opacB = new QGraphicsOpacityEffect( this );
        opacB->setOpacity( 0.5 );

        QGraphicsOpacityEffect * opacL = new QGraphicsOpacityEffect( this );
        opacL->setOpacity( 0.5 );

        QGraphicsOpacityEffect * opacR = new QGraphicsOpacityEffect( this );
        opacR->setOpacity( 0.5 );

//        ui->frameRight->setStyleSheet( str2 );
//        ui->frameBottom->setStyleSheet( str2 );
//        ui->frameLeft->setStyleSheet( str2 );
//        ui->frameRight->setStyleSheet( str2 );

        ui->frameTop->setGraphicsEffect(  opacT );
        ui->frameBottom->setGraphicsEffect( opacB );
        ui->frameLeft->setGraphicsEffect( opacL );
        ui->frameRight->setGraphicsEffect( opacR );


        ui->frameTop->setAttribute( Qt::WA_TranslucentBackground );
        ui->frameBottom->setAttribute( Qt::WA_TranslucentBackground );
        ui->frameLeft->setAttribute( Qt::WA_TranslucentBackground );
        ui->frameRight->setAttribute( Qt::WA_TranslucentBackground );


//        QGraphicsBlurEffect *blur = new QGraphicsBlurEffect( this );
//        blur->setBlurRadius(10);
//        ui->frameRight->setGraphicsEffect( blur );

}


QSize Transparency_Dlg_Sides::sizeHint( ) const
{
    return parentWidget()->sizeHint();
}

QSize Transparency_Dlg_Sides::minimumSizeHint( ) const
{
    return parentWidget()->minimumSizeHint();
}

void Transparency_Dlg_Sides::adjustSize()
{
    qDebug() << "fake Transparency_Dlg_Sides::adjustSize()";
}

void Transparency_Dlg_Sides::set_centralWidget( QWidget * wgt)
{
    centralWgt = wgt;

    setObjectName( "wrapper for "+wgt->objectName() );

    qDebug() << "set_centeralWidget" << size();

    ui->VLO_INTO->addWidget( wgt );//, 1000 );

    qDebug() << "set_centeralWidget addWidget" << size();

    //update();

    //qDebug() << "set_centeralWidget update" << size();

    //adjustSize();

    //qDebug() << "set_centeralWidget adjustSize" << size();
}

Transparency_Dlg_Sides::~Transparency_Dlg_Sides()
{
    qDebug() << "~Transparency_Dlg_Sides objectName" <<objectName();

    if ( centralWgt !=0 && ! deleteCentralWgtOnExit )
    {
        //        QDialog *dd = findChild<QDialog*>("aaa");
        //centralWgt->setParent( wgtOldParent ); // просто устанавливаем ему предыдущего родителя, и это не сработает здеь

        // ui->VLO_INTO->removeWidget( centralWgt ); // открепляем и он не удалится и это не правда

        // qDebug() << "~Transparency_Dlg_Sides centralWgt->deleteLater()" ;
        //centralWgt->deleteLater();
        qDebug() <<"НЕ НАДО СПЕЦИАЛЬНО УДАЛЯТЬ, т.к. delete ui; сам удалит всех потомков";
    }

    delete ui;
}

void Transparency_Dlg_Sides::set_margins( int width, int height)
{
    ui->frameLeft->setMinimumWidth(width);
    ui->frameRight->setMinimumWidth(width);
    ui->frameTop->setMinimumHeight(height);
    ui->frameBottom->setMinimumHeight(height);
}

void Transparency_Dlg_Sides::repaintCental()
{
    ui->frameInCenter->update();
}

void Transparency_Dlg_Sides::set_proportions( int ww1, int ww2, int ww3, int hh1, int hh2, int hh3 )
{
    ui->horizontalLayout->setStretch( 0 , ww1 );
    ui->horizontalLayout->setStretch( 1 , ww2 );
    ui->horizontalLayout->setStretch( 2 , ww3 );

    ui->hl_center->setStretch( 0, hh1 );
    ui->hl_center->setStretch( 1, hh2 );
    ui->hl_center->setStretch( 2, hh3 );
}


int Transparency_Dlg_Sides::showWithTransparentWrapperDlg( QDialog * wgt , bool deleteCentralWgtOnExit, int stretch )
{

    /*
      -------------------------------------------------------------------------------
        НЕ В КОЕМ СЛУЧАЕ НЕ УСТАНАВЛИВАЙ ГЛОБАЛЬНО СТИЛЯМ QDialog min/max размеры
        ИНАЧЕ ЗДЕСЬ ПPОТPАХАЕШЬ ВСЕ МОЗГИ !!!
      -------------------------------------------------------------------------------
    */

    QWidget *wgtOldParent = wgt->parentWidget(); // запоминаем

    Transparency_Dlg_Sides wrapper (  wgt->parentWidget() , deleteCentralWgtOnExit);  // да работает так
    // если wgt->parentWidget() = 0 , то это отдельное окно создается
    // если wgt->parentWidget() != 0, то над окном родителем и при ALT-Tab выглядит едино


    //---------------------------------------------------
    //--------------------------------------------------

    wrapper.set_proportions( 10,stretch,10, 10,stretch,10);

    wrapper.set_centralWidget( wgt );

    wrapper.showMaximized(); //!!

    //wrapper.setModal( true ); // отрисовка сразу правильная
    //wgt->setModal( true ); //  поведение иное

    QApplication::setOverrideCursor(Qt::ArrowCursor);

    int res = wgt->exec();

    if( ! deleteCentralWgtOnExit )
    {
        wgt->setParent( wgtOldParent ); // восстанавливаем старого владельца виджета (или 0 как оно было)
        // и здесь это сработает Ура!
    }
    else
    {
        wgt->deleteLater();
    }
    // ------------------------------------------------------------------
    // таким образом при выходе Transparency_Dlg_Sides уничтожится (на стеке)
    // а wgt либо уничтожится , либо если deleteCentralWgtOnExit=true не уничтожится,
    // а только отвяжется от формы к старому родителю
    // ------------------------------------------------------------------
    //wrapper->deleteLater();
    // поскольку wgt включен в Transparency_Dlg_Sides,
    // в деструкторе Transparency_Dlg_Sides удалится wgt нормально

    return res;

}
