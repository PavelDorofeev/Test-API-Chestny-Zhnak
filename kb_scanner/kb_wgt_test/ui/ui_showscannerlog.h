/********************************************************************************
** Form generated from reading UI file 'showscannerlog.ui'
**
** Created: Wed 4. Jun 20:12:59 2025
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSCANNERLOG_H
#define UI_SHOWSCANNERLOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowScannerLog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plte_log;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ShowScannerLog)
    {
        if (ShowScannerLog->objectName().isEmpty())
            ShowScannerLog->setObjectName(QString::fromUtf8("ShowScannerLog"));
        ShowScannerLog->resize(898, 792);
        ShowScannerLog->setMinimumSize(QSize(898, 792));
        verticalLayout_2 = new QVBoxLayout(ShowScannerLog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plte_log = new QPlainTextEdit(ShowScannerLog);
        plte_log->setObjectName(QString::fromUtf8("plte_log"));
        QFont font;
        font.setPointSize(10);
        plte_log->setFont(font);
        plte_log->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"color: rgb(75, 111, 222);"));

        verticalLayout->addWidget(plte_log);

        buttonBox = new QDialogButtonBox(ShowScannerLog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ShowScannerLog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ShowScannerLog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ShowScannerLog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShowScannerLog);
    } // setupUi

    void retranslateUi(QDialog *ShowScannerLog)
    {
        ShowScannerLog->setWindowTitle(QApplication::translate("ShowScannerLog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShowScannerLog: public Ui_ShowScannerLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSCANNERLOG_H
