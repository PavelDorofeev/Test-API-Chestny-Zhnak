/********************************************************************************
** Form generated from reading UI file 'smart_process_dlg.ui'
**
** Created: Tue 4. Nov 13:01:46 2025
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMART_PROCESS_DLG_H
#define UI_SMART_PROCESS_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Smart_Process_Dlg
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_dark_1;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_dark_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_header;
    QVBoxLayout *contentLayout;
    QLabel *lbl_text1;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *lbl_text2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_save_to_file;
    QPushButton *btn_maximizedShow;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Close;
    QPushButton *btn_wait;

    void setupUi(QDialog *Smart_Process_Dlg)
    {
        if (Smart_Process_Dlg->objectName().isEmpty())
            Smart_Process_Dlg->setObjectName(QString::fromUtf8("Smart_Process_Dlg"));
        Smart_Process_Dlg->resize(606, 542);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Smart_Process_Dlg->sizePolicy().hasHeightForWidth());
        Smart_Process_Dlg->setSizePolicy(sizePolicy);
        Smart_Process_Dlg->setMinimumSize(QSize(537, 542));
        Smart_Process_Dlg->setWindowTitle(QString::fromUtf8("..."));
        Smart_Process_Dlg->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(Smart_Process_Dlg);
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        frame_dark_1 = new QFrame(Smart_Process_Dlg);
        frame_dark_1->setObjectName(QString::fromUtf8("frame_dark_1"));
        sizePolicy.setHeightForWidth(frame_dark_1->sizePolicy().hasHeightForWidth());
        frame_dark_1->setSizePolicy(sizePolicy);
        frame_dark_1->setMinimumSize(QSize(0, 0));
        frame_dark_1->setFrameShape(QFrame::StyledPanel);
        frame_dark_1->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_dark_1);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetMaximumSize);
        frame_dark_2 = new QFrame(frame_dark_1);
        frame_dark_2->setObjectName(QString::fromUtf8("frame_dark_2"));
        frame_dark_2->setFrameShape(QFrame::StyledPanel);
        frame_dark_2->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_dark_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        lbl_header = new QLabel(frame_dark_2);
        lbl_header->setObjectName(QString::fromUtf8("lbl_header"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(lbl_header->sizePolicy().hasHeightForWidth());
        lbl_header->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbl_header->setFont(font);
        lbl_header->setTextFormat(Qt::RichText);
        lbl_header->setScaledContents(false);
        lbl_header->setAlignment(Qt::AlignCenter);
        lbl_header->setWordWrap(true);
        lbl_header->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(lbl_header);


        verticalLayout_6->addLayout(verticalLayout_2);

        contentLayout = new QVBoxLayout();
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        lbl_text1 = new QLabel(frame_dark_2);
        lbl_text1->setObjectName(QString::fromUtf8("lbl_text1"));
        sizePolicy1.setHeightForWidth(lbl_text1->sizePolicy().hasHeightForWidth());
        lbl_text1->setSizePolicy(sizePolicy1);
        lbl_text1->setFrameShadow(QFrame::Raised);
        lbl_text1->setTextFormat(Qt::RichText);
        lbl_text1->setWordWrap(true);

        contentLayout->addWidget(lbl_text1);


        verticalLayout_6->addLayout(contentLayout);

        scrollArea = new QScrollArea(frame_dark_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 472, 314));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        lbl_text2 = new QPlainTextEdit(scrollAreaWidgetContents);
        lbl_text2->setObjectName(QString::fromUtf8("lbl_text2"));
        lbl_text2->setContextMenuPolicy(Qt::NoContextMenu);
        lbl_text2->setAcceptDrops(false);
#ifndef QT_NO_TOOLTIP
        lbl_text2->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
        lbl_text2->setFrameShape(QFrame::NoFrame);
        lbl_text2->setLineWrapMode(QPlainTextEdit::NoWrap);
        lbl_text2->setReadOnly(true);
        lbl_text2->setPlainText(QString::fromUtf8(""));
        lbl_text2->setOverwriteMode(false);
        lbl_text2->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        lbl_text2->setBackgroundVisible(true);

        verticalLayout_3->addWidget(lbl_text2);


        verticalLayout_5->addLayout(verticalLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_save_to_file = new QPushButton(frame_dark_2);
        btn_save_to_file->setObjectName(QString::fromUtf8("btn_save_to_file"));
        btn_save_to_file->setDefault(true);

        horizontalLayout->addWidget(btn_save_to_file);

        btn_maximizedShow = new QPushButton(frame_dark_2);
        btn_maximizedShow->setObjectName(QString::fromUtf8("btn_maximizedShow"));
        btn_maximizedShow->setDefault(true);

        horizontalLayout->addWidget(btn_maximizedShow);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Close = new QPushButton(frame_dark_2);
        btn_Close->setObjectName(QString::fromUtf8("btn_Close"));
        btn_Close->setDefault(true);

        horizontalLayout->addWidget(btn_Close);

        btn_wait = new QPushButton(frame_dark_2);
        btn_wait->setObjectName(QString::fromUtf8("btn_wait"));

        horizontalLayout->addWidget(btn_wait);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_7->addWidget(frame_dark_2);


        verticalLayout->addWidget(frame_dark_1);


        retranslateUi(Smart_Process_Dlg);

        QMetaObject::connectSlotsByName(Smart_Process_Dlg);
    } // setupUi

    void retranslateUi(QDialog *Smart_Process_Dlg)
    {
        lbl_header->setText(QString());
        lbl_text1->setText(QString());
        lbl_text2->setDocumentTitle(QString());
        btn_save_to_file->setText(QApplication::translate("Smart_Process_Dlg", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        btn_maximizedShow->setText(QApplication::translate("Smart_Process_Dlg", "\320\275\320\260 \320\262\320\265\321\201\321\214 \321\215\320\272\321\200\320\260\320\275", 0, QApplication::UnicodeUTF8));
        btn_Close->setText(QApplication::translate("Smart_Process_Dlg", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btn_wait->setText(QApplication::translate("Smart_Process_Dlg", "\320\266\320\264\320\270\321\202\320\265...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Smart_Process_Dlg);
    } // retranslateUi

};

namespace Ui {
    class Smart_Process_Dlg: public Ui_Smart_Process_Dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMART_PROCESS_DLG_H
