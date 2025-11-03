#include "mainwindow.h"
#include "base_version.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle(QString( "Тест АПИ ЧЗ (вер:%1.%2.%3)").arg(NVER1).arg(NVER2).arg(STATIC_BUILD_NUMBER));
}
