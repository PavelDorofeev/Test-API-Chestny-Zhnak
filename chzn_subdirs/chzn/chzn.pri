#INCLUDEPATH += $$includePath( $$PWD/../../../equipment)
#INCLUDEPATH += $$includePath( $$PWD/../../../equipment/a_subdirs)
INCLUDEPATH += $$includePath( $$PWD/../)

HEADERS += \
    $$PWD/chzn_validate.h \
    $$PWD/chzn_test_wgt.h \
    $$PWD/chzn_response.h \
    $$PWD/chzn_responsecode.h \
    $$PWD/chzn_goods_info.h \
    $$PWD/lm_responsecode.h \
    $$PWD/lm_response_lst.h \
    $$PWD/ntwqueryansw.h \
    $$PWD/chzn_goodsinfo_lst.h \
    $$PWD/nk_product_lst.h \
    $$PWD/nk_product.h

SOURCES += \
    $$PWD/chzn_validate.cpp \
    $$PWD/chzn_test_wgt.cpp \
    $$PWD/chzn_response.cpp \
    $$PWD/chzn_goods_info.cpp \
    $$PWD/chzn_responsecode.cpp \
    $$PWD/lm_responsecode.cpp \
    $$PWD/lm_response_lst.cpp \
    $$PWD/ntwqueryansw.cpp \
    $$PWD/chzn_goodsinfo_lst.cpp \
    $$PWD/nk_product_lst.cpp \
    $$PWD/nk_product.cpp


FORMS += \
    $$PWD/chzn_test_wgt.ui
