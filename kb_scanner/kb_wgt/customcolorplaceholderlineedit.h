#ifndef CUSTOMCOLORPLACEHOLDERLINEEDIT_H
#define CUSTOMCOLORPLACEHOLDERLINEEDIT_H

#include <QLineEdit>

#include "../dll_kb_scanner_global.h"

class LIB_PREFIX_KB_SCANNER CustomColorPlaceholderLineEdit : public QLineEdit
{
public:
    CustomColorPlaceholderLineEdit(QWidget * parent = 0) ;

    const QString &customPlaceholderText() const { return mText; }

    void setCustomPlaceholderColor(const QColor &color) { this->color = color; }

    const QColor &customPlaceholderColor() const { return color; }

    void paintEvent(QPaintEvent *event);

private:
    QString mText;
    QColor color;
};

#endif // CUSTOMCOLORPLACEHOLDERLINEEDIT_H
