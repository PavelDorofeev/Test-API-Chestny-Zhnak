QT       += core

TARGET = marking
TEMPLATE = lib

OBJECTS_DIR = tmp\\obj
MOC_DIR = tmp\\moc
RCC_DIR = tmp\\rcc
UI_DIR = tmp\\ui

include($$PWD/../qp/general/general.pri)

include( $$include2($$PWD/../qp/config/lib_qp_core.pri))
include( $$include2($$PWD/../qp/config/lib_qp_gui.pri))
include( $$include2($$PWD/../qp/config/lib_qp_ntw.pri))

include( $$include2($$PWD/config/create_lib_marking.pri))

include( $$include2($$PWD/marking.pri))



