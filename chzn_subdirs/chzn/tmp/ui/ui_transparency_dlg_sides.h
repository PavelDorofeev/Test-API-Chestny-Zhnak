/********************************************************************************
** Form generated from reading UI file 'transparency_dlg_sides.ui'
**
** Created: Tue 4. Nov 13:09:30 2025
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSPARENCY_DLG_SIDES_H
#define UI_TRANSPARENCY_DLG_SIDES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Transparency_Dlg_Sides
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *hl_left;
    QFrame *frameLeft;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *hl_center;
    QVBoxLayout *verticalLayout_6;
    QFrame *frameTop;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QFrame *frameInCenter;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *VLO_INTO;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameBottom;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *hl_right;
    QFrame *frameRight;
    QVBoxLayout *verticalLayout_10;

    void setupUi(QDialog *Transparency_Dlg_Sides)
    {
        if (Transparency_Dlg_Sides->objectName().isEmpty())
            Transparency_Dlg_Sides->setObjectName(QString::fromUtf8("Transparency_Dlg_Sides"));
        Transparency_Dlg_Sides->setWindowModality(Qt::WindowModal);
        Transparency_Dlg_Sides->resize(494, 378);
        Transparency_Dlg_Sides->setMinimumSize(QSize(100, 100));
        Transparency_Dlg_Sides->setWindowOpacity(1);
#ifndef QT_NO_TOOLTIP
        Transparency_Dlg_Sides->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
        Transparency_Dlg_Sides->setAutoFillBackground(true);
        Transparency_Dlg_Sides->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(Transparency_Dlg_Sides);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hl_left = new QHBoxLayout();
        hl_left->setSpacing(0);
#ifndef Q_OS_MAC
        hl_left->setContentsMargins(0, 0, 0, 0);
#endif
        hl_left->setObjectName(QString::fromUtf8("hl_left"));
        frameLeft = new QFrame(Transparency_Dlg_Sides);
        frameLeft->setObjectName(QString::fromUtf8("frameLeft"));
        frameLeft->setAutoFillBackground(false);
        frameLeft->setFrameShape(QFrame::NoFrame);
        frameLeft->setFrameShadow(QFrame::Plain);
        frameLeft->setLineWidth(0);
        verticalLayout_12 = new QVBoxLayout(frameLeft);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));

        hl_left->addWidget(frameLeft);


        horizontalLayout->addLayout(hl_left);

        hl_center = new QVBoxLayout();
        hl_center->setSpacing(0);
        hl_center->setObjectName(QString::fromUtf8("hl_center"));
        hl_center->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
#ifndef Q_OS_MAC
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
#endif
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        frameTop = new QFrame(Transparency_Dlg_Sides);
        frameTop->setObjectName(QString::fromUtf8("frameTop"));
        frameTop->setAutoFillBackground(false);
        frameTop->setFrameShape(QFrame::NoFrame);
        frameTop->setFrameShadow(QFrame::Plain);
        verticalLayout_8 = new QVBoxLayout(frameTop);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        verticalLayout_6->addWidget(frameTop);


        hl_center->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
#ifndef Q_OS_MAC
        verticalLayout->setContentsMargins(0, 0, 0, 0);
#endif
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frameInCenter = new QFrame(Transparency_Dlg_Sides);
        frameInCenter->setObjectName(QString::fromUtf8("frameInCenter"));
        frameInCenter->setMinimumSize(QSize(0, 0));
        frameInCenter->setAutoFillBackground(false);
        frameInCenter->setFrameShape(QFrame::NoFrame);
        frameInCenter->setFrameShadow(QFrame::Plain);
        frameInCenter->setMidLineWidth(0);
        verticalLayout_14 = new QVBoxLayout(frameInCenter);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        VLO_INTO = new QVBoxLayout();
        VLO_INTO->setSpacing(0);
#ifndef Q_OS_MAC
        VLO_INTO->setContentsMargins(0, 0, 0, 0);
#endif
        VLO_INTO->setObjectName(QString::fromUtf8("VLO_INTO"));

        verticalLayout_14->addLayout(VLO_INTO);


        verticalLayout->addWidget(frameInCenter);


        hl_center->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
#ifndef Q_OS_MAC
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
#endif
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frameBottom = new QFrame(Transparency_Dlg_Sides);
        frameBottom->setObjectName(QString::fromUtf8("frameBottom"));
        frameBottom->setAutoFillBackground(false);
        verticalLayout_5 = new QVBoxLayout(frameBottom);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        verticalLayout_3->addWidget(frameBottom);


        hl_center->addLayout(verticalLayout_3);

        hl_center->setStretch(0, 1);
        hl_center->setStretch(1, 1);
        hl_center->setStretch(2, 1);

        horizontalLayout->addLayout(hl_center);

        hl_right = new QHBoxLayout();
        hl_right->setSpacing(0);
#ifndef Q_OS_MAC
        hl_right->setContentsMargins(0, 0, 0, 0);
#endif
        hl_right->setObjectName(QString::fromUtf8("hl_right"));
        frameRight = new QFrame(Transparency_Dlg_Sides);
        frameRight->setObjectName(QString::fromUtf8("frameRight"));
        frameRight->setAutoFillBackground(false);
        frameRight->setFrameShape(QFrame::NoFrame);
        frameRight->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frameRight);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));

        hl_right->addWidget(frameRight);


        horizontalLayout->addLayout(hl_right);


        retranslateUi(Transparency_Dlg_Sides);

        QMetaObject::connectSlotsByName(Transparency_Dlg_Sides);
    } // setupUi

    void retranslateUi(QDialog *Transparency_Dlg_Sides)
    {
        Transparency_Dlg_Sides->setWindowTitle(QApplication::translate("Transparency_Dlg_Sides", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Transparency_Dlg_Sides: public Ui_Transparency_Dlg_Sides {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSPARENCY_DLG_SIDES_H
