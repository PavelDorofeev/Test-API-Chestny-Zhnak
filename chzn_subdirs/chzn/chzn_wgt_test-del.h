#ifndef CHZN_TEST_DLG_H
#define CHZN_TEST_DLG_H

#include <QDialog>
#include <QSettings>


namespace Ui {
class Chzn_Test_Dlg;
}


class Chzn_Test_Dlg : public QWidget
{
    Q_OBJECT

public:
    explicit Chzn_Test_Dlg(QWidget *parent = 0);
    ~Chzn_Test_Dlg();

    QSettings sett;

private slots:
    void on_btn_scan_bar_code_clicked();

private:
    Ui::Chzn_Test_Dlg *ui;
};

#endif // DIALOG_H
