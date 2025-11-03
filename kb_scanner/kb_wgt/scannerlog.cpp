#include "scannerlog.h"
#include "ui_scannerlog.h"

ScannerLog::ScannerLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScannerLog)
{
    ui->setupUi(this);


}

ScannerLog::~ScannerLog()
{
    delete ui;
}


void ScannerLog::fillContent( const QString &txt)
{
    ui->plte_log->setPlainText( txt );
}
