#ifndef SHOW_SCANNER_LOG_H
#define SHOW_SCANNER_LOG_H

#include <QDialog>

namespace Ui {
class ScannerLog;
}

#include "../dll_kb_scanner_global.h"

class LIB_PREFIX_KB_SCANNER ScannerLog : public QDialog
{
    Q_OBJECT
    
public:

    explicit ScannerLog(QWidget *parent = 0);

    ~ScannerLog();

    void fillContent( const QString &txt);
    
private:

    Ui::ScannerLog *ui;
};

#endif // SHOWSCANNERLOG_H
