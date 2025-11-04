/********************************************************************************
** Form generated from reading UI file 'scan_code_dlg.ui'
**
** Created: Tue 4. Nov 13:33:53 2025
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCAN_CODE_DLG_H
#define UI_SCAN_CODE_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <kb_scanner/kb_wgt/datamatrix_text_edit.h>
#include "customcolorplaceholderlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_Scan_Code_Dlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QFrame *dialogTopFrame;
    QVBoxLayout *vl;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    DatamatrixTextEdit *plte_datamatrix;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *chk_auto_detection;
    CustomColorPlaceholderLineEdit *ledt_redefineGS;
    QPushButton *btn_save_redifinedGS;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_clear;
    QPushButton *btn_show_log;
    QCheckBox *chk_enable_log;
    QCheckBox *chk_clearAfterScanned;
    QCheckBox *chk_closeWin_afterEnter;
    QCheckBox *chk_showBase64;
    QPushButton *btn_show_app_log;
    QFrame *fr_showBase64;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPlainTextEdit *plte_base64;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_warning;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_accept;

    void setupUi(QDialog *Scan_Code_Dlg)
    {
        if (Scan_Code_Dlg->objectName().isEmpty())
            Scan_Code_Dlg->setObjectName(QString::fromUtf8("Scan_Code_Dlg"));
        Scan_Code_Dlg->resize(910, 588);
        Scan_Code_Dlg->setMinimumSize(QSize(910, 588));
        Scan_Code_Dlg->setWindowTitle(QString::fromUtf8("\321\201\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\210\321\202\321\200\320\270\321\205 \320\272\320\276\320\264\320\260"));
        Scan_Code_Dlg->setSizeGripEnabled(true);
        Scan_Code_Dlg->setModal(true);
        verticalLayout_2 = new QVBoxLayout(Scan_Code_Dlg);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(19);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        dialogTopFrame = new QFrame(Scan_Code_Dlg);
        dialogTopFrame->setObjectName(QString::fromUtf8("dialogTopFrame"));
        dialogTopFrame->setAutoFillBackground(true);
        dialogTopFrame->setFrameShape(QFrame::Box);
        vl = new QVBoxLayout(dialogTopFrame);
        vl->setObjectName(QString::fromUtf8("vl"));
        label = new QLabel(dialogTopFrame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label->setTextInteractionFlags(Qt::NoTextInteraction);

        vl->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plte_datamatrix = new DatamatrixTextEdit(dialogTopFrame);
        plte_datamatrix->setObjectName(QString::fromUtf8("plte_datamatrix"));
        plte_datamatrix->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        plte_datamatrix->setFont(font1);
        plte_datamatrix->setPlainText(QString::fromUtf8(""));

        verticalLayout->addWidget(plte_datamatrix);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(11, 11, 11, -1);
        frame = new QFrame(dialogTopFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setMidLineWidth(1);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setTitle(QString::fromUtf8("\321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\274 GS \321\201\321\207\320\270\321\202\320\260\321\202\321\214 :"));
        groupBox->setFlat(false);
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        chk_auto_detection = new QCheckBox(groupBox);
        chk_auto_detection->setObjectName(QString::fromUtf8("chk_auto_detection"));

        verticalLayout_5->addWidget(chk_auto_detection);

        ledt_redefineGS = new CustomColorPlaceholderLineEdit(groupBox);
        ledt_redefineGS->setObjectName(QString::fromUtf8("ledt_redefineGS"));
        ledt_redefineGS->setMinimumSize(QSize(0, 0));
        ledt_redefineGS->setMaximumSize(QSize(1644465, 16777215));
        ledt_redefineGS->setFont(font1);
#ifndef QT_NO_TOOLTIP
        ledt_redefineGS->setToolTip(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.5pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\277\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\262 \320\273\320\276\320\263\320\265 \320\272\320\260\320\272 \321\201\320\272\320\260\320\275\320\265\321\200 \320\277\320\265\321\200\320\265\320\264\320\260\320\265\321\202 GS \321\201\320\270\320\274\320\262\320\276\320\273, <br />\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200 \320\276\320\275 \320\277\320\265\321\200\320\265\320\264\320\260\320\265\321"
                        "\202 \320\265\320\263\320\276 \320\272\320\260\320\272 F8  (\321\200\321\217\320\264\320\276\320\274 \320\265\320\263\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 0\321\20542)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\320\243\320\272\320\260\320\267\321\213\320\262\320\260\320\265\320\274 \320\267\320\264\320\265\321\201\321\214 0x42 \320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\267\320\260\320\274\320\265\320\275\320\270\321\202 \320\262\321\201\320\265 F8 (0x42) \320\275\320\260 GS (0x1d)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\320\225\321\201\320\273\320\270 \320\275\320\260\320\264\320\276 2 \321\201\320\272\320\260\320\275\320\272\320\276\320\264\320\260 \320\275\320\260\320\277\320\270"
                        "\321\201\320\260\321\202\321\214 \320\274\320\276\320\266\320\275\320\276 \321\207\320\265\321\200\320\265\320\267 \320\267\320\260\320\277\321\217\321\202\321\203\321\216, \320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">0x38,0x51 \321\215\321\202\320\276 Alt PgDown \320\261\321\203\320\264\320\265\321\202 \320\267\320\260\320\274\320\265\320\275\321\217\321\202\321\214\321\201\321\217 \320\275\320\260 \320\276\320\264\320\270\320\275 \320\261\320\260\320\271\321\202 GS (0x1d).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\320\241\320\272\320\260\320\275\320\265\321\200 \320\274\320\276\320\266\320\265\321\202 \320\277\320\265\321\200\320\265\320\264\320\260\320\262\320\260\321\202\321\214 \320\270 \321\202"
                        "\320\260\320\272\320\276\320\265 0x152 (\321\215\321\202\320\276 r\320\272\320\273\320\260\320\262\320\270\321\210\320\260 Ins),</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\321\202\320\276\320\263\320\264\320\260 \321\203\320\272\320\260\320\267\321\213\320\262\320\260\320\265\320\274 </span><span style=\" font-size:10pt;\">0x152 (\321\202\321\200\320\270 \321\206\320\270\321\204\321\200\321\213)</span></p></body></html>"));
#endif // QT_NO_TOOLTIP
        ledt_redefineGS->setInputMask(QString::fromUtf8(""));
        ledt_redefineGS->setText(QString::fromUtf8(""));
        ledt_redefineGS->setMaxLength(100);
        ledt_redefineGS->setPlaceholderText(QString::fromUtf8("0x152,0x42"));

        verticalLayout_5->addWidget(ledt_redefineGS);

        btn_save_redifinedGS = new QPushButton(groupBox);
        btn_save_redifinedGS->setObjectName(QString::fromUtf8("btn_save_redifinedGS"));

        verticalLayout_5->addWidget(btn_save_redifinedGS);


        verticalLayout_8->addWidget(groupBox);


        horizontalLayout_4->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(11, 11, -1, -1);
        btn_clear = new QPushButton(dialogTopFrame);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        verticalLayout_3->addWidget(btn_clear);

        btn_show_log = new QPushButton(dialogTopFrame);
        btn_show_log->setObjectName(QString::fromUtf8("btn_show_log"));

        verticalLayout_3->addWidget(btn_show_log);

        chk_enable_log = new QCheckBox(dialogTopFrame);
        chk_enable_log->setObjectName(QString::fromUtf8("chk_enable_log"));
        chk_enable_log->setText(QString::fromUtf8("\320\262\320\265\321\201\321\202\320\270 \320\273\320\276\320\263"));
        chk_enable_log->setChecked(false);

        verticalLayout_3->addWidget(chk_enable_log);

        chk_clearAfterScanned = new QCheckBox(dialogTopFrame);
        chk_clearAfterScanned->setObjectName(QString::fromUtf8("chk_clearAfterScanned"));
        chk_clearAfterScanned->setText(QString::fromUtf8("\320\276\321\207\320\270\321\211\320\260\321\202\321\214 \320\276\320\272\320\275\320\276\n"
"\320\277\320\276\321\201\320\273\320\265 \321\201\320\272\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217"));
        chk_clearAfterScanned->setShortcut(QString::fromUtf8(""));
        chk_clearAfterScanned->setChecked(true);

        verticalLayout_3->addWidget(chk_clearAfterScanned);

        chk_closeWin_afterEnter = new QCheckBox(dialogTopFrame);
        chk_closeWin_afterEnter->setObjectName(QString::fromUtf8("chk_closeWin_afterEnter"));
        chk_closeWin_afterEnter->setText(QString::fromUtf8("\320\267\320\260\320\272\321\200\321\213\320\262\320\260\321\202\321\214 \320\276\320\272\320\275\320\276 \320\277\320\276\321\201\320\273\320\265\n"
" \320\277\321\200\320\270\321\205\320\276\320\264\320\260 Enter"));
        chk_closeWin_afterEnter->setShortcut(QString::fromUtf8(""));
        chk_closeWin_afterEnter->setChecked(false);

        verticalLayout_3->addWidget(chk_closeWin_afterEnter);

        chk_showBase64 = new QCheckBox(dialogTopFrame);
        chk_showBase64->setObjectName(QString::fromUtf8("chk_showBase64"));
        chk_showBase64->setText(QString::fromUtf8("\320\277\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 base64"));
        chk_showBase64->setShortcut(QString::fromUtf8(""));
        chk_showBase64->setChecked(false);

        verticalLayout_3->addWidget(chk_showBase64);

        btn_show_app_log = new QPushButton(dialogTopFrame);
        btn_show_app_log->setObjectName(QString::fromUtf8("btn_show_app_log"));

        verticalLayout_3->addWidget(btn_show_app_log);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 1);

        vl->addLayout(horizontalLayout_2);

        fr_showBase64 = new QFrame(dialogTopFrame);
        fr_showBase64->setObjectName(QString::fromUtf8("fr_showBase64"));
        horizontalLayout_3 = new QHBoxLayout(fr_showBase64);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(fr_showBase64);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        plte_base64 = new QPlainTextEdit(fr_showBase64);
        plte_base64->setObjectName(QString::fromUtf8("plte_base64"));
        plte_base64->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_3->addWidget(plte_base64);


        vl->addWidget(fr_showBase64);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lbl_warning = new QLabel(dialogTopFrame);
        lbl_warning->setObjectName(QString::fromUtf8("lbl_warning"));
        lbl_warning->setFont(font);

        verticalLayout_4->addWidget(lbl_warning);


        vl->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_cancel = new QPushButton(dialogTopFrame);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_accept = new QPushButton(dialogTopFrame);
        btn_accept->setObjectName(QString::fromUtf8("btn_accept"));
        btn_accept->setFont(font1);

        horizontalLayout->addWidget(btn_accept);


        vl->addLayout(horizontalLayout);


        verticalLayout_6->addWidget(dialogTopFrame);


        verticalLayout_2->addLayout(verticalLayout_6);


        retranslateUi(Scan_Code_Dlg);

        QMetaObject::connectSlotsByName(Scan_Code_Dlg);
    } // setupUi

    void retranslateUi(QDialog *Scan_Code_Dlg)
    {
        label->setText(QApplication::translate("Scan_Code_Dlg", "\320\277\321\200\320\276\321\201\320\272\320\260\320\275\320\270\321\200\321\203\320\271\321\202\320\265 \321\210\321\202\321\200\320\270\321\205 \320\272\320\276\320\264 \320\274\320\260\321\200\320\272\320\270\321\200\320\276\320\262\320\272\320\270 (\321\201\320\272\320\260\320\275\320\265\321\200\320\276\320\274 \320\262 \321\200\320\265\320\266\320\270\320\274\320\265 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213)", 0, QApplication::UnicodeUTF8));
        chk_auto_detection->setText(QApplication::translate("Scan_Code_Dlg", "\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\321\214 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270", 0, QApplication::UnicodeUTF8));
        btn_save_redifinedGS->setText(QApplication::translate("Scan_Code_Dlg", "\321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btn_clear->setText(QApplication::translate("Scan_Code_Dlg", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btn_show_log->setText(QApplication::translate("Scan_Code_Dlg", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\273\320\276\320\263", 0, QApplication::UnicodeUTF8));
        btn_show_app_log->setText(QApplication::translate("Scan_Code_Dlg", "\320\273\320\276\320\263 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Scan_Code_Dlg", "base64 : ", 0, QApplication::UnicodeUTF8));
        lbl_warning->setText(QString());
        btn_cancel->setText(QApplication::translate("Scan_Code_Dlg", "\320\276\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btn_accept->setText(QApplication::translate("Scan_Code_Dlg", "\320\277\321\200\320\270\320\275\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Scan_Code_Dlg);
    } // retranslateUi

};

namespace Ui {
    class Scan_Code_Dlg: public Ui_Scan_Code_Dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCAN_CODE_DLG_H
