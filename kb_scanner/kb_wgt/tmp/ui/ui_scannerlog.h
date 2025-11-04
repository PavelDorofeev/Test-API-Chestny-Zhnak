/********************************************************************************
** Form generated from reading UI file 'scannerlog.ui'
**
** Created: Tue 4. Nov 13:33:53 2025
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANNERLOG_H
#define UI_SCANNERLOG_H

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

class Ui_ScannerLog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plte_log;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ScannerLog)
    {
        if (ScannerLog->objectName().isEmpty())
            ScannerLog->setObjectName(QString::fromUtf8("ScannerLog"));
        ScannerLog->resize(898, 792);
        ScannerLog->setMinimumSize(QSize(898, 792));
        verticalLayout_2 = new QVBoxLayout(ScannerLog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plte_log = new QPlainTextEdit(ScannerLog);
        plte_log->setObjectName(QString::fromUtf8("plte_log"));
        QFont font;
        font.setPointSize(10);
        plte_log->setFont(font);
        plte_log->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);\n"
"color: rgb(75, 111, 222);"));

        verticalLayout->addWidget(plte_log);

        buttonBox = new QDialogButtonBox(ScannerLog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ScannerLog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ScannerLog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ScannerLog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ScannerLog);
    } // setupUi

    void retranslateUi(QDialog *ScannerLog)
    {
        ScannerLog->setWindowTitle(QApplication::translate("ScannerLog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScannerLog: public Ui_ScannerLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANNERLOG_H
