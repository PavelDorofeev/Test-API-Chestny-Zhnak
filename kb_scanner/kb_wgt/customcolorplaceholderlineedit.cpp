#include "customcolorplaceholderlineedit.h"
#include <QPainter>

CustomColorPlaceholderLineEdit::CustomColorPlaceholderLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    color = QColor(0,255,0,128);
}

void CustomColorPlaceholderLineEdit::paintEvent(QPaintEvent *evt)
{
    if( color.isValid()
            && ! text().isEmpty()
            //&& (!placeholderText().isEmpty() || !mText.isEmpty())
            )
    {

        // By this, we make sure Qt will paint QLineEdit default parts properly.
        QLineEdit::paintEvent( evt);

        // And now @Meefte code is reused here.
        QPainter p(this);

        p.setPen(color);

        QFontMetrics fm = fontMetrics();

        int minLB = qMax(0, -fm.minLeftBearing());

        QRect lineRect = this->rect();

        QRect ph = lineRect.adjusted(minLB + 3, 0, 0, 0);

        QString elidedText = fm.elidedText( text(), Qt::ElideRight, ph.width());

        p.drawText(ph, Qt::AlignVCenter, elidedText);
        return; // No need to paint again.
    }

    // Default Qt's painting behavior for QLineEdit.
    QLineEdit::paintEvent(evt);
}
