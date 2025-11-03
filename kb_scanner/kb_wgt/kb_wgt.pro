TEMPLATE = lib

TARGET = kb_wgt

QT += core gui svg

OBJECTS_DIR = tmp\\obj
MOC_DIR = tmp\\moc
RCC_DIR = tmp\\rcc
UI_DIR = tmp\\ui

include($$PWD/../../qp/general/general.pri)


INCLUDEPATH += $$includePath($$PWD)
INCLUDEPATH += $$includePath($$PWD/../)
INCLUDEPATH += $$includePath($$PWD/../../)
#INCLUDEPATH += $$includePath($$PWD/../../../my_lib)

include( $$include2( $$PWD/../../config/lib_qp.pri) )
#include( $$include2( $$PWD/../../config/lib_my_lib.pri) )

#include( $$include2( $$PWD/../../config_eqpt/lib_aeqpt.pri) )
#include( $$include2( $$PWD/../../config_eqpt/lib_akkt.pri) )
include( $$include2( $$PWD/../../marking/config/lib_marking.pri) )

include( $$include2( $$PWD/../config/create_lib_scanner_kb.pri) )

include( $$include2( $$PWD/kb_wgt.pri) )


