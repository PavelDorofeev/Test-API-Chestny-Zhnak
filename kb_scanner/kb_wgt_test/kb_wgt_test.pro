#-------------------------------------------------
#
# Project created by QtCreator 2025-04-09T19:56:06
#
#-------------------------------------------------

QT += core gui svg network

include($$PWD/../../../qp/general/general.pri)

TARGET = $$targetWithVer(kb_scanner_barcode_test)

TEMPLATE = app

OBJECTS_DIR     = obj
MOC_DIR         = moc
RCC_DIR         = rcc
UI_DIR          = ui




INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/../
INCLUDEPATH += $$PWD/../kb_wgt
INCLUDEPATH += $$PWD/../../../my_lib
INCLUDEPATH += $$PWD/../../../
INCLUDEPATH += $$PWD/../../

#include( $$include2( $$PWD/../../../qp/config/lib_openssl.pri ))
#include( $$include2( $$PWD/../../../qp/qp.pri) )
include( $$include2( $$PWD/../../../qp/config/lib_qp_core.pri ))
include( $$include2( $$PWD/../../../qp/config/lib_qp_gui.pri ))

include( $$include2( $$PWD/../../../config/lib_my_lib.pri ))


include( $$include2( $$PWD/../kb_wgt/kb_wgt.pri) )

#include( $$include2( $$PWD/../../marking/marking.pri) )

OTHER_FILES += \
    $$PWD/rc_kb_wgt_test.rc


win32 {
  RC_FILE   += $$PWD/rc_kb_wgt_test.rc
}

#static_increment.commands = $$PWD/my_batch_file.bat

#QMAKE_EXTRA_TARGETS +=  static_increment

#PRE_TARGETDEPS += static_increment


SOURCES += main.cpp

HEADERS += \
    base_version.h

