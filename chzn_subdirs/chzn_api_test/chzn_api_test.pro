
QT       += core gui network qaxcontainer svg


include($$PWD/../../qp/general/general.pri)

TARGET = $$targetWithVer(bit_chzn_api_test)
#TARGET = bit_chzn_api_test
message($$TARGET)
TEMPLATE = app

#CONFIG +=  windows
#CONFIG   += openssl
#CONFIG +=  console


OBJECTS_DIR = tmp\\obj
MOC_DIR = tmp\\moc
RCC_DIR = tmp\\rcc
UI_DIR = tmp\\ui

MY_PRODUCT_TYPE=1 # 1 APP
MY_IDE=1 # Qt=1

win32:MY_OS_TYPE=2


include($$include2($$PWD/../../qp/config/lib_openssl.pri))

#include( $$include2( $$PWD/../../../equipment/qextserialport/qextserialport.pri) )
#include( $$include2( $$PWD/../../../equipment/config_eqpt/lib_qextserialport.pri) )

#include( $$include2($$PWD/../../../qp/config/lib_qp_core.pri))
include( $$include2($$PWD/../../qp/core/qp_core.pri))

#include( $$include2($$PWD/../../../qp/config/lib_qp_gui.pri))
include( $$include2($$PWD/../../qp/gui/qp_gui.pri))

#include( $$include2($$PWD/../../../qp/config/lib_qp_ntw.pri))
include( $$include2($$PWD/../../qp/ntw/qp_ntw.pri))

#include( $$include2($$PWD/../../../config/lib_my_lib.pri))
#include( $$include2($$PWD/../../../my_lib/my_lib.pri))

include($$include2($$PWD/../../qp/config/lib_axcontainer.pri))

#include($$include2($$PWD/../../../kb_scanner/config/lib_scanner_kb.pri))
include($$include2($$PWD/../../kb_scanner/kb_wgt/kb_wgt.pri))

#include($$include2($$PWD/../../../marking/marking.pri))
#include($$include2($$PWD/../../../equipment/config_eqpt/lib_marking.pri))

#include($$include2($$PWD/../../../equipment/a_subdirs/abstract/abstract.pri))
#include($$include2($$PWD/../../../equipment/config_eqpt/lib_aeqpt.pri))


#include($$include2($$PWD/../../../config/lib_chzn.pri))  Ттак почему-то падает
include($$include2($$PWD/../chzn/chzn.pri))



CONFIG(release,release|debug){

    CONFIG -= debug shared
    CONFIG += release static
    DEFINES -= MY_DEBUG

    contains(CONFIG,static){

        DEFINES += STATIC_MODE
        QTPLUGIN += qsvg

        MY_DEBUG_RELEASE=4

        CONFIG -=  console

        QMAKE_LFLAGS_EXCEPTIONS_ON -= -mthreads
        message("----- RELEASE STATIC ----")
    }
    else{
        MY_DEBUG_RELEASE=3

        message("----- release  shared ----??????")
    }
}
else:CONFIG(debug,release|debug){

    MY_DEBUG_RELEASE=1
    CONFIG -= release static


    contains(CONFIG,static){
        message("????????---------- debug static -----------??????????")
        MY_DEBUG_RELEASE=2
    }
    else:contains(CONFIG,shared){
        message("---------- DEBUG SHARED ----------- ")


    }
}

HEADERS += \
    $$PWD/base_version.h \
    inno_setup.h \
    mainwindow.h

SOURCES += $$PWD/main.cpp \
    mainwindow.cpp

OTHER_FILES += \
    $$PWD/rc_info.rc

win32 {
  RC_FILE     += $$PWD/rc_info.rc
}
win32{
    CONFIG += embed_manifest_exe
    #QMAKE_LFLAGS_WINDOWS += /MANIFESTUAC:"level='requireAdministrator'"
}


