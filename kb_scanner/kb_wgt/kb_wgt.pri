INCLUDEPATH += $$includePath($$PWD/../) # kb_wgt/..

HEADERS += \
    $$PWD/scan_code_dlg.h \
    $$PWD/datamatrix_text_edit.h\
    $$PWD/scannerlog.h \
    $$PWD/customcolorplaceholderlineedit.h

SOURCES += \
    $$PWD/scan_code_dlg.cpp \
    $$PWD/datamatrix_text_edit.cpp \
    $$PWD/scannerlog.cpp \
    $$PWD/customcolorplaceholderlineedit.cpp

FORMS += \
    $$PWD/scan_code_dlg.ui \
    $$PWD/scannerlog.ui
