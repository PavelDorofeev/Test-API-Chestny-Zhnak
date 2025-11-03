QT       += core gui network qaxcontainer

TARGET = chzn
TEMPLATE = lib

OBJECTS_DIR = tmp\\obj
MOC_DIR = tmp\\moc
RCC_DIR = tmp\\rcc
UI_DIR = tmp\\ui

include($$PWD/../../qp/general/general.pri)

include($$include2($$PWD/../../qp/config/lib_openssl.pri))

include($$PWD/../../qp/config/lib_qp_core.pri)
include($$PWD/../../qp/config/lib_qp_gui.pri)
include($$PWD/../../qp/config/lib_qp_ntw.pri)

#include($$PWD/../../../config/lib_my_lib.pri)

include($$include2($$PWD/../../qp/config/lib_axcontainer.pri))

include($$include2($$PWD/../../kb_scanner/config/lib_scanner_kb.pri))
#include($$include2($$PWD/../../../equipment/scanner/kb_wgt/kb_wgt.pri))



include( $$include2( $$PWD/../config/create_lib_chzn.pri))

include( $$include2( $$PWD/chzn.pri))






